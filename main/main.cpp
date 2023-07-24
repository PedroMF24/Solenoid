#include "../src/include/Solenoid.h"
#include "../src/include/Circuit.h"
#include "../src/include/Needle.h"


void printTitle();


int main() {

    printTitle();

    float I = 1.34;
    float V = 6.4;

    Solenoid S1(500, 0.03, I, 0, 0.15);
    Solenoid S2(500, 0.03, I, 0.16, 0.31);
    
    Constants C;
    Circuit Circ(V, I);

    Needle needle(0.01, 0.01, I, 0.15, 0.16, C.pi/4);

    float m_needle = needle.calcMagMoment(0,0);

    // float B_S1 = S1.infSolBField(needle.getXi(), needle.getPos(), I);
    // float B_S2 = S2.infSolBField(needle.getXf(), -needle.getPos(), I);

    float angleS2_N_pole = needle.getTheta();
    float angleS1_N_pole = C.pi/2 + needle.getTheta();

    float B_S1 = S1.calcBField(needle.getL(), angleS1_N_pole, -I);
    float B_S2 = S2.calcBField(needle.getL(), angleS2_N_pole, I);

    cout << "B_S1 = " << B_S1 << " B_S2 = " << B_S2 << " T" << endl;

    B_S1 = abs(B_S1);
    B_S2 = abs(B_S2);

    if (B_S2 < B_S1) { cout << "Points left!" << endl; }
    else if (B_S1 < B_S2) { cout << "Points right!" << endl; }
    else { cout << "Does not move!" << endl; }
    
    // cout << S.infSolBField(0.05, 1) << " T" << endl;
    // cout << S.infSolBField(1, 1) << " T" << endl;

    // cout << C << endl;

    /*
    if (needle.calcTorque(1,1) > 0)
    {
        // Turns to one side
    } else if (needle.calcTorque(1,1) > 0) {
        // Turns to the other side
    }

    //

    while (needle.calcTorque(1,1) != 0) {
        if (needle.calcTorque(1,1) > 0)
        {
            // Turns to one side
        } else if (needle.calcTorque(1,1) > 0) {
            // Turns to the other side
        }
    }
    // Print side.
    
    */

    return 0;
}

void printTitle() {
    cout << "* ======================================== *" << endl;
    cout << "*  ___     _                      _        *" << endl;
    cout << "* | __| __| | _  _  __ _  _ _  __| | __ _  *" << endl;
    cout << "* | _| / _` || || |/ _` || '_|/ _` |/ _` | *" << endl;
    cout << "* |___|\\__/_| \\_._|\\__/_||_|  \\__/_|\\__/_| *" << endl;
    cout << "*                                          *"  << endl;
    cout << "* ======================================== *" << endl << endl;
}