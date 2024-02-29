#include <stdio.h>
#include <stdlib.h>

int transformare(char c[])///functia care transforma string-ul in nr intreg
{
    int numar=0, i=0, semn=1;
    if (c[i]=='-')
    {
        semn=-1;
        i++;
    }
    for (i=i; c[i]!='\n'; i++)
        numar=numar*10+(c[i]-'0');
    return semn*numar;
}

int main()
{
    FILE* fptr;
    fptr = fopen("in.txt", "r");
    char nr[100];
    int nr_curent, suma=0;

    while (fgets(nr, sizeof(nr), fptr) != NULL)
    {
        nr_curent = transformare(nr);
        suma += nr_curent;
    }

    fclose(fptr);

    printf("%d", suma);

    return 0;
}
