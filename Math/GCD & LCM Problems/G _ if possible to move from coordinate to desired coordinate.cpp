/*
Check if possible to move from given coordinate to desired coordinate
Given two coordinates (x, y) and (a, b). Find if it is possible to reach (x, y) from (a, b).
Only possible moves from any coordinate (i, j) are
(i-j, j)
(i, i-j)
(i+j, j)
(i, i+j)
Given x, y, a, b can be negative.
Input : (x, y) = (1, 1) and  (a, b) = (2, 3).
Output : Yes.
(1, 1) -> (2, 1) -> (2, 3).
Input : (x, y) = (2, 1) and  (a, b) = (2, 3).
Output : Yes.
Input : (x, y) = (35, 15) and  (a, b) = (20, 25).
Output : Yes.
(35, 15) -> (20, 15) -> (5, 15) -> (5, 10) -> (5, 5) ->
(10, 5) -> (15, 5) -> (20, 5) -> (20, 25)
If we take a closer look at the problem
we can notice that the moves are similar steps of Euclidean algorithm for finding GCD
So, it is only possible to reach coordinate (a, b) from (x, y) if GCD of x, y is equal to GCD of a, b
Otherwise, it is not possible.
Let GCD of (x, y) be gcd. From (x, y), we can reach (gcd, gcd) and from this point
we can reach to (a, b) if and only if GCD of ‘a’ and ‘b’ is also gcd.
*/

  
bool ispossible(int x, int y, int a, int b) 
{ 
    x = abs(x), y = abs(y), a = abs(a), b = abs(b); 
    return (gcd(x, y) == gcd(a, b)); 
} 
int main() 
{ 
    int x = 35, y = 15; 
    int a = 20, b = 25; 
    (ispossible(x, y, a, b)) ? (cout << "Yes") : (cout << "No"); 
    return 0; 
} 
