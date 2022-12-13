#include "header.h"
#include <igl/copyleft/tetgen/tetrahedralize.h>

void init_tetrahedralize(py::module_ & m)
{
    m.def("tetrahedralize", [](
        const Eigen::MatrixXd &V,
        const Eigen::MatrixXi &F,
        const Eigen::MatrixXd &H,
        const Eigen::MatrixXd &R,
        const std::string switches){
            Eigen::MatrixXd TV;
            Eigen::MatrixXi TT;
            Eigen::MatrixXi TF;
            Eigen::MatrixXd TR;
            Eigen::MatrixXi TN;
            Eigen::MatrixXi PT;
            Eigen::MatrixXi FT;
            size_t numRegions;
            igl::copyleft::tetgen::tetrahedralize(V,F,H,R,switches,TV,TT,TF,TR,TN,PT,FT,numRegions);
            return py::make_tuple(TV,TT,TF,TR,TN,PT,FT,numRegions);
        });   
}