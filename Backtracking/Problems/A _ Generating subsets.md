# Generating subsets

Given a set of positive integers, find all its subsets.
         
Input : 1 2 3
Output :
```
  (this space denotes null element)
1
1 2
1 2 3
1 3
2
2 3
3
```
Time Complexity : O(2 ^ n)  by Backtracking

```cpp
vector<int>v,sub;int n;
vector<vector<int>>res;
void subset(int index)
{
    res.push_back(sub);
    for(int i=index;i<n;i++)
    {
        sub.push_back(v[i]);
        subset(i+1);
        sub.pop_back();
    }
}
int main()
{
    cin>>n;v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    subset(0);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
        cout<<res[i][j]<<' ';cout<<'\n';}
    return 0;
}
```
