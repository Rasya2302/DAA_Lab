#include <stdio.h>

#define MAX 100

struct Scientist
{
    char name[50];
    int birth;
    int death;
};

int main()
{
    int n;
    struct Scientist s[MAX];

    printf("Enter number of scientists: ");
    scanf("%d", &n);

    // Input scientist details
    for (int i = 0; i < n; i++)
    {
        printf("\nScientist %d\n", i + 1);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Birth year: ");
        scanf("%d", &s[i].birth);

        printf("Death year: ");
        scanf("%d", &s[i].death);
    }

    int bestYear = s[0].birth;
    int maximum = 0;

    // Check every possible year
    for (int year = s[0].birth; year <= s[n - 1].death; year++)
    {
        int count = 0;

        // Count scientists alive in this year
        for (int i = 0; i < n; i++)
        {
            if (s[i].birth <= year && year < s[i].death)
            {
                count++;
            }
        }

        // Update maximum
        if (count > maximum)
        {
            maximum = count;
            bestYear = year;
        }
    }

    printf("\nBest time to be alive: %d\n", bestYear);
    printf("Number of scientists alive: %d\n", maximum);

    return 0;
}