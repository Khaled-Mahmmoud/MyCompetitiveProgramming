/*

Maximum points of intersection n circles
Given a number n, we need to find the maximum number of times n circles intersect.

Examples:

Input :  n = 2
Output : 2

Input :  n = 3
Output : 6


Description and Derivation
As we can see in above diagram, for each pair of circles, there can be maximum two intersection points
Therefore if we have n circles then there can be nC2 pairs of circles in which each pair will have two intersections
So by this we can conclude that by looking at all possible pairs of circles the mathematical formula can be made for
the maximum number of intersection by n circles is given by 2 * nC2.

2 * nC2 = 2 * n * (n – 1)/2 = n * (n-1)

*/

#include <bits/stdc++.h> 
using namespace std; 
int intersection(int n) 
{ 
   return n * (n - 1); 
} 
  
int main() 
{ 
    cout << intersection(3) << endl; 
}
