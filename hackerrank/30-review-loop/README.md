# Review Loop

## Objective
Today we will expand our knowledge of strings, combining it with what we have already learned about loops.

## Task
Given a string, $S$, of length $N$ that is indexed from $0$ to $N-1$, print its even-indexed and odd-indexed characters as $2$ space-separated strings on a single line .

**Note**: $0$ is considered to be an even index.

## Example

`s = adbecf`

Print => `abc def`

## Input Format

The first line contains an integer, $T$ (the number of test cases).

Each line $i$ of the $T$ subsequent lines contain a string, $S$.

## Constraints

+ $1 \leq T \leq 10$
+ $2 \leq |S| \leq 10000$

## Output Format

For each String $S_i$ (where $0 \leq j \leq T-1$), print $S_j$'s even-indexed characters, followed by a space, followed by $S_j$'s odd-indexed characters.

## Sample Input

```
2
Hacker
Rank
```

## Sample Output
```
Hce akr
Rn ak
```