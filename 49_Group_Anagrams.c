
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    int used;
    unsigned int freq[26];
    int group;
} HashEntry;

uint64_t hashFrequency(unsigned int freq[26]) {
    uint64_t hash = 1469598103934665603ULL;

    for (int i = 0; i < 26; i++) {
        hash ^= freq[i];
        hash *= 1099511628211ULL;
    }

    return hash;
}

char*** groupAnagrams(
    char** strs,
    int strsSize,
    int* returnSize,
    int** returnColumnSizes
) {

    *returnSize = 0;

    *returnColumnSizes = malloc(strsSize * sizeof(int));

    char*** result = malloc(strsSize * sizeof(char**));

    int* capacities = calloc(strsSize, sizeof(int));

    // Hash table size
    int tableSize = 1;

    while (tableSize < strsSize * 2) {
        tableSize *= 2;
    }

    HashEntry* table = calloc(tableSize, sizeof(HashEntry));

    for (int i = 0; i < strsSize; i++) {

        // Step 1: Calculate frequency
        unsigned int freq[26] = {0};

        for (int j = 0; strs[i][j] != '\0'; j++) {
            freq[strs[i][j] - 'a']++;
        }

        // Step 2: Generate hash
        uint64_t hash = hashFrequency(freq);

        int index = hash & (tableSize - 1);

        // Step 3: Find existing group
        while (table[index].used &&
               memcmp(table[index].freq, freq,
                      sizeof(freq)) != 0) {

            index = (index + 1) & (tableSize - 1);
        }

        // Step 4: Create new group if necessary
        if (!table[index].used) {

            table[index].used = 1;

            memcpy(table[index].freq, freq, sizeof(freq));

            table[index].group = (*returnSize);

            int g = (*returnSize);

            result[g] = malloc(sizeof(char*));

            capacities[g] = 1;

            (*returnColumnSizes)[g] = 0;

            (*returnSize)++;
        }

        // Step 5: Add string to its group
        int g = table[index].group;

        if ((*returnColumnSizes)[g] == capacities[g]) {

            capacities[g] *= 2;

            result[g] = realloc(
                result[g],
                capacities[g] * sizeof(char*)
            );
        }

        result[g][(*returnColumnSizes)[g]] = strs[i];

        (*returnColumnSizes)[g]++;
    }

    free(table);
    free(capacities);

    return result;
}

