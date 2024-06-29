#include<bits/stdc++.h>

using namespace std;

class Stack{
    int top;
    int capacity;
    char *arr;
public:
    Stack(int n){
        top=-1;
        capacity=n;
        arr=(char*)malloc(sizeof(char));
    }
    bool isStackFull(){
        if(top==capacity-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isStackEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

    void push(char value){
        if(isStackFull()){
            cout<<"Stack is full (overflow)!"<<endl;
        }
        else{
            top++;
            arr[top]=value;
           // cout<<value<<" is pushed into the Stack"<<endl;
        }
    }

    char pop(){
        if(isStackEmpty()){
           // cout<<"Stack is empty (underflow)!"<<endl;
            return 'X';
        }
        else{
            char tmp=arr[top];
            top--;
           // cout<<"Popped value is "<<tmp<<endl;
            return tmp;
        }
    }

    void sizeofStack(){
        int count=0;
        for(int i=top;i>=0;i--){
            count++;
        }
        cout<<"Number of elements: "<<count<<endl;
    }



    void printStack(){
        if(isStackEmpty()){
            cout<<"Empty stack can't be printed!"<<endl;
        }
        else{
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<endl;
            }
        }
    }
};



int main(){
    string str;
    getline(cin, str);
    char comp;
    int flag=0;
    int n=str.length();
    Stack stk(n);
    for(int i=0;i<n;i++)
    {
        if(str[i]=='<' && str[i+1]!='/')
        {
            int j=i+1;
            while(str[j]!='>')
            {
                stk.push(str[j]);
                j++;
            }
        }
        else if(str[i]=='<' && str[i+1]=='/')
        {
            int j=i+2;
            string popped="";
            string word="";
            while(str[j]!='>')
            {
                word=word+str[j];
                cout<<"str[j] is "<<str[j]<<endl;
                char c=stk.pop();
                popped=popped+c;
                cout<<"Popped "<<c<<endl;

                j++;
            }
            reverse(popped.begin(), popped.end());
            cout<<"Popped word "<<popped<<endl;
            cout<<"Word is "<<word<<endl;
            if(popped!=word)
            {
                cout<<"hello for i"<<i<<endl;
                flag=1;
                break;
            }
        }
    }
    stk.printStack();
    if(flag==0 && stk.isStackEmpty())
        cout<<"Valid"<<endl;
    else
        cout<<"Invalid"<<endl;
}

