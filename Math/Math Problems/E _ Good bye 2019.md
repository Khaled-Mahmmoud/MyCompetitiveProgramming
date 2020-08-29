# Good bye 2019

For an array a of integers let's denote its maximal element as max(a), and minimal as min(a). 

We will call an array a of k integers interesting if `max(a)−min(a) ≥ k`.

For example, array [1,3,4,3] isn't interesting as max(a)−min(a)=4−1=3<4 while array [7,3,0,4,3] is as max(a)−min(a)=7−0=7≥5 is interesting.

**Solution***

You are given an array a of n integers. Find some interesting nonempty subarray of a, or tell that it doesn't exist.

We will show that if some interesting nonempty subarray exists, then also exists some interesting subarray of length 2

Therefore, the solution is as follows: 
for each i from 1 to n−1 check if |a(i+1) − a(i)| ≥ 2 holds. If this is true for some i,
we have found an interesting subarray of length 2 else such subarray doesn't exist
```cpp
int main()
{
    int t;cin>>t;while(t--)
    {
        bool flag=true;
        int n;cin>>n;int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=1;i<n;i++)
        if(abs(a[i]-a[i-1])>=2)
        {
             cout<<"YES\n"<<i<<' '<<i+1;
             flag = false;
             break;
        }
        if(flag)
           cout<<"NO";
        cout<<'\n';
    }
    return 0;
}
```
