```cpp
#define point complex<double>
#define X real()
#define Y imag()
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

// point a(2,3) ==> norm(a) = 2^2 + 3^2 = 13
double norm(point a) 
{
    return dot(a, a);
}

double length(point a)
{
    return abs(a);
    return hypot(a.real(),a.imag());
    // Length of a: |a| = √(a.a)
    return sqrt(norm(a));
}

point vec(point a,point b)
{
    return b - a;
}
// distance between two points
double dist(point a,point b)
{
    return length(vec(a,b));
}

double angle(point a)// angle with x-axis
{
    return arg(a);
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
point refelct(point v,point m)
{
    return conj(v/m) * m;
}
```
