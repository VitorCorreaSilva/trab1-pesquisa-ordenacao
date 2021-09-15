# Sistema para geração de arquivos em C
Este repositório foi criado e editado por mim para o trabalho A1 da disciplina de Pesquisa, Ordenação e Técnicas de Armazenamento pelo professor Jader Marques da Silva do curso de Ciência da Computação da Universidade Ritter dos Reis. O objetivo é desenvolver um sistema simples para gerar arquivos com as especificações assinaladas pelo professor.


## O Desafio
O desafio do exercicio é resolver todos os problemas propostos no enunciado do projeto disponibilizado pelo mestre do curso. Então, temos como objetivos:

	- Criar um arquivo texto e gerar uma sequência aleatória de números separados por “;” (ponto e vírgula).O usuário deverá inserir quantos números deseja gerar no arquivo (no mínimo 100 números).
	- Após a geração do arquivo, o programa deverá ter uma função para carregar o arquivo. Ao carregar o arquivo, o programa deverá armazenar os valores em um array.
	- O programa também deverá possuir as seguintes funcionalidades, após a execução das etapas anteriores:
-  opção para inversão dos elementos do arquivo (ou seja, o programa deverá ter uma função de gerar um novo arquivo com os elementos invertidos).

-  opção de geração de um novo arquivo com os elementos ordenados.

- opção de geração de um novo arquivo com o maior e o menor número encontrado no arquivo e a média de todos os números do arquivo.

- opção de geração de um novo arquivo em que cada número do arquivo original é convertido para binário.


## A Estrutura
A estrutura do projeto conta com um diretório chamado `source/` onde estão todos os arquivos com código escrito. Dentro deste foram criados arquivos de cabeçalho no formato `.hpp`. Estes contém todas as definições das classes que usamos no código. E também foram criados os arquivos `.cpp` onde esta a implementação das funções definidas anteriormente. No momento em que o build é executado será também criado um novo diretório na pasta raiz do projeto chamado `objects/` e o arquivo da aplicação chamado `trab1-pesquisa-ordenacao`.


## O Build
Para executar o build que gera os binários e o executavel do projeto sem muitas complicações foi implementado um arquivo `makefile`. Ele foi desenvolvido com base nesta [documentação](https://www.gnu.org/software/make/manual/make.html). Nesse arquivo foram criado os seguintes métodos:
- `make all`: executa as instruções para compilação e gera os binários e o executável do projeto. Para executar basta estar no mesmo diretório do arquivo `makefile` e digitar `make all` conforme abaixo. 

	```Shell
	# User@Computer .../sistemaControle
	$ make all
	Building target using GCC compiler: source/data.cpp
	g++ source/data.cpp -c -W -Wall       -o objects/data.o	

	Building target using GCC compiler: source/empresa.cpp
	g++ source/empresa.cpp -c -W -Wall       -o objects/empresa.o

	Building target using GCC compiler: source/jogador.cpp
	g++ source/jogador.cpp -c -W -Wall       -o objects/jogador.o

	Building target using GCC compiler: source/main.cpp
	g++ source/main.cpp -c -W -Wall       -o objects/main.o

	Building target using GCC compiler: source/time.cpp
	g++ source/time.cpp -c -W -Wall       -o objects/time.o

	Building binary using GCC linker: sistemaControle
	g++ objects/data.o objects/empresa.o objects/jogador.o objects/main.o objects/time.o -o sistemaControle
	Finished building binary: sistemaControle
	```


	Se algum erro de compilação acontecer o gcc informará o arquivo, a linha, a coluna onde o erro aconteceu e qual foi o erro. Nesse caso o erro esta na linha 10, na coluna 35 do arquivo jogador.cpp. E o erro que acontece é a falta de um ";" antes do "this" da linha 11.

	```Shell
	# User@Computer .../sistemaControle
	$ make all
	Building target using GCC compiler: source/data.cpp
	g++ source/data.cpp -c -W -Wall       -o objects/data.o

	Building target using GCC compiler: source/empresa.cpp
	g++ source/empresa.cpp -c -W -Wall       -o objects/empresa.o

	Building target using GCC compiler: source/jogador.cpp
	g++ source/jogador.cpp -c -W -Wall       -o objects/jogador.o
	source/jogador.cpp: In constructor 'Jogador::Jogador(std::string, Data, std::string, Categorias, float)':
	source/jogador.cpp:10:35: error: expected ';' before 'this'
	10 |  this->dataNascimento = nascimento
	  |                                   ^
	  |                                   ;
	11 |  this->nacionalidade = nacionalidade;
	  |  ~~~~
	source/jogador.cpp:7:55: warning: unused parameter 'nacionalidade' [-Wunused-parameter]
	7 | Jogador::Jogador(string nome, Data nascimento, string nacionalidade, Categorias categoria, float salarioBruto){
	  |                                                ~~~~~~~^~~~~~~~~~~~~
	make: *** [objects/jogador.o] Error 1
	```


- `make clean`: Serve para limpar os arquivos dos ultimos builds e não possui um retorno quando tem sucesso. É aconselhavel sempre executar antes de um `make all` para garantir que todos os arquivos serão compilados novamente. Para a execução devemos estar no mesmo diretório do arquivo `makefile`  e digitar `make clean` conforme código abaixo.

	```Shell
	# User@Computer .../sistemaControle
	$ make clean

	```