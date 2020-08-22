# Terminology
```
K#*8w
W8#m+3*(u(-
```
**proper divisors of number**

is all divisors of number excluding the number itself
For instance, 6 has divisors 1, 2, 3 and 6 but it's proper divisors is 1, 2, 3

**perfect number**

is a positive integer that is equal to the sum of its proper divisors
For instance, 6 has divisors 1, 2 and 3 (excluding itself), and 1 + 2 + 3 = 6, so 6 is a perfect number

**square number or perfect square**

is an integer that is the square of an integer 
in other words it is the product of some integer with itself
For example, 9 is a square number, since it can be written as 3 × 3

**square root** 

square root of a number x is a number y such that y^2 = x

**Unit digit of a number**

It is the rightmost digit of the number.
For example, the unit digit of 243 is 3, the unit digit of 39 is 9

******************************************************************************************************************************************************

**Subarray**

A subarray is a slice from the array which is contiguous (i.e. occupy consecutive positions) and inherently maintains the order of 
elements. For example, the subarrays of the array {1, 2, 3} are {1}, {1, 2}, {1, 2, 3}, {2}, {2, 3}, and {3}.
Please note that there are exactly `n * (n+1)/2` subarrays in an array of size n. Also, there is no such thing as contiguous subarray. 
The prefix contiguous is sometimes applied to make context more clear. 


**Substring**

A substring of a string s is that occurs in s. A substring is almost similar to a subarray but it is in context of strings. 
For example , the substrings of 'apple' are 'a' , 'ap' , 'app' , 'appl' , 'apple' , 'p' , 'pp' , 'ppl' , 'pple' , 'p' , 'pl' ,
'ple' , 'l' , 'le' , 'e'.
Please note that there are exactly `n * (n+1)/2` subtrings in an string of size n


**Subsequence**

A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of 
the remaining elements.
For example, {A, B, D} is a subsequence of sequence {A, B, C, D, E} that is obtained after removing {C} and {E}. 
. A subarray will always be contiguous but a subsequence need not be 
contiguous. That is, unlike subarrays, subsequences are not required to occupy consecutive positions within the original sequences. 
For example, {A, C, E} is a subsequence of {A, B, C, D, E}, but not a substring and {A, B, c} is both a subarray and a subsequence. 

For example , the subsequence of { 1 , 2 , 3 , 4 } are { 1 } , { 1 , 2 } , { 1 , 2 , 3 } , { 1 , 2 , 3 , 4 } , { 2 } , { 2 , 3 } ,
{ 2 , 3 , 4 } , { 3 } , { 3 , 4 } , { 4 } ,      { 1 , 3 } ,{ 1 , 3 , 4 } , { 1 , 2 , 4 } , { 1 , 4 } , { 2 , 4 }

Please note that a Subsequence can be in context of both arrays and string and there is not empty sebsequence.
Generating all subsequences of an array/string is equivalent to generating power set of the array/string - 1. 
For a given set S, the number of subsequences equals `2^n - 1`


**Subset**

A subset is any possible combination of the original set. The term subset is often used for subsequence but this is wrong.
A subsequence always maintain the relative order of elements of the array (i.e. increasing index) but there is no such 
restriction on a subset. For example {3, 1} is a valid subset of {1, 2, 3, 4, 5} but it is neither a subsequence or a subarray. 

It is worth noting that all subarrays are subsequences and all subsequences are subset but the reverse is not true. 
For instance, the subarray {1, 2} of the array {1, 2, 3, 4, 5} is also a subsequence and a subset. 

For example, all subsets of { 1 , 2 , 3 } is { } , { 1 } , { 1 , 2 } , { 2 , 1 } , { 2 } , { 2 , 3 } , { 3 , 2 } ,
{ 3 } , { 1 , 3 } , { 3 , 1 } , { 1 , 2 , 3 } , { 1 , 3 , 2 } , { 2 , 1 , 3 } , { 2 , 3 , 1 } , { 3 , 1 , 2 } , { 3 , 2 , 1 }

but subset {1,2} as same subset {2,1}

so , we can announce that sebsets of { 1 , 2 , 3 } is {}, {1}, {2}, {3}, {1, 2}, {2, 3}, {3, 1}, {1, 2, 3}.

Please note that there is empty subset 
Generating all subsets of an array/string is equivalent to generating power set of the array/string. 
For a given set S, the number of subsets equals the power set `2^n` 

**Summary**

A subarray/substring has Order and Continuity :   `n*(n+1)/2`

A subsequence has Order but not Continuity :       `2^n - 1` 

A subset does not Order nor Continuity :          `2^n` 

******************************************************************************************************************************************************

Given string s = abcd

**Prefix** (n prefixes)

Any string that start from first character
such that : a , ab , abc , abcd

**Proper Prefix** (n-1 prefixes)

Any prefix of S except S itself
such that : a , ab , abc.
then string of 1 letter , has no proper prefix

**Suffix** (n suffixes)

Any string that ends at last character
such that : d , cd , bcd , abcd

**Proper Suffix** (n-1 suffixes)

Any suffix of S except S itself
such that : d , cd , bcd.
then string of 1 letter , has no proper suffix

******************************************************************************************************************************************************
**Rational Numbers** : can be represented as **fraction** : 1/6 , 7/2. **Irrational** : pi = 3.1415 , sqrt(2)
