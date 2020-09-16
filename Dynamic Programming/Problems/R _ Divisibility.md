# Divisibility 

Consider an arbitrary sequence of integers. One can place + or - operators between integers in the
sequence, thus deriving different arithmetical expressions that evaluate to different values. Let us, for
example, take the sequence: 17, 5, -21, 15. There are eight possible expressions:
```
17 + 5 + -21 + 15 = 16
17 + 5 + -21 - 15 = -14
17 + 5 - -21 + 15 = 58
17 + 5 - -21 - 15 = 28
17 - 5 + -21 + 15 = 6
17 - 5 + -21 - 15 = -24
17 - 5 - -21 + 15 = 48
17 - 5 - -21 - 15 = 18
```
We call the sequence of integers divisible by K if + or - operators can be placed between integers
in the sequence in such way that resulting value is divisible by K. In the above example, the sequence
is divisible by 7 (17+5+-21-15=-14) but is not divisible by 5.
You are to write a program that will determine divisibility of sequence of integers.

Input :
The first line of the input file contains a integer M indicating the number of cases to be analyzed. Then
M couples of lines follow.
For each one of this couples, the first line of the input file contains two integers, N and K (1 ≤ N ≤
10000, 2 ≤ K ≤ 100) separated by a space.
The second line contains a sequence of N integers separated by spaces. Each integer is not greater
than 10000 by it’s absolute value.

Output :
For each case in the input file, write to the output file the word ‘Divisible’ if given sequence of integers
is divisible by K or ‘Not divisible’ if it’s not.

Input

2

4 7

17 5 -21 15

4 5

17 5 -21 15

Output

Divisible

Not divisible

```cpp
int dp[10009][109];
int n,k;
int a[10009];
int fix(int x)
{
	return (x % k + k) % k;
}
bool solve(int i, int mod)
{
	int &ret = dp[i][mod];
	if (~ret)
		return ret;
	if (i == n)
		return ret = (mod == 0);

	if (solve(i + 1, fix(mod + a[i])) || solve(i + 1, fix(mod - a[i])))
		return ret = 1;
	return ret = 0;
}
int main()
{
    int t;cin>>t;while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>a[i];
        memset(dp,-1,sizeof dp);
        if(solve(1,fix(a[0])))
            cout<<"Divisible";
        else
            cout<<"Not divisible";
        cout<<'\n';
    }
    return 0;
}
```
Complexity : O(nk)
