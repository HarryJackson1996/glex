#include "BoundingBox.h"


/* 
- For the BoundingBox I used collision from starship fontana as a base.
- Starship Fontana already implemented a 2d axis aligned bounding box.
- I changed the vector2's to vector3's as we needed to implement the Z axis collision detection.
- Changed the const int's into floats as from my research it suggested that floats are more precise for 3d collision detection
- I was not able to implement my collision into my game as I had not fully completed the first semester coursework and therefore had not finished the 	implementation of the model view.
- To test if my collision worked a wrote a boost test.
- This is called testBoundingBox.cpp.
*/

BoundingBox::BoundingBox(const Vector3 centre,
			     const float width,
			     const float height,
			     const float depth) :
  centre(make_shared<Vector3>(centre)),
  extent_x(make_shared<Vector3>(Vector3((float) width/2.0, 0.0f, 0.0f))),
  extent_y(make_shared<Vector3>(Vector3(0.0f,(float) height/2.0, 0.0f))),
  extent_z(make_shared<Vector3>(Vector3(0.0f, 0.0f, (float) depth/2.0))){
}

BoundingBox::~BoundingBox() {
  centre.reset();
  extent_x.reset();
  extent_y.reset();
  extent_z.reset();
}

void BoundingBox::SetCentre(Vector3 & v) {
  centre = make_shared<Vector3>(v);
}

bool straddles(const pair<float, float> & a, const pair<float, float> & b) {
  return (a.first >= b.first && a.first <= b.second)  // a1 intersects b
    || (a.second >= b.first && a.second <= b.second)  // a2 intersects b
    || (b.first >= a.first && b.first <= a.second)    // b1 intersects a
    || (b.second >= a.first && b.second <= a.second); // b2 intersects a
}

pair<float,float> BoundingBox::projectOntoAxis(const BoundingBox & b, enum AXIS axis) {
  float lo, hi;

  switch (axis) {
  case X:
    {
      Vector3 bx = *b.extent_x;
      lo  = projection( Point3(Vector3(*(b.centre)) + (bx * -1)), xAxis());
      hi  = projection( Point3(Vector3(*(b.centre)) + bx), xAxis());
    }
    break;
  case Y:
    {
      Vector3 by = *b.extent_y;
      lo  = projection( Point3(Vector3(*(b.centre)) + (by * -1)), yAxis());
      hi  = projection( Point3(Vector3(*(b.centre)) + by), yAxis());
    }
    break;
   case Z:
    {
      Vector3 bz = *b.extent_z;
      lo  = projection( Point3(Vector3(*(b.centre)) + (bz * -1)), zAxis());
      hi  = projection( Point3(Vector3(*(b.centre)) + bz), zAxis());
    }
    break;
  }

  return make_pair(lo, hi);
}

bool BoundingBox::CollidesWith(const shared_ptr<BoundingBox> b) {
  pair<float, float> a_x_proj = projectOntoAxis(*this, X),
    a_y_proj = projectOntoAxis(*this, Y),
    a_z_proj = projectOntoAxis(*this, Z),
    b_y_proj = projectOntoAxis(*b, Y),
    b_z_proj = projectOntoAxis(*b, Z),
    b_x_proj = projectOntoAxis(*b, X);


 return (straddles(a_x_proj, b_x_proj)) && (straddles(a_y_proj, b_y_proj)) && (straddles(a_z_proj, b_z_proj));
}

ostream& operator<<(ostream& os, const BoundingBox& obj) {
  os << "c:(" << obj.centre->getX() << ", " << obj.centre->getY() << ") w:" << (obj.extent_x->getX()*2) << " h:" << (obj.extent_y->getY()*2);
  return os;
}
