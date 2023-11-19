# Ranked-Pairs Voting Method

The Ranked-Pairs voting method, a ranked-choice system, aims to determine the Condorcet winner in an election. Voters rank candidates, and the algorithm constructs a graph of pairwise victories. The winner is the candidate with no arrows pointing towards them, representing a lack of head-to-head preference by voters. The process involves tallying preferences, sorting victories by strength, and locking in pairs without creating cycles in the graph. Ranked Pairs ensures a fair outcome by avoiding ties and selecting the candidate preferred in all head-to-head matchups.

For more details, refer to following [link](https://cs50.harvard.edu/x/2023/psets/3/tideman/).