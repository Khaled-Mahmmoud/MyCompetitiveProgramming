
```cpp
double toRadians(double degree) 
{
    const double PI = acos(-1.0);
    return (degree * PI) / 180.0;
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

**How to check if two given line segments intersect?**

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

[Problem Link](https://codeforces.com/gym/101350/problem/J)
[Solution Link](https://codeforces.com/gym/101350/submission/101374638)
