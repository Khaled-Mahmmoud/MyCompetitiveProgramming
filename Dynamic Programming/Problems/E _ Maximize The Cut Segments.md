 # Maximize The Cut Segments
 
Given an integer N denoting the Length of a line segment. you need to cut the line segment in such a way that the cut length of a line 
segment each time is integer either x , y or z. and after performing all cutting operation the total number of cutted segments must be 
maximum.
    
1<=n,x,y,z<=4000
    
```cpp
int dp[4009];
int cut(int n,int x,int y,int z)
{
    if(n<0)return INT_MIN;
    if(n==0)return 0;
    if(dp[n])return dp[n];
    return dp[n] = 1 + max(cut(n-x,x,y,z),max(cut(n-y,x,y,z),cut(n-z,x,y,z)));
}
int main()
{
    int t;cin>>t;while(t--)
    {
        int n,x,y,z;
        cin>>n>>x>>y>>z;
        memset(dp,0,sizeof(dp));
        cout<<cut(n,x,y,z)<<'\n';
    }
    return 0;
}
```
Time Complexity : O(n)
