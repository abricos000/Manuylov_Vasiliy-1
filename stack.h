#ifndef STACK_H
#define STACK_H
#include "estackexception.h"
#include "estackempty.h"

template <class T>
class Stack
{
public:
    ~Stack(); // деструктор
    int Size(); // размер стека
    void Clear(); // удаление из стека всех узлов
    void Push(const T &k); //Помещение объекта в стек;
    const T Pop(); // Извлечение объекта из стека;


private:
    struct Node
    {
        const T key;

        Node *pr = nullptr;
    };

    Node *nd = nullptr;

    int size = 0;
};
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
