*PROBLEM STATMENT*

There are N homes in a plane , ith home at co-ordinate $(X_i,Y_i)$ .

Answer the following Query : What is the distance between $(a_i,b_i)$ and the $K_i$th nearest Home to that point, measured in Manhattan distance?


*INPUT FORMAT*

first line contain a integer N,

next N line contain two integer $x_i$ and $y_i$ , co-ordinate of ith home

next line contain a integer Q (number of Queries)

next Q line contain three integer $a_i$ , $b_i$ and $K_i $ 

*OUTPUT FORMAT*

Print Q line , ith line should contain answer to ith query


*EXAMPLE*

Input :

4

3 3

4 6

7 4

2 5

6

3 5 1

3 5 2

3 5 3

3 5 4

100 200 3

300 200 1


Output :

1

2

2

5

293

489
