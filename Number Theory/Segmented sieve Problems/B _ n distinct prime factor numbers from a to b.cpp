/*


Exactly n distinct prime factor numbers from a to b
You are given two numbers a and b (1 <= a,b <= 10^8 ) and n
The task is to find all numbers between a and b inclusively having 
exactly n distinct prime factors. The solution should be designed 
in a way that it efficiently handles multiple queries for 
different values of a and b like in Competitive Programming.

Input  : a = 1, b = 10, n = 2
Output : 2
// Only 6 = 2*3 and 10 = 2*5 have exactly two 
// distinct prime factors

Input : a = 1, b = 100, n = 3
Output: 2
// only 30 = 2*3*5, 42 = 2*3*7, 60 = 2*2*3*5, 66 = 2*3*11,
// 70 = 2*5*7, 78 = 2*3*13, 84 = 2*2*3*7 and 90 = 2*3*3*5 
// have exactly three distinct prime factors
This problem is basically application of segmented sieve. As we know that all prime factors
of a number are always less than or equal to square root of number i.e; sqrt(n)
So we generate all prime numbers less than or equals to 10^8 and store them in an array
Now using this segmented sieve we check each number from a to b to have exactly n prime factors

*/

vector<int> primes;
void segmentedSieve() 
{ 
	int limit = 10000;
   	bool mark[limit+1];
	   memset(mark, true, sizeof(mark));

  	for (int i=2; i*i<limit; i++)
	  	if (mark[i])
		  	for (int j=i*2; j<limit; j+=i)
			  	mark[j] = false;
  	for (int i=2; i<limit; i++)
	  	if (mark[i])
		  	primes.push_back(i);
}  
int Nfactors(int a, int b, int n) 
{ 
    int result = 0; 
    for (int i=a; i<=b; i++) 
    { 
        int tmp = sqrt(i), copy = i; 
        int count = 0; 
        for (int j=0; primes[j]<=tmp; j++) 
        { 
            if (copy%primes[j]==0) 
            { 
                count++; 
                while (copy%primes[j]==0) 
                    copy = copy/primes[j]; 
            } 
        } 
        if (copy != 1) 
            count++; 
        if (count==n) 
            result++; 
    } 
    return result; 
} 
int main() 
{ 
    segmentedSieve(); 
    int t;cin>>t;while(t--){
    int a = 1, b = 100, n = 3; 
    cout << Nfactors(a, b, n)<<'\n';}
    return 0; 
} 
