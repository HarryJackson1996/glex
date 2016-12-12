#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/martix_transform.hpp>
#include <memory>

#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_

class Camera {
public:
	Camera();
	virtual ~Camera();
	glm::mat4 getViewMatrix();

private:
	std::unique_ptr<glm::mat4> view;

};

#endif
