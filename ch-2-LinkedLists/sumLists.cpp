/*
Chapter 02 - Problem 05 - Sum Lists - CTCI 6th Edition page 95

Problem Statement:
You have two numbers represented by a linked list, where each node contains a single digit.
The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function
that adds the two numbers and returns the sum as a linked list.

Example:
Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
Output: (2 -> 1 -> 9). That is, 912.

Solution:
Create a node representing the head of a new linked list. Traverse the input linked lists one node at a time until
both pointers are nullptr. Append a new node to the output linked list for every sum computed between pairs of nodes.
Add two input nodes and store the sum in the output node. If the sum is > 9, store the carry value in an int variable.
If one pointer is nullptr but the other isn't, copy the value of the non-null pointer into the new list.
Add the sum to a node in the new linked list. Return head of new linked list.

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

node<int> *sumlists(node<int> *l1,node<int> *l2){
    node<int> temp(0),*p=&temp;
    int carry=0;
    while(l1 || l2 || carry){
        int sum=(l1?l1->data:0)+(l2?l2->data:0)+carry;
        carry=sum/10;
        p->next=new node<int>(sum%10);
        p=p->next;
        l1=l1?l1->next:0;
        l2=l2?l2->next:0;
    }
    return temp.next;
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
    node<int> *head1=takeinput();
    node<int> *head2=takeinput();
    node<int> *head=sum_recursive(head1,head2,0);
    print(head);
} 
