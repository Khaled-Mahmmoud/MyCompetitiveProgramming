/*

We are given a variable n, we need to find whether Fibonacci number will be multiple of 10 or not.

Input : 15
Output : Yes

Input : 17
Output : No

A Simple Method is to find nth Fibonacci number and check if it is divisible by 10 or not.

Efficient Method :

The above solution may not work if n is very large, then it is not possible to find fibonacci number
Moreover, we can check without finding fibonacci number by looking on the pattern. Let’s see how !

If number is divisible by 10, then it must have to be divisible by 5 and 2 both.

Multiples of 2 in Fibonacci Series :
      _     _       _         _           _             _
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 ….
On careful observation, we finds that every 3rd number is divisible by 2.

Multiples of 5 in Fibonacci Series :
          _            _                  _
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 ……
On careful observation, we find that every 5-th number is divisible by 5.

Now LCM of 3 and 5 is 15. So, every 15-th Fibonacci number will be divisible by 10
So, we don’t need to find Fibonacci number, just we have to check if n is divisible by 15 or not

*/

bool isMultipleOf10(int n) 
{ 
    return  (n % 15 == 0); 
} 
  
int main() 
{ 
    int n = 30; 
    if (isMultipleOf10(n)) 
        printf("Yes\n"); 
    else
        printf("No\n"); 
    return 0; 
} 

/*
Factors of Fibonacci number : On careful observation, we can observe the following thing :

Every 3-rd Fibonacci number is a multiple of 2
Every 4-th Fibonacci number is a multiple of 3
Every 5-th Fibonacci number is a multiple of 5
Every 6-th Fibonacci number is a multiple of 8

*/
