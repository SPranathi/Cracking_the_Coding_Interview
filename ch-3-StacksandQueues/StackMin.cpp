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
