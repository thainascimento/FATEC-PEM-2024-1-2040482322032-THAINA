#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    
    int is_palindrome(char *word) {
        int length = strlen(word);
        for (int i = 0; i < length / 2; i++) {
            if (tolower(word[i]) != tolower(word[length - i - 1])) {
                return 0; // Não é um palíndromo
            }
        }
        return 1; // É um palíndromo
    }
    
    int is_article_or_preposition(char *word) {
        const char *articles_prepositions[] = {"a", "o", "as", "os", "um", "uma", "uns", "umas", "de", "da", "do", "das", "dos", "em", "no", "na", "nos", "nas", "por", "para", "pelo", "pela", "pelos", "pelas", "com", "como", "sem", "mas", "se", "até", "entre", "sobre", "sob", "perante", "contra", "durante", "desde", "para", "através", "além", "afora", "como", "conforme", "consoante", "segundo", "ante", "bajo", "cabe", "con", "contra", "desde", "durante", "en", "entre", "excepto", "hacia", "hasta", "mediante", "por", "salvo", "según", "sin", "so", "sobre", "tras"};
        int total_articles_prepositions = sizeof(articles_prepositions) / sizeof(articles_prepositions[0]);
        for (int i = 0; i < total_articles_prepositions; i++) {
            if (strcmp(word, articles_prepositions[i]) == 0) {
                return 1; 
            }
        }
        return 0; 
    }
    
    int main() {
        char input[1000];
        printf("Digite uma frase: ");
        fgets(input, sizeof(input), stdin);
        
        char *token = strtok(input, " \n");
        while (token != NULL) {
        
            if (!is_article_or_preposition(token)) {
                
                int length = strlen(token);
                while (ispunct(token[length - 1])) {
                    token[length - 1] = '\0';
                    length--;
                }
                
                if (is_palindrome(token)) {
                    printf("Palíndromo encontrado: %s\n", token);
                }
            }
            token = strtok(NULL, " \n");
        }
        
        return 0;
    }
    