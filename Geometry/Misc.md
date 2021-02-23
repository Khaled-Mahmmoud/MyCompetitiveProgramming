```cpp
struct point {
	double a, b;
	point():a(0),b(0){}
	point(double a_,double b_):a(a_),b(b_) {}
};
struct line {
    point a, b;
    line():a(point(0,0)),b(point(0,0)){}
    line(point a_,point b_):a(a_),b(b_) {}
};
/*
Polar System , Cartesian System
x = r * cos(O)
y = r * sin(O)
r = sqrt(x^2 + y^2)
O = atan2(y,x)

Complex number with Catresian System : X + i Y
Complex number with Polar System : R(cos(O) + i sin(O)) = R e^(i O)
*/

/*
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
