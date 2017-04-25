#include <boost/python.hpp>
#include "CubeAsset.h"
using namespace boost::python;

BOOST_PYTHON_MODULE(hello)
{
    class_<CubeAsset>("CubeAsset")
        
    ;
}
