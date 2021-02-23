```cpp
// Internal angle for Regular Polygon = (n-2) * 180 / n
// number of diagonals of n-polygon = n * (n-3) / 2
bool is_simple_polygon(vector<point>&p)
{
    for(int i=0;i<sz(p)-1;i++)
       for(int j=i+2;j<sz(p)-1;j++)
          if(intersect(p[i],p[i+1],p[j],p[j+1])&&(i!=0||j!=sz(p)-2))
            return false;
    return true;
}

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
```
