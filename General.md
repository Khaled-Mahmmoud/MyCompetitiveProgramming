
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
// convert to c = 1ll * a * b

if(a * b > MAX) continue;
// Convert to
if(a > MAX / b) 
    continue;
// What about a * b * c?
if(a > MAX / b || a * b > MAX / c)	
    continue;	// Check ab, then abc
// What about a * b + c?
if(a > MAX / b || a * b > MAX - c)	
   continue;	// Check ab, then abc

double a,b;
if (abs(a-b) < 1e-9) 	
{	
    // a and b are equal	
}

#define EPS 1e-9
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

map<Double,int>m;

/*
- Floor of 2 positive Integers
	 a / b
- Ceil of 2 positive Integers
	(a + b-1) / b
- Round of 2 positive Integers
	(a + b/2) / b
*/
#include<iomanip>	
cout<< fixed << showpoint << setprecision(n) ;

cout<<setw(5)<<setfill('0')<<"kh"; 000kh

int dx[] = {0,0,-1,1,-1,1,-1,1};
int dy[] = {-1,1,0,0,-1,-1,1,1};
bool check(int i,int j)
{
    return i>=0&&j>=0&&i<n&&j<m;
}

/*
// Grid Conversion
Say we are given grid of characters, and you want to convert them to grid of numbers.
	Say you are given characters S, E, ., # to {.=0, S=1, E=2, #=3}
...S.				00010
##E.#		->		33203
...#.				00030
*/
for(int i = 0 ; i < r; i++)
for(int j = 0 ; j < c; j++)
   gridInt[i][j] = string(".SE#").find( gridChar[i][j] );	//O(n)	
   
/*
// Ranges Intersection / Union
Say you have 2 ranges [1-20] and [5-15] and want to find their Intersection? Union?
	Let them (a, b) and (c, d)
	1- check if no intersection is easy? I am after you or reverse
	if(b < c || d < a) ...
	2- Sort 4 numbers a, b, c, d
	3- Intersection: 2 numbers in mid.
	4- Union: 2 numbers on boundary
*/
/*
// Array Flatten
Say we have 2D array R*C, and we want to convert it to 1D array of R*C elements
	then for any (i, j) zero based: we have i rows before us, each of C elements. In current row, j elements.
	then (i, j) = i * C + j			(note j < C)
	what if we have index X in 1 D, and want to convert it to its 2D?
	we know X = i * C + j
		then X%C = (i * C % C + j % C)%C = j
			 X/C = i*C / C + j/C = i
What about X*Y*Z?
	Then (i, j, k) = i * Y * Z + j * Z + k	-> Each term * Multiplication of next dimensions
	What about Index?
		Index%Z = i * Y * Z + j * Z + k = 0 + 0 + k
		Index/Z = i * Y + j + 0	= Index2
		then
		Index2%Y = 0 + j
		Index2/Y = i
	Coding wise, the processing from left and ranking (i, j, k) are similar
*/

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

// dist distance between dragon and princess 
double td = dist / (vd - vp);  // time for the dragon to reach the princess where vd > vp
// vd the speed of dragon and vp the speed of princess

// Computes the length of the longest increasing subsequence (LIS) 
// O(n.log(n))
int getLIS()
{
    int len = 0;
    vector<int> LIS(n, INT_MAX);
    for (int i = 0; i < n; ++i)
    {
        // To get the length of the longest non decreasing subsequence
        // replace function "lower_bound" with "upper_bound"
        int idx = lower_bound(LIS.begin(), LIS.end(), a[i]) - LIS.begin();
        LIS[idx] = a[i];
        len = max(len, idx);
    }
    return len + 1;
}

// for reverse number
ll rev(ll n)
{
    string str = to_string(n);
    reverse(str.begin(),str.end());
    ll n1 = 0;
    for(int i=0;i<sz(str);i++)
        n1 = n1 * 10 + (str[i]-'0');
    return n1;
}
```
