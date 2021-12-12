#include <iostream>

using namespace std;

struct AddressParent{
    Parent *p;
};

struct AddressChild{
    Child *c;
};

struct Parent{
    string nama;
    AddressParent *next;
    AddressParent *prev;
};

struct Child{
    string nama;
    AddressChild *next;
};

struct ListParent{
    AddressParent *first;
    AddressParent *last;
};

struct ListChild{
    AddressChild *first;
    AddressChild *last;
};