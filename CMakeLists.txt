cmake_minimum_required(VERSION 3.16)
project(pyigl)

# libigl
option(LIBIGL_COPYLEFT_TETGEN  "Build target igl_copyleft::tetgen"  ON)
# option(LIBIGL_COPYLEFT_CGAL    "Build target igl_copyleft::cgal"    ON)
list(PREPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(libigl)

# eigen
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

# pybind11
find_package(pybind11 REQUIRED)

# OpenMP
find_package(OpenMP)

file(GLOB SOURCES "./src/*.cpp")
pybind11_add_module(pyigl MODULE ./module.cpp ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC igl::core)
target_link_libraries(${PROJECT_NAME} PUBLIC igl_copyleft::tetgen)
# target_link_libraries(${PROJECT_NAME} PUBLIC igl_copyleft::cgal)