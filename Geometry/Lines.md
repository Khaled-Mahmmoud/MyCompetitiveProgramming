```cpp
__Line Equations__
/*
Type
Explicit 2D : f(x) = y = mx + b where m = ∆y/∆x   // a non-vertical 2D line
Implicit 2D : f(x,y) = ax + by + c = 0   // any 2D line
Parametric  : P(t) = P0 + t (p1 - p0)  where t = vec(p0,ps)/vec(p0,p1) // any line in any dimension
*/
__Point Related toLine__
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

__Point onLine__
bool check_point_online(point a,point b,point c)
{
    return (dcmp(cross(vec(a,c),vec(a,b)), 0)==0);
}

__Point onRay__
bool point_on_ray(point a,point b,point c)
{
    return (dcmp(cross(vec(a,c),vec(a,b)), 0) == 0 && dcmp(dot(vec(a,c),vec(a,b)), 0) == 1);
}

__Point onSegment__
bool point_on_segment(point a,point b,point c)
{
    if(dcmp(length(vec(a,b)), 0) == 0)
        return (dcmp(length(vec(a,c)), 0) == 0);
    return (point_on_ray(a,b,c) && point_on_ray(b,a,c));
}

___Point distance toLine__
// AB line and C point: X = AC sin O = (AC AB sin O) / AB  
double dist_to_line(point a,point b,point c)
{
    return fabs(cross(vec(a,c),vec(a,b))/dist(a,b));
}

___Point distance toSegment__
// Point p2 distance to Segment p0-p1 and p4 is the nearest point to p2
double distToSegment(point p0, point p1, point p2, point& p4) {
	double d1, d2;
	point v1 = p1 - p0, v2 = p2 - p0;
	if ((d1 = dot(v1, v2)) <= 0) {
		p4 = p0;
		return dist(p2 , p0);
	}
	if ((d2 = dot(v1, v1)) <= d1) {
		p4 = p1;
		return dist(p2 , p1);
	}
	double t = d1 / d2;
	p4 = (p0 + v1 * t);  // this is point
	return dist(p2 , (p0 + v1 * t));
}

__Two Lines Parallel__
// is Line AB and Line CD is the Parallel
bool arelinesparallel(point a,point b,point c,point d)
{
    return dcmp(cross(vec(a,b),vec(c,d)), 0) == 0;
}

__Two Lines Same__
// is Line AB and Line CD is the Same
bool arelinesame(point a,point b,point c,point d)
{
    return (arelinesparallel(a,b,c,d) && check_point_online(a,b,c));
}

__Intersect Point__
// rt = intersect point between two lines
bool intersect_line(point a,point b,point c,point d,point &rt)
{
    double d1 = cross(vec(a,b),vec(c,d)), d2 = cross(vec(c,a),vec(c,d)),d3 = cross(vec(a,b),vec(c,a));
    if(fabs(d1) < EPS)
        return 0; // Parllel || Identical
    double t = -d2 / d1, t1 = d3 / d1;
    rt = a + (b - a) * t;
    if (t < -EPS || t1 < -EPS || t1 > 1 + EPS)
		return false;  //e.g ab is ray, cd is segment ... change to whatever
    return true;
}

// not use above code to check if two segment intersect because debug with
// this cases: line1(0,0,1,1),line2(1,1,2,2) and line1(0,0,1,1),line2(2,2,3,3)
// you have to use below code to check if two segment intersect
// and above code to find intersect point

__Counterclockwise Test__
/*
Where is c relative to segment a-b?
ccw = +1 => angle > 0 or collinear after b 
point c is counter-clockwise about segment a-b
cw = -1 => angle < 0 or collinear after a
point c is clockwise about segment a-b
Undefined = 0 => Collinar in range [a, b]. Be careful here
*/
int ccw(point a, point b, point c)
{
    point v1(b - a), v2(c - a);
    double t = cross(v1, v2);

    if (t > +EPS)
        return 1;
    if (t < -EPS)
        return -1;
    if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
        return -1;
    if (norm(v1) < norm(v2) - EPS)
        return +1;
    return 0;
}
__Intersect Segment__
bool intersect_segment(point p1, point p2, point p3, point p4)
{
    // special case handling if a segment is just a point
    bool x = (p1 == p2), y = (p3 == p4);
    if (x && y)
        return p1 == p3;
    if (x)
        return ccw(p3, p4, p1) == 0;
    if (y)
        return ccw(p1, p2, p3) == 0;

    return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}
```
