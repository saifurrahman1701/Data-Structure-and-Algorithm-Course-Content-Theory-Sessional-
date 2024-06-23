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
      if(head == NULL) {
        cout<<"Index not found"<<endl;
        return;
      }
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
    pair<Army, Army> SplitArmy() {
      Army army1, army2;
      Soldier *tmp = head;
      int cnt = 0;
      while(tmp != NULL) {
        if(cnt%2 == 0) {
          army1.InsertSoldier(tmp->height);
        }
        else {
          army2.InsertSoldier(tmp->height);
        }
        cnt++;
        tmp = tmp->next;
      }
      return {army1, army2};
    }
    void PurgeDuplicates() {
      if(head == NULL) return;
      Soldier *tmp = head;
      Soldier *tmp1 = tmp->next;
      while(tmp1!= NULL) {
        if(tmp->height == tmp1->height) {
          Soldier *tmp2 = tmp1;
          tmp1 = tmp1->next;
          tmp->next = tmp1;
          delete tmp2;
        }
        else {
          tmp = tmp1;
          tmp1 = tmp1->next;
        }
      }
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
}army;

int main() {
  cout<<"Greetings!!!\n\n";
  
  while(1) {
    cout<<"Options: \n";
    cout<<"1. Insert a Solder\n";
    cout<<"2. Execute the Traitor\n";
    cout<<"3. Split the Force\n";
    cout<<"4. Purge Duplicates\n";
    cout<<"5. ShowLineups\n";
    cout<<"6. Exit\n";
    cout<<"Select your option: ";
    int option;cin>>option;
    if(option == 1) {
      cout<<"Enter soldier height: ";
      int height;cin>>height;
      army.InsertSoldier(height);
    }
    else if(option == 2) {
      cout<<"Enter soldier index: ";
      int idx;cin>>idx;
      army.ExecuteTheTraitor(idx);
    }
    else if(option == 3) {
      pair<Army, Army> army1 = army.SplitArmy();
      cout<<"Even army: ";
      army1.first.ShowLineups();
      cout<<"Odd army: ";
      army1.second.ShowLineups();
    }
    else if(option == 4) {
      army.PurgeDuplicates();
    }
    else if(option == 5) {
      army.ShowLineups();
    }
    else if(option == 6) {
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