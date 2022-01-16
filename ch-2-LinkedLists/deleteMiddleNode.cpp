/*
Problem Statement:
Implement an algorithm to delete a node in the middle (i.e., any node but the first and last
node, not necessarily the exact middle) of a singly linked list, given only access to that node.

Example:
Input: the node c from the linked list a -> b -> c -> d -> e -> f
Result: nothing is returned, but the new linked list looks like a -> b -> d -> e -> f

IMPLEMENTATION:
Copy the data from the next node into the node of choice, then delete that node.

TIME COMPLEXITY:
O(1), as we perform 3 assignments and one deletion.

SPACE COMPLEXITY:
O(1), as we do not use any space for this algorithm.
 
