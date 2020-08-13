# Number Spiral

A number spiral is an infinite grid whose upper-left square has number 1. Here are the first eight layers of the spiral:


              1    2    `9`    10    25   26   49   50
              
              4    3    8    11    24   27   48   51
              5    6    7    12    23   28   47   52
              16   15   14   13    22   29   46   53
              17   18   19   20    21   30   45   54
              36   35   34   33    32   31   44   55
              37   38   39   40    41   42   43   56
              64   63   62   61    60   59   58   57

Your task is to find out the number in row y and column x

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

```cpp
int t;cin>>t;while(t--)
{
   long long a,b,m,x;
   cin>>a>>b;
   m=max(a,b);
   if(m & 1) x = -1;
   else x = 1;
   cout<<(a-b)*x+m*m-m+1<<'\n';
}
```
