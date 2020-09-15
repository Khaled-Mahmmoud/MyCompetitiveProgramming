# Nikita and string

```cpp
string str;
int n, dp[5005][5];
int solve(int i, int group)
{
    if(i == n)
        return 0;
    if(~dp[i][group])
        return dp[i][group];
    int ans = 0;
    if(str[i] == 'a')
    {
        if(group == 0 || group == 2)
            ans = solve(i + 1, group) + 1;
        else
            ans = max(solve(i + 1, group), solve(i + 1, group + 1) + 1);
    }
    else
    {
        if(group == 0)
            ans = max(solve(i + 1, group), solve(i + 1, group + 1) + 1);
        else if(group == 1)
            ans = solve(i + 1, group) + 1;
        else
            ans = solve(i + 1, group);
    }
    return dp[i][group] = ans;
}
int main()
{
    cin>>str;
    n = str.size();
    memset(dp,-1,sizeof dp);
    cout<<solve(0,0);
    return 0;
}

```
