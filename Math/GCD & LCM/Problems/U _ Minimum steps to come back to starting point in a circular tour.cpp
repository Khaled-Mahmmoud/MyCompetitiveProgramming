/*
Consider circular track with n points marked as 1, 2, …n. A person is initially placed on point k
The person moves m > 0, slot forward (in circular way) in each step
Find the minimum number of steps required so that the person reaches initial point k.

Input : n = 9, k = 2, m = 6 
Output : 3
Explanation : Sequence of moves is
 2 => 8 => 5 => 2

Input : n = 6, k = 3, m = 2 
Output : 3

Naive Approach : Initialize a counter ‘i’ with ‘k’ and ‘count’ = 0
Further for each iteration increment ‘count’ add ‘m’ to ‘i’. Take its modulus with n i.e. i=((i+m)%n), if i > n
If i becomes equal to k then count will be our answer.
Time complexity: O(n). 

Efficient Approach: We find GCD(n, m) and then divide n by GCD(n, m). That will be our answer
This can be explained as : Think of n and m as per question now as we know that gcd(n, m) must divide n 
and the quotient tells us that after how many successive jumps(addition) of m numbers from starting position(say 0)
we again reach the starting position.
Note: In circular arrangement of n numbers nth and 0th position are same.

*/

int minStroke(int n, int m) 
{ 
    return (n/__gcd(n, m)); 
} 
int main() 
{ 
    int n = 12, k = 5, m = 8; 
    cout << minStroke(n, m); 
    return 0; 
} 
//  Time Complexity: O(log(n))
