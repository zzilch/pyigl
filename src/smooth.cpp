#include "header.h"
#include <igl/cotmatrix.h>
#include <igl/massmatrix.h>
#include <igl/barycenter.h>
#include <igl/doublearea.h>

void init_smooth(py::module_ & m)
{
    m.def("smooth_laplacian", [](
        Eigen::MatrixXd &V,
        const Eigen::MatrixXi &F,
        const int n_iter,
        const double lambda){
            Eigen::SparseMatrix<double> L;
            igl::cotmatrix(V,F,L);
            for(int i=0;i<n_iter;i++)
            {
                Eigen::SparseMatrix<double> M;
                igl::massmatrix(V,F,igl::MASSMATRIX_TYPE_BARYCENTRIC,M);
                const auto & S = (M - lambda*L);
                Eigen::SimplicialLLT<Eigen::SparseMatrix<double > > solver(S);
                V = solver.solve(M*V).eval();
            }
            return V;
        });
    m.def("smooth_taubin", [](
        Eigen::MatrixXd &V,
        const Eigen::MatrixXi &F,
        const int n_iter,
        const double lambda,
        const double miu){
            Eigen::SparseMatrix<double> L;
            igl::cotmatrix(V,F,L);
            for(int i=0;i<n_iter;i++)
            {
                Eigen::SparseMatrix<double> M;

                igl::massmatrix(V,F,igl::MASSMATRIX_TYPE_BARYCENTRIC,M);
                const auto & S1 = (M - lambda*L);
                Eigen::SimplicialLLT<Eigen::SparseMatrix<double > > solver1(S1);
                V = solver1.solve(M*V).eval();

                igl::massmatrix(V,F,igl::MASSMATRIX_TYPE_BARYCENTRIC,M);
                const auto & S2 = (M + miu*L);
                Eigen::SimplicialLLT<Eigen::SparseMatrix<double > > solver2(S2);
                V = solver2.solve(M*V).eval();
            }
            return V;
        });
}