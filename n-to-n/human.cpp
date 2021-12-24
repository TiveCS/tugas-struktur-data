#include "human.h"

bool Parent::hasChild(string name){
    ListNode<Human> *n = Parent::getChildrens()->getFirst();
    while(n != NULL){
        if (n->getInfo().getName() == name) return true;
        n = n->getNext();
    }
    return false;
}

void Parent::addChild(Child *c){
    if (Parent::hasChild(c->getName())){
        return;
    }
    Parent::getChildrens()->addElement(c);
    c->getParents()->addElement(this);
}

ListNode<Human>* Parent::findChildNode(string name){
    ListNode<Human> *n = Parent::getChildrens()->getFirst();

    while(n != NULL){
        if (n->getInfo().getName() == name) return n;
        n = n->getNext();
    }

    return NULL;
}

Child* Parent::findChild(string name){
    Child *found = NULL;
    ListNode<Human> *n = findChildNode(name);

    if (n != NULL){
        Human h = n->getInfo();
        found = (Child *) &h;
    }

    return found;
}

void Parent::removeChild(string name){
    ListNode<Human> *n = findChildNode(name);
    if (Parent::getChildrens()->getFirst() == n){
        Parent::getChildrens()->setFirst(n->getNext());
        n->getNext()->setPrev(NULL);
    }
}


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

bool Child::hasParent(string name){
    ListNode<Human> *n = Child::getParents()->getFirst();
    while(n != NULL){
        if (n->getInfo().getName() == name) return true;
        n = n->getNext();
    }
    return false;
}

void Child::addParent(Parent *p){
    if (Child::hasParent(p->getName())){
        return;
    }
    Child::getParents()->addElement(p);
    p->getChildrens()->addElement(this);
}

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