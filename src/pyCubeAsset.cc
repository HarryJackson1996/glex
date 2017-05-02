#include <boost/python.hpp>
#include "CubeAsset.h"
#include "Camera.h"
#include "BoundingBox.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace boost::python;

BOOST_PYTHON_MODULE(libpyhydra)
{
	class_<CubeAsset>("CubeAsset", init<>())   

    ;
	class_<Camera>("Camera", init<>())
	 .def("move_PositiveX", &Camera::move_PositiveX)
	 .def("move_NegativeX", &Camera::move_NegativeX)
	 .def("move_PositiveY", &Camera::move_PositiveY)
	 .def("move_NegativeY", &Camera::move_NegativeY)
	 .def("move_PositiveZ", &Camera::move_PositiveZ)
	 .def("move_NegativeZ", &Camera::move_NegativeZ)
	 .def("reset_View", &Camera::resetView)
    ;


}
