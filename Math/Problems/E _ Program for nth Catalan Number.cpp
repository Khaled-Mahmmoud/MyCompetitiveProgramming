/*

Program for nth Catalan Number
Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following
The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
 Catalan Number = (2n)! / ((n + 1)! * n!)
 Catalan numbers satisfy the following recursive formula
C0 = 1 , C(n+1) = sum(i=0,n) Ci Cn-i , n >= 0

*/

int catalan[10000];
int catalan(int n) 
{ 
    if (n <= 1) return 1; 
    if(catalan[i])return catalan[i];
    int res = 0; 
    for (int i=0; i<n; i++) 
        res += catalan(i)*catalan(n-i-1); 
  
    return catalan[n] = res; 
} 
// Complexity : O(n^2)

/*

Using Binomial Coefficient
We can also use the below formula to find nth catalan number in O(n) time
catalan(n) = nCr(2n,n) / (n+1)
We have discussed a O(n) approach to find binomial coefficient nCr

*/

int binomialCoeff(int n,int r)
{
    if (n < r)
        return 0;

    if (r == 0)
        return 1;

    return n * binomialCoeff(n - 1, r - 1) / r;
}
int catalan(int n)
{
    int c = binomialCoeff(2*n, n);
    return c/(n+1);
}
int main()
{
    for(int i=0;i<10;i++)
        cout<<catalan(i)<<' ';
	return 0;
}
