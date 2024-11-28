#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"
#define ENFORCADO 7

//BLOCO DE FUNCOES SECUNDARIAS
void escolhePalavra(){
	FILE* f;
	f = fopen("forca.txt", "r");
	if(f == 0){
		printf("Desculpe, banco de dados nao disponivel\n\n");
		exit(1);
	}
	int quantidadePalavras;
	fscanf(f, "%d", &quantidadePalavras);
	srand(time(0));
	int controleLoop = rand() % quantidadePalavras;

	for(int i = 0; i <= controleLoop; i++){
		fscanf(f, "%s", palavraSecreta);
	}
	fclose(f);
}

void adicionarPalavra(){
	FILE* f;
	char novaPalavra[20];
	f = fopen("forca.txt", "r+");
	if(f == 0){
		printf("Desculpe, banco de dados nao disponivel\n\n");
		exit(1);
	}
	
	printf("Gostaria de adicionar uma nova palavra no seu banco de dados? (S/N): ");
	char quer;
	scanf(" %c", &quer);
	if(quer == 'S'||quer == 's'){
		int quantidadePalavras;
		fscanf(f, "%d", &quantidadePalavras);
		fseek(f, 0, SEEK_SET);
		quantidadePalavras++;
		fprintf(f, "%d", quantidadePalavras);
		fseek(f, 0, SEEK_END);
		printf("Digite a nova palavra em letras maiusculas: ");
		fgets(novaPalavra, 20, stdin);
		fprintf(f, "%s", novaPalavra);
		printf("Palavra adicionada com sucesso!");
	}else if(quer != 'N'||quer != 'n'){
		printf("opcao invalida!");
		exit(1);
	}
	fclose(f);
}


void chutar()
{	
	char chute;
	int tamanhoPalavra = strlen(palavraSecreta);
	int posicao = 0;
	int acertou;
	char chutesDados[20] = {'\0'};

	printf("teste");

	while(strcmp(letrasCertas, palavraSecreta))
	{		
		if(tentativas == ENFORCADO)
		{
			break;
		}

		if(posicao==0){
			mostrarForca(tentativas);
		}

		printf("\nAs letras que voce ja chutou foram: %s\n", chutesDados);
		printf("Escolha uma letra: ");
		scanf(" %c", &chute);
		peencherChutesCertos(chute, tamanhoPalavra);
		acertou = validarChute(chute, tamanhoPalavra);
		chutesDados[posicao] = chute;
		
		if(acertou){
			mostrarForca(tentativas);
			printf("%s\n", letrasCertas);
		}else{
			tentativas++;
			printf("\nA palavra secreta nao possui essa letra. Tente novamente!\n");
			mostrarForca(tentativas);
			printf("%s\n", letrasCertas);
		}
		
		posicao++;
		
	}


}

void peencherChutesCertos(char c, int n){
	for(int i=0;i<n;i++){
		if(palavraSecreta[i]==c){
			letrasCertas[i]=c;
		}else if(letrasCertas[i]==palavraSecreta[i]){
			letrasCertas[i]=palavraSecreta[i];
		}else{
			letrasCertas[i]='_';
		}
	}
}

int validarChute(char validador, int controlador){
	int temp;
	for(int i=0;i<controlador;i++){
		if(validador==palavraSecreta[i]){
			temp=1;
			break;
		}else{
			temp=0;
		}
	}

	return temp;
}

void mostrarForca(int n)
{
	switch(n){
	case 0:
		printf("\n----------------	\n");
		printf("|---------------	\n");
		printf("| /            |	\n");
		printf("|/  				\n");
		printf("|               	\n");
		printf("|  					\n");
		printf("|					\n"); 
		printf("|					\n");
		printf("|					\n");
		printf("\n");
	break;
	case 1:
		printf("\n----------------	\n");
		printf("|---------------	\n");
		printf("| /            |	\n");
		printf("|/           (:-()	\n");
		printf("|               	\n");
		printf("|  					\n");
		printf("|					\n"); 
		printf("|					\n");
		printf("|					\n");
		printf("\n");
		break;
	case 2:
		printf("\n----------------	\n");
		printf("|---------------	\n");
		printf("| /            |	\n");
		printf("|/           (:-()	\n");
		printf("|              |	\n");
		printf("|              |	\n");
		printf("|					\n"); 
		printf("|					\n");
		printf("|					\n");
		printf("\n");
		break;
	case 3:
		printf("\n----------------	\n");
		printf("|---------------	\n");
		printf("| /            |	\n");
		printf("|/           (:-()	\n");
		printf("|             /|	\n");
		printf("|              |	\n");
		printf("|					\n"); 
		printf("|					\n");
		printf("|					\n");
		printf("\n");
		break;
	case 4:
		printf("\n----------------	\n");
		printf("|---------------	\n");
		printf("| /            |	\n");
		printf("|/           (:-()	\n");
		printf("|             /|\\	\n");
		printf("|              |	\n");
		printf("|             		\n"); 
		printf("|					\n");
		printf("|					\n");
		printf("\n");
		break;
	case 5:
		printf("\n----------------	\n");
		printf("|---------------	\n");
		printf("| /            |	\n");
		printf("|/           (:-()	\n");
		printf("|             /|\\	\n");
		printf("|              |	\n");
		printf("|              /	\n"); 
		printf("|					\n");
		printf("|					\n");
		printf("\n");
		break;
	case 6:
		printf("\n----------------	\n");
		printf("|---------------	\n");
		printf("| /            |	\n");
		printf("|/           (:-()	\n");
		printf("|             /|\\	\n");
		printf("|              |	\n");
		printf("|              /\\	\n"); 
		printf("|					\n");
		printf("|					\n");
		printf("\n");
		break;
	default:
		printf("\n----------------	\n");
		printf("|---------------	\n");
		printf("| /            |	\n");
		printf("|/           (:-()	\n");
		printf("|             /|\\	\n");
		printf("|              |	\n");
		printf("|              /\\	\n"); 
		printf("|					\n");
		printf("|					\n");
		printf("\n");
		printf("Enforcado!!\n");
	}
	

}


