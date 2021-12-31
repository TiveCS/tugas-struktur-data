#include "human.h"

Human* Human::addRelation(Human *anotherHuman){
    this->getRelations()->addElement(anotherHuman->getNode());
    anotherHuman->getRelations()->addElement(this->getNode());
    return this;
}

Human* Human::removeRelation(Human *anotherHuman){
    this->getRelations()->removeElement(anotherHuman->getNode());
    anotherHuman->getRelations()->removeElement(this->getNode());
    return this;
}

Human* Human::findHuman(string name){
    ListNode<Human> *n = this->getRelations()->getFirst();

    while(n != NULL){
        if (n->getInfo().getName() == name) return n->getInfoPtr();
        n = n->getNext();
    }

    return NULL;
}

List<Human>* Human::findHuman(int age){
    List<Human> *found = new List<Human>();
    ListNode<Human> *n = this->getRelations()->getFirst();

    while(n != NULL){
        if (n->getInfo().getAge() == age){
            found->addElement(n);
        }
        n = n->getNext();
    }

    return found;
}

Human* Human::showRelation(){
    ListNode<Human> *n = Human::getRelations()->getFirst();
    cout << getName() << ": [";

    string space = "";
    while(n != NULL){
        cout << space << n->getInfo().getName();
        space = ", ";
        n = n->getNext();
    }
    cout << "]\n";
    return this;
}