/*
Given two arrays of n integers with values of array being small (values never exceed a small number say 100)
Find the pair(x, y) which has maximum gcd. x and y cannot be of the same array. If multiple pairs have same gcd
then consider the pair which has the maximum sum.
Examples:
Input : a[] = {3, 1, 4, 2, 8}
        b[] = {5, 2, 12, 8, 3}
Output : 8 8
Explanation: The maximum gcd is 8 which is 
of pair(8, 8).  
Input: a[] = {2, 3, 5}
       b[] = {7, 11, 13}
Output: 5 13
Explanation: Every pair has a gcd of 1.
The maximum sum pair with GCD 1 is (5, 13)
*/

void gcdMax(int a[], int b[], int n, int N) 
{ 
    int cnt[N] = { 0 };  
    int first[N] = { 0 }, second[N] = { 0 }; 
    for (int i = 0; i < n; ++i) 
        cnt[a[i]] = 1; 
    for (int i = 1; i < N; ++i) 
        for (int j = i; j < N; j += i) 
            if (cnt[j]) 
                first[i] = max(first[i], j); 
    memset(cnt, 0, sizeof(cnt)); 
    for (int i = 0; i < n; ++i) 
        cnt[b[i]] = true; 
    for (int i = 1; i < N; ++i) 
        for (int j = i; j < N; j += i) 
            if (cnt[j]) 
                second[i] = max(second[i], j); 
     int i; 
    for (i = N - 1; i >= 0; i--) 
        if (first[i] && second[i]) 
            break; 
  
    cout << "Maximum GCD pair with maximum "<< first[i] << " "<< second[i] << endl; 
} 
int main() 
{ 
    int a[] = { 3, 1, 4, 2, 8 }; 
    int b[] = { 5, 2, 12, 8, 3 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    int N = 0;
    for(int i=0;i<n;i++)
    {
         N = max(a[i],N);
         N = max(b[i],N);
    }
  
    gcdMax(a, b, n, N); 
    return 0; 
} 

//  Time complexity : O(N Log N + n). Note that N + (N/2) + (N/3) + ….. + 1 = N log N.
//  Auxiliary Space : O(N)
