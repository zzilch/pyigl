#include "header.h"
#include <igl/AABB.h>
#include <igl/in_element.h>

void init_in_element(py::module_ & m)
{
    m.def("in_element", [](
        const Eigen::MatrixXd &V,
        const Eigen::MatrixXi &Ele,
        const Eigen::MatrixXd &Q){
            igl::AABB<Eigen::MatrixXd,3> aabb;
            aabb.init(V,Ele);
            Eigen::VectorXi I;
            igl::in_element(V,Ele,Q,aabb,I);
            return I;
        });
}