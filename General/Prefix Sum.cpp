/*
Prefix sum (also called cumulative sum) is an array that helps to get the sum of elements to answer several queries with less complexity 
than answering each query by brute force. A cumulative sum is a sequence of partial sums of a given sequence
For example, the cumulative sums of the sequence (a, b, c, …) are (a, a+b, a+b+c, …)

Complexity:
1) Building the array
         One-dimensional array: O(n)
         Two-dimensional array: O(n*m)
2) Answering each query: O(1)

Prerequisites
None                 
*/

//Building one-dimensional prefix sum array and printing the prefix sum between to indices for each query
    int n;cin>>n;
    vector<int>v(n),prefix_sum(n);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=1;i<n;i++)prefix_sum[i]=prefix_sum[i-1]+v[i];
    int q;cin>>q;
    while(q--)
    {
        int l,r;cin>>l>>r;
        cout<<prefix_sum[r]-prefix_sum[l-1]<<endl;
    }

//Building two-dimensional prefix sum array and printing the prefix sum between two indices for each query

