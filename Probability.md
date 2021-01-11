```cpp
/*
Probability
A probability is a real number between 0 and 1 that indicates how probable an event is. 
If an event is certain to happen, its probability is 1, and if an event is impossible, its probability is 0. 
The probability of an event is denoted P(···) where the three dots describe the event.
For example, when throwing a dice, the outcome is an integer between 1 and 6, and it is assumed that 
the probability of each outcome is 1/6. For example, we can calculate the following probabilities:
• P(”the result is 4”) = 1/6
• P(”the result is not 6”) = 5/6
• P(”the result is even”) = 1/2

Calculation
To calculate the probability of an event, we can either use combinatorics or simulate the process that generates the event. 
As an example, let us calculate the probability of drawing three cards with the same value from a shuffled deck of cards
(for example, ♠8, ♣8 and ♦8).

Method 1
We can calculate the probability using the formula
(number of desired outcomes / total number of outcomes)
In this problem, the desired outcomes are those in which the value of each card is the same.
There are 13 ncr(4,3) such outcomes, because there are 13 possibilities for the value of the cards and ncr(4,3) ways 
to choose 3 suits from 4 possible suits. There are a total of ncr(52,3) outcomes, because we choose 3 cards from 52 cards.
Thus, the probability of the event is ncr(4,3) / ncr(52,3) = 1 / 425.

Method 2
Another way to calculate the probability is to simulate the process that generates the event.
In this case, we draw three cards, so the process consists of three steps.
We require that each step in the process is successful.
Drawing the first card certainly succeeds, because there are no restrictions.
The second step succeeds with probability 3/51, because there are 51 cards left
and 3 of them have the same value as the first card. In a similar way.
the third step succeeds with probability 2/50.
The probability that the entire process succeeds is 1 * (3/51) * (2/50) = 1 / 425

Events
An event in probability can be represented as a set A ⊂ X,
where X contains all possible outcomes and A is a subset of outcomes.
For example, when drawing a dice, the outcomes are X = {1,2,3,4,5,6}.
Now, for example, the event ”the result is even” corresponds to the set A = {2,4,6}.
Each outcome x is assigned a probability p(x). Furthermore, the probability
P(A) of an event that corresponds to a set A can be calculated as a sum of
probabilities of outcomes using the formula P(A) = sum(x∈A) p(x).
For example, when throwing a dice, p(x) = 1/6 for each outcome x, 
so the probability of the event ”the result is even” is p(2)+ p(4)+ p(6) = 1/2.

Since the events in probability are sets, we can manipulate them using standard set operations:
• The complement A¯ means ”A does not happen”. For example, when throwing a dice, the complement of A = {2,4,6} is A¯ = {1,3,5}.
• The union A ∪ B means ”A or B happen”, the union of A = {2,5} and B = {4,5,6} is A∪B = {2,4,5,6}.
• The intersection A ∩ B means ”A and B happen”, the intersection of A = {2,5} and B = {4,5,6} is A∩B = {5}.

Complement
The probability of the complement A¯ is calculated using the formula P(A¯) = 1 − P(A).
Sometimes, we can solve a problem easily using complements by solving the opposite problem.
For example, the probability of getting at least one six when throwing a dice ten times is 1−(5/6)^10
Here 5/6 is the probability that the outcome of a single throw is not six, and (5/6)^10 is the probability
that none of the ten throws is a six. The complement of this is the answer to the problem

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
