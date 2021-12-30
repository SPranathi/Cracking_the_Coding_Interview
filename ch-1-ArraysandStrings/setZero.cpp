/*
Chapter 01 - Problem 08 - Set Zero - CTCI 6th Edition page 91
Problem Statement:
Write an algorithm such that if an element in an MxN matrix is 0, its entire
row and column are set to 0.
Example:
[1, 2, 0, 4,      [0, 0, 0, 0,
 1, 2, 3, 4,  ->   0, 2, 0, 4,
 0, 2, 3, 4]       0, 0, 0, 0]
Solution:
We will implement this with allocating constant additional space. Use two boolean
variables firstZeroRow and firstZeroCol that indicate whether the first row and column
must be zeroed out. Search the first row and column for zeros to determine the value of
these boolean values. Next, use the first row as storage to note which columns must be zeroed.
Use the first column as storage to determine which rows must be zeroed. In Gayle's words
"iterate through the rest of the matrix, setting matrix[i][0] and matrix[0][j] to zero
whenever there's a zero in matrix[i][j]." Finally, iterate through the first row and column
to zero out the rows and columns indicated.
Time complexity: O(MxN).
Space complexity: O(1).
*/ 
