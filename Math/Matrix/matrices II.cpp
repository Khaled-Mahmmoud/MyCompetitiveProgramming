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


/*

  Matrix Approach : Observe
  0 1     0 1     1 1
  0 0  x  1 1  =  0 0
  
  1 1     0 1     1 2
  0 0  x  1 1  =  0 0
  
   1 2     0 1     2 3
   0 0  x  1 1  =  0 0
  
   2 3     0 1     3 5
   0 0  x  1 1  =  0 0
   
   Matrix Approach : Generally
   a b       0 1          b a+b
   c d   x   1 1    =     d c+d
  Initial   Transition    Updated
  Matrix    Matrix        Matrix
  
then give matrix with first row(a,b) we could move to (b,a+b) 
which means we could  move one step in sequence 

then one more multiplication another one step

then multiplying n times move use n steps
we could do all mulitplications once in O(logn) only

  0 1     0 1 ^ 1    1 1
  0 0  x  1 1     =  0 0
  
  0 1     0 1 ^ 2    1 2
  0 0  x  1 1     =  0 0
  
  0 1     0 1 ^ 3    2 3
  0 0  x  1 1     =  0 0
  
  0 1     0 1 ^ 4    3 5
  0 0  x  1 1     =  0 0

*/

ll fibonacciMatrix(ll n) 
{
	if (n <= 1)return n;
	/*
	transition matrix
	0 1
	1 1
	Initial matrix
	0 1
	0 0
	*/
	matrix transition = zero(2, 2);
	transition[0][1] = transition[1][0] = transition[1][1] = 1;
        transition = power(transition, n - 1);
	matrix Initial = zero(2, 2);
	Initial[0][1] = 1;
	Initial = multiply(Initial, transition);
	return Initial[0][1];
}
// So instead : initial x transition^(n-1) , we use transition^n
ll fibonacciMatrix(ll n) 
{
	if (n <= 1)return n;
	/*
	transition matrix
	0 1
	1 1
	*/
	matrix transition = zero(2, 2);
	transition[0][1] = transition[1][0] = transition[1][1] = 1;
        transition = power(transition, n );
	return transition[0][1];
}
