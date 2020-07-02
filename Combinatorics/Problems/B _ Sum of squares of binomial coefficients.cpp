/*

Sum of squares of binomial coefficients
Given a positive integer n. The task is to find the sum of square of Binomial Coefficient 
nC0^2 + nC1^2 + nC2^2 + nC3^2 + ……… + nCn-2^2 + nCn-1^2 + nCn^2

Input : n = 4
Output : 70

Input : n = 5
Output : 252

Method 1: (Brute Force)
The idea is to generate all the terms of binomial coefficient and find the sum of square of each binomial coefficient

Method 2: (Using Formula)
nC0^2 + nC1^2 + nC2^2 + .... + nCn-1^2 + nCn^2
= 2nCn
= (2n)! / (n!)^2

Proof
We know,
(1 + x)n = nC0 + nC1 x + nC2 x^2 + ......... + nCn-1 x^n-1 + nCn x^n
Also,
(x + 1)n = nC0 x^n + nC1 x^n-1 + nC2 x^n-2 + ......... + nCn-1 x + nCn

Multiplying above two equations,
(1 + x)^2n = [nC0 + nC1 x + nC2 x^2 + ......... + nCn-1 x^n-1 + nCn x^n] X 
            [nC0 x^n + nC1 x^n-1 + nC2 x^n-2 + ......... + nCn-1 x + nCn]

Equating coefficients of x^n on both sides, we get
2nCn = nC0^2 + nC1^2 + nC2^2 + nC3^2 + ......... + nCn-2^2 + nCn-1^2 + nCn^2

Hence, sum of the squares of coefficients = 2nCn = (2n)!/(n!)2

*/
int nCr(int n, int r) 
{
    if (n < r)
        return 0;

    if (r == 0)
        return 1;

    return n * nCr(n - 1, r - 1) / r;
}
int main()
{
    int n;cin>>n;
    cout<<nCr(2n,n)<<endl;
}

