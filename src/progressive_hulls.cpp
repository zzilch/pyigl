#include "header.h"
#include <igl/copyleft/progressive_hulls.h>

void init_progressive_hulls(py::module_ & m)
{
    m.def("progressive_hulls", [](
        const Eigen::MatrixXd &V,
        const Eigen::MatrixXi &F,
        const size_t max_m){
            Eigen::MatrixXd U;
            Eigen::MatrixXi G;
            Eigen::VectorXi J;
            igl::copyleft::progressive_hulls(V,F,max_m,U,G,J);
            return py::make_tuple(U,G,J);
        }); 
}