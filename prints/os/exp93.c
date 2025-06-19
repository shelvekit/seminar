#include <stdio.h>

void main() {
    int in[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int f[3], t[3], n = 20, faults = 0, i, j, k, pos, max;

    for (i = 0; i < 3; i++) f[i] = -1;

    for (i = 0; i < n; i++) {
        int hit = 0;
        for (j = 0; j < 3; j++)
            if (f[j] == in[i]) { hit = 1; break; }

        if (!hit) {
            int empty = -1;
            for (j = 0; j < 3; j++) {
                if (f[j] == -1) {
                    f[j] = in[i];
                    faults++;
                    empty = 1;
                    break;
                }
            }

            if (empty == -1) {
                for (j = 0; j < 3; j++) {
                    t[j] = -1;
                    for (k = i + 1; k < n; k++)
                        if (f[j] == in[k]) { t[j] = k; break; }
                }

                int found = 0;
                for (j = 0; j < 3; j++)
                    if (t[j] == -1) { pos = j; found = 1; break; }

                if (!found) {
                    max = t[0]; pos = 0;
                    for (j = 1; j < 3; j++)
                        if (t[j] > max) { max = t[j]; pos = j; }
                }

                f[pos] = in[i];
                faults++;
            }
        }

        for (j = 0; j < 3; j++)
            f[j] == -1 ? printf("-\t") : printf("%d\t", f[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d", faults);
    printf("\nTotal Hits = %d\n", n - faults);
}
