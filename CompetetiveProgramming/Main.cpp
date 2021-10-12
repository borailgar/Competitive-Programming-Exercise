#include "CodeForces/CodeForce-1598A.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <stack>

int main()
{
    Grid_t<6> grid{{0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0}}; // EXPECTED: TRUE
    Grid_t<4> grid_n{{0, 1, 1, 1, 1, 1, 1, 0}};           // EXPECTED: FALSE

    depth_first_search(grid_n, {0, 0});

    return 0;
}
