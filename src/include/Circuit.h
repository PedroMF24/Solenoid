#ifndef __CIRCUIT__
#define __CIRCUIT__

#include <iostream>

#include "include/Constants.h"

class Circuit : public Constants
{
public:
    Circuit(float voltage, float current);
    // Circuit(float voltage, float resistance);
    // Circuit(float current, float resistance);
    Circuit(float voltage, float current, float resistance);
    ~Circuit() = default;

    int getV() { return V; };
    float getI() { return I; };
    float getRes() { return Res; };

    friend std::ostream& operator<<(ostream& s, const Circuit& p);

private:
    float V = 1;
    float I = 1;
    float Res = 1;
};
#endif