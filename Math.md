```cpp
// 10^8 = (10^2)^4 = (10^4)^2
// 10^9 = 10 * 10^8
int power(int x, unsigned int y) 
{ 
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return power(x, y / 2) * power(x, y / 2); 
    else
        return x * power(x, y / 2) * power(x, y / 2); 
} 
// O(4^log y)
    
// Above function can be optimized to O(log y) by calculating power(x, y/2) only once and storing it
int power(int x, unsigned int y) 
{ 
    int temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    if (y & 1) 
        return x*temp*temp;
    else
        return temp*temp;
} 
// O(log y)
// Better Solution
template<class T>
T power(T a, T b, T mod)
{
    T ans = 1;
    a %= mod;

    while (b) 
    {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}
// O(log(y))
/*
calc a^1 + a^2 + a^3 + ..... + a^k
(a^1+a^2+a^3+a^4+a^5+a^6)       = (a^1+a^2+a^3)+(a^1*a^3+a^2*a^3+a^3*a^3)
(a^1+a^2+a^3)+a^3*(a^1+a^2+a^3) = (a^1+a^2+a^3)*(1+a^3)
(a^1+a^2+a^3)+a^3*(a^1+a^2+a^3) = (a^1+a^2+a^3)*(1+ a^1+a^2+a^3 - (a^1+a^2))
= (a^1+a^2+a^3)*(1+a^3)

what about odd n (a^1+a^2+a^3+a^4+a^5+a^6+a^7)  = a + a*(a^1+a^2+a^3+a^4+a^5+a^6)
= a(1+(a^1+a^2+a^3+a^4+a^5+a^6))
*/
ll sumPower(ll a, int k)
{
    if (k == 0)
        return 0;
    if (k % 2 == 1)
        return a * (1 + sumPower(a, k - 1));
    ll half = sumPower(a, k / 2);
    return half * (1 + half - sumPower(a, k / 2 - 1));
}
// Time Complexity : O(log(k)) 
/*
Powers tower % M
Let’s compute: 2^3^4^5^6^7^8 % 56.
We can solve it using Euler theorem. let’s simplify it, compute 2^X % 56. where x is very large, e.g. x = 3^4^5^6^7^8.
Imagine we compute 2^i%M for i [0 - OO]. We know we have M mod values: [0 - M-1].
Pigeonhole: values repeat in maximum M + 1 iterations. 
Then computing X should have same value as one of the first powers in range [0-M-1]. But which 2^i%M correspond to 2^x%M ?
Let’s simulate it.
   i         0    1    2    3    4    5    6    7
2^i % 56     1    2    4    8    16   32   8    16
2^6 is same as 2^3. Then 2^7 must = 2^4...etc. {8,16,32} is cycle and {1,2,4} is precycle.
Let length of the cycle be L, and length of precycle be P.
Given some X, we can compute its i position. i = (X % L - P % L + L) % L + P -->> (X-P)%L + P
Then? Solve subproblem X % L in same manner. Then compute 2^i % M.
*/
// Generate Divisors
template<class T>
vector<T> getDivisors(T n) 
{
    vector<T> divs;
    for (T i = 1; i * i <= n; ++i) 
    {
        if (n % i) 
           continue;
        divs.push_back(i);
        if (i * i == n) 
           continue;
        divs.push_back(n / i);
    }
    return divs;
}
// O(sqrt(n))
// Count all the divisors of the integers from 1 to "n"
vector<int> divs[N];
void generateDivisors(int n) 
{
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            divs[j]++;
}
// O(n.log(n))
// Count all perfect divisors of a number
int perfectDiv[MAX]; 
void precomputeCounts() 
{ 
    for (int i=1; i*i < MAX; ++i) 
        for (int j=i*i; j < MAX; j += i*i) 
              perfectDiv[j]++; 
} 
// only perfect square numbers have odd number of divisors
// Check if count of divisors is even or odd
void countDivisors(int n) 
{ 
    int root_n = sqrt(n); 
    if (root_n * root_n == n) 
        printf("Odd\n"); 
    else
        printf("Even\n"); 
} 
/*
Check whether a number has exactly three distinct factors or not?
According to property of perfect square, “Every perfect square(x^2) always have only odd numbers of factors“
If the square root of given number(say x^2) is prime then it must have exactly three distinct factors i.e,
1) A number 1 of course.
2) Square root of a number i.e., x(prime number).
3) Number itself i.e., x^2.

 Counting tne number of the divisors of number
 2^4 has 5 divisors 2^0, 2^1...2^4, p^n has n+1 divisors for any p prime number
 what about not prime number n = p1^a * p1^b  , it's (a+1) * (b+1)
 
 what about Factorizing n^power
 Simply if n     =  p1^a  *	p2^b   * p3^c
 Then n^z        = p1^az  *	p2^bz  * p3^cz
 Divisors of n   = (a+1)  * (b+1)  * (c+1)
 Divisors of n^z = (az+1) * (bz+1) * (cz+1)
 */
 #define sz(v) (int)(v.size())
typedef vector<int> row;
typedef vector<row> matrix;
/*
Zero Matrix 
matrix with all values are zero
|0 0 0|
|0 0 0|
|0 0 0|
*/
matrix zero(int n, int m, int val = 0)
{
	return matrix(n, row(m, val));
}
/*
identity matrix
The n X n, identity matrix, denoted I_n 
The entries on the diagonal from the upper left to the bottom right are all 1's, and all other entries are 0
 I2 = |1  0|               |1  0  0|
      |0  1|          I3 = |0  1  0|                    
                           |0  0  1|               							
The product of any square matrix and the appropriate identity matrix is always the original matrix
regardless of the order in which the multiplication was performed! In other words, A.I = I.A = A
*/
matrix identity(int n) 
{
	matrix rt = zero(n, n);
	for (int i = 0; i < n; i++)
		rt[i][i] = 1;
	return rt;
}

matrix addIdentity(const matrix& a) 
{
	matrix rt = a;
	for (int i = 0; i < sz(a); i++)
		rt[i][i] += 1;
	return rt;
}
/*
           Matrix multiplication dimensions
The dimensions of a matrix give the number of rows and columns of the matrix in that order
Since matrix A has 2 rows and 3 columns, it is called 2 * 3 matrix
When is matrix multiplication defined?
In order for matrix multiplication to be defined, the number of columns in the first matrix must 
be equal to the number of rows in the second matrix
          (m X n).(n X k)
    product matrix is dimension of m X k
    
1  2       1  2  3  4       11  14  17  20
3  4   *                =   23  30  37  44
5  6       5  6  7  8       35  46  57  68
    
*/
matrix multiply(const matrix& a, const matrix& b) 
{
	matrix rt = zero(sz(a), sz(b[0]));
        for(i=0;i<sz(a);i++)
          for(j=0;j<sz(b[0]);j++)
             for(k=0;k<sz(a[0]);k++)
                rt[i][j]+=a[i][k]*b[k][j];
	return rt;
}
matrix power(const matrix& a, ll k) 
{	
	if (k == 0)return identity(sz(a));	
	if (k & 1)return multiply(a, power(a, k - 1));	
	return power(multiply(a, a), k >> 1);	
}	

matrix power_itr(matrix a, ll k) 
{	
	matrix rt = identity(sz(a));	
	while (k)
	{	
		if (k & 1)rt = multiply(rt, a);	
		a = multiply(a, a); k >>= 1;	
	}	
	return rt;	
}
/*
Calc a^1 + a^2 + a^3 + ..... + a^k
(a^1+a^2+a^3+a^4+a^5+a^6)  =  (a^1+a^2+a^3)+a^3*(a^1+a^2+a^3) = (a^1+a^2+a^3)*(1+a^3)
what about odd n (a^1+a^2+a^3+a^4+a^5+a^6+a^7) = a(1+(a^1+a^2+a^3+a^4+a^5+a^6))
*/
matrix sumPower(const matrix& a, ll k)
{	
	if (k == 0)return zero(sz(a), sz(a));	
	if (k & 1)return multiply(a, addIdentity(sumPower(a, k - 1)));	
	return multiply(sumPower(a, k >> 1), addIdentity(power(a, k >> 1)));	
}	
/*
Matrix Reflect
            15
1234   ---> 26
5678   ---> 37
            48
*/
v = vector<string>(m);
for (int i = 0; i < n; i++)
for (int j = 0; j < m; j++)
{
     char ch;
     cin >> ch;
     v[j].push_back(ch);
}
```
