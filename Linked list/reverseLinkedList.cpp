#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int val;
        node *next;
        node(int val){
            this->val = val;
            this->next = NULL;
        }
        
};
node *head = NULL,*tail=NULL;
void insertAtTail(int val){
    node *tem = new node(val);
    if(head==NULL){
        head = tem;
        tail = tem;
    }else{
        tail->next = tem;
        tail = tem;
    }
}
void reverseList(){
    node *pre = NULL,*cur=head;
    while(cur!=NULL){
        node *tem = cur->next;
        cur->next = pre;
        if(cur->next==NULL)
            tail = cur;
        pre = cur;
        cur = tem;    
    }
    head = pre;
}
void printList(){
    node *tem = head;
    while(tem!=NULL){
        cout << tem->val << ' ';
        tem = tem->next;
    }
    cout << "\n";
}

int main(){
    for (int i = 1; i <= 5;i++){
        insertAtTail(i);
    }
    printList();
    reverseList();
    printList();
    // cout << "Head => " << head->val << " tail => " << tail->val << endl;
}