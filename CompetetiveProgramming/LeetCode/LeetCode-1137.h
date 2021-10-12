#pragma once

class Solution
{
  public:
    size_t tribonacci(size_t nvalue)
    {
        if (nvalue <= 1)
            return nvalue;

        size_t T0{0}, T1{1}, T2{1};

        for (size_t idx{3}; idx < nvalue; ++idx)
        {
            auto T3 = T0 + T1 + T2;
            T0 = T1;
            T1 = T2;
            T2 = T3;
        }
        return T2 + T1 + T0;
    }
};
