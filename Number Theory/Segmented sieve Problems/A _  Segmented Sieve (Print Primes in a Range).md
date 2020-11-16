Given a range [low, high], print all primes in this range? For example, if the given range is [10, 20], then output is 11, 13, 17, 19.
```cpp
void simpleSieve(int limit, vector<int> &prime)
{
	bool mark[limit+1];
	memset(mark, true, sizeof(mark));

	for (int i=2; i*i<limit; i++)
		if (mark[i])
			for (int j=i*2; j<limit; j+=i)
				mark[j] = false;
	for (int i=2; i<limit; i++)
		if (mark[i])
			prime.push_back(i);
}
void segmentedSieve(int low,int high)
{
	int limit = sqrt(high)+1;
	vector<int> prime;
	simpleSieve(limit, prime);
	bool mark[(high-low+1)+1];
	memset(mark, true, sizeof(mark));
	for (int i = 0; i < prime.size(); i++)
	{
		int loLim = (low/prime[i]) * prime[i];
		if (loLim < low)
			loLim += prime[i];
		if(loLim == prime[i])
		loLim += prime[i];
		for (int j=loLim; j<=high; j+=prime[i])
			mark[j-low] = false;
	}
	for (int i = low; i<=high; i++)
		if (mark[i - low] == true)
			cout<<i<<' ';
}
int main()
{
    int t;cin>>t;while(t--)
    {
        int l,r;cin>>l>>r;
        segmentedSieve(l,r);
    }
	return 0;
}
