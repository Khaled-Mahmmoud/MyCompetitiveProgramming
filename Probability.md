```cpp
/*
A probability is a real number between 0 and 1 that indicates how probable
an event is. If an event is certain to happen, its probability is 1, and if an event
is impossible, its probability is 0. The probability of an event is denoted P(···)
where the three dots describe the event.
For example, when throwing a dice, the outcome is an integer between 1 and
6, and it is assumed that the probability of each outcome is 1/6. For example, we
can calculate the following probabilities:
• P(”the result is 4”) = 1/6
• P(”the result is not 6”) = 5/6
• P(”the result is even”) = 1/2


https://codeforces.com/contest/312/problem/B
SmallR, who shoots first can win in the following cases:
1) He shoots the target in the first shot. OR
2) He misses AND his opponent misses AND he shoots the target. OR
3) He misses AND his opponent misses AND he misses AND his opponent misses AND he shoots the target
When there is an OR between 2 events(which lead to same result) happening, it means EITHER of them will lead to the same result, 
so the probability of the result is the SUM OF ALL THESE PROBABILITIES.
the other hand, when there is AND between 2 events, it means that BOTH OF THEM SHOULD HAPPEN TO GET THE DESIRED OUTCOME. 
//////////////////////////////////////////////////////////////////////////////////////////////////
So if event A happens with probability = 1/2 and event B happens with probability = 1/2 and 
event C happens when both A and B happen, then probability of C happening is 1/2 * 1/2 = 1/4, 
which also makes sense logically. Because C will happen in only 1 out 4 cases, 
when BOTH A and B have happened. You can imagine the 4 cases:
1) A didn't happen AND B didn't happen => C didn't happen   (0 & 0 = 0)
2) A happened AND B didn't happen => C didn't happen        (1 & 0 = 0)
3) A didn't happen AND B happened => C didn't happen        (0 & 1 = 0)
4) A happened AND B happened => C happened                  (1 & 1 = 1)
P(A) = (2/4) = 1/2
P(B) = (2/4) = 1/2
P(C) = P(A) * P(B) = 1/2 * 1/2 = 1/4
///////////////////////////////////////////////////////////////////////////////////////////////
So a good rule of thumb is AND means product of probabilities and OR means sum of probabilities.
P(A) = a/b        P(A') = 1 - a/b
P(B) = c/d        P(B') = 1 - c/d
So now we can get the answer to our problem:
answer = p(A) + (P(A')*P(B') * P(A)) + P(P(A')*P(B')*P(A')*P(B') * P(A)) + ......
       = a/b + ((1-a/b)*(1-c/d) * a/b) + ((1-a/b)*(1-c/d)*(1-a/b)*(1-c/d) * a/b)... and so on.
let p= a/b ,q = (1-c/d)*(1-a/b). The answer of this problem can be showed as: p * q^0 + p * q^1 + p * q^2 + ....
this is infinite geometric series but 0 < q < 1.We can get the limit by the formula:p / (1-q).
*/
int main()
{
    double a,b,c,d,p,q;
    cin>>a>>b>>c>>d;
    p = a/b;
    q = (1-c/d)*(1-a/b);
    cout<<fixed<<setprecision(9);
    cout<<p/(1-q);
    return 0;
}
```
