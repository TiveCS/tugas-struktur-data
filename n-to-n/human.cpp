#include "human.h"

// Cek nama child dari parent
bool Parent::hasChild(string name){
    ListNode<Human> *n = Parent::getChildrens()->getFirst();
    while(n != NULL){
        if (n->getInfo().getName() == name) return true;
        n = n->getNext();
    }
    return false;
}

// Tambahkan child ke parent
void Parent::addChild(Child *c){
    if (Parent::hasChild(c->getName())){
        return;
    }
    Parent::getChildrens()->addElement(c);
    c->getParents()->addElement(this);
}

// Cari node child dari parent
ListNode<Human>* Parent::findChildNode(string name){
    ListNode<Human> *n = Parent::getChildrens()->getFirst();

    while(n != NULL){
        if (n->getInfo().getName() == name) return n;
        n = n->getNext();
    }

    return NULL;
}

// Cari objek child berdasarkan nama dari parent
Child* Parent::findChild(string name){
    Child *found = NULL;
    ListNode<Human> *n = findChildNode(name);

    if (n != NULL){
        Human h = n->getInfo();
        found = (Child *) &h;
    }

    return found;
}

// Hapus child dari parent
void Parent::removeChild(string name){
    ListNode<Human> *n = findChildNode(name);
    if (Parent::getChildrens()->getFirst() == n){
        Parent::getChildrens()->setFirst(n->getNext());
        n->getNext()->setPrev(NULL);
    }
}

// Lihat daftar child dari parent
void Parent::showChildrens(){
    ListNode<Human> *n = getChildrens()->getFirst();
    string space = "";

    cout << getName() << "\'s Childrens: ";
    if (n == NULL){
        cout << "No children";
    }else{
        while(n != NULL){
            cout << space << n->getInfo().getName();
            n = n->getNext();
            space = ", ";
        }
    }
    cout << "\n";
}

// Cek jika nama parent ada dari child
bool Child::hasParent(string name){
    ListNode<Human> *n = Child::getParents()->getFirst();
    while(n != NULL){
        if (n->getInfo().getName() == name) return true;
        n = n->getNext();
    }
    return false;
}

// Tambahkan parent kedalam child
void Child::addParent(Parent *p){
    if (Child::hasParent(p->getName())){
        return;
    }
    Child::getParents()->addElement(p);
    p->getChildrens()->addElement(this);
}

// TODO
// Hapus parent dari child
void Child::removeParent(Parent *p){

}

// TODO
// Cari node parent berdasarkan nama dari child
ListNode<Human>* Child::findParentNode(string name){
    ListNode<Human> *found = NULL;
    return found;
}

// TODO
// Cari objek parent berdasarkan nama dari child
Parent* Child::findParent(string name){
    Parent *found = NULL;
    return found;
}

// Tampilkan daftar parent dari child
void Child::showParents(){
    ListNode<Human> *n = Child::getParents()->getFirst();

    cout << getName() << "\'s Parents: ";
    string space = "";

    if (n == NULL){
        cout << "No parents";
    }else{
        while (n != NULL){
            cout << space << n->getInfo().getName();
            n = n->getNext();
            space = ", ";
        }
    }
    cout << "\n";
}