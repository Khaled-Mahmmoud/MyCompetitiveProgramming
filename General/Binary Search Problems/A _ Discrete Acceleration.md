# Discrete Acceleration

[Problem Link](https://codeforces.com/contest/1408/problem/C)

```cpp
#define ll long long
const int N = 1e5 + 5;
int main()
{
    int t, n, l, a[N];
    cin >> t;
    while(t--)
    {
        cin >> n >> l;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        double low = 0, high = l, mid;
        for(int i = 0; i < 200; i++)
        {
            mid = (low + high) / 2;
            double x = 0, y = 0, s = 1, lst = 0;
            for(int i = 0; i < n; i++)
            {
                if(a[i] - mid > 1e-6)
                    break;
                x += (a[i] - lst) / s;
                s++, lst = a[i];
            }
            x += (mid - lst) / s;
            s = 1, lst = l;
            for(int i = n - 1; i >= 0; i--)
            {
                if(mid - a[i] > 1e-6)
                    break;
                y += (lst - a[i]) / s;
                s++, lst = a[i];
            }
            y += (lst - mid) / s;
            if(abs(x - y) < 1e-6)
            {
                cout << fixed << setprecision(9) << x << '\n';
                break;
            }
            else if(x - y > 1e-6)
                high = mid;
            else
                low = mid;
        }
    }
    return 0;
}
```
