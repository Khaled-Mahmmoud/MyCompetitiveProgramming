```cpp
// Graham Scan Algorithm
#define point complex<double>
#define x real()
#define y imag()
int n;
vector<point> v,hull;
point input()
{
    int nx,ny;
    cin>>nx>>ny;
    return point(nx,ny);
}
double cross(point a,point b)
{
    return (conj(a)*b).imag();
}
double length(point a)
{
    return abs(a);
}
bool cmp(point a, point b)
{
    a = a-v[0];
    b = b-v[0];
    ll d = cross(a,b);
    if(!d)
        return length(a) < length(b);
    return d < 0;
}
void convexHull()
{
    hull.push_back(v[0]);
    for(int i=1; i<n; ++i)
    {
        while(sz(hull)>1)
        {
            point v1 = hull[sz(hull)-1] - hull[sz(hull)-2];
            point v2 = v[i]-hull[sz(hull)-2];
            if(cross(v1,v2)<0)
                break;
            hull.pop_back();
        }
        hull.push_back(v[i]);
    }
}
bool operator<(point a,point b)
{
    if(a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}
int main()
{
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; ++i)
        v[i] = input();
    point mn(1e9,1e9);
    for(int i=0; i<n; ++i)
        if(v[i]<v[0])
            swap(v[0],v[i]);
    sort(v.begin()+1, v.end(), cmp);
    convexHull();
    cout<<sz(hull)<<endl;
    for(int i=0; i<sz(hull); ++i)
        cout<<hull[i].x<<" "<<hull[i].y<<endl;
    return 0;
}
// O(n log n)
```
