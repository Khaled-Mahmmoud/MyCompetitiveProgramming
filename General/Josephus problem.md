```cpp
/*
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. 
The task is to choose the place in the initial circle so that you are the last one remaining and so survive.
*/
int k;
int jose(int n)
{
    if (!n)
        return n;
    return (jose(n-1)+k) % n;
}
void josephus()
{
    int n;
    cin>>n>>k;
    cout<<jose(n)+1;
}
// Print the last three numbers of josephus(n,k) sequence
void solve()
{
    int n,k,ans1,ans2,ans3;
    cin>>n>>k;
    ans1 = 0;
    ans2 = (k-1)%2;
    ans3 = (k-1)%3;
    for(int i=2; i<=n; i++)
        ans1 = (ans1+k)%i;
    for(int i=3; i<=n; i++)
        ans2 = (ans2+k)%i;
    for(int i=4; i<=n; i++)
        ans3 = (ans3+k)%i;
    cout<<ans3+1<<" "<<ans2+1<<" "<<ans1+1<<'\n';
}
```
