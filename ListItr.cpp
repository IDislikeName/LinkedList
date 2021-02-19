#include <iostream>
#include "List.h"
#include "ListNode.h"
using namespace std;

ListItr::ListItr(){
    current = nullptr;
};
ListItr::ListItr(ListNode<int>* theNode){
    current = theNode;
};
bool ListItr::isPastEnd() const{
    return(current->next->val==NULL);
};
bool ListItr::isPastBeginning() const{
    return(current->prev->val==NULL);
};
void ListItr::moveForward(){
    if(!isPastEnd()){
        current = current->next;
    }
    else{
        cout<<"end of list"<<endl;
    }    
}
void ListItr::moveBackward(){
    if(!isPastBeginning()){
        current = current->prev;
    }
    else{
        cout<<"start of list"<<endl;
    }    
}
int ListItr::retrieve() const{
    return current->val;
}