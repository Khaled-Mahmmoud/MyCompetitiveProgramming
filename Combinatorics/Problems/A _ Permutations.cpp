/*
A permutation of integers 1,2,…,n is called beautiful if there are no adjacent elements whose difference is 1
Given n, construct a beautiful permutation if such a permutation exists
Input  : The only input line contains an integer n
Output : Print a beautiful permutation of integers 1,2,…,n. If there are several solutions, you may print any of them
If there are no solutions, print "NO SOLUTION".

Constraints
1 ≤ n ≤ 10^6

Input: 5
Output: 4 2 5 3 1

Input: 3
Output: NO SOLUTION

*/
int main()
{
    int n;cin>>n;
    if(n==1)cout<<"1";
    else if(n<=3)cout<<"NO SOLUTION";
    else if(n==4)cout<<"2 4 1 3";
    else {
        for(int i=1;i<=n;i+=2)
            cout<<i<<' ';
        for(int i=2;i<=n;i+=2)
            cout<<i<<' ';
    }
    return 0;
}
