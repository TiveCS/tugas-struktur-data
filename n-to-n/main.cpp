#include "human.cpp"

// Tampilkan tiap elemen dalam list
void showList(List<Human> l){
    ListNode<Human> *n = l.getFirst();
    string space = "";
    cout << "[";
    while(n != NULL){
        cout << space << n->getInfo().getName();
        space = ", ";
        n = n->getNext();
    }
    cout << "]\n";
}

// Tampilkan relasi tiap elemen dalam list
void showListRelation(List<Human> l){
    ListNode<Human> *n = l.getFirst();
    while(n != NULL){
        n->getInfo().showRelation();
        n = n->getNext();
    }
    cout << "\n";
}

// Tambahkan elemen baru ke list
void addHumanToList(List<Human> &l, Human *h){
    l.addElement(h->getNode());
}

// Tambahkan relasi antara kedua elemen (insert parent & insert child of parent)
Human* addRelation(Human *h1, Human *h2){
    return h1->addRelation(h2);
}

// Hapus relasi antara kedua elemen (delete parent & delete child of parent)
Human* removeRelation(Human *h1, Human *h2){
    return h1->removeRelation(h2);
}

// Tampilkan relasi dalam sebuah elemen
Human* showRelation(Human *h){
    return h->showRelation();
}

// Menghitung total umur pada setiap relasi yang ada dari objek
int totalUmurRelasi(Human *h){
    int total = 0;
    ListNode<Human> *n = h->getRelations()->getFirst();
    while(n != NULL){
        total += n->getInfo().getAge();
        n = n->getNext();
    }
    return total;
}

// Menghitung total umur pada setiap relasi dari objek dan umur objek itu sendiri
int totalUmurGenerasi(Human *h){
    return totalUmurRelasi(h) + h->getAge();
}

// Mencari objek dari list untuk menemukan parameter nama 
// memiliki relasi pada objek-objek dalam list.
Human* findRelation(List<Human> l, string nama){
    ListNode<Human> *n = l.getFirst();
    while(n != NULL){
        if (n->getInfo().findHuman(nama) != NULL){
            return n->getInfoPtr();
        }
        n = n->getNext();
    }
    return NULL;
}

int main(){

    // Implementasi N to N tipe ke-1
    // Menggunakan analogi: Orang tua & Anak (Parent & Child)

    // List parent
    List<Human> listParent; //listChild;

    // Parent
    Human *a = new Human("Iqbal", 20);
    Human *b = new Human("Annisa", 21);
    Human *c = new Human("Lutfi", 21);
    Human *d = new Human("Ahmad", 21);
    Human *e = new Human("Robert", 32);

    // Child
    Human *v = new Human("Revo", 5);
    Human *w = new Human("Adi", 2);
    Human *x = new Human("Eka", 4);
    Human *y = new Human("Nurdin", 1);
    Human *z = new Human("Theo", 3);

    // Tambahkan objek ke parent list
    addHumanToList(listParent, a);
    addHumanToList(listParent, b);
    addHumanToList(listParent, c);
    addHumanToList(listParent, d);
    addHumanToList(listParent, e);

    // Tampilkan daftar objek tiap list
    showList(listParent);
    cout << "\n";

    // Membuat relasi dari semua elemen yang ada
    addRelation(x, a);
    addRelation(x, b);
    addRelation(v, d);
    addRelation(d, w);
    addRelation(d, y);
    addRelation(z, e);

    // Tampilkan kondisi relasi saat ini
    showListRelation(listParent);

    // Hapus relasi beberapa elemen
    removeRelation(d, w);
    removeRelation(x, a);
    removeRelation(x, b);

    // Tampilkan kondisi relasi saat ini
    showListRelation(listParent);
    
    cout << "Cek '" << w->getName() << "' memiliki relasi dengan '" << d->getName() << "': " << (w->findHuman(d->getName()) != NULL) << "\n";
    cout << "Cek '" << z->getName() << "' memiliki relasi dengan '" << e->getName() << "': " << (z->findHuman(e->getName()) != NULL) << "\n";

    cout << "\n";

    cout << "Umur Relasi '" << e->getName() << "': " << totalUmurRelasi(e) << "\n";
    cout << "Umur Generasi '" << e->getName() << "': " << totalUmurGenerasi(e) << "\n";

    cout << "\n";
    Human* related = findRelation(listParent, v->getName());
    cout << "Objek yang memiliki relasi dengan '" << v->getName() << "': " << related->getName() << "\n\n";
    return 0;
}
