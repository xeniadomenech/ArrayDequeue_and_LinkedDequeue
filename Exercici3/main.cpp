
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include "Patient.h"
#include "LinkedDeque.hpp"

using namespace std;

void llegirFitxer (LinkedDeque<Patient> *cua){
    int i;
    string nomfile;
    string info[4];
    Patient *pacient;
    ifstream fitxer;
    cout << "Doni el nom del fitxer" << endl;
    cin >> nomfile;
    fitxer.open(nomfile,ios::in);
    cout << endl;
    cout << "Reading file..." << endl;
    cout << endl;
    if(!fitxer)
        cout << "Fitxer buit." << endl;
    else{
        string linea;
        
        while(getline(fitxer,linea)){
            replace(linea.begin(), linea.end(), ',', ' ');
            stringstream ss(linea);
            string temp;
            i=0;
            while (ss >> temp){
                
                info[i]=temp;
                i++;
            }
            if(info[3].compare("NOT_OK")==0){
                pacient= new Patient(info[0], info[1], info[2], info[3]);
                cua->enqueueFront(*pacient);
            }else if(info[3].compare("OK")==0){
                pacient= new Patient(info[0], info[1], info[2], info[3]);
                cua->enqueueBack(*pacient);
            }else{
                 cout << "Error en l'estat de " << info[1] << " (No s'ha introduit el pacient)" << endl;
            }
        }
    }
    fitxer.close();
}


int main(int argc, char** argv) {
    int i, opcio;
    bool inserir=true;
    string identificador, nom, cognom, estat;
    Patient *pacient;
    LinkedDeque<Patient> *cua = new LinkedDeque<Patient>();
    string options[]={"Llegir un fitxer amb les entrades de pacients", 
    "Imprimir la cua de pacients", "Eliminar el primer pacient de la cua",
    "Eliminar el darrer pacient de la cua", 
    "Inserir n entrades de pacients des de teclat (0 per finalitzar)", 
    "Consultar el primer pacient de la cua", "Consultar el darrer pacient de la cua",
    "Sortir"};
    do{
        cout << "Què vol fer?" << endl;
        for(i=0; i<8; i++){
            cout << i+1 << ". " << options[i] << endl;
        }
        cin >> opcio;
        switch(opcio){
            case 1:
                llegirFitxer(cua);
                break;
            case 2:
                cua->print();
                break;
            case 3:
                try{
                    cua->dequeueFront();
                    cua->print();
                }catch(exception& ex){
                    cout << ex.what() << endl;
                }
                break;
            case 4:
                try{
                    cua->dequeueBack();
                    cua->print();
                }catch(exception& ex){
                    cout << ex.what() << endl;
                }
                break;
            case 5:
                do{
                    cout << "Doni l'identificador, el nom, el cognom i l'estat del pacient\n(0 PER ACABAR)" << endl;
                    cin >> identificador;
                    inserir=false;
                    if(identificador.compare("0")!=0){
                        inserir=true;
                        cin >> nom;
                        cin >> cognom;
                        cin >> estat;
                        if(estat.compare("NOT_OK")==0){
                            pacient = new Patient(identificador, nom, cognom, estat);
                            cua->enqueueFront(*pacient);
                        } 
                        else if(estat.compare("OK")==0){
                            pacient = new Patient(identificador, nom, cognom, estat);
                            cua->enqueueBack(*pacient);
                        }
                        else{
                            cout << "Error en l'estat de " << nom << " (No s'ha introduit el pacient)" << endl;
                        }
                    }
                }while(inserir);
                break;
            case 6:
                try{
                    cout << "El primer pacient de la cua es " << cua->getFront().toString() << endl;
                }catch(exception& ex){
                    cout << ex.what() << endl;
                }
                break;
            case 7:
                try{
                    cout << "L'ultim pacient de la cua es " << cua->getBack().toString() << endl;
                }catch(exception& ex){
                    cout << ex.what() << endl;
                }
                break;
            case 8:
                cout << "Fins la propera" << endl;
                break;
        }
        
    }while(opcio!=8);
    delete cua;
    return 0;
}

