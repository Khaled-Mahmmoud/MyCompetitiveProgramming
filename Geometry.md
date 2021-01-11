```cpp
/*
Polar system , Cartesian
x = r * cos(O)
y = r * sin(O)
r = sqrt(x^2 + y^2)
O = atan2(y,x)

Radians: 0 - 2 π
Degrees: 0 - 360
Right angle 90 degree or π/2 radians
370 Degree = 10 Degree = 370 % 360
*/
#define PI acos(-1.0)
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
/*
Vector = Direction + Magnitude
Two vectors are perpendicular if and only if their angle is a right angle
Set of vectors is orthogonal if and only if they are pairwise perpendicular
The normal vector to a surface is a vector which is perpendicular to the surface at a given point
*/
#define point complex<double>
point input()
{
    point a;int val;
    cin>>val;a.real(val);
    cin>>val;a.imag(val);
    return a;
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
// point a(2,3) ==> norm(a) = 2^2 + 3^2 = 13
double norm(point a) 
{
    return dot(a, a);
}
double length(point a)
{
    return abs(a);
}
double length1(point a)
{
    return hypot(a.real(),a.imag());
}
double length2(point a) 
{
    // Length of a: |a| = √(a.a)
    return sqrt(norm(a));
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


struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    point operator+(const point &p)const
    {
        return point(x+p.x,y+p.y);
    }
    point operator-(const point &p)const
    {
        return point(x-p.x,y-p.y);
    }
    point operator*(double c)const
    {
        return point(x*c,y*c);
    }
    point operator/(double c)const
    {
        return point(x/c,y/c);
    }

};


struct point3d
{
    int x,y,z;
}
point cross_3d(point3d a, point3d b)
{
    return point(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}


// Triangle Law
// sin(A)/a = sin(B)/b = sin(C)/c
// a^2 = b^2 + c^2 - 2*b*c*cos(A)
double fixAngle(double A)
{
	return A > 1 ? 1 : (A < -1 ? -1 : A);
}
double getSide_a_bAB(double b, double A, double B) 
{
	return (sin(A) * b) / sin(B);
}
double getAngle_A_abB(double a, double b, double B) 
{
	return asin(fixAngle((a * sin(b)) / b));
}
double getAngle_A_abc(double a, double b, double c)
{
	return acos(fixAngle((b * b + c * c - a * a) / (2 * b * c)));
}
double perimeter_triangle(double a, double b, double c) 
{
	return a + b + c;
}
// a, b, c are sides of triangle
double area_triangle(double a, double b, double c) 
{
        if(a+b<=c||b+c<=a||a+c<=b)
            return -1;
	double s = 0.5 * perimeter_triangle(a, b, c);
	    return sqrt(s * (s - a) * (s - b) * (s - c));
}
// a, b, c are medians of triangle
double area_triangle1(double a, double b, double c) 
{
        if(a+b<=c||b+c<=a||a+c<=b)
            return -1;
	double s = 0.5 * perimeter_triangle(a, b, c);
	    return (4.0/3.0) * sqrt(s * (s - a) * (s - b) * (s - c));
}
// check whether point X lies inside the triangle abc
double area_triangle2(point a,point b,point c) 
{ 
   return abs((a.x*(b.y-c.y) + b.x*(c.y-a.y)+ c.x*(a.y-b.y))/2.0); 
   //OR return abs(a.x*(b.y-c.y) + b.x*(c.y-a.y)+ c.x*(a.y-b.y)); 
} 
bool isInside(point a,point b,point c,point x) 
{    
   double A  = area_triangle2(a,b,c); 
   double A1 = area_triangle2(x,a,b); 
   double A2 = area_triangle2(x,b,c); 
   double A3 = area_triangle2(x,a,c); 
   
   return (A == A1 + A2 + A3); 
}
/*
Distance between two points on Earth	
we need to have the co-ordinates of point A and point B.	
convert the latitude and longitude values from decimal degrees to radians.	
*/	
#define R 6378	
double spherical_distance(double lat1,double lon1,double lat2,double lon2)	
{	
    double dlon, dlat, a, c, d;	
    dlon = lon2 - lon1;	
    dlat = lat2 - lat1;	
    a = pow((sin(dlat/2)),2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2);	
    c = 2 * atan2(sqrt(a), sqrt(1-a));	
    d = R * c;	
    return d;	
}
```
