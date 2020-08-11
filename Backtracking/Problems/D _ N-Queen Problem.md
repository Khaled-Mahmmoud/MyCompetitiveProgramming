# N-Queen Problem

The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two 
queens attack each other

Solution :
Backtracking Algorithm
The idea is to place queens one by one in different columns, starting from the leftmost column
When we place a queen in a column , we check for clashes with already placed queens
In the current column, if we find a row for which there is no clash, we mark this 
row and column as part of the solution. If we do not find such a row due to clashes 
then we backtrack and return false

1) Start in the leftmost column
    
2) If all queens are placed
    return true
3) Try all rows in the current column.  Do following
   for every tried row.
    a) If the queen can be placed safely in this row
       then mark this [row, column] as part of the 
       solution and recursively check if placing  
       queen here leads to a solution.
    b) If placing queen in [row, column] leads to a
       solution then return true.
    c) If placing queen doesn't lead to a solution 
       then unmark this [row, column] (Backtrack) 
       and go to step (a) to try other rows.
3) If all rows have been tried and nothing worked, 
   return false to trigger backtracking

```cpp
int n;int board[10][10];
void print(int board[10][10])
{
    static int k = 1;
    cout<<k++<<'\n';
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<board[i][j]<<' ';
        cout<<'\n';
    }
    cout<<'\n';
}
bool save(int board[10][10],int row,int col)
{
    int i, j;
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;

    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}
bool solve(int board[10][10],int col)
{
    if(col == n)
    {
        print(board);
        return true;
    }
    bool res = false;
    for(int i=0;i<n;i++)
    {
        if(save(board,i,col))
        {
            board[i][col]=1;
            res = solve(board,col+1)||res;  // please remember that solve(..) before res
            board[i][col]=0;            // if we said res = res || solve(..) , this gives wrong answer
        }
    }
    return res;
}
int main()
{
    cin>>n;
    memset(board,0,sizeof(board));
    if(!solve(board,0))
        cout<<"Solution does not exist";
    return 0;
}
```
