#include <iostream>
#include "list.cpp"

using namespace std;

class Human{
private:
    string name;
    int age;
    ListNode<Human> *node;
    List<Human> *relations;
public:
    Human(string n, int a){
        name = n;
        age = a;
        node = new ListNode<Human>();
        relations = new List<Human>();

        node->setInfo(this);
    }

    // Tambahkan relasi dengan objek lain
    Human* addRelation(Human *anotherHuman);

    // Hapus relasi dengan objek lain
    Human* removeRelation(Human *anotherHuman);

    // Cari objek dari list relasi dengan nama yang ditentukan
    Human* findHuman(string name);

    // Cari objek dari list relasi dengan umur yang ditentukan
    List<Human>* findHuman(int age);

    bool isRelated(Human *h);

    // Tampilkan relasi
    Human* showRelation();

    void setName(string n){
        name = n;
    }

    string getName(){
        return name;
    }

    void setAge(int a){
        age = a;
    }

    int getAge(){
        return age;
    }

    ListNode<Human>* getNode(){
        return node;
    }

    List<Human>* getRelations(){
        return relations;
    }
};