
```cpp
// Given an unsorted array of integers
// count a continuous subarray which adds to a given number.
int cnt_subarray(int arr[], int n, int sum)
{
    map<int, int> m;
    int res = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) 
    {
        cur += arr[i];
        if (cur == sum)
            res++;
        if (m.find(cur - sum) != m.end())
            res += (m[cur - sum]);
        m[cur]++;
    }
    return res;
}
/*
Count of subarrays having exactly K prime numbers
Count of subarrays having exactly K perfect square numbers

Traverse the given array and check whether the element is prime or not.
If the current element is prime then change the value of index to 1, Else 0.
Find the count of subarray with sum equals to K in the above Binary Array.

Count subarrays with equal number of 1’s and 0’s
Count subarrays with same even and odd elements

Traverse the given array and check whether the element is 1 or not.
If the current element is 1 then change the value of index to 1, Else -1.
Find the count of subarray with sum equals to 0 in the above Binary Array.
*/
// Longest sub-array having sum k
int long_subarray(int arr[],int n,int k)
{
    map<ll, int> m;
    ll sum = 0;int len = 0,index = -1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            len = i + 1;
            index = i;
        }
        if (m.find(sum - k) != m.end())
            if (len < (i - m[sum - k]))
                len = i - m[sum - k],index = i;
	if (m.find(sum) == m.end())
            m[sum] = i;
    }
    cout<<index-len+1<<' '<<index;
    return len;
}
// Find the total number of subarrays having bitwise XOR of all elements equals to B
int cnt_subarray(int a[],int n,int b)
{
    unordered_map<int,int>m;
    int res = 0,cur = 0;
    for(int i=0;i<n;i++)
    {
        cur ^= a[i];
        if(cur==b)
            res++;
        if(m.find(cur^b)!=m.end())
            res += m[cur^b];
        m[cur]++;
    }
    return res;
}

// Minimum number of swaps required to sort an array
int min_swaps(int arr[], int n)
{
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
    sort(arrPos, arrPos + n);
    vector<bool> vis(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] || arrPos[i].second == i)
            continue;
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
            j = arrPos[j].second;
            cycle_size++;
        }
        if (cycle_size > 0)
            ans += (cycle_size - 1);
    }
    return ans;
}
// Minimum swaps to make two arrays identical
int min_swap_2array(int a[], int b[], int n)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[b[i]] = i;
    for (int i = 0; i < n; i++)
        b[i] = mp[a[i]];
    return min_swaps(b, n);
}
```
