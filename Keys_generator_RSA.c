
bool ehPrimo (unsigned long long  nTeste, unsigned long long  divisor) {
    for (nTeste; divisor > 1; divisor -= 2){
        if (nTeste == 2 || divisor == 1) {
            return true;
        } else if (nTeste % 2 == 0 || nTeste % divisor == 0) {
            return false;
        }
    }
}

unsigned long long computandoChavePublica(unsigned long long p, unsigned long long q) {
    return  p * q;
}

bool mdc (unsigned long long a, unsigned long long b) {
    while (b != 0)
    {
       int r = a % b;
       a = b;
       b = r;
    }   
   return a == 1 ? true : false;
}

void critpografando_mensagem(lli frase_enumerada[], int tamanho, lli frase_criptograda[], int e, int n)
{
    for(int i =0; i<tamanho-1; i++)
        {                           
            lli potencia_da_letra = pow(frase_enumerada[i],e); 
            potencia_da_letra %= n;     
			//printf("%llu\n", potencia_da_letra);          
            frase_criptograda[i]= potencia_da_letra;      
        }
        return;
}
void entrada_numeros (int *num1, int *num2, int *crp) {
    unsigned long long chavePublica = 0, chavePrivada; 
    int  p,q,validadeP, validadeQ, validadeCoprimo, numRelativamentePrimo;
    
    printf("\nDigite dois numeros primos para a geracao da chave publica:");
    printf("\nP: ");
    scanf("%i", &p);
    printf("\nQ: ");
    scanf("%i", &q);

    validadeP = ehPrimo(p, p - 2);
    validadeQ = ehPrimo(q, q - 2);

    do {   
        if (!validadeP && !validadeQ) {
            printf("\nOs numeros P e Q nao sao primos, digite-os novamente:");

            printf("\nP: ");
            scanf("%i", &p);
            printf("\nQ: ");
            scanf("%i", &q);

            validadeP = ehPrimo(p, p - 2);
            validadeQ = ehPrimo(q, q - 2);
        } else if (!validadeP) {
            printf("\nO numero P nao eh um numero primo, digite-o novamente:");
            printf("\nP: ");
            scanf("%i", &p);

            validadeP = ehPrimo(p, p - 2);
        } else if (!validadeQ) {
            printf("\nO numero Q nao eh um numero primo, digite-o novamente:");

            printf("\nQ: ");
            scanf("%i", &q);

            validadeQ = ehPrimo(q, q - 2);
        } else {
            chavePublica = computandoChavePublica(p, q);
        }
    } while (!chavePublica);

    system("cls"); // usar pra clear, implementar o ifdef

    printf("\nDigite um numero Co-primo (numero E) ao produto de P e Q:");
    
    do {
        scanf("%d", &numRelativamentePrimo);

        validadeCoprimo = mdc(chavePublica, numRelativamentePrimo);

        if (!validadeCoprimo) {
            printf("\nEste numero nao pode ser usado para gerar a chave publica, digite-o novamente:");
        }
    } while (!validadeCoprimo);

	*crp = numRelativamentePrimo;
	*num1 = p;
	*num2 = q;
}
