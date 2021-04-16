
#include "ArrayDeque.h"

ArrayDeque::ArrayDeque(const int max) {
    _max_size=max;
    _size=-1;
    vector <int> vtemp(max);
    _data=vtemp;
}


void ArrayDeque::enqueueBack(const int key){
    if(!isFull())
        _data[++_size]=key;
    else
            throw out_of_range("EXCEPCIÓ: enqueueBack(const int key): cua plena");
}


void ArrayDeque::dequeueFront(){
    if(!isEmpty()){
        for(int i=0; i<_size; i++)
            _data[i]=_data[i+1];
        _size--;
    }else
        throw out_of_range("EXCEPCIÓ: dequeueFront(): cua buida");
}


bool ArrayDeque::isFull(){
    return (_size+1==_max_size);
}

bool ArrayDeque::isEmpty(){
    return (_size==-1);
}


void ArrayDeque::print(){
    if(isEmpty()){
        cout << "Cua=[]" << " mida: 0 " << endl;
    }else{
        cout << "Cua=[" ;
        for (int i=0; i<_size; i++)
            cout << _data[i] << ", " ;
        cout << _data[_size] << "]" << endl;
    }
}


const int ArrayDeque::getFront(){
    if(!isEmpty())
        return _data[0];
    else
        throw out_of_range("EXCEPCIÓ: getFront(): cua buida");
}


void ArrayDeque::enqueueFront(const int elem){
    int aux1, aux2=elem;
    if(!isFull()){
        for(int i=0; i<=_size; i++){
            aux1=_data[i];
            _data[i]=aux2;
            aux2=aux1;
        }
        _data[++_size]=aux2;
    }else
        throw out_of_range("EXCEPCIÓ: enqueueFront(const int elem): cua plena");
}


void ArrayDeque::dequeueBack(){
    if(!isEmpty())
        _size--;
    else
        throw out_of_range("EXCEPCIÓ: dequeueBack(): cua buida");
}


const int ArrayDeque::getBack(){
    if(!isEmpty())
        return _data[_size];
    else
        throw out_of_range("EXCEPCIÓ: getBack: cua buida");
}