#ifndef __SOLENOID__
#define __SOLENOID__

#include <iostream>

#include "include/Constants.h"

class Solenoid : public Constants
{
public:
    Solenoid(int N_loops, float radius, float current, float i_pos, float f_pos);
    ~Solenoid() = default;

    int getN() { return N; };
    float getL() { return L; };
    float getn() { return n; };
    float getR() { return R; };
    float getXi() { return Xi; };
    float getXf() { return Xf; };
    float getm() { return m; };


    float calcInfSolBField(float pos, float I);
    float calcBField(float length, float angle, float I);
    float calcMagMoment(float I);

private:
    int N = 1;
    float L = 1;
    float n = 1;
    float R = 1;
    float Xi = 0;
    float Xf = 1;
    float m = 1;
};
#endif