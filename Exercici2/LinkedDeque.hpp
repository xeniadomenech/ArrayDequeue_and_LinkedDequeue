

#ifndef LINKEDDEQUE_HPP
#define LINKEDDEQUE_HPP

#include "DoubleNode.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

template <class Type>
class LinkedDeque {
    public:
        LinkedDeque();
        LinkedDeque(const LinkedDeque<Type>& q);
        virtual ~LinkedDeque();
        void enqueueFront (Type& f);
        void enqueueBack(Type& f);
        void dequeueFront();
        void dequeueBack();

        bool isEmpty();
        void print();
        const Type& getFront();
        const Type& getBack();
        int size();
        
    private:
        int _size;
        DoubleNode<Type> *front;
        DoubleNode<Type> *rear;

};

template <class Type>
LinkedDeque<Type>::LinkedDeque() {
    _size=0;
    front = nullptr;
    rear = nullptr;
}

template <class Type>
LinkedDeque<Type>::~LinkedDeque() {
    while(!isEmpty())
        dequeueFront();
    delete front;
    delete rear;
}

template <class Type>
LinkedDeque<Type>::LinkedDeque(const LinkedDeque<Type>& q){
    
    DoubleNode<Type> *copia=q.front;
    _size=q._size;
    
    if(copia==nullptr){
        
        front=nullptr;
        rear=nullptr;
        
    }else{
        
        front=copia;
        DoubleNode<Type> *nodeActual = front;
        nodeActual->setPrevious(nullptr);
        
        for(int i=1; i<_size; i++){
                
            //Guardo els node següent i anterior al meu node actual
            DoubleNode<Type> *prevNode = new DoubleNode<Type>(copia->getElement());
            copia = copia->getNext();
            DoubleNode<Type> *nextNode = new DoubleNode<Type>(copia->getElement());
                
            //Modifico relacions
            nodeActual->setNext(nextNode);
            nodeActual = nodeActual->getNext();
            nodeActual->setPrevious(prevNode);

        }
            
        rear=nodeActual;
        rear->setNext(nullptr);

    }
}


template <class Type>
void LinkedDeque<Type>::enqueueFront(Type& f){
    
    DoubleNode<Type> *nouNode = new DoubleNode<Type>(f);
    
    if(isEmpty()){
        
        rear=nouNode;
        front=nouNode;
        
    }else{
        
        nouNode->setNext(front);
        nouNode->setPrevious(nullptr);
        front->setPrevious(nouNode);
        front=nouNode;
        
    }
    _size++;         
}


template <class Type>
void LinkedDeque<Type>::enqueueBack(Type& f){
    
    DoubleNode<Type> *nouNode = new DoubleNode<Type>(f);
    
    if(isEmpty()){
        
        rear=nouNode;
        front=nouNode;
        
    }else{
     
        nouNode->setPrevious(rear);
        nouNode->setNext(nullptr);
        rear->setNext(nouNode);
        rear=nouNode;
    
    }
    _size++;
}

template <class Type>
void LinkedDeque<Type>::dequeueFront(){
    DoubleNode<Type> *nodeEliminar=front;
    
    if(isEmpty()){
        
        throw out_of_range("EXCEPCIO: CUA BUIDA");
        
    }else{
         
        front=front->getNext();
        
        //Cas en el que només tenim un element a la cua
        if(front==nullptr)
            rear=front;
        //Cas en el que tinc més d'un element
        else
            front->setPrevious(nullptr);
        
        delete nodeEliminar;
        _size--;
        
    }
}

template <class Type>
void LinkedDeque<Type>::dequeueBack(){
    DoubleNode<Type> *nodeEliminar=rear;
    if(isEmpty()){
        
        throw out_of_range("EXCEPCIO: CUA BUIDA");
    
    }else{
        
        rear=rear->getPrevious();
        
        //Cas en el que només tenim un element a la cua
        if(rear==nullptr)
            front=rear;
        //Cas en el que tinc més d'un element
        else
            rear->setNext(nullptr);
        
        delete nodeEliminar;
        _size--;
      
    }
}

template <class Type>
bool LinkedDeque<Type>::isEmpty(){
    return(_size==0);
}

template <class Type>
void LinkedDeque<Type>::print(){
    cout << "Cua [ ";
    if(isEmpty())
        cout << " ]" << endl;    
    else{
        DoubleNode<Type> *aux = front;
        for(int i=0; i<_size; i++){
            cout << aux->getElement() << " ";
            aux=aux->getNext();
        }
        cout << "]" << endl;
    }        
}

template <class Type>
const Type& LinkedDeque<Type>::getFront(){
    if(!isEmpty())
        return front->getElement();
    else
        throw out_of_range("EXCEPCIO: CUA BUIDA");
}

template <class Type>
const Type& LinkedDeque<Type>::getBack(){
    if(!isEmpty())
        return rear->getElement();
    else
        throw out_of_range("EXCEPCIO: CUA BUIDA");
}

template <class Type>
int LinkedDeque<Type>::size(){
    return _size;
}



#endif /* LINKEDDEQUE_HPP */

