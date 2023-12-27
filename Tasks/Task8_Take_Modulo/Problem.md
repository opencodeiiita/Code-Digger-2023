**PROBLEM STATEMENT:**

You are given an array **a** you can do following operation exactly 1 time

- choose **l**,**r** such that **1 ≤ l ≤ r ≤ n**
- for every **i** such that **l ≤ i ≤ r** set **a[i]=a[i]%((l-r+1)+1)** (Note :- _l-r+1_ is length of subarray)

You have to choose **l,r** such that after applying the operation given subarray (i.e. subarray from **l** to **r**) becomes a permutation and hence maximize the length of subarray if no permutation is possible just print 0.

**INPUT FORMAT:**

The First line of input is an integer **T**. The number of the test case.

For Each of the test cases:

- First line contains one integer **n(1 ≤ n ≤ 10<sup>3</sup>)**.
- Second line contains **n** integer **a[0] a[1] a[2] a[3] ..... a[n]** (1 ≤ **a[i]** ≤ 10<sup>9</sup>)

Sum of n overall Testcases does not exceeds **10<sup>3</sup>**

**OUTPUT FORMAT**:

Output length of Maximum Subarray

**SAMPLE INPUT**: </br>
1</br>
4</br>
5 7 6 13</br>

**OUTPUT**: </br>
3

**EXPLANATON**
In this test case we have to choose l=1 and r=3 so subarray converts to [5%4 7%4 6%4] --> [1 3 2] Hence answer is 3.
