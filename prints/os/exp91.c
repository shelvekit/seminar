#include <stdio.h>
void main() {
    int a[] = {4,1,2,4,5}, f[3] = {-1,-1,-1}, i, j, k = 0, pf = 0;
    printf("Page\tF1\tF2\tF3\n");
    for (i = 0; i < 5; i++) {
        int hit = 0;
        for (j = 0; j < 3; j++) if (f[j] == a[i]) hit = 1;
        if (!hit) { f[k] = a[i]; k = (k + 1) % 3; pf++; }
        printf("%d\t", a[i]);
        for (j = 0; j < 3; j++) ( f[j] == -1 ) ? printf("-\t") : printf("%d\t", f[j]);
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pf);
}
