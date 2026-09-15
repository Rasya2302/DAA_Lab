#include <stdio.h>

#define MAX 20

int main()
{
    int n;
    int possible[MAX];

    printf("Enter number of hiding spots: ");
    scanf("%d", &n);

    if (n <= 1 || n > MAX)
    {
        printf("Enter n greater than 1.\n");
        return 0;
    }

    // Initially target can be anywhere
    for (int i = 0; i < n; i++)
    {
        possible[i] = 1;
    }

    printf("\nShooting process:\n");

    for (int shot = 1; shot <= 2 * n; shot++)
    {
        int shoot;

        // Shoot at a suitable position
        shoot = (shot % n);

        if (shoot == 0)
            shoot = n;

        printf("Shot %d -> Spot %d\n", shot, shoot);

        // Remove the spot that was shot
        possible[shoot - 1] = 0;

        // Move target to adjacent spots
        int next[MAX] = {0};

        for (int i = 0; i < n; i++)
        {
            if (possible[i] == 1)
            {
                if (i > 0)
                    next[i - 1] = 1;

                if (i < n - 1)
                    next[i + 1] = 1;
            }
        }

        // Copy new possible positions
        for (int i = 0; i < n; i++)
        {
            possible[i] = next[i];
        }

        // Check whether target can still exist
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (possible[i] == 1)
            {
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            printf("\nTarget is guaranteed to be hit.\n");
            printf("Number of shots = %d\n", shot);
            return 0;
        }
    }

    printf("\nTarget is still possible.\n");

    return 0;
}