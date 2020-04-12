/*

Sum of Binomial coefficients
Given a positive integer n, the task is to find the sum of binomial coefficient 
nC0 + nC1 + nC2 + ……. + nCn-1 + nCn

Method 1 (Brute Force):
The idea is to evaluate each binomial coefficient term i.e nCr, where 0 <= r <= n and calculate the sum of all the terms

Method 2 (Using Formula):
nC0 + nC1 + nC2 + ……. + nCn-1 + nCn = 2^n

*/

int binomialCoeffSum(int n) 
{ 
    return (1 << n); 
} 
int main() 
{ 
    int n = 4; 
    cout<<binomialCoeffSum(n); 
    return 0; 
} 
