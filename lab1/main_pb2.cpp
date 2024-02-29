#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

bool comparare(char *s1, char *s2)
{
    if (strlen(s1)<strlen(s2))
        return 1;
    if (strlen(s1)==strlen(s2) && strcmp(s1, s2)>0)
        return 1;
    return 0;
}

void ordonare(char *s[], int n)
{
    int i, j;
    char *aux;
    for (i=1; i<n; i++)
    {
        aux=s[i];
        j=i-1;
        while(j>=0 && comparare(s[j], aux))
        {
            s[j+1]=s[j];
            j--;
        }
        if (s[j+1]!=aux)
            s[j+1]=aux;
    }
}

int main()
{
    char sir[256];
    scanf("%[^\n]s", sir);
    int i=0, j;
    char *cuvinte[56];
    char *p=strtok(sir, " .,?!");
    while (p)
    {
        cuvinte[i++]=p;
        p=strtok(NULL, " .,?!");
    }
    ordonare(cuvinte, i);
    for (j=0; j<i; j++)
        printf("%s\n", cuvinte[j]);
    return 0;
}
