
//
// Created by hieu- on 05.05.2020.
//

#include <iostream>
#include "stack.h"

using namespace std;


template<typename T>
stack_t<T>::stack_t(int initialSize) {
    size = initialSize;
    values = new T[size]; // Speicher für float Array der Größe 'size' reservieren
}
template<typename T>
stack_t<T>::~stack_t() {
    delete values;
}
template<typename T>
bool stack_t<T>::isFull() {
    if (insertPos == size) {
        return true;
    }
}
template<typename T>
bool stack_t<T>::isEmpty() {
    return insertPos == 0;
}
template<typename T>
void stack_t<T>::push(T f) {             //auf den stack legen
    if (isFull())
        increaseSize();
    values[insertPos] = f;
    insertPos += 1;

}
template<typename T>
void stack_t<T>::pop() {                        //vom stack nehmen
    if (isEmpty()){
        throw runtime_error("fail pop");
    }
    insertPos -= 1;
}
template<typename T>
T stack_t<T>::top() {                       //oberstes element vom stack

    if (isEmpty()){
        throw runtime_error("fail top");

    }
    return values[insertPos -1];

}

template<typename T>
void stack_t<T>::increaseSize() {
    size *= 2;
    T * temp = new T[size]; // Neues Array mit neuer Größe

    for (int i = 0; i < size/2; i++) // Alle alten Werte übernehmen
        temp[i] = values[i];

    delete[] values; // Speicher vom alten Array wieder freigeben
    values = temp; // Der 'values' Pointer zeigt jetzt auf unser neues Array
}


//...

int main()
{
    cout << "Hello World" << endl;
    stack_t<int> name(5);
    try{
        name.push(1);
        cout << name.top() << endl;
        name.pop();


    } catch (exception& x) {
        cout << x.what() << endl;

    }
    return 0;
}



