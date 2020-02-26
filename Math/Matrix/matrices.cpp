#define ll long long
#define sz(v) (int)(v.size())

typedef vector<int> row;
typedef vector<row> matrix;

matrix initial(int n, int m, int val = 0)
{
	return matrix(n, row(m, val));
}
/*
Zero Matrix 
matrix with all values are zero
|0 0 0|
|0 0 0|
|0 0 0|
*/
matrix zero(int n,int m)
{
	return initial(n,m);
}
/*
identity matrix
The n X n, identity matrix, denoted I_n 
The entries on the diagonal from the upper left to the bottom right are all 1's, and all other entries are 0

 I2 = |1  0|               |1  0  0|
      |0  1|          I3 = |0  1  0|                    |1  0  0  0|
                           |0  0  1|               I4 = |0  1  0  0|
                                                        |0  0  1  0|
                                                        |0  0  0  1|
							
The product of any square matrix and the appropriate identity matrix is always the original matrix
regardless of the order in which the multiplication was performed! In other words, A.I = I.A = A
*/
matrix identity(int n) 
{
	matrix rt = initial(n, n);
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

matrix add(const matrix& a, const matrix& b) 
{
	matrix rt = initial(sz(a), sz(a[0]));
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
    
*/
matrix multiply(const matrix& a, const matrix& b) 
{
	matrix rt = initial(sz(a), sz(b[0]));
        for(i=0;i<sz(a);i++)
          for(j=0;j<sz(b[0]);j++)
             for(k=0;k<sz(a[0]);k++)
                rt[i][j]+=a[i][k]*b[k][j];
	return rt;
}
/*
Matrix Trace
sum of diagonal values
10  1   2
-5  20  7
0   0   30
Trace = 10 + 20 +30 = 60
*/
int matrixTrace(int a,int b)
{
	int ret = 0;
	for(int i=0;i<sz(a);i++)ret += a[i][i];
	return ret;
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
		k >>= 1;
		a = multiply(a, a);
	}
	return rt;
}
