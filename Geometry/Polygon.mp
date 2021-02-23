```cpp
bool is_simple_polygon(vector<point>&p)
{
    for(int i=0;i<sz(p)-1;i++)
       for(int j=i+2;j<sz(p)-1;j++)
          if(intersect(p[i],p[i+1],p[j],p[j+1])&&(i!=0||j!=sz(p)-2))
            return false;
    return true;
}
```
