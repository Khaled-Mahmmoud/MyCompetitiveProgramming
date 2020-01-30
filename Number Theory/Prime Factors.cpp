// O(sqrt(n))
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


// using Sieve of Eratosthenes
// O(n.log(log(n)))

vector<int>spf(N);
void sieve()
{
    for(int i=2;i*i<N;i++)
    if(!spf[i])
        for(int j=i;j<N;j+=i)
          spf[j] = i;
    
    for(int i=1;i<N;i++)
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
