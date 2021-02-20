```cpp
#define PI acos(-1.0)
#define EPS 1e-9
int dcmp(double x, double y) {return fabs(x - y) <= EPS ? 0 : x > y ? 1 : -1;}
/*
Polar System , Cartesian System
x = r * cos(O)
y = r * sin(O)
r = sqrt(x^2 + y^2)
O = atan2(y,x)

Complex number with Catresian System : X + i Y
Complex number with Polar System : R(cos(O) + i sin(O)) = R e^(i O)

// Angles
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

// Check if 4 points is Square
bool is_square(vector<point> p)
{
    map<Double,vector<pair<int, int>>> mp;
    for(int i = 0; i < (int)p.size(); ++i)
        for(int j = i+1; j < (int)p.size(); ++j)
        {
            Double len(dist(p[i],p[j]));
            mp[len].push_back({i, j});
        }
    if(mp.size() != 2)
        return false;
    auto S = mp.begin();// side
    auto D = mp.begin(); // Diagonal
    ++D;
    if(S->Y.size() != 4 || D->Y.size() != 2)
        return false;
}
```
