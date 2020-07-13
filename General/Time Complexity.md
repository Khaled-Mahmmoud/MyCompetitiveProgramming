The efficiency of algorithms is important in competitive programming. 
Usually, it is easy to design an algorithm that solves the problem slowly
but the real challenge is to invent a fast algorithm.
If the algorithm is too slow, it will get only partial points or no points at all.
The time complexity of an algorithm estimates how much time the algorithm will use for some input.
The idea is to represent the efficiency as an function whose parameter is the maximum size of the input
By calculating the time complexity we can find out whether the algorithm is fast enough without implementing it.

**Calculation rules**

The time complexity of an algorithm is denoted O(···) where the three dots represent some function
O(n)   Usually, the variable n denotes the maximum size of the input.
For example, if the input is an array of numbers, n will be the size of the array
and if the input is a string, n will be the length of the string

**Loops**

A common reason why an algorithm is slow is that it contains many loops . The more nested loops the algorithm contains
the slower it is.
If there are k nested loops, the time complexity is O(n^k)

For example, the time complexity of the following code is O(n):
```cpp
for (int i = 1; i <= n; i++) {
// code
}
```
And the time complexity of the following code is O(n^2)
```cpp
for (int i = 1; i <= n; i++) {
     for (int j = 1; j <= n; j++) {
     // code
     }
}
```

**Order of magnitude**
A time complexity does not tell us the exact number of times the code inside a loop is executed
but it only shows the order of magnitude. In the following examples
the code inside the loop is executed [3n] ,[n+5] and [n/2] times, but the time complexity of each code is O(n)
```cpp
for (int i = 1; i <= 3*n; i++) {
// code
}
for (int i = 1; i <= n+5; i++) {
// code
}
for (int i = 1; i <= n; i += 2) {
// code
}
```
As another example, the time complexity of the following code is O(n^2)
```cpp
for (int i = 1; i <= n; i++) {
for (int j = i; j <= n; j++) {
// code
}
}
```

**Phases**

If the algorithm consists of consecutive phases, the total time complexity is the largest time complexity of a single phase.
The reason for this is that the slowest phase is usually the bottleneck of the code.
For example, the following code consists of three phases with time complexities O(n), O(n^2) and O(n)
Thus, the total time complexity is O(n^2)
```cpp
for (int i = 1; i <= n; i++) {
// code
}
for (int i = 1; i <= n; i++) {
for (int j = 1; j <= n; j++) {
// code
}
}
for (int i = 1; i <= n; i++) {
// code
}
```

**Several variables**
Sometimes the time complexity depends on several factors. In this case
the time complexity formula contains several variables.
For example, the time complexity of the following code is O(nm):
```cpp
for (int i = 1; i <= n; i++) {
   for (int j = 1; j <= m; j++) {
   // code
   }
}
```

**Recursion**
The time complexity of a recursive function depends on the number of times 
the function is called and the time complexity of 
a single call . The total time complexity is the product of these values.
For example, consider the following function:
```cpp
void f(int n) {
if (n == 1) return;
f(n-1);
}
```
The call f(n) causes n function calls, and the time complexity of each call is O(1).
Thus, the total time complexity is O(n).

As another example, consider the following function:
```cpp
void g(int n) {
if (n == 1) return;
g(n-1);
g(n-1);
}
```
In this case each function call generates two other calls, except for n = 1
Hence, the call g(n) causes the following calls:

|parameter|     number of calls|
|---|---|
|g(n)       |          1|
|g(n−1)    |           2|
|g(n-2) | 4|
|··· |···|
|g(1)    |            2^(n−1)|

Based on this, the time complexity is `1+2+4+··· +2^(n-1)  = O(2^n-1)`



**Complexity classes**
The following list contains common time complexities of algorithms
**O(1)**
constant time
The running time of a constant-time algorithm does not depend on the input size
A typical constant-time algorithm is a direct formula that calculates the answer
Ex. i++ , n = n*10 , ans += a + b 

**O(logn)**
logarithmic time 
 A logarithmic algorithm often halves the input size at each step. The running time of such an algorithm is logarithmic
 because log2 n equals the number of times n must be divided by 2 to get 1

**O(sqrt(n))**
square root time 
A square root algorithm is slower than O(logn) but faster than O(n)
A special property of square roots is that square(n) = n / square(n)

**O(n**
linear time 
algorithm goes through the input a constant number of times . This is often the best possible time complexity
because it is usually necessary to access each input element at least once before reporting the answer

**O(nlogn)**
linear logarithmic time 
This time complexity often indicates that the algorithm sorts the input
because the time complexity of efficient sorting algorithms is O(nlogn)
Another possibility is that the algorithm uses a data structure where each operation takes O(logn) 

**O(n^2)**
quadratic time 
A quadratic algorithm often contains two nested loops. It is possible to go through all pairs of the input elements in O(n^2)

**O(n^3)**
cubic time 
 A cubic algorithm often contains three nested loops. It is possible to go through all triplets of the input elements in O(n^3)
 
**O(2^n)**
exponential time
This time complexity often indicates that the algorithm iterates through all subsets of the input elements. 
For example, the subsets of {1,2,3} are ; Φ , {1}, {2}, {3}, {1,2}, {1,3}, {2,3} and {1,2,3}

 **O(n!)**
 factorial time	
 This time complexity often indicates that the algorithm iterates through all permutations of the input elements
 For example, the permutations of {1,2,3} are (1,2,3), (1,3,2), (2,1,3), (2,3,1), (3,1,2) and (3,2,1)

An algorithm is polynomial if its time complexity is at most O(n^k) k is a constant
Polynomial time :: n , log n , sqrt(n) , n^2  , n^3
Exponential time	       :: 2^Poly(n)    ==>> 2^n , 2^(n^2) 
Double exponential time	 :: 2^2^poly(n)  ==>> 2^2^n

2^(log n) ===>> Polynomial time
