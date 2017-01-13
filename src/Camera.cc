#include "Camera.h"

Camera::Camera(){
}

Camera::~Camera(){
}

glm::mat4 getViewMatrix(){
	return glm::mat4();{

                   glm::vec4(0.0f, 0.0f, 3.0f, 0.0f), 
  		   glm::vec4(0.0f, 0.0f, 0.0f, 0.0f),
	   	   glm::vec4(0.0f, 0.0f, 0.0f, 0.0f), 
  		   glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
}
}
