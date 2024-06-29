/*
* author: brownFalcon
*/
#include<bits/stdc++.h>
using namespace std;

struct Node {
  string data;
  Node* next;
};

class Stack {
  Node *head;
public:
  Stack() {
    head = NULL;
  }
  void push(string data) {
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
  string top() {
    return head->data;
  }
  bool isEmpty() {
    if(head == NULL) return true;
    return false;
  }
};

int main() {
  Stack stk;
  string str = "<div><p></span></div>";
  // cin>>str;
  int n = str.size();
  if(str[0] != '<') {
    cout<<"Invalid"<<endl;
    return 0;
  }
  string temp = "";
  bool first = false;
  bool second = false;
  bool valid = true;
  for(int i=0;i<n;i++) {
    cout<<i<<endl;
    if(str[i] == '<') {

      if(i+1<n && str[i+1] == '/') {
        if(second == false && first == false) {
          second = true;
          i++;
        }
        else {
          valid = false;
          break;
        }
        
      }
      else {
        if(second == false && first == false) {
          first = true;
        }
        else {
          valid = false;
          break;
        }
      }
    }
    else if(str[i] == '>') {
      if(first == true && second == false) {
        stk.push(temp);
        temp = "";
        first = false;
      }
      else if(second == true && first == false) {
        if(stk.isEmpty()) {
          valid = false;
          break;
        }
        else {
          if(stk.top() == temp) {
            stk.pop();
            temp = "";
            second = false;
          }
          else {
            valid = false;
            break;
          }
        }
      }
      else {
        valid = false;
        break;
      }
    }
    else {
      if((first == true && second == false) || (first == false && second == true)) {
        temp += str[i];
      }
      else {
        valid = false;
        break;
      }
    }
  }
  cout<<valid<<endl;
  if(valid && stk.isEmpty() && first == false && second == false) {
    cout<<"Valid"<<endl;
  }
  else {
    cout<<"Invalid"<<endl;
  }
}
