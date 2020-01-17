// O(sqrt(n))
void primeFactors(int n)  
{  
    while (!(n & 1))  
    {  
        cout << 2 << " ";  
        n >> = 1;  
    }
    for (int i = 3; i*i <= n; i = i + 2)  
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
// O(log(n))
// using Sieve of Eratosthenes
#define N 10000009
vector<int>spf(N);
void sieve()
{
    for(int i=0;i<N;i++)
        if(i & 2)spf[i]=i;else spf[i]=2;
    for(int i=3;i*i<N;i+=2)
    {
        if(spf[i]==i)
            for(int j=i*i;j<N;j+=i)
              if(spf[j]==j)
                spf[j]=i;
    }
} 
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
