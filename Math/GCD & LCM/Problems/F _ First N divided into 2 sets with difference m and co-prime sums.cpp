/*
Given N and M, task is to find whether numbers 1 to N can be divided into two sets such that the absolute difference between 
the sum of two sets is M and gcd of the sum of two sets is 1 (i.e. Sum of both sets are co-prime)

Input : N = 5 and M = 7
Output : YES
Explanation : as numbers from 1 to 5 can be divided into two sets {1, 2, 3, 5} and {4} such that absolute difference between
the sum of both sets is 11 – 4 = 7 which is equal to M and also GCD(11, 4) = 1.

Input : N = 6 and M = 3
Output : NO
Explanation : In this case, Numbers from 1 to 6 can be divided into two sets {1, 2, 4, 5} and {3, 6} such that absolute
difference between their sum is 12 – 9 = 3. But, since 12 and 9 are not co-prime as GCD(12, 9) = 3, the answer is ‘NO

Approach : Since we have 1 to N numbers, we know that the sum of all the numbers is N * (N + 1) / 2
Let S1 and S2 be two sets such that,
1) sum(S1) + sum(S2) = N * (N + 1) / 2
2) sum(S1) – sum(S2) = M
Solving these two equations will give us the sum of both the sets
If sum(S1) and sum(S2) are integers and they are co-prime (their GCD is 1)
then there exists a way to split the numbers into two sets. Otherwise, there is no way to split these N numbers
*/
int gcd(int a,int b)
{
     if(!b)return a;
     return gcd(b,a%b);
}
bool isSplittable(int n, int m) 
{ 
    int total_sum = (n * (n + 1)) / 2; 
    if (total_sum < m) 
        return false; 
        
     /*
         total_sum = sum_s1 + sum_s2 
         m = sum_s1 - sum_s2 
         sum_s1 = m + sum_s2
         sum_s1 = m + (total_sum - sum_s1)
         2 * sum_s1 = m + total_sum
    */
    
    int sum_s1 = (total_sum + m) / 2;
    int sum_s2 = total_sum - sum_s1; 
  
    if (sum_s1 + sum_s2 == total_sum && sum_s1 - sum_s2 == m) 
        return (gcd(sum_s1, sum_s2) == 1); 
    return false; 
} 
int main() 
{ 
    int n = 5, m = 7; 
  
    if (isSplittable(n, m)) 
        cout << "Yes"; 
    else
        cout << "No"; 
  
    return 0; 
} 
// Time Complexity : O(log(n))
