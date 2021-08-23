#include "Operator.hpp"

Operator::Operator(int dim)
    : data(MatrixData::Zero(dim, dim))
{
}

Operator::Operator(const MatrixData& data)
    : data(data)
{
    if (data.innerSize() != data.outerSize())
    {
        throw std::runtime_error("Operator is not square");
    }
}

bool Operator::check_selfadjoint() const
{
    return fuzzy_compare(data, data.adjoint());
}

const MatrixData& Operator::get_data() const
{
    return data;
}

decltype(std::declval<MatrixData>().trace()) Operator::get_trace() const
{
    return data.trace();
}

Operator Operator::commutator(const Operator& A, const Operator& B)
{   
    assert(A.data.innerSize() == B.data.innerSize());
    Operator result(A.data.innerSize());
    result.data.noalias() =  A.data * B.data - B.data * A.data;
    return result;
}
