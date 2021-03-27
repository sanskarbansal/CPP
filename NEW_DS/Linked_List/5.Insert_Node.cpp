/*
Problem Statement: 
You have been given a linked list of integers. Your task is to write a function that inserts a node at a given position, 'pos'.

Input Format: 
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the linked list separated by a single space. 

The second line of each test case contains two space separated integers, that denote the value of 'pos' and the data to be inserted respectively.

Output Format: 
For each test case/query, print the resulting linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a separate line.
You don't need to print explicitly, it has been taken care of.

Constraints: 
1 <= t <= 20
0 <= length of linked list <= 10^4
0 <= pos, data to be inserted <= 2^31 - 1
Time Limit: 1 second

Sample Input1: 
1
3 4 5 2 6 1 9 -1
3 100

Sample Output1: 
3 4 5 100 2 6 1 9

Sample Input1: 
1 
3 4 5 2 6 1 9 -1
0 20

Sample Output2: 
20 3 4 5 2 6 1 9

*/ 


#include <iostream>

class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;


Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}

Node* insertNodeRec(Node *head, int i, int data) {
  if(head == NULL){
    return head;
  }
  if(i == 0){
    Node *newHead = new Node(data);
    newHead -> next = head;
    head = newHead;
  }else{
    Node * newHead = insertNodeRec(head -> next, i - 1, data);
    head -> next  = newHead;
  }

  return head;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        int pos, data;
        cin >> pos >> data;
        head = insertNodeRec(head, pos, data);
        print(head);
    }
}