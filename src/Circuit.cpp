#include "include/Circuit.h"

Circuit::Circuit(float voltage, float current) {
    V = voltage;
    I = current;
    Res = V/I;
}

// Circuit::Circuit(float voltage, float resistance) {
//     V = voltage;
//     Res = resistance;
//     I = V/Res;
// }
// Circuit::Circuit(float current, float resistance) {
//     I = current;
//     Res = resistance;
//     V = Res*I;
// }

Circuit::Circuit(float voltage, float current, float resistance) {
    float res = voltage/current;
    if (abs(res - resistance) <= 0.1) {
        V = voltage;
        I = current;
        Res = resistance;
    } else {
        fprintf(stderr,"**Ohm's Law does not check out in Circuit");
        exit(0);
    }
}

ostream& operator<<(std::ostream& s, const Circuit& p) {
    s << "Circuit specs: ";
    s << "V = " << p.V << " V, ";
    s << "I = " << p.I << " A, ";
    s << "R = " << p.Res << " Ohms.";
    return s;
}