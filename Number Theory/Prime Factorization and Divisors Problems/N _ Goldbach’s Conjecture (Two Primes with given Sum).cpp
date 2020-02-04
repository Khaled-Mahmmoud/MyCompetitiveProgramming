/*
Program for Goldbach’s Conjecture (Two Primes with given Sum)
Goldbach’s conjecture is one of the oldest and best-known unsolved problems in number theory of mathematics
Every even integer greater than 2 can be expressed as the sum of two primes.

Examples:

Input :  n = 44
Output :   3 + 41 (both are primes)

Input :  n = 56
Output :  3 + 53  (both are primes)

Solution :
1) Find the prime numbers using Sieve of eratosthenes O(nloglog(n))
2) Check if entered number is an even number greater than 2 or not, if no return.
If yes, then one by one subtract a prime from N and then check if the difference is also a prime
if yes then express it as a sum

*/

const int MAX = 10000; 
vector <int> primes;
void sieveEratosthenes() 
{ 
     vector<bool>pr(MAX,false);
     
     for(int i=2 ; i*i<MAX ; i++)
     if(!pr[i])
     for(int j=2*i ; j<MAX ; j+=i)
     pr[j] = true;
   
     for(int i=2;i<MAX;i++)
     if(!pr[i]) primes.push_back(i);
} 
void findPrimes(int n) 
{ 
    if (n<=2 || n%2 != 0) 
    { 
        cout << "Invalid Input \n"; 
        return; 
    } 
     for (int i=0 ; primes[i] <= n/2; i++) 
    { 
        int diff = n - primes[i]; 
        if (binary_search(primes.begin(), primes.end(), diff)) 
        { 
            cout << primes[i] << " + " << diff << " = "<< n << endl; 
            return; 
        } 
    } 
} 
