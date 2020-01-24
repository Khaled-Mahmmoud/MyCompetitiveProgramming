/*
You have two coin piles containing a and b coins. On each move, you can either remove one coin from the left pile and two coins 
from the right pile, or two coins from the left pile and one coin from the right pile
Your task is to efficiently find out if you can empty both the piles

CSES problem link : https://cses.fi/problemset/task/1754

1 ≤ t ≤ 10^5
0 ≤ a,b ≤ 10^9

Input:
3
2 1
2 2
3 3

Output:
YES
NO
YES

Solution :
a  b
x = takes 2 from a and 1 from b
y = takes 1 from a and 2 from b

a = 2 * x + 1 * y
b = 1 * x + 2 * y

2a = 4 * x + 2 * y
 b = 1 * x + 2 * y
 -----------------
2a - b = 3 * x

2b - a = 3 * y

*/

int main()
{
    fast();
    int t;cin>>t;while(t--)
    {
        int a,b;cin>>a>>b;
        if((2*a-b)>=0&&(2*a-b)%3==0&&(2*b-a)>=0&&(2*b-a)%3==0)
            cout<<"YES";
        else cout<<"NO";
        cout<<'\n';
    }
    return 0;
