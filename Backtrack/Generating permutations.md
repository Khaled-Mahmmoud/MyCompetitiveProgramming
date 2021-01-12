```cpp
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
