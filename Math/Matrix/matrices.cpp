#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(v) (int)(v.size())

typedef vector<int> row;
typedef vector<row> matrix;

matrix initial(int n, int m, int val = 0)
{
	return matrix(n, row(m, val));
}
matrix zero(int n,int m)
{
	return initial(n,m);
}
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

matrix multiply(const matrix& a, const matrix& b) 
{
	matrix rt = initial(sz(a), sz(b[0]));
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
		k >>= 1;
		a = multiply(a, a);
	}
	return rt;
}
