#ifndef DLL_H
#define DLL_H

#include <vector>
using std::vector;

struct Node;

class DLL {
private:
    Node* head;
    Node* tail;

    int size;

public:
    DLL();
    DLL(const DLL& copy);
    ~DLL();

    double& operator [](int n);
    double& operator [](int n) const;

    void insertStart(double val);
    void insertEnd(double val);
    void popFront();
    void popEnd();
    void printDLL();

    const int& getSize();

};

#endif