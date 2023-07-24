#ifndef __CONSTANTS__
#define __CONSTANTS__

using namespace std;

#include <cmath>

class Constants
{
public:
    Constants() = default;
    ~Constants() = default;

    const double pi = acos(-1);

    const double eps_0 = 8.85418*pow(10,-12);
    const double mu_0 = 4*pi*pow(10,-7);
};
#endif