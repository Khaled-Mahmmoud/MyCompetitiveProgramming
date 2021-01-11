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

Sample space
the sample space of an experiment or random trial is the set of all possible outcomes or results of that experiment.
For example, if the experiment is tossing a coin, the sample space is typically the set {head, tail}.
For tossing two coins, the corresponding sample space would be {(head,head), (head,tail), (tail,head), (tail,tail)},.
If the sample space is unordered, it becomes {{head,head}, {head,tail}, {tail,tail}}.

Events
an event is a subset of the sample space.
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

Union
The probability of the union A ∪B is calculated using the formula P(A ∪ B) = P(A)+ P(B)− P(A ∩ B)
For example, when throwing a dice, the union of the events A = ”the result is even”
and B = ”the result is less than 4” is A ∪ B = ”the result is even or less than 4”,
and its probability is P(A ∪ B) = P(A)+ P(B)− P(A ∩ B) = 1/2+1/2−1/6 = 5/6.
If the events A and B are disjoint, i.e., A ∩ B is empty, the probability of the event A ∪B is simply P(A ∪ B) = P(A)+ P(B).

Conditional probability
P(A|B) = P(A ∩ B) / P(B)
is the probability of A assuming that B happens. In this situation, when calculating the probability of A,
we only consider the outcomes that also belong to B.
Using the above sets, P(A|B) = 1/3, because the outcomes of B are {1,2,3}, and one of them is even.
This is the probability of an even result if we know that the result is between 1...3.

Intersection
Using conditional probability, the probability of the intersection A ∩ B can be
calculated using the formula P(A ∩ B) = P(A)P(B|A).
Events A and B are independent if P(A|B) = P(A) and P(B|A) = P(B),
which means that the fact that B happens does not change the probability of A,
and vice versa. In this case, the probability of the intersection is P(A ∩ B) = P(A)P(B).
For example, when drawing a card from a deck, the events A = ”the suit is clubs” and
B = ”the value is four” are independent. Hence the event A ∩ B = ”the card is the four of clubs”
happens with probability P(A ∩ B) = P(A)P(B) = 1/4·1/13 = 1/52

Random variables
A random variable is a value that is generated by a random process. 
For example, when throwing two dice, a possible random variable is X = ”the sum of the results”.
For example, if the results are [4,6] (meaning that we first throw a four and then a six), then the value of X is 10.
We denote P(X = x) the probability that the value of a random variable X is x. 
For example, when throwing two dice, P(X = 10) = 3/36, because the total number of outcomes is 36
and there are three possible ways to obtain the sum 10: [4,6], [5,5] and [6,4].

Expected value
The expected value E[X] indicates the average value of a random variable X.
The expected value can be calculated as the sum(x) P(X = x)x, where x goes through all possible values of X.
Let X be a random variable with a finite number of finite outcomes x1,x2,x3,...xk occurring with probabilities 
p1,p2,p3,...,pk respectively. The expectation of X is defined as E[X] = sum(i=1,k) xi pi = x1p1 + x2p2 + x3p3 + .... + xkpk.
Since p1 + p2 + p3 +...+ pk = 1
For example, when throwing a dice, the expected result is 1/6·1+1/6·2+1/6·3+1/6·4+1/6·5+1/6·6 = 7/2.
A useful property of expected values is linearity. 
It means that the sum E[X1 + X2 + ··· + Xn] always equals the sum E[X1] + E[X2] + ··· + E[Xn]. 
This formula holds even if random variables depend on each other.
For example, when throwing two dice, the expected sum is E[X1 + X2] = E[X1] + E[X2] = 7/2 + 7/2 = 7.
Let us now consider a problem where n balls are randomly placed in n boxes,
and our task is to calculate the expected number of empty boxes. 
Each ball has an equal probability to be placed in any of the boxes.
For example, if n = 2, the possibilities are as follows: (.)(-), (-)(.), (.-)(), ()(.-)
In this case, the expected number of empty boxes is (0+0+1+1) / 4 = 1/2
In the general case, the probability that a single box is empty is ((n-1) / n)^n
Hence, using linearity, the expected number of empty boxes is n * ((n-1) / n)^n

