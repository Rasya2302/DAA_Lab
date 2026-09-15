#include <stdio.h>

#define MAX 20

int queue[1 << MAX];
int distance[1 << MAX];

int main()
{
    int n;

    printf("Enter number of switches: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid input\n");
        return 0;
    }

    int start = (1 << n) - 1;   // All switches ON
    int goal = 0;               // All switches OFF

    int front = 0;
    int rear = 0;

    // Put starting state into queue
    queue[rear++] = start;
    distance[start] = 0;

    while (front < rear)
    {
        int state = queue[front++];

        // We reached all OFF
        if (state == goal)
        {
            printf("Minimum number of moves = %d\n",
                   distance[state]);
            return 0;
        }

        // Try toggling every switch
        for (int i = 0; i < n; i++)
        {
            int allowed = 1;

            // Rightmost switch can always be toggled
            if (i != n - 1)
            {
                // Switch immediately to the right must be ON
                if ((state & (1 << (i + 1))) == 0)
                    allowed = 0;

                // All switches further right must be OFF
                for (int j = i + 2; j < n; j++)
                {
                    if (state & (1 << j))
                        allowed = 0;
                }
            }

            if (allowed)
            {
                // Toggle switch i
                int newState = state ^ (1 << i);

                // If this state is visited for the first time
                if (distance[newState] == 0 && newState != start)
                {
                    distance[newState] =
                        distance[state] + 1;

                    queue[rear++] = newState;
                }
            }
        }
    }

    return 0;
}