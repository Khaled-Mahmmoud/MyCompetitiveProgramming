/*

Find Square Root under Modulo p (Shanks Tonelli algorithm)
Given a number ‘n’ and a prime ‘p’, find square root of n under modulo p if it exists.

Input: n = 2, p = 113
Output: 62
62^2 = 3844  and  3844 % 113 = 2

Input:  n = 2, p = 7
Output: 3 or 4
3 and 4 both are square roots of 2 under modulo
7 because (3*3) % 7 = 2 and (4*4) % 7 = 2

Input:  n = 2, p = 5
Output: Square root doesn't exist

We have discussed Euler’s criterion to check if square root exists or not
We have also discussed a solution that works only when p is in form of 4*i + 3
In this post, Shank Tonelli’s algorithm is discussed that works for all types of inputs.

Algorithm steps to find modular square root using shank Tonelli’s algorithm :

1) Calculate n ^ ((p – 1) / 2)) (mod p), it must be 1 or p-1, if it is p-1
then modular square root is not possible.

2) Then after write p-1 as (s * 2^e) for some integer s and e
where s must be an odd number and both s and e should be positive.

3) Then find a number q such that q ^ ((p – 1) / 2) (mod p) = -1

4) Initialize variable x, b, g and r by following values
   x = n ^ ((s + 1) / 2) (first guess of square root)
   b = n ^ s                
   g = q ^ s
   r = e   (exponent e will decrease after each updation) 
   
5) Now loop until m > 0 and update value of x, which will be our final answer
   Find least integer m such that b^(2^m) = 1(mod p)  and  0 <= m <= r – 1 
   If m = 0, then we found correct answer and return x as result
   Else update x, b, g, r as below
       x = x * g ^ (2 ^ (r – m - 1))
       b = b * g ^(2 ^ (r - m))
       g = g ^ (2 ^ (r - m))
       r = m 
so if m becomes 0 or b becomes 1, we terminate and print the result
This loop guarantees to terminate because value of m is decreased each time after updation.

*/

int pow(int base, int exponent, int modulus) 
{ 
    int result = 1; 
    base = base % modulus; 
    while (exponent > 0) 
    { 
        if (exponent % 2 == 1) 
           result = (result * base)% modulus; 
        exponent = exponent >> 1; 
        base = (base * base) % modulus; 
    } 
    return result; 
} 
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    else
        return gcd(b, a % b); 
} 
int order(int p, int b) 
{ 
    if (gcd(p, b) != 1) 
    { 
        printf("p and b are not co-prime.\n"); 
        return -1; 
    } 
    int k = 3; 
    while (1) 
    { 
        if (pow(b, k, p) == 1) 
            return k; 
        k++; 
    } 
} 
int convertx2e(int x, int& e) 
{ 
    e = 0; 
    while (x % 2 == 0) 
    { 
        x /= 2; 
        e++; 
    } 
    return x; 
} 
int STonelli(int n, int p) 
{ 
    if (gcd(n, p) != 1) 
    { 
        printf("a and p are not coprime\n"); 
        return -1; 
    } 
    if (pow(n, (p - 1) / 2, p) == (p - 1)) 
    { 
        printf("no sqrt possible\n"); 
        return -1; 
    }  
    int s, e; 
    s = convertx2e(p - 1, e); 
    int q; 
    for (q = 2; ; q++) 
    { 
        if (pow(q, (p - 1) / 2, p) == (p - 1)) 
            break; 
    } 
    int x = pow(n, (s + 1) / 2, p); 
    int b = pow(n, s, p); 
    int g = pow(q, s, p); 
  
    int r = e; 
  
    while (1) 
    { 
        int m; 
        for (m = 0; m < r; m++) 
        { 
            if (order(p, b) == -1) 
                return -1; 
  
            if (order(p, b) == pow(2, m)) 
                break; 
        } 
        if (m == 0) 
            return x; 

        x = (x * pow(g, pow(2, r - m - 1), p)) % p; 
        g = pow(g, pow(2, r - m), p); 
        b = (b * g) % p; 
  
        if (b == 1) 
            return x; 
        r = m; 
    } 
} 
