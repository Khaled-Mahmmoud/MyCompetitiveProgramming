```CPP
/*
Diameter = 2 * Radius
Area of circle = PI * r^2
Circumference of a circle = 2 * PI * r
Length of an Arc = (n/360) * 2 * PI * r
Sector area = (n/360) * PI * r^2
(x-h)^2 + (y-k)^2 = r^2 where (h,k) is center, (x,y) any point in circle
*/
bool is_inside_circle(point center, point b, double r)
{
    double d1 = (b.X - center.X);
    double d2 = (b.Y - center.Y);
    return (d1 * d1 + d2 * d2) <= r * r;
}

/*
// cylinder
The surface area of cylinder consists of three parts:

the area of the top base: πr^2
the area of the bottom base: πr^2
the area of the side(lateral area): 2πrh (Circumference of the bottom base * height)

The surface area of cylinder = πr^2 + 2πrh + πr^2 = 2πrh + πr^2 = 2πr(h + r)
volume = πr^2 * h (Area of the bottom base * height)
*/
```
