/*
* author: brownFalcon
*/
#include<iostream>
using namespace std;

int main() {
  string str = "\"Quote\", MiSsiPPI 74 5496 88AAaa A asgard";
  // cin>>str;
  string cmp = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string sorted ="";
  for(int i=0;i<cmp.size();i++) {
    for(int j=0;j<str.size();j++) {
      if(i<=9) {
        if(cmp[i] == str[j]) {
          sorted += cmp[i];
        }
      }
      else {
        if(cmp[i] == 'E') {
          // cout<<"Hello"<<endl;
        }
        char ch1 = cmp[i]; // caps
        char ch2 = cmp[i]-'A'+'a'; // small
        if(str[j] == ch1 || str[j] == ch2) {
          sorted += str[j];
        }
      }
    }
  }
  // cout<<sorted<<endl;
  while(1) {
    cout<<"Option: ";
    int opt;cin>>opt;
    if(opt == 1) {
      cout<<sorted<<endl;
    }
    else {
      char ch;cin>>ch;
      int i = sorted.size()-1;
      for(;i>=0;i--) {
        if(sorted[i] == ch) {
          break;
        }
      }
      if(i>= 0) {
        cout<<"Character "<<ch<<" found at "<<i<<endl;
      }
      else {
        cout<<"Character "<<ch<<" Not found"<<endl;
      }
    }
  }

}