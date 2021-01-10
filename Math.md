- Power
- Matrices
- Fibonacci
- Generate Divisors
- Logarithms
- Series
```cpp
// <Power>
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
Calc a^1 + a^2 + a^3 + ..... + a^k
(a^1+a^2+a^3+a^4+a^5+a^6)  =  (a^1+a^2+a^3)+a^3*(a^1+a^2+a^3) = (a^1+a^2+a^3)*(1+a^3)
what about odd n (a^1+a^2+a^3+a^4+a^5+a^6+a^7) = a(1+(a^1+a^2+a^3+a^4+a^5+a^6))
*/
ll sumPower(ll a, int k)
{
    if (!k) return 0;
    if (k&1) return a * (1 + sumPower(a, k - 1));
    return sumPower(a, k>>1) * (1 + power(a,k>>1));
}
// Time Complexity : O(log(k)) 

//<Matrices>
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
	if (!k)return identity(sz(a));	
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
// Time Complexity : O(log(k)) 
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
// <Fibonacci>
// Fn = Fn-1 + Fn-2, F0 = 0, F1 = 1
int fib(int n) 
{ 
  int a = 0, b = 1, c, i; 
  if( n == 0) 
    return a; 
  for (i = 2; i <= n; i++) 
  { 
     c = a + b; 
     a = b; 
     b = c; 
  } 
  return b; 
} 
/*
  Matrix Approach : Observe
  
  0 1     0 1 ^ 1    1 1
  0 0  x  1 1     =  0 0
  
  0 1     0 1 ^ 2    1 2
  0 0  x  1 1     =  0 0
  
  0 1     0 1 ^ 3    2 3
  0 0  x  1 1     =  0 0
  
  0 1     0 1 ^ 4    3 5
  0 0  x  1 1     =  0 0

   Matrix  Approach  :   Generally
   a b       0 1          b a+b
   c d   x   1 1    =     d c+d
  Initial   Transition    Updated
  Matrix    Matrix        Matrix
*/
ll fibonacciMatrix(ll n)
{
    if(n <= 1)
        return n;
    matrix transition = zero(2, 2);
    transition[0][1] = transition[1][0] = transition[1][1] = 1;
    transition = power(transition, n - 1);
    matrix Initial = zero(2, 2);
    Initial[0][1] = 1;
    Initial = multiply(Initial, transition);
    return Initial[0][1];
}
// O(logn) 
// first row in initial matrix same as first row in transition matrix
// So instead : initial x transition^(n-1) , we use transition^n
ll fibonacciMatrix(ll n)
{
    if(n <= 1)
        return n;
    matrix transition = zero(2, 2);
    transition[0][1] = transition[1][0] = transition[1][1] = 1;
    transition = power(transition, n);
    return transition[0][1];
}
/*
In Fibonacci , F(n) depends on 2 terms only ; F(n-1) + F(n-2) 
So we have 2 base cases Then define 2x2 matrix, Fill first row with bases and Others zeros.
Let F[0][0] = 0 , F[0][1] = 1
0 1
0 0
Imaginary Sequence
F[0] = 1 , F[1] = 3 , F[2] = 4
F[n] = 2 * F[n-3] + F[n-2] + 4 * F[n-1]
we depend on 3 terms , construct 3 x 3 and fill with base cases
1 3 4
0 0 0
0 0 0
Now we need to prepare column values We know that initial matrix first row 1 3 4 (base case) and first row in updated matrix
after 1 step 3 4 x that is first 2 columns just shift 2 values , 3rd column only do calculation 2 * F[n-3] + F[n-2] - 4 * F[n-1]
0  0  2
1  0  1
0  1 -4
*/
int fmat(int n)
{
    if(n==0) return 1;
    if(n==1) return 3;
    if(n==2) return 4;
    matrix initial = zero(3,3);
    initial[0][0] = 1 , initial[0][1] = 3 , initial[0][2] = 4;
    matrix transition = zero(3,3);
    transition[1][0] = 1;
    transition[2][1] = 1;
    transition[0][2] = 2 ; transition[1][2] = 1 ; transition[2][2] = -4 ;
    transition = power(transition , n-2);
    initial = multiply(initial,transition);
    return initial[0][2];
} 
/*
The Leonardo numbers are a sequence of numbers given by the recurrence:
                   1              if n = 0
  L(n)   =         1              if n = 1
              L(n-1)+L(n-2)+1     if n > 1
The Leonardo numbers are related to the Fibonacci numbers by below relation L(n) = 2 * F(n+1) - 1 , n >= 0
*/
//<Generate Divisors>
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
/*
<Logarithms>
logk(x) means the number of times we have to divide x by k before we reach the number 1
(x = k^a) ==> (a = logk(x))

log(a * b) = log(a) + log(b)
log(x^n) = log(x * x * x...n times) = log(x) + log(x) + ... + n times =  n·log(x)
log(a/b) = log(a) − log(b)
logu(x) = log(u) / log(x)

The natural logarithm ln(x) = loge(x) where e ≈ 2,71828
k = [10, e, 2] => (common, natural, binary) log
- Math notations: lg(x), ln(x), lb(x)
- In c++: log10(x), log(x), log2(x)
logb b = 1, logb 1 = 0, logb 0 = -oo, log1 x = undefined, b^logb(x) = x 
number of digits of integer x in base b is floor(logb(x)) + 1 
*/
#define numOfDigit(x) 1 + floor(log10(x))
#define numOfBits(x)  1 + floor(log2(x)))
// Number of Digits in !n = floor(log10(1 * 2 * 3 * 4 * 5 *  .... * n)) + 1 
//                        = floor(log10(1) + log10(2) + ... + log10(n)) + 1
int main()
{
    int n;
    cin>>n;
    double ans = 0;
    for(int i=1;i<=n;i++)
        ans += log10(i);
    cout<<fixed<<setprecision(0)<<floor(ans) + 1;
    return 0;
}
/*
Harmonic Progression: 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + ..... + 1/(n-1) + 1/n = log(n)
1/2 + 1/3 + 1/5 + 1/7 + ..... + 1/p = log(log n) where p is largest prime less then n

Θ(log(n!)) = Θ(n·log(n))
log(1) + log(2) + ... + log(n) <= log(n) + log(n) + ... + log(n) 
*/

/*
<Series>
sum(x=1,n) x   = 1 + 2 + 3 + ... + n = n*(n+1)/2
sum(x=1,n) x^2 = 1 + 4 + 9 + ... + n*n = n*(n+1)*(2n+1)/6

Arithmetic Progression (AP) :: is a sequence of numbers where the difference between any two consecutive numbers is constant.
n ==>> number of elements , a ==>> first element , b ==>> last element , d ==>> difference between any two consecutive numbers
a , a+d , a+2d , a+3d , ..... , b : 2 5 8
i'th term = a + (i-1) * d
          n*(a+b)     n*(a+[a+(n-1)*d])
The sum =--------- = ----------------
             2             2
2   5   8  
8   5   2
==========
10  10  10  sum = (10 + 10 + 10) /2

Geometric Progression (GP) :: is a sequence of numbers where the ratio between any two consecutive numbers is constant.
n ==>> number of elements , a ==>> first element , b ==>> last element , r ==>> ratio between any two consecutive numbers
a , a*r , a*r*r , a*r*r*r , .... , b: 3 , 6 , 12 
i'th term = a * r^(i-1)
           (br-a)   a*(r^n-1)
The sum =  ------ = ---------
           (r-1)     (r-1)
S = a + a*r + a*r*r +··· + b
S*r = a*r + a*r*r + a*r*r*r +··· + b*r
S*r − S = b*r − a
S*(r-1) = b*r - a

2^(0) + 2^(1) + 2^(2) +2^(3) + ... + 2^(n-1) = 2^n - 1
Infinite Geometric Series:  a + ar + ar^2 + ar^3 + ..... = a/(1-r). for abs(r) < 1
