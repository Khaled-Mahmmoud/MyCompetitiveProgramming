/*

Pascal’s triangle is a triangular array of the binomial coefficients
Write a function that takes an integer value n as input and prints first n lines of the Pascal’s triangle
Following are the first 6 rows of Pascal’s Triangle

1  
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 

Method 1 ( O(n^3) time complexity )
Number of entries in every line is equal to line number
For example, the first line has “1”, the second line has “1 1”, the third line has “1 2 1”,.. and so on
Every entry in a line is value of a Binomial Coefficient. The value of ith entry in line number line is C(line, i)
The value can be calculated using following formula.

C(line, i)   = line! / ( (line-i)! * i! ) 
A simple method is to run two loops and calculate the value of Binomial Coefficient in inner loop

*/

int binomialCoeff(int n,int r)
{
    if(n<r)
    return 0;
    if(r == 0)
    return 1;
    return n * binomialCoeff(n-1,r-1) / r;
}
void printPascal(int n) 
{ 
    for (int line = 0; line < n; line++) 
    {  
        for (int i = 0; i <= line; i++) 
            printf("%d ", binomialCoeff(line, i)); 
        printf("\n"); 
    } 
} 

/*

Method 2( O(n^2) time and O(n^2) extra space )
If we take a closer at the triangle, we observe that every entry is sum of the two values above it
So we can create a 2D array that stores previously generated values. To generate a value in a line
we can use the previously stored values from array

*/

void printPascal(int n) 
{ 
    int arr[n][n];  
    for (int line = 0; line < n; line++) 
    {  
        for (int i = 0; i <= line; i++) 
        { 
            if (line == i || i == 0) 
                arr[line][i] = 1;  
            else
                arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i]; 
        cout << arr[line][i] << " "; 
        } 
        cout << "\n"; 
    } 
} 

/*

Method 3 ( O(n^2) time and O(1) extra space )
This method is based on method 1. We know that ith entry in a line number line is Binomial Coefficient C(line, i) 
and all lines start with value 1. The idea is to calculate C(line, i) using C(line, i-1)
It can be calculated in O(1) time using the following.

C(line, i)   = line! / ( (line - i)! * i! )
C(line, i-1) = line! / ( (line - i + 1)! * (i - 1)! )
We can derive following expression from above two expressions
C(line, i) = (line - i + 1) * line! / (line - i + 1) * (line - i)! * i!
C(line, i) = (line - i + 1) * line! / (line - i + 1)! * (i-1)! * i
C(line, i) = line! / ( (line - i + 1)! * (i-1)! )   *   (line - i + 1) / i

C(line, i) = C(line, i-1) * (line - i + 1) / i

So C(line, i) can be calculated from C(line, i-1) in O(1) time

*/

using namespace std; 
void printPascal(int n) 
{   
   for (int line = 1; line <= n; line++) 
    { 
       int C = 1; 
       for (int i = 1; i <= line; i++)  
        { 
           cout<< C<<" ";  
           C = C * (line - i) / i;  
        } 
        cout<<"\n"; 
   } 
} 
