# N-th multiple in sorted list of multiples of two numbers

Given three positive integers a, b and n. Consider a list that has all multiples of ‘a’ and ‘b’ is sorted and duplicates are removed. 
    
The task is to find n-th element of the list.

Input :  a = 3, b = 5, n = 5

Output : 10
    
a = 3 b = 5, Multiple of 3 are 3, 6, 9, 12, 15,... and multiples of 5 are 5, 10, 15, 20,.... 
After deleting duplicate element and sorting: 3, 5, 6, 9, 10, 12, 15, 18, 20,.... 

The 5th element in the sequence is 10.

**Solution** :

f(a, b, x) :  Count of number that are less than x and multiples of a and b

f(a, b, x) = (x/a) + (x/b) - (x/lcm(a, b)) where 

(x/a) define number of multiples of a

(x/b) define number of multiple of b 

(x/lcm(a, b)) define the number of common multiples  of a and b

```cpp
int nthElement(int a, int b, int n) 
{ 
    int lcm = (a * b)/__gcd(a,b); 
    int l = 1, r = min(a, b)*n; 
    while (l <= r) 
    { 
        int mid = (l + r)>>1; 
        int val = mid/a + mid/b - mid/lcm; 
  
        if (val == n) 
            return max((mid/a)*a, (mid/b)*b); 
        if (val < n) 
            l = mid + 1; 
        else
            r = mid - 1; 
    } 
} 
```
