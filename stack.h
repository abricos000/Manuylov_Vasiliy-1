#ifndef STACK_H
#define STACK_H
#include "estackexception.h"
#include "estackempty.h"
#include <functional>

template <class T>
class Stack
{
public:
    ~Stack(); // деструктор
    int Size(); // размер стека
    void Clear(); // удаление из стека всех узлов
    void Push(const T &k); //Помещение объекта в стек;
    const T Pop(); // Извлечение объекта из стека;
   void Print(std::function<void(const T &k)> f) const;//метод перебора значений

private:
    struct Node
    {
        const T key;

        Node *pr = nullptr;
    };

    Node *nd = nullptr;

    int size = 0;
};
//Метод перебора значений стека
template <class T>void Stack<T>::Print(std::function<void(const T &k)> f) const
{
    Node *tmp = nd; // указатель на последний элемент

    while (tmp != nullptr)
    {
        f(tmp->key); // вызов функции обратной связи

        tmp = tmp->pr;//Указатель на предыдущий
    }
}
//размерность стека
template <class T> int Stack<T>::Size()
{
    return size;
}

template <class T> void Stack<T>::Clear()
{
    while (nd != nullptr)
    {
        Node *tmp = nd;

        nd = nd->pr;

        delete tmp;
    }
}
//деструктор
template <class T>Stack<T>::~Stack()
{
    Clear();
}

// Помещение объекта в стек;
template <class T>void Stack<T>::Push(const T &k)
{
    Node *node = new Node{ k, nd };
    if (node == nullptr)
    {
        throw Exception("Память заполнена.");
    }

    nd = node;

    size++;
}

// Извлечение объекта из стека;
template <class T> const T Stack<T>::Pop()
{
    if (nd == nullptr)
    {
        throw EStackEmpty();
    }

    const T k = nd->key;

    Node *tmp = nd;

    nd = nd->pr;

    delete tmp;

    size--;

    return k;
}
#endif // STACK_H
