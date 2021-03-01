```cpp
// Check if 4 points is Square
bool is_square(vector<point> p)
{
    map<Double,vector<pair<int, int>>> mp;
    for(int i = 0; i < (int)p.size(); ++i)
        for(int j = i+1; j < (int)p.size(); ++j)
        {
            Double len(dist(p[i],p[j]));
            mp[len].push_back({i, j});
        }
    if(mp.size() != 2)
        return false;
    auto S = mp.begin();// side
    auto D = mp.begin(); // Diagonal
    ++D;
    if(S->Y.size() != 4 || D->Y.size() != 2)
        return false;
}
```
