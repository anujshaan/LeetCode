/*
  ASKED IN AMAZON

 You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3]

Output:[3, 4]

A = 3, B = 4
 */

#include<bits/stdc++.h>
using namespace std;

void calc(vector<int> &ar)
{
    int n = ar.size();
    int i = 0;
    while (i < n)
    {
        if(ar[i] != ar[ar[i]-1])
            swap(ar[i],ar[ar[i]-1]);
        else
            i++;
    }
    for(int i = 0; i < n; i++) {
        if (ar[i] != i + 1) {
            cout << "missing :" << i + 1;
            cout << "\nduplicate: " << ar[i];
        }
    }
}
int main()
{
    vector<int> p = {1,1,4,5,2};
    calc(p);
    return 0;
}
