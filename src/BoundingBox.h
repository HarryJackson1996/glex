#ifdef BOUNDINGBOX_H
#define BOUNDINGBOX_H

using namespace std;

#include "Math.h"
#include "GameAsset.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>
#include <utility>
#include <ostream>

enum AXIS {X, Y, Z};  	
		
static glm::vec3 HalfX = glm::vec3(1.0, 0.0, 0.0);
static glm::vec3 HalfY = glm::vec3(0.0, 1.0, 0.0);
static glm::vec3 HalfZ = glm::vec3(0.0, 0.0, 1.0);

class BoundingBox : public GameAsset {
 
public:
	BoundingBox(const Vector3, 
		    const float extent_x, 
		    const float extent_y, 
		    const float extent_z);
	
	virtual ~BoundingBox();
	
	void SetCentre(Vector3 &);
	bool CollidesWith(const shared_ptr<BoundingBox> & b);


private:
	shared_ptr<Vector3> centre, extent_x, extent_y, extent_z;
	pair<float,float> projectOntoAxis(const BoundingBox &, enum AXIS);	
	
	glm:: vec3 hx, hy, hz;


};

#endif 
