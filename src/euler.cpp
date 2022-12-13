#include "header.h"
#include <igl/euler_characteristic.h>

void init_euler_characteristic(py::module_ & m)
{
    m.def("euler_characteristic", [](
        const Eigen::MatrixXi &F){
            return igl::euler_characteristic(F);
        });
    
    m.def("euler_characteristic_complete", [](
        const Eigen::MatrixXd &V,
        const Eigen::MatrixXi &F){
            return igl::euler_characteristic(V,F);
        });
}