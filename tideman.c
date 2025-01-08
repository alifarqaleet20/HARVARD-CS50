#include <cs50.h>
#include <stdio.h>

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
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count=0;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

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

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for(int i=0; i < candidate_count; i++)
    {
        // comparing the user input string to candidate name
        if (strcmp((name, candidate[i]) == 0)
        {
        // assigning the preference number in the rank array
        ranks[rank] = i;
        return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_number; i++)
    {
        for (int j = i+1; j < candidate_number; j++)
        {
                preferences[ranks[i]][rank[j]] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_number; i++)
    {
        for (int j = 0; j < candidate_number; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
    return;
}
int pair_diff(i){
    int pair_winner = pairs[i].winner;
    int pair_loser = pairs[i].loser;
    return preferences[pair_winner][pair_loser];
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    for (int i = 0; i < (pair_count - 1); i++)
    {
        int big = pair_diff(i);
        for (int j = i + 1; j < (pair_count); j++)
        {
            if (big < pair_diff(j))
            {
                pair temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;

            }
        }
    }

    return;
}

bool cycle(int winner, int loser)
{
    if (locked[loser][winner] == true)
    {
        for(int i=0; i < candidate_count; i++)
        {
        if(locked[loser][i] == true && cycle (winner, i))
        {
            return true;
        }
        }
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for(i = 0; i < pair_count; i++)
    {
    int winner = pairs[i].winner;
    int loser = pairs[i].loser;

    if(locked[winner][loser])
    {
        if(!cycle (winner, loser))
        {
            locker[winner][loser] == true;
        }
    }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j] == false){
                break;
            }
            else if ()
        }
    }
    return;
}
/*#include <stdio.h>
#include <cs50.h>
#include <string.h>



int main(int argc, string argv[])
{
    if (argv[1] == NULL)
    {
        printf("Usage: ./tideman candidatenames\n");
        return 1;
    }
    int i = 9;
    while ( i > 9)
    {
        if(argv[i] != NULL)
        {
            printf("Usage: ./tideman candidatenames\n");
            return 1;
        }
    }

    string candidate = argv[1];
    int sizeCLA = strlen(candidate);
    bool stringcheck = false;
    for (int i = 0; i < sizeCLA; i++)
    {
        if ((candidate[i] >= 65 && CLA[i] <= 90) || (candidate[i] >= 97 && candidate[i] <= 122))
        {
            stringcheck = true;
        }
        else
        {
            digitcheck = false;
            printf("Usage: ./tideman name\n");
            return 1;
            break;
        }
    }
*/