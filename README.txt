Integrantes do grupo:
-Gabriel Luís Silva Pereira
-Gabriel Alves Barbosa
-Natália Nogueira Lara


Instruções para a compilação e execução:
	1) Compilação:
	O jogo foi feito no ambiente Linux, para realizar a compilação, é necessário efetuar o seguinte comando no terminal:
	gcc galaxian.c -lglut -lGLU -lGL -lSOIL -o galaxian

	ou pelo Makefile:
	make galaxian
	
	2)Execução
	E para realizar a execução do jogo execute o comando abaixo:
	./galaxian

	Ou pelo Makefile:
	make run

Lista de itens adicionais implementados:

	1- Texturas animadas
		1.1) Jogador parado ou andando.
		1.2) Cenário de fundo animado.

	2- Relativas ao jogo:
		2.1) Rasante.
		2.2) Inimigos diferentes.
		2.3) Pontuação.

	3- Relativas à nave:
		3.1) Vidas.
		3.2) Controle via setas e letras "a" e "d".
	
	4- Outras funcionalidades:
		4.1) Telas.