#include <stdio.h>
#include <conio.h>

void main() {
    int i, sum = 0, n, disk;
    int ar[20], tm[20];
    printf("Enter number of requests:\t");
    scanf("%d", &n);
    printf("Enter initial head position:\t");
    scanf("%d", &disk);
    printf("Enter the request sequence :\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    for (i = 0; i < n; i++) {
        tm[i] = disk - ar[i];
        if (tm[i] < 0) tm[i] = -tm[i];
        sum += tm[i];
        disk = ar[i];
    }
    printf("\nMovement of cylinders = %d", sum);
    getch();
}
