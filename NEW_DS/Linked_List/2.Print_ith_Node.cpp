/*
Problem Statement: 
For a given a singly linked list of integers and a position 'i', print the node data at the 'i-th' position.

Input Format: 
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line contains the value of 'i'. It denotes the position in the given singly linked list.

Output Format: 
For each test case, print the node data at the 'i-th' position of the linked list(if exists).

Output for every test case will be printed in a seperate line.

Constraints: 
1 <= t <= 10^2
0 <= N <= 10^5
i  >= 0
Time Limit: 1sec

Sample Input1: 
1
3 4 5 2 6 1 9 -1
3

Sample Output1: 
2

Sample Input1: 
2
3 4 5 2 6 1 9 -1
0
9 8 4 0 7 8 -1
3

Sample Output2: 
3
0
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
void printIthNode(Node *head, int i) {
  int j = 0;
  int data;
  Node *temp = head;
  while(j <= i){
    if(temp == NULL){
      data = -1;
      j++;
    }else{
      data = temp -> data;
      temp = temp -> next;
      j++; 
    }
  }
  if(data != -1){
    cout << data;
  }
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
		printIthNode(head, pos);
		cout << endl;
	}
	return 0;
}
