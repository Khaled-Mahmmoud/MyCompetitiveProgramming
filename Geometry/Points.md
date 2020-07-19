# Points

r = 75;

theta = 45;

Convert polar coordinates  to cartesian coordinates 

See this [diagram](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Geometry/polar%20coordinate.png)

x = r * cos(theta);
 
y = r * sin(theta);
 
r = sqrt(x^2  + y^2);

O = tan^-1 (y/x);

**Rotatet**

x_  = cos(O) -sin(O) * x

y_  = sin(O) - cos(O) * y
