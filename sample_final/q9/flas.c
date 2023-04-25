
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

List flas(List l) {
    // TODO
    if (!l || !l->next) {
        // If the list is empty or has only one element, there's no ascending sublist.
        return NULL;
    }

    List current = l;
    List longest_start = NULL;
    List sublist_start = l;
    int longest_length = 1;
    int current_length = 1;

    while (current->next) {
        if (current->value < current->next->value) {
            // If the values are strictly increasing, update the current length.
            current_length++;
        } else {
            // If the sublist ended, check if it's longer than the current longest sublist.
            if (current_length > longest_length) {
                longest_length = current_length;
                longest_start = sublist_start;
            }
            // Reset the start of the current sublist and its length.
            sublist_start = current->next;
            current_length = 1;
        }
        current = current->next;
    }

    // Check if the last sublist is the longest.
    if (current_length > longest_length) {
        longest_length = current_length;
        longest_start = sublist_start;
    }

    if (longest_length >= 2) {
        return longest_start;
    } else {
        return NULL;
    }
}

