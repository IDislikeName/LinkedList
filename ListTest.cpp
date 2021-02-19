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
    list.insertAtTail(6);
    list.insertAfter(4,list.find(3));
    list.insertBefore(5,list.find(6));
    list.remove(6);
    cout<<list.size()<<endl;
    list.printList();
    int s =list.sum(list.find(3),list.find(5));
    cout<<s<<endl;
    List list2 = list.findSequence(12);
    list2.printList();

}

