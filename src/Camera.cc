#include "Camera.h"
#include <memory>
#include <utility>
#include <ostream>

using namespace std;

/*View matrix - position of camera
- Set view;
- Prints out the position of the camera in the terminal when running src/shaderexample even if the screen is black as model view not correctly 	     implemented.
- Prints out the position of the newCamera in the python interpreter 
- I have exposed the camera and its relative functions in the pyCubeAsset.cc
- If you create a newCamera in the python interpreter it will print the position of the new camera (0.0, 0.0, 0.0, 1.0)
- prints a line
- If you were to go into the python interpreter and make a newCamera by doing NewCamera = libpyhydra.Camera()
- The result you would get is "Camera Position: vec4(0.000000, 0.000000, 0.000000, 1.000000)"
- As the move functions have also been exposed you can also move the new camera.
- For example, if you type NewCamera.move_PositiveX(10)
- The result would print 

Camera Position: vec4(10.000000, 0.000000, 0.000000, 1.000000)

Camera moved:
x = 10
y = 0
z = 0

- As you can see the difference in the new camera's x position is +10 units.
- And it then prints which direction the camera has moved in and by how many units ( x = +10)
- You can also reset the view.
*/

Camera::Camera(){
	view = glm::mat4(			
             glm::vec4(1.0, 0.0, 0.0, 0.0),
             glm::vec4(0.0, 1.0, 0.0, 0.0),
             glm::vec4(0.0, 0.0, 1.0, 0.0),
             glm::vec4(0.0, 0.0, 0.0, 1.0)
           );
	view = view;
	std::cout<< "Camera Position: " <<glm::to_string(view[3])<<std::endl;
	std::cout<< endl;
}

Camera::~Camera(){
}


void Camera::move_PositiveX (float x){		//matrix for moving +x
	glm::mat4 a = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(x, 0.0, 0.0, 1.0)
	);
	view = a * view;
	std::cout<< "Camera Position: " <<glm::to_string(view[3])<<std::endl;
	std::cout<< endl;
	std::cout << "Camera moved:" << endl << "x = " << a[3][0] << endl << "y = " << a[3][1] << endl << "z = "<< a[3][2] << endl << std::endl;
}

void Camera::move_NegativeX (float x){		//matrix for moving -x
	glm::mat4 a = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(-x, 0.0, 0.0, 1.0)
	);
	view = a * view;
	std::cout<< "Camera Position: " <<glm::to_string(view[3])<<std::endl;
	std::cout<< endl;
	std::cout << "Camera moved:" << endl << "x = " << a[3][0] << endl << "y = " << a[3][1] << endl << "z = "<< a[3][2] << endl << std::endl;
}

void Camera::move_PositiveZ (float z){		//matrix for moving +z
	glm::mat4 a = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(0.0, 0.0, z, 1.0)
	);
	view = a * view;
	std::cout<< "Camera Position: " <<glm::to_string(view[3])<<std::endl;
	std::cout<< endl;
	std::cout << "Camera moved:" << endl << "x = " << a[3][0] << endl << "y = " << a[3][1] << endl << "z = "<< a[3][2] << endl << std::endl;
}

void Camera::move_NegativeZ (float z){		//matrix for moving -z
	glm::mat4 a = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(0.0, 0.0, -z, 1.0)
	);
	view = a * view;
	std::cout<< "Camera Position: " <<glm::to_string(view[3])<<std::endl;
	std::cout<< endl;
	std::cout << "Camera moved:" << endl << "x = " << a[3][0] << endl << "y = " << a[3][1] << endl << "z = "<< a[3][2] << endl << std::endl;
}

void Camera::move_PositiveY (float y){		//matrix for moving +y
	glm::mat4 a = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(0.0, y, 0.0, 1.0)
	);
	view = a * view;
	std::cout<< "Camera Position: " <<glm::to_string(view[3])<<std::endl;
	std::cout<< endl;
	std::cout << "Camera moved:" << endl << "x = " << a[3][0] << endl << "y = " << a[3][1] << endl << "z = "<< a[3][2] << endl << std::endl;;
}

void Camera::move_NegativeY (float y){		//matrix for movning -y
	glm::mat4 a = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(0.0, -y, 0.0, 1.0)
	);
	view = a * view;
	std::cout<< "Camera Position: " <<glm::to_string(view[3])<<std::endl;
	std::cout<< endl;
	std::cout << "Camera moved:" << endl << "x = " << a[3][0] << endl << "y = " << a[3][1] << endl << "z = "<< a[3][2] << endl << std::endl;
}

void Camera::resetView() {				//reset view;
	glm::mat4 newView = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(0.0, 0.0, 0.0, 1.0)
	);
	view = newView;

	std::cout<< "Camera Position: " <<glm::to_string(view[3])<<std::endl;
	std::cout<< endl;
}

glm::mat4 Camera::getViewMatrix(){
	return view;
	std::cout<<glm::to_string(view)<<std::endl;
}



void Camera::Draw(GLuint) {
}



