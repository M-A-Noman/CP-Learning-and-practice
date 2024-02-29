#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *pre;
    node *next;
    node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->pre = NULL;
    }
    ~node()
    {
        int val = this->val;
        cout << "Space freed for data " << this->val << '\n';
        if (this->next != NULL || this->pre != NULL)
        {
            delete next;
            delete pre;
        }
        this->next = NULL;
        this->pre = NULL;
    }
};
node *head = NULL, *tail = NULL;
void insertAtHead(int val)
{
    node *tem = new node(val);
    if (head == NULL)
    {
        head = tem;
        tail = tem;
    }
    else
    {
        tem->next = head;
        head->pre = tem;
        if (tail->pre == NULL)
            tail->pre = tem;
        head = tem;
    }
}
void insertAtTail(int val)
{
    node *tem = new node(val);
    if (tail == NULL)
    {
        head = tem;
        tail = tem;
    }
    else
    {
        tem->pre = tail;
        tail->next = tem;
        if (head->next == NULL)
            head->next = tem;
        tail = tem;
    }
}
void insertAtPosition(int pos, int val)
{
    node *tem = new node(val);
    if (pos == 1)
    {
        insertAtHead(val);
        return;
    }
    node *insertNextTo = head;
    while (insertNextTo != NULL)
    {
        pos--;
        if (pos == 1)
            break;
        insertNextTo = insertNextTo->next;
    }
    if (pos > 1)
    {
        insertAtTail(val);
        return;
    }
    tem->pre = insertNextTo;
    tem->next = insertNextTo->next;
    insertNextTo->next = tem;
}
void deleteFromFront()
{
    node *tem = head;
    head = head->next;
    head->pre = NULL;
    tem->next = NULL;
    tem->pre = NULL;
    delete tem;
}
void deleteFromTail()
{
    node *tem = tail;
    tail = tail->pre;
    tail->next = NULL;
    tem->next = NULL;
    tem->pre = NULL;
    delete tem;
}
void deleteFromPosition(int pos)
{
    node *cur = head, *prev = NULL;
    if (pos < 1)
    {
        cout << "Invalid position\n";
        return;
    }
    if (pos == 1)
    {
        deleteFromFront();
        return;
    }
    while (pos != 1)
    {
        prev = cur;
        cur = cur->next;
        if (cur->next == NULL)
            break;
        pos--;
    }
    if (pos != 1)
    {
        cout << "Invalid position\n";
        return;
    }
    if (cur->next == NULL)
    {
        deleteFromTail();
        return;
    }
    prev->next = cur->next;
    cur->next->pre = prev;
    cur->next = NULL;
    cur->pre = NULL;
    delete cur;
}
void printList()
{
    node *tem = head;
    while (tem != NULL)
    {
        cout << tem->val << ' ';
        tem = tem->next;
    }
    cout << '\n';
}
int main()
{
    for (int i = 1; i < 5; i++)
    {
        insertAtTail(i);
    }
    insertAtHead(0);
    printList();
    insertAtPosition(4, 3);
    printList();
    deleteFromFront();
    printList();
    cout << "Head value is " << head->val << '\n'
         << "tail value is " << tail->val << endl;

    deleteFromTail();
    printList();
    cout << "Head value is " << head->val << '\n'
         << "tail value is " << tail->val << endl;

    deleteFromPosition(2);
    printList();
    cout << "Head value is " << head->val << '\n'
         << "tail value is " << tail->val << endl;
}