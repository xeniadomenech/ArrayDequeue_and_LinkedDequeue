

#ifndef DOUBLENODE_HPP
#define DOUBLENODE_HPP

#include <iostream>

using namespace std;

template <class Type>
class DoubleNode{
    public:
        DoubleNode(Type);
        ~DoubleNode();
        
        const Type& getElement() const;
        
        DoubleNode<Type> * getNext() const;
        void setNext(DoubleNode<Type> * aux);
        
        DoubleNode<Type> * getPrevious() const;
        void setPrevious(DoubleNode<Type> * aux);
        
    private:
        Type n;
        DoubleNode<Type> *next;
        DoubleNode<Type> *previous;
};

template <class Type>
DoubleNode<Type>::DoubleNode(Type num) {
    this->n=num;
    this->next=nullptr;
    this->previous=nullptr;
}

template <class Type>
DoubleNode<Type>::~DoubleNode() {}

template <class Type>
const Type& DoubleNode<Type>::getElement() const{
    return this->n;
}

template <class Type>
DoubleNode<Type> * DoubleNode<Type>::getNext() const{
    return this->next;
}

template <class Type>
void DoubleNode<Type>::setNext(DoubleNode<Type> * aux){
    this->next=aux;
}

template <class Type>
DoubleNode<Type> * DoubleNode<Type>::getPrevious() const{
    return this->previous;
}

template <class Type>
void DoubleNode<Type>::setPrevious(DoubleNode<Type> * aux){
    this->previous=aux;
}


#endif /* DOUBLENODE_HPP */

