/*
This page contains a step by step explanation of simple but fast C++ implementation of segmented sieve 
of Eratosthenes that generates the primes below n using O(n log log n) operations and O(sqrt(n)) space
It runs significantly faster than  a traditional sieve of Eratosthenes implementation due to its more 
efficient CPU cache usage i.e. This implementation generates the primes below 10^9 in just 0.8 seconds 

 n    Prime Count 	Segmented byte sieve
10^7	    664,579	          	0.03s
10^8	    5,761,455	        	0.11s
10^9	    50,847,534	         	0.65s
10^10	  455,052,511	        	7.25s
10^11  	4,118,054,813	        	88.47s
10^12  	37,607,912,018	        	1104.0s

*/
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
		{
			prime.push_back(i);
			cout << i << " ";
		}
}
void segmentedSieve(int n)
{
	int limit = sqrt(n)+1;
	vector<int> prime;
	simpleSieve(limit, prime);
	int low = limit;
	int high = 2*limit;
	while (low < n)
	{
		if (high >= n)
		high = n;
		bool mark[limit+1];
		memset(mark, true, sizeof(mark));
		for (int i = 0; i < prime.size(); i++)
		{
			int loLim = floor(low/prime[i]) * prime[i];
			if (loLim < low)
				loLim += prime[i];
			for (int j=loLim; j<high; j+=prime[i])
				mark[j-low] = false;
		}
		for (int i = low; i<high; i++)
			if (mark[i - low] == true)
				cout << i << " ";
		low = low + limit;
		high = high + limit;
	}
}
int main()
{
	cout << "Primes Smaller Than " << n << " : ";
	segmentedSieve(n);
	return 0;
}
