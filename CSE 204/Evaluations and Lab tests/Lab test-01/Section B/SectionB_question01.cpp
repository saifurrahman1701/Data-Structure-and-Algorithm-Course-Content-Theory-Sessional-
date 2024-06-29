/*
* author: brownFalcon
*/
#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
};

class Stack {
  Node *head;
public:
  Stack() {
    head = NULL;
  }
  void push(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    if(head == NULL) {
      newNode->next = NULL;
    }
    else {
      newNode->next = head;
    }
    head = newNode;
  }
  void pop() {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
  int top() {
    return head->data;
  }
  bool isEmpty() {
    if(head == NULL) return true;
    return false;
  }
};

int main() {
  Stack stk;
  string str;
  getline(cin, str);
  int n = str.size();
  bool valid = true;
  for(int i=0;i<n;i++) {
    if(str[i] == '*') {
      if(i+1<n && str[i+1] == '*') {
        if(i == 0) {
          stk.push(2);
        }
        else if(str[i-1] == ' ') {
          stk.push(2);
        }
        else {
          // pop needed
          if(stk.isEmpty()) {
            valid = false;
            break;
          }
          else {
            if(stk.top() == 2) {
              stk.pop();
            }
            else {
              valid = false;
              break;
            }
          }
        }
        i++;
      }
      else {
        //single star
        if(i == 0) {
          stk.push(1);
        }
        else if(str[i-1] == ' ') {
          stk.push(1);
        }
        else {
          //pop needed
          if(stk.isEmpty()) {
            cout<<"hello"<<endl;
            valid = false;
            break;
          }
          else {
            if(stk.top() == 1) {
              stk.pop();
            }
            else {
              valid = false;
              break;
            }
          }
        }
      }
    }
  }
  if(valid && stk.isEmpty()) {
    cout<<"Valid"<<endl;
  }
  else {
    cout<<"Invalid"<<endl;
  }
}

// This is **bold** and *italic* text.
// This is **bold* and *italic** text.
// This is **bold and *italic* text**.
// This is **bold** and *italic text.