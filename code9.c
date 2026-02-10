#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);

    int i = 0, j = strlen(s) - 1;
    char temp;

    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }

    printf("%s", s);
    return 0;
}
