/*
Chapter 03 - Problem 03 - StackMin - CTCI 6th Edition 

Problem Statement:
Implement a stack of plates. Create a new stack if previous one exceeds the capacity.
Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.

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
