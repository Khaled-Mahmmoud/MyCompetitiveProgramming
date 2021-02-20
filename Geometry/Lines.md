```cpp
#define point complex<double>
#define X real()
#define Y imag()
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
double dist_to_line(point a,point b,point c)
{
    double d = cross(b-a,c-a)/dist(a,b);
    return fabs(d);
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
```
