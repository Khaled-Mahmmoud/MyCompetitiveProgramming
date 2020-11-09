# Euler Theory

[Euler's theorem](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Graph/Euler's%20theorem.pdf)

```cpp
vector<vector<int>>adj;
vector<int>tour;
int n,m;
void euler(int i)
{
    for(int j=1;j<=n;j++)
    {
        if(adj[i][j]) // this condtion for self loops
        {
            adj[i][j]--;
            adj[j][i]--;
            euler(j);
        }
    }
    tour.push_back(i);
}
// this code don't work with multiple edges
```
