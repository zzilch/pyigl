#include "header.h"
#include <igl/iterative_closest_point.h>

void init_icp(py::module_ & m)
{
    m.def("icp", [](
        const Eigen::MatrixXd &VX,
        const Eigen::MatrixXi &FX,
        const Eigen::MatrixXd &VY,
        const Eigen::MatrixXi &FY,
        const int num_samples,
        const int max_iters){
            Eigen::Matrix3d R;
            Eigen::RowVector3d t;
            return igl::iterative_closest_point(VX,FX,VY,FY,num_samples,max_iters,R,t);
        });
}