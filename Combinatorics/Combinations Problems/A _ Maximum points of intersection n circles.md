
# Maximum points of intersection n circles

Given a number n, we need to find the maximum number of times n circles intersect.


|Input |  Output |
|---|---|
|2|2|
|3|6|


**Description and Derivation**

As we can See in this [diagram](https://github.com/Khaled-Mahmmoud/MyCompetitiveProgramming/blob/master/img/Combinatorics/points%20of%20intersection%20n%20circles.jpg), for each pair of circles, there can be maximum two intersection points
Therefore if we have n circles then there can be nC2 pairs of circles in which each pair will have two intersections
So by this we can conclude that by looking at all possible pairs of circles the mathematical formula can be made for
the maximum number of intersection by n circles is given by `2 * nC2`.

`2 * nC2 = 2 * n * (n – 1)/2 = n * (n-1)`

```cpp
int intersection(int n) 
{ 
   return n * (n - 1); 
} 
  
int main() 
{ 
    cout << intersection(3) << endl; 
}
```
