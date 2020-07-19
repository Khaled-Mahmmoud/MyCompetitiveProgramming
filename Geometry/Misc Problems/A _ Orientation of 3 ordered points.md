# A Orientation of 3 ordered points

Orientation of an ordered triplet of points in the plane can be

1) clockwise
2) counterclockwise
3) colinear

The following [diagram](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Geometry/orientations.png) shows different possible orientations of (a, b, c)

If orientation of (p1, p2, p3) is collinear, then orientation of (p3, p2, p1) is also collinear.
    
If orientation of (p1, p2, p3) is clockwise, then orientation of (p3, p2, p1) is counterclockwise and vice versa 

Given three points p1, p2 and p3, find orientation of (p1, p2, p3).

Input:   p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 2}

Output:  CounterClockWise

Input:   p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 1}

Output:  Colinear

**How to compute Orientation?**

The idea is to use slope.  

Slope of line segment (p1, p2): σ = (y2 - y1)/(x2 - x1)
    
Slope of line segment (p2, p3): τ = (y3 - y2)/(x3 - x2)

If  σ > τ, the orientation is clockwise (right turn)

Using above values of σ and τ, we can conclude that, 
the orientation depends on sign of below expression: 

(y2 - y1)*(x3 - x2) - (y3 - y2)*(x2 - x1)

Above expression is negative when σ < τ, i.e.,  counterclockwise

```cpp
struct Point 
{ 
    int x, y; 
}; 
void orientation(Point p1, Point p2, Point p3) 
{ 
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y); 
  
    if (val == 0)
        cout<<"colinear";
    else if(val>0)
        cout<<"clockwise";
    else 
        cout<<"counterclockwise";
} 
int main() 
{ 
    Point p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 2}; 
    orientation(p1, p2, p3); 
    return 0; 
} 
```
Time complexity : O(1)