void mensagemInicio(){
	printf("000000000000000     000000        0000000000            0000000000           0000		\n");
	printf("000000000000000    00000000       000000000000        00000000000000        000000		\n");
	printf("0000              000    000      000       000      000          000      000  000		\n");
	printf("0000              00      00      000        00      000                   00    00		\n");
	printf("0000000000        00      00      000       000      000                   00000000		\n");
	printf("0000000000        00      00      000000000000       000                   00000000		\n");
	printf("0000              00      00      0000000000         000                   00    00		\n");
	printf("0000              000    000      000    00          000          000      00    00		\n");
	printf("0000               00000000       000     00          00000000000000       00    00		\n");
	printf("0000                000000        000      00           0000000000         00    00		\n\n");

	printf("=================================SEJA BEM VINDO====================================		\n");
	
}

void mensagemFim(){
	if(!strcmp(letrasCertas, palavraSecreta))
	{
		printf("\nParabens! Voce acertou a palavra secreta\n.");
		printf("		     ___________															\n");
		printf("                             .---'::' `---.											\n");
		printf("                            (::::::' )												\n");
		printf("                            |`-----._______.-----'|									\n");
		printf("                            | :::::::|												\n");
		printf("                           .| ::::::!-.												\n");
		printf("                           \\| :::::/|/												\n");
		printf("                            | ::::::|												\n");
		printf("                            | Prêmio FORCA        :|								\n");
		printf("                            | PARABENS!!::::|										\n");
		printf("                            | ::::::|												\n");
		printf("                            | .::::::|												\n");
		printf("                            J :::::::FILE											\n");
		printf("                             \\ :::::::/											\n");
		printf("                              `. .:::::::'											\n");
		printf("                                `-._ .::::::-'										\n");
		printf("____________________________________| \"\"|\"_______________________________________\n");
		printf("                                    | :::|											\n");
		printf("                                    F ::J 											\n");
		printf("                                   / ::\\                                        	\n");
		printf("                              __.-' :::`-.__										\n");
		printf("                             (_ ::::::_)											\n");
		printf("                               `\"\"\"---------\"\"\"'								\n");

		system("pause");
	}else
	{
		printf("\nVoce foi enforcado! A palavra secreta era %s \n", palavraSecreta);
		mostrarForca(tentativas);
		printf("		     .... NÃO! ... ... MNO! ...							\n");
		printf("   ..... NÃO!! ...................... MNNOO! ...				\n");
		printf(" ..... MM NÃO! ......................... MNNOO!! .				\n");
		printf(".... MNOONNOO! MMMMMMMMMMPPPOII! MNNO!!!! .						\n");
		printf(" ... !O! NÃO! MMMMMMMMMMMMMPPPOOOII!! NÃO! ....					\n");
		printf("    ...... ! MMMMMMMMMMMMMPPPPOOOOIII! ! ...					\n");
		printf("   ........MMMMMMMMMMMPPPPPOOOOOOII!! .....						\n");
		printf("   ........ MMMMMOOOOOOPPPPPPPOOOOMII! ...						\n");  
		printf("    ....... MMMMM.. OPPMMP., OMI! ....							\n");
		printf("     ...... MMMM:: o.,OPMP,.o ::Eu!! ...						\n");
		printf("         ....NNM:::.,,OOPM!P,.::::!! ....						\n");
		printf("          .. MMNNNNNOOOOPMO!!IIPPO!!O! .....					\n");
		printf("         ...MMMMMNNNNOO:!!:!!IPPPPOO! ....						\n");
		printf("           .. MMMMMNNOOMMNNIIIPPPOO!! ......					\n");
		printf("          ...... MMMONNMMNNNIIIOO!..........					\n");
		printf("       ....... MN MÃEMMNNNIIIIIO! OO..........					\n");
		printf("    ......... MNO! IiiiiiiiiiiiiI OOOO ...........				\n");
		printf("  ...... NNN.MNO! . Ó!!!!!!!!!Ó. OON NÃO! ........				\n");
		printf("   .... MNNNNNO! ...OOOOOOOOO. MNN NÃO!........					\n");
		printf("   ...... MNNNNO! .. PPPPPPPPP .. MMNON!........				\n");
		printf("      ...... OH! ................. SOBRE! .......				\n");
		printf("         ................................						\n");

		system("pause");
	}
}



//INICIO FUNCAO PRINCIPAL
int main()
{
	int menu = 0;
	mensagemInicio();
	
		printf("Escolha uma opcao: \n1 - jogar\n2 - adicionar palavra ao banco de dados\n3 - sair\n");
		scanf(" %d", &menu);

		while(menu<1||menu>3){
			printf("Selecione uma opcao valida: ");
			scanf(" %d", &menu);
		}

		switch(menu){
		case 1:
			tentativas = 0;
			escolhePalavra();
			printf("A palavra secreta possui %d letras\n", strlen(palavraSecreta));
			system("pause");
			chutar();
			mensagemFim();
			break;
		case 2:
			adicionarPalavra();
			break;
		default:
			printf("Ate mais!");
			return 0;
		}
		
	return 0;
}
