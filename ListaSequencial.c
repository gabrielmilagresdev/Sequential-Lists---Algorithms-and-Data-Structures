#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int Elemento;
typedef int Bool;

typedef struct {
    Elemento valorElemento;
    Bool disponivel;
} listaSequencial;


Bool buscaListaSequencial(Elemento* lista, int tamanho, Elemento e){
    for(int i = 0; i < tamanho; i++)
        if(lista[i] == e)
            return TRUE;
        return FALSE;
}

int buscaListaSequencialIndice(Elemento* lista, int tamanho, Elemento e){
    int i;
    for(i = 0; i < tamanho; i++)
        if(lista[i] == e)
            break;
    if(i == tamanho)
        return FALSE;
    else
        return i;
}

Elemento buscaListaSequencialElemento(Elemento* lista, int tamanho, Elemento e){
    int i;
    for(i = 0; i < tamanho; i++)
        if(lista[i] == e)
            break;
    if(i == tamanho)
        return FALSE;
    else
        return lista[i];
}

Bool buscaListaSequencialSentinela(Elemento* lista, int tamanho, Elemento e){
    //É necessário ter alocado um espaço a mais no vetor
    lista[tamanho] = e;
    int i;
    while(lista[i] != e)
        i++;
    if(i < tamanho)
        return TRUE;
    return FALSE;
}

Bool buscaListaSequencialBinaria(Elemento* lista, int tamanho, Elemento e) {
    int ini = 0;
    int fim = tamanho - 1;

    while (ini <= fim) {
        int meio = (ini + fim) / 2;

        if (lista[meio] == e)
            return TRUE;
        else if (lista[meio] > e)
            fim = meio - 1;
        else
            ini = meio + 1;
    }
    return FALSE;
}

void insercaoListaSequencialComBuracos(listaSequencial* lista, int tamanho, Elemento e, int posicao){
    //Note que tamanho é o índice do último espaço disponível, isso vale para as outras implementações
    //A disponibilidade é iniciada como TRUE para todos os elementos
    if(posicao > tamanho || posicao < 1){
        printf("Insira uma posicao valida!");
        return;
    }
    if(lista[posicao-1].disponivel == TRUE){
        lista[posicao-1].valorElemento = e;
        lista[posicao-1].disponivel = FALSE;
        return;
    }
    for(int i = tamanho-1; i >= posicao-1; i--){
        lista[i+1].valorElemento = lista[i].valorElemento;
        lista[i+1].disponivel = FALSE; //Caso seja inserção no último índice disponível, ocupa o próximo índice
    }
    lista[posicao-1].valorElemento = e;
    lista[posicao-1].disponivel = FALSE;
}

void insercaoListaSequencialOrdenada1ComBuracos(listaSequencial* lista, int tamanho, Elemento e){
    //O último elemento da lista está no tamanho-1
    lista[tamanho].valorElemento = e;
    lista[tamanho].disponivel = FALSE;

    Elemento tmp;
    for(int i = tamanho; i > 0; i--){
        if(lista[i].valorElemento < lista[i-1].valorElemento){
            tmp = lista[i].valorElemento;
            lista[i].valorElemento = lista[i-1].valorElemento;
            lista[i-1].valorElemento = tmp;
        }
    }
}

void insercaoListaSequencialOrdenada2ComBuracos(listaSequencial* lista, int tamanho, Elemento e){
    //O último elemento da lista está no tamanho-1
    int posicao;
    for(int i = 0; i <= tamanho; i++){
        if(e < lista[i].valorElemento || i==tamanho-1){
            posicao = i;
            break;
        }
    }
    for(int i = tamanho-1; i >= posicao-1; i--){
        lista[i+1].valorElemento = lista[i].valorElemento;
        lista[i+1].disponivel = FALSE; //Caso seja inserção no último índice disponível, ocupa o próximo índice
    }
    lista[posicao].valorElemento = e;
    lista[posicao].disponivel = FALSE;
}



