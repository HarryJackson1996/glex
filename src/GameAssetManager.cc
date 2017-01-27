#include "GameAssetManager.h"
#include <exception>
/**
 * Creates a GameAssetManager to load the correct shaders based on the
 * ApplicationMode.
 */
GameAssetManager::GameAssetManager(ApplicationMode mode) {
  std::string vertex_shader("shaders/translate.vs");
  std::string fragment_shader("shaders/fragment.fs");

  switch(mode) {
  case ROTATE:
    vertex_shader = "shaders/rotate.vs";
    break;
  case SCALE:
    vertex_shader = "shaders/scale.vs";
    break;
  case TRANSFORM:
  default:
    break;
  };

  program_token = CreateGLProgram(vertex_shader, fragment_shader);

  camera = std::make_shared<Camera>();
}

/**
 * Deletes a GameAssetManager, in particular it will clean up any modifications
 * to the OpenGL state.
 */
GameAssetManager::~GameAssetManager() {
  glDeleteProgram(program_token);
}

/**
 * Unimplemented copy constructor -- this means that the GameAssetManager
 * may not work as you'd expect when being copied.
 */
GameAssetManager::GameAssetManager(GameAssetManager const& the_manager) {
  // TODO: implement this
}

/**
 * Unimplemented move constructor -- this unimplemented method violates the
 * C++11 move semantics for GameAssetManager.
 */
GameAssetManager::GameAssetManager(GameAssetManager const&& the_manager) {
  // TODO: implement this
}

/**
 * Unimplemented assisgnment operator -- violates the expected semantics for
 * assignment in C++11.
 */
void GameAssetManager::operator=(GameAssetManager const& the_manager) {
  // TODO: implement this
}

/**
 * Adds a GameAsset to the scene graph.
 */
void GameAssetManager::AddAsset(std::shared_ptr<GameAsset> the_asset) {
  draw_list.push_back(the_asset);
}

/**
 * Draws each GameAsset in the scene graph.
 */
void GameAssetManager::Draw() {
	
SDL_Event event;
while( SDL_PollEvent(&event)){
	switch(event.type){
	case SDL_KEYDOWN:   //Key movements 
			switch( event.key.keysym.sym ){ 		//switch statement
				case SDLK_w: case SDLK_UP:		//'up arrow' or 'W'
					camera->move_PositiveZ(0.35);	//Camera forward in the Z direction
					break;				//break from case

				case SDLK_s: case SDLK_DOWN:		//'s' or 'down arrow' 
				        camera->move_NegativeZ(0.35);	//Camera moves backwards in Z direction
					break;				//break from case

				case SDLK_a: case SDLK_LEFT:		//'a' or 'left arrow'
					camera->move_PositiveX(0.35);	//Camera moves positive in x direction
					break;				//break from case

				case SDLK_d: case SDLK_RIGHT:		//'d' or 'right arrow'
					camera->move_NegativeX(0.35);	//Camera moves negative in x direction
					break;				//break from case

				case SDLK_BACKSPACE:			//'backspace'
					camera->move_PositiveY(0.35);	//Camera moves positive in y direction
					break;				//break from case

				case SDLK_SPACE:			//'space' 
					camera->move_NegativeY(0.35);	//camera moves negative in y direction
					break;				//break from case

				case SDLK_r: case SDLK_DELETE:		//Pressing 'r' or 'delete' will reset camera
					camera->resetView();		//Resets camera position to center of screen
					break;				//break from case
				default:	
					break;				//break 
				case SDLK_ESCAPE:			//If 'escape' is pressed
					std::exit(0);			//Exits window
			}
				default:
					break;
	
				case SDL_MOUSEMOTION:   
					if(event.motion.xrel > 0){		
					camera->move_NegativeX(0.035);	
				} else if(event.motion.xrel < 0){
					camera->move_PositiveX(0.035);
				}
					if(event.motion.yrel > 0){
					camera->move_PositiveY(0.025);
				} else if(event.motion.yrel < 0){
					camera->move_NegativeY(0.025);
				}
					break;
			}
		}
		
	glm::mat4 a = camera->getViewMatrix();
	GLuint view_uniform = glGetUniformLocation(program_token, "view");
	glUniformMatrix4fv(view_uniform, 1, false, glm::value_ptr(a));

	
	for(auto ga: draw_list) {
    	ga->Draw(program_token);
  	}
}
/**
 * When given the contents of a vertex shader and fragment shader
 * GameAssetManager::CreateGLProgram will compile and link them.  This
 * implementation will exit with -1 error if an error is detected.
 *
 * @return the GL "token" referring to the gl program.
 */
GLuint GameAssetManager::CreateGLProgram(std::string & vertex_shader
                                         , std::string & fragment_shader) {
  auto v_shader_token = CreateGLESShader(GL_VERTEX_SHADER, vertex_shader);
  auto f_shader_token = CreateGLESShader(GL_FRAGMENT_SHADER, fragment_shader);

  GLint program_ok;

  GLuint program = glCreateProgram();

  glAttachShader(program, v_shader_token);
  glAttachShader(program, f_shader_token);
  glLinkProgram(program);

  glGetProgramiv(program, GL_LINK_STATUS, &program_ok);
  if (!program_ok) {
    std::cerr << "Failed to link shader program:" << std::endl;
    glDeleteProgram(program);
    exit(-1);
  }
  return program;
}

/**
 * When given a type of shader to construct and the contents of a shader,
 * GameAssetManager::CreateGLESShader will create the shader or exit with
 * error -1.
 *
 * @return the GL "token" for the requested shader.
 */
GLuint GameAssetManager::CreateGLESShader(GLenum type, std::string & shader) {
  GLuint shader_token;
  GLint shader_ok;
  auto source = ReadShader(shader);

  if (!source.first)
    return 0;

  shader_token = glCreateShader(type);
  glShaderSource(shader_token, 1, (const GLchar**)&source.first, &source.second);
  glCompileShader(shader_token);
  delete(source.first);

  glGetShaderiv(shader_token, GL_COMPILE_STATUS, &shader_ok);
  if (!shader_ok) {
    GLint maxLength = 0;
    glGetShaderiv(shader_token, GL_INFO_LOG_LENGTH, &maxLength);

    //The maxLength includes the NULL character
    std::vector<char> errorLog(maxLength);
    glGetShaderInfoLog(shader_token, maxLength, &maxLength, &errorLog[0]);

    //Provide the infolog in whatever manor you deem best.
    std::cerr << "Failed to compile " << shader << " with error code " << shader_ok << std::endl;
    for(auto c: errorLog) {
      std::cerr << c;
    }

    glDeleteShader(shader_token); //Don't leak the shader.
    exit(-1);
  }
  return shader_token;
}

/**
 * ReadShader reads the contents of a file and packs it into a null termintated
 * GLchar * which is suitable for sending to OpenGL.
 *
 * @return a pair consisting of the shader file contents and a holder for the
 *         OpenGL "token".
 */
std::pair<GLchar *, GLint> GameAssetManager::ReadShader(std::string & shader) {
  std::ifstream input_file;
  GLint length;
  input_file.open(shader, std::ios::in);

  input_file.seekg(0, std::ios::end);  // go to the end of the file
  length = input_file.tellg();    // get length of the file
  input_file.seekg(0, std::ios::beg);  // go to beginning of the file

  GLchar * buffer = new GLchar[length+1];
  input_file.read(buffer, length);
  buffer[length+1]='\0';  // Ensure null terminated

  input_file.close();
  return std::make_pair(buffer, length);
}
