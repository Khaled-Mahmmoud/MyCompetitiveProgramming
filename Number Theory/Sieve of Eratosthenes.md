```cpp
/*
<Sieve of Eratosthenes> (Simple Sieve)
Time complexity : O(n.log(log(n)))
Auxiliary space : O(MAX)   MAX = 10^7 (vector)
*/
#define N 10000009 
vector<int>spf(N); // Smallest Prime Factor
void sieve()
{
    for(int i=2;i*i<N;i++)
    if(!spf[i])
        for(int j=i*i;j<N;j+=i)
	    if(!spf[j])
               spf[j] = i;
    
    for(int i=3;i<N;i+=2)
        if(!spf[i])
        spf[i] = i;
}
// O(log(n))
vector<int> primeFactors(int x) 
{ 
    vector<int> res; 
    while (x != 1) 
    { 
        res.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return res; 
} 

// Store all prime numbers in vector primes  less than 10^7
// Forward thinking
int primes(int n)
{
    vector<int> ans;
    for(int i = 1; i <= n; ++i)
        if( isprime(i) )
            ans.push_back(i);
    return ans;
}
// O(n * sqrt(n))

// Backward thinking
#define N 10000009 
vector<int>primes;
void sieve()
{
	vector<bool>mark(N,true);
	for (int i=2; i*i<limit; i++)
	if (mark[i])
	    for (int j=i*i; j<limit; j+=i)
		mark[j] = false;
	
	for (int i=2; i<limit; i++)
	if (mark[i])
	{
		prime.push_back(i);
		cout << i << " ";
	}
}
// O(n log long n)
/*
How is the time complexity of Sieve of Eratosthenes is n*log(log(n))?
What is Sieve of Eratosthenes algorithm?
In order to analyze it, let’s take a number n and the task is to print the prime numbers less than n.
Therefore, by definition of Sieve of Eratosthenes, for every prime number.
it has to check the multiples of the prime and mark it as composite.
This process continues until a value p which is the highest prime number less than n.
Understanding the n*log(log n) time complexity of Sieve of Eratosthenes
If it is assumed that the time taken to mark a number as composite is constant, then the number of times the loop runs is equal to:
n/2 + n/3 + n/5 + n/7 + ...... p
On taking n common from the above equation, the above equation can be rewritten as:
n * ( 1/2 + 1/3 + 1/5 + 1/7 + ...... p)
It can be proved as below with the help of Harmonic Progression of the sum `( 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + ...... 1/n) = log n`
Harmonic Progression of the sum of primes `( 1/2 + 1/3 + 1/5 + 1/7 + ...... p) = log(log n)`
So n/2 + n/3 + n/5 + n/7 + ...... p = nlog(logn)

int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}; // [1-100]
It is known that amount of prime numbers non greater than n is about **(n / log n)**
(2^31)-1 is a prime number with value 2147483647
(2^61)-1 is a prime number with value 2305843009213693951
primesRangeCnt 10^i (4, 25, 168, 1229, 9592, 78498, 664579, 5761455) [e.g. 4 primes <= 10^1] ~= n / log(n)
257, 263, 269, 271 -> 4 primes their multiplication > 2^32
 */
 
// Generate prime divisors for all number from 1 to n
// O(n*log(n)) // max -> 2e6
const int M = 2e6;
vector<int> primeDivs[M + 1];
void primeDivisors()
{
    for(int i = 2; i <= M; i += 2)
        primeDivs[i].push_back(2);
    for(int i = 3; i <= M; i += 2)
    {
        if(primeDivs[i].empty())
            for (int j = i; j <= M; j += i)
                primeDivs[j].push_back(i);
    }
}
 ```
