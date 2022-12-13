#include "header.h"
#include <igl/bfs_orient.h>

void init_reorient(py::module_ & m)
{
    m.def("bfs_orient", [](
        const Eigen::MatrixXi &F){
            Eigen::MatrixXi FF;
            Eigen::VectorXi C;
            igl::bfs_orient(F,FF,C);
            return py::make_tuple(FF,C);
        }); 
}