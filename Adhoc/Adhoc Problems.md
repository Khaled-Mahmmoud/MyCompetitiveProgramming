#### Find Second largest element
```cpp
int main()
{
    int n,x,mx1=INT_MIN,mx2=INT_MIN;
    cin>>n;
    while(n--)
    {
        cin>>x;
        if(x>mx1)
        {
            mx2 = mx1;
            mx1 = x;
        }
        else if(x>mx2&&x!=mx1)
            mx2 = x;
    }
    cout<<(mx2==INT_MIN)?-1:mx2;
    return 0;
}
```
Complexity : O(n)

#### Balanced Bitstring
[Problem Link](https://codeforces.com/contest/1405/problem/C)
[Tutorial Link](https://codeforces.com/blog/entry/82366)

#### Common Divisors
[Problem Link](https://codeforces.com/contest/182/problem/D)
[Solution Link](https://codeforces.com/contest/182/submission/94810395)

#### Count of subarrays which contains a given number exactly K times
Given an array A[] of N elements consisting of values from 1 to N with duplicates, the task is to find the total number of subarrays which contain a given number num exactly K times.
```cpp
int countSubarrays(int A[], int num,int K, int size)  
{                                                  
    vector<int> indices;
    for (int i = 0; i < size; i++) 
        if (A[i] == num)
            indices.push_back(i);
    if (indices.size() < K)
        return 0;
    int prev = -1,ans = 0,ctr = 0;
    for (int i = 0;i <= indices.size() - K;i++) 
    {
        ctr = indices[i] - prev;
        if (i < indices.size() - K) 
            ctr *= (indices[i + K]- indices[i + K - 1]);
        else 
            ctr *= ((size - 1) - indices[i + K - 1] + 1);
        ans += ctr;
        prev = indices[i];
    }
    return ans;
}
```
Time Complexity : O(N)
