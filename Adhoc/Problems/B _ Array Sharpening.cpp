/*
You're given an array a1,…,an of n non-negative integers.

Let's call it sharpened if and only if there exists an integer 1 ≤ k ≤ n such that a1 < a2 < … < ak and ak > ak+1 > … > an
In particular, any strictly increasing or strictly decreasing array is sharpened

The arrays [4], [0,1], [12,10,8] and [3,11,15,9,7,4] are sharpened;
The arrays [2,8,2,8,6,5], [0,1,1,0] and [2,5,6,9,8,8] are not sharpened.
You can do the following operation as many times as you want:
choose any strictly positive element of the array, and decrease it by one
Formally, you can choose any i (1 ≤ i ≤ n) such that a[i]>0 and assign a[i] = a[i] - 1

Tell if it's possible to make the given array sharpened using some number (possibly zero) of these operations.

1 ≤ n ≤ 3⋅10^5
0 ≤ ai ≤ 10^9 

Codeforces problem link : https://codeforces.com/contest/1291/problem/B

Solution :
How to know if we can make the prefix [1;k] strictly increasing? We just have to consider the following simple greedy solution: 
take down values to 0,1,…,k−1 (minimal possible values). It's possible if and only if ai≥i−1 holds in the whole prefix.

Similarly, the suffix [k;n] can be made strictly decreasing if and only if ai≥n−i holds in the whole suffix.

Using these simple facts, we can compute the longest prefix we can make strictly increasing,
and the longest suffix we can make strictly decreasing in O(n). Then, we just have to check that their intersection is non-empty.

*/

int main()
{
    int nbTests; cin >> nbTests;
    while (nbTests--) {
	    int nbElem; cin >> nbElem;
	    vector<int> tab(nbElem);

	    for (int i = 0; i < nbElem; ++i)
		    cin >> tab[i];

	    int prefixEnd = -1, suffixEnd = nbElem;

	    for (int i = 0; i < nbElem; ++i) {
		    if (tab[i] < i) break;
		    prefixEnd = i;
	    }
	    for (int i = nbElem-1; i >= 0; --i) {
		    if (tab[i] < (nbElem-1)-i) break;
		    suffixEnd = i;
	    }

	    if (suffixEnd <= prefixEnd) // Non-empty intersection
		    cout << "Yes\n";
	    else
		    cout << "No\n";
    }
}
