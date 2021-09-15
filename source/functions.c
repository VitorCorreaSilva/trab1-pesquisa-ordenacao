#include "functions.h"


int* generate_random_number(int n)
{
    srand(time(NULL));
    int* out = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        out[i] = rand() % 1000;  
    }
    return out;
}

average* average_bigger_smaller(int* numbers, int size)
{
    int sum = 0;
    average* avg;
    avg = (average*) malloc(sizeof(average*));
    for (int i = 0; i < size; ++i)
    {
        sum = sum + numbers[i];

        if (i == 0)
        {
            avg->menor = numbers[i];
            avg->maior = numbers[i];
        }
        else
        {
            if (avg->menor < numbers[i])
            {
                avg->menor = numbers[i];
            }
            else if (avg->maior > numbers[i])
            {
                avg->maior = numbers[i];
            }
        }
    }

    avg->media = (float)sum/(float)size;

    return avg;
}


FILE* open_file(char* filename, char* mode)
{
    FILE* fptr;
    if ((fptr = fopen(filename, mode)) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }
    return fptr;
}

int* insertion_sort(int* numbers, int size)
{
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = numbers[i];
        j = i - 1;
        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }
        numbers[j + 1] = key;
    }

    return numbers;
}

int* reverse_elements(int* numbers, int size)
{
    int* tmp = (int*) malloc(size * sizeof(int));
    int var = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        tmp[var] = numbers[i];
        var++;
    }
    return tmp;
}

void write_in_file(char* filename, int* numbers, int size)
{   
    FILE *fptr = open_file(filename, "w");

    for (int i = 0; i < size - 1; i++)
    {
        fprintf(fptr,"%d;", numbers[i]);
    }
    fprintf(fptr,"%d", numbers[size - 1]);

    fclose(fptr);
}

void write_average_in_file(char* filename, average* avg)
{   
    FILE *fptr = open_file(filename, "w");

    fprintf(fptr,"Menor: %d \n", avg->menor);
    fprintf(fptr,"Maior: %d \n", avg->maior);
    fprintf(fptr,"Media: %.2f", avg->media);

    fclose(fptr);
}

int* load_file(char* filename, int n)
{
    int i = 0;
    char* token;
    char* str = (char*) malloc(1024 * sizeof(char));
    int* out  = (int*) malloc(n * sizeof(int));

    FILE *fptr = open_file(filename, "r");
    
    fgets(str,1024,fptr);
    
    fclose(fptr);

    token = strtok(str, ";");

    while( token != NULL ) {
        out[i] = atoi(token);
        token = strtok(NULL, ";");
        i++;
    }

    return out;
}

int int_to_bin(int k) 
{
    if (k == 0) return 0;
    if (k == 1) return 1;
    return (k % 2) + 10 * int_to_bin(k / 2);
}

int* convert_to_binary(int* numbers, int size)
{
    for (int i = 0; i < size; ++i)
    {
        numbers[i] = int_to_bin(numbers[i]);
    }

    return numbers;
}