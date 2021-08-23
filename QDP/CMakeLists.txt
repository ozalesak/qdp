# CMakeList.txt : CMake project for QDP, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)



find_package (Eigen3 3.3 REQUIRED NO_MODULE)

# Add source to this project's executable.
add_executable (QDP "QDP.cpp" "QDP.hpp" "DensityMatrix.hpp" "Operator.hpp" "Utility.hpp" "DensityMatrix.cpp" "Operator.cpp"  "Utility.cpp" "Hamiltonian.hpp" "Hamiltonian.cpp" "LiouvillevonNeumann.hpp" "Propagator.hpp" "Propagator.cpp" "LiouvillevonNeumann.cpp")
target_link_libraries (QDP Eigen3::Eigen)





# TODO: Add tests and install targets if needed.
