```cpp
/*
Vector = Direction + Magnitude
Two vectors are perpendicular if and only if their angle is a right angle
Set of vectors is orthogonal if and only if they are pairwise perpendicular
The normal vector to a surface is a vector which is perpendicular to the surface at a given point
*/
/*
Dot Product : Algebraically, sum of the products of the corresponding entries
Geometrically, the product of the Euclidean magnitudes of the two vectors
and the cosine of the angle between them. A . B = |A| |B| cos(O) = x1*x2 + y1*y2
*/
// conj(a) ==> 2 + 3i ==> 2 - 3i flip sign of image
/*
The cross product, a X b, is a vector that is perpendicular
to both a and b and therefore normal to the plane containing them.
A x B = |A| |B| sin(O) = A.x * B.y - B.x * A.y 
*/
#define PI acos(-1.0)
#define EPS 1e-9
int dcmp(double x, double y) {return fabs(x - y) <= EPS ? 0 : x > y ? 1 : -1;}
#define point complex<double>
#define X real()
#define Y imag()
#define vec(a,b) ((b) - (a))
#define length(a) abs(a)
#define dot(a,b) (conj(a)*(b)).real()
#define cross(a,b) (conj(a)*(b)).imag()
#define norm(a) dot((a),(a))
#define dist(a,b) length(vec((a),(b)))
#define angle(a) arg(a)
#define scale(a,s) (a) * (s)
#define dot_angle(a,b) acos(dot(a,b)/(abs(a) * abs(b)))
#define cross_3d(a,b) point(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x)
#define rotate_counterclockwise(a,ang) a * polar(1.0,ang) // rotate around origin
#define rotate_clockwise(a,ang) a * polar(1.0, -ang)
#define rotate_around_b(a,b,ang) (a - b) * polar(1.0, ang) + b  // rotate point a around point b
#define refelct(v,m) conj(v/m) * m
/*
Polar System , Cartesian System
x = r * cos(O)
y = r * sin(O)
r = sqrt(x^2 + y^2)
O = atan2(y,x)

Complex number with Catresian System : X + i Y
Complex number with Polar System : R(cos(O) + i sin(O)) = R e^(i O)
*/

/*
// Angles
Radians: 0 - 2 π
Degrees: 0 - 360
Right angle 90 degree or π/2 radians
370 Degree = 10 Degree = 370 % 360
*/
double toRadians(double degree) 
{
    return (degree * PI) / 180.0;
}
double toDegree(double radian)
{
    if(radian<0)
        radian += 2*PI;
    return (radian * 180.0 / PI);
}
// Convert degrees, minutes, seconds(d° m' s") to decimal degrees d°
double to_degree(double degrees, double minutes, double seconds)
{
    return degrees + (minutes/60) + (seconds/60*60);
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
