
#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string.h>

using namespace std;

class Patient {
public:
    Patient(Patient& p);
    Patient(string, string, string, string);
    virtual ~Patient();
    
    string toString() const;
    
private:
    string identificador, nom, cognom, estat;
};

#endif /* PATIENT_H */

