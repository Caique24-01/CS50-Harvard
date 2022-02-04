#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int contador_letras = 0; 
    int contador_palavras = 0;
    int contador_frases = 0;
    
    string texto = get_string("Texto: ");
    
    for (int i = 0; i < strlen(texto); i++){
        if ((texto[i] >= 'a' && texto[i] <= 'z') || (texto[i] >= 'A' && texto[i] <= 'Z')){
            contador_letras++;
        }
        
        contador_palavras = texto[i] == ' ' ? contador_palavras + 1 : contador_palavras;
        
        contador_frases = (texto[i] == '.' || texto[i] == '!' || texto[i] == '?') ? contador_frases + 1 : contador_frases;
    
    }
    
    contador_palavras++;
    
    float L = (float )contador_letras * 100 / (float) contador_palavras;
    float S = (float) contador_frases * 100 / (float) contador_palavras;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    
    if (index >= 16){
        printf("Grade 16+\n");
    }
    else{
        if (index <= 1){
            printf("Before Grade 1\n");
        }
        else{
            printf("Grade %i\n", (int)round(index));
        }
    }
    return 0 ;
}