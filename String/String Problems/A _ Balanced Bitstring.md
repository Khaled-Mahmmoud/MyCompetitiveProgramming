# Balanced Bitstring

A bitstring is a string consisting only of the characters 0 and 1. A bitstring is called k-balanced if every substring of size k of this bitstring has an equal amount of 0 and 1 characters (k2 of each).

You are given an integer k and a string s which is composed only of characters 0, 1, and ?. You need to determine whether you can make a k-balanced bitstring by replacing every ? characters in s with either 0 or 1.

A string a is a substring of a string b if a can be obtained from b by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

Input :
Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 10^4). Description of the test cases follows.

The first line of each test case contains two integers n and k (2 ≤ k ≤ n ≤ 3⋅10^5, k is even)  — the length of the string and the parameter for a balanced bitstring.

The next line contains the string s (|s|=n). It is given that s consists of only 0, 1, and ?.

It is guaranteed that the sum of n over all test cases does not exceed 3⋅105.

Output :
For each test case, print YES if we can replace every ? in s with 0 or 1 such that the resulting bitstring is k-balanced, or NO if it is not possible.
```
input
9
6 4
100110
3 2
1?1
3 2
1?0
4 4
????
7 4
1?0??1?
10 10
11??11??11
4 2
1??1
4 4
?0?0
6 2
????00
output
YES
YES
NO
YES
YES
NO
NO
YES
NO
```
Note

For the first test case, the string is already a 4-balanced bitstring.

For the second test case, the string can be transformed into 101.

For the fourth test case, the string can be transformed into 0110.

For the fifth test case, the string can be transformed into 1100110.

[Tutorial](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/String/tutorial%20of%20balanced%20bitstring.png)
```cpp
int n, k, t;
string s;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> s;
        int zer = 0, one = 0;
        bool chk = true;
        for (int i = 0; i < k; i++)
        {
            int tmp = -1;
            for (int j = i; j < n; j += k)
            {
                if (s[j] != '?')
                {
                    if (tmp != -1 && s[j] - '0' != tmp)
                    {
                        chk = false;
                        break;
                    }
                    tmp = s[j] - '0';
                }
            }
            if (tmp != -1)
            {
                (tmp == 0 ? zer : one)++;
            }
        }
        if (max(zer, one) > k / 2)
        {
            chk = false;
        }
        cout << (chk ? "YES\n" : "NO\n");
    }
}

```
