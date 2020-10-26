# Number of subarrays having sum less than K

Given an array of non-negative numbers and a non-negative number k, find the number of subarrays having sum less than k. We may assume that there is no overflow.

Examples :

Input : arr[] = {2, 5, 6}, K = 10, Output : 4

The subarrays are {2}, {5}, {6} and {2, 5},

Input : arr[] = {1, 11, 2, 3, 15}, K = 10, Output : 4

{1}, {2}, {3} and {2, 3}


A **simple solution** is to generate all subarrays of the array and then count the number of arrays having sum less than K.

Time complexity : O(n^2)

**Efficient solution**

Time complexity : O(n)

```cpp
int countSubarrays(int arr[],int n, int k)
{
    int start = 0, end = 0, count = 0, sum = arr[0];
    while (start < n && end < n)
    {
        if (sum < k)
        {
            end++;
            if (end >= start)
                count += end - start;
            if (end < n)
                sum += arr[end];
        }
        else
        {
            sum -= arr[start];
            start++;
        }
    }
    return count;
}
```

# Smallest subarray with sum equal or greater than a given value

Given an array of integers and a number x, find the smallest subarray with sum equal or greater than the given value.

input : 5 12

1 3 4 5 2

output : 3, the subarray is [3,4,5]

input : 5 6

1 1 1 1 1

output : -1

```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int solve(int arr[],int n, int k)
{
    int start = 0, en = 0, cnt = n; ll sum = arr[0];
    while (start < n && en < n)
    {
        if (sum < k)
        {
            en++;
            if (en < n)
                sum += arr[en];
        }
        else
        {
            if(en>=start)
            cnt = min( cnt,en - start+1);
            sum -= arr[start];
            start++;
        }
    }
    return cnt;
}
int main()
{
    int n,k;cin>>n>>k;
    int a[n];ll sum=0;
    for(int i=0;i<n;i++)cin>>a[i],sum+=a[i];
    if(sum<k)return cout<<-1,0;
    cout<<solve(a,n,k);
    return 0;
}
```

