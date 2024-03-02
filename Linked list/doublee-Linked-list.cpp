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
            this->next = NULL;
            this->pre = NULL;
            delete next;
            delete pre;
        }
        
    }
};
node *head = NULL, *tail = NULL;
int len;
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
    len++;
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
    len++;
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
    len++;
}
void deleteFromFront()
{
    node *tem = head;
    // head = head->next;
    // head->pre = NULL;
    // tem->next = NULL;
    // tem->pre = NULL;
    tem->next->pre = NULL;
    head = head->next;
    tem->next = NULL;
    delete tem;
    len--;
}
void deleteFromTail()
{
    // node *tem = tail,*deletedNode=tail;
    // tem = deletedNode->pre;
    // tem->next = NULL;
    // tail = tem;
    // deletedNode->next = NULL;
    // deletedNode->pre = NULL;
    // cout << "previous value of tail is " << tail->pre->val << endl;
    // tail = tail->pre;

    // tail->next = NULL;
    // tem->next = NULL;
    // tem->pre = NULL;
    // delete tem;

    node *tem = tail;
    node *prev = tail->pre;
    prev->next = NULL;
    tem->pre = NULL;
    tail = prev;

    len--;
}
void deleteFromPosition(int pos)
{
    node *tem = head, *prev = NULL;
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
    if (len == pos)
    {
        deleteFromTail();
        return;
    }
    int cnt = 1;
    while (cnt < pos - 1)
    {
        cnt++;
        tem = tem->next;
        if(tem==NULL)break;
    }
    if (tem == NULL)
    {
        cout << "Illegal Index. Please insert a valid Index\n";
        return;
    }
    node *deletedNode = tem->next;
    tem->next = deletedNode->next;
    deletedNode->pre = tem;
    if (deletedNode->next == NULL)
        tail = tem;
    deletedNode->next = NULL;
    deletedNode->pre = NULL;
    delete deletedNode;
    len--;
}
int length()
{
    return len;
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
void printList1()
{
    node *tem = head;
    while (tem != NULL)
    {
        cout << tem->val << '\n';
        if (tem->pre == NULL)
        {
            cout << "Empty previous for value " << tem->val << endl;
        }
        else
        {
            cout << "Previous value of " << tem->val << " is " << tem->pre->val << endl;
        }
        tem = tem->next;
    }
    cout << '\n';
}
void printListInReverseOrder()
{
    node *tem = tail;
    while (tem != NULL)
    {
        
        cout << tem->val << ' ';
        if(tem->pre==NULL)break;
        tem = tem->pre;
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
    // printList1();
    // deleteFromPosition(3);
    // printListInReverseOrder();
    cout << "Length of the current Linked List is " << length() << endl;
    insertAtPosition(4, 3);
    printList();
    cout << "Length of the current Linked List is " << length() << endl;
    deleteFromFront();
    printList();
    cout << "Length of the current Linked List is " << length() << endl;
    cout << "Head value is " << head->val << '\n'
         << "tail value is " << tail->val << endl;
    if (tail->pre == NULL)
        cout << "NULL\n";
    else
        cout << "Previous of current tail " << tail->pre->val << endl;

    deleteFromTail();
    printList();
    cout << "Length of the current Linked List is " << length() << endl;
    cout << "Head value is " << head->val << '\n'
         << "tail value is " << tail->val << endl;
    if (tail->pre == NULL)
        cout << "NULL\n";
    else
        cout << "Previous of current tail " << tail->pre->val << endl;

    deleteFromPosition(2);
    printList();
    printList();
    cout << "Length of the current Linked List is " << length() << endl;
    cout << "Head value is " << head->val << '\n'
         << "tail value is " << tail->val << endl;
    if (tail->pre == NULL)
        cout << "NULL\n";
    else
        cout << "Previous of current tail " << tail->pre->val << endl;

    // printListInReverseOrder();
}