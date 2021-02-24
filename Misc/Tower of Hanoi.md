```cpp
stack<int>ar[3];
void get(stack<int> st)
{
    if(st.empty())
        return;
    int k = st.top();
    st.pop();
    get(st);
    cout<<' '<<k;
}
void tower(int n, int f, int t, int d,int &k)
{
    if(k<1)
        return;
    if (n == 1)
    {
        k--;
        cout<<"Move disk 1 from rod " << f + 1<<" to rod " << t + 1 <<'\n';
        ar[f].pop();
        ar[t].push(1);
        cout<<"rod 1: ";get(ar[0]);cout<<'\n';
        cout<<"rod 2: ";get(ar[1]);cout<<'\n';
        cout<<"rod 3: ";get(ar[2]);cout<<'\n';
        cout<<'\n';
        return;
    }
    tower(n - 1, f, d, t, k);
    if(k<1)
        return;
    {
        k--;
        cout<<"Move disk " << n << " from rod " << f + 1<<" to rod " << t + 1 << '\n';
        ar[f].pop();
        ar[t].push(n);
        cout<<"rod 1: ";get(ar[0]);cout<<'\n';
        cout<<"rod 2: ";get(ar[1]);cout<<'\n';
        cout<<"rod 3: ";get(ar[2]);cout<<'\n';
        cout<<'\n';
    }
    tower(n - 1, d, t, f, k);
}
void solve()
{
    int n; // number of disk
    int k; // number of moves
    cin>>n>>k;
    for(int i=n;i>0;i--)
        ar[0].push(i);
    cout<<"rod 1: ";get(ar[0]);cout<<'\n';
    cout<<"rod 2: ";get(ar[1]);cout<<'\n';
    cout<<"rod 3: ";get(ar[2]);cout<<'\n';
    cout<<'\n';
    tower(n, 0, 2, 1, k);
    for(int i=0;i<3;i++)
        while(sz(ar[i]))
            ar[i].pop();
}
```
