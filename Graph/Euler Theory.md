# Euler Theory

[Euler Theory](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Graph/Theory%20Euler.pdf)

[Eulerian Path](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Graph/Eulerian%20path.png)

```cpp
vector<vector<int>>adj;
vector<int>tour;
int n,m;
void euler(int i)
{
    for(int i=1;i<=j;i++)
    {
        if(adj[i][j])
        {
            adj[i][j]--;
            adj[j][i]--;
            euler(j);
        }
        tour.push_back(i);
    }
}
```
