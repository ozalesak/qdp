#include "Hamiltonian.hpp"

Hamiltonian::Hamiltonian(const Operator& op)
    : Operator(op)
{
    check_properties();
}

Hamiltonian::Hamiltonian(const MatrixData& data)
    : Operator(data)
{
    check_properties();
}

void Hamiltonian::check_properties() const
{
    if (!check_selfadjoint())
    {
        if (debug_print)
        {
            std::cerr << "Hamiltonian must be selfadjoint:\n" << data;
        }
        throw std::runtime_error("Hamiltonian must be selfadjoint");
    }
}