```cpp
#define point complex<double>
#define X real()
#define Y imag()
//Check if point c on, above, below Line AB
void check_point_line(point a,point b,point c)
{
    int x = dcmp(cross(c-a,c-b),0);
    if(x==1)
        cout<<"below";
    else if(x==-1)
        cout<<"above";
    else
        cout<<"on line";
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
