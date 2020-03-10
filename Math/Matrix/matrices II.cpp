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

