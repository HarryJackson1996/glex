#ifndef CAMERA_H
#define CAMERA_H
#include "GameAsset.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Camera : public GameAsset {
 public:
	Camera();
	~Camera();
	glm::mat4 getViewMatrix();
	void move_PositiveY(float);
	void move_NegativeY(float);
	void move_PositiveX(float);
	void move_NegativeX(float);
	void move_PositiveZ(float);
	void move_NegativeZ(float);
	void Draw(GLuint);
	void resetView();
	glm::mat4 view;
};

#endif 
