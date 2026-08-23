#include <stdio.h>
#include <string.h>

struct Item {
    int number;
    char colour[10];
};

int main() {
    int n;
    scanf("%d", &n);

    struct Item red[n], blue[n], yellow[n];
    int r = 0, b = 0, y = 0;

    for (int i = 0; i < n; i++) {
        struct Item item;
        scanf("%d %s", &item.number, item.colour);

        if (strcmp(item.colour, "Red") == 0)
            red[r++] = item;
        else if (strcmp(item.colour, "Blue") == 0)
            blue[b++] = item;
        else
            yellow[y++] = item;
    }

    for (int i = 0; i < r; i++)
        printf("%d Red\n", red[i].number);

    for (int i = 0; i < b; i++)
        printf("%d Blue\n", blue[i].number);

    for (int i = 0; i < y; i++)
        printf("%d Yellow\n", yellow[i].number);

    return 0;
}