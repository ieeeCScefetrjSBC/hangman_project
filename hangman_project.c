#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_TENTATIVAS 4

void clearScr(); // AULA 03
void menu(); // AULA 03

void main (){
	// AULAS 1, 2 e 4 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// VARIÁVEIS
	char menu_select, guess;
	char word[51]="\0";
	char word2[51]="\0";
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	// AULA 1 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// TELA DE BOAS-VINDAS
	printf("\t\t\t\t    #######################\n");
	printf("\t\t\t\t      FORCA IEEE CEFET/RJ\n");
	printf("\t\t\t\t    #######################\n\n");

	printf("\t\t\t\t  M E N U   P R I N C I P A L\n\n");
	printf("\t\t\t\t           [J]ogar\n");
	printf("\t\t\t\t           [A]juda\n");
	printf("\t\t\t\t           [S]air\n");

	do{
		scanf("%1c", &menu_select);
		if(menu_select=='A'||menu_select=='a'){
			clearScr();
			printf("\n\n\t\t\t\tInsira aqui as instrucoes do jogo\n\n");
			system("PAUSE");
			clearScr();
			menu();
		}

		if(menu_select=='S'||menu_select=='s'){
			printf("\t\t\t\tVoce saiu do jogo\n");
			return;
		}

		if(menu_select=='J'||menu_select=='j'){
			printf("Iniciando jogo...");
			break;
		}
	}while(1);//while(menu_select!='J' && menu_select!='j' && menu_select!='A' && menu_select!='a' && menu_select!='S' && menu_select!='s');

	clearScr();
	printf("\n\n\t\t\t\tJogo Iniciado!\n\n");
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


	// AULA 2 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	printf("\n\tDigite a palavra desejada (sem acentos ou caracteres especiais): ");
	getchar(); // SÓ EXISTE POR CULPA DO WINDOWS (-_-)
	fgets(word, 50, stdin);
	word[strlen(word)-1]='\0'; // SÓ EXISTE POR CULPA DO WINDOWS (-_-) x2

	strcpy(word2, word);
	for(int i=0; i<strlen(word); i++){
		word[i]=tolower(word[i]); // Garante que todas as letras sejam minúsculas, para facilitar o jogo
		if(word2[i]!=' '&&word2[i]!='-'){ // Converte os caracteres em '~' para exibir na tela do jogo
			word2[i] = '~';
		}
	}
	// printf("%s: %i chars\n",word, strlen(word));
	// printf("%s: %i chars\n",word2, strlen(word2));

	clearScr();
	gameScr(word2, 0);

	int i=0;
	int k;
	do{
		k=0;
		scanf("%1c", &guess);
		getchar(); // NOVAMENTE AQUI POR CAUSA DO WINDOWS
		for(int j=0; j<strlen(word); j++){
			if(word[j]==guess){
				word2[j]=word[j];
				k++;
			}
		}
		if(k==0){
			i++;
			printf("\n\nERROU! Voce ainda possui %i tentativa(s)\n\n", NUM_TENTATIVAS-i);
			system("PAUSE");
		}
		if(!strchr(word2, '~')){
				break;
			}
		clearScr();
		gameScr(word2, i);
	}while(i<NUM_TENTATIVAS);

	if(i<NUM_TENTATIVAS){
		printf("\t\t\t\tVOCE VENCEU!\n");
	}else {
		printf("VOCE PERDEU!");
		return;
	}
	// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	// AULA 4 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

    FILE *myFile;
    char nome[21]="\0";

    printf("Digite o nome a ser gravado para esta pontuação (até 20 caracteres): ");
    fgets(nome, 20, stdin);
    nome[strlen(nome)-1]='\0';
    myFile = fopen("scores.csv", "a+");
    fprintf(myFile, "%s,%s,%i\n", nome, word, i);




	fclose(myFile);
	// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
}



// AULA 3
// #############################################################################
void clearScr(){
	// LIMPA A TELA DO CONSOLE
	if(system("CLS")){
		system("clear");
	}
}

void menu(){
	// TELA DE BOAS-VINDAS
	printf("\t\t\t\t     ######################\n");
	printf("\t\t\t\t      FORCA IEEE CEFET/RJ\n");
	printf("\t\t\t\t     ######################\n\n");

	printf("\t\t\t\tM E N U    P R I N C I P A L\n\n");
	printf("\t\t\t\t         [J]ogar\n");
	printf("\t\t\t\t         [A]juda\n");
	printf("\t\t\t\t         [S]air\n");
}

void gameScr(char palavra[], int a){
	switch(a){
		case 0:
			printf("\t\t\t\t  _________\n\t\t\t\t   |      |\n\t\t\t\t   |       \n\t\t\t\t   |       \n\t\t\t\t   |     \n\t\t\t\t   |\n\t\t\t\t   |\n\t\t\t\t-------\n\n\t\t\t\t");
		break;
		case 1:
			printf("\t\t\t\t  _________\n\t\t\t\t   |      |\n\t\t\t\t   |      O\n\t\t\t\t   |       \n\t\t\t\t   |     \n\t\t\t\t   |\n\t\t\t\t   |\n\t\t\t\t-------\n\t\t\t\t");
		break;
		case 2:
			printf("\t\t\t\t  _________\n\t\t\t\t   |      |\n\t\t\t\t   |      O\n\t\t\t\t   |      |\n\t\t\t\t   |     \n\t\t\t\t   |\n\t\t\t\t   |\n\t\t\t\t-------\n\t\t\t\t");
		break;
		case 3:
			printf("\t\t\t\t  _________\n\t\t\t\t   |      |\n\t\t\t\t   |      O\n\t\t\t\t   |     /|\\\n\t\t\t\t   |     \n\t\t\t\t   |\n\t\t\t\t   |\n\t\t\t\t-------\n\t\t\t\t");
		break;
		case 4:
			printf("\t\t\t\t  _________\n\t\t\t\t   |      |\n\t\t\t\t   |      O\n\t\t\t\t   |     /|\\\n\t\t\t\t   |     / \\\n\t\t\t\t   |\n\t\t\t\t   |\n\t\t\t\t-------\n\t\t\t\t");
		break;
	}
	for (int i=0; i<strlen(palavra);i++){
		printf("%c ", palavra[i]);
	}
	printf("\n");
}
//##############################################################################
