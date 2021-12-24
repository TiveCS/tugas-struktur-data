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
    Parent *a = new Parent("Adi");
    Parent *b = new Parent("Budi");
    Parent *c = new Parent("Tono");

    // Deklarasi child
    Child *x = new Child("Reynaldi");
    Child *y = new Child("Yahya");
    Child *z = new Child("Udin");

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

    // Tambah child ke parent 'a'
    a->addChild(x);
    a->addChild(y);
    a->showChildrens();

    c->addChild(z);

    x->showParents();

    return 0;
}
