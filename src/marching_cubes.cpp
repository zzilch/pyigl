#include "header.h"
#include <igl/marching_cubes.h>

void init_marching_cubes(py::module_ & m)
{
    m.def("marching_cubes", [](
        const Eigen::MatrixXd &S,
        const Eigen::MatrixXd &GV,
        const unsigned nx,
        const unsigned ny,
        const unsigned nz,
        const double isovalue){
            Eigen::MatrixXd V;
            Eigen::MatrixXi F;
            igl::marching_cubes(S,GV,nx,ny,nz,isovalue,V,F);
            return py::make_tuple(V,F);
        }); 
}