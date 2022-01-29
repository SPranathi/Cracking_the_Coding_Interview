/*
Chapter 02 - Problem 08 - Find Loop - CTCI 6th Edition page 95

Problem Stetement:
Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.

Definition:
Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so
as to make a loop in the linked list.

Example:
A -> B -> C -> D -> E -> C [the same C as earlier]
Return C

Time complexity: O(N), because we iterate through the whole list once.

Space complexity: O(N), because we store a hashmap of seen nodes.
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

node<char> *findloop(node<char> *head){
    node<char> *slow=head;
    node<char> *fast=head;

    /*Find meeting point. This will be LOOP_SIZE-k steps into the linked list.*/
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break; //collision
        }
    }

    /*Error check - no meeting point, and therefore no loop*/
    if(fast==NULL || fast->next==NULL){
        return nullptr;
    }

    /*Move slow to head. Keep fast at meeting point. Each are k steps from the
    Loop start. If they move at the same pace, they must meet at Loop start*/
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }

    /*Both now point to the start of the loop*/
    return fast;
}


int main(){
    node<char> *h1=new node<char>('A');
    node<char> *h2=new node<char>('B');
    node<char> *h3=new node<char>('C');
    node<char> *h4=new node<char>('D');
    node<char> *h5=new node<char>('E');
	
    h1->next=h2;
    h2->next=h3;
    h3->next=h4;
    h4->next=h5;
    h5->next=h3;
	node<char> *ans=findloop(h1); 
    cout<<ans->data;
}

 
