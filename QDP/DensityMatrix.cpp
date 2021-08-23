#include "DensityMatrix.hpp"

DensityMatrix::DensityMatrix(const Operator& op)
    : Operator(op)
{
    check_properties();
}

DensityMatrix::DensityMatrix(const MatrixData& data)
    : Operator(data)
{
    check_properties();
}

void DensityMatrix::check_properties() const
{
    if (!check_selfadjoint())
    {
        if (debug_print)
        {
            std::cerr << "Density Matrix must be selfadjoint:\n" << data << std::endl;
        }
        throw std::runtime_error("Density Matrix must be selfadjoint");
    }

    if (!check_unit_trace())
    {
        if (debug_print)
        {
            std::cerr << "Density Matrix must be of trace 1:\n" << data << std::endl;
        }
        throw std::runtime_error("Density Matrix must be of trace 1");
    }
}

bool DensityMatrix::check_unit_trace() const
{
    const auto& tr = get_trace();
    return fuzzy_compare(tr.real(), 1) && fuzzy_compare(tr.imag(), 0);
}