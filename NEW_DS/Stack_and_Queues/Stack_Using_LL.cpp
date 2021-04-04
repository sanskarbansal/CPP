/* 
Problem Statement: Implement a Stack Data Structure specifically to store integer data using a Singly Linked List.

Operations Performed On the Stack: 
Query-1(Denoted by an integer 1): Pushes an integer data to the stack.

Query-2(Denoted by an integer 2): Pops the data kept at the top of the stack and returns it to the caller.

Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the top of the stack but doesn't remove it, unlike the pop function.

Query-4(Denoted by an integer 4): Returns the current size of the stack.

Query-5(Denoted by an integer 5): Returns a boolean value denoting whether the stack is empty or not.
*/
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Node {
    public :
    T data;
    Node<T> *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};
template <typename T>
class Stack {
    Node<T> *head;
    int size;		// number of elements prsent in stack
    
    public :
    
    Stack() {
      head = NULL;
      size = 0;
    }
    
    int getSize() {
      return size;
    }
    
    bool isEmpty() {
      return size == 0;
    }
    
    void push(T element) {
      Node<T> *temp = new Node<T>(element);
      if(head != NULL){
		 temp -> next = head;
     	 head = temp;
      }else{
        head = temp;
      }
      size++;
    }
    
    T pop() {
      if(!isEmpty()){
        T ans = head -> data;
        Node<T> *temp = head;
        head = head -> next;
        delete temp ;
        size--;
        return ans;
      }
        return 0;
    }
    
    T top() {
      if(!isEmpty()){
        return head -> data;
      }
      return 0;
    }    
};

int main() {
    Stack<int> st;
    int choice;
    cin >> choice;
    int input;
    
    while (choice !=-1) {
        if(choice == 1) {
            cin >> input;
            st.push(input);
        }
        else if(choice == 2) {
            int ans = st.pop();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 3) {
            int ans = st.top();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 4) {
            cout << st.getSize() << endl;
        }
        else if(choice == 5) {
            cout << st.isEmpty() << endl;
        }
        cin >> choice;
    }

} 

