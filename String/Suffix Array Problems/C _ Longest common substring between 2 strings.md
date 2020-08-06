# Longest common substring between 2 strings

given two strings A and B find Longest common substring between them, we concatenate them as S=A#B, where # is a character not present in both A and B. 
The reason for choosing such a character is so that when computing the LCP of two suffixes, the comparison will break off at the end of the first string
(since it only occurs once, two different suffixes will never have it in the same position), and won't "overflow" into the other string.

Keep checking the LCP array for the maximum value such that the two suffixes being compared do not belong to the same original string.
If they don't belong to the same original string (one begins in A and the other in B), then the largest such value is the length of the largest common substring.

As an example, consider A=abcabc and B=bc. Then, S=abcabc#bc. Sorted suffixes are {abc#bc,abcabc#bc,bc,bc#bc,bcabc#bc,c,c#bc,cabc#bc}.
SALCP=[4,1,8,5,2,9,6,3,7]=[−,3,0,2,2,0,1,1,0]
Now, the greatest value is LCP[2]=3, but it is for SA[1] and SA[2], both of which start in the string A. So, we ignore that.
On the other hand, LCP[4]=2 is for SA[3] (corresponds to the suffix bc of B) and SA[4] (corresponding to suffix bcabc#bc of A). 
So, this is the longest common substring between the two strings. 
For getting the actual substring, you take a length 2 (value of the greatest feasible LCP) substring starting from either SA[3] or SA[4], which is bc.

