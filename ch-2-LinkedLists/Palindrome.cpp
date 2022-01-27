/*
Chapter 02 - Problem 06 - Palindrome - CTCI 6th Edition page 95

Problem Statement:
Implement a function to check if a linked list is a palindrome.

Example:
Input: 1 -> 3 -> 5 -> 3 -> 1
Output: true

Time complexity: O(N)

Space complexity: O(N)
*/ 
#include<bits/stdc++.h>
using namespace std; 
template <typename T>

class node{
    public:
    T data;
    node<T> *next;
    node(T data){
        this->data=data;
        this->next=NULL;
    }
};

bool ispalindrome(node<int> *head){
    node<int> *fast=head;
    node<int> *slow=head;

    stack<int> st;

    /*Push elements from first half of the linked list onto stack.
    when fast runner reaches the end of the linked list, then we know we're at the middle.*/
    while(fast!=NULL && fast->next!=NULL){
        st.push(slow->data);
        slow=slow->next;
        fast=fast->next->next;
    } 

    //Has odd number of elements, so skip the middle element.
    if(fast!=NULL){
        slow=slow->next;
    }

    while(slow!=NULL){
        int top=st.top();
        st.pop();
        //If values are different,then its not a palindrome
        if(top!=slow->data){
            return false;
        }
        slow=slow->next;
    }

    return true;
}


node<int> *takeinput(){
    int data;
    cin>>data;
    node<int> *head=NULL,*tail=NULL;
    while(data!=-1){
        node<int> *newnode=new node<int>(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node<int> *head){
    node<int> *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node<int> *head=takeinput();
    if(ispalindrome(head))
        cout<<"true";
    else
    {
        cout<<"false";
    }
    
}

