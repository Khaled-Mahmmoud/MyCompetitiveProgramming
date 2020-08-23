# Logarithms

The logarithm of a number x is denoted logk(x), where k is the base of the logarithm

According to the definition, logk(x) = a exactly when x = k^a 

A useful property of logarithms is that logk(x) equals the number of times we have to divide x by k before we reach the number 1

For example, log2(8) = 3 because 3 divisions are needed

8 → 4 → 2 → 1

log10(1000) = 3 because 3 divisions are needed

1000 → 100 → 10 → 1

Logarithms are often used in the analysis of algorithms, because many efficient algorithms halve something at each step

Hence, we can estimate the efficiency of such algorithms using logarithms

The logarithm of a product is 
```
logk(ab) = logk(a)+logk(b)
```
and consequently
```
logk(x^n) = n·logk(x)
```                                  
In addition, the logarithm of a quotient is
```
logk(a/b) = logk(a)−logk(b)
```
Another useful formula is
```
logu(x) = logk(u)/logk(x)
``` 
and using this, it is possible to calculate logarithms to any base if there is a way
to calculate logarithms to some fixed base

The natural logarithm ln(x) = loge(x) of a number x is a logarithm whose base is

e ≈ 2,71828

k = [10, e, 2] => (common, natural, binary) log
- Math notations: lg(x), ln(x), lb(x)
- In c++: log10(x), log(x), log2(x)


Another property of logarithms is that the number of digits of an integer x in base b is `[ logb(x) + 1 ]`

For example, the representation of 123 in base 2 is 1111011 and [ log2(123) + 1 ] = 7
```
logb b = 1, logb 1 = 0, logb 0 = -oo, log1 x = undefined
● b ^ logb(x) = x => take logb for the equation to get x
● xb^y => b^(logb(x) + y)
```
