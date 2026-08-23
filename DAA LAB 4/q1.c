#include <stdio.h>

typedef struct {
    int number;
    char colour;
} Item;

int main() {
    int n;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item red[n], blue[n], yellow[n];

    int r = 0, b = 0, y = 0;

    printf("Enter items in increasing number order:\n");

    for (int i = 0; i < n; i++) {
        char c;
        int num;

        scanf("%d %c", &num, &c);

        if (c == 'R' || c == 'r') {
            red[r].number = num;
            red[r].colour = 'R';
            r++;
        }
        else if (c == 'B' || c == 'b') {
            blue[b].number = num;
            blue[b].colour = 'B';
            b++;
        }
        else if (c == 'Y' || c == 'y') {
            yellow[y].number = num;
            yellow[y].colour = 'Y';
            y++;
        }
    }

    printf("\nSorted by colour:\n");

    for (int i = 0; i < r; i++)
        printf("(%d, R) ", red[i].number);

    for (int i = 0; i < b; i++)
        printf("(%d, B) ", blue[i].number);

    for (int i = 0; i < y; i++)
        printf("(%d, Y) ", yellow[i].number);

    printf("\n");

    return 0;
}