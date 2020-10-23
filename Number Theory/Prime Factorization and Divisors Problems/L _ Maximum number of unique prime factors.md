# Maximum number of unique prime factors

Given a number N, find the maximum number of unique prime factors any number can have in range [1, N].

Input : N = 500
	
Output : 4
	
The maximum number of prime factors for any number in [1, 500] is 4. A number in range that has 4 prime  factors is 210 (2 x 3 x 5 x 7)


N <= 10^18

```cpp
vector<int>primes;
void sieve()
{
    vector<bool>pr(N,false);
    for(int i=2;(long long)i*i<N;i++)
    if(!pr[i])
    for(int j=i*2;j<N;j+=i)
    pr[j] = true;
    
    for(int i=2;i<N;i++)
    if(!pr[i])primes.push_back(i);
}
int main()
{
    sieve();
    int t;cin>>t;while(t--)
    {
        long long n,res=1;
        cin>>n;int cnt = 0;
        for(int i=0;i<primes.size();i++)
        {
            res *= primes[i];
            if(res>n||res<0)  // IF res exceed 10^18 , res carries negative value
            break;
            cnt++;
        }
        cout<<cnt<<'\n';
    }
	return 0;
}
```
