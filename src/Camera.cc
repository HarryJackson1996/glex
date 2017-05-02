#include "Camera.h"
#include <memory>
#include <utility>
#include <ostream>

using namespace std;


Camera::Camera(){
	view = glm::mat4(			//view matrix
             glm::vec4(1.0, 0.0, 0.0, 0.0),
             glm::vec4(0.0, 1.0, 0.0, 0.0),
             glm::vec4(0.0, 0.0, 1.0, 0.0),
             glm::vec4(-2.0, 0.0, 0.0, 1.0)
           );
	view = view;
	std::cout<<glm::to_string(view)<<std::endl;
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
	std::cout<<glm::to_string(view)<<std::endl;
}

void Camera::move_NegativeX (float x){		//matrix for moving -x
	glm::mat4 a = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(-x, 0.0, 0.0, 1.0)
	);
	view = a * view;
	std::cout<<glm::to_string(view)<<std::endl;
}

void Camera::move_PositiveZ (float z){		//matrix for moving +z
	glm::mat4 a = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(0.0, 0.0, z, 1.0)
	);
	view = a * view;
	std::cout<<glm::to_string(view)<<std::endl;
}

void Camera::move_NegativeZ (float z){		//matrix for moving -z
	glm::mat4 a = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(0.0, 0.0, -z, 1.0)
	);
	view = a * view;
	std::cout<<glm::to_string(view)<<std::endl;
}

void Camera::move_PositiveY (float y){		//matrix for moving +y
	glm::mat4 a = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(0.0, y, 0.0, 1.0)
	);
	view = a * view;
	std::cout<<glm::to_string(view)<<std::endl;
}

void Camera::move_NegativeY (float y){		//matrix for movning -y
	glm::mat4 a = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(0.0, -y, 0.0, 1.0)
	);
	view = a * view;
	std::cout<<glm::to_string(view)<<std::endl;
}

void Camera::resetView() {				//reset view;
	glm::mat4 newView = glm::mat4(
		glm::vec4(1.0, 0.0, 0.0, 0.0),
    		glm::vec4(0.0, 1.0, 0.0, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 0.0),
		glm::vec4(-2.0, 0.0, 0.0, 1.0)
	);
	view = newView;
	std::cout<<glm::to_string(newView)<<std::endl;
}



glm::mat4 Camera::getViewMatrix(){
	return view;
	std::cout<<glm::to_string(view)<<std::endl;
}



void Camera::Draw(GLuint) {
}



