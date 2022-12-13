#include "header.h"
#include <igl/facet_components.h>
#include <igl/vertex_components.h>

void init_connected_components(py::module_ & m)
{
    m.def("facet_components", [](
        const Eigen::MatrixXi &F){
            Eigen::VectorXi C;
            igl::facet_components(F,C);
            return C;
        });
    
    m.def("facet_components_number", [](
        const Eigen::MatrixXi &F){
            Eigen::VectorXi C;
            igl::facet_components(F,C);
            return C.maxCoeff()+1;
        });
    
    m.def("vertex_components", [](
        const Eigen::MatrixXi &F){
            Eigen::VectorXi C;
            igl::vertex_components(F,C);
            return C;
        });
}