### to_string

Returns a string with the representation of val
```cpp
#include <iostream>   
#include <string>     
using namespace std;
int main ()
{
    int m = 1593;
    string s = to_string(m);
    cout<<s;                     //  1593
    return 0;
}
```

### stoi 

converts the string to an integer
```cpp
#include <iostream>  
#include <string>     
using namespace std;
int main ()
{
     string s = "1593";
     int m = stoi(s);   // 1593
     cout<< m + 1;      //  1594
}
```
Complexity :: Unspecified, but generally linear in the number of characters interpreted.

### stof 

converts the string to float
```cpp
#include <iostream>   // std::cout
#include <iomanip>
#include <string>     // std::string, std::stoi
using namespace std;
int main ()
{
     string s = "90613.524";
     float m = stof(s);   // 90613.524
     cout<<fixed<<showpoint<<setprecision(4);
     cout<< m + 1;      //  90614.524
}
Complexity :: Unspecified, but generally linear in the number of characters interpreted.
```

### stol 

converts the string to long long
```cpp
#include <iostream>   
#include <string>     
using namespace std;
int main ()
{
     string s = "1987520892";
     long long m = stol(s);   // 1987520892
     cout<< m + 1;      //  1987520893
}
```
Complexity :: Unspecified, but generally linear in the number of characters interpreted.


### stold
converts the string to double
```cpp
#include <iostream> 
#include <iomanip>
#include <string>     
using namespace std;
int main ()
{
     string s = "90613.30536524";
     double m = stold(s);   // 90613.30536524
     cout<<fixed<<showpoint<<setprecision(8);
     cout<< m + 1;      //  90614.30536524
}
```
Complexity :: Unspecified, but generally linear in the number of characters interpreted.
