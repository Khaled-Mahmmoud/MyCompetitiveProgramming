/*

Find sum of modulo K of first N natural number
Given two integer N ans K, the task is to find sum of modulo K of first N natural numbers i.e 1%K + 2%K + ….. + N%K.

Examples :

Input : N = 10 and K = 2.
Output : 5
Sum = 1%2 + 2%2 + 3%2 + 4%2 + 5%2 + 6%2 + 7%2 + 8%2 + 9%2 + 10%2
   = 1 + 0 + 1 + 0 + 1 + 0 + 1 + 0 + 1 + 0 = 5

Method 1:
Iterate a variable i from 1 to N, evaluate and add i%K
Time Complexity : O(N)

Method 2 :
Two cases arise in this method.

Case 1: When N < K, for each number i, N >= i >= 1, will give i as result when operate with modulo K
So, the required sum will be the sum of the first N natural number, N*(N+1)/2.

Case 2: When N >= K, then integers from 1 to K in natural number sequence will produce, 1, 2, 3, ….., K – 1, 0 
as result when operate with modulo K. Similarly, from K + 1 to 2K, it will produce same result
So, the idea is to count how many numbers of times this sequence appears and multiply it with 
the sum of first K – 1 natural numbers

*/

int findSum(int N, int K) 
{ 
    int ans = 0; 
    int y = N / K; 
    int x = N % K; 
    ans = (K * (K - 1) / 2) * y + (x * (x + 1)) / 2; 
  
    return ans; 
} 
int main() 
{ 
    int N = 10, K = 2; 
    cout << findSum(N, K) << endl; 
    return 0; 
} 
/*
Output :
5
Time Complexity : O(1)
