bool ehPrimo (unsigned long long int p) {

    unsigned long long int i;
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

unsigned long long int potencia(unsigned long long int a, unsigned long long int e, unsigned long long int n)
{

    unsigned long long int chave_privada_D = a, P = 1, chave_publica_E = e;

    while (1)
    {

        if (chave_publica_E == 0)
            return P;

        else if (chave_publica_E % 2 != 0)
        {

            P = (chave_privada_D * P) % n;
            chave_publica_E = (chave_publica_E - 1) / 2;
        }

        else
        {
            chave_publica_E = chave_publica_E / 2;
        }

        chave_privada_D = (chave_privada_D * chave_privada_D) % n;
    }
}
bool mdc (unsigned long long int a, unsigned long long int b) {
    while (b != 0)
    {
       int r = a % b;
       a = b;
       b = r;
    }   
   return a == 1 ? true : false;
}

int indice_d(unsigned long long int e, unsigned long long int phi){
  unsigned long long int b_base = phi, q, t;
  unsigned long long int x0 = 0, chave_privada = 1;

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

bool ehPrimo (unsigned long long int p) {

    unsigned long long int i;
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

unsigned long long int exponenciacao_modular_rapida(unsigned long long int denominador, unsigned long long int potencia, unsigned long long int mod)
{
    unsigned long long int n = denominador;
    unsigned long long int k = potencia;
    unsigned long long int d = mod;
    unsigned long long int resultado, pot;

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
