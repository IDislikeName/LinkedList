#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

List::List(){
    head = new ListNode<int>();
    tail = new ListNode<int>();
    head->next = tail;
    tail->prev = head;
    count = 0;
};
List::~List(){
    makeEmpty();
    delete head;
    delete tail;
};
List::List(const List& source):
    head(source.head),tail(source.tail),count(source.count)
    {}
List& List::operator=(const List& source){
    head = source.head;
    tail = source.tail;
    count = source.count;
    return *this;
};
bool List::isEmpty() const{
    if(head->next==tail){
        return true;
    }
    else{
        return false;
    }
};
void List::makeEmpty(){
    ListNode<int>* temp = head;
    ListNode<int>* temp2 = head->next;
    while(!isEmpty()){
        delete temp2;
        temp = temp->next;
        temp2 = temp;
    }
    delete temp;
    return;
};
ListItr List::first(){
    return ListItr(head->next);
};
ListItr List::last(){
    return ListItr(tail->prev);
}
void List::insertAfter(int x, ListItr position){
    ListNode<int>* newNode = new ListNode<int>(x);
    position.current->next->prev = newNode;
    newNode->next = position.current->next;
    position.current->next = newNode;
    newNode->prev = position.current;
};
void List::insertBefore(int x, ListItr position){
    ListNode<int>* newNode = new ListNode<int>(x);
    position.current->prev->next = newNode;
    newNode->prev = position.current->prev;
    position.current->prev = newNode;
    newNode->next = position.current;
};
void List::insertAtTail(int x){
    ListNode<int>* newNode = new ListNode<int>(x);
    ListItr itr = last();
    itr.current ->next = newNode;
    newNode->prev = itr.current;
    newNode->next = tail;
    tail->prev = newNode;
    return;
};

void List::remove(int x){
    ListItr itr = find(x);
    itr.current->prev->next = itr.current->next;
    itr.current->next->prev = itr.current->prev;
    delete itr.current;
};

ListItr List::find(int x){
    ListItr itr = first();
    while(itr.retrieve()!=x&&!itr.isPastEnd()){
        itr.moveForward();
    };
    if(itr.current->val==NULL){
        return NULL;
    }
    else{
        return itr;
    }
    
};
int List::size() const{
    ListItr itr = ListItr(head);
    int c = 0;
    while(!itr.isPastEnd()){
        c++;
        itr.moveForward();
    }
    return c;
};
void List::printList(){
    ListItr itr = first();
    for(int i=0; i<size();i++){
        int num = itr.retrieve();
        cout<<num<<endl;
        itr.moveForward();
    }    
}
List List::findSequence(int x){
    int s=0;
    ListItr itr1 = first();
    ListItr itr2 = itr1;
    List l;
    while(s!=x){
       s = sum(itr1,itr2);
       if(s==x){
           while(itr1.current!=itr2.current){
               l.insertAtTail(itr1.retrieve());
               itr1.moveForward();
           }
           l.insertAtTail(itr1.retrieve());
           return l;
       }
       else if(s>x||itr2.isPastEnd()){
           itr1.moveForward();
           itr2 = itr1;
       }
       else if(s<x){
           itr2.moveForward();
       }
       if(itr1.isPastEnd()){
           cout<<"can't find it"<<endl;
           return l;
       }
    }

}

int List::sum(ListItr pos1, ListItr pos2){
    int s = pos1.retrieve();
    while(pos1.current!=pos2.current){
        pos1.moveForward();
        s+= pos1.retrieve();
    }
    return s;
}
