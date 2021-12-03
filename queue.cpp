#include "queue.h"

// circular array implementation of queue
queue::queue(int sz){
    _size = 0;
    _capacity = sz;
    _front = 0;
    _arr = new TYPE[_capacity];
}

queue::queue(const queue& q) {
    _capacity = q._capacity;
    _size = q._size;
    _front = q._front;
    _arr = new TYPE[q._capacity];
    for (int i = 0; i < _capacity; i++) {
        _arr[i] = q._arr[i];
    }
}

queue& queue::operator = (const queue& q) {
    if (this == &q) {
        return *this;
    }
    delete[] _arr;
    _capacity = q._capacity;
    _size = q._size;
    _front = q._front;
    _arr = new int[_capacity];
    for (int i = 0; i < _size; i++) {
        _arr[i] = q._arr[i];
    }
    return *this;
}

void queue::enqueue(int data){
    if (_size == _capacity) {
        _capacity = _capacity * 2;
        TYPE *temp = new TYPE[_capacity];
        for (int i = 0; i < _size; i++) {
            temp[i] = _arr[i];
        }
        delete[] _arr;
        _arr = new TYPE[_capacity];
        for (int i = 0; i < _size; i++) {
            _arr[i] = temp[i];
        }
        _arr[(_front + _size)%_capacity] = data;
        _size++;
        delete[] temp;
    } else {
        _arr[(_front + _size)%_capacity] = data;
        _size++;
    }
}

TYPE queue::dequeue(){
    if (_size == 0) {
        throw EmptyQueueException();
    }
    else {
        int temp = (_front++) % _capacity;
        _size--;
        return _arr[temp];
    }
}

void queue::dump(ostream &os){
    for(int i=_front; i<_front + _size; i++)
        os<<_arr[i%_capacity]<<endl;
}

int queue::size(){
    return _size;
}

TYPE& queue::front() {
    return _arr[_front];
}

int queue::capacity() {
    return _capacity;
}

bool queue::empty(){
    if (_size == 0) {
        return true;
    }
    else {
        return false;
    }
}

queue::~queue() {
    delete []_arr;
}