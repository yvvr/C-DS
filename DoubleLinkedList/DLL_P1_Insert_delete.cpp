// Implementation of Insertions & Deletions in double linked list.
#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *prev, *next;
};

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
	(*head)->prev = temp;
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

	Node *temp2 = newNode(data);
	temp->next = temp2;
	temp2->prev = temp;
}

void insertAfter(Node **head, int afterData, int data)
{
	if (*head == NULL)
	{
		insertatFirst(head, data);
		return;
	}

	Node *currentNode = *head;
	Node *nwNode = newNode(data);
	Node *nextNode = NULL;
	while (currentNode->next != NULL)
	{
		if (currentNode->data == afterData)
			break;
		currentNode = currentNode->next;
	}

	nextNode = currentNode->next;

	if (nextNode != NULL)
	{
		currentNode->next = nwNode;
		nwNode->prev = currentNode;
		nextNode->prev = nwNode;
		nwNode->next = nextNode;
	}
	else
	{
		insertatEnd(head, data);
	}
}

void insertBefore(Node **head, int beforeData, int data)
{
	if (*head == NULL)
	{
		insertatFirst(head, data);
		return;
	}

	Node *currentNode = *head;
	Node *nwNode = newNode(data);
	Node *prevNode = NULL;
	while (currentNode != NULL)
	{
		if (currentNode->data == beforeData)
			break;
		prevNode = currentNode;
		currentNode = currentNode->next;
	}

	if (prevNode == NULL)
	{
		insertatFirst(head, data);
	}
	else if (currentNode != NULL)
	{
		currentNode->prev = nwNode;
		nwNode->next = currentNode;
		prevNode->next = nwNode;
		nwNode->prev = prevNode;
	}
}

int deleteNode(Node *head)
{
	return 0;
}

int deleteAtFirst(Node **head)
{
	return 0;
}

int deleteatLast(Node **head)
{
	return 0;
}

int deleteAfterNode(Node **head, int data)
{
	return 0;
}

int delteBeforeNode(Node **head, int data)
{
	return 0;
}

void printList(Node **head)
{
	Node *temp = *head;
	cout << "DLList : ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node *newNode(int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->next = temp->prev = NULL;

	return temp;
}

int main()
{
	// your code goes here
	Node *head = NULL;
	Node **pHead = &head;
	insert(pHead, 5);
	insertatFirst(pHead, 24);
	insertatFirst(pHead, 48);
	insertatEnd(pHead, 7);
	insertBefore(pHead, 5, 9);
	insertAfter(pHead, 9, 55);

	insertAfter(pHead, 7, 25);
	insertBefore(pHead, 48, 67);

	printList(pHead);

	return 0;
}