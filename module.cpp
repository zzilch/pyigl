#include "src/header.h"

void init_arap(py::module_ & m);
void init_barycentric(py::module_ & m);
void init_boundary_loop(py::module_ & m);
void init_connected_components(py::module_ & m);
void init_distances(py::module_ & m);
void init_euler_characteristic(py::module_ & m);
void init_harmonic(py::module_ & m);
void init_icp(py::module_ & m);
void init_in_element(py::module_ & m);
void init_io(py::module_ & m);
void init_marching_cubes(py::module_ & m);
void init_progressive_hulls(py::module_ & m);
void init_reorient(py::module_ & m);
void init_smooth(py::module_ & m);
void init_tetrahedralize(py::module_ & m);
void init_voxel_grid(py::module_ & m);

PYBIND11_MODULE(pyigl, m) {
    init_arap(m);
    init_barycentric(m);
    init_boundary_loop(m);
    init_connected_components(m);
    init_distances(m);
    init_euler_characteristic(m);
    init_harmonic(m);
    init_icp(m);
    init_in_element(m);
    init_io(m);
    init_marching_cubes(m);
    init_progressive_hulls(m);
    init_reorient(m);
    init_smooth(m);
    init_tetrahedralize(m);
    init_voxel_grid(m);
}
