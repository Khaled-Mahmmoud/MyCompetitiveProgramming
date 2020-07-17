# balanced brackets

Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

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
bool areParanthesisBalanced(string expr) 
{ 
    stack<char> s; 
    char x; 
    for (int i = 0; i < expr.length(); i++) 
    { 
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        { 
            s.push(expr[i]); 
            continue; 
        } 
        if (s.empty()) 
            return false; 
        switch (expr[i]) 
        { 
        case ')': 
              x = s.top(); 
            s.pop(); 
            if (x == '{' || x == '[') 
                return false; 
            break; 
  
        case '}': 
              x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '[') 
                return false; 
            break; 
  
        case ']': 
              x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '{') 
                return false; 
            break; 
       } 
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
