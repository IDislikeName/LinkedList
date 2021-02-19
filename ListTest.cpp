#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;


int main(){
    List list;
    list.printList();
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(6);
    list.find(6);
    list.remove(6);
    cout<<list.size()<<endl;
    list.printList();
}

