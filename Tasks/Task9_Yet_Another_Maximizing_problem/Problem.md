**PROBLEM STATEMENT:**

You are Given a binary tree.Each node of tree has some value on it represented in array **v**. You have a special power you can choose any edge of tree and remove that edge. you have to such an edge such that after deleting edge the sum of **bitwise and** of each component of tree is maximized.

NOTE:- For one component, value of **bitwise and** is calculated by talking bitwise and each of its node.For Example lets say a component have node **p<sub>1</sub>, p<sub>2</sub>, p<sub>3</sub>, p<sub>4</sub>** so its value will be **v[p<sub>1</sub>]&v[p<sub>2</sub>]&v[p<sub>3</sub>]&v[p<sub>4</sub>]**.

Lets say there 2 components after deleting an edge **C<sub>1</sub>, C<sub>2</sub>** Your final value to final value will be
bitwise and value of **C<sub>1</sub>** + bitwise and value of **C<sub>2</sub>**

**INPUT FORMAT:**

The First line of input is an integer **T**. The number of the test case.

For Each of the test cases:

- First line contains two integers **n**(1 ≤ **n** ≤ 10<sup>5</sup>)
- Second line contains **n** space seperated integer **v[0] v[1] v[2] v[3] ..... v[n]** (1 ≤ **v[i]** ≤ 10<sup>9</sup>)
- Next **n-1** lines contains two integer **u v** denoting and edge between node **u** and **v**.

**OUTPUT FORMAT**:</br>
For each test case output maximum required value possible

**SAMPLE INPUT**:</br>
1</br>
5</br>
2 3 5 6 8</br>
1 3</br>
1 2</br>
2 4</br>
2 5</br>

**OUTPUT**:</br>
8</br>
**EXPLANATION**</br>
Here if we delete edge 2 5 we get maximum value.

