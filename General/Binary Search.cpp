/*
Binary Search is a searching algorithm in which you can find an element in a sorted big range of possible solutions but in each iteration
we erase half of the range . Such solution takes no more than O(logn) which is really small even for really big numbers
*/
@https://translate.google.com/#view=home&op=translate&sl=en&tl=ar
https://translate.google.com/#view=home&op=translate&sl=en&tl=ar
#https://translate.google.com/#view=home&op=translate&sl=en&tl=ar
#include <bits/stdc++.h>
using namespace std;

// Check if the given value fulfills a certain criteria or not.
// The function must be a monotonic function matching the binary search type (min or max).
bool valid(int m) {
	// TODO: to be implemented
	return 1;
}

// Binary search on the minimum value fulfilling a certain criteria
int binarySearch() {
	int l = 0, r = 1e9;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (valid(mid))
            r = mid;
        else
            l = mid + 1;
    }
}
2
