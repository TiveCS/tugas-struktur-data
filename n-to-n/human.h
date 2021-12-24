#include <iostream>
#include "list.cpp"

using namespace std;

class Human{
private:
    string name;
public:
    Human(string n){
        name = n;
    }

    void setName(string n){
        name = n;
    }

    string getName(){
        return name;
    }
};

class Child;

class Parent : public Human{
using Human::Human;

private:
    List<Human> *childrens = new List<Human>();
public:
    void addChild(Child *c);
    void removeChild(string name);
    ListNode<Human>* findChildNode(string name);
    Child* findChild(string name);
    void showChildrens();
    bool hasChild(string name);

    List<Human>* getChildrens(){
        return childrens;
    }
};

class Child : public Human{
using Human::Human;

private:
    List<Human> *parents = new List<Human>();
public:
    void addParent(Parent *p);
    void removeParent(Parent *p);
    ListNode<Human>* findParentNode(string name);
    Parent* findParent(string name);
    void showParents();
    bool hasParent(string name);

    List<Human>* getParents(){
        return parents;
    }
};
