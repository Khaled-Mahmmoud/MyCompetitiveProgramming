void primeFactors(int n)  
{  
    while (!(n & 1))  
    {  
        cout << 2 << " ";  
        n >> = 1;  
    }
    for (int i = 3; i*i <= n; i += 2)  
    {  
        while (!(n % i))  
        {  
            cout << i << " ";  
            n /= i;  
        }  
    }    
    if (n > 1)  
        cout << n << " ";  
} 
// O(sqrt(n))


// using Sieve of Eratosthenes
// O(n.log(log(n)))
// Auxiliary space : O(MAX)
#define N 10000009 
vector<int>spf(N);
void sieve()
{
    for(int i=2;i*i<N;i++)
    if(!spf[i])
        for(int j=i;j<N;j+=i)
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
#define N 10000009 
vector<int>primes;
void sieve()
{
    vector<bool>iscomposite(N,false);
    for(int i=2;i*i<N;i++)
    if(!iscomposite[i])
        for(int j=2*i;j<N;j+=i) // notice that we start from 2*i
          iscomposite[j] = true;
    
    for(int i=2;i<N;i++)
        if(!iscomposite[i])
           primes.push_back(i);
}
