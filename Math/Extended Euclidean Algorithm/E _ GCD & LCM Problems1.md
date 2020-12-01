### Given GCD(a,b) G and LCM(a,b) L, find number of possible pairs (a, b)

We need to find number of possible pairs (a, b) such that GCD(a, b) is equal to given G and LCM(a, b) is equal to given L.
    
Input : G = 2, L = 12 , Output : 4
    
Explanation : There are 4 possible pairs : (2, 12), (4, 6), (6, 4), (12, 2)

**Solution** 1 (Simple):

Since a and b both will be less than or equal to lcm(a, b) L

so we try all possible pairs that have product equal to L * G

Note that product of a and b is same as product of gcd(a, b) and lcm(a, b), a*b = G*L

```cpp
int countPairs(int G, int L) 
{ 
    int count = 0; 
    int p = G*L; 
    for (int a=1; a<=L; a++) 
        if (!(p%a) && gcd(a, p/a)==G) 
            count++; 
    return count; 
} 
```
Time Complexity: O( L * log(L) )

**Solution** 2 (Efficient):
We know that G * L = a * b, Since G is gcd(a, b), both a and b will have G as its factor

Let A = a/G

Let B = b/G

From above definitions of A and B, GCD of A and B must be 1.
    
We can write, a = G * A, b = G * B

G * L = G * A * G * B

A * B = L / G

Now, we need to find all possible pairs of (A, B)
such that gcd(A, B) = 1 and A*B = L/G.
    
Let say p1, p2, ..., pk are prime factors of L/G.
    
Then if p1 is present in prime factorization of A 

then p1 can't be present in prime factorization of B because gcd(A, B) = 1
    
Therefore each prime factor p[i] will be present in either A or B

Hence total possible ways to divide all prime factors among A and B is 2^k, where k is number of **distinct** prime factors of L/G.
    
Example let G = 2 , L = 12
    
A * B = L/G 

A * B = 6
    
Primes(6) = {2,3}
```
  A      B     A    B     a    b
(2,3)    ()    6    1     12   2
 (2)    (3)    2    3     4    6
 (3)    (2)    3    2     6    4
 ()    (2,3)   1    6     2    12
```


```cpp
int countPairs(int G, int L) 
{ 
    if (L % G != 0) 
       return 0; 
    int div = L/G; 
    return (1 << total_Distinct_PrimeFactors(div)); 
} 
```
Time Complexity : O(sqrt(L/G)).

### Check if LCM of array elements is divisible by a prime number or not

Given an array and a prime number k, the task is to find if LCM of the array is divisible by k or not.
    
    
**Naive Solution** :
One simple solution is to first find LCM of array elements, then check if LCM is divisible by k or not.

**Better Solution** :    
Here, we can find that LCM of array of number is divisible by a prime number k or not
If any number of the array is divisible by prime number k
then the LCM of the number is also divisible by prime number k.

### Check if elements of array can be made equal by multiplying given prime numbers

Given an array of integers and an array of prime numbers. The task is to find if it is possible to make all the elements of integer array equal
by multiplying one or more elements from prime given array of prime numbers.
        
Input : arr[]   = {50, 200} , prime[] = {2, 3}, Output : Yes

We can multiply 50 with 2 two timesto make both elements of arr[] equal

**Solution** : We find LCM of all array elements, All elements can be made equal only if it is possible to convert all numbers to LCM.
        
```cpp
bool checkArray(int arr[], int prime[], int n, int m) 
{ 
    int lcm = lcmOfArray(arr,n); 
    for (int i=0; i<n; i++) 
    { 
        int val = lcm/arr[i]; 
 
        for (int j=0; j<m && val!=1; j++) 
            while (val % prime[j] == 0) 
                val = val/prime[j]; 

        if (val != 1) 
          return false; 
    } 
  
    return true; 
}  
```
**Apples Again!**

[Problem Link](https://codeforces.com/group/MEqF8b6wBT/contest/277493/problem/M)
[Solution Link](https://codeforces.com/group/MEqF8b6wBT/contest/277493/submission/100137140)

f(a, b, x) :  Count of numbers that are equal or less than x and multiples of a and b

f(a, b, x) = (x/a) + (x/b) - (x/lcm(a, b)) where 

(x/a) define number of multiples of a

(x/b) define number of multiple of b 

(x/lcm(a, b)) define the number of common multiples  of a and b
