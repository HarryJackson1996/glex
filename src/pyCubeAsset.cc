#include <boost/python.hpp>
#include "CubeAsset.h"
using namespace boost::python;

BOOST_PYTHON_MODULE(libpyhydra)
{
  class_<CubeAsset>("CubeAsset", init<>())
        
    ;
}
