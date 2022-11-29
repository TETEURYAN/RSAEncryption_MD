#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

//PROJETO DE MATEMATICA DISCRETA
//APRESENTADO POR:

//MATHEUS RYAN
//CAIO CESAR
//JOAO GOMES
//THYAGO VIANNA

char letras[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
int numero_no_alfabeto[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28};

long long int exponenciacao_modular_rapida(long long int denominador, long long int potencia, long long int mod);
bool mdc (long long int a, long long int b);
long long int chave_privada(long long int e, long long int lambda);
bool ehPrimo (long long int p);
void criptografando_mensagem(long long int frase_enumerada[], int tamanho, long long int frase_criptograda[], int e, int n);
void reenumerando_frase(long long int frase_criptografada[], int tamanho, long long int new_frase_enumerada[], long long int e, long long int d, long long int n);
int letra_na_tabela(int tabela[], long long new[], long long int n, int j, int i);
int numero_na_tabela(char letras[], char frase[], int tam, int j, int i);
void enumerar(char letras[], int tabela[], char frase[], long long int new_frase[], int n, int i);
void decifrar(char letras[], int tabela[], long long int new[], char novo_texto[], long long int n, int i);
void entrada_mensagem_descriptografada();
void entrada_descriptografia();
void entrada_numeros(long long int *num1, long long int *num2, long long int *phi);
void entrada_frase();
void entrada();

int main() 
{
    entrada();
}

bool mdc (long long int a, long long int b) {
    while (b != 0)
    {
       int r = a % b;
       a = b;
       b = r;
    }   
   return a == 1 ? true : false;
}

int indice_d(long long int e, long long int phi)
{
    long long int b_base = phi, q, t;
    long long int x0 = 0, chave_privada = 1;

    if(phi == 1) return 1;
        while(e > 1){
        q = e/phi;
        t = phi;
        phi = e%phi;
            e = t;
        t = x0;
        x0 = chave_privada - (q*x0);
        chave_privada = t;  
    }

  if(chave_privada <0)
  {
    chave_privada += b_base;
  } 
  return chave_privada;
}

bool ehPrimo (long long int p) {

    long long int i;
    double j;
    
    if(p < 2)
        return false;

    j = sqrt(p);

    for (i = 2; i <= j; i++) {
        if (p % i == 0)
            return false;
    }

    return true;
}

void criptografando_mensagem(long long int frase_enumerada[], int tamanho, long long int frase_criptograda[], int e, int n)
{
    for(int i =0; i<tamanho-1; i++)
        {                           
            long long int potencia_da_letra = exponenciacao_modular_rapida(frase_enumerada[i],e,n);     
            frase_criptograda[i]= potencia_da_letra;      
        }

        return;
}

void reenumerando_frase(long long int frase_criptografada[], int tamanho, long long int new_frase_enumerada[], long long int e, long long int d, long long int n)
{
    int i;
    for(i =0; i<tamanho; i++)
        {                           
            long long int potencia_da_letra = exponenciacao_modular_rapida(frase_criptografada[i],d,n); 
            new_frase_enumerada[i]= potencia_da_letra;      
        }
}

int letra_na_tabela(int tabela[], long long new[], long long int n, int j, int i)
{
    if (new[i] == tabela[j])
    {
        return j;
    }
    else
    {
        j++;
        return letra_na_tabela(tabela, new, n, j, i);
    }
    return letra_na_tabela(tabela, new, n, j, i);
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

void enumerar(char letras[], int tabela[], char frase[], long long int new_frase[], int n, int i)
{
    if (i < n)
    {
        int pos;
        pos = numero_na_tabela(letras, frase, n, 0, i);
        new_frase[i] = tabela[pos];
        return enumerar(letras, tabela, frase, new_frase, n, i + 1);
    }
    return;
}

void decifrar(char letras[], int tabela[],  long long int new[], char novo_texto[], long long int n, int i)
{
    if (i == n)
    {
        novo_texto[i] = '\0';
        FILE *new_text;
        new_text = fopen("descriptado.txt", "w");
        fprintf(new_text, "%s", novo_texto);
        fclose(new_text);
        return;
    }
    else
    {
        long long int posicao;
        posicao = letra_na_tabela(tabela, new, n, 0, i);
        novo_texto[i] = letras[posicao];
    }
    decifrar(letras, tabela, new, novo_texto, n, i + 1);
}

void entrada_mensagem_descriptografada()
{
    FILE *descrip;

    char frase[10000];
    int tamanho = 0; int i;

    descrip = fopen("descriptado.txt", "r");

    if(descrip == NULL)
    {
        printf("Nao existe texto descriptado!");
    }
    else 
    {
        while(fscanf(descrip, "%c", &frase[tamanho]) != EOF) {tamanho++;}

        printf("Frase descriptografada: %s\n", frase);
        system("pause");
        
        fclose(descrip);
    }    
}

void entrada_descriptografia()
{
    FILE *crip;
    
    crip = fopen("grifado.txt", "r");

    if(crip == NULL)
    {
        printf("Não existe texto criptado!\n");
        printf("Retornando ao menu.");
        entrada();
    }
    else
    {
        long long int p = 0,q = 0,e = 0;

        entrada_numeros(&p, &q, &e);
        long long int n = p * q;
        long long int cop = (p-1)*(q-1);
        long long int d = indice_d(e, cop);
        long long int frase_criptograda[10000], tamanho_frase = 0, new_frase_enumerada[10000];
        char nova_frase[10000];
        while (fscanf(crip, "%lld", &frase_criptograda[tamanho_frase]) != EOF)
        {
            tamanho_frase++;
        }
        reenumerando_frase(frase_criptograda, tamanho_frase,new_frase_enumerada,e,d,n);
        decifrar(letras,numero_no_alfabeto, new_frase_enumerada,nova_frase, tamanho_frase, 0);
        fclose(crip);
    }
}

void entrada_numeros(long long int *num1, long long int *num2, long long int *phi) 
{
    long long int chavePublica = 0, chavePrivada; 
    long long int  p,q,validadeP, validadeQ, validadeCoprimo, e;

    printf("\nDigite dois numeros primos para a geracao da chave publica:");
    printf("\nP: ");
    scanf("%lld", &p);
    printf("\nQ: ");
    scanf("%lld", &q);

    validadeP = ehPrimo(p);
    validadeQ = ehPrimo(q);

    do {
        if (!validadeP && !validadeQ) {
            printf("\nDigite dois numeros primos para a geracao da chave publica:");
            printf("\nP: ");
            scanf("%lld", &p);
            printf("\nQ: ");
            scanf("%lld", &q);

            validadeP = ehPrimo(p);
            validadeQ = ehPrimo(q);
        } else if (!validadeP) {
            printf("\nO numero P nao eh um numero primo, digite-o novamente:");
            printf("\nP: ");
            scanf("%lld", &p);

            validadeP = ehPrimo(p);
        } else if (!validadeQ) {
            printf("\nO numero Q nao eh um numero primo, digite-o novamente:");

            printf("\nQ: ");
            scanf("%lld", &q);

            validadeQ = ehPrimo(q);
        } else {
            chavePublica = p * q;
        }
    } while (!chavePublica);

    printf("\nDigite um numero Co-primo (numero E) de (P - 1)*(Q - 1): ");

    do {
        scanf("%lld", &e);

        long long int cop = (p-1)*(q-1);
        validadeCoprimo = mdc(cop, e);

        if (!validadeCoprimo) {
            printf("\nEste numero nao pode ser usado para gerar a chave publica, digite-o novamente:");
        }
        
    } while (!validadeCoprimo);
    *num1 = p;
    *num2 = q;
    *phi = e;
}

void entrada_frase()
{
    FILE *keys;
    FILE *crip;
    long long int p = 0,q = 0,e = 0;

    crip = fopen("grifado.txt", "w");
    keys = fopen("chaves.txt", "r+");
    
    if(keys == NULL)
    {
        printf("Ainda nao existem chaves publicas!\n");

        system("pause");
        entrada();
    }
    else 
    {
        fscanf(keys, "p = %lld q = %lld e = %lld",&p,&q, &e);
        
        char frase[10000], aux[10000];
        printf("Digite sua frase: ");
        scanf(" %[^\n]", frase);
        
        int tamanho_frase = strlen(frase);

        for (int i = 0; i <= tamanho_frase; i++) 
        {
            aux[i] = frase[i];
            frase[i] = toupper(frase[i]);
            
        }

        long long int frase_enumerada[tamanho_frase+1];
        long long int frase_criptograda[tamanho_frase-1];
        long long int new_frase_enumerada[tamanho_frase+1];
        
        enumerar(letras,numero_no_alfabeto,frase,frase_enumerada,tamanho_frase,0);
        criptografando_mensagem(frase_enumerada,tamanho_frase+1, frase_criptograda, e, p*q);

        for (int i = 0; i < tamanho_frase; i++)
        {
            fprintf(crip, "%lli ", frase_criptograda[i]);
        }

        printf("Texto criptografado com sucesso!\n");
        printf("Retornando. . .");
        
        fclose(keys);
        fclose(crip);
    }
}

long long int exponenciacao_modular_rapida(long long int denominador, long long int potencia, long long int mod)
{
    long long int n = denominador, k = potencia, d = mod;
    long long int resultado, pot;


    pot = n % d;
    resultado = 1;

    for ( ; k > 0; k /= 2) 
    {
        if (k % 2 == 1) 
        {
            resultado = (resultado * pot) % d;
        }
    
        pot = (pot * pot) % d;
     }
    
      return resultado;
}

void entrada()
{
    while(1)
    {
        int opcao;

        system("cls");
        printf("\n\tPROJETO DE MATEMATICA DISCRETA CRIPTOGRAFIA");
        printf("\n\n (1) - Gerar chave publica");
        printf("\n\n (2) - Encriptar");
        printf("\n\n (3) - Desencriptar");
        printf("\n\n (4) - Ver mensagem descriptografada");
        printf("\n\n (5) - Sair");
        printf("\n\n Escolha : ");
        scanf("%d", &opcao);
        
        system("cls");

        if(opcao == 1)
        {
            system("cls");
            FILE *keys;
            keys = fopen("chaves.txt", "w");

            long long int chave1 = 0, chave2 = 0, phi = 0;
            entrada_numeros(&chave1, &chave2, &phi);

            fprintf(keys, "p = %lli q = %lli e = %lli", chave1, chave2, phi);

            fclose(keys);

            printf("\nChaves publicas criadas com sucesso!\n");
        }
        else if(opcao == 2)
        {
            system("cls");
            entrada_frase();
        }
        else if(opcao == 3)
        {
            system("cls");
            entrada_descriptografia();
        }
        else if(opcao == 4)
        {
            entrada_mensagem_descriptografada();
        }
        else if( opcao == 5)
        {
            printf("Obrigado por usar!");
            exit(0);
            return;
        }
        else
        {
            printf("Escolha uma opcao valida!");
            getchar();
        }
    }
}