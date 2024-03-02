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
};
node *head = NULL;
void insertAtPosition(int pos, int val)
{
    node *tem = new node(val);
    if (head == NULL)
    {
        head = tem;
        return;
    }
    else if (pos == 1)
    {
        tem->next = head;
        head = tem;
        return;
    }
    int cnt = 1;
    node *ttem = head;
    while (cnt != pos - 1)
    {
        ttem = ttem->next;
        cnt++;
    }
    tem->next = ttem->next;
    ttem->next = tem;
}
void makeLoop(int pos)
{
    node *node1 = head, *node2 = NULL;
    int cnt = 0;
    while (node1 != NULL)
    {
        cnt++;
        if (cnt == pos )
        {
            node2 = node1;
        }
        node1 = node1->next;
        if (node1->next == NULL)
        {
            node1->next = node2;
            return;
        }
    }
}
node *loopDetection()
{
    node *slow = head, *fast = head;
    while (fast != NULL&&fast->next!=NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
            fast = fast->next;
        slow = slow->next;
        if (slow == fast)
            return slow;
    }
    return NULL;
}
bool chkLoop()
{
    if (head == NULL)
        cout << "There is a loop exist in the list\n";
    else if (head->next == NULL)
        cout << "There is no loop exist in the list\n";
    else
    {
        node *tem = loopDetection();
        if (tem == NULL)
        {
            cout << "There is no loop exist in the list\n";
        }
        else
            cout << "There is a loop exist in the list\n";
    }
}
node *findStartingOfTheLoop(){
    if(head==NULL)
        return NULL;
    node *fast = loopDetection();
    if(fast==NULL)
        return NULL;
    node *slow = head;
    while(fast!=slow){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
void removeLoop(){
    node *start = findStartingOfTheLoop();
    if(start==NULL)
        return;
    node *tem = start;
    while(tem->next!=start){
        tem = tem->next;
    }
    tem->next = NULL;
    cout << "Loop removed Successfully\n";
}
void printList()
{
    node *tem = head;
    while (tem != NULL)
    {
        cout << tem->val << ' ';
        tem = tem->next;
    }
    cout << endl;
}

int main()
{
    for (int i = 1; i <= 7; i++)
    {
        insertAtPosition(i, i);
    }
    printList();
    chkLoop();
    makeLoop(4);
    chkLoop();
    // printList();
    node * start=findStartingOfTheLoop();
    cout << "Starting point of the loop is " << start->val << endl;
    removeLoop();
    printList();
}