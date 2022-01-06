#include <iostream>
using namespace std;

#include "list_child.h"

void connect(address_parent P, address_child &C);
void disconnect(address_child &C);

int main() {
    cout << "Bentuk I - Contoh Relasi 1-N" << endl;

    List_parent LP;
    List_child LC;
    address_child C;
    address_parent P;

    createList(LP);
    createList(LC);

    /** insert parent */
    P = alokasi_parent("Annisa");
    insertFirst(LP, P);
    P = alokasi_parent("Fathan");
    insertFirst(LP, P);
    P = alokasi_parent("Dudung");
    insertFirst(LP, P);
    P = alokasi_parent("Adi");
    insertFirst(LP, P);
    P = alokasi_parent("Putri");
    insertFirst(LP, P);


    cout<<"list parent"<<endl;
    printInfo(LP);

    /** insert child */
    C = alokasi("Aisyah");
    insertFirst(LC, C);
    C = alokasi("Andien");
    insertFirst(LC, C);
    C = alokasi("Eka");
    insertFirst(LC, C);
    C = alokasi("Alif");
    insertFirst(LC, C);
    C = alokasi("Putra");
    insertFirst(LC, C);

    cout<<"\nlist child sebelum direlasikan"<<endl;
    printInfo(LC);

    /** RELASIKAN CHILD DENGAN PARENT */
    P = findElm(LP, "Annisa");
    C = findElm(LC, "Andien");
    connect(P,C);
    C = findElm(LC, "Aisyah");
    connect(P,C);

    P = findElm(LP, "Putri");
    C = findElm(LC, "Putra");
    connect(P,C);

    P = findElm(LP,"Fathan");
    C = findElm(LC, "Eka");
    connect(P,C);
    C = findElm(LC, "Alif");
    connect(P,C);

    cout<<"\nlist child setelah direlasikan"<<endl;
    printInfo(LC);

    C = findElm(LC, "Putra");
    disconnect(C);

    cout<<"\nlist child setelah relasi dihapus"<<endl;
    printInfo(LC);

    return 0;
}

void connect(address_parent P, address_child &C) {
    parent(C) = P;
}

void disconnect(address_child &C) {
    parent(C) = NULL;
}
