/*
Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.
Input : n = 1
Output : 5 
1!, 2!, 3!, 4! does not contain trailing zero.
5! = 120, which contains one trailing zero.
5!  has 1 trailing zeroes  ==>>  [All numbers from 6 to 9 have 1 trailing zero]
10! has 2 trailing zeroes  ==>>  [All numbers from 11 to 14 have 2 trailing zeroes]
15! to 19! have 3 trailing zeroes
20! to 24! have 4 trailing zeroes
25! to 29! have 6 trailing zeroes
We can notice that, the minimum value whose factorial contain n trailing zeroes is 5*n
*/

bool valid(ll mid)
{
    ll cnt=0;
    while(mid)
    {
        cnt+=mid/5;
        mid/=5;
    }
    return (cnt>=n);
}
void solve()
{
    ll l=0,r=n*5;
    while(l<r)
    {
        ll mid = l+((r-l)>>1);
        if(valid(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<l;
}
// Time Complexity : O( log2(n) * log5(n) )
