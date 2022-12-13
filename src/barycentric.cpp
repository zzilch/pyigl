#include "header.h"
#include <igl/barycentric_coordinates.h>

void init_barycentric(py::module_ & m)
{
    m.def("barycentric_coordinates_tet", [](
        const Eigen::MatrixXd &P,
        const Eigen::MatrixXd &A,
        const Eigen::MatrixXd &B,
        const Eigen::MatrixXd &C,
        const Eigen::MatrixXd &D){
            Eigen::MatrixXd L;
            igl::barycentric_coordinates(P,A,B,C,D,L);
            return L;
        });
    
    m.def("barycentric_coordinates_tri", [](
        const Eigen::MatrixXd &P,
        const Eigen::MatrixXd &A,
        const Eigen::MatrixXd &B,
        const Eigen::MatrixXd &C){
            Eigen::MatrixXd L;
            igl::barycentric_coordinates(P,A,B,C,L);
            return L;
        });
}