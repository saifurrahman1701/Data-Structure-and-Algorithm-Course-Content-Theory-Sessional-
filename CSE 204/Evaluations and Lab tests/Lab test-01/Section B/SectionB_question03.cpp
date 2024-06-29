/*
* author: brownFalcon
*/
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct Node {
  string name;
  int batch;
  Node *next;
};

class PriorityQueue {
  Node *head;
  int salamiFund;
  int *countJunior;
public: 
  PriorityQueue(int fund) {
    head = NULL;
    salamiFund = fund;
    countJunior = new int(100);
    countJunior[23] = countJunior[24] = countJunior[25] = countJunior[26] = 0;
  }
  void push(string name, int batch) {
    Node *newNode = new Node;
    newNode->name = name;
    newNode->batch = batch;
    if(head == NULL) {
      newNode->next = NULL;
      head = newNode;
    }
    else {
      if(batch < head->batch) {
        newNode->next = head;
        head = newNode;
      }
      else {
        Node *temp = head;
        while(temp->next != NULL && temp->next->batch <= batch) {
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
      if((head->batch == 23 && salamiFund >= 10) || (head->batch == 24 && salamiFund >= 100) || (head->batch == 25 && salamiFund >= 70) || (head->batch == 26 && salamiFund >= 50)) {
        cout<<head->name<<" received ";
        if(head->batch == 23) {salamiFund -= 10;cout<<10;}
        if(head->batch == 24) {salamiFund -= 100;cout<<100;}
        if(head->batch == 25) {salamiFund -= 70;cout<<70;}
        if(head->batch == 26) {salamiFund -= 50;cout<<50;}
        countJunior[head->batch]++;
        cout<<" taka as salami"<<endl;
        Node *temp = head;
        head = head->next;
        delete temp;
      }
      else {
        cout<<"No enough money in the fund"<<endl;
      }
    }
  }
  Node peek() {
    return *head;
  }
  void countJuniors() {
    cout<<"The numer of Juniors and Friends who received salami are: "<<endl;
    for(int i=23;i<=26;i++) {
      cout<<"CSE "<<i<<" -> "<<countJunior[i]<<endl;
    }
    cout<<endl;
  }
  int currentFund() {
    return salamiFund;
  }
  bool isEmpty() {
    if(head == NULL) return true;
    return false;
  }
};

int main() {
  int SalamiFund;
  cout<<"Enther the amound you have in the Salami Fund: ";
  cin>>SalamiFund;
  PriorityQueue pq(SalamiFund);
  while(1) {
    cout<<"Options:\n1. Push\n2. Pop\n3. Peek\n4. Count juniors\n5. Current Salami Fund\n6. Exit\n";
    cout<<"Select your option: ";
    int opt;cin>>opt;
    if(opt == 1) {
      cout<<"Enter name: ";
      string name;cin>>name;
      cout<<"Enter batch: ";
      int batch;cin>>batch;
      pq.push(name, batch);
    }
    if(opt == 2) {
      pq.pop();
    }
    if(opt == 3) {
      if(pq.isEmpty()) {
        cout<<"Priority Queue is empty"<<endl;
      }
      else {
        cout<<"The most eligible salami recepient: (";
        Node x = pq.peek();
        cout<<x.name<<", "<<x.batch;
        cout<<")"<<endl;
      }
    }
    if(opt == 4) {
      pq.countJuniors();
    }
    if(opt == 5) {
      cout<<pq.currentFund()<<endl;
    }
    if(opt == 6) {
      break;
    }
  }
}