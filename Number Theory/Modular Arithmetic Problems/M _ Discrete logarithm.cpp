/*
Discrete logarithm
Given three integers a, b and m. Find an integer k such that 
a^k = b (mod m) then k is discrete logarithm of m
where a and m are relatively prime. If it is not possible for any k to satisfy this relation, print -1

Input: 2 3 5
Output: 3

Explanation:
a = 2, b = 3, m = 5

The value which satisfies the above equation
is 3, because 

=> 23 = 2 * 2 * 2 = 8
=> 23 (mod 5) = 8 (mod 5) 
=> 3
which is equal to b i.e., 3

Input: 3 7 11
Output: -1

A Naive approach is to run a loop from 0 to m to cover all possible values of k and check for which value of k
the above relation satisfies. If all the values of k exhausted, print -1. Time complexity of thuis approach is O(m)

An efficient approach is to use baby-step, giant-step algorithm by using meet in the middle trick

Baby-step giant-step algorithm 
First of all we have to write k = i * n - j
where n = sqrt{m} and 0 <= i,j < n 

Replace the ‘k’ in above equality, we get
a^k = b (mod m)
a^{i * n - j} = b (mod m)
a^{i * n} = a^j * b (mod m)

*/

int powmod(int x, int y, int p) 
{ 
    int res = 1; 
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
      
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
int discreteLogarithm(int a, int b, int m)
{ 
    int n = (int) sqrt (m) + 1; 
    unordered_map<int, int> value; 
  
    for (int i = n; i >= 1; --i) 
        value[ powmod (a, i * n, m) ] = i; 
  
    for (int j = 0; j < n; ++j) 
    { 
        int cur = (powmod (a, j, m) * b) % m; 
        if (value[cur]) 
        { 
            int ans = value[cur] * n - j; 
            if (ans < m) 
                return ans; 
        } 
    } 
    return -1; 
} 
int main() 
{ 
    int a = 2, b = 3, m = 5; 
    cout << discreteLogarithm(a, b, m) << endl; 
} 

/*
Time complexity: O(sqrt(m)*log(b))
Auxiliary space: O(sqrt(m))

A possible improvement is to get rid of binary exponentiation or log(b) factor in the second phase of the algorithm
This can be done by keeping a variable that multiplies by ‘a’ each time as ‘an’. Let’s see the program to understand more.

*/

int discreteLogarithm(int a, int b, int m)  
{ 
    int n = (int) sqrt (m) + 1; 
    int an = 1; 
    for (int i = 0; i<n; ++i) 
        an = (an * a) % m; 
  
    unordered_map<int, int> value; 
    for (int i = 1, cur = an; i<= n; ++i) 
    { 
        if (! value[ cur ]) 
            value[ cur ] = i; 
        cur = (cur * an) % m; 
    } 
  
    for (int i = 0, cur = b; i<= n; ++i) 
    { 
        if (value[cur]) 
        { 
            int ans = value[cur] * n - i; 
            if (ans < m) 
                return ans; 
        } 
        cur = (cur * a) % m; 
    } 
    return -1; 
} 
int main() 
{ 
    int a = 2, b = 3, m = 5; 
    cout << discreteLogarithm(a, b, m) << endl; 
} 
/*
Time complexity: O(sqrt(m))
Auxiliary space: O(sqrt(m))
