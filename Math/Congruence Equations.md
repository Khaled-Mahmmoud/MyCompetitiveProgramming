```cpp
/*
a ≡ b (mod n)
called a and b congruent modulo n
- It means a%n = b%n = x,
- this means (a-b)%n = 0 and (b-a)%n = 0
- a = b+qn for some q integer (a-b = qn)
Note that a ≡ 0 (mod m) if and only if m | a. 
Thus, modular arithmetic gives you another way of dealing with divisibility relations.
Another way of saying this is:  any multiple of m Mod m is 0.
- If ax ≡ ay (mod n) and gcd(a,n) = d, then the congruence is equivalent x ≡ y (mod n/d)
- If ax ≡ ay (mod n) SAME as x ≡ y (mod n) THEN d = 1, Reverse doesn’t need this condition.
- IF a ≡ b (mod m) then a^n ≡ b^n (mod m) for all  n >= 1
- If p is prime , (x+y)^p ≡ x^p + y^p (mod p)
- If a ≡ b (mod m) and b ≡ c (mod m), then a ≡ c (mod m)
proof : there are two integers j and k such that
a - b = jm , b - c = km 
add two equations a - c = jm + km 
this implies that a ≡ c (mod m)
- If a ≡ b (mod m) and c ≡ d (mod m), then a + c ≡ b + d (mod m) OR a - c ≡ b - d (mod m)
proof : m | a - b and m | c - d
then m | (a-b) + (c-d) = m | (a+c) - (b+d)
tis implies a+c ≡ b+d (mod m)
- If a ≡ b (mod m) and c ≡ d (mod m), then ac ≡ bd (mod m) 
proof : there are two integers j and k such that
a ≡ b+jm   and   c ≡ d+km
Multiplying these two equations, I obtain
ac ≡ (b+jm) * (d+km)
ac ≡ bd + bkm + jmd + jmkm
ac - bd ≡ m (bk + jd + jkm)
m | ac - bd 
this implies ac ≡ bd (mod m)
- IF a ≡ b (mod m)  a + c ≡ b + c (mod m) 
- IF a ≡ b (mod m)  ac ≡ bc (mod m) 
- From last one, ax ≡ b (mod n) same as x ≡ ba^-1 (mod n) 

Find answer of 3^5555 % 80
Hint: Think how to reduce the large power?!
Hint: 3^4 ≡ 1 (% 80) and 5555 = 4 * 1388 + 3
Then, 3^5555 % 80 = 3^3 % 80 = 27

Find answer of (3^1000 + 3) % 28
Hint: 3^3 = 27 = -1 (% 28) and 1000 = 3*333+1
Then equation = [(-1 * 3) + 3] (% 28) = 0
for this 27 ≡ -1 (% 28) then n ≡ n - m (% m)
a % (a-b) = b % (a-b)
*/
```
