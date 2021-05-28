#include<stdio.h>
#include <stdlib.h>

int generate(int row, int column);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./multiplication row size column size\n");
        return 1;
    }

    int row = atoi(argv[1]);
    int column = atoi(argv[2]);

    if (row == 0 || column == 0)
    {
        return 1;
    }

    generate(row, column);
}

int generate(int row, int column)
{
    FILE *output = fopen("generated.txt", "w");

    if (output == NULL)
    {
        printf("Could not write file.\n");
        return 1;
    }

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= column; j++)
        {
            fprintf(output, "%i X %i = %i\n", i, j, i * j);
        }

        fprintf(output, "\n");
    }

    fprintf(output, "Created by https://github.com/devEyosiyas\n");
    fclose(output);

    printf("Multiplication generated.\nCheck generated.txt file\n");

    return 0;
}