
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

#define INT_MAX 2147483647

void collect_values_on_level(BSTree t, int l, int current_level, int *values, int *count) {
    if (t == NULL) {
        return;
    }

    if (current_level == l) {
        values[*count] = t->key;
        (*count)++;
    } else {
        collect_values_on_level(t->left, l, current_level + 1, values, count);
        collect_values_on_level(t->right, l, current_level + 1, values, count);
    }
}

int compare_ints(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int minDiff(BSTree t, int l) {
    // TODO
    if (t == NULL) {
        return 0;
    }

    int values[1000];
    int count = 0;
    collect_values_on_level(t, l, 0, values, &count);

    if (count <= 1) {
        return 0;
    }

    qsort(values, count, sizeof(int), compare_ints);

    int min_diff = INT_MAX;
    for (int i = 1; i < count; i++) {
        int diff = values[i] - values[i - 1];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    return min_diff;
}

