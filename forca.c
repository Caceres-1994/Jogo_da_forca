#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"


//BLOCO DE DECLARACAO DE VARIAVEIS GLOBAIS
char palavraSecreta[20];
char chutesDados[20];
int erro;
int tentativas = 0;


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
		scanf(" %20s", novaPalavra);
		fprintf(f, "%s", novaPalavra);
		printf("Palavra adicionada com sucesso!");
	}else if(quer != 'N'||quer != 'n'){
		printf("opcao invalida!");
		exit(1);
	}
	fclose(f);
}


void chutar(int* nAcertos)
{	
	char letrasCertas[20];
	char chute;
	int tamanhoPalavra = strlen(palavraSecreta);


	while(*nAcertos < tamanhoPalavra)
	{
		int j = 0;
		if(tentativas == 7)
		{
			break;
		}

		if(j == 0){
			mostrarForca(tentativas);
		}
		
		printf("As letras que voce ja chutou foram: %s\n", chutesDados);
		printf("Escolha uma letra: ");
		scanf(" %c", &chute);
		chutesDados[j] = chute;
		validarChute(chute, &tentativas);
		mostrarForca(tentativas);
		for(int z = 0; z < (signed)strlen(palavraSecreta); z++) 
		{
			if(chute == palavraSecreta[z])
			{
				printf("%c", palavraSecreta[z]);
				(*nAcertos)++;
				letrasCertas[z] = chute;
			}else if(palavraSecreta[z] == letrasCertas[z])
			{
				printf("%c", palavraSecreta[z]);
			}else
			{
				printf("_");
			}

		}
		j++;
	}
}

void validarChute(char chute, int* tentativas){
	for (int i = 0; i < (signed)strlen(palavraSecreta); i++){
		if(chute == palavraSecreta[i]){
			break;
		}else if(i == ((signed)strlen(palavraSecreta) - 1)){
			(*tentativas)++;}
	}
}

void mostrarForca()
{
	switch(tentativas){
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

void mensagemFim(int* nAcertos){
	if(*nAcertos == (signed)strlen(palavraSecreta))
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
		mostrarForca();
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
	int nAcertos = 0;
	int menu = 0;
	mensagemInicio();
	while(menu != 3){
		printf("Escolha uma opcao: \n1 - jogar\n2 - adicionar palavra ao banco de dados\n3 - sair\n");
		scanf(" %d", &menu);

		while(menu<1||menu>3){
			printf("Selecione uma opcao valida: ");
			scanf(" %d", &menu);
		}

		switch(menu){
		case 1:
			escolhePalavra();
			printf("A palavra secreta possui %d letras\n", strlen(palavraSecreta));
			chutar(&nAcertos);
			mensagemFim(&nAcertos);
			break;
		case 2:
			adicionarPalavra();
			break;
		default:
			return 0;
		}

	}
	

	printf("Ate mais!");
	
	return 0;
}