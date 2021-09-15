#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct{
    int maior;
    int menor;
    float media;
} average;

int* generate_random_number(int n);
int* insertion_sort(int* numbers, int size);
int* reverse_elements(int* numbers, int size);
int* load_file(char* filename, int n);
int int_to_bin(int k);
int* convert_to_binary(int* numbers, int size);
void write_in_file(char* filename, int* numbers, int size);
void write_average_in_file(char* filename, average* avg);
FILE* open_file(char* filename, char* mode);
average* average_bigger_smaller(int* numbers, int size);

#endif