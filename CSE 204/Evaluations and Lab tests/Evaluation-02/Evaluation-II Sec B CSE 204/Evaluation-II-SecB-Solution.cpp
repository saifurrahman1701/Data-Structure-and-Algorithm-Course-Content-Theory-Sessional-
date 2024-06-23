/*
 *   author: brownFalcon
 */
#include<iostream>
using namespace std;

struct Soldier{
  int height;
  Soldier *next;
};

class Army {
  private:
    Soldier *head;
  public: 
    Army() {
      head = NULL;
    }
    void InsertSoldier(int height) {
      Soldier *tmp = new Soldier;
      tmp->height = height;
      tmp->next = NULL;
      if(head != NULL) {
        Soldier *cur = head, *prev = NULL;
        while(cur != NULL && cur->height < height) {
          prev = cur;
          cur = cur->next;
        }  
        if(prev == NULL) {
          cout<<"hello"<<endl;
          tmp->next = head;
          head = tmp;
        }
        else if(cur == NULL) {
          prev->next = tmp;
        }
        else {
          Soldier *tmp1 = prev->next;
          prev->next = tmp;
          tmp->next = tmp1;
        }
      }
      else {
        head = tmp;
      }
      
    }
    void ExecuteTheTraitor(int idx) {
      if(idx == 0) {
        Soldier *tmp = head;
        head = head->next;
        delete tmp;
      }
      else {
        int i = 0;
        Soldier *tmp = head, *prev = NULL;
        while(tmp->next!= NULL) {
          prev = tmp;
          tmp = tmp->next;
          i++;
          if(i == idx) break;
        }
        if(i == idx) {
          prev->next = tmp->next;
          delete tmp;
        }
        else {
          cout<<"Index not found"<<endl;
        }
      }
    }
    void MergeArmies(Army &army2) {
      Soldier *tmp = army2.head;
      while(tmp != NULL) {
        InsertSoldier(tmp->height);
        tmp = tmp->next;
      }
      tmp = army2.head;
      while(tmp != NULL) {
        Soldier *x = tmp;
        tmp = tmp->next;
        delete x;
      }
      army2.head = NULL;
    }
    void ShowLineups() {
      cout<<"Lineup: [";
      Soldier *tmp = head;
      while(tmp != NULL) {
        cout<<tmp->height<<", ";
        tmp = tmp->next;
      }
      cout<<"]"<<endl;
    }
}army1, army2;

int main() {
  cout<<"Greetings!!!\n\n";
  
  while(1) {
    cout<<"Options: \n";
    cout<<"1. Insert a Solder\n";
    cout<<"2. Execute the Traitor\n";
    cout<<"3. Merge forces\n";
    cout<<"4. ShowLineups\n";
    cout<<"5. Exit\n";
    cout<<"Select your option: ";
    int option;cin>>option;
    if(option == 1) {
      cout<<"On which army? ";
      int arm;cin>>arm; 
      if(arm == 1) {
        cout<<"Enter soldier height: ";
        int height;cin>>height;
        army1.InsertSoldier(height);
      }
      else if(arm == 2) {
        cout<<"Enter soldier height: ";
        int height;cin>>height;
        army2.InsertSoldier(height);
      }
      else {
        cout<<"That army doesn't exist!!\n";
      }
    }
    else if(option == 2) {
      cout<<"On which army? ";
      int arm;cin>>arm; 
      if(arm == 1) {
        cout<<"Enter soldier index: ";
        int idx;cin>>idx;
        army1.ExecuteTheTraitor(idx);
      }
      else if(arm == 2) {
        cout<<"Enter soldier index: ";
        int idx;cin>>idx;
        army2.InsertSoldier(idx);
      }
      else {
        cout<<"That army doesn't exist!!\n";
      }
    }
    else if(option == 3) {
      army1.MergeArmies(army2);
    }
    else if(option == 4) {
      army1.ShowLineups();
      army2.ShowLineups();
    }
    else if(option == 5) {
      cout<<"Thank you\n";
      break;
    }
    else {
      cout<<"Wrong option\n";
    }
    cout<<endl;
  }
  return 0;
}