#include "DLL.h"

#include <iostream>
using namespace std;

struct Node {
    double data;
    Node* next;
    Node* prev;
};

DLL::DLL()
{
    size = 0;

    head = new Node;
    tail = new Node;

    head->data = 0.0;
    tail->data = 0.0;

    head->prev = nullptr;
    head->next = tail;

    tail->prev = head;
    tail->next = nullptr;
}

DLL::DLL(const DLL &copy)
{
    size = 0;

    head = new Node;
    tail = new Node;

    head->data = 0.0;
    tail->data = 0.0;

    head->prev = nullptr;
    head->next = tail;

    tail->prev = head;
    tail->next = nullptr;

    for (int i = 0; i < copy.size; i++) {
        insertEnd(copy[i]);
    }
}

DLL::~DLL()
{
    Node* current = head;
    Node* to_be_del = nullptr;

    while (current) {
        to_be_del = current;
        current = current->next;

        delete to_be_del;
    }
}

double &DLL::operator[](int n)
{
    Node* current = head;

    while (n > 0) {
        current = current->next;
        n--;
    }

    return current->next->data;
}

double &DLL::operator[](int n) const
{
    Node* current = head;

    while (n > 0) {
        current = current->next;
        n--;
    }

    return current->next->data;
}

void DLL::insertStart(double val)
{
    Node* newNode = new Node;
    newNode->data = val;

    newNode->next = head->next;
    newNode->prev = head;

    head->next->prev = newNode;
    head->next = newNode;

    size++;
}

void DLL::insertEnd(double val)
{
    Node* newNode = new Node;
    newNode->data = val;

    newNode->next = tail;
    newNode->prev = tail->prev;

    tail->prev->next = newNode;
    tail->prev = newNode;

    size++;
}

void DLL::popFront()
{
    head->next->next->prev = head;

    Node* head_next_past = head->next;
    head->next = head_next_past->next;

    delete head_next_past;

    size--;
}

void DLL::popEnd()
{
    tail->prev->prev->next = tail;

    Node* tail_prev_past = tail->prev;
    tail->prev = tail_prev_past->prev;

    delete tail_prev_past;

    size--;
}

void DLL::printDLL()
{
    Node* current = head;
    while (current) {
        if (current != head && current != tail) {
            cout << current->data << "<->";
        }
        current = current->next;
    }
    cout << "NULL" << endl;
}

const int &DLL::getSize()
{
    return size;
}
