// Implementation of Cloning a Linked list with next & random pointer.
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next, *arbit;
};

// Insertion functions
Node *newNode(int data);
void insertatFirst(Node **head, int data);
void insertatEnd(Node **head, int data);
void insertAfter(Node **head, int afterData, int data);
void insertBefore(Node **head, int beforeData, int data);

void insert(Node **head, int data)
{
    insertatFirst(head, data);
}

void insertatFirst(Node **head, int data)
{

    if (*head == NULL)
    {
        *head = newNode(data);
        return;
    }

    Node *temp = newNode(data);
    temp->next = *head;
    *head = temp;
}

void insertatEnd(Node **head, int data)
{

    if (*head == NULL)
    {
        insertatFirst(head, data);
    }
    Node *temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode(data);
}

void printList(Node **head)
{
    Node *temp = *head;
    cout << "LList : " << endl;
    while (temp != NULL)
    {
        cout << "Node : " << temp->data << ", Arbitrary Link : " << temp->arbit->data << endl;
        temp = temp->next;
    }
}

// Function to seperate Lists from common List.
void seperateLists(Node **shead, Node **dhead)
{
    Node * stemp = *shead, *dtemp = *dhead;

    if(stemp==NULL){
        return;
    }

    *dhead = dtemp = stemp->next;

    while(stemp!=NULL){
        stemp->next = dtemp->next;
        dtemp->next = (stemp->next!=NULL) ? stemp->next->next : stemp->next;
        stemp = stemp->next;
        dtemp = dtemp->next;
    }
}

// Function to clone a Linked List.
Node *cloneLL(Node **head)
{

    if (head == NULL)
    {
        return NULL;
    }

    Node *curr = *head, *temp = NULL;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = newNode(curr->data);
        curr->next->next = temp;
        curr = temp;
    }

    curr = *head;

    while (curr != NULL)
    {
        curr->next->arbit = (curr->arbit != NULL) ? curr->arbit->next : curr->arbit;
        curr = (curr->next != NULL) ? curr->next->next : curr->next;
    }

    Node *dhead = NULL;

    seperateLists(head, &dhead);

    return dhead;
}

Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = temp->arbit = NULL;

    return temp;
}

void getRandomLinkedList(Node **head)
{
    insert(head, 5);
    insert(head, 24);
    insert(head, 48);
    insert(head, 7);
    insert(head, 55);

    Node *temp = *head;

    temp->arbit = temp->next->next;              // 48
    temp->next->arbit = temp->arbit->next;       // 7
    temp->arbit->arbit = temp;                   // 5
    temp->arbit->next->arbit = temp->arbit;      //48
    temp->next->arbit->next->arbit = temp->next; // 24
}

int main()
{
    // your code goes here
    Node *head = NULL;
    Node **pHead = &head;

    getRandomLinkedList(pHead);
    printList(pHead);

    Node *dhead = cloneLL(pHead);
    printList(&dhead);

    return 0;
}