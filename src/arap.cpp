#include "header.h"
#include <igl/arap.h>

void init_arap(py::module_ & m)
{
    py::enum_<igl::ARAPEnergyType>(m, "ARAPEnergyType")
        .value("ARAP_ENERGY_TYPE_SPOKES", igl::ARAPEnergyType::ARAP_ENERGY_TYPE_SPOKES)
        .value("ARAP_ENERGY_TYPE_SPOKES_AND_RIMS", igl::ARAPEnergyType::ARAP_ENERGY_TYPE_SPOKES_AND_RIMS)
        .value("ARAP_ENERGY_TYPE_ELEMENTS", igl::ARAPEnergyType::ARAP_ENERGY_TYPE_ELEMENTS)
        .value("ARAP_ENERGY_TYPE_DEFAULT", igl::ARAPEnergyType::ARAP_ENERGY_TYPE_DEFAULT)
        .export_values();

    py::class_<igl::ARAPData>(m, "ARAPData")
        .def(py::init<>())
        .def_readwrite("b", &igl::ARAPData::b)
        .def_readwrite("energy", &igl::ARAPData::energy)
        .def_readwrite("with_dynamics", &igl::ARAPData::with_dynamics)
        .def_readwrite("h", &igl::ARAPData::h)
        .def_readwrite("max_iter", &igl::ARAPData::max_iter);

    m.def("arap_precomputation", [](
        const Eigen::MatrixXd &V,
        const Eigen::MatrixXi &F,
        const int dim,
        const Eigen::VectorXi & b,
        igl::ARAPData & data){
            return igl::arap_precomputation(V,F,dim,b,data);
        });

    m.def("arap_solve", [](
        const Eigen::MatrixXd &bc,
        igl::ARAPData & data,
        Eigen::MatrixXd &V){
            igl::arap_solve(bc,data,V);
            return V;
        });
}