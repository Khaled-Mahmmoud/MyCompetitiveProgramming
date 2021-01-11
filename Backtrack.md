```cpp
// Generating Subsets
// the subsets of {1,2,3} are ;φ, {1}, {2}, {3}, {1,2}, {1,3}, {2,3} and {1,2,3}.
// Method 1: Recursion
int n;
vector<int>v,sub;
vector<vector<int>>res;
void subset(int idx)
{
    if(idx==n)
    {
        res.push_back(sub);
        return;
    }
    sub.push_back(v[idx]);
    subset(idx+1);
    sub.pop_back();
    subset(idx+1);
}
int main()
{
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    subset(0);
    sort(res.begin(),res.end());
    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
            cout<<res[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
// O(n * 2^n)

// Method 2: Bitmask
for(int b=0;b<(1<<n);b++)
{
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        if (b&(1<<i))
            v.push_back(i+1);
    }
}
// O(n * 2^n)

// Generating permutations
// Method 1: Recursion
int n;
vector<int>v,p;
void gen()
{
    if(v.size()==n)
    {
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(p[i])
            continue;
        p[i] = 1;
        v.push_back(i);
        gen();
        p[i] = 0;
        v.pop_back();
    }
}
// O(n * !n)

// Method 2: The C++ standard library
void Permutation(int a[],int n)
{
    do
    {
        for(int i=0;i<n;i++)
            cout<<a[i]<<' ';
        cout<<'\n';
    }
    while(next_permutation(a,a+n));
    // while(prev_permutation(a,a+n);
}
// Complexity : O(n * !n)

// The next permutation of s after x steps ?
void permutation(string str,int x)
{
    for(int i=0;i<x;i++)
        next_permutation(str.begin(),str.end());
    //  prev_permutation(str.begin(),str.end());
    cout<<str;
}
// Complexity : O(n * x)

```
