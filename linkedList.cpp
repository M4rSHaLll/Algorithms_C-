#include <iostream>


//class List "описание списка"

template<typename T>
class List
{
public:
    List();
    ~List();

    int GetSize() { return Size; }
    void push_back(T data);
    void pop_front();
    void clear();    
    void push_front(T data);
    void insert(T data, int index);
    void removeAt(int index);

    T& operator[](const int index);
private:

    // описание элемента списка

    template<typename T>
    class Node
    {
    public:
        Node* pNext;
        T data;
        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;
    Node<T>* head;

};



// реализация методов класса List

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}


template<typename T>
List<T>::~List()
{
    clear();
}


template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else {
        Node<T>* current = this->head;

        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }

    Size++;
}


template<typename T>
void List<T>::pop_front()
{
    Node<T> *temp = head;

    head = head->pNext;

    delete temp;
    Size--;
}


template<typename T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}


template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}


template <typename T>
void List<T>::push_front(T data) 
{
    head = new Node<T>(data,head);
    Size++;
}


template <typename T>
void List<T>::insert(T data, int index)
{
    if (index == 0)
    {
        push_front(data);
    }
    else {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        Node<T>* newNode = new Node<T>(data, previous->pNext);
        previous->pNext = newNode;
        Size++;
    }
}


template<typename T>
void List<T>::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T> previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        Node<T>* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;

        delete toDelete;
        Size--;
    }
}



// функция main

int main()
{
    using namespace std;

    List<int> list1;
    
    list1.push_back(5);
    list1.push_back(10);

    cout << list1.GetSize();
    return 0;
}