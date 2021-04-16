

#ifndef DOUBLENODE_HPP
#define DOUBLENODE_HPP

#include <iostream>

using namespace std;

template <class Type>
class DoubleNode{
    public:
        DoubleNode(Type& person);
        ~DoubleNode();
        
        Type& getElement();
        string toString();
        
        DoubleNode<Type> * getNext() const;
        void setNext(DoubleNode<Type> * p);
        
        DoubleNode<Type> * getPrevious() const;
        void setPrevious(DoubleNode<Type> * p);
        
    private:
        Type *p;
        DoubleNode<Type> *next;
        DoubleNode<Type> *previous;
};

template <class Type>
DoubleNode<Type>::DoubleNode(Type& person) {
    this->p=new Type(person);
    this->next=nullptr;
    this->previous=nullptr;
}

template <class Type>
DoubleNode<Type>::~DoubleNode() {
}

template <class Type>
Type& DoubleNode<Type>::getElement(){
    return *p;
}

template <class Type>
string DoubleNode<Type>::toString(){
    return p->toString();
}

template <class Type>
DoubleNode<Type> * DoubleNode<Type>::getNext() const{
    return this->next;
}

template <class Type>
void DoubleNode<Type>::setNext(DoubleNode<Type> * p){
    this->next=p;
}

template <class Type>
DoubleNode<Type> * DoubleNode<Type>::getPrevious() const{
    return this->previous;
}

template <class Type>
void DoubleNode<Type>::setPrevious(DoubleNode<Type> * p){
    this->previous=p;
}


#endif /* DOUBLENODE_HPP */

