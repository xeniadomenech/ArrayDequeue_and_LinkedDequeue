
#ifndef ARRAYDEQUE_H
#define ARRAYDEQUE_H

#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

class ArrayDeque {
public:
    ArrayDeque(const int);
    void enqueueBack(const int key);
    void dequeueFront();
    bool isFull();
    bool isEmpty();
    void print();
    const int getFront();
    void enqueueFront(const int);
    void dequeueBack();
    const int getBack();
private:
    int _max_size;
    int _size;
    vector<int> _data;

};

#endif /* ARRAYDEQUE_H */

