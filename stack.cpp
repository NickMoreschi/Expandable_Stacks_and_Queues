#include "stack.h"

stack::stack(int sz) :_capacity(sz), _tos(-1)
{
    _arr = new TYPE[_capacity]{0};
}

stack::stack(const stack& s) : _tos(s._tos), _capacity(s._capacity)
{
    _arr = new TYPE[_capacity];
    for (int i = 0; i < _capacity; i++) {
        _arr[i] = s._arr[i];
    }
}

stack& stack::operator = (const stack& s)
{
    if (this == &s) {
        return *this;
    }
    delete []_arr;
    _capacity = s._capacity;
    _tos = s._tos;
    if (_capacity > 0) {
        _arr = new int[_capacity];
        for (int i = 0; i < _capacity; i++) {
            _arr[i] = s._arr[i];
        }
    }
    return *this;
}

void stack::pop()
{
    if (empty()) {
        throw EmptyStackException();
    } else {
        --_tos;
    }
}

TYPE& stack::top()
{
    if (empty()) {
        throw EmptyStackException();
    } else {
        return _arr[_tos];
    }
}

bool stack::empty()
{
    return _tos == -1;
}

int stack::size()
{
    return _tos + 1;
}

int stack::capacity()
{
    return _capacity;
}

void stack::push(const TYPE x)
{
    if (_tos+1 == _capacity) {
        _capacity = _capacity * 2;
        TYPE *temp = new TYPE[_capacity];
        for (int i = 0; i < size(); i++) {
            temp[i] = _arr[i];
        }
        delete[] _arr;
        _arr = new TYPE[_capacity];
        for (int i = 0; i < size(); i++) {
            _arr[i] = temp[i];
        }
        _arr[++_tos] = x;
        delete[] temp;
    }
    else {
        _arr[++_tos] = x;
    }
}

void stack::dump(ostream &o)
{
    while (!empty()) {
        o << top();
        pop();
        o << " ";
    }
    o << endl;
}

stack::~stack()
{
    delete []_arr;
}