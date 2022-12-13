#include "header.h"
#include <igl/harmonic.h>

void init_harmonic(py::module_ & m)
{
    m.def("harmonic", [](
        const Eigen::MatrixXd &V,
        const Eigen::MatrixXi &F,
        const Eigen::VectorXi &b,
        const Eigen::MatrixXd &bc,
        int k){
            Eigen::MatrixXd W;
            igl::harmonic(V,F,b,bc,k,W);
            return W;
        });
}