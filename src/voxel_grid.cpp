#include "header.h"
#include <igl/voxel_grid.h>

void init_voxel_grid(py::module_ & m)
{
    m.def("voxel_grid_box", [](
        const Eigen::MatrixXd &box,
        const int s,
        const int pad_count){
            Eigen::MatrixXd GV;
            Eigen::RowVector3i side;
            igl::voxel_grid(Eigen::AlignedBox<double,3>(box.row(0),box.row(1)),s,pad_count,GV,side);
            return py::make_tuple(GV,side);
        }); 

    m.def("voxel_grid_offset", [](
        const Eigen::MatrixXd &V,
        const double offset,
        const int s,
        const int pad_count){
            Eigen::MatrixXd GV;
            Eigen::RowVector3i side;
            igl::voxel_grid(V,offset,s,pad_count,GV,side);
            return py::make_tuple(GV,side);
        }); 
}