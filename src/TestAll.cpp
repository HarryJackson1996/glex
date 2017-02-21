#include <cppunit/ui/text/TestRunner.h>

#include "CollidesTrue.h"

int main( int argc, char **argv) {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest( TestBoundingBox::suite() );
  runner.run();
  return 0;
}
