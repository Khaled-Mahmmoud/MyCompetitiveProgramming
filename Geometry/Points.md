# Points

r = 75;

theta = 45;

Convert polar coordinates  to cartesian coordinates 

See this [diagram](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Geometry/polar%20coordinate.png)

x = r * cos(theta);
 
y = r * sin(theta);
 
r = sqrt(x^2  + y^2);

theta = tan^-1 (y/x);

**Rotatet**

x_  = cos(theta) - sin(theta) * x

y_  = sin(theta) - cos(theta) * y

Two vectors are perpendicular if and only if their angle is a right angle

A . B = |A| |B| cos(theta) = x1*x2 + y1*y2

if A and B are orthogonal, then the angle between them is 90  A.B = 0

if they are codirectional, then the angle between them is 0   A.B = |A| |B|

if (theta)  > 90 then A.B <0  and if(theta) < 90 then A.B > 0 if (theta) = 90 the A.B = 0

**convert degree to radian**
```cpp
double toRadian(double degree) 
{
   	return (degree * PI) / 180.0;
}
```

**Check is a point (x,y) is between two points drawn on a straight line (x1,y1) , (x2,y2)?**

point is between tow points if (y1-y)/(x1-x) = (y2-y) / (x2-x)
