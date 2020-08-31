# Storages

given an array of integers, and q queries, print the most number repeated in array after every query, if there multiple numbers print largest of them.

query has two types:

X + : means add number x into array

X - : means remove number x from array (it is guaranteed that the array has number X)

input :

6

1 2 3 2 1 1

4

2 +

3 +

2 -

1 - 

output :

2

2

1

3

**Constraints**

1 <= n, a[i], q , x <= 10^ 5

```cpp
int main()
{
    int n,x;
    cin>>n;
    set<pair<int,int>>st;
    map<int,int>m;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(m[x])
        {
            st.erase({m[x],x});
            st.insert({m[x]+1,x});
        }
        else
        st.insert({1,x});
        m[x]++;
    }

    int q;cin>>q;
    while(q--)
    {
        char c;
        cin>>x>>c;
        if(st.find({m[x],x})!=st.end())
        st.erase({m[x],x});
        if(c=='+')
            m[x]++;
        else
            m[x]--;
        if(m[x])
        st.insert({m[x],x});
        auto it = st.end();
        it--;
        cout<<it->second<<endl;
    }
    return 0;
}

```
