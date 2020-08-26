# Get right most non zero digit of factorial N?

Let's simplify. Last digit of X = X%10

Let X = 123000, then last non zero digit of X = 3

Let X = 123 * 10^3, so 3 = 123%10

Note (a*b*c)%D = (a%D * b%D * c%D) % D

If in n! we could represent it as = 10^x * reminder...then reminder%10 is the answer

again, Let n! = 2^a * 5^b * reminder1

Then	n! = 10^b * reminder2

So to calculate reminder2 we need to cacl n! such that we don't consider b 2's and b 5's

In fact, all 5's wont't be used, and we will use overall a-b 2's

Let n = 15, n! = 1307674368000 = 2^11 * 5^3 * 5108103

So n! has 3 zeros

We want to calculate n! with only 11-3 2's

Let X = 2^8 * 5108103 = 1307674368		so X%10 = 8

