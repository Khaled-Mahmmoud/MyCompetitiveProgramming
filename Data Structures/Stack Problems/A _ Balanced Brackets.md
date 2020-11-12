# Balanced Brackets

Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.


{([])} ==>> balanced

() ==>> balanced

([] ==>> not balanced

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
        
        if((s[i]==')'&&sk.top()=='(')||(s[i]==']'&&sk.top()=='[')||(s[i]=='}'&&sk.top()=='{'))
            sk.pop();
        else 
            return false;
    } 
    return (sk.empty()); 
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
```
