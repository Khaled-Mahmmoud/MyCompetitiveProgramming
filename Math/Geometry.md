### Computational Geometry

Radians: 0 - 2 π

Degrees: 0 - 360

Radians is better computationally - so libraries use that

Right angle 90 degree or π/2 radians

370 Degree = 10 Degree = 370 % 360

[Tutorials](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Geometry/Computational%20Geometry.pdf)

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
double area_triangle(double a, double b, double c) 
{
	double s = 0.5 * perimeter_triangle(a, b, c);
	return sqrt(s * (s - a) * (s - b) * (s - c));
}
double triangleArea(point p0, point p1, point p2)
{
	double a = length(vec(p1, p0)), b = length(vec(p2, p0)), c = length(vec(p2, p1));
	return area_triangle(a, b, c);
}
```


### Orientation of 3 points

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

### How to check if two given line segments intersect?

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
### Compute intersected rectangule between two Rectangules
```cpp
struct point
{
    int x,y;
};
int main()
{
    int t;cin>>t;while(t--)
    {
        point a,b,c,d,s,e;
        cin>>a.x>>a.y>>b.x>>b.y;
        cin>>c.x>>c.y>>d.x>>d.y;
        s.x = max(a.x,c.x);
        s.y = max(a.y,c.y);
        e.x = min(b.x,d.x);
        e.y = min(b.y,d.y);
        if(s.x>=e.x||s.y>=e.y)
            cout<<"No Overlap\n";
        else
            cout<<s.x<<' '<<s.y<<' '<<e.x<<' '<<e.y<<'\n';
        if(t)
            cout<<'\n';
    }
    return 0;
}
```
