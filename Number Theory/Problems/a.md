
When we *meet* an opening brackets, we will decrement $\text{depth}$, and when we meet a closing bracket, we increase it.
If we are at some point meet an opening bracket, and the balance after processing this symbol is positive, then we have found the rightmost position that we can change.
We change the symbol, compute the number of opening and closing brackets that we have to add to the right side, and arrange them in the lexicographically minimal way.
If we find do suitable position, then this sequence is already the maximal possible one, and there is no answer.


``` cpp
bool next_balanced_sequence(string & s) {
    int n = s.size();
    int depth = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(')
            depth--;
        else
            depth++;

        if (s[i] == '(' && depth > 0) {
            depth--;
            int open = (n - i - 1 - depth) / 2;
            int close = n - i - 1 - open;
            string next = s.substr(0, i) + ')' + string(open, '(') + string(close, ')');
            s.swap(next);
            return true;
        }
    }
    return false;
}
```
