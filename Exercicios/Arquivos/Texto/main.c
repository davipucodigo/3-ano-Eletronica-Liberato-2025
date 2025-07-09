/*
Modo Significado
"r" Abre um arquivo para leitura
"w" Cria um arquivo para escrita
"a" Acrescenta dados para um arquivo existente
"rb" Abre um arquivo binário para leitura
"wb" Cria um arquivo binário para escrita
"ab" Acrescenta dados a um arquivo binário existente
"r+" Abre um arquivo para leitura/escrita
"w+" Cria um arquivo para leitura/escrita
"a+" Acrescenta dados ou cria um arquivo para leitura/escrita
"r+b" Abre um arquivo binário para leitura/escrita
"w+b" Cria um arquivo binário para leitura/escrita
"a+b" Acrescenta ou cria um arquivo binário para leitura/escrita
"rt" Abre um arquivo texto para leitura
"wt" Cria um arquivo texto para escrita
"at" Acrescenta dados a um arquivo texto
"r+t" Abre um arquivo-texto para leitura/escrita
"w+t" Cria um arquivo texto para leitura/escrita
"a+t" Acrescenta dados ou cria um arquivo texto para leitura/escrita
*/

/*
FUNÇÕES
fopen() Abre um fluxo
fclose() Fecha um fluxo
putc() Escreve um caractere para um fluxo
getc() Lê um caractere para um fluxo
fseek() Procura por um byte especificado no fluxo
fprintf() É para um fluxo aquilo que printf() é para o console
fscanf() É para um fluxo aquilo que scanf() é para o console
feof() Retorna verdadeiro se o fim do arquivo é encontrado
ferror() Retorna verdadeiro se ocorreu um erro
fread() Lê um bloco de dados de um fluxo
fwrite() Escreve um bloco de dados para um fluxo
rewind() Reposiciona o começo do arquivo
remove() Apaga um arquivo
*/

#include <stdio.h> // <-- Possui o FILE Aqui.
#include <stdlib.h>
#include <string.h>



int main() {

    // |======================== LENDO O ARQUIVO CARACTER POR CARACTER ========================|

    FILE *ponteiro_arquivo; // Ponteiro, fluxo de dados (Stream)
    char ch;

    //                       (nome do arquivo.txt , modo de operação);
    ponteiro_arquivo = fopen( "note.txt", "rt"); // Abre o arquivo e lê caracter por caracter.
    //ch = getc(ponteiro_arquivo);
    /*
    feof() retorna 1 ao termino do arquivo.
    */
    while(!feof(ponteiro_arquivo))
    {
        putchar(ch); // Printa o ch que está sendo lido.
        ch=getc(ponteiro_arquivo); // Capitura o caracter lido conforme o fluxo do ponteiro.
    }

    fclose(ponteiro_arquivo); // Fecha o Arquivo

    // OBSERVANDO O FUNCIONAMENTO DO EOF.
    int testeEOF;
    ponteiro_arquivo = fopen( "note.txt", "rt"); // Abrindo denovo.
    /*
    feof() retorna 1 ao termino do arquivo ao final da leitura do mesmo, enquanto lê retorna 0.
    */
    while(!feof(ponteiro_arquivo))
    {
        ch=getc(ponteiro_arquivo);
        testeEOF = feof(ponteiro_arquivo);
        printf(" EOF: %d",testeEOF);
    }

    fclose(ponteiro_arquivo); // Fecha o Arquivo
    printf("\n\n");

    
    // |======================== ACRESENTANDO ou ESCREVENDO NO ARQUIVO =====================================|
    ponteiro_arquivo = fopen("note.txt", "at"); // at acrescenta um texto e wt reescreve o texto.

    char cha[50] = "\nComer Pizza é muito bom.";
    for (int x = 0; x < strlen(cha); x++) { // Dá para usar o for para limitar a gravação da struct.
        putc(cha[x], ponteiro_arquivo); // Gravando caracter por caracter da struct.
    }
    fclose(ponteiro_arquivo);

    return 0;
}