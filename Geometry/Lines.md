```cpp
// check if point c on, above, below Line AB
void check_point_line(point a,point b,point c)
{
    int x = dcmp(cross(vec(a,c),vec(a,b)), 0);
    if(x==1)
        cout<<"below";
    else if(x==-1)
        cout<<"above";
    else
        cout<<"on line";
}
bool check_point_online(point a,point b,point c)
{
    return (dcmp(cross(vec(a,c),vec(a,b)), 0)==0);
}
// check if point c is on Ray AB
bool point_on_ray(point a,point b,point c)
{
    return (dcmp(cross(vec(a,c),vec(a,b)), 0) == 0 && dcmp(dot(vec(a,c),vec(a,b)), 0) == 1);
}
// check if point c is on Segment AP
bool point_on_segment(point a,point b,point c)
{
    if(dcmp(length(vec(a,b)), 0) == 0)
        return (dcmp(length(vec(a,c)), 0) == 0);
    return (point_on_ray(a,b,c) && point_on_ray(b,a,c));
}
// Point C distance to Line AB
// X = AC sin O = (AC AB sin O) / AB
double dist_to_line(point a,point b,point c)
{
    return fabs(cross(vec(a,c),vec(a,b))/dist(a,b));
}
// Point p2 distance to Segment p0-p1
// p4 is the nearest point to p2
double distToSegment(point p0, point p1, point p2, point& p4)
{
    point v1 = p1 - p0, v2 = p2 - p0;
    double d1 = dot(v1, v2);
    double d2 = dot(v1, v1);
    // d1 <= 0
    if (dcmp(d1,0)==-1||dcmp(d1,0)==0)
    {
        p4 = p0;
        return dist(p2 - p0);
    }
    // d2 <= d1
    if (dcmp(d1,d2)==-1||dcmp(d1,d2)==0)
    {
        p4 = p1;
        return dist(p2 - p1);
    }
    double t = d1 / d2;
    p4 = (p0 + v1 * t);  // this is point
    return dist(p2 - (p0 + v1 * t));
}
// is Line AB and Line CD is the Parallel
bool arelinesparallel(point a,point b,point c,point d)
{
    return dcmp(cross(vec(a,b),vec(c,d)), 0) == 0;
}
// is Line AB and Line CD is the Same
bool arelinesame(point a,point b,point c,point d)
{
    return (arelinesparallel(a,b,c,d) && check_point_online(a,b,c));
}
// rt = intersect point between two lines
// check if rt on line AB and CD to get intersect between two segments
bool intersect_line(point a,point b,point c,point d,point &rt)
{
    double d1 = cross(vec(a,b),vec(c,d)), d2 = cross(vec(c,a),vec(c,d));
    if(dcmp(fabs(d1),0)==0)
        return 0; // Parllel || Identical
    double t = -d2 / d1;
    rt = a + (b - a) * t;
    return true;
}
```
