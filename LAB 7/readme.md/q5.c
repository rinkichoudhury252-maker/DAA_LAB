#include <stdio.h>

#define MAX 20

/*
   State represents all possible positions where the target
   could currently be.

   We use a simple exhaustive search to find a sequence of
   positions that guarantees finding the moving target.
*/

int n;
int solution[MAX];
int found = 0;

/* Move target to an adjacent position */
void generateNextStates(int states[], int count, int next[])
{
    for (int i = 0; i < n; i++)
        next[i] = 0;

    for (int i = 0; i < count; i++)
    {
        int pos = states[i];

        if (pos > 0)
            next[pos - 1] = 1;

        if (pos < n - 1)
            next[pos + 1] = 1;
    }
}

/* Check whether target can still be at an unchecked position */
int remainingStates(int possible[])
{
    for (int i = 0; i < n; i++)
    {
        if (possible[i])
            return 1;
    }

    return 0;
}

/*
   Simulate checking position 'check'.

   If target is found, that possibility disappears.
   Otherwise, target moves to an adjacent position.
*/
void simulate(int possible[], int check, int depth)
{
    int next[MAX] = {0};

    /* Remove the checked position */
    possible[check] = 0;

    /* Target moves after the check */
    for (int i = 0; i < n; i++)
    {
        if (possible[i])
        {
            if (i > 0)
                next[i - 1] = 1;

            if (i < n - 1)
                next[i + 1] = 1;
        }
    }

    if (!remainingStates(next))
    {
        solution[depth] = check;
        found = 1;
        return;
    }

    /*
       Try every possible checking position.
       This is an exhaustive search suitable for validating
       small values of n.
    */
    for (int p = 0; p < n && !found; p++)
    {
        int temp[MAX];

        for (int i = 0; i < n; i++)
            temp[i] = next[i];

        solution[depth] = check;

        simulate(temp, p, depth + 1);
    }
}

int main()
{
    int possible[MAX] = {0};

    printf("Enter number of hiding positions: ");
    scanf("%d", &n);

    if (n <= 1 || n > MAX)
    {
        printf("Invalid number of positions.\n");
        return 0;
    }

    /*
       Initially, the target can be in any position.
    */
    for (int i = 0; i < n; i++)
        possible[i] = 1;

    /*
       Start exhaustive search.
    */
    for (int first = 0; first < n && !found; first++)
    {
        int temp[MAX];

        for (int i = 0; i < n; i++)
            temp[i] = possible[i];

        simulate(temp, first, 0);
    }

    if (found)
    {
        printf("\nA guaranteed checking sequence exists.\n");
        printf("Sequence of positions checked:\n");

        for (int i = 0; i < MAX && solution[i] != 0; i++)
        {
            printf("%d ", solution[i] + 1);
        }

        printf("\n");
    }
    else
    {
        printf("\nNo guaranteed sequence found.\n");
    }

    return 0;
}