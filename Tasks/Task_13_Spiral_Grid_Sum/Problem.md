## Problem Statement

You are given a park represented as a grid of size n x m, where each cell contains a tree with fruits in increasing order from 1 to n * m, arranged from left to right as shown below for a 4*6 grid :

<pre>
1   2  3  4  5  6
7   8  9 10 11 12
13 14 15 16 17 18
19 20 21 22 23 24
</pre>

A monkey is positioned at cell (a, b) and needs to reach cell (c, d) while picking all the berries along the way.
But it is constrained to move along a fixed spiral path as illustrated below :
<pre>
 1 →  2 →  3 →  4 →  5 →  6 
                          ↓ 
 7  → 8  →  9 → 10 → 11  12 
 ↑                   ↓    ↓ 
 13   14 ← 15 ← 16 ← 17  18 
 ↑                        ↓ 
 19 ← 20 ← 21 ← 22 ← 23 ← 24 
</pre>

Your task is to write a program that, given q queries, outputs the total number of berries 
the monkey will pick along its path from the starting cell to the destination cell. 

Note : The result should be computed modulo 10^9 + 7, as the answer can be large.

Input Format : <br>
Take three integers n,m,q. <br>
Then for each query take 4 integers : a,b,c,d

Output Format : <br>
For each query output the desired number

Constraints : <br>
1 <= n,m <= 10^9 <br> 
1 <= q   <= 2*10^5 <br>
1 <=  a,c <=  n <br>
1 <=  b,d <=  m <br>

<pre>
Sample
Input : 
4 6 2
1 2 4 5 
4 3 3 4 

Output :
97
151
</pre>