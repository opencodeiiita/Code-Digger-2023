STATMENT

You have given a sequence of N integer $A_1,A_2$,..., $A_n$ .

Defined a operation such - choose two integer i and j such that (i is not equal to j)
each between 1 and N . and Add 1 to $A_i$ and Subtract 1 from $A_j$ .

You can do above operation atmost K times .

Compute the maximum possible positive integer that divides every element of 
A after the operations. Here a positive integer x divides an integer 
y if and only if there exists an integer z such that y=xz.


CONSTRAINTS

$2 <= N <= 500$

$1<= A_i <= 1000000$

$0<= k <= 1000000000$


INPUT FORMAT

first line contain two integer *n* and *k* , next line contain n integer
$A_1,A_2$,..., $A_n$

OUTPUT FORMAT

Print the maximum possible positive integer that divides every element of 
A after the operations.


EXAMPLE 

Input :-

2 3

8 20

Output :-

7
