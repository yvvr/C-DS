// Implementation of Insertions & Deletions in linked list.
#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

// Insertion functions
Node *newNode(int data);
void insertatFirst(Node **head, int data);
void insertatEnd(Node **head, int data);
void insertAfter(Node **head, int afterData, int data);
void insertBefore(Node **head, int beforeData, int data);

// Deletion functions
int deleteNode(Node **head);
int deleteAtFirst(Node **head);
int deleteAtLast(Node **head);
int deleteAfterNode(Node **head);
int deleteBeforeNode(Node **head, int data);

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

	Node *temp2 = newNode(data);
	temp->next = temp2;
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
		nwNode->next = currentNode;
		prevNode->next = nwNode;
	}
}

int deleteNode(Node **head)
{
	return deleteAtFirst(head);
}

int deleteAtFirst(Node **head)
{
	int val = -1;
	if (*head == NULL)
	{
		return -1;
	}

	Node *temp = *head;
	*head = (*head)->next;
	val = temp->data;
	delete (temp);
	return val;
}

int deleteAtLast(Node **head)
{
	int val = -1;
	if (*head == NULL)
	{
		return -1;
	}
	if ((*head)->next == NULL)
	{
		return deleteAtFirst(head);
	}

	Node *temp = *head, *prev = NULL;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	val = temp->data;
	delete (temp);
	return val;
}

int deleteAfterNode(Node **head, int data)
{
	int val = -1;
	if (*head == NULL)
	{
		return -1;
	}

	Node *temp = *head, *prev = NULL;

	while (temp != NULL)
	{
		if (prev != NULL && prev->data == data)
			break;
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL)
	{
		return -1;
	}
	prev->next = temp->next;
	val = temp->data;
	delete (temp);
	return val;
}

int deleteBeforeNode(Node **head, int data)
{
	int val = -1;
	if (*head == NULL)
	{
		return -1;
	}

	Node *next = *head, *prev = NULL, *curr = NULL;
	while (next != NULL)
	{
		if (next->data == data)
			break;
		prev = curr;
		curr = next;
		next = next->next;
	}

	if (next == NULL || curr == NULL)
	{
		return -1;
	}

	if (prev != NULL)
	{
		prev->next = next;
	}
	else if (*head == curr)
	{
		*head = next;
	}

	val = curr->data;
	delete (curr);
	return val;
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
	temp->next = NULL;

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

	deleteNode(pHead);
	deleteAtLast(pHead);
	deleteAfterNode(pHead, 55);
	deleteAfterNode(pHead, 48);
	printList(pHead);

	deleteBeforeNode(pHead, 9);
	deleteBeforeNode(pHead, 7);
	printList(pHead);

	return 0;
}