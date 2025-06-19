#include <stdio.h>
#include <stdlib.h>

void main() {
    int RQ[] = {95,180,34,119,11,123,62,64}, n = 8;
    int head = 50, size = 200, move = 1, total = 0;

    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (RQ[j] > RQ[j+1]) {
                int t = RQ[j]; RQ[j] = RQ[j+1]; RQ[j+1] = t;
            }

    int i, idx;
    for (i = 0; i < n; i++) if (head < RQ[i]) { idx = i; break; }

    if (move) {
        for (i = idx; i < n; i++) total += abs(RQ[i] - head), head = RQ[i];
        total += abs(size - head - 1) + (size - 1);
        head = 0;
        for (i = 0; i < idx; i++) total += abs(RQ[i] - head), head = RQ[i];
    } else {
        for (i = idx-1; i >= 0; i--) total += abs(RQ[i] - head), head = RQ[i];
        total += abs(head - 0) + (size - 1);
        head = size - 1;
        for (i = n-1; i >= idx; i--) total += abs(RQ[i] - head), head = RQ[i];
    }

    printf("Total head movement: %d\n", total);
}
