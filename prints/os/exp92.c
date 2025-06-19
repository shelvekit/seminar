 #include <stdio.h>
#include <limits.h>
int checkHit(int p, int q[], int occ) {
    for (int i = 0; i < occ; i++)
        if (p == q[i]) return 1;
    return 0;
}
void printFrame(int q[], int occ) {
    for (int i = 0; i < 3; i++)
        i < occ ? printf("%d\t", q[i]) : printf("-\t");
    printf("\n");
}
void main() {
    int in[] = {1,2,3,2,1,5,2,1,6,2,5,6,3,1,3}, q[3], d[3], occ = 0, pf = 0;
    int n = sizeof(in)/sizeof(in[0]);
    printf("Page\tF1\tF2\tF3\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", in[i]);
        if (checkHit(in[i], q, occ)) { printFrame(q, occ); continue; }
        if (occ < 3) {
            q[occ++] = in[i]; pf++;
            printFrame(q, occ); continue;
        }
        for (int j = 0; j < 3; j++) {
            d[j] = 0;
            for (int k = i - 1; k >= 0; k--) {
                d[j]++;
                if (q[j] == in[k]) break;
            }
        }
        int max = 0;
        for (int j = 1; j < 3; j++)
            if (d[j] > d[max]) max = j;
        q[max] = in[i]; pf++;
        printFrame(q, occ);
    }    printf("Page Faults: %d\n", pf);
}
