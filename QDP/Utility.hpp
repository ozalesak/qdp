#ifndef UTILITY_HPP_
#define UTILITY_HPP_

#include <iostream>
#include <Eigen/Dense>

using MatrixData = Eigen::MatrixXcd;

namespace detail
{
    const auto atol = 1e-15;
    const auto rtol = 1e-12;
}

extern bool debug_print;

static inline bool fuzzy_compare(const MatrixData& left, const MatrixData& right)
{
    return ((left - right).array().abs() <= (detail::rtol * left.array().abs()).max((detail::rtol * right.array().abs()).max(detail::atol))).all();
}

static inline bool fuzzy_compare(double left, double right)
{
    return std::abs(left - right) <= std::max(detail::atol, detail::rtol * std::max(std::abs(left), std::abs(right)));
}



#endif