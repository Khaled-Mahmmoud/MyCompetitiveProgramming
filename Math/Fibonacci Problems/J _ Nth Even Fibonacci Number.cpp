/*

Nth Even Fibonacci Number
Given a value n, find the n’th even Fibonacci Number

Input  : n  = 3
Output : 34

Input  : n  = 4
Output : 144

Input : n = 7
Output : 10946
The Fibonacci numbers are the numbers in the following integer sequence.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ….
where any number in sequence is given by:

 Fn = Fn-1 + Fn-2 
      with seed values
      F0 = 0 and F1 = 1

The even number Fibonacci sequence is, 0, 2, 8, 34, 144, 610, 2584…. We need to find n’th number in this sequence
If we take a closer look at Fibonacci sequence, we can notice that every third number in sequence is even 
and the sequence of even numbers follow following recursive formula

Recurrence for Even Fibonacci sequence is:
     EFn = 4EFn-1 + EFn-2
with seed values
     EF0 = 0 and EF1 = 2.

EFn represents n'th term in Even Fibonacci sequence.
How does above formula work?
Let us take a look original Fibonacci Formula and write it in the form of Fn-3 and Fn-6 
because of the fact that every third Fibinacci number is even

Fn = Fn-1 + Fn-2 [Expanding both terms]
   = Fn-2 + Fn-3 + Fn-3 + Fn-4 
   = Fn-2 + 2Fn-3 + Fn-4 [Expending first term]
   = Fn-3 + Fn-4 + 2Fn-3 + Fn-4
   = 3Fn-3 + 2Fn-4  [Expending one Fn-4]
   = 3Fn-3 + Fn-4 + Fn-5 + Fn-6 [Combing Fn-4 and Fn-5]
   = 4Fn-3 + Fn-6  

Since every third Fibonacci Number is even, So if Fn is 
even then Fn-3 is even and Fn-6 is also even. Let Fn be
xth even element and mark it as EFx.
If Fn is EFx, then Fn-3 is previous even number i.e. EFx-1
and Fn-6 is previous of EFx-1 i.e. EFx-2
So
Fn = 4Fn-3 + Fn-6
which means,
EFx = 4EFx-1 + EFx-2

*/

int dp[1000];
long int evenFib(int n) 
{ 
    if (n < 1) 
    return n; 
    if (n == 1)  
    return 2; 
    if(dp[n])
     return dp[n];
    return return dp[n] = ((4 * evenFib(n-1)) + evenFib(n-2));  
} 
int main () 
{ 
    int n = 7; 
    cout << evenFib(n);  
    return 0; 
} 
// Complexity : O(n)
