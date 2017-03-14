#include "BoundingBox.h"

BoundingBox::BoundingBox(const Vector3 centre, const float width, const float height, const float depth) {
centre(make_shared<Vector3>(centre)),
extent_x(make_shared<Vector3>(Vector3(width/2.0, 0.0, 0.0))),
extent_y(make_shared<Vector3>(Vector3(0.0, height/2.0, 0.0))),
extent_z(make_shared<Vector3>(Vector3(0.0, 0.0, depth/2.0))) {

}

SFBoundingBox::~SFBoundingBox() {
  centre.reset();
  extent_x.reset();
  extent_y.reset();
  extent_z.reset();
}

void BoundingBox::SetCentre(Vector3 & v) {
  centre = make_shared<Vector3>(v);
}

bool straddles(const pair<float, float> & a, const pair<float, float> & b) {
  if((a.first >= b.first && a.first <= b.second)
     || (a.second >= b.first && a.second <= b.second))
    {
      return true;
    }
return false;
}


pair<float,float> BoundingBox::projectOntoAxis(const BoundingBox & b, enum AXIS axis) {
  
float lo, hi;

  switch (axis) {
  case X:
    {
      Vector3 bx = *b.x;
      lo  = projection( Point3(Vector3(*(b.centre)) + (bx * -1)), HalfX());
      hi  = projection( Point3(Vector3(*(b.centre)) + bx), HalfX());
    }
    break;
  case Y:
    {
      Vector3 by = *b.y;
      lo  = projection( Point3(Vector3(*(b.centre)) + (by * -1)), HalfY());
      hi  = projection( Point3(Vector3(*(b.centre)) + by), HalfY());
    }
    break;
  case Z:
    {
      Vector3 bz = *b.z;
      lo  = projection( Point3(Vector3(*(b.centre)) + (bz * -1)), HalfZ());
      hi  = projection( Point3(Vector3(*(b.centre)) + bz), HalfZ());
    }
    break;
  }

  return make_pair(lo, hi);
}

BoundingBox::CollidesWith(const shared_ptr<BoundingBox> b){



}


