# Common Divisors

[Problem Link](https://codeforces.com/contest/182/problem/D)

[Tutorial Link](https://codeforces.com/blog/entry/4408)

```cpp
#include<bits/stdc++.h>
using namespace std;
char s1[100001],s2[100001];
bool check(char s[],int n){
	int size=strlen(s);
	for(int i=0;i<size;i++)
		if(s[i%n]!=s[i])return 0;
	return 1;
}
bool equal(int n){
	for(int i=0;i<n;i++)
		if(s1[i]!=s2[i])return 0;
	return 1;
}
int main(){
	scanf("%s%s",s1,s2);
	int cnt=0,sz1=strlen(s1),sz2=strlen(s2);
	for(int i=1;i<=min(sz1,sz2);i++)
		if((!(sz1%i))&&(!(sz2%i))&&equal(i)&&check(s1,i)&&check(s2,i))cnt++;
	printf("%d",cnt);
}
```
