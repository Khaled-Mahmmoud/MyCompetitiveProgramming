```cpp
#define point complex<double>
#define X real()
#define Y imag()
#define polar(r,t) ((r)*exp(point(0,(t))))
#define length(a) hypot((a).X,(a).Y)
#define angle(a) atan2((a).Y,(a).X)
```
