/*
Problem Statement:
Implement an algorithm to delete a node in the middle (i.e., any node but the first and last
node, not necessarily the exact middle) of a singly linked list, given only access to that node.

Example:
Input: the node c from the linked list a -> b -> c -> d -> e -> f
Result: nothing is returned, but the new linked list looks like a -> b -> d -> e -> f

TIME COMPLEXITY:
O(1), as we perform 3 assignments and one deletion.

SPACE COMPLEXITY:
O(1), as we do not use any space for this algorithm.
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>

class node{
    public:
    T data;
    node<T> *next;
    
    node(T data){
        this->data=data;
        this->next=NULL;
    }
};

bool delete_node(node<char> *n){
    if(n==NULL || n->next==NULL)
        return false; //failure

    node<char> *nxt=n->next;
    n->data=nxt->data;
    n->next=nxt->next;
    return true;
}

void print(node<char> *head){
    node<char> *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main() {
  node<char> *head = new node<char>('a');
  head->next = new node<char>('b');
  head->next->next = new node<char>('c');
  head->next->next->next = new node<char>('d');
  head->next->next->next->next = new node<char>('e');
  cout << "List before deletion:\n";
  print(head);
  cout << "Deleting node containing data as 'c'\n";
  delete_node(head->next->next);
  cout << "List after deletion:\n";
  print(head);
  return 0;
}
