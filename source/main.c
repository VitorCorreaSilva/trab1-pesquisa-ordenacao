#include "functions.h"

int main()
{
    int n;

    printf("Digite a quantidade de numeros para gerar no arquivo: ");
    scanf("%d", &n);  

    int* random_numbers = generate_random_number(n);
    write_in_file("files/numbers.txt", random_numbers, n);

    int* r = load_file("files/numbers.txt", n);
    int* d = (int*) malloc(n * sizeof(int)); 
    int* p = (int*) malloc(n * sizeof(int));
    int* z = (int*) malloc(n * sizeof(int));
    average* v;

    int opcao;
    do{
        printf("\n \n");
        printf("1 - Gerar arquivo com numeros inversos \n");
        printf("2 - Gerar arquivo com numeros ordenados \n");
        printf("3 - Gerar arquivo mostrando a media, o maior e menor numero \n");
        printf("4 - Gerar arquivo com numeros binarios \n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        printf("\n");
        switch(opcao)
        {
            case 0:
                printf("Encerrando... \n");
            break;
            case 1:
                d = reverse_elements(r,n);
                write_in_file("files/inverse_numbers.txt", d, n);
                printf("inverse_numbers.txt criado com sucesso! \n");
            break;
            case 2:
                p = insertion_sort(r,n);
                write_in_file("files/insertion_sort.txt", p, n);
                printf("insertion_sort.txt criado com sucesso! \n");
            break;
            case 3:
                v = average_bigger_smaller(r,n);
                write_average_in_file("files/average_bigger_smaller.txt",v);
                printf("average_bigger_smaller.txt criado com sucesso! \n");
            break;
            case 4:
                z = convert_to_binary(r,n);
                write_in_file("files/binary_numbers.txt", z, n);
                printf("binary_numbers.txt criado com sucesso! \n");
            break;
            default:
                printf("Escolha um opcao valida... \n");
            break;
        }
    }while(opcao != 0);
    
    free(r);

    return 0;
}