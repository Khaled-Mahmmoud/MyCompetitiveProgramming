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
(1 + x)n = nC0 + nC1 x + nC2 x2 + ......... + nCn-1 xn-1 + nCn-1 xn
Also,
(x + 1)n = nC0 xn + nC1 xn-1 + nC2 xn-2 + ......... + nCn-1 x + nCn

Multiplying above two equations,
(1 + x)2n = [nC0 + nC1 x + nC2 x2 + ......... + nCn-1 xn-1 + nCn-1 xn] X 
            [nC0 xn + nC1 xn-1 + nC2 xn-2 + ......... + nCn-1 x + nCn]

Equating coefficients of xn on both sides, we get
2nCn = nC02 + nC12 + nC22 + nC32 + ......... + nCn-22 + nCn-12 + nCn2

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

