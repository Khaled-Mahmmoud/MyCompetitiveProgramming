# Count number of pairs (A <= N, B <= N) such that gcd (A , B) is B

Given a number n. We need find the number of ordered pairs of a and b such gcd(a, b) is b itself.
    
Input : n = 2
    
Output : 3, (1, 1) (2, 2) and (2, 1) 
    
Input : n = 3
    
Output : 5, (1, 1) (2, 2) (3, 3) (2, 1) and (3, 1)
    
gcd(a, b) = b means that a is a multiple of b.
    
So total number of pairs will be sum of number of multiples of each b 
(where b varies from 1 to n) which are less than or equal to n.
For a number i, number of multiples of i is equal to floor(n/i)
So what we need to do is just sum the floor(n/i) for each i = 1 to n and print it.

Complexity : O(n)
```cpp
int main()
{
    int n,ans=0;cin>>n;
    for(int i=1;i<=n;i++)
        ans+=n/i;
    cout<<ans;
    return 0;
}
```
