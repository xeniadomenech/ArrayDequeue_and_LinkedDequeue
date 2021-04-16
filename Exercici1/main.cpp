
#include <iostream>
#include <stdexcept>
#include "ArrayDeque.h"

using namespace std;


int main(int argc, char** argv) {
    int i, opcio, num;
    string arr_opcions[] = {"Inserir element al davant de la cua", 
    "Inserir element al darrera de la cua", "Treure element pel davant de la cua",
    "Treure element pel darrere de la cua", "Consultar primer element", 
    "Consultar darrer element", "Imprimir tot el contingut de l'ArrayDeque", 
    "Sortir"};
    cout << "Quina mida vol que tingui la seva cua" << endl;
    cin >> num;
    ArrayDeque *cua = new ArrayDeque(num);
    do{
        cout << "Què vols fer?" <<endl;
        for (i=0; i<8 ; i++){
            cout << i+1 << ". " << arr_opcions[i] << endl;
        }
        cin >> opcio;
        switch(opcio){
            case 1: 
                cout << endl;
                try {
                    cout << "Quin element vol inserir?" << endl;
                    cin >> num;
                    cua->enqueueFront(num);
                }catch(const out_of_range& ex){
                    cout << ex.what() << endl;
                }
                cout << endl;
                break;
            case 2: 
                cout << endl;
                try {
                    cout << "Quin element vol inserir?" << endl;
                    cin >> num;
                    cua->enqueueBack(num);
                }catch(const out_of_range& ex){
                    cout << ex.what() << endl;
                }
                cout << endl;
                break;
            case 3:
                cout << endl;
                try {
                    cout << "Eliminant element del davant..." << endl;
                    cua->dequeueFront();
                }catch(const out_of_range& ex){
                    cout << ex.what() << endl;
                }
                cout << endl;
                break;
            case 4:
                cout << endl;
                try {
                    cout << "Eliminant element del darrere..." << endl;
                    cua->dequeueBack();
                }catch(const out_of_range& ex){
                    cout << ex.what() << endl;
                }
                cout << endl;
                break;
            case 5:
                cout << endl;
                try {
                    num=cua->getFront();
                    if (num!=0)
                        cout << "El primer element de la cua és " << num << endl;
                }catch(const out_of_range& ex){
                    cout << ex.what() << endl;
                }
                cout << endl;
                break;
            case 6:
                cout << endl;
                try {
                    num=cua->getBack();
                    if (num!=0)
                        cout << "El darrer element de la cua és " << num << endl;
                }catch(const out_of_range& ex){
                    cout << ex.what() << endl;
                }
                cout << endl;
                break;
            case 7:
                cout << endl;
                cua->print();
                cout << endl;
                break;
            case 8:
                cout << "Fins la propera" << endl;
                break;
            default: 
                cout << "Error en la opció." << endl;break;
        }
    }while(opcio!=8);
    return 0;
}

