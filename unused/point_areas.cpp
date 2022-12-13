#include "header.h"
#include <igl/octree.h>
#include <igl/knn.h>
#include <igl/copyleft/cgal/point_areas.h>

void init_point_areas(py::module_ & m)
{
    m.def("point_areas", [](
        const Eigen::MatrixXd &P,
        const Eigen::MatrixXd &N,
        const int k){
            std::vector<std::vector<int > > O_PI;
            Eigen::MatrixXi O_CH;
            Eigen::MatrixXd O_CN;
            Eigen::VectorXd O_W;
            igl::octree(P,O_PI,O_CH,O_CN,O_W);
            Eigen::VectorXd A;
            Eigen::MatrixXi I;
            igl::knn(P,k,O_PI,O_CH,O_CN,O_W,I);
            igl::copyleft::cgal::point_areas(P,I,N,A);
            return A;
        });   
}