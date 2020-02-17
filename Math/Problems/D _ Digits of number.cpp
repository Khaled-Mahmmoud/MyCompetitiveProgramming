/*
Given number n , print sum of it's digits
*/
int digit(int n) 
{ 
    int sum = 0;
    while (n) 
    { 
        sum += n%10;
        n = n/10; 
    } 
    return sum; 
} 
// Complexity : O(N) , Where N is number of digits of n
