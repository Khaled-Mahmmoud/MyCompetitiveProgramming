```cpp
#define point complex<double>
#define X real()
#define Y imag()
#define polar(r,t) ((r)*exp(point(0,(t))))
/*
// Polar system , Cartesian
x = r * cos(O)
y = r * sin(O)
r = sqrt(x^2  + y^2)
O = atan2(y,x)
*/
#define pi acos(-1.0)
#define EPS 1e-8
int dcmp(double x, double y){return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;}

point input()
{
    int nx,ny;
    cin>>nx>>ny;
    return point(nx,ny);
}

/*
Dot Product : Algebraically, sum of the products of the corresponding entries
Geometrically, the product of the Euclidean magnitudes of the two vectors
and the cosine of the angle between them. A . B = |A| |B| cos(O) = x1*x2 + y1*y2
*/
// conj(a) ==> 2 + 3i ==> 2 - 3i flip sign of image
double dot(point a,point b)
{
    return (conj(a)*b).real();
}
/*
The cross product, a X b, is a vector that is perpendicular
to both a and b and therefore normal to the plane containing them.
A x B = |A| |B| sin(O) = A.x * B.y - B.x * A.y 
*/
double cross(point a,point b)
{
    return (conj(a)*b).imag();
}
struct point3d
{
    int x,y,z;
}
point cross_3d(point3d a, point3d b)
{
    return point(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

double length(point a)
{
    return abs(a);
}
double length1(point a)
{
    return hypot(a.real(),a.imag());
}
// point a(2,3) ==> norm(a) = 2^2 + 3^2 = 13
double norm(point a) 
{
    return dot(a, a);
}
double length2(point a) 
{
    // Length of a: |a| = √(a.a)
    return sqrt(norm(a));
}

// distance between two points
double dist(point a,point b)
{
    return length1(b-a);
}

double angle(point a)// angle with x-axis
{
    return arg(a);
}
double angle1(point a)// angle with x-axis
{
    return atan2((a).imag(), (a).real());
}
double dot_angle(point a, point b) 
{
    return acos(dot(a,b)/(abs(a) * abs(b)));
}
point scale(point a,double s)
{
    return a * s;
}
point vec(point a,point b)
{
    return b - a;
}
point rotate_counterclockwise(point a,double ang)
{
    // rotate around origin
    return a * polar(1.0,ang);// ang is radian
}
point rotate_clockwise(point a,double ang)
{
    // rotate around origin
    return a * polar(1.0, -ang);
}
point rotate_around_b(point a,point b,double ang)
{
    // rotate point a around point b
    return (a - b) * polar(1.0, ang) + b;
}
void check_point_line(point a,point b,point c)
{
    // check if point c on, above, below vector/line ab
    int x = dcmp(cross(c-a,c-b),0);
    if(x==1)
        cout<<"below";
    else if(x==-1)
        cout<<"above";
    else
        cout<<"on line";
}
// Point C distance to Line A-B
double dist_to_line(point a,point b,point c)
{
    double d = cross(b-a,c-a)/dist(a,b);
    return fabs(d);
}
double proj(point a, point b) 
{
    return dot(a, b) / abs(b);
}
bool arelinesame(point a,point b,point c,point d)
{
    return (cross(a-c,d-c)==0&&cross(b-c,d-c)==0);
}
bool arelinesparallel(point a,point b,point c,point d)
{
    return cross(b-a,d-c)==0;
}
// Check if 4 points is Square
bool is_square(vector<point> p)
{
    map<Double,vector<pair<int, int>>> mp;
    for(int i = 0; i < (int)p.size(); ++i)
        for(int j = i+1; j < (int)p.size(); ++j)
        {
            Double len(dist(p[i],p[j]));
            mp[len].push_back({i, j});
        }
    if(mp.size() != 2)
        return false;
    auto S = mp.begin();// side
    auto D = mp.begin(); // Diagonal
    ++D;
    if(S->Y.size() != 4 || D->Y.size() != 2)
        return false;
}
```
