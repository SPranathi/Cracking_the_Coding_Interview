/*
Chapter 02 - Problem 07 - Intersection - CTCI 6th Edition page 95

Problem Statement:
Given two singly linked lists, determine if the two lists intersect.Return the intersecting node.
Note that the intersection is defined based on reference, not value.That is, if the kth node of the
first linked list is the exact same node(by reference) as the jth node of the second linked list,
then they are intersecting.

Example:
3 -> 1 -> 5 -> 9 -> 7 -> 2 -> 1
                    ^
                    |
               4 -> 6

TIME COMPLEXITY:
O(A + B), because we iterate through both lists twice in the worst case,
performing constant work over each iteration.

SPACE COMPLEXITY:
O(1), as we store a fixed number of bookkeeping variables.

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


int listLen(node<int> *head )
{
  int count = 0;
  while(head) {
    head = head->next;
    count++;
  }
  return count;
}

node<int> *intersectionPoint(node<int> *head1,node<int> *head2 )
{
  int len1 = listLen(head1);
  int len2 = listLen(head2);
  //figure out the bigger list ( and smaller )
  //ptr points to bigger list, let us move the difference
  //between the two.
  node<int> *ptr1 = ( len1 > len2 ) ? head1 : head2;
  node<int> *ptr2 = ( len1 > len2 ) ? head2 : head1;
  int i = 0;
  while (i<abs(len1 - len2) && ptr1 ) {
    ptr1 = ptr1->next;
    ++i;
  }
  //Now we have equal nodes to travel on both the nodes
  // traversing and comparing the pointers.

  while( ptr1 && ptr2 ) {
    if ( ptr1 == ptr2 ) {
      return ptr1;
    }
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  return nullptr;
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
    node<int> *list1 = new node<int>(3);
    list1->next = new node<int>(6);
    list1->next->next = new node<int>(9);
    list1->next->next->next = new node<int>(12);
    list1->next->next->next->next = new node<int>(15);
    list1->next->next->next->next->next = new node<int>(18);

    node<int> *list2 = new node<int>(7);
    list2->next = new node<int>(10);
    list2->next->next = list1->next->next->next;

    node<int> *intersectingNode = intersectionPoint( list1 , list2 );
    if(intersectingNode)
        cout<<"Intersecting Node of lists is : "<<intersectingNode->data<<endl;
    else
    {
        cout<<"Lists do not intersect"<<endl;
    }
    
}


