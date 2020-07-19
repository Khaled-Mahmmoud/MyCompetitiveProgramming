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
