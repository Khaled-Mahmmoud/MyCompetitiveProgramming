/*

Sum of largest prime factor of each number less than equal to n
Given a non-negative integer n. The problem is to find the sum of the largest prime factor of each number less than equal to n


Input : n = 10
Output : 32
Largest prime factor of each number
Prime factor of 2 = 2
Prime factor of 3 = 3
Prime factor of 4 = 2
Prime factor of 5 = 5
Prime factor of 6 = 3
Prime factor of 7 = 7
Prime factor of 8 = 2
Prime factor of 9 = 3
Prime factor of 10 = 5

Sum = (2+3+2+5+3+7+2+3+5) = 32


Algorithm:

sumOfLargePrimeFactor(n)
    Declare prime[n+1] and initialize all value to 0
    Initialize sum = 0
    max = n / 2
 
    for p = 2 to sqrt(n)
        if prime[p] == 0 then
            i = p*2
            while i <= n
                prime[i] = p
                i = i + p
        
    for p = 2 to n
        if prime[p] then
               sum = sum + prime[p]
           else
              sum = sum + p
    
    return sum
    
*/

int sumOfLargePrimeFactor(int n) 
{ 
    int prime[n+1], sum = 0; 
    memset(prime, 0, sizeof(prime)); 

    for (int p=2; p<=sqrt(n); p++) 
    { 
        if (prime[p] == 0) 
        { 
             for (int i=p*2; i<=n; i += p) 
                prime[i] = p; 
        } 
    } 
    for (int p=2; p<=n; p++) 
    { 
        if (prime[p]) 
             sum += prime[p]; 
        else
             sum += p; 
    } 
    return sum;       
} 
