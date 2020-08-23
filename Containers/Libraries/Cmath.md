### pow 

Returns base raised to the power exponent : pow(a,b)
```
pow(7 , 3)        =   343.000000
pow(4.73 , 12)    =   125410439.217423
pow(32.01 , 1.54) =   208.036691
```
Time complexity O(log b)

### sqrt 

Returns the square root of x : sqrt(x)

sqrt(4) = 2

sqrt(7) = 2.64575

sqrt(9) = 3

Time complexity O(log x)

### cbrt 

Returns the cubic root of x : cbrt(x)
```
cbrt(8) = 2
cbrt(27) = 3
cbrt(43) = 3.5033
```
Time complexity O(log x)

### ceil 

Rounds x upward, returning the smallest integral value that is not less than x   O(1)
```
ceil(2.3) = 3
ceil(2.5) = 3
ceil(2.8) = 3
ceil(2)   = 2
ceil(-3.2)= -3
ceil(-5.5)= -5
```
ceil(x,y) = `(x+y-1)/y`

### floor 

Rounds x downward, returning the largest integral value that is not greater than x   O(1)
```
floor(2.3) = 2
floor(2.5) = 2
floor(2.8) = 2
floor(3)   = 3
floor(-3.2)= -4
floor(-5.5)= -6
```
### round/llround 

Returns the integral value that is nearest to x, with halfway cases rounded away from zero   O(1)
```
round(2)   = 2
round(2.3) = 2
round(2.5) = 3            
round(2.7) = 3   
round(-5.2)= -5
round(-5.5)= -6
round(-5.8)= -6
```
round   ==>> int

llround ==>> long long int

round(x, y) = (x+y/2)/y [if x > 0] and (x-y/2)/y [x < 0]

### trunc

return rounds x toward zero
```
trunc(2.3)  =  2.0
trunc(3.8)  =  3.0
trunc(5.5)  =  5.0
trunc(-2.3) =  -2.0
trunc(-3.8) =  -3.0
trunc(-5.5) =  -5.0
```
