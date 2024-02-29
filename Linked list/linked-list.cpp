#include <iostream>
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
        // int val = this->val;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory freed for value " << this->val << "\n";
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
        head = tem;
    }
}
void insertAtTail(int val)
{
    node *tem = new node(val);
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
    node *tem = new node(val);
    node *findPos = head;
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
void deleteFromFront()
{
    node *tem = head;
    head = head->next;
    tem->next = NULL;
    delete tem;
}
void deleteFromPosition(int pos)
{
    node *tem = head;
    if (pos < 1)
    {
        cout << "Illegal Index. Please insert a valid Index\n";
        return;
    }
    if (pos == 1)
    {
        deleteFromFront();
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
    if (deletedNode->next == NULL)
        tail = tem;
    deletedNode->next = NULL;
    delete deletedNode;
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
    for (int i = 1; i <= 5; i++)
    {
        // insertAtHead(i);
        insertAtTail(i);
    }
    printList();

    insertAtPosition(8, 3);
    insertAtTail(21);
    printList();
    cout << "Head => " << head->val << endl;
    cout << "Tail => " << tail->val << endl;
    deleteFromFront();
    printList();
    deleteFromPosition(9);
    printList();

    cout << "Head => " << head->val << endl;
    cout << "Tail => " << tail->val << endl;
}