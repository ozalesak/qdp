#ifndef HAMILTONIAN_HPP_
#define HAMILTONIAN_HPP_

#include "Operator.hpp"

class Hamiltonian : public Operator
{
public:
    Hamiltonian(const MatrixData& data); // copies data
    Hamiltonian(const Operator& op); // copies operator

private:
    void check_properties() const;
};

#endif