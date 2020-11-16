# Chinese Remainder Theorem

We are given two arrays num[0..k-1] and rem[0..k-1]. In num[0..k-1], every pair is coprime (gcd for every pair is 1)
We need to find minimum positive number x such that:
```
     x % num[0]    =  rem[0], 
     x % num[1]    =  rem[1], 
     .......................
     x % num[k-1]  =  rem[k-1] 
```
Input:  num[] = {3, 4, 5}, rem[] = {2, 3, 1}, Output: 11
     

The solution is based on below formula

x =  ( &Sum; (rem[i]*pp[i]*inv[i]) ) % prod
   
Where 0 <= i <= n-1, rem[i] is given array of remainders

prod is product of all given numbers. prod = num[0] * num[1] * ... * num[k-1]

pp[i] is product of all divided by num[i]. pp[i] = prod / num[i]

inv[i] = Modular Multiplicative Inverse of  pp[i] with respect to num[i]


num[] = {3, 4, 5}, rem[] = {2, 3, 1}

prod  = 60
     
pp[]  = {20, 15, 12}
   
inv[] = {2,  3,  3}  // (20*2)%3 = 1, (15*3)%4 = 1 // (12*3)%5 = 1

x = (rem[0]*pp[0]*inv[0] + rem[1]*pp[1]*inv[1] + rem[2]*pp[2]*inv[2]) % prod = (2*20*2 + 3*15*3 + 1*12*3) % 60 = (40 + 135 + 36) % 60 = 11

```cpp
int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)  
    {  
        *x = 0;  
        *y = 1;  
        return b;  
    }  
  
    int x1, y1;  
    int g = gcdExtended(b%a, a, &x1, &y1);   
    *x = y1 - (b/a) * x1;  
    *y = x1;  
  
    return g; 
}
int modInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        cout << "Inverse doesn't exist"; 
    else
    { 
        int res = (x%m + m) % m; 
        return  res; 
    } 
} 
int findMinX(int num[], int rem[], int k) 
{ 
    int prod = 1; 
    for (int i = 0; i < k; i++) 
        prod *= num[i]; 
        
    int result = 0; 
    for (int i = 0; i < k; i++) 
    { 
        int pp = prod / num[i]; 
        result += rem[i] * inv(pp, num[i]) * pp; 
    } 
  
    return result % prod; 
} 
int main(void) 
{ 
    int num[] = {3, 4, 5}; 
    int rem[] = {2, 3, 1}; 
    int k = sizeof(num)/sizeof(num[0]); 
    cout << "x is " << findMinX(num, rem, k); 
    return 0; 
} 
```
