# Finding sum of digits of a number until sum becomes single digit

Given a number n, we need to find the sum of its digits such that:

Input : 1234 , Output : 1
    
Explanation : The sum of 1+2+3+4 = 10, digSum(x) == 10, Hence ans will be 1+0 = 1

A brute force approach is to sum all the digits until sum < 10
```cpp
int digSum(int n) 
{ 
    int sum = 0; 
    while(n > 0 || sum > 9) 
    { 
        if(n == 0) 
        { 
            n = sum; 
            sum = 0; 
        } 
        sum += n % 10; 
        n /= 10; 
    } 
    return sum; 
} 
int main() 
{ 
    int n = 1234; 
    cout << digSum(n); 
    return 0; 
} 
```
Time Complexity : log10(n)

There exists a simple and elegant O(1) solution for this too. The ans is given by simply :-


How does the above logic works?
A number can be of the form 9x or 9x + k. 
For the first case, answer is always 9. For the second case, and is always k.


```cpp
int digSum(int n) 
{ 
    if (n == 0)  
       return 0; 
    return (n % 9 == 0) ? 9 : (n % 9); 
} 
int main() 
{ 
    int n = 9999; 
    cout<<digSum(n); 
    return 0; 
} 
```
