#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// define um novo tipo, byte
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // abre arquivo com nome passado por parametro
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("could not open the file: %s\n", argv[1]);
        return 1;
    }
    // marcador do número de jpegs encontrados
    int count = 0;

    FILE *img = NULL;
    BYTE *arr = malloc(sizeof(BYTE) * 512);
    char filename[8];

    while (fread(arr, sizeof(BYTE), 512, file) != 0)
    {
        // procura o padrão jpeg de 4 bytes no inicio de cada bloco de 512
        if (arr[0] ==  0xff && arr[1] == 0xd8 && arr[2] == 0xff && (arr[3] & 0xf0) == 0xe0)
        {
            // seta o nome para o arquivo
            sprintf(filename, "%03i.jpg", count);

            // se for o primeiro jpeg encontrado
            if (count == 0)
            {
                // formata string para ser usada no nome de cada jpeg recuperado

                img = fopen(filename, "w");
                fwrite(arr, sizeof(BYTE), 512, img);
                count++;
            }
            else
            {
                // se nao for o primeiro, fecha o ultimo e abre um novo
                fclose(img);
                img = fopen(filename, "w");
                fwrite(arr, sizeof(BYTE), 512, img);
                count++;
            }
        }
        // pode ser que o primeiro bloco de 512 não seja o começo de um jpeg
        else if (img != NULL)
        {
            fwrite(arr, sizeof(BYTE), 512, img);
        }
    }
    // fecha arquivos
    fclose(img);
    fclose(file);
    return 0;
}
