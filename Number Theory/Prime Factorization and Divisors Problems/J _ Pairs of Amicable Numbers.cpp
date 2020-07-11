/*
Pairs of Amicable Numbers
Given an array of integers, print the number of pairs in the array that form an amicable pair
Two numbers are amicable if the first is equal to the sum of divisors of the second
and if the second number is equal to the sum of divisors of the first.

Input  : arr[] = {220, 284, 1184, 1210, 2, 5}
Output : 2
Explanation : (220, 284) and (1184, 1210) 
              form amicable pair

Input  : arr[] = {2620, 2924, 5020, 5564, 6232, 6368}
Output : 3
Explanation : (2620, 2924), (5020, 5564) and (6232, 6368) forms amicable pair

A simple solution is to traverse each pair and check if they form an amicable pair, if they do we increment the count
Complexity : O(n*n*sqrt(a[i]))

An efficient solution is be to keep the numbers stored in a map and for every number we find the sum of its divisor
and check if that’s also present in the array. If it is present, we can check if they form an amicable pair or not
Complexity : O(n*sqrt(a[i]))
*/

int sumOfDiv(int x) 
{ 
    int sum = 0; 
    for (int i = 1; i <= sqrt(x); i++)  
    { 
        if (x % i) 
        continue;
        sum += i;
        if(i*i == x)
        continue;
        sum += x/i;
    } 
    return sum; 
} 
  
int countPairs(int arr[], int n) 
{ 
    set<int> s; 
    int count = 0; 
    for (int i = 0; i < n; i++) 
        s.insert(arr[i]); 
    for (int i = 0; i < n; i++)  
    { 
        int num1 = sumOfDiv(arr[i]);
        if (s.find(num1) != s.end())  
        { 
            int num2 = sumOfDiv(num1); 
            if (num2 == arr[i]) 
                count++; 
        } 
    } 
    return count / 2; 
} 
