/*
Chapter 02 - Problem 04 - Partition - CTCI 6th Edition page 94

Problem Statement:
Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater
than or equal to x. lf x is contained within the list, the values of x only need to be after the elements less than x
(see below).The partition element x can appear anywhere in the "right partition"; it does not need to appear between
the left and right partitions.

Example:
Input:  3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8

Solution:
Start a new list with a head and tail pointing to null. Traverse the nodes of the input linked list one at a time.
If the current node has value greater than or equal to the partition value, move it to the tail of the new list. Else,
move it to the the head of the new list.

Time complexity: O(N).

Space complexity: O(1) (we need no additional space in addition to the O(N) space required to store the list itself).
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

node<int> *partition(node<int> *n,int x){
    node<int> *head=n;
    node<int> *tail=n;

    while(n!=NULL){
        node<int> *nxt=n->next;
        if(n->data<x){
            //insert node at head
            cout<<head->data<<"-";
            n->next=head;
            head=n;
        }
        else{
            //insert node at tail
            cout<<tail->data<<"--";
            tail->next=n;
            tail=n;
        }
        n=nxt;
    }
    tail->next=NULL;

    //the head has changed, so we need to return it to the user
    return head;
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
    int x;
    cin>>x;
    head=partition(head,x);
    print(head);
}

