# Array Sharpening

[Problem Link](https://codeforces.com/problemset/problem/1291/B)

**Tutorial**

How to know if we can make the prefix [1;k] strictly increasing? We just have to consider the following simple greedy solution: take down values to 0,1,…,k−1 (minimal possible values). It's possible if and only if ai≥i−1 holds in the whole prefix.

Similarly, the suffix [k;n] can be made strictly decreasing if and only if ai≥n−i holds in the whole suffix.

Using these simple facts, we can compute the longest prefix we can make strictly increasing, and the longest suffix we can make strictly decreasing in O(n). Then, we just have to check that their intersection is non-empty.

```cpp
int main()
{
    int nbTests;
    cin >> nbTests;
    while (nbTests--)
    {
        int nbElem;
        cin >> nbElem;
        vector<int> tab(nbElem);

        for (int i = 0; i < nbElem; ++i)
            cin >> tab[i];

        int prefixEnd = -1, suffixEnd = nbElem;

        for (int i = 0; i < nbElem; ++i)
        {
            if (tab[i] < i)
                break;
            prefixEnd = i;
        }
        for (int i = nbElem-1; i >= 0; --i)
        {
            if (tab[i] < (nbElem-1)-i)
                break;
            suffixEnd = i;
        }

        if (suffixEnd <= prefixEnd)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
```
