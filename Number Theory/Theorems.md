# Theorems

### Fermat's Little Theorem:

If n is a prime number, then for every a, 1 < a < n-1,

`a^(n-1) ≡ 1 (mod n)` 
 

Example: Since 5 is prime, 2^4 ≡ 1 (mod 5), 3^4 ≡ 1 (mod 5) and 4^4 ≡ 1 (mod 5) 

Since 7 is prime, 2^6 ≡ 1 (mod 7), 3^6 ≡ 1 (mod 7), 4^6 ≡ 1 (mod 7), 5^6 ≡ 1 (mod 7) and 6^6 ≡ 1 (mod 7) 
         
         
## Fermat’s Last Theorem
 
According to Fermat’s Last Theorem, no three positive integers a, b, c satisfy the equation.
 
`a^n + b^n = c^n` for any integer value of n greater than 2.
 
For n = 1 and n = 2, the equation have infinitely many solutions.

Some solutions for n = 1 
 ```
 2 + 3 = 5
 7 + 13 = 20
 5 + 6 = 11
 10 + 9 = 19
```
Some solutions for n = 2 
```
5^2 + 12^2 = 13^2     
3^2 + 4^2 = 5^2    
8^2 + 15^2 = 17^2    
9^2 + 40^2 = 41^2 
```

### Lemoine’s Conjecture Theorem

Any odd integer greater than 5 can be expressed as a sum of an odd prime (all primes other than 2 are odd)
 
and an even semiprime. A semiprime number is a product of two prime numbers

7 = 3 + (2 × 2), where 3 is a prime number and 4 (= 2 × 2) is a semiprime number

11 = 5 + (2 × 3) where 5 is a prime number and 6(= 2 × 3) is a semiprime number

9 = 3 + (2 × 3) or 9 = 5 + (2 × 2)
 
47 = 13 + 2 × 17 = 37 + 2 × 5 = 41 + 2 × 3 = 43 + 2 × 2

```cpp
void lemoine(int n) 
{ 
    map<int, int> pr; 
    map<int, int>::iterator it; 
    it = pr.begin(); 
      
    // Finding various values of p for each q 
    // to satisfy n = p + (2 * q) 
    for (int q = 1; q <= n / 2; q++)  
    {  
        int p = n - 2 * q; 
        if (isPrime(p) && isPrime(q)) 
            pr.insert(it, pair<int, int>(p, q)); 
    } 
    for (it = pr.begin(); it != pr.end(); ++it) 
        cout << n << " = " << it->first << " + (2 * " << it->second << ")\n"; 
} 
int main() 
{ 
    int n = 39; 
    lemoine(n);
    return 0; 
}
/*output :
39 = 5 + (2 * 17)
39 = 13 + (2 * 13)
39 = 17 + (2 * 11)
39 = 29 + (2 * 5)*/
```
