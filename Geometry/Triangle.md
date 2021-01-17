```cpp
// sin(A)/a = sin(B)/b = sin(C)/c
// a^2 = b^2 + c^2 - 2*b*c*cos(A)
// sin(A + B) = sin(A) cos(B) + sin(B) cos(A)
// sin(A - B) = sin(A) cos(B) - sin(B) cos(A)
// cos(A + B) = cos(A) cos(B) - sin(A) sin(B)
// cos(A - B) = cos(A) cos(B) + sin(A) sin(B)
// tan(A + B) = (tan A + tan B)/(1 - tan A tan B)
// tan(A - B) = (tan A - tan B)/(1 + tan A tan B)
double fixAngle(double A)
{
	return A > 1 ? 1 : (A < -1 ? -1 : A);
}
double getSide_a_bAB(double b, double A, double B) 
{
	return (sin(A) * b) / sin(B);
}
double getAngle_A_abB(double a, double b, double B) 
{
	return asin(fixAngle((a * sin(b)) / b));
}
double getAngle_A_abc(double a, double b, double c)
{
	return acos(fixAngle((b * b + c * c - a * a) / (2 * b * c)));
}
double perimeter_triangle(double a, double b, double c) 
{
	return a + b + c;
}
// a, b, c are sides of triangle
double area_triangle(double a, double b, double c) 
{
        if(a+b<=c||b+c<=a||a+c<=b)
            return -1;
	double s = 0.5 * perimeter_triangle(a, b, c);
	    return sqrt(s * (s - a) * (s - b) * (s - c));// Heron’s formula
}
// a, b, c are medians of triangle
double area_triangle1(double a, double b, double c) 
{
        if(a+b<=c||b+c<=a||a+c<=b)
            return -1;
	double s = 0.5 * perimeter_triangle(a, b, c);
	    return (4.0/3.0) * sqrt(s * (s - a) * (s - b) * (s - c));
}
// check whether point X lies inside the triangle abc
double area_triangle2(point a,point b,point c) 
{ 
   return abs((a.x*(b.y-c.y) + b.x*(c.y-a.y)+ c.x*(a.y-b.y))/2.0); 
   //OR return abs(a.x*(b.y-c.y) + b.x*(c.y-a.y)+ c.x*(a.y-b.y)); 
} 
bool isInside(point a,point b,point c,point x) 
{    
   double A  = area_triangle2(a,b,c); 
   double A1 = area_triangle2(x,a,b); 
   double A2 = area_triangle2(x,b,c); 
   double A3 = area_triangle2(x,a,c); 
   
   return (A == A1 + A2 + A3); 
}
```