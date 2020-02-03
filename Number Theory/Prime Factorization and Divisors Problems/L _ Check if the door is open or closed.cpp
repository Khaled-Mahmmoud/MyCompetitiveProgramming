/*
Check if the door is open or closed
Given n doors and n persons. The doors are numbered 1 to n and persons are given id’s numbered 1 to n
Each door can have only 2 status open and closed. Initially all the doors have status closed
Find the final status of all the doors if a person changes the current status of all the doors
i.e. if status open then change to status closed and vice versa, for which he is authorized
A person with id ‘i’ is authorized to change the status of door numbered ‘j’ if ‘j’ is a multiple of ‘i’

Note:
– A person has to change the current status of all the doors for which he is authorized exactly once.
– There can be a situation that before a person changes the status of the door, another person who 
is also authorized for the same door changes the status of the door.

Input : 3
Output : open closed closed
Explanation : As n = 3, therefore there are
3 doors {1, 2, 3} and 3 persons with ids {1, 2, 3}

person with id = 1 can change the status of door 1, 2, 3
person with id = 2 can change the status of door 2
person with id = 3 can change the status of door 3

Input : 5
Output : open closed closed open closed

Note: Sequence of open/closed is displayed in increasing door number 

 Solution :
 Approach : It is mathematical and logical approach. If we observe it properly, then we find 
 that the final status of a door numbered i is open if ‘i’ has odd number of factors and status 
 is closed if ‘i’ has even number of factors
*/

bool hasEvenNumberOfFactors(int n) 
{ 
    int root_n = sqrt(n);                                                                                                                           
    if ((root_n*root_n) == n) 
        return false; 
    return true; 
} 
void printStatusOfDoors(int n) 
{ 
    for (int i=1; i<=n; i++) 
    { 
        if (hasEvenNumberOfFactors(i)) 
            cout << "closed" << " "; 
        else
            cout << "open" << " "; 
    } 
} 
// Time complexity : O(n)

/*
To know Number Of Open Doors
it's answer if floor(sqrt(n))
because we find number of odd factors between 1 and n 
more effcient number of perfect square between 1 and n
it's sqrt(n) 
example 
n = 16
it's answer = floor(sqrt(16)) = 4
1 --> it's perfect square is 1 , exists between 1 and n
2 --> it's perfect square is 4 , exists between 1 and n
3 --> it's perfect square is 9 , exists between 1 and n
4 --> it's perfect square is 16 , exists between 1 and n
5 --> it's perfect square is 25 , not exists between 1 and n
