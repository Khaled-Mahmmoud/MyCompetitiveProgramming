/*
Find minimum number to be divided to make a number a perfect square
Given a positive integer n. Find the minimum number which divide n to make it a perfect square.

Input : n = 50
Output : 2
By Dividing n by 2, we get which is a perfect square.

Input : n = 6
Output : 6
By Dividing n by 6, we get which is a perfect square.

Input : n = 36
Output : 1

A number is perfect square if all prime factors appear even number of times
The idea is to find the prime factor of n and find each prime factor power
Now, find and multiply all the prime factor whose power is odd
The resultant of the multiplication is the answer

*/

int findMinNumber(int n) 
{ 
    int count = 0, ans = 1; 
    while (n%2 == 0) 
    { 
        count++; 
        n /= 2; 
    } 
    if (count%2) 
        ans *= 2; 
    for (int i = 3; i <= sqrt(n); i += 2) 
    { 
        count = 0; 
        while (n%i == 0) 
        { 
            count++; 
            n /= i; 
        } 
        if (count%2) 
            ans *= i; 
    } 
    if (n > 1) 
        ans *= n; 
  
    return ans; 
} 
