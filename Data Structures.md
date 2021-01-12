```cpp
/*
<Segment Tree>
Given an array A of size N and some queries. There are two types of queries:
Update : Given Idx and Val, update array element A[Idx] as A[Idx] = A[Idx] + Val.
Query : Given L and R return the value of `A[L]+A[L+1]+A[L+2]+....+A[R-1]+A[R]` such that 0 <= L <= R <= N-1
*/
const int N = 4e5 + 5;
int n, m, a[N];
int l[N], r[N];
ll seg[4 * N], lazy[4 * N];
vector<int> g[N];
vector<int> flatten;
void build(int node, int s, int e)
{
    if(s == e)
    {
        seg[node] = (1ll << a[flatten[s]]);
        return;
    }
    int mid = s + e >> 1;
    build(node << 1, s, mid);
    build(node << 1 | 1, mid + 1, e);
    seg[node] = (seg[node << 1] | seg[node << 1 | 1]);
} // O(n)
void propagate(int node, int s, int e)
{
    seg[node] = lazy[node];
    if(s != e)
    {
        lazy[node << 1] = lazy[node];
        lazy[node << 1 | 1] = lazy[node];
    }
    lazy[node] = 0;
} // O(1)
void update(int node, int s, int e, int l, int r, int val)
{
    if(lazy[node])
        propagate(node, s, e);
    if(s > r || e < l)
        return;
    if(l <= s && e <= r)
    {
        lazy[node] = (1ll << val);
        propagate(node, s, e);
        return;
    }
    int mid = s + e >> 1;
    update(node << 1, s, mid, l, r, val);
    update(node << 1 | 1, mid + 1, e, l, r, val);
    seg[node] = (seg[node << 1] | seg[node << 1 | 1]);
} // O(log n) 
ll query(int node, int s, int e, int l, int r)
{
    if(lazy[node])
        propagate(node, s, e);
    if(s > r || e < l)
        return 0;
    if(l <= s && e <= r)
        return seg[node];
    int mid = s + e >> 1;
    return (query(node << 1, s, mid, l, r) | query(node << 1 | 1, mid + 1, e, l, r));
} // O(log n)
/*
main
build(1,0,n-1);	
updata(1,0,n-1,idx,val);
query(1,0,n-1,l,r)

We we have a coordinate space on x-axis from [0 - N].
we are given set of numbers (order is not issue)	e.g.: 20 7 4 9 12.
Queries are as following.
 
HOW many numbers are in given interval?			
E.g In interval [1-3]  = 0	-> Notice, our first element is 4
E.g In interval [6-15] = 3	-> 7, 9, 12

Get Kth item in sorted list
 E.g. get(2) = 7		-> in sorted list 4 7 9 12 20
			
Remove kth item in sorted list
E.g. remove(5) 		-> 4 7 9 12
		
Insert new element: so we update our list
E.g. insert(16)		-> 4 7 9 12 16 20
*/
const int N = 2000006;
int interval[2*N-1];	
int S = 0, E = N;
// insert num and return its order (kth in order)
int insert(int num, int s = S, int e = E, int p = 1)  // O(logn)
{	
	interval[p]++;
	if(s == e)	
	        return interval[p];	
	int mid = (s+e) >> 1;
	if(num <= mid)
		return insert(num, s, mid, 2*p);
	return interval[2*p] + insert(num, mid+1, e, 2*p+1);
}
// remove kth element, and return its value
int remove(int kTh, int s = S, int e = E, int p = 1) // O(logn)
{
	interval[p]--;
	if(s == e)	
	    return s;
	int mid = (s+e) >> 1;
	if(interval[2*p] >= kTh)	
	    return remove(kTh, s, mid, 2*p);
	return remove(kTh - interval[2*p], mid + 1, e, 2*p+1);
}
// remove num , return position of deleted val 
int remove(int num, int s = S, int e = E, int p = 1) // O(logn)
{
	interval[p]--;
	if(s == e)	
	    return interval[p] + 1;
	int mid = (s+e) >> 1;
	if(mid >= num)	
	    return remove(num, s, mid, 2*p);
	return interval[2*p] + remove(num , mid + 1, e, 2*p+1);
}
// get value of kth element
int get(int kTh, int s = S, int e = E, int p = 1)
{
	if(s == e)	
	    return s;
	int mid = (s+e) >> 1;
	if(interval[2*p] >= kTh)	
	     return getkTh(kTh, s, mid, 2*p);
	return getkTh(kTh-interval[2*p], mid+1, e, 2*p+1);
}
void displayElements(int s=S, int e=E, int p=1)
{
    int mid = (s+e) >> 1;
    if(s < e)
    {
        displayElements(s, mid, 2*p);
        displayElements(mid+1, e, 2*p+1);
    }
    if(s == e)
    {
        int cnt = interval[p];
        while(cnt--)
            cout<<s<<" ";
    }
}
/*
<Binary Indexed Tree> 
- Given an array of integer N, Assume index 0 always will be 0 (NOT in use)
- 2 query types:(1) Add value val to position index. (2) Sum values from 1 to index
- Segment Tree can be used to such problem : O(N) preprocess, O(NlogN) queries, O(nlogn) memory
- BIT has a better memory order (shorter code) :  O(n) memory + O(NlogN) queries
- Integer = Sum of Powers of 2
- Accumulative Sum = Sum of Sub sums
- Recall: 147 = 128 + 16 + 2 + 1
- Think in accumulative sum (1 to 147) = Sum of last 1 number + Sum of next 2 numbers + 
Sum of next 16 numbers + Sum of next 128 numbers
- Sum(1,147) = Sum(147,147) + Sum(146,145) + Sum(144,129) + Sum(128,1)
- 147 ⇒ positions {147, 146, 144, 128} with ranges {1, 2, 16,128}
- To get starting positions fast? Remove last bit
- 147 = 010010011 [remove last 1 bit]
- 146 = 010010010 [remove last 1 bit]
- 144 = 010010000 [remove last 1 bit]
- 128 = 010000000 [remove last 1 bit]
- 0 = DONE
- How to interpret:
- 147 responsible for range 147 to > 146
- 146 responsible for range 146 to > 144
- 144 responsible for range 144 to > 128
- 146 responsible for range 128 to > 0

Steps
- Create a new array of Length N, name it BIT
- BIT[position] = sum of its responsible range
- Then For each Query
- Sum(147)= BIT(147) + BIT(146) + BIT(144) + BIT(128), That is: 4 steps only to get the answer.
- Sum(144) = BIT(144) + BIT(128)
- Sum(15) = BIT(15) + BIT(14) + BIT(12) + BIT(8), Recall: 1111 = 1111, 1110, 1100, 1000, 0
- Sum(11) = BIT(11) + BIT(10) + BIT(8), Recall 1011: 1011, 1010, 1000, 0
- Sum(7) = BIT(7) + BIT(6) + BIT(4) ⇒ 111, 110, 100, 0
12 = 1100 ⇒ removing last 1 bit ⇒ 1000 = 8, Then parent of 12 ⇒ 8
Notice: we removed bit at position 2 ⇒ 12 covers 2^2 numbers = 12 - 8 = 4
Notice: 8 = 1000 => has 3 trailing zeros. Try to replace each 0 with 1
1001 = 9, 1010 = 10, 1100 = 12
number of trailing zeros = number of children … child remove last bit => go to parent

Get Interval Accumulation
Sum(15) = BIT(15) + BIT(14) + BIT(12) + BIT(8) = 1111 ⇒ 1110 ⇒ 1100 ⇒ 1000 ⇒ 0 = STOP
15 is responsible for 1 number, 14 for 2, 12 for 4, 8 for 8 numbers
*/
const int max_val = 30000;
int bit_tree[max_val];
int getAccum(int idx)
{
    int sum = 0;
    while(idx>0)
    {
        sum += bit_tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
/*
Updating position
Position 1: Covered by 4 intervals ⇒ 1, 2, 4, 8
Add -3 to 1 ⇒ add -3 to these 4 intervals

Given index, how to get smallest position covering it?
E.g. 1 ⇒ 2 6 ⇒ 8 10 ⇒ 12 13 ⇒ 14
Then 1 goes to 2...2 goes to 4..4 goes to 8 [recursive]
Recall given number idx it covers 2^r values where r is position of “last bit”.
All following numbers cover 8 values
- (0001000, 0101000, 1101000, 1111000, 1001000) ⇒ r = 3 ⇒ 2^3 = 8
- So our focus on “last bit”, NOT before that

Let’s get who covers 4 = 0100
4 has “last bit” at k = 2, When target number enumerate its 2^r, one contains 100
So we need to go at least 1 bit higher than k, E.g. re-set last bit k = 3 ⇒ 1000 ⇒ first one to cover 0100

Let’s get who covers 5 = 0101
k = 0, We need target number to include our 1 at k = 0
The earlier one should exist in smallest coverer number. So again, shift k = 0 1 step to be in its enumeration
E.g. re-set last bit k = 1 ⇒ 110. Note, 1000 also cover 5 Updating position

Let’s get who covers 3 = 0011, “last bit” at k = 0
We need enumeration includes whole 11. So parent need to be a 1 before these 11. E.g. ⇒ 0100

How to get that number easily?
Just add 2^k ⇒ if one or more bits ⇒ shifted. E.g. 100100011100 + 000000000100 = 100100100000

Notice: 8 = 1000 => has 3 trailing zeros. Remove last bit, and add 1, 2, 3...trailing ones
0100 = 4, 0110 = 6, 0111 = 7
number of trailing zeros = number of children
*/
void add(ll idx,ll val)
{
    while(idx<MAX_VAL)
    {
        bit_tree[idx] += val;
        idx += (idx & -idx);
    }
}
/*
Index with cumulative sum
Assume we have array of values >= 0, Accumulate it ⇒ increasing sequence
- Find first index with accumulation >= value
- Given that it is increasing, using binary search is direct
- BIT maintain such accumulation by definition, if all values >= 0
*/
int get_idx(int accum)
{
    int s = 1, e = MAX_VAL;
    while(s<e)
    {
        int mid_idx = (s+e)/2;
        int val = get_accum(mid_idx);
        if(val>=accum)
            e = mid_idx;
        else
            s = mid_idx + 1;
    }
    return s;
}
// How to get value of indx
int get_value(int idx)
{
    return get_accum(idx) - get_accum(idx-1);
}

/*
Disjoint sets
A disjoint-sets is a data structure that keeps track of a set of elements partitioned into number of non-overlapping subsets.
It has two powerful operation
1) connect two subsets together.
2) determine the subset that each element belong to.
*/
const int N = 1000;
int p[N];vector<int>siz;
int find(int u) 
{
    if (p[u] == u)
        return u;
    return p[u] = find(p[u]);
}
int main() 
{
    int n,m;
    cin>>n>>m;
    int cnt = n; // number of connected components
    siz.resize(n);
    for (int i=0;i<n;i++)
        p[i] = i;
    while(m--) 
    {
        int a,b;
        cin>>a>>b;

        a = find(a);
        b = find(b);

        if(a != b) 
        {
            cnt--;
            siz[b] += siz[a];
            p[a] = b;
        }
    }
    return 0;
}

/*
<Sparse Table>
Sparse table is a data structure that can help us answer range queries on a set on static data
More formally, sparse table can calculate the answer of Q(l, r) on an array a[i] of length n
Where Q(l, r) can be any _duplicate-invariant function_ as (max / min / GCD / LCM)
What I mean by _duplicate-invariant function_ is any function that output the same value for duplicate inputs.
| Function                          | Description                              |
| min(2, 3) = min(2, 2, 3, 3) = 2   | minimum is duplicate-invariant function  |
| (2 + 3) != (2 + 2 + 3 + 3)        | addition is not duplicate-invariant      |

Sparse Table Structure
The structure of sparse table is a 2D array ST[j][i]
where the j-th row in the sparse table holds the answer of queries of length 2^j
More formally, ST[j][i] holds the value of Q(i, i + (2^j) - 1)
We can build the sparse table easily in O(n.log(n)) as follows (having Q() equals min() as an example):
*/
const int N = 2e5 + 5, K = 25;
int arr[N], mn[N][K + 1], lg[N + 1];
void build() 
{
    lg[1] = 0;
    for(int i = 2; i <= n; ++i)
        lg[i] = lg[i / 2] + 1;
    for(int i = 0; i < n; ++i)
        mn[i][0] = arr[i];
    for(int j = 1; j <= K; ++j) 
    {
        for (int i = 0; i + (1 << j) <= n; ++i)
        {
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
        }
    }
}
// O(n.log(n))
// Sparse Table Query
// Now in order to calculate any Q(l, r) we are going to use the duplicate-invariant property
// to get the answer in O(1) as follows:

int get_min(int l, int r) 
{
    int j = lg[r - l + 1];
    return min(mn[l][j], mn[r - (1 << j) + 1][j]);
}
// O(1)

/*
<Sqrt Decomposition>
Sqrt Decomposition is a method (or a data structure) that allows you to perform some common operations
(finding sum of the elements of the sub-array, finding the minimal/maximal element, etc.)
in O(√n) operations, which is much faster than O(n) for the trivial algorithm
*/
const int N = 100005;
int n,q,v[N],root,bucket[N];
int main()
{
    cin>>n;
    root=sqrt(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    for(int i=0; i<n; ++i)
    {
        if(i%root==0)
            bucket[i/root]=v[i];
        else
            bucket[i/root]=min(bucket[i/root], v[i]);
    }
    cin>>q;
    for(int l,r,i=0; i<q; ++i)
    {
        cin>>l>>r;
        int ans=1e9;
        for(int j=l; j<=r; ++j)
        {
            if(j%root==0 && j+root-1<=r)
            {
                ans=min(ans, bucket[j/root]);
                j+=root-1;
            }
            else
                ans=min(ans, v[j]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
// O(q * sqrt(n))
/*
<Mo's algorithm>
A similar idea, based on sqrt decomposition, can be used to answer range queries (Q) offline in O((N+Q) * sqrt(N)).
*/
int n, t,a[200010],Z,freq[1000010];
ll res[200010];
struct qu
{
    int l, r,idx;
 
    qu() {}
    bool operator<(const qu &rhs) const
    {
        if(l/Z != rhs.l/Z)
        {
            return l < rhs.l;
        }
        return r < rhs.r;
    }
};
qu q[200010];
ll ans = 0;
void add(int idx)
{
    ans -= 1ll*freq[a[idx]]*freq[a[idx]]*a[idx];
    freq[a[idx]]++;
    ans += 1ll*freq[a[idx]]*freq[a[idx]]*a[idx];
}
void remove(int idx)
{
    ans -= 1ll*freq[a[idx]]*freq[a[idx]]*a[idx];
    freq[a[idx]]--;
    ans += 1ll*freq[a[idx]]*freq[a[idx]]*a[idx];
}
int main()
{
    cin>>n>>t;
    Z = sqrt(n)+1;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    for (int i = 0; i < t; ++i)
    {
        cin>>q[i].l>>q[i].r;
        q[i].l--;
        q[i].r--;
        q[i].idx = i;
    }
    sort(q,q+t);
    int l = 0, r = -1;
    for (int i = 0; i < t; ++i)
    {
        while(r < q[i].r)
        {
            r++;
            add(r);
        }
        while(r > q[i].r)
        {
            remove(r);
            r--;
        }
        while(l < q[i].l)
        {
            remove(l);
            l++;
        }
        while(l > q[i].l)
        {
            --l;
            add(l);
        }
        res[q[i].idx] = ans;
    }
    for (int i = 0; i < t; ++i)
    {
        cout<<res[i]<<'\n';
    }
    return 0;
}
```
