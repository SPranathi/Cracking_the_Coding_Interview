/*
Chapter 03 - Problem 02 - StackMin - CTCI 6th Edition 

Problem Statement:
How would you design a stack which, in addition to push and pop, has a function min
which returns the minimum element? Push, pop and min should operate in O(1) time.

Example:
push(5); // stack is {5}, min is 5
push(6); // stack is {6,5}, min is 5
push(3); // stack is {3,6,5}, min is 3
push(7); // stack is {7,3,6,5}, min is 3
pop(); // stack is {3,6,5}, min is 3
pop(); // stack is {6,5}, min is 5

TIME COMPLEXITY:
O(1), push, pop and min operate in constant time. 

SPACE COMPLEXITY:
O(1), as we constant space.
*/

#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
    stack<int> s;
    int minele;

    void getMin(){
        if(s.empty()){
            cout<<"Stack is empty\n";
            return;
        }
        else{
            cout<<"Minimum element in the stack is: "<<minele<<endl;
        }
    }
    
    void top(){
        if(s.empty()){
            cout<<"Stack is empty\n";
            return;
        }
        int t=s.top();
        cout<<"Top most element is: ";
        (t<minele)?cout<<minele:cout<<t;
    }

    void pop(){
        if(s.empty()){
            cout<<"Stack is empty\n";
            return;
        }
        cout<<"Top most element removed: ";
        int t=s.top();
        s.pop();

        if(t<minele){
            cout<<minele<<"\n";
            minele=2*minele-t;
        }
        else
        {
            cout<<t<<"\n";
        }
        
    }

    void push(int x){
        //insert new number into the stack
        if(s.empty()){
            minele=x;
            s.push(x);
            cout<<"Number Inserted: "<<x<<"\n";
            return;
        }

    else if(x<minele){
        s.push(2*x-minele);
        minele=x;
    }
    else{
        s.push(x);
    }
    cout<<"Number Inserted: "<<x<<"\n";
    }

};

int main(){
    Stack st;
    int choice=0;
    cout<<"Stack"<<endl;
    int ele;
    while(choice!=-1){
        cout<<"1.Push\n2.Pop\n3.Min\n"<<endl;
        cin>>choice;
        switch(choice){
            case 1:cout<<"Enter element to push into stack:";
            cin>>ele;
            st.push(ele);
            break;
            case 2:st.pop();
            break;
            case 3:st.getMin();
            break;
            default:
            break;
        }
    }
}