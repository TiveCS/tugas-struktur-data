#include "human.cpp"

void showList(List<Human> l){
    ListNode<Human> *n = l.getFirst();
    string space = "";
    while(n != NULL){
        cout << space << n->getInfo().getName();
        space = ", ";
        n = n->getNext();
    }
    cout << "\n";
}

int main(){

    // List parent & child
    List<Human> listParent, listChild;

    // Deklarasi parent
    Parent *a = new Parent("Ahmad");
    Parent *b = new Parent("Annisa");
    Parent *c = new Parent("Fathan");
    Parent *d = new Parent("Lutfi");
    Parent *e = new Parent("Yudi");

    // Deklarasi child
    Child *x = new Child("Reynaldi");
    Child *y = new Child("Yahya");
    Child *z = new Child("Eka");

    // Tambah parent kedalam list
    listParent.addElement(a);
    listParent.addElement(b);
    listParent.addElement(c);

    // Tambah child kedalam list
    listChild.addElement(x);
    listChild.addElement(y);
    listChild.addElement(z);

    // Melihat daftar parent & child
    showList(listParent);
    showList(listChild);

    cout << "\n";
    x->addParent(a);
    x->addParent(b);

    a->showChildrens();
    b->showChildrens();
    x->showParents();

    z->addParent(c);
    c->showChildrens();

    return 0;
}
