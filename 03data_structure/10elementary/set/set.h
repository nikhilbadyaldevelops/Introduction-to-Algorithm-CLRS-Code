#include "../linked_list/doubly/list_with_sentinal/list.h"
class Set{
private:
    List l;
    int size ;
public:
    Set(int size_):l(),size(size_){}
    Set(){}

    void insert(int value){
        l.insert(value);
    }

    void union_(Set& s){
        l.nil->prev->next = s.l.nil->next;
        s.l.nil->next->prev = l.nil->prev;
        l.nil->prev = s.l.nil->prev;
        s.l.nil->prev->next = l.nil;
        l.rename(s.l);
    }

};
