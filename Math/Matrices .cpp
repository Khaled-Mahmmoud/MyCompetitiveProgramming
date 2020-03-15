/*
A matrix is a rectangular arrangement of numbers into rows and columns
For example, matrix A has two rows and three columns

              3 Columns
     A  =   | -2  5  6 | 2 Rows
            |  5  2  7 |
           
           
Matrix dimensions
The dimensions of a matrix tells its size : the number of rows and columns of the matrix, in that order
Since matrix A has two rows and three columns , we write its dimensions as 2 x 3 , pronounced "two by three"
When working with matrix dimensions, remember row x columns  // A ( 2 x 3 )

Matrix elements
A matrix element is simply a matrix entry
Each element in a matrix is identified by naming the row and column in which it appears

the element g(2,1) is the entry in the second row and the first column

        |4  14 -7|
    G = |18  5 13|
        |-20 4 22|
  in this case , g(2,1) = 18
  
in general , the element in row i and column j of matrix A is denoted as a(i,j)

Matrices can be used to solve systems of equations 
But first, we must learn how to represent systems with matrices
Representing a linear system with matrices
A system of equations can be represented by an augmented matrix

system of equations :  2x + 5y = 10
system of equations :  3x + 4y = 24

                     x   y  constants
Augmented matrix   | 2   5   10 | --> Eq : 1
                   | 3   4   24 | --> Eq : 2
                   
In an augmented matrix, each row represents one equation in the system and each column represents a variable 
or the constant terms In this way, we can see that augmented matrices are a shorthand way of writing systems 
of equations , The organization of the numbers into the matrix makes it unnecessary to write various symbols 
like x, y, and = equals yet all of the information is still there!



Matrix row operations
The following table summarizes the three elementary matrix row operations

Matrix row operation	          Example
Switch any two rows        |2 5 3|  --> |3 4 6|
                           |3 4 6|  --> |2 5 3|
                       (Interchange row 1 and row 2)
                       
Multiply a row by         |2 5 3|  --> |3.2  3.5  3.3|
a nonzero constant        |3 4 6|  --> | 3    4    6 |
                       (Row 1 becomes 3 times itself)
        
Add one row to another    |2 5 3|  --> | 2    5    3 |
                          |3 4 6|  --> |3+2  4+5  6+3|
                     (Row 2 becomes the sum of rows 2 and 1)
  
Matrix row operations can be used to solve systems of equations 
but before we look at why, let's practice these skills

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
      |0  1|          I3 = |0  1  0|                    |1  0  0  0|
                           |0  0  1|               I4 = |0  1  0  0|
                                                        |0  0  1  0|
                                                        |0  0  0  1|
							
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
Matrix Addition 
1) Same dimensions for two matrices
2) Sum is for corresponing cells
 1  2  3      1  5  3     2  7  6
 4  0  0  +   0  7  9  =  4  7  9
*/
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
// a^1 + a^2 + a^3 + ..... + a^k
matrix sumPower(const matrix& a, ll k)
{	
	if (k == 0)return initial(sz(a), sz(a));	
	if (k & 1)return multiply(a, addIdentity(sumPower(a, k - 1)));	
	return multiply(sumPower(a, k >> 1), addIdentity(power(a, k >> 1)));	
}	
/*
Matrix Trace
sum of diagonal values
 10  1   2
-5  20  7
 0   0   30
Trace = 10 + 20 +30 = 60
*/
int matrixTrace(const matrix& a)
{
	int ret = 0;
	for(int i=0;i<sz(a);i++)ret += a[i][i];
	return ret;
}
/*
Matrix ClockWise Rotation
 1  7  4           0  1
 0  9  4    -->    9  7
                   4  4
*/  
matrix rotate(matrix v)
{
	  matrix r = zero(sz(v[0]),sz(v));
    for(int i=0;i<sz(v);i++)
        for(int j=0;i<sz(v[0]);j++)
            r[j][sz(v)-i-1] = v[i][j];
    return r;
}
/*
Matrix Reflection
 1  7  4           4  7  1
 0  9  4    -->    4  9  0
 */
matrix Reflect(matrix v)
{
	  matrix r = zero(sz(v),sz(v[0]));
    for(int i=0;i<sz(v);i++)
        for(int j=0;i<sz(v[0]);j++)
            r[i][sz(v[0])-j-1] = v[i][j];
    return r;
}
