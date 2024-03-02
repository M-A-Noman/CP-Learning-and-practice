#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *next;
    node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
    ~node()
    {
        int data = this->val;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
            
        }
        cout << "Free memory for the data " << data << endl;
    }
};
node *tail = NULL;
int len;
void insertAtHead(int val)
{
    node *tem = new node(val);
    if (tail == NULL)
    {
        tail = tem;
        tail->next = tail;
    }
    else
    {
        tem->next = tail->next;
        tail->next = tem;
    }
    len++;
}
void insertAtTail(int val)
{
    node *tem = new node(val);
    if (tail == NULL)
    {
        tail = tem;
        tail->next = tem;
    }
    else
    {
        tem->next = tail->next;
        tail->next = tem;
        tail = tem;
    }
    len++;
}
void insertAfterValue(int posVal, int val)
{
    node *loop = tail;
    int cnt = 0, notOk = 0;
    while (loop->val != posVal)
    {
        loop = loop->next;
        cnt++;
        if (cnt > len)
        {
            notOk = 1;
            break;
        }
    }
    if (!notOk)
    {
        if (loop->val == tail->val)
        {
            insertAtTail(val);
            return;
        }
        node *tem = new node(val);
        tem->next = loop->next;
        loop->next = tem;
    }
}
void deleteNode(int val)
{
    node *pre = tail, *cur = tail->next;
    
    while (cur->val != val)
    {
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next;
    if(cur==pre){
        tail = NULL;
    }
    else if (tail == cur)
    {
        tail = pre;
    }
    
    cur->next = NULL;
    delete cur;
}
void printList()
{
    node *tem = tail;
    if(tail==NULL){
        cout << "Empty List\n";
        return;
    }
    // cout << tem->val << ' ';
    tem = tem->next;
    // while (tem->val != tail->val)
    // {
    //     cout << tem->val << ' ';
    //     tem = tem->next;
    // }
    // cout << tem->val << endl;
    do
    {
        cout << tem->val << ' ';
        tem = tem->next;
    } while (tem->val != tail->next->val);
    cout << endl;
}
int main()
{
    for (int i = 1; i <= 1; i++)
    {
        insertAtTail(i);
    }
    printList();
    // insertAfterValue(5, 6);
    // printList();
    deleteNode(1);
    printList();
}