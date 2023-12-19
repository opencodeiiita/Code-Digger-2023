// Solved By - Prakhar Shukla

/*
Pattern Decoded in 23, 36, 64, 128:
Binary = 10111 100100 1000000 10000000

Lets define a function f which takes a binary string and performs follwing operations sequentially:
i. unsets middle bit (both of the middle bits if no of bits are even) 
ii. unsets least significant bit
iii. Left shift the number

f(23) = f(10111) = 100100(36 = next element)
f(36) = f(100100) = 1000000 (64)
f(64) = f(1000000) = 10000000 (128)
f(128) = f(10000000) = (100000000)

Similarly it works on second series also.

*/

#include <bits/stdc++.h>

using namespace std;

int f(int &num)
{
    int n_bits = (int)log2(num) + 1; // Calculates number of bits in num. (Source: GFG)
    // debug(n_bits);

    if (n_bits % 2)
    {
        num &= (~(1 << (((n_bits + 1) / 2) - 1))); // unsets middle bit
        num &= (~(1));                             // unsets least significant bit
        return num << 1;
    }
    else
    {
        num &= ~(1 << (n_bits / 2 - 1)); // unsetting n/2th bit
        num &= (~(1 << (n_bits / 2)));   // unsetting (n/2+1)th bit
        num &= (~1);                     // unsets least significant bit bit
        return num << 1;
    }
}

void solve()
{
    int num;
    cin >> num;
    for (int i = 0; i < 5; i++)
    {
        cout << num << " ";
        num = f(num);
    }
    cout << endl;
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
