/*
Given a positive integer n. Find the sum of all divisors of i where ( 1 <= i <= n)
Examples :


Input: 4
Output: 15
Explanation
F(1) = 1
F(2) = 1 + 2 = 3
F(3) = 1 + 3 = 4
F(4) = 1 + 2 + 4 = 7
ans = F(1) + F(2) + F(3) + F(4)
    = 1 + 3 + 4 + 7
    = 15
    
1 <= T <= 500
1 <= N <= 106



Solution 1 : 
is to traverse for every number(1 to n), find all divisors and keep updating the sum with that divisor
Time complexity: O(n.sqrt(n))
*/

int divisorSum(int n) i
{ 
    int sum = 0; 
  
    for (int i = 1; i <= n; ++i) 
    for (int j = 1; j * j <= i; ++j) 
    { 
         if(i % j)
         continue;
         sum +=j;
         if(j*j == i)
         continue;
         sum += i/j;
    } 
    return sum; 
} 
/*
Solution 2 :
is to traverse for every numb(1 to n), find all prime factors and keep updating the sum with that factor
Time complexity: O(n.log(n))
*/

#define N 1000009
vector<int>spf(N);
void sieve()
{
    for(int i=2;(long long)i*i<N;i++)
    if(!spf[i])
    for(int j=i;j<N;j+=i)
    spf[j] = i;
    
    for(int i=3;i<N;i+=2)
    if(!spf[i])spf[i] = i;
}
int getsum(int n)
{
    int sum=1;
    while(n!=1)
    {
        int pw=1,cur=1;
        int x = spf[n];
        while(n%x==0)
        {
            pw *= x;
            cur+=pw;
            n /= x;
        }
        sum *=cur;
    }
    return sum;
}
int main()
{
    sieve();
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;long long ans=0;
        for(int i=1;i<=n;i++)
        ans+=getsum(i);
        cout<<ans<<'\n';
    }
	return 0;
}

/*
Solution 3 :
is to traverse for every number(1 to n), and add d[i] to sum where d[i] contains sum of all divisors of i
Time complexity: O(N.log(N)) for function solve
and o(n) for each test case
*/

#define N 1000009
void solve()
{
    for(int i=1;i<N;i++)
    for(int j=i;j<N;j+=i)
    d[j]+=i;
}
int main()
{
    solve();
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;long long ans=0;
        for(int i=1;i<=n;i++)
        ans+=d[i];
        cout<<ans<<'\n';
    }
	return 0;
  
}

/*
Solution 4 :
is to observe the function and co-relate the pattern
For a given number n, every number from 1 to n contribute 
it’s presence up to the highest multiple less than n 

Let n = 6
=> F(1) + F(2) + F(3) + F(4) + F(5) + F(6)
=> 1 will occurs 6 times in F(1), F(2),
   F(3), F(4), F(5) and F(6)
=> 2 will occurs 3 times in F(2), F(4) and
   F(6)
=> 3 will occur 2 times in F(3) and F(6)
=> 4 will occur 1 times in F(4)
=> 5 will occur 1 times in F(5)
=> 6 will occur 1 times in F(6)
From above observation, it can easily be observed that number i is occurring only in there multiples less than or equal to n
Thus, we just need to find the count of multiples and then multiply it with i for full contribution in the final sum
It can easily be done in O(1) time by taking floor of (n / i) and then multiply it with i for the sum

*/
int divisorSum(int n) 
{ 
    int sum = 0; 
    for (int i = 1; i <= n; ++i) 
        sum += (n / i) * i; 
    return sum; 
} 
