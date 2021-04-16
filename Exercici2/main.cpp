
#include <iostream>
#include <string>
#include <stdexcept>
#include "LinkedDeque.hpp"

using namespace std;


int main(int argc, char** argv) {
    int i, opcio;
    int num;
    LinkedDeque<int> *cua = new LinkedDeque<int>();
    string options[]={ "Inserir element al davant de la cua",
    "Inserir element al darrera de la cua", 
    "Treure element pel davant de la cua", 
    "Treure element pel darrera de la cua", "Consultar el primer element",
    "Consultar el darrer element", "Imprimir tot el contingut de la LinkedDequeue", 
    "Provem constructor copia",
    "Sortir"};
    do{
        cout << "Què vol fer?" << endl;
        for(i=0; i<9; i++){
            cout << i+1 << ". " << options[i] << endl;
        }
        cin >> opcio;
        switch(opcio){
            case 1:
                try{
                    cout << "Doni el numero per introduir al inici" << endl;
                    cin >> num;
                    cua->enqueueFront(num);
                    cua->print();
                }catch(exception& ex){
                    cout << ex.what() << endl;
                }
                break;
            case 2:
                try{
                    cout << "Doni el numero per introduir al final" << endl;
                    cin >> num;
                    cua->enqueueBack(num);
                    cua->print();
                }catch(exception& ex){
                    cout << ex.what() << endl;
                }
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
                try{
                    cout << "El primer element de la cua es " << cua->getFront() << endl;
                }catch(exception& ex){
                    cout << ex.what() << endl;
                }
                break;
            case 6:
                try{
                    cout << "El darrer element de la cua es " << cua->getBack() << endl;
                }catch(exception& ex){
                    cout << ex.what() << endl;
                } 
                break;
            case 7:
                cua->print();
                break;
            case 8:{
                LinkedDeque<int> *aux = new LinkedDeque<int>();
                cout << "Doni el numero per introduir (0 PER ACABAR)" << endl;
                cin >> num;
                while(num!=0){
                    aux->enqueueBack(num);
                    cout << "Doni el numero (0 PER ACABAR)" << endl;
                    cin >> num;
                }
                cua = new LinkedDeque<int>(*aux);
                cua->print();
                break;
            }
            case 9:
                cout << "Fins la propera" << endl;
                break;
            default:
                cout << "Error en la opcio" << endl;
                break;
        }
        
    }while(opcio!=9);
    delete cua;
    return 0;
}

