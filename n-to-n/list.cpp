#include <iostream>

using namespace std;

template<class T>
class ListNode{
private:
    T *info;
    ListNode<T> *next = NULL;
    ListNode<T> *prev = NULL;
public:
    void setInfo(T *v){
        info = v;
    }

    T getInfo(){
        return *info;
    }

    void setNext(ListNode<T> *n){
        next = n;
    }

    void setPrev(ListNode<T> *n){
        prev = n;
    }

    ListNode<T>* getNext(){
        return next;
    }

    ListNode<T>* getPrev(){
        return prev;
    }

    bool hasPrev(){
        return prev != NULL;
    }

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
    void addElement(ListNode<T> *e){
        if (first == NULL){
            first = e;
            last = e;
        }else{
            e->setPrev(last);
            last->setNext(e);

            last = e;
        }
    }
    void addElement(T *info){
        ListNode<T> *n = new ListNode<T>();
        n->setInfo(info);
        
        addElement(n);
    }

    void removeElement(ListNode<T> *e){
        if (e == getFirst()){
            if (e->getNext() == NULL){
                first = NULL;
                last = NULL;
            }else{
                first = getFirst()->getNext();
                first->setPrev(NULL);
            }
        }else if(e == getLast()){
            if (e->getPrev() == NULL){
                first = NULL;
                last = NULL;
            }else{
                last = getLast()->getPrev();
                last->setNext(NULL);
            }
        }else{
            ListNode<T>* p = e->getPrev();
            ListNode<T>* n = e->getNext();

            p->setNext(n);
            n->setPrev(p);
        }
    }
    void removeElement(T info){
        ListNode<T> *n = findElement(info);
        if (n != NULL){
            removeElement(n);
        }
    }

    ListNode<T>* findElement(T info){
        if (getFirst() != NULL){
            if (getFirst()->getInfo() == info){
                return getFirst();
            }else if (getLast()->getInfo() == info){
                return getLast();
            }else{
                ListNode<T> *n = getFirst();
                while(n != NULL){
                    if (n->getInfo() == info){
                        return n;
                    }
                    n = n->getNext();
                }
            }
        }

        return NULL;
    } 

    void setFirst(ListNode<T> *f){
        first = f;
    }

    int size(){
        int count = 0;
        ListNode<T> *n = getFirst();
        while(n != NULL){
            count++;
            n = n->getNext();
        }
        return count;
    }

    bool isFirst(ListNode<T> *n){
        if (first != NULL){
            return first == n;
        }
        return false;
    }

    bool isLast(ListNode<T> *n){
        if (last != NULL){
            return last == n;
        }
        return false;
    }

    ListNode<T>* getFirst(){
        return first;
    }

    ListNode<T>* getLast(){
        return last;
    }
};