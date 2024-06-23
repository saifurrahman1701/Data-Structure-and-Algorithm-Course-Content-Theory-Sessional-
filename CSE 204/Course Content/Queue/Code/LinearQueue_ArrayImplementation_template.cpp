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
  
}
bool isEmpty() {
  
}
int peek() {
  
}
int dequeue() {
  
}
bool isFull() {
  
}
void clear() {
  
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
        
    }
    else if(x == 2) {
      
    }
    else if(x == 3) {
      
    }
    else if(x == 4) {
      
    }
    else if(x == 5) {
      
    }
    else if(x == 6) {
      
    }
    else if(x == 7) break;
    else cout<<"Invalid option!!!"<<endl;
  }

  return 0;
  
}