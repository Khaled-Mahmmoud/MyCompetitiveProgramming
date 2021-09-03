**PROBLEM:**
You will be given n strings consisting of lowercase English letter. You need to find the shortest non-empty string that doesn’t occur as a substring in given strings. If there are many such string, you need to print the lexicographically minimum one. 

**CONSTRAINTS:**

1 <= n <= 28

The length of each given string is from 1 to 20

**FUNCTION DESCRIPTION:**

Complete the function 'shortestString' in code. Function must return a string represent The lexicographically minimum string.

'shortestString' has the following parameter(n, ar[]):

Input

The first line contains integer n.

Then n strings, one per line.

Output

The lexicographically minimum string.

**EXAMPLE 1:** 

Eg Input

3

assignment

interview

testbcd

Output 

f

Explanation

The first 5 letters (a,b,c,d,e) occur in strings, so answer is f

**EXAMPLE 2:** 

Eg Input

2

jklaacbdefghi

mnuvwxyzopqrst

Output 

ab

Explanation

The strings contain 26 letters, so the shortest string cannot have size 1. The aa occurs as substring. So, answer is ab
