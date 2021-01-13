
```cpp
ios_base::sync_with_stdio(0), cin.tie(0);

string s;
while(s.size()==0)
getline(cin, s);

while (cin >> x) 
{
    // code
}

freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

cout<< 838897238475ll ;

int a = 1e9 , b = 1e9 ;	
cout<< a * b ;             // -148668157543         // Overflow 	
long long c = a*b ;       // c = -148668157543     // Casting

double a,b;
if (abs(a-b) < 1e-9) 	
{	
    // a and b are equal	
}

#include<iomanip>	
cout<< fixed << showpoint << setprecision(n) ;

cout<<setw(5)<<setfill('0')<<"kh"; 000kh

int dx[] = {0,0,-1,1,-1,1,-1,1};
int dy[] = {-1,1,0,0,-1,-1,1,1};
bool check(int i,int j)
{
    return i>=0&&j>=0&&i<n&&j<m;
}

// Leap Year
bool isLeap(int y)
{
    return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}
string dayOfTheWeek(int day, int month, int year)
{
    vector<int> md = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    vector<string> show{ "Friday", "Saturday", "Sunday", "Monday",
                         "Tuesday", "Wednesday", "Thursday" };
    int idx = 6;
    for (int y = 1971; y < year; y++)
        idx += (isLeap(y) ? 366 : 365);
    for (int m = 1; m < month; m++)
        idx += (isLeap(year) && m == 2 ? 29 : md[m]);
    idx += day;
    return show[idx % 7];
}
```
