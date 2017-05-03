using namespace std;
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello
#include <iostream>
#include <boost/test/unit_test.hpp>
#include <memory>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "BoundingBox.h"
#include "BoundingBox.cc"


/*
- Made two test cases one called collidesTrue and CollidesFalse
- When running "make check" the result returned will be true.
- This is because i have set b1 and b2's boundingbox to overlap in the X,Y and Z axis.
- However in order to actually test if the collision works I had to test each axis individually.
- To do this I set first the x position of the boundingbox to 0.51, this meant that both the Y and Z axis overlapped however not the X.
- The result returned false (correct).
- Then I set the Y position of the boundingbox to 0.51, returned the X to 0.41. This meant that both the X and Z axis overlapped however not the Y.
- The result returned false (correct).
- Finally I set the Z position of the boundingbox to 0.51, returned the Y to 0.41. This meant that both the X and Y axis overlapped however not the Z.
- The result returned false (correct).
- These 3 results provided with me the proof the my Collision worked even if not implemented.
*/


BOOST_AUTO_TEST_SUITE( TestBoundingBox );





BOOST_AUTO_TEST_CASE(CollidesTrue)
{
	auto b1 = make_shared<BoundingBox>(BoundingBox(Vector3(0.0f, 0.0f, 0.0f), 0.5f, 0.5f, 0.5f));
	auto b2 = make_shared<BoundingBox>(BoundingBox(Vector3(0.41f, 0.41f, 0.41f), 0.5f, 0.5f, 0.5f));
	BOOST_CHECK(b1->CollidesWith(b2));
	BOOST_CHECK(b2->CollidesWith(b1));
}

BOOST_AUTO_TEST_CASE(CollidesFalse)
{
	auto b1 = make_shared<BoundingBox>(BoundingBox(Vector3(0.0f, 0.0f, 0.0f), 0.5f, 0.5f, 0.5f));
	auto b2 = make_shared<BoundingBox>(BoundingBox(Vector3(0.51f, 0.51f, 0.51f), 0.5f, 0.5f, 0.5f));
	BOOST_CHECK(!b1->CollidesWith(b2));
	BOOST_CHECK(!b2->CollidesWith(b1));
}

BOOST_AUTO_TEST_SUITE_END()


