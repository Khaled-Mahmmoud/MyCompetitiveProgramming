```cpp
/*
// Polar system , Cartesian
x = r * cos(O)
y = r * sin(O)
r = sqrt(x^2 + y^2)
O = atan2(y,x)

//vectors
Vector = Direction + Magnitude
Two vectors are perpendicular if and only if their angle is a right angle
Set of vectors is orthogonal if and only if they are pairwise perpendicular
The normal vector to a surface is a vector which is perpendicular to the surface at a given point
*/
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
/*
Dot Product : Algebraically, sum of the products of the corresponding entries
Geometrically, the product of the Euclidean magnitudes of the two vectors
and the cosine of the angle between them. A . B = |A| |B| cos(O) = x1*x2 + y1*y2

if A and B are orthogonal, then the angle between them is 90 A.B = 0
if they are codirectional, then the angle between them is 0 A.B = |A| |B|
if (O) > 90 then A.B <0 and if(O) < 90 then A.B > 0 if (O) = 90 the A.B = 0
*/
double dot(point p,point q)
{
    return p.x*q.x + p.y*q.y;
}
double norm(point a) 
{
    return dot(a, a);
}
double abs(point a) 
{
    // Length of a: |a| = √(a.a)
    return sqrt(norm(a));
}
double dot_angle(point a, point b) 
{
    return acos(dot(a,b)/(abs(a) * abs(b)));
}
/*
The cross product, a X b, is a vector that is perpendicular
to both a and b and therefore normal to the plane containing them.
it's a magnitude of one if the two are perpendicular and zero if the two are parallel.
A x B = |A| |B| sin(O) = A.x * B.y - B.x * A.y 
*/
double cross(point p,point q)
{
    return p.x*q.y - p.y*q.x;
}
point cross_3d(point a, point b)
{
    return point(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
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

/*
Radians: 0 - 2 π
Degrees: 0 - 360
Right angle 90 degree or π/2 radians
370 Degree = 10 Degree = 370 % 360
*/
const double PI = acos(-1.0);
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
/*
How to convert degrees, minutes, seconds to decimal degrees

One degree is equal to 60 minutes and equal to 3600 seconds: 1° = 60' = 3600"

One minute is equal to 1/60 degrees: 1' = (1/60)° = 0.01666667°

One second is equal to 1/3600 degrees: 1" = (1/3600)° = 2.77778e-4° = 0.000277778°

For angle with d integer degrees m minutes and s seconds: d° m' s"

The decimal degrees dd is equal to: dd = d + m/60 + s/3600
*/
double to_degree_from_minutes(double minutes)
{
    return (minutes/60);
}
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
double area_triangle(double a, double b, double c) 
{
        if(a+b<=c||b+c<=a||a+c<=b)
            return -1;
	double s = 0.5 * perimeter_triangle(a, b, c);
	    return (4.0/3.0) * sqrt(s * (s - a) * (s - b) * (s - c));
}
/* A function to check whether point P(x, y) lies inside the triangle formed  
   by A(x1, y1), B(x2, y2) and C(x3, y3) */ 
double area(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
   //OR return abs(x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2)); 
} 
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) 
{    
   /* Calculate area of triangle ABC */
   double A = area (x1, y1, x2, y2, x3, y3); 
  
   /* Calculate area of triangle PBC */   
   double A1 = area (x, y, x2, y2, x3, y3); 
  
   /* Calculate area of triangle PAC */   
   double A2 = area (x1, y1, x, y, x3, y3); 
  
   /* Calculate area of triangle PAB */    
   double A3 = area (x1, y1, x2, y2, x, y); 
    
   /* Check if sum of A1, A2 and A3 is same as A */ 
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
