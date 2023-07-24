#ifndef __NEEDLE__
#define __NEEDLE__

#include <iostream>

#include "Constants.h"

class Needle : public Constants
{
public:
    Needle(float mass, float length, float current, float i_pos, float f_pos, float theta);
    ~Needle() = default;

    float calcMagMoment(float Chi, float B);
    float calcTorque(float mag_moment, float B, float theta);
    float mvEq();

    int getm() { return m; };
    float getM() { return M; };
    float getTheta() { return Theta; };
    float getL() { return L; };
    float getXi() { return Xi; };
    float getXf() { return Xf; };
    float getPos() { return Pos; };


    friend std::ostream& operator<<(ostream& s, const Needle& p);

private:
    float m = 1;
    float M = 1;
    float Theta = 1;
    float L = 1;
    float I_center = 1;
    float I_end = 1;
    float Xi = 0;
    float Xf = 1;
    float Pos = 0;
};
#endif