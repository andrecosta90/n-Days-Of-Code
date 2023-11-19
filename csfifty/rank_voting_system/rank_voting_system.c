#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
void print_ranks(int ranks[]);

bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

bool dfs(int v, bool visited[], bool finished[]);
bool has_cycle(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
            preferences[i][j] = 0;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        // print_ranks(ranks);

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

void print_ranks(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        printf("%d = %d\n", i, ranks[i]);
    }
    printf("=====\n\n");
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    ranks[rank] = -1;
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (ranks[i] < 0 || ranks[j] < 0)
            {
                continue;
            }
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 1; i < candidate_count; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (preferences[i][j] != preferences[j][i])
            {

                pairs[pair_count].winner = preferences[i][j] > preferences[j][i] ? i : j;
                pairs[pair_count].loser = preferences[i][j] > preferences[j][i] ? j : i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    bool no_swaps = true;
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < pair_count - 1; j++)
        {
            int val_j = preferences[pairs[j].winner][pairs[j].loser];
            int val_j_plus1 = preferences[pairs[j + 1].winner][pairs[j + 1].loser];

            if (val_j < val_j_plus1)
            {
                pair aux = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = aux;
                no_swaps = false;
            }
        }
        if (no_swaps)
            return;
    }
    return;
}

bool dfs(int v, bool visited[], bool finished[])
{
    if (finished[v])
        return false;

    if (visited[v])
        return true;

    visited[v] = true;

    // for each neighbor
    bool has_cycle = false;
    for (int w = 0; w < candidate_count; w++)
    {
        if (locked[v][w])
        {
            if (dfs(w, visited, finished))
            {
                has_cycle = true;
                break;
            }
        }
    }
    finished[v] = true;
    return has_cycle;
}

bool has_cycle(void)
{
    bool visited[candidate_count];
    bool finished[candidate_count];

    // for every vertex v in the graph
    for (int v = 0; v < candidate_count; v++)
    {

        // initialize control variables
        for (int i = 0; i < candidate_count; i++)
        {
            visited[i] = false;
            finished[i] = false;
        }

        bool cycle_flag = dfs(v, visited, finished);
        // printf("vertex = %d -- %i\n=====\n\n", v, cycle_flag);
        if (cycle_flag)
            return true;
    }

    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{

    for (int i = 0; i < pair_count; i++)
    {
        if (pairs[i].winner == pairs[i].loser)
            continue;

        locked[pairs[i].winner][pairs[i].loser] = true;
        if (has_cycle())
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{

    for (int j = 0; j < candidate_count; j++)
    {
        int sum_col = 0;

        for (int i = 0; i < candidate_count; i++)
        {
            sum_col += locked[i][j];
        }

        if (sum_col == 0)
        {
            printf("%s\n", candidates[j]);
        }
    }

    return;
}
