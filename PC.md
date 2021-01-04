### Bitmask
```cpp
/*
X ^ 0 = X
X ^ X = 0
(A ^ B ^ C ^ D ^ E) ^ (A ^ B ^ C) = D ^ E
A ^ B ^ C ^ D = E , if E has any 1s bit, it must have odd number of 1s
X % 2 = X & 1 = bit 0
Generally : X % (2^n) = X & (2^n - 1)
*/
bool get_bit(int num,int idx){return ((num>>idx)&1);}
int set_bit(int num,int idx){return (num|(1<<idx));}
int clear_bit(int num,int idx){return (num&~(1<<idx));}
int flip_bit(int num,int idx){return num^(1<<idx);}
void get_binary(int n)
{
     if(!n)
        return;
     printNumber(n>>1);	
     cout<<(n&1);           
}
int cnt_bit(int mask)
{
    int ret = 0;
    while (mask)
    {
        if(mask&1)
            ret++;
        mask >>= 1;
    }
    return ret;
}
/*
X    = 840 	= 011010010000
X-1  = 839 	= 011010001111		What happened? First bit 16=(2^4) is removed, and 15=2^4-1 is added
X & (X-1) 	= 011010000000		first bit from right removed
X & ~(X-1) 	= 011010010000  & 100101110000 = 000000010000	
*/
int lsb(int num) {return (num & ~(num-1));}
int msb(int n) 
{ 
    if (!n) 
        return 0; 
    int cnt = -1; 
    while(n)
    { 
        n>>=1; 
        cnt++; 
    } 
    return (1<<cnt);
} 
/*
Get last bit using index & -index
+20 = 00010100
-20 = 11101100
20 & -20 = 00000100
Remove last bit : index - (index & -index)
00010100 - 00000100 = 00010000
Removing bits from mask
X = 10010100
Y = 00010100
X - Y removes all Y 1s from X : 10000000
general way to do so: X & ~Y : 10010100 & 11101011 = 10000000
*/
bool is_power_of_two(ll n)
{
    if(!n)
       return 0;
    return (n&(n-1))==0;
}
void get_binary_len(int n, int len)
{
    if(!len)
        return;
    get_binary_len(n>>1, len-1);
    cout<<(n&1);
}
// len = 3: 000, 001, 010, 011, 100, 101, 110, 111
void get_subset_binary(int len)	
{
   for (int i = 0; i < (1<<len); ++i)
   {
        get_binary_len(i,len);
        cout<<' ';
   }
}
/*
binary    gray
 0111	0100
in gray code, every bit is Xor of its bit and last one in binary
*/
int gray_code(int i)
{
    return i ^ (i>>1);
}
/*
One’s complement of a binary number is the inverse of the digits, change all 0's to 1's and all 1's to 0's.
Two’s Complement is start to flip after the “last bit”.
-number = 2’s complement of number or Get 1’s complement...then add 1
*/

```
### Generating Subsets
```cpp
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
// complexity : O(2^n)
````

### Prefix sum
```cpp
ll prefix_sum_2d(vector<int>v,int l,int r)
{
    int n = v.size();
    vector<ll>pr(n+1);

    for(int i=1;i<=n;i++)
        pr[i] = pr[i-1]+v[i-1];

    return pr[r]-pr[l-1];
}
ll prefix_sum_3d(vector<vector<int>>v,int r1,int c1,int r2,int c2)
{
    int n = v.size(),m = v[0].size();
    vector<vector<int>>pr(n+1,vector<int>(m+1));

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            pr[i][j] = v[i-1][j-1] + pr[i][j-1] + pr[i-1][j] - pr[i-1][j-1];

    return pr[r2][c2]-pr[r2][c1-1]-pr[r1-1][c2]+pr[r1-1][c1-1];
}
```
### Kadane's Algorithm
```cpp
// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
int maxSubArraySum(int a[], int size) 
{ 
    int ans = INT_MIN, r = 0; 
    for (int i = 0; i < size; i++) 
    { 
        r = r + a[i]; 
        if (ans < r) ans = r; 
        if (r < 0) r = 0; 
    } 
    return ans; 
}
//  OR
int maxSubArraySum(int a[], int size) 
{ 
   int ans = a[0], r = a[0]; 
   for (int i = 1; i < size ; i++) 
   { 
       r = max( a[i] , r + a[i] ); 
       ans = max( ans , r );
   } 
   return ans; 
} 
// Time Complexity : O(n)

//To print the subarray with the maximum sum, we maintain indices whenever we get the maximum sum

