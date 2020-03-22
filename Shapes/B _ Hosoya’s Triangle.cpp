/*

Hosoya’s Triangle
The Fibonnaci triangle or Hosoya’s triangle is a triangular arrangement of numbers based on Fibonacci numbers
Each number is the sum of two numbers above in either the left diagonal or the right diagonal. The first few rows are:

                1
              1   1
            2   1   2
          3   2   2   3
        5   3   4   3   4
      8   5   6   6   5   8
    13  8   10  9   10  8   13
  21  13  16  15  15  16  13  21
34  21  26  24  25  24  26  21  34

The numbers in this triangle follow the recurrence relations
The entries in the triangle satisfy the identity
Thus, the two outermost diagonals are the Fibonacci numbers
while the numbers on the middle vertical lines are the squares of the Fibonacci numbers
All the other numbers in the triangle are the product of two distinct Fibonacci numbers greater than 1
The row sums are the first convolved Fibonnaci numbers

Given a positive integers n. The task is print Hosoya’s triangle of size n

Input : n = 4
Output :
1
1 1
2 1 2
3 2 2 3

Input : n = 5
Output :
1
1 1
2 1 2
3 2 2 3
5 3 4 3 5

*/

#define N 5 
int Hosoya(int n, int m) 
{ 
    if(dp[n][m])
         return dp[n][m];
    if (n > m) 
        return dp[n][m] = Hosoya(n - 1, m) + Hosoya(n - 2, m); 
  
    else if (m == n) return dp[n][m] = Hosoya(n - 1, m - 1)  + Hosoya(n - 2, m - 2); 
  
    else
        return dp[n][m] = 0; 
} 
void printHosoya(int n) 
{ 
    dp[0][0] = dp[1][0] = dp[1][1] = dp[2][1] = 1;
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j <= i; j++)  
            cout << Hosoya(i, j) << " ";      
  
        cout << endl; 
    } 
} 
/*
Output :
1 
1 1 
2 1 2 
3 2 2 3 
5 3 4 3 5 
