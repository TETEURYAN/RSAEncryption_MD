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

<h2>Linguagem usada no projeto</h2>
<p align="center"> <a href="https://www.cprogramming.com/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="c" width="40" height="40"/> </a> </p>

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
> 	Logo depois
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
void decifrar(char letras[], int tabela[],  unsigned long long int new[], char novo_texto[], unsigned long long int n, int i)
{
        while(i < n)
        { 
            if(new[i] != 28)  novo_texto[i] = new[i] + ('A' - 2);
            else if(new[i] == 28) novo_texto[i] = ' ';
            i++;
	    }
}
```

# Obrigado pela atenção!
