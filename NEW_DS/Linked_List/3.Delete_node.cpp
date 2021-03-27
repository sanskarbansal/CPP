/*
Problem Statement: 
You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'pos'.

Input Format: 
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the linked list separated by a single space. 

The second line of each test case contains the integer value of 'pos'. It denotes the position in the linked list from where the node has to be deleted.

Output Format: 
For each test case/query, print the resulting linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a separate line.
You don't need to print explicitly, it has been taken care of.

Constraints: 
1 <= t <= 10^2
0 <= N <= 10^5
pos >= 0
Time Limit: 1sec

Where 'N' is the size of the singly linked list.

Sample Input1: 
1 
3 4 5 2 6 1 9 -1
3

Sample Output1: 
3 4 5 6 1 9

Sample Input1: 
2
3 4 5 2 6 1 9 -1
0
10 20 30 40 50 60 -1
7

Sample Output2: 
4 5 2 6 1 9
10 20 30 40 50 60

*/ 


#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};



Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
Node* deleteNode(Node *head, int i){ 
  int pos=0; Node * temp=head; 
  while(pos<i-1 && temp->next!=NULL) { 
    temp=temp->next; pos++; 
  } if(temp->next==NULL) {
    return head;
  } 
  Node * n=temp->next; 
  temp->next=temp->next->next; 
  delete n; 
  return head; 
}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}