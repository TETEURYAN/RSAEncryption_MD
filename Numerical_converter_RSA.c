
int printar_crptografia(lli array[], lli array_original[], int i, int tam){
    if(i == tam) return 0;
    if(array_original[i] == 28) printf(" ");
    printf("%llu",array[i]);
    printar_crptografia(array,array_original, i+1, tam);
}

int printar_sequencia_enumerada(lli array[], char frase[], int i, int tam){
    if(i == tam) return 0;
    if(array[i] == 28) printf(" ");
    printf("%llu",array[i]);
    printar_sequencia_enumerada(array,frase, i+1, tam);
}

int numero_na_tabela(char letras[], char frase[], int tam, int j, int i)
{
    if (frase[i] == letras[j]) return j;
    else
    {
        j++;
        return numero_na_tabela(letras, frase, tam, j, i);
    }
    return numero_na_tabela(letras, frase, tam, j, i);
}

void enumerar(char letras[], int tabela[], char frase[], lli new_frase[], int n, int i)
{
    if (i < n)
    {
        int pos;
        pos = numero_na_tabela(letras, frase, n, 0, i);
        new_frase[i] = tabela[pos];
        enumerar(letras, tabela, frase, new_frase, n, i + 1);
    }
    return;
}
