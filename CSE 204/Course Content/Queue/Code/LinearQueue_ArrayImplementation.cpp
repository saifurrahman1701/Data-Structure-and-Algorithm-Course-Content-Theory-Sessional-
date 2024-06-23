/*
 *   author: brownFalcon
 */
#include<iostream>
using namespace std;

const int capacity = 5;
int queue[capacity];

int front = -1;
int rear = -1;

bool enqueue(int val) {
  if(front == -1) {
    front = 0;
    rear = 0;
    queue[front] = val;
    return true;
  }
  else if(rear == capacity-1) {
    return false;
  }
  else {
    rear++;
    queue[rear] = val;
    return true;
  }
}
bool isEmpty() {
  if(front == -1) return true;
  else return false;
}
int peek() {
  return queue[front];
}
int dequeue() {
  int temp = front;
  front++;
  if(front > rear) {
    front = -1;
    rear = -1;
  }
  return queue[temp];
}
bool isFull() {
  if(rear-front == capacity-1) return true;
  else return false;
}
void clear() {
  front = -1;
  rear = -1;
}



int main() {
  cout<<"The capacity of the queue is "<<capacity<<endl;;
  
  while(1) {
    cout<<"Select an option: "<<endl;
    cout<<"1. Enqueue"<<endl;
    cout<<"2. IsEmpty"<<endl;
    cout<<"3. Peek"<<endl;
    cout<<"4. Dequeue"<<endl;
    cout<<"5. IsFull"<<endl;
    cout<<"6. Clear"<<endl;
    cout<<"7. Exit"<<endl;

    int x;cin>>x;
    if(x == 1) {
      cout<<"Enter the value: ";
      int val;cin>>val;
      if(enqueue(val)) {
        cout<<"The value has been successfully inserted into the queue."<<endl;
      }
      else {
        cout<<"Queue is Full!!"<<endl;
      }  
    }
    else if(x == 2) {
      if(isEmpty()) cout<<"The queue is empty!!!"<<endl;
      else cout<<"The queue is not empty!!!"<<endl;
    }
    else if(x == 3) {
      if(isEmpty()) cout<<"The queue is empty!!!"<<endl;
      else {
        int val = peek();
        cout<<"The first element of the queue is: "<<val<<endl;
      }
    }
    else if(x == 4) {
      if(isEmpty()) cout<<"The queue is empty!!!"<<endl;
      else {
        int val = dequeue();
        cout<<"The first element of the queue is: "<<val<<" and its successfully deleted."<<endl;
      }
    }
    else if(x == 5) {
      if(isFull()) cout<<"The queue is full!!!"<<endl;
      else cout<<"The queue is not full!!!"<<endl;
    }
    else if(x == 6) {
      clear();
      cout<<"The queue has been cleared!!!"<<endl;
    }
    else if(x == 7) break;
    else cout<<"Invalid option!!!"<<endl;
  }

  return 0;
  
}