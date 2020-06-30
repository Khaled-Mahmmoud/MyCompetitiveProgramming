/*

Finding sum of digits of a number until sum becomes single digit
Given a number n, we need to find the sum of its digits such that:

If n < 10    
    digSum(n) = n
Else         
    digSum(n) = Sum(digSum(n))
Examples :

Input : 1234
Output : 1
Explanation : The sum of 1+2+3+4 = 10, 
              digSum(x) == 10
              Hence ans will be 1+0 = 1

Input : 5674
Output : 4 

A brute force approach is to sum all the digits until sum < 10

*/
``
int digSum(int n) 
{ 
    int sum = 0; 
    while(n > 0 || sum > 9) 
    { 
        if(n == 0) 
        { 
            n = sum; 
            sum = 0; 
        } 
        sum += n % 10; 
        n /= 10; 
    } 
    return sum; 
} 
int main() 
{ 
    int n = 1234; 
    cout << digSum(n); 
    return 0; 
} 

//  Time Complexity : log10(n)
/*

There exists a simple and elegant O(1) solution for this too. The ans is given by simply :-

If n == 0
   return 0;

If n % 9 == 0      
    digSum(n) = 9
Else               
    digSum(n) = n % 9 

*/

int digSum(int n) 
{ 
    if (n == 0)  
       return 0; 
    return (n % 9 == 0) ? 9 : (n % 9); 
} 
int main() 
{ 
    int n = 9999; 
    cout<<digSum(n); 
    return 0; 
} 