Distributions
The distribution of a random variable X shows the probability of each value that X may have.
The distribution consists of values P(X = x). For example, when throwing two dice, the distribution for their sum is:
x          2   3    4    5    6    7    8    9    10   11  12
P(X = x) 1/36 2/36 3/36 4/36 5/36 6/36 5/36 4/36 3/36 2/36 1/36

Uniform Distribution
the random variable X has n possible values a,a+1,...,b and the probability of each value is 1/n. 
For example, when throwing a dice, a = 1, b = 6 and P(X = x) = 1/6 for each value x.
The expected value for X in a uniform distribution is E[X] = (a + b)/2

Binomial Distribution
n attempts are made and the probability that a
single attempt succeeds is p. The random variable X counts the number of successful attempts,
and the probability for a value x is P(X = x) = p^x * (1 − p)^(n−x) * ncr(n,x) where p^x and (1 − p)^n−x 
correspond to successful and unsuccessful attemps, and ncr(n,x) is the number of ways we can choose the order of the attempts.
For example, when throwing a dice ten times, the probability of throwing a six exactly three times is (1/6)^3 * (5/6)^7 * ncr(10,3)
The expected value for X in a binomial distribution is E[X] = pn

Geometric Distribution
the probability that an attempt succeeds is p, and we continue until the first success happens. 
The random variable X counts the number of attempts needed, and the probability for a value x is P(X = x) = (1 − p)^(x−1) p,
where (1 − p)^x−1 corresponds to unsuccessful attemps and p corresponds to the first successful attempt.
For example, if we throw a dice until we throw a six, the probability that the number of throws is exactly 4 is (5/6)^3 * 1/6.
The expected value for X in a geometric distribution is E[X] = 1/p

Markov chains
A Markov chain is a random process that consists of states and transitions between them.
For each state, we know the probabilities for moving to other states. 
A Markov chain can be represented as a graph whose nodes are states and edges are transitions.
As an example, consider a problem where we are in floor 1 in an n floor building. 
At each step, we randomly walk either one floor up or one floor down, except that we always walk one floor up from floor 1 
and one floor down from floor n. What is the probability of being in floor m after k steps?
In this problem, each floor of the building corresponds to a state in a Markov chain. 
For example, if n = 5, the graph is as follows:

    1     1/2    1/2    1/2
  ---->   ---->  ---->  ---->
(1)    (2)    (3)    (4)    (5)  
  <----  <----  <----  <-----
   1/2    1/2    1/2     1

The probability distribution of a Markov chain is a vector [p1, p2,..., pn], 
where pk is the probability that the current state is k. The formula p1 + p2 +···+ pn = 1 always holds.
In the above scenario, the initial distribution is [1,0,0,0,0], because we always begin in floor 1. 
The next distribution is [0,1,0,0,0], because we can only move from floor 1 to floor 2. 
After this, we can either move one floor up or one floor down, so the next distribution is [1/2,0,1/2,0,0], and so on.
An efficient way to simulate the walk in a Markov chain is to use dynamic programming. 
The idea is to maintain the probability distribution, and at each step go through all possibilities how we can move. 
Using this method, we can simulate a walk of m steps in O(n^2m) time.
The transitions of a Markov chain can also be represented as a matrix that updates the probability distribution.
In the above scenario, the matrix is
| 0 1/2  0   0  0 |
| 1  0  1/2  0  0 |
| 0 1/2  0  1/2 0 |
| 0  0  1/2  0  1 |
| 0  0   0  1/2 0 |
When we multiply a probability distribution by this matrix, we get the new distribution after moving one step. 
For example, we can move from the distribution [1,0,0,0,0] to the distribution [0,1,0,0,0] as follows:
| 0 1/2  0   0  0 | |1|   |0|
| 1  0  1/2  0  0 | |0|   |1|
| 0 1/2  0  1/2 0 |.|0| = |0|
| 0  0  1/2  0  1 | |0|   |0|
| 0  0   0  1/2 0 | |0|   |0|
By calculating matrix powers efficiently, we can calculate the distribution after m steps in O(n^3 log m) time.

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
