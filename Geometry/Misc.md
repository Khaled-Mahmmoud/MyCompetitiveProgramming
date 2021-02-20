```cpp
#define PI acos(-1.0)
#define EPS 1e-9
int dcmp(double x, double y) {return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;}
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
```
