/*
Given two matrices find its multiplication 
codeforces problem link : https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/K
*/

int r1,c1,c2,r2,a[101][101],b[101][101],i,j,c[101][101],k;
int main()
{
    cin>>r1>>c1;
    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
           cin>>a[i][j];
           
    cin>>r2>>c2;
    for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
           cin>>b[i][j];
           
     for(i=0;i<r1;i++)
         for(j=0;j<c2;j++)
             for(k=0;k<c1;k++)
                c[i][j]+=a[i][k]*b[k][j];
               
     for(i=0;i<r1;i++){
        for(j=0;j<c2;j++)
           cout<<c[i][j]<<" ";
           cout<<'\n';}
 }
