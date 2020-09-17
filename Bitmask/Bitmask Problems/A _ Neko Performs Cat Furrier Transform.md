# Neko Performs Cat Furrier Transform

[Problem Link](https://codeforces.com/contest/1152/problem/B)
```cpp
int main()
{
    vector<int>ans;
    int cnt=0;
    bool p=true;
    int n;
    cin>>n;
    while(true)
    {
        string s;
        int m=n;
        while(m)
        {
            s+=m%2+'0';
            m/=2;
        }
        reverse(s.begin(),s.end());
        bool flag=true;
        int i;
        for(i=0; i<s.size(); i++)
            if(!(s[i]-'0'))
                break;

        if(i==s.size())
            break;
        if(p)
        {
            i=s.size()-i;
            ans.push_back(i);
            i=pow(2,i)-1;
            n=n^i;
        }
        else
            n+=1;
        p=!p;
        cnt++;
    }
    cout<<cnt<<'\n';
    for(int x:ans)
        cout<<x<<' ';
    return 0;
}
```
