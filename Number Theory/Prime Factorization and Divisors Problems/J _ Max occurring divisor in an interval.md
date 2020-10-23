# Max occurring divisor in an interval

Given an interval [x, y] Find the divisor that occurs maximum number of times except ‘1’
in the divisors of numbers in the range [x, y], both inclusive

Input : [2, 5]
Output : 2
Explanation : Divisors of 2, 3, 4, 5 except 1 are:
              2 -> 2
              3 -> 3
              4 -> 2, 4
              5 -> 5
              Among all the divisors 2 occurs 
              maximum time, i.e two times.

Input : [3, 3]
Output : 3

An **efficient approach** will be to observe carefully that every even number will have 2 as a divisor.
And in the interval [x, y] there is atleast floor((y-x)/2) + 1 numbers of 2. That is, half of the total numbers in 
the interval will have divisor as 2. Clearly this is the maximum number of occurrences of a divisor in the interval

If (x == y), then answer will be x or y

```cpp
int findDivisor(int x, int y) 
{ 
    if (x == y) 
        return y; 
    return 2; 
} 
int main() 
{ 
    int x = 3, y = 16; 
    cout << findDivisor(x, y); 
    return 0; 
} 
````
