/*
A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:

              1    2    9    10    25
              4    3    8    11    24
              5    6    7    12    23
              16   15   14   13    22
              17   18   19   20    21
              
Your task is to find out the number in row y and column x

CSES problem link : https://cses.fi/problemset/task/1071/

1 <= t <= 10^5
1 <= x,y <= 10^9

Input:
3
2 3
1 1
4 2

Output:
8
1
15

*/

    int t;cin>>t;while(t--)
    {
        long long a,b,m,x;
        cin>>a>>b;
        m=max(a,b);
        if(m & 2) x = -1;
        else x = 1;
        cout<<(a-b)*x+m*m-m+1<<'\n';
    }
    return 0;
