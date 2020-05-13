//
// Created by hieu- on 11.05.2020.
//

#ifndef PROJECTS_STACK_H
#define PROJECTS_STACK_H
template <typename T>
class stack_t {
public:
    stack_t(int initialSize);   // initialSize = anfängliche Größe des Arrays
    ~stack_t();// ...
    T top();
    void pop();
    void push(T);
    bool isEmpty();
private:
    void increaseSize(); // private?, sollte ja nicht von außen aufgerufen werden
    int size;
    bool isFull();
    T * values; // Array für die Werte des 'Stacks'
    int insertPos = 0;
    int error = 0;
    //...
};




#endif //PROJECTS_STACK_H
