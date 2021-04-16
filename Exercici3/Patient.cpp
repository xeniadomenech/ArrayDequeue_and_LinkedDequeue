

#include "Patient.h"

Patient::Patient(string identificador, string nom, string cognom, string estat) {
    this->identificador=identificador;
    this->nom=nom;
    this->cognom=cognom;
    this->estat=estat;
}

Patient::Patient(Patient& p){
    this->identificador=p.identificador;
    this->nom=p.nom;
    this->cognom=p.cognom;
    this->estat=p.estat;
}

Patient::~Patient() {
}

string Patient::toString()const{
    return nom + ", " + cognom + ", " + identificador + ", " + estat;
}
