#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
    ~Node()
    {
        // int val = this->val;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory freed for value " << this->val << "\n";
    }
};
Node *head = NULL, *tail = NULL;
void insertAtHead(int val)
{
    Node *tem = new Node(val);
    if (head == NULL)
    {
        head = tem;
        tail = tem;
    }
    else
    {
        tem->next = head;
        head = tem;
    }
}
void insertAtTail(int val)
{
    Node *tem = new Node(val);
    if (head == NULL)
    {
        head = tem;
        tail = tem;
    }
    else
    {
        tail->next = tem;
        tail = tem;
    }
}
void insertAtPosition(int pos, int val)
{
    Node *tem = new Node(val);
    Node *findPos = head;
    if (pos < 1)
    {
        cout << "Error! Invalid position\n";
        return;
    }
    if (pos == 1)
    {
        insertAtHead(val);
        return;
    }
    while (true)
    {
        if ((pos == 1 || findPos->next == NULL))
            break;
        pos--;
        findPos = findPos->next;
    }
    if (pos != 1)
    {
        insertAtTail(val);
        return;
    }
    tem->next = findPos->next;
    findPos->next = tem;
}
void printList()
{
    Node *tem = head;
    while (tem != NULL)
    {
        cout << tem->val << ' ';
        tem = tem->next;
    }
    cout << '\n';
}
void removeDuplicate(){
    Node *cur=head;
    
    while(cur!=NULL){
        if((cur->next!=NULL)&&cur->next->val==cur->val){
            Node *nextOfNext = cur->next->next;
            Node *nodeToDelete = cur->next;
            nodeToDelete->next = NULL;
            delete (nodeToDelete);
            cur->next = nextOfNext;
        }else{
            cur = cur->next;
        }
    }
}
void removeDuplicateFromUnsortedList(){
    Node *tem = head;
    map<int, bool> m;
    Node *pre = NULL, *cur = head;
    while(cur!=NULL){
        if(m.find(cur->val)==m.end()){
            m[cur->val] = true;
            pre = cur;
            cur = cur->next;
        }else{
            Node *nodeToDelete = cur;
            Node *nextOfNext = cur->next;
            cur = cur->next;
            pre->next = nextOfNext;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
        }

    }
}
int main()
{
    // for (int i = 1; i <= 10; i++)
    // {
    //     insertAtTail(i);
    //     if(i>1)
    //         insertAtTail(i - 1);
    // }
    insertAtTail(3);
    insertAtTail(2);
    insertAtTail(3);
    insertAtTail(4);
    insertAtTail(2);
    insertAtTail(3);
    printList();
    // removeDuplicate();
    // printList();
    removeDuplicateFromUnsortedList();
    printList();
}