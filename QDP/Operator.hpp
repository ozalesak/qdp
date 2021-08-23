#ifndef OPERATOR_HPP_
#define OPERATOR_HPP_

#include "Utility.hpp"

class Operator
{
public:
    Operator(int dim); // constructs zero matrix(dim, dim)
    Operator(const MatrixData& data); // copies data

    bool check_selfadjoint() const;

    const MatrixData& get_data() const;
    decltype(std::declval<MatrixData>().trace()) get_trace() const;

    static Operator commutator(const Operator& A, const Operator& B);

protected:
    MatrixData data;
};
#endif