int maxSubArraySum(int a[], int size) 
{ 
    int ans = INT_MIN , r = 0, sat =0, en = 0, s=0; 

    for (int i=0; i< size; i++ ) 
    { 
        r += a[i]; 

        if (ans < r) 
        { 
            ans = r; 
            sat = s; 
            en = i; 
        } 

        if (r < 0) 
        { 
            r = 0; 
            s = i + 1; 
        } 
    } 
    cout << "Maximum contiguous sum is "<< ans << endl; 
    cout << "Starting index "<< sat <<"  :   Ending index "<< en << endl; 
}
```
### Search Algorithms
```cpp
int binary_search()
{
    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = (l+r) / 2;

        if (valid(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
double binary_search_d()
{
    double l = 0, r = 1e9;
    
    while (r-l > 1e-9)
    {
        double mid = (l+r) / 2;

        if (valid(mid))
            r = mid;
        else
            l = mid;
    }
    return l;
}
int ternary_search(int l, int r)
{
    while (l<=r)
    {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
                
        if(f(mid1) < f(mid2))
            l = mid1 + 1;
        else
            r = mid2 - 1;
    }
    return f(l);                   
}
double ternary_search_d(double l, double r)
{
    while (r - l > 1e-9)
    {
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        
        if(f(mid1) < f(mid2))
            l = mid1;
        else
            r = mid2;
    }
    return f(l);                   
}
```
### Sorting
```cpp
sort(v.begin(),v.end());   // O(nlogn)

// a reverse order is possible as follows:
sort(v.rbegin(),v.rend());
sort(v.begin(),v.end(),greater<int>())


// An ordinary array a can be sorted as follows:
sort(a,a+n);  

// a reverse order is possible as follows:
sort(a,a+n,greater<int>());

// but if there 
ll a[n];
// we can sort it by:
sort(a,a+n,greater<ll>());


//sorting the string s:
sort(str.begin(), str.end());

// a reverse order is possible as follows:
sort(str.rbegin(),str.rend());          OR 
sort(str.begin(),str.end(),greater<char>())

/*
Pairs (pair) are sorted primarily according to their first elements (first).
However, if the first elements of two pairs are equal, they are sorted according to their second elements (second)
*/
vector<pair<int,int>> v;
v.push_back({1,5});
v.push_back({2,3});
v.push_back({1,2});
sort(v.begin(), v.end());
// After this, the order of the pairs is (1,2), (1,5) and (2,3).

// comparison function to the sort 
bool pred(string a, string b)
{
    return a < b;
}
sort(v.begin(), v.end(), pred);
// How to sort a pair increasing based on first element then decreasing based on second element?
bool pred(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}
vector<pair<int,int>>v;
sort(v.begin(), v.end(), pred);
// How to declare a set based on specified sorting ?
struct cmp
 {
     // notice you should to use (struct cmp, const, &)
     bool operator() (const pair<int, int> &a, const pair<int, int> &b) const  
     {
	 // code
     }
};
set<pair<int,int>,cmp>st;

// How to sort an array of structures ?
struct q
{
    int l, r;
    q() {}
    // notice you should to put < instead of (), also notice that rhs instead of b
    bool operator<(const qu &rhs) const
    {
        if(l==rhs.l)
        {
            return r > rhs.r;
        }
        return l < rhs.l;
    }
};
q a[200010];

// To sort a range[l,r] of string where 1<=l<=r<=str.size()
sort(&str[l-1], &str[r]);
sort(str.begin() + l - 1, str.begin() + r);

// Radix Sort
int n, v[100000], t[100000];
void sort()
{
    int f[10] = {};
    int p10 = 1;
    for (int it = 0; it < 10; ++it)
    {
        for (int i = 0; i < n; ++i)
            ++f[v[i] / p10 % 10];
        for (int i = 1; i < 10; ++i)
            f[i] += f[i - 1];
        for (int i = n - 1; i >= 0; --i)
            t[--f[v[i] / p10 % 10]] = v[i];
        for (int i = 0; i < n; ++i)
            v[i] = t[i];
        for (int i = 0; i < 10; ++i)
            f[i] = 0;
        p10 *= 10;
    }
}
```

### Subarray Problems
```cpp
// Given an unsorted array of integers
// count a continuous subarray which adds to a given number.
int cnt_subarray(int arr[], int n, int sum)
{
    map<int, int> m;
    int res = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) 
    {
        cur += arr[i];
        if (cur == sum)
            res++;
        if (m.find(cur - sum) != m.end())
            res += (m[cur - sum]);
        m[cur]++;
    }
    return res;
}
/*
Count of subarrays having exactly K prime numbers
Count of subarrays having exactly K perfect square numbers

Traverse the given array and check whether the element is prime or not.
If the current element is prime then change the value of index to 1, Else 0.
Find the count of subarray with sum equals to K in the above Binary Array.

Count subarrays with equal number of 1’s and 0’s
Count subarrays with same even and odd elements

Traverse the given array and check whether the element is 1 or not.
If the current element is 1 then change the value of index to 1, Else -1.
Find the count of subarray with sum equals to 0 in the above Binary Array.

// Longest sub-array having sum k
int long_subarray(int arr[],int n,int k)
{
    map<ll, int> m;
    ll sum = 0;int len = 0,index = -1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            len = i + 1;
            index = i;
        }
        if (m.find(sum - k) != m.end())
            if (len < (i - m[sum - k]))
                len = i - m[sum - k],index = i;
	if (m.find(sum) == m.end())
            m[sum] = i;
    }
    cout<<index-len+1<<' '<<index;
    return len;
}
// Find the total number of subarrays having bitwise XOR of all elements equals to B
int cnt_subarray(int a[],int n,int b)
{
    unordered_map<int,int>m;
    int res = 0,cur = 0;
    for(int i=0;i<n;i++)
    {
        cur += a[i];
        if(cur==b)
            res++;
        if(m.find(cur^b)!=m.end())
            res += m[cur^b];
        m[cur]++;
    }
    return res;
}
```
