
```cpp
ios_base::sync_with_stdio(0), cin.tie(0);

string s;
while(s.size()==0)
getline(cin, s);

while (cin >> x) 
{
    // code
}

freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

cout<< 838897238475ll ;

int a = 1e9 , b = 1e9 ;	
cout<< a * b ;             // -148668157543         // Overflow 	
long long c = a*b ;       // c = -148668157543     // Casting

double a,b;
if (abs(a-b) < 1e-9) 	
{	
    // a and b are equal	
}

#include<iomanip>	
cout<< fixed << showpoint << setprecision(n) ;

cout<<setw(5)<<setfill('0')<<"kh"; 000kh

int binary_search()
{
    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = l + (r-l) / 2;

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
    while (r-l > 1e-9) // somtimes give us time limited
    // better than above : while (r-l > 1e-6)
    // better than above : for (int i = 0; i < 100; ++i)
    {
        double mid = l + (r-l) / 2;

        if (valid(mid))
            r = mid;
        else
            l = mid;
    }
    return l;
}
// Ternary search to find an interger local minimum
int ternary_search(int l, int r)
{
    int l = 0, r = 1e6;
    while(r - l > 10)
    {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (calc(mid1) < calc(mid2))
            r = mid2;
        else
            l = mid1;
    }
    int pos, val = 1e9;
    for (int i = l; i <= r; ++i)
    {
        int tmp = calc(i);
        if(val > tmp)
        {
            val = tmp;
            pos = i;
        }
    }
    return pos;
}
// Ternary search on to find a real (floating) local minimum
double ternary_search_d(double l, double r)
{
    while (r - l > 1e-9) // // somtimes give us time limited
    // better than above : while (r-l > 1e-6)
    // better than above : for (int i = 0; i < 100; ++i)
    {
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        
        if(f(mid1) < f(mid2))
            r = mid2;
        else
            l = mid1;
    }
    return f(l);                   
}

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
// Generating Subsets
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
```
