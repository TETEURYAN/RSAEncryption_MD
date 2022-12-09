# Projeto de Criptografia RSA | Matematica Discreta
Projeto da disciplina de Matemática Discreta sobre criptografia RSA. 1º semestre(2022.1) do curso de Ciências da Computação na UFAL: Universidade Federal de Alagoas.
<p align="center">
  <img src="https://user-images.githubusercontent.com/91018438/204195385-acc6fcd4-05a7-4f25-87d1-cb7d5cc5c852.png" alt="animated" />
</p>

<center>
Integrantes:

  
    Matheus Ryan | Caio César | Thyago Vianna | João Gomes | Matheus Silva
 </center>
  
  

## O que é a criptografia RSA?
* A criptografia RSA consiste em uma forma de criptografar números com base na artimética modular.
* É bastante usada no ramo computacional na finalidade de obter serviços mais seguros.
* Possui como alicerce a aritmética modular, onde se buscam números primos eficazes para trazer segurança.

## Como funciona a criptografia RSA
* Inserção de duas chaves públicas(p e q), que consequentemente geram uma chave privada(d)
* As chaves públicas e provadas precisam se respeitar diante da primalidade e aritmética modular
* Para criptografar, basta econtrar o resto do número desejado elevado ao expoente phi com o produto de p e q.
* Pra descriptografar, basta econtrar o resto do número crifado elevado ao expoente d com o produto de p e q.

```c
criptografia: mensagem^e = crifrado mod (p*q)

descriptografia: cifrado^d = mensagem mod (p*q)

```		
<h2>Linguagem usada no projeto</h2>
<a href="https://www.cprogramming.com/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="c" width="40" height="40"/> </a> </p>

## Instalação do programa

<p> Para poder instalar e executar o programa, você terá que ter instalado o GCC em sua máquina

> Exemplo:
>
> Clone esse projeto em seu computador com o comando:
> ```
> 	git clone https://github.com/TETEURYAN/RSAEncryption_MD
> ```
> Acesse a pasta do projeto seu terminal:
> ```
> 	cd [Nome da pasta onde você salvou]
> ```
> Já pasta da aplicação em seu terminal, digite o seguinte comando:
> ```
> 	gcc RSA_encritpion_Final.c -o exe -lm
> ```
> 	Logo depois, basta executar com o seguinte comando:
> ```
>         ./exe
  </p>


## Execução do programa
<p> Ao inicializar o programa, você terá direito de escolha de 5 opções:
  
* Criar chaves públicas e armazená-las em um arquivo .txt
* Criptografar uma frase de até 100000 caracteres digitada pelo usuário e gerar um arquivo criptado em .txt
* Descriptografar o arquivo com a inserção de chaves públicas a critério do usuário
* Ver a mensagem dseciptografada, ou não, conforme o item 3
* Sair do programa
  <p align="center">
  <img src="https://user-images.githubusercontent.com/91018438/204197425-1a4b0e67-4a5e-4e71-b263-142ad27a81e7.png" alt="animated" />
</p>

## Algoritmos notórios utilizados no programa

### Exponenciação modular rápida
```c
int exponenciacao_modular_rapida( long long int denominador,  long long int potencia,  long long int mod)
{
     long long int n = denominador;
     long long int k = potencia;
     long long int d = mod;
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
```

### Reposicionar as os números descriptados em letras
```c
void decifrar(char letras[], int tabela[], long long int new[], char novo_texto[], long long int n, int i)
{
        while(i < n)
        { 
            if(new[i] != 28)  novo_texto[i] = new[i] + ('A' - 2);
            else if(new[i] == 28) novo_texto[i] = ' ';
            i++;
	    }
}
```
### Arrays para números e letras de acordo com a numeração dada

```c
char letras[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
int numero_no_alfabeto[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28};
```
## Erros durante a criação do programa

* Encerramento precoce ao digitar string no espaço dedicado a inteiro
* Impressão de lixo quando não era possível encontrar letras
* Erros de conversão na exponenciação modular rápida
* Limitação da linguagem C no suporte de números grandes

<p align="center">
  <img src="https://user-images.githubusercontent.com/91018438/204663649-24e7168c-3eb6-4589-9bcb-10bfa45e1b82.png" alt="animated" />
</p>

# Obrigado pela atenção!
