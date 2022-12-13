#include "header.h"
#include <igl/boundary_loop.h>

void init_boundary_loop(py::module_ & m)
{
    m.def("boundary_loop", [](
        const Eigen::MatrixXi &F){
            std::vector<std::vector<int>> L;
            igl::boundary_loop(F,L);
            return L;
        });
    
    m.def("boundary_loop_number", [](
        const Eigen::MatrixXi &F){
            std::vector<std::vector<int>> L;
            igl::boundary_loop(F,L);
            return L.size();
        });
}