```cpp
__Polygon__
// Internal angle for Regular Polygon = (n-2) * 180 / n
// number of diagonals of n-polygon = n * (n-3) / 2

__Simple Polygon__
bool is_simple_polygon(vector<point>&p)
{
    for(int i=0;i<sz(p)-1;i++)
       for(int j=i+2;j<sz(p)-1;j++)
          if(intersect(p[i],p[i+1],p[j],p[j+1])&&(i!=0||j!=sz(p)-2))
            return false;
    return true;
}

__Convex Polygon__
bool is_convex_polygon(vector<point>&p)
{
    p.push_back(p[0]),p.push_back(p[1]);
    int sign = ccw(p[0],p[1],p[2]);
    bool ok = true;
    for(int i=1;ok&&i<sz(p)-2;i++)
      if(ccw(p[i],p[i+1],p[i+2])!=sign)
        ok = false;
    p.pop_back(),p.pop_back();
    return ok;
}

__Polygon Area__
double polygon_area(vector<point>&points)
{
    double a = 0;
    for(int i=0;i<sz(point);i++)
        a += cross(points[i],points[(i+1)%sz(points)]);
    return fabs(a/2);
}

__Polygon Centroid__
point polygon_centeriod(vector<point> points)
{
    double x = 0, y = 0, c;
    for(int i=0;i<sz(points);i++)
    {
        int j = (i+1) % sz(points);
        c = cross(points[i], point[j]), a += c;
        x += (points[i].X + points[j].X) * c;
        y += (points[i].Y + points[j].Y) * c;
    }
    if(dcmp(a, 0)== 0)
        return (points[0] + points.back()) * 0.5;
    a /= 2, x /= 6*a, y /= 6*a;
    return point(x,y);
}

__Convex Polygon Cut__
// p need to be counterclockwise convex polygon
pair<vector<point>, vector<point>> polygon(vector<point> &p, point A, point B)
{
    vector<point> up, down;
    point intersect;
    for(int i=0;i<sz(p);i++)
    {
        point cur = p[i], nx = p[(i+1)%sz(p)];
        if(cross(vec(A,B),vec(A,cur))>=0)
            up.push_back(cur);
        if(intersect_segment(A,B,cur,nx,intersect))
        {
            up.push_back(intersect);
            down.push_back(intersect);
        }
        if(cross(vec(A,B),vec(A,cur))<=0)
            down.push_back(cur);
    }
    return make_pair(down,up);
}
```
