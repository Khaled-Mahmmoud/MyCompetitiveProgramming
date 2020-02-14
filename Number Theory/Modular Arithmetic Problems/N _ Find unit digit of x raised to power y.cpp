/*

Find unit digit of x raised to power y
Given two numbers x and y, find unit digit of xy.

Input  : x = 2, y = 1
Output : 2
Explanation
2^1 = 2 so units digit is 2.

Input : x = 4, y = 2
Output : 6
Explanation
4^2 = 16 so units digit is 6.


Method 1 (Simple) Compute value of xy and find its last digit
This method causes overflow for slightly larger values of x and y.

Method 2 (Efficient)
1) Find last digit of x.
2) Compute x^y under modulo 10 and return its value.

*/


int unitDigitXRaisedY(int x, int y) 
{  
    int res = 1; 
    for (int i = 0; i < y; i++) 
        res = (res * x) % 10; 
  
    return res; 
} 
  
/*

Further Optimizations: We can compute modular power in Log y.

Method 3 (Direct based on cyclic nature of last digit)
This method depends on the cyclicity with the last digit of x that is

x   |  power 2  |  power 3  |   power 4  | Cyclicity  
0   | .................................. |  .... repeat with 0
1   | .................................. |  .... repeat with 1
2   |     4     |     8     |      6     | .... repeat with 2
3   |     9     |     7     |      1     | .... repeat with 3
4   |     6     |....................... |  .... repeat with 4
5   | .................................. |  .... repeat with 5
6   | .................................. |  .... repeat with 6
7   |     9     |     3     |      1     | .... repeat with 7
8   |     4     |     2     |      6     | .... repeat with 8
9   |     1     | ...................... |  .... repeat with 9 
So here we directly mod the power y with 4 because this is the last power after this all number’s repetition start
after this we simply power with number x last digit then we get the unit digit of produced number.

*/

int unitnumber(int x, int y) 
{ 
    x = x % 10; 
    if(y!=0) 
        y = y % 4 + 4; 
    return (((int)(pow(x, y))) % 10); 
} 
