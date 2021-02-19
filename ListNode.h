#ifndef LISTNODE_H
#define LISTNODE_H
#include <string>
template<typename T>
class ListNode{
    public:
        ListNode(){
            val = NULL;
            next = nullptr;
            prev = nullptr;
        };
        ListNode(T val): val(val){
            val = val;
            next = nullptr;
            prev = nullptr;
        };
    private:
        ListNode<T> * next;
        ListNode<T> * prev;
        T val;
    friend class ListItr;
    friend class List;
};
#endif