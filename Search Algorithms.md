```cpp
int binary_search()
{
    int l = 0, r = 1e9;
    int ans = l;
    while (l <= r)
    {
        int mid = l + (r-l) / 2;

        if (valid(mid))
            l = mid + 1,ans = mid;
        else
            r = mid - 1;
    }
    return ans;
}
double binary_search(double l,double r)
{
    double ans = l;
    for (int i = 0; i < 100; ++i)
    {
        double mid = l + (r-l) / 2;

        if (valid(mid))
            l = mid,ans = l;
        else
            r = mid;
    }
    return ans;
}
// while (r - l > 1e-9)  // somtimes give us time limited
// better than above : while (r-l > 1e-6)
// better than above : for (int i = 0; i < 100; ++i) 
    
// Ternary search to find an interger local minimum
int ternary_search()	
{	
    int l = 0, r = 1e6;	   
    while(r - l > 10)	
    {	    
        int mid1 = l + (r - l) / 3;	        
        int mid2 = r - (r - l) / 3;	       
        if (calc(mid1) < calc(mid2))	       
            r = mid2;	           
        else	       
            l = mid1;	            
    }	    
    int pos, val = 1e9;	
    for (int i = l; i <= r; ++i)	
    {	
        int tmp = calc(i);	
        if(val > tmp)	
        {	
            val = tmp;	
            pos = i;	
        }	
    }	
    return pos;	
}
// Ternary search on to find a real (floating) local minimum
double ternary_search(double l,double r)
{
    for (int i = 0; i < 100; ++i)
    {
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        
        if(f(mid1) < f(mid2))
            r = mid2;
        else
            l = mid1;
    }
    return f(l);                   
}
```
