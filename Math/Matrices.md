```cpp
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
// matrix trace : sum of all diagonal 
int matrix_trace(const matrix &a)
{
    int ret = 0;
    for(int i=0;i<sz(a);i++)
        ret += a[i][i];
    return ret;
}

matrix add(const matrix& a, const matrix& b) 
{
	matrix rt = zero(sz(a), sz(a[0]));
	for(int i = 0; i < sz(a); i++)
        for(int j = 0; j < sz(a[0]); j++)
		rt[i][j] = a[i][j] + b[i][j];
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
        for(int i=0;i<sz(a);i++)
          for(int j=0;j<sz(b[0]);j++)
             for(int k=0;k<sz(a[0]);k++)
                rt[i][j]+=a[i][k]*b[k][j];
	return rt;
}
matrix power(const matrix& a, ll k)
{
	if (!k)return identity(sz(a));
	if (k & 1ll)return multiply(a, power(a, k - 1));
	return power(multiply(a, a), k >> 1ll);
}
matrix power_itr(matrix a, ll k)
{
	matrix rt = identity(sz(a));
	while (k)
	{
		if (k & 1ll)rt = multiply(rt, a);
		a = multiply(a, a); k >>= 1ll;
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
v = vector<string>(sz(ch[0]));
for (int i = 0; i < sz(ch); i++)
for (int j = 0; j < sz(ch[0]); j++)
     v[j].push_back(ch[i][j]);

/*
Matrix Rotate
            51
1234   ---> 62
5678   ---> 73
            84
*/
v = vector<string>(sz(ch[0]));
for (int i = sz(ch)-1; i >=0 ; i--)
for (int j = 0; j < sz(ch[0]); j++)
     v[j].push_back(ch[i][j]);
```
