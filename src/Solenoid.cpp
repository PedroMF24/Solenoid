#include "include/Solenoid.h"

Solenoid::Solenoid(int N_loops, float radius, float current, float i_pos, float f_pos)
{
    N = N_loops;
    Xi = i_pos;
    Xf = f_pos;
    L = f_pos - i_pos;
    n = N/L;
    R = radius;
    m = N*current*pi*pow(R,2);
}

float Solenoid::calcInfSolBField(float pos, float I) {
    float B = 0;
    // Inside Solenoid
    if (pos >= Xi && pos <= Xf) {
        B = mu_0*n*I;
    }
    // Outside Solenoid
    else if (pos < Xi || pos > Xf) {
        B = 0;
    }
    else {
        fprintf(stderr, "**Incorrect position");
    }
    return B;
}

float Solenoid::calcMagMoment(float I) {
    return N*I*pi*pow(R,2); //  Lembrar cos(theta)
}

float Solenoid::calcBField(float length, float angle, float I) {
    float temp_I = I;
    float pos = sin(angle);
    float aux1 = abs((Xf + length/2 - pos));
    float aux2 = abs((Xi - length/2 + pos));
    
    float r_dist = (aux2 > aux1) ? aux1 : aux2;
    // if (r_dist == aux2) { temp_I = -I; }

    float B = mu_0*(N*temp_I)/(2*pi*r_dist);
    return B;
}

