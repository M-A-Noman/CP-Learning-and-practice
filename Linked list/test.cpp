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
};
Node *head = NULL, *tail = NULL;
void insertAtHead(int val)
{
    Node *tem = new Node(val);
    tem->next = head;
    head = tem;
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
        // Node *ttem = head;
        // while(ttem->next!=NULL){
        //     ttem = ttem->next;
        // }
        // ttem->next = tem;
        tail->next = tem;
        tail = tem;
    }
}
void printList()
{
    Node *tem = head;
    while (tem != NULL)
    {
        cout << tem->val << ' ';
        tem = tem->next;
    }
}

int main()
{
    for (int i = 1; i < 5; i++)
    {
        insertAtTail(i);
    }
    printList();
}