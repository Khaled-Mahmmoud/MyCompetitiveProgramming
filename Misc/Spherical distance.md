```cpp
// Spherical distance between two points on Earth
/*
we need to have the co-ordinates of point A and point B. convert the latitude 
and longitude values from decimal degrees to radians.	
*/	
#define R 6378	
double spherical_distance(double lat1,double lon1,double lat2,double lon2)	
{	
    double dlon, dlat, a, c, d;	
    dlon = lon2 - lon1;	
    dlat = lat2 - lat1;	
    a = pow((sin(dlat/2)),2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2);	
    c = 2 * atan2(sqrt(a), sqrt(1-a));	
    d = R * c;	
    return d;	
}
```
