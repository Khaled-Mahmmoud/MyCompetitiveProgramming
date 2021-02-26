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

__Winding Number Algorithm__
bool is_inside_polygon(vector<point> &points,point p)
{
    double angles_sum = 0;
    for(int i=0;i<sz(points);i++)
    {
        point cur = points[i], nx = points[(i+1)%sz(points)];
        if(ccw(cur,nx,p)==0)
            return true;
        angles_sum += dot_angle(cur,p,nx) * ccw(p,cur,nx);
    }
    // Answer is either 0 (outside) or 2PI (inside)
    return fabs(angles_sum) > PI;
}// O(n)
// Equivalent Approach
bool is_inside_polygon(vector<point> &points,point p)
{
    int wn = 0;
    for(int i=0;i<sz(points);i++)
    {
        point cur = points[i], nx = points[(i+1)%sz(points)];
        if(point_on_segment(cur,nxt,p))
            return true;
        if(cur.Y<=p.Y)
        {
            if(nx.Y>p.Y&&cross(vec(cur,nx),vec(cur,p)) > EPS)
                ++wn;
        }
        else
        {
            if(nx.Y <= p.Y&&cross(vec(cur,nx),vec(cur,p)) < -EPS)
                ++wn;
        }
    }
    return wn != 0;
}// O(n)

__Point inConvex__
// is point p is strictly inside convex polygon
bool in_convex(vector<point>& l, point p)
{
    int a = 1, b = l.size()-1, c;
    if (cross(vec(l[0],l[a]),vec(l[0],l[b])) > 0)
        swap(a,b);
    if (cross(vec(l[0],l[a]),vec(l[0],p)) >= 0 || cross(vec(l[0],l[b]),vec(l[0],p)) <= 0)
        return false;
    while(abs(a-b) > 1)
    {
        c = (a+b)/2;
        if (cross(vec(l[0],l[c]),vec(l[0],p)) > 0)
            b = c;
        else
            a = c;
    }
    return cross(vec(l[a],l[b]),vec(l[a],p)) < 0;
}// O(log n)
```
