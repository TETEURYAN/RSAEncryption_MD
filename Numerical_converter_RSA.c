void criptografando_mensagem(unsigned long long int frase_enumerada[], int tamanho, unsigned long long int frase_criptograda[], int e, int n)
{
    for(int i =0; i<tamanho-1; i++)
        {                           
            unsigned long long int potencia_da_letra = exponenciacao_modular_rapida(frase_enumerada[i],e,n); 
            frase_criptograda[i]= potencia_da_letra;      
        }

        return;
}

void reenumerando_frase(unsigned long long int frase_criptografada[], int tamanho, unsigned long long int new_frase_enumerada[], unsigned long long int e, unsigned long long int d, unsigned long long int n)
{
    int i;
    for(i = 0; i < tamanho; i++)
        {                           
            unsigned long long int potencia_da_letra = exponenciacao_modular_rapida(frase_criptografada[i],d,n);    
            new_frase_enumerada[i]= potencia_da_letra;      
        }
}

int letra_na_tabela(int tabela[], long long new[], unsigned long long int n, int j, int i)
{
    for (; j < 28; j++) {
        if (new[i] == tabela[j]) return j;
    }
}

int numero_na_tabela(char letras[], char frase[], int tam, int j, int i)
{
    for (; j < 28; j++) {
        if (frase[i] == letras[j]) return j;
    }
}

void enumerar(char letras[], int tabela[], char frase[], unsigned long long int new_frase[], int n, int i)
{   
    int pos;
    for (; i < n; i++) {
        pos = numero_na_tabela(letras, frase, n, 0, i);
        new_frase[i] = tabela[pos];
    }
}

void decifrar(char letras[], int tabela[],  unsigned long long int new[], char novo_texto[], unsigned long long int n, int i)
{
        while(i < n)
        { 
            if(new[i] != 28)  novo_texto[i] = new[i] + ('A' - 2);
            else if(new[i] == 28) novo_texto[i] = ' ';
            i++;
	    }

        novo_texto[i] = '\0';
        FILE *new_text;
        new_text = fopen("descriptado.txt", "w");
        fprintf(new_text, "%s", novo_texto);
        fclose(new_text);
        return;
}
