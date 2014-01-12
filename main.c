/* 
 * File:   main.c
 * Author: drummer
 *
 * Created on 11. Januar 2014, 14:28
 */

#include <stdio.h>
#include <stdlib.h>

int numbers[] = {0, 9, -4, 8, 11, 2, 16, 5};

void insertionSort() {

    int numberOfElements = sizeof (numbers) / sizeof (int);

    int i;
    for (i = 1; i < numberOfElements; i++) {
        int temp = numbers[i];
        int j = i - 1;

        while (j >= 0 && numbers[j] > temp) {
            numbers[j + 1] = numbers[j];
            j--;
        }

        numbers[j + 1] = temp;
    }

    for (i = 0; i < numberOfElements; i++) {
        printf("%i ", numbers[i]);
    }
}

void bubble() {

    int numberOfElements = sizeof (numbers) / sizeof (int);
    int i;
    for (i = 0; i < numberOfElements; i++) {

        int j;
        for (j = 0; j < numberOfElements - i - 1; j++) {
            if (numbers[j + 1] < numbers[j]) {
                // swap
                int tmp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = tmp;
            }
        }
    }

    for (i = 0; i < numberOfElements; i++) {
        printf("%i ", numbers[i]);
    }
}

void doQuick(int indexPivot, int startIndex) {

    // find greater
    int i;
    for (i = startIndex; i < indexPivot; i++) {

        if (i == indexPivot - 1) {
            // switch if necessary and terminate
            if (numbers[i] > numbers[indexPivot]) {
                int tmp = numbers[i];
                numbers[i] = numbers[indexPivot];
                numbers[indexPivot] = tmp;
            }

            break;
        }

        if (numbers[i] > numbers[indexPivot]) {
            // find lesser
            int j;
            for (j = indexPivot - 1; j >= i; j--) {

                if (j == i) {
                    // switch with pivot and do recursion
                    int tmp = numbers[i];
                    numbers[i] = numbers[indexPivot];
                    numbers[indexPivot] = tmp;

                    // left side
                    doQuick(i - 1, startIndex);
                    // right side
                    doQuick(indexPivot, i + 1);
                    break;

                } else if (numbers[j] < numbers[indexPivot]) {
                    // switch j with i
                    int tmp = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = tmp;
                    break;
                }
            }
        }
    }

    // if index pivot and index pivot - 1 terminate
}

void output() {
    int numberOfElements = sizeof (numbers) / sizeof (int);
    int i;
    for (i = 0; i < numberOfElements; i++) {
        printf("%i ", numbers[i]);
    }
}

/**
 * 
 */
void quick() {

    int numberOfElements = sizeof (numbers) / sizeof (int);

    doQuick(numberOfElements - 1, 0);

    output();
}

/*
 * 
 */
int main(int argc, char** argv) {

    //    insertionSort();
    //    bubble();
    quick();

    return (EXIT_SUCCESS);
}

