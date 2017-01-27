#ifndef CUBEASSET2_H
#define CUBEASSET2_H

#include <vector>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "GameAsset.h"

class CubeAsset2 : public GameAsset {
 public:
  CubeAsset2();
  ~CubeAsset2();
  virtual void Draw(GLuint);



 private:
  GLuint element_buffer_length;
  GLuint vertex_buffer_token, element_buffer_token;
};

#endif // CUBEASSET2_H
