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
    for(int i=0;i<sz(points);i++)
        a += cross(points[i],points[(i+1)%sz(points)]);
    return fabs(a/2);
}
__Pick theorem__
// S = area, I = number of integer points strictly Inside, B = number of points on sides of polygon
// S = I + B/2 - 1
ll get_border_points(vector<point>P)
{
    int n = P.size();ll res = 0;
    for( int i = 0, j = n - 1; i < n; j = i++ )
            res += __gcd((ll)abs(P[i].X-P[j].X),(ll)abs(P[i].Y-P[j].Y));
    return res;
}
// I = (2*A - B + 2)/2
ll get_inside_points(vector<point>&points)
{
    return (2 * polygon_area(points) - get_border_points(points) + 2)/2;
}
__Polygon Volume__
double polygon_volume(vector<point>&points, double h)
{
    return polygon_area(points) * h;
}

__Regular Polygon Volume__
double rpolygon_volume(int n,double s,double h)
{
    // n-polygon, s: length of side, h: height of polygon
    return (1/4 * n * s * s * cot(PI/n) ) * h;
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

__Winding Number Algorithm__
// 2: onside, 1: inpolygon, 0: outpolygon
// https://open.kattis.com/submissions/6920809
int in_polygon(vector<point> &points,point p)
{
    double angles_sum = 0;
    for(int i=0;i<sz(points);i++)
    {
        point cur = points[i], nx = points[(i+1)%sz(points)];
        if(ccw(cur,nx,p)==0)
            return 2;
        angles_sum += dot_angle(vec(p,cur),vec(p,nx)) * ccw(p,cur,nx);
    }
    // Answer is either 0 (outside) or 2PI (inside)
    return fabs(angles_sum) > PI;
}// O(n)

__Point inConvex__
// is point p is strictly inside convex polygon 
// https://codeforces.com/contest/166/submission/108568041
bool in_convex(vector<point>& l, point p)
{
    int a = 1, b = l.size()-1, c;
    if (dcmp(cross(vec(l[0],l[a]),vec(l[0],l[b])), 0)== 1)
        swap(a,b);
    if (dcmp(cross(vec(l[0],l[a]),vec(l[0],p)), 0)!= -1 || dcmp(cross(vec(l[0],l[b]),vec(l[0],p)),0)!= 1)
        return false;
    while(abs(a-b) > 1)
    {
        c = (a+b)/2;
        if (dcmp(cross(vec(l[0],l[c]),vec(l[0],p)), 0)==1)
            b = c;
        else
            a = c;
    }
    return dcmp(cross(vec(l[a],l[b]),vec(l[a],p)), 0) == -1;
}// O(log n)
// is point p is inside convex polygon (on edge allowed)
bool in_convex(vector<point>& l, point p)
{
    int a = 1, b = l.size()-1, c;
    if (dcmp(cross(vec(l[0],l[a]),vec(l[0],l[b])), 0)==1)
        swap(a,b); 
    if (dcmp(cross(vec(l[0],l[a]),vec(l[0],p)),0)==1 || dcmp(cross(vec(l[0],l[b]),vec(l[0],p)), 0)==-1)
        return false;
    while(abs(a-b) > 1)
    {
        c = (a+b)/2;
        if (dcmp(cross(vec(l[0],l[c]),vec(l[0],p)), 0)==1)
            b = c;
        else
            a = c;
    }
    return dcmp(cross(vec(l[a],l[b]),vec(l[a],p)),0)!=1;
}
```
