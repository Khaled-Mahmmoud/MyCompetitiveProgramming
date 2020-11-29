### Get right most non zero digit of factorial N?

Let's simplify. Last digit of X = X%10

Let X = 123000, then last non zero digit of X = 3

Let X = 123 * 10^3, so 3 = 123%10

Note (a*b*c)%D = (a%D * b%D * c%D) % D

If in n! we could represent it as = 10^x * reminder...then reminder%10 is the answer

again, Let n! = 2^a * 5^b * reminder1

Then	n! = 10^b * reminder2 , So to calculate reminder2 we need to cacl n! such that we don't consider b 2's 

In fact, all 5's wont't be used, and we will use overall a-b 2's

Let n = 15, n! = 1307674368000 = 2^11 * 5^3 * 5108103

So n! has 3 zeros, We want to calculate n! with only 11-3 2's

Let X = 2^8 * 5108103 = 1307674368, so X%10 = 8

### Right most non zero digit of product of array

You will be given an array A of N non negative integers. Your task is to find the right most non zero digit in the product of array elements.

```cpp
int cnt2,cnt5;
int solve(long long n)
{
    while(cnt2&&n%2==0)
    {
        n/=2;
        cnt2--;
    }
    while(cnt5&&n%5==0)
    {
        n/=5;
        cnt5--;
    }
    return n%10;
}
int main()
{
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;cnt2 = 0;cnt5 = 0;
        long long a[n],x;bool flag = false;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(!a[i])
            {
                flag = true;
                continue;
            }
            x = a[i];
            while(x%2==0)
            {
                cnt2++;
                x = x/2;
            }
            while(x%5==0)
            {
                cnt5++;
                x = x/5;
            }
        }
        if(flag)
        {
            cout<<-1<<'\n';
            continue;
        }
        cnt2 = min(cnt2,cnt5);
        cnt5 =  cnt2;
        int ans = 1;
        for(int i=0;i<n;i++)
        {
            ans = (ans * solve(a[i]))%10;
        }
        cout<<ans<<'\n';
    }
	return 0;
}
```
