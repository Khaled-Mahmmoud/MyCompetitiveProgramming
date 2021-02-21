```cpp
//Check if point c on, above, below Line AB
void check_point_line(point a,point b,point c)
{
    int x = dcmp(cross(c - a, b - a),0);
    if(x==1)
        cout<<"below";
    else if(x==-1)
        cout<<"above";
    else
        cout<<"on line";
}
// check if point c is on Ray AB
bool point_on_ray(point a,point b,point c)
{
    return (dcmp(cross(vec(a,b),vec(a,c)),0)==0&&dcmp(dot(vec(a,b),vec(a,c)),0)==1);
}
// check if point c is on Segment AP
bool point_on_segment(point a,point b,point c)
{
    if(dcmp(length(vec(a,b)),0)==0)
        return (dcmp(length(vec(a,c)),0)==0);
    return (point_on_ray(a,b,c)&&point_on_ray(b,a,c));
}
// Point C distance to Line AB
// X = AC sin O = (AB AC sin O) / AB
double dist_to_line(point a,point b,point c)
{
    return fabs(cross(vec(a,b),vec(a,c))/dist(a,b));
}
// is Line AB and Line CD is the Same
bool arelinesame(point a,point b,point c,point d)
{
    return (cross(a-c,d-c)==0&&cross(b-c,d-c)==0);
}
// is Line AB and Line CD is the Parallel
bool arelinesparallel(point a,point b,point c,point d)
{
    return cross(b-a,d-c)==0;
}
// rt = intersect point between two lines
// check if rt on line AB and CD to get intersect between two segments
bool intersect(point a,point b,point c,point d,point &rt)
{
    double d1 = cross(vec(a,c),vec(a,b));
    double d2 = cross(vec(a,d),vec(a,b));
    rt = (d1*d - d2*c)/(d1-d2);
    return (dcmp(fabs(d1 - d2),0) == 1);
}
```
