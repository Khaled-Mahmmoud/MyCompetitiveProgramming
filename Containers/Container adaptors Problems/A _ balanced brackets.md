# balanced brackets

Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.

**Input**

The first line of input contains an integer T denoting the number of test cases.  Each test case consists of a string of expression, in a separate line.

**Output**

Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.

**Constraints**

1 ≤ T ≤ 100

1 ≤ |s| ≤ 105

**Input**

3

{([])}

()

([]

**Output**

balanced

balanced

not balanced

```cpp
bool areParanthesisBalanced(string s) 
{ 
    stack<char> sk; 
    for (int i = 0; i < s.length(); i++) 
    { 
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        { 
            sk.push(s[i]); 
            continue; 
        } 
        if (sk.empty()) 
            return false; 
        
        if(s[i]==')'&&sk.top()=='('||s[i]==']'&&sk.top()=='['||s[i]=='}'&&sk.top()=='{')
            sk.pop();
        else 
            return false;
    } 
    return (s.empty()); 
} 
  
int main() 
{ 
    string s;
    cin>>s;
    if (areParanthesisBalanced(s)) 
        cout << "Balanced"; 
    else
        cout << "Not Balanced"; 
    return 0; 
} 
