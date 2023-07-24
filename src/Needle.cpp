#include "include/Needle.h"

Needle::Needle(float mass, float length, float current, float i_pos, float f_pos, float theta) {
    M = mass;
    L = length;
    Xi = i_pos;
    Xf = f_pos;
    Theta = theta;
    Pos = sin(theta);
    I_center = 1/12*M*pow(L,2); 
}

float Needle::calcMagMoment(float Chi, float B) {
    m = 1; // Chi*pi* Lembrar cos(theta)
    return m;
}

float calcTorque(float magMoment, float B, float theta) {
    return magMoment*B*sin(theta);
}
