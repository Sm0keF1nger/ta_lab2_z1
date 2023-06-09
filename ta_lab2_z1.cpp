#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing table data
struct Material {
    char substance[20];
    char type[2];
    char moisture[8];
    float coefficient;
};

// Comparison function for sorting
int compare(const void* a, const void* b) {
    struct Material* materialA = (struct Material*)a;
    struct Material* materialB = (struct Material*)b;
    return (materialA->coefficient > materialB->coefficient) - (materialA->coefficient < materialB->coefficient);
}

int main() {
    // Declaration of structure array
    struct Material materials[] = {
        {"Aluminum", "M", "0-100", 209.3},
        {"Glass wool", "T", "0-100", 0.035},
        {"Clay", "I", "15-20", 0.73}
    };

    // Calculating the number of rows in the table
    int numRows = sizeof(materials) / sizeof(materials[0]);

    // Sorting the table by the values in the first column
    qsort(materials, numRows, sizeof(materials[0]), compare);

    // Printing the sorted table to the screen
    printf("%-10s %-10s %-12s %-10s\n", "Substance", "Type", "Moisture (%)", "Coefficient");
    printf("-----------------------------------------\n");
    for (int i = 0; i < numRows; i++) {
        printf("%-10s %-10s %-12s %-10.2f\n", materials[i].substance, materials[i].type, materials[i].moisture, materials[i].coefficient);
    }

    return 0;
}