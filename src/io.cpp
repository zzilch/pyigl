#include "header.h"
#include <igl/readDMAT.h>

void init_io(py::module_ & m)
{
    m.def("readDMAT", [](
        const std::string file_name){
            Eigen::VectorXi W;
            igl::readDMAT(file_name,W);
            return W;
        }); 
}