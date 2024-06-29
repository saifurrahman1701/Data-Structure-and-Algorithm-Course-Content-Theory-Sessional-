/*
* author: brownFalcon
*/
#include<iostream>
using namespace std;

int main() {
  string str = "\"Quote\", MiSsiPPI 74 5496 88AAaa A asgard";
  // string str ="BbaA";
  // cin>>str;
  string processedStr = "";
  for(int i=0;i<str.size();i++) {
    if((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
      processedStr += str[i];
    }
  }
  //sorting using bubble sort
  int n = processedStr.size();

  for(int i=0;i<n-1;i++) {
    for(int j=0;j<n-i-1;j++) {
      char ch1 = processedStr[j];
      if(ch1 >= 'A' && ch1 <= 'Z') {
        ch1 = ch1 - 'A' + 'a'; // converting into lowercase
      }
      char ch2 = processedStr[j+1];
      if(ch2 >= 'A' && ch2 <= 'Z') {
        ch2 = ch2 - 'A' + 'a';
      }
      if(ch1 > ch2) {
        swap(processedStr[j], processedStr[j+1]);
      }
    }
  }
  while(1) {
    cout<<"Option: ";
    int x;cin>>x;
    if(x == 1) {
      cout<<processedStr<<endl;
    }
    else {
      char ch;cin>>ch;
      int i = processedStr.size()-1;
      for(;i>=0;i--) {
        if(processedStr[i] == ch) {
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