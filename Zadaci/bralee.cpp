#include <stdio.h>

int main() {
    int unos = 0, brojevi = 0;
    while(unos != 5) {
        scanf("%d", &unos);
        brojevi++;
    }
    printf("Broj unesenih brojeva je: %d", brojevi);
}







#include <stdio.h>

int main() {
    char poruka[] = "Ja sam string, a ko si ti?";
    char c;
    int i;
    scanf("%c", &c);
    poruka[25] = c;
    for (i = 0; i < 26; i++)
    {
        printf("%c", poruka[i]);
    }
    return 0;
}