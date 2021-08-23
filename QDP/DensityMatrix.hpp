#ifndef DENSITYMATRIX_HPP_
#define DENSITYMATRIX_HPP_

#include "Operator.hpp"

class DensityMatrix : public Operator
{
public:
    DensityMatrix(const MatrixData& data); // copies data
    DensityMatrix(const Operator& op); // copies operator

private:
    void check_properties() const;
    bool check_unit_trace() const;
};

#endif
