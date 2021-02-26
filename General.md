
```cp
string s;
while(s.size()==0)
getline(cin, s);
// OR
while (cin >> x) 
{
    // code
}

freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

clockid_t ct1,ct2;
ct1 = clock();
//
ct2 = clock();
cout<<fixed<<setprecision(5)<<double(ct2-ct1)/double(CLOCKS_PER_SEC);

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

string k = "khaled mahmoud fawzy",s1,s2,s3;
stringstream input(k);
input>>s1>>s2>>s3;
cout<<s1<<':'<<s2<<':'<<s3;  // khaled:mahmoud:fawzy

string k = "23 87 69";int s1,s2,s3;
stringstream input(k);
input>>s1>>s2>>s3;
cout<<s1<<':'<<s2<<':'<<s3;  // 23:87:69

string k = "23 87 69";
stringstream input(k);
int n=0,x,a[102];
while(input>>x)
a[n++] = x;

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


// dist distance between dragon and princess 
double td = dist / (vd - vp);  // time for the dragon to reach the princess where vd > vp
// vd the speed of dragon and vp the speed of princess
```
