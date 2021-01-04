### Computational Geometry

Radians: 0 - 2 π

Degrees: 0 - 360

Radians is better computationally - so libraries use that

Right angle 90 degree or π/2 radians

370 Degree = 10 Degree = 370 % 360

[Computational Geometry Tutorial](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Geometry/Computational%20Geometry.pdf)

```cpp
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

Example

Convert 30 degrees 15 minutes and 50 seconds angle to decimal degrees: 30° 15' 50"

The decimal degrees dd is equal to: dd = d + m/60 + s/3600 = 30° + 15'/60 + 50"/3600 = 30.263888889°
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
```


### Orientation of 3 points?

Orientation of an ordered triplet of points in the plane can be

- clockwise

- counterclockwise

- colinear

If orientation of (p1, p2, p3) is collinear, then orientation of (p3, p2, p1) is also collinear.

If orientation of (p1, p2, p3) is clockwise, then orientation of (p3, p2, p1) is counterclockwise and vice versa is also true.

Given three points p1, p2 and p3, find orientation of (p1(x1,y1), p2(x2,y2), p3(x3,y3)).

**How to compute Orientation?**

The idea is to use slope.  

Slope of line segment (p1, p2): σ = (y2 - y1)/(x2 - x1)

Slope of line segment (p2, p3): τ = (y3 - y2)/(x3 - x2)

Using above values of σ and τ, we can conclude that, 
the orientation depends on sign of  below expression: 

(y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 - x1)

Above expression is positive when σ > τ, the orientation is clockwise. 

Above expression is negative when σ < τ, the orientation is counterclockwise.

Above expression is zero when σ == τ,  the orientation is colinear 

```cpp
struct Point 
{ 
    int x, y; 
}; 
void orientation(Point p1, Point p2, Point p3) 
{ 
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y); 
  
    if (val == 0) 
        return cout<<"colinear";  
  
    return cout<<(val > 0)? "clockwise": "counterclockwise"; 
} 
```

### Check if two given line segments intersect?

Given two line segments (p1, q1) and (p2, q2), find if the given line segments intersect with each other.

How is Orientation useful here?
Two segments (p1,q1) and (p2,q2) intersect if and only if one of the following two conditions is verified

1. **General Case**

- (p1, q1, p2) and (p1, q1, q2) have different orientations and
- (p2, q2, p1) and (p2, q2, q1) have different orientations.

![alt text](https://media.geeksforgeeks.org/wp-content/uploads/linesegments1.png)

2. **Special Case**
- (p1, q1, p2), (p1, q1, q2), (p2, q2, p1), and (p2, q2, q1) are all collinear and
- the x-projections of (p1, q1) and (p2, q2) intersect
- the y-projections of (p1, q1) and (p2, q2) intersect

![alt text](https://media.geeksforgeeks.org/wp-content/uploads/linesegments2.png)
```cpp
struct Point 
{ 
    int x; 
    int y; 
}; 
// Given three colinear points p, q, r,
// the function checks if point q lies on line segment 'pr' 
bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 
bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    // General case 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false; 
} 
```
### Check whether a given point lies inside a triangle or not?
```cpp
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
```
[Point and Vector Tutorial](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Geometry/Point%20and%20Vector.pdf)

[Vectors](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Geometry/vectors.pdf)

[Complex Number and 2D Point](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Geometry/Complex%20Number%20and%202D%20Point.pdf)

[Lines and Distances](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Geometry/Lines%20and%20Distances.pdf)

[Parametric equation - Part 1](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Geometry/Parametric%20equation.pdf)

[Parametric equation - Part 2](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Geometry/Parametric%20equation2.pdf)
```cpp
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
double dot(point p,point q)
{
    return p.x*q.x + p.y*q.y;
}
double cross(point p,point q)
{
    return p.x*q.y - p.y*q.x;
}
point cross_3d(point a, point b)
{
    return point(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
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
```
```cpp
// Distance between two points on Earth
// we need to have the co-ordinates of point A and point B.
// convert the latitude and longitude values from decimal degrees to radians.
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
