using namespace std;
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <memory>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>


class TestBoundingBox : public CPPUNIT_NS::TestCase {
CPPUNIT_TEST_SUITE( TestBoundingBox );
CPPUNIT_TEST( testOverlap );
CPPUNIT_TEST_SUITE_END();

public:
TestBoundingBox( ) : CppUnit::TestCase( "TestBoundingBox" ) {}
TestBoundingBox( std::string name ) : CppUnit::TestCase( name ) {}



void testOverlap(){
auto b1 = make_shared<BoundingBox>(BoundingBox(Vector3(0.0f, 0.0f, 0.0f), 5.0f, 5.0f, 5.0f));
auto b2 = make_shared<BoundingBox>(BoundingBox(Vector3(20.0f, 20.0f, 20.0f), 5.0f, 5.0f, 5.0f));

CPPUNIT_ASSERT( b1->CollidesWith(b2) );
CPPUNIT_ASSERT( b2->CollidesWith(b1) );
}



};

//change to boost B_A_T_C
