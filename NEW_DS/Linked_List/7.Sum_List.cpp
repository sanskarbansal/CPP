/*
Problem Statement: 
You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a program that adds the two numbers and returns the sum of as a linked list. 

Input Format: 
Integers till not encounter any -1. (First Line); 
Integers till not encounter any -1. (Second Line); 

Output Format: 
Integer which is sum of both the linked list. 

Sample Input: 
8 5 2 -1 
1 9 3 -1

Output: 
649

Explaination :  8->5->2 is treated as (258) & 1->9->3 as (391). therefore, sum of 258 and 391 is equal to 
*/
#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef vector<int> vi;
#define pb push_back
typedef long long ll;

class Node{
    public: 
    int data; 
    Node *next; 
    Node(int data){
        next = nullptr; 
        this -> data = data; 
    }
}; 
int addHelper(Node *a, Node *b, int placeVal){
    if(a == nullptr && b == nullptr) return 0; 
    if(a == nullptr){
        return addHelper(a, b->next, placeVal*10) + (b->data*placeVal); 
    }
    if(b==nullptr){
        return addHelper(a->next, b, placeVal*10) + (a->data*placeVal); 
    }
    return  (a->data + b->data) * placeVal + addHelper(a->next, b->next, placeVal*10); 

}

int add(Node *a, Node *b){
    return addHelper(a, b, 1); 
}
Node *takeInput(){
    Node *head = nullptr, *t =nullptr; 
    int n; cin >> n; 
    while(n!=-1){
        if(head == nullptr){
            head = new Node(n); 
            t = head; 
        }else{
            t->next = new Node(n); 
            t = t->next; 
        } 
        cin >> n; 
    }
    return head; 
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Node *n1 = takeInput(); 
    Node *n2 = takeInput(); 
    int sum = add(n1, n2); 
    cout << sum; 
}

//Try to solve it using iteration. 