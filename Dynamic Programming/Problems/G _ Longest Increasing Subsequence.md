# Longest Increasing Subsequence

The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence 
of a given sequence such that all elements of the subsequence are sorted in increasing order.
        
For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}

**Tabulation Method – Bottom Up Dynamic Programming**

Complexity : O(n^2)
```cpp
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int lis[n];
        for(int i=0;i<n;i++)
        {
            lis[i]=1;
            for(int j=0;j<i;j++)
            {
                if(a[j]<a[i])
                    lis[i]=max(lis[i],lis[j]+1);
            }
        }
        cout<<*max_element(lis,lis+n);
```        
**Printing longest increasing subsequence**

Complexity : O(nlogn)
```cpp
        int n;
        cin >> n;
        vector<int> dp;
        for (int i = 0; i < n; i++) 
        {
            int x;
            cin >> x;
            auto it = lower_bound(dp.begin(), dp.end(), x);
            if (it == dp.end()) 
               dp.push_back(x);
             else *it = x;
        }
        cout << dp.size() <<'\n';
        for(auto& z:dp)cout<<z<<' ';
```
