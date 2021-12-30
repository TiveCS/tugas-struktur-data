#include <iostream>

using namespace std;

template<class T>
class ListNode{
private:
    T *info;
    ListNode<T> *next = NULL;
    ListNode<T> *prev = NULL;
public:
    // Set nilai infotype
    void setInfo(T *v){
        info = v;
    }

    // Mendapatkan nilai infotype
    T getInfo(){
        return *info;
    }

    // Set node next
    void setNext(ListNode<T> *n){
        next = n;
    }

    // Set node prev
    void setPrev(ListNode<T> *n){
        prev = n;
    }

    // Mendapatkan node next dari node saat ini
    ListNode<T>* getNext(){
        return next;
    }

    // Mendapatkan node prev dari node saat ini
    ListNode<T>* getPrev(){
        return prev;
    }

    // Cek apakah node saat ini memiliki node prev
    bool hasPrev(){
        return prev != NULL;
    }

    // Cek apakah node saat ini memiliki node next
    bool hasNext(){
        return next != NULL;
    }
};

template<class T>
class List{
private:
    ListNode<T> *first = NULL;
    ListNode<T> *last = NULL;
public:
    // Tambahkan node baru kedalam list (insert last)
    void addElement(ListNode<T> *e){
        if (first == NULL){ // Jika first kosong, isi first
            first = e;
            last = e;
        }else{ // Tambahkan node baru sebagai node last
            e->setPrev(last);
            last->setNext(e);

            last = e;
        }
    }
    // Tambahkan node baru kedalam list (insert first)
    void addElement(T *info){
        ListNode<T> *n = new ListNode<T>();
        n->setInfo(info);
        
        addElement(n);
    }

    // Hapus node jika ada dalam list
    void removeElement(ListNode<T> *e){
        if (e == getFirst()){ // Jika node target adalah first (delete first)
            if (e->getNext() == NULL){ // Hapus node jika hanya satu-satunya node
                first = NULL;
                last = NULL;
            }else{ // Gantikan next dari node sebagai pengganti node
                first = getFirst()->getNext();
                first->setPrev(NULL);
            }
        }else if(e == getLast()){ // Jika node target adalah last (delete last)
            if (e->getPrev() == NULL){ // Hapus node jika hanya satu satunya node
                first = NULL;
                last = NULL;
            }else{ // Hapus node last, lalu gantikan dengan node prev dari last
                last = getLast()->getPrev();
                last->setNext(NULL);
            }
        }else{ // Jika node berada ditengah (delete after)
            ListNode<T>* p = e->getPrev();
            ListNode<T>* n = e->getNext();

            p->setNext(n);
            n->setPrev(p);
        }
    }
    // Hapus node pertama yang memiliki nilai infotype yang sama
    void removeElement(T info){
        ListNode<T> *n = findElement(info);
        if (n != NULL){
            removeElement(n);
        }
    }

    // Mencari node sesuai nilai infotype
    ListNode<T>* findElement(T info){
        if (getFirst() != NULL){ // Cek jika list tidak kosong
            if (getFirst()->getInfo() == info){ // Jika infotype first benar, return first
                return getFirst();
            }else if (getLast()->getInfo() == info){ // Jika infotype last benar, return last
                return getLast();
            }else{ // Jika infotype first dan last belum benar, lakukan linear search pada tiap elemen
                ListNode<T> *n = getFirst();
                while(n != NULL){ // Linear search
                    if (n->getInfo() == info){ // Jika node saat ini benar, return node
                        return n;
                    }
                    n = n->getNext(); // Pindah ke node selanjutnya
                }
            }
        }

        return NULL; // Jika node tidak ditemukan
    } 

    // Set node first menjadi node baru
    void setFirst(ListNode<T> *f){
        first = f;
    }

    // Mendapatkan ukuran list dengan linear loop
    int size(){
        int count = 0;
        ListNode<T> *n = getFirst();
        while(n != NULL){
            count++;
            n = n->getNext();
        }
        return count;
    }

    // Cek jika node adalah node first
    bool isFirst(ListNode<T> *n){
        if (first != NULL){
            return first == n;
        }
        return false;
    }

    // Cek jika node adalah node last
    bool isLast(ListNode<T> *n){
        if (last != NULL){
            return last == n;
        }
        return false;
    }

    // Mendapatkan node first
    ListNode<T>* getFirst(){
        return first;
    }

    // Mendapatkan node last
    ListNode<T>* getLast(){
        return last;
    }
};