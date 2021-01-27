```CPP
const int base = 1e9;
typedef vector<int> big;
void Set(big &a)
{
    while(a.size()>1&&a.back()==0)
        a.pop_back();
}
void print(big a)
{
    Set(a);
    if(a.empty())
        cout<<0;
    else
    {
        cout<<a[sz(a)-1];
        for(int i=sz(a)-2; i>=0; i--)
            cout<<setw(9)<<setfill('0')<<a[i];
    }
}
big convert(string s)
{
    big ans;
    if(s.empty())
    {
        ans.push_back(0);
        return ans;
    }
    if(s[0]=='-')
        return ans;
    while(s.size()%9)
        s = '0' + s;
    for(int i=0; i<sz(s); i+=9)
    {
        int v = 0;
        for(int j=i; j<i+9; j++)
            v = v*10 + (s[j]-'0');
        ans.insert(ans.begin(),v);
    }
    Set(ans);
    return ans;
}
big convert(char c[],int sz)
{
    string s="";
    for(int i=0; i<sz; i++)
        s=s+c[i];
    return convert(s);
}
big convert(ll x)
{
    string s="";
    while(x>0)
        s=char(x%10+'0')+s,x/=10;
    return convert(s);
}
big convert(int x)
{
    return convert((ll)x);
}
bool operator<(big a,big b)
{
    Set(a);
    Set(b);
    if(sz(a)!=sz(b))
        return sz(a) < sz(b);
    for(int i=sz(a)-1; i>=0; i--)
        if(a[i]!=b[i])
            return a[i] < b[i];
    return false;
}
bool operator>(big a,big b)
{
    return b < a;
}
bool operator==(big a,big b)
{
    return !(a<b) && !(b<a);
}
bool operator!=(big a,big b)
{
    return !(a==b);
}
bool operator<=(big a,big b)
{
    return (a<b||a==b);
}
bool operator>=(big a,big b)
{
    return (a>b||a==b);
}
bool operator<(big a,int b)
{
    return a<convert(b);
}
bool operator>(big a,int b)
{
    return convert(b) < a;
}
bool operator==(big a,int b)
{
    return !(a<b) && !(a>b);
}
bool operator!=(big a,int b)
{
    return !(a==b);
}
bool operator<=(big a,int b)
{
    return (a<b||a==b);
}
bool operator>=(big a,int b)
{
    return (a>b||a==b);
}
big max(big a,big b)
{
    return (a>b)?a:b;
}
big min(big a,big b)
{
    return (a<b)?a:b;
}
big operator+(big a,big b)
{
    Set(a);
    Set(b);
    big ans;
    int carry = 0;
    for(int i=0; i<max(sz(a),sz(b)); i++)
    {
        if(i<sz(a))
            carry += a[i];
        if(i<sz(b))
            carry += b[i];
        ans.push_back(carry%base);
        carry /= base;
    }
    if(carry)
        ans.push_back(carry);
    Set(ans);
    return ans;
}
big operator+(big a,int b)
{
    return a + convert(b);
}
big operator++(big &a)
{
    a = a + 1;
    return a;
}
void operator+=(big &a,big b)
{
    a = a + b;
}
void operator+=(big &a,int b)
{
    a = a + convert(b);
}
big operator-(big a,big b)
{
    Set(a);
    Set(b);
    big ans;
    int carry = 0;
    for(int i=0; i<sz(a); i++)
    {
        carry += a[i] - (i<sz(b)?b[i]:0);
        if(carry<0)
            ans.push_back(carry+base),carry = -1;
        else
            ans.push_back(carry),carry = 0;
    }
    Set(ans);
    return ans;
}
big operator-(big a,int b)
{
    return a - convert(b);
}
void operator--(big &a)
{
    a = a - 1;
}
void operator-=(big &a,big b)
{
    a = a - b;
}
void operator-=(big &a,int b)
{
    a = a - convert(b);
}
big operator*(big a,big b)
{
    Set(a);
    Set(b);
    big ans;
    ans.assign(sz(a)+sz(b),0);
    for(int i=0; i<sz(a); i++)
    {
        ll carry = 0;
        for(int j=0; j<sz(b)||carry>0; j++)
        {
            ll s = ans[i+j] + carry + (ll)a[i]*(j<sz(b)?b[j]:0);
            ans[i+j] = s%base;
            carry = s/base;
        }
    }
    Set(ans);
    return ans;
}
big operator*(big a,int b)
{
    return a * convert(b);
}
void operator*=(big &a,big b)
{
    a = a * b;
}
void operator*=(big &a,int b)
{
    a = a * convert(b);
}
big operator/(big a,big b)
{
    Set(a);
    Set(b);
    big ans,cur;
    if(b==convert(0))
        return convert("-1");
    for(int i=sz(a)-1; i>=0; i--)
    {
        cur.insert(cur.begin(),a[i]);
        int x = 0,l = 0,r = base;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(b*convert(mid)>cur)
                r = mid - 1,x = mid;
            else
                l = mid+1;
        }
        cur = cur - convert(x-1) * b;
        ans.insert(ans.begin(),x - 1);
    }
    Set(ans);
    return ans;
}
big operator/(big a,int b)
{
    return a / convert(b);
}
void operator/=(big &a,big b)
{
    a = a / b;
}
void operator/=(big &a,int b)
{
    a = a / convert(b);
}
big operator%(big a,big b)
{
    Set(a);
    Set(b);
    big ans;
    if(b==convert(0))
        return convert("-1");
    for(int i=sz(a)-1; i>=0; i--)
    {
        ans.insert(ans.begin(),a[i]);
        int x = 0, l = 0,r = base;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(b*convert(mid)>ans)
                r = mid-1, x = mid;
            else
                l = mid+1;
        }
        ans = ans - convert(x-1)*b;
    }
    Set(ans);
    return ans;
}
big operator%(big a,int b)
{
    return a % convert(b);
}
void operator%=(big &a,big b)
{
    a = a / b;
}
void operator%=(big &a,int b)
{
    a = a % convert(b);
}
big sqrt(big a)
{
    big x0 = a, x1 = (a+1)/2;
    while(x1<x0)
    {
        x0 = x1;
        x1 = (x1+a/x1)/2;
    }
    return x0;
}
```
