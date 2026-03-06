#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char word[]) {
    char keywords[][10] = {
        "int", "float", "char", "if", "else", "while", "return", "for", "void"
    };
    
    int i;
    for(i = 0; i < 9; i++) {
        if(strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[100], word[50];
    int i = 0, j = 0;

    printf("Enter a statement: ");
    gets(input);

    while(input[i] != '\0') {
        
        if(isalpha(input[i])) {
            j = 0;
            
            while(isalnum(input[i])) {
                word[j++] = input[i++];
            }
            word[j] = '\0';

            if(isKeyword(word))
                printf("%s : Keyword\n", word);
            else
                printf("%s : Identifier\n", word);
        }

        else if(isdigit(input[i])) {
            j = 0;

            while(isdigit(input[i])) {
                word[j++] = input[i++];
            }
            word[j] = '\0';

            printf("%s : Number\n", word);
        }

        else if(strchr("+-*/=%", input[i])) {
            printf("%c : Operator\n", input[i]);
            i++;
        }

        else if(input[i] == ';') {
            printf("; : Special Symbol\n");
            i++;
        }

        else {
            i++;
        }
    }

    return 0;
}