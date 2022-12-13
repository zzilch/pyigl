#include "header.h"
#include <igl/signed_distance.h>
#include <igl/point_mesh_squared_distance.h>

void init_distances(py::module_ & m)
{
    m.def("point_mesh_squared_distance", [](
        const Eigen::MatrixXd &P,
        const Eigen::MatrixXd &V,
        const Eigen::MatrixXi &Ele){
            Eigen::VectorXd sqrD;
            Eigen::VectorXi I;
            Eigen::MatrixXd C;
            igl::point_mesh_squared_distance(P,V,Ele,sqrD,I,C);
            return py::make_tuple(sqrD,I,C);
        });

    m.def("point_mesh_distance", [](
        const Eigen::MatrixXd &P,
        const Eigen::MatrixXd &V,
        const Eigen::MatrixXi &Ele){
            Eigen::VectorXd D;
            Eigen::VectorXi I;
            Eigen::MatrixXd C;
            igl::point_mesh_squared_distance(P,V,Ele,D,I,C);
            return py::make_tuple(D.array().sqrt(),I,C);
        });

    py::enum_<igl::SignedDistanceType>(m, "SignedDistanceType")
        .value("SIGNED_DISTANCE_TYPE_PSEUDONORMAL", igl::SignedDistanceType::SIGNED_DISTANCE_TYPE_PSEUDONORMAL)
        .value("SIGNED_DISTANCE_TYPE_WINDING_NUMBER", igl::SignedDistanceType::SIGNED_DISTANCE_TYPE_WINDING_NUMBER)
        .value("SIGNED_DISTANCE_TYPE_DEFAULT", igl::SignedDistanceType::SIGNED_DISTANCE_TYPE_DEFAULT)
        .value("SIGNED_DISTANCE_TYPE_UNSIGNED", igl::SignedDistanceType::SIGNED_DISTANCE_TYPE_UNSIGNED)
        .value("SIGNED_DISTANCE_TYPE_FAST_WINDING_NUMBER", igl::SignedDistanceType::SIGNED_DISTANCE_TYPE_FAST_WINDING_NUMBER)
        .export_values();

    m.def("signed_distance", [](
        const Eigen::MatrixXd &P,
        const Eigen::MatrixXd &V,
        const Eigen::MatrixXi &F,
        const igl::SignedDistanceType sign_type)
        {
            Eigen::MatrixXd S;
            Eigen::VectorXi I;
            Eigen::MatrixXd C;
            Eigen::MatrixXd N;
            igl::signed_distance(P,V,F,sign_type,S,I,C,N);
            return py::make_tuple(S,I,C,N);
        });
    
    m.def("fast_winding_number_soups", [](
        const Eigen::MatrixXd &V,
        const Eigen::MatrixXi &F,
        const Eigen::MatrixXd &Q)
        {
            Eigen::VectorXd W;
            igl::fast_winding_number(V,F,Q,W);
            return W;
        });

    m.def("fast_winding_number_clouds", [](
        const Eigen::MatrixXd &P,
        const Eigen::MatrixXd &N,
        const Eigen::VectorXd &A,
        const Eigen::MatrixXd &Q)
        {
            Eigen::VectorXd WN;
            igl::fast_winding_number(P,N,A,Q,WN);
            return WN;
        });
}