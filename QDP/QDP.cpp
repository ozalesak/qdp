// QDP.cpp : Defines the entry point for the application.
//

#include "QDP.hpp"

#include "DensityMatrix.hpp"
#include "Hamiltonian.hpp"

#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

int main()
{
    MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);
    std::cout << m << std::endl;

    MatrixData m2(2, 2);
    m2 << 0.25, 2, 2, std::complex<double>(0.75, 0);
    DensityMatrix d(m2);
    std::cout << d.get_data();

    MatrixData m3(2, 2);
    m3 << 15, std::complex<double>(1, 5), std::complex<double>(1, -5), std::complex<double>(20, 0);

    std::cout << std::endl;
    Hamiltonian h(m3);
    std::cout << h.get_data();
}