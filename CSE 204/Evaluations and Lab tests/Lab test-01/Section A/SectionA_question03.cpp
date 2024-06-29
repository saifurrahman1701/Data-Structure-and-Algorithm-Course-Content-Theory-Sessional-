/*
* author: brownFalcon
*/
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct Node {
  string name;
  int amount;
  int batch;
  Node *next;
};

class PriorityQueue {
  Node *head;
  int *countSenior;
public:
  PriorityQueue() {
    head = NULL;
    countSenior = new int(100);
    for(int i=1;i<=23;i++) {
      countSenior[i] = 0;
    }
  }
  void push(string name, int amount, int batch) {
    Node *newNode = new Node;
    newNode->name = name;
    newNode->amount = amount;
    newNode->batch = batch;
    countSenior[batch]++;
    if(head == NULL) {
      newNode->next = NULL;
      head = newNode;
    }
    else {
      if(amount > head->amount) {
        newNode->next = head;
        head = newNode;
      }
      else if((amount == head->amount) && (batch > head->batch)) {
        newNode->next = head;
        head = newNode;
      }
      else {
        Node *temp = head;
        while(temp->next != NULL && temp->next->amount > amount) {
          temp = temp->next;
        }
        while(temp->next != NULL && (temp->next->amount == amount) && temp->next->batch >= batch) {
          temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
      }
    }
  }
  void pop() {
    if(isEmpty()) {
      cout<<"No one left in the list"<<endl;
    }
    else {
      countSenior[head->batch]--;
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }
  Node peek() {
    return *head;
  }
  void countSeniors() {
    for(int i=1;i<=23;i++) {
      cout<<"CSE "<<i<<" -> "<<countSenior[i]<<endl;
    }
  }
  bool isEmpty() {
    if(head == NULL) return true;
    return false;
  }
};

int main() {
  PriorityQueue pq;
  while(1) {
    cout<<"Options:\n1. Push\n2. Pop\n3. Peek\n4. Count Seniors\n5. Exit\n";
    cout<<"Select your option: ";
    int opt;cin>>opt;
    if(opt == 1) {
      cout<<"Enter name: ";
      string name;
      getchar();
      getline(cin, name);
      cout<<"Enter salami amount: ";
      int salami;cin>>salami;
      cout<<"Enter batch: ";
      int batch;cin>>batch;
      pq.push(name, salami, batch);
    }
    if(opt == 2) {
      pq.pop();
    }
    if(opt == 3) {
      if(pq.isEmpty()) {
        cout<<"Priority Queue is empty"<<endl;
      }
      else {
        cout<<"Maximum Salami giver is: (";
        Node x = pq.peek();
        cout<<x.name<<", "<<x.amount<<", "<<x.batch;
        cout<<")"<<endl;
      }
    }
    if(opt == 4) {
      pq.countSeniors();
    }
    if(opt == 5) {
      break;
    }
  }
}