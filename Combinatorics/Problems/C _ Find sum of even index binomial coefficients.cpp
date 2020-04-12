/*

Given a positive integer n. The task is to find the sum of even indexed binomial coefficient
nC0 + nC2 + nC4 + nC6 + nC8 + ………..

Input : n = 4
Output : 8
4C0 + 4C2 + 4C4
= 1 + 6 + 1
= 8

Input : n = 6
Output : 32

Method 1: (Brute Force)
The idea is to find all the binomial coefficient and find only the sum of even indexed value

Method 2: (Using Formula)
Sum of even indexed binomial coeffient :
nC0 + nC2 + nC4 + nC6 + nC8 + ……… = 2^(n-1)

Proof :
We know,
(1 + x)^n = nC0 + nC1 x + nC2 x2 + ..... + nCn x^n

Now put x = -x, we get
(1 - x)^n = nC0 - nC1 x + nC2 x2 + ..... + (-1)^n nCn x^n

Now, adding both the above equation, we get,
(1 + x)^n + (1 - x)^n = 2 * [nC0 + nC2 x2 + nC4 x4 + .....]

Put x = 1
(1 + 1)^n + (1 - 1)^n = 2 * [nC0 + nC2 + nC4 + .......]
2^n/2 = nC0 + nC2 + nC4 + .......
2^(n-1) = nC0 + nC2 + nC4 + .......

*/

int evenbinomialCoeffSum(int n) 
{ 
    return (1 << (n - 1)); 
} 
int main() 
{ 
    int n = 4; 
    cout<<evenbinomialCoeffSum(n); 
    return 0; 
} 
