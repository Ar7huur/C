#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

struct TpAposta{
	int NumAposta, vet[7];
	char DtAposta[15];
	
	
};



void MaiorChr(char NomeArq[100]);//ex1
void MaiorStr(char NomeArq[100]);// ex1 com string
void ContCaracteres(char NomeArq[100]);//ex2
void Iguais(char NomeArq[100], char NomeArq2[100]); //ex3
void PrimeirasLetrasMaisc(char NomeArq[100]);//ex4
void ArquivoFormatado(); //ex5 e 6
void Criptografia (char NomeArq[100]); //ex7
void Descriptografar (char NomeArq[100]);//ex8
void IniciadosPorVogal (char NomeArq[100]);//ex9
void GerarArqContagem ();//ex10
void MostrarArqContagem (char NomeArq[100]);//ex10
void LerLinha (char NomeArq[100]);//ex11
void RetornarVogais(char NomeArq[100]);//ex28

char Menu(void);

char Menu(void)
{
	setlocale(LC_ALL,"portuguese");
	system("cls");
	printf("### Menu de Opcoes ###\n");
	printf("[A] Execício 1 - com FGETC e FPUTC\n"); 
	printf("[B] Execício 1 - com FGETS e FPUTS\n"); 
	printf("[C] Execício 2 - Qtde de letras, espaços e caracteres\n"); 
	printf("[D] Execício 3 - Verificar igualdades.\n"); 
	printf("[E] Exercício 4 - Copiar primeira letra maisc.\n");
	printf("[F] Exercício 5 e 6 - Apostas formatadas.\n");
	printf("[G] Exercício 7 - Criptografia.\n");
	printf("[H] Exercício 8 - Descriptografar.\n");
	printf("[I] Exercício 9 - Contador de vogais.\n");
	printf("[J] Exercício 10 - Gerar Arquivo de contagem.\n");
	printf("[K] Exercício 10 - Mostrar Arquivo de contagem.\n");
	printf("[L] Exercício 11 - Ler linhas.\n");	
	printf("[M] Exercício 28 - Retornar vogais.\n");		
	printf("[ESC] Sair do Programa\n");
	printf("\nPressione a opcao desejada: ");
	return toupper(getche());
}

//ex1
void MaiorChr(char NomeArq[100]){
	setlocale(LC_ALL,"portuguese");
	FILE * PtrArq= fopen (NomeArq,"r");
	char chr;
	
	if (PtrArq == NULL)
		printf("\nErro ao abrir o arquivo ou o mesmo não existe");
	else{
		FILE *PtrArq2 = fopen("ArqEx1.txt","w");
		chr = fgetc(PtrArq);
		while(!feof(PtrArq)){
			fputc(toupper(chr),PtrArq2);
			chr=fgetc(PtrArq);
		}
		fclose(PtrArq2);
	}	
	fclose(PtrArq);
	printf("\n\nArq Gerado!\n");
	getch();
}

//ex1 com str.
void MaiorStr(char NomeArq[100]){
	FILE *PtrArq = fopen(NomeArq,"r");
	char chr[100];
	
	if (PtrArq == NULL)
		printf("\nArquivo n existe..\n");
	else{
		FILE *PtrN = fopen("Arq1String.txt","w");
		fgets(chr,100,PtrArq);
		while(!feof(PtrArq)){
			strupr(chr);
			fputs(chr,PtrN);
			fgets(chr,100,PtrArq);
			
		}
		fclose(PtrN);
	}
	fclose(PtrArq);
	getch();
}

//exercio2
void ContCaracteres(char NomeArq[100]){
	setlocale(LC_ALL,"portuguese");
	FILE *PtrArq = fopen (NomeArq,"r");
	char chr;
	int l=0, e=0, c=0;
	
	//espaços = 32
	//linhas = 10
	
	if (PtrArq == NULL)
		printf("\nProblema com o arquivo, retorne mais tarde!\n");
	else{
		chr = fgetc(PtrArq);
		while(!feof(PtrArq)){
			if (chr == 32)
				e++;
			if(chr == 10)
				l++;
			if (chr!=32&&chr!=10)
				c++;
			chr=fgetc(PtrArq);
			
		}
		printf("\nHá cerca de [%d] linhas, tem também cerca de [%d] espaços com uma quantidade de [%d] caracteres\n",l,e,c);
	}
	fclose(PtrArq);
	getch();
}

//ex3.
void Iguais(char NomeArq[100], char NomeArq2[100]){
	setlocale(LC_ALL,"portuguese");
	FILE *PtrArq = fopen (NomeArq,"r");
	FILE *PtrArq2 = fopen (NomeArq2,"r");
	char chr, chr2;
	
	if (PtrArq == NULL)
		printf("\nHouve problema em um dos arquivos, verifique os erros e tente novamente.\n");
	else{
		chr=fgetc(PtrArq);
		chr2=fgetc(PtrArq2);
		while(!feof(PtrArq)&& chr==chr2){
			chr=fgetc(PtrArq);
			chr2=fgetc(PtrArq2);
		}
		if(feof(PtrArq))
			printf("\nOs arquivos são iguais.\n");
		else
			printf("\nOs arquivos são diferentes");
	}
	fclose(PtrArq);
	fclose(PtrArq2);
	printf("\nFim do programa..\n");
	getch();
}

//EX4
void PrimeirasLetrasMaisc(char NomeArq[100]){
	FILE *PtrArq = fopen (NomeArq,"r");
	char chr;
	
	if (PtrArq == NULL)
		printf("Erro com o Arquivo..\n");
	else{
		FILE *PtrArq2 = fopen ("Arquivo4.txt","w");
		chr=fgetc(PtrArq);
		if (chr!=32 && chr != 10)
			fputc(toupper(chr),PtrArq2);
		while(!feof(PtrArq)){
			fputc(chr,PtrArq2);
			if (chr == 32){ //espaço
				chr =fgetc(PtrArq);
				fputc(toupper(chr),PtrArq2);
			}
			if(chr==10){ //quebra de linha 
				chr=fgetc(PtrArq);
				fputc(toupper(chr),PtrArq2);
			}
			if(chr==02){ //começo de texto
				chr=fgetc(PtrArq);
				fputc(toupper(chr),PtrArq2);
			}
			chr=fgetc(PtrArq);	
		}
		fclose(PtrArq2);
	}
	fclose(PtrArq);
	printf("\nFim do programa..!\n");
	getch();
}

//ex5 e 6 - Arquivo texto formatado
void ArquivoFormatado (){
	setlocale(LC_ALL,"portuguese");
	TpAposta Aposta;
	int i=0;
	FILE *PtrArq = fopen ("Exercicio5.txt","a");
	
	if (PtrArq == NULL){
		printf("\nErro ao gerar o arquivo de aposta, sendo assim, o mesmo será criado.\n");
		FILE *PtrArq = fopen ("Exercicio5.txt","w");
	}

		
	else{
		printf("Informe o número da aposta: \n");
		scanf("%d",&Aposta.NumAposta);
		printf("Informe a data da aposta: \n");
		fflush(stdin);
		gets(Aposta.DtAposta);
		while(i<7){
			printf("Informe os números apostados: \n");
			scanf("%d",&Aposta.vet[i]);
			i++;
		}
		fprintf(PtrArq,"Numero aposta: [%d] Data da aposta: [%s]",Aposta.NumAposta,Aposta.DtAposta);
		for (int i=0;i<7;i++){
			if (i!=6){
				fprintf(PtrArq," Números: [%d] ",Aposta.vet[i]);
			}
			else{
				fprintf(PtrArq," Números: [%d] \n",Aposta.vet[i]);
			}
		}
	}
	fclose(PtrArq);
	printf("\nFim do programa...\n");
	getch();
}

//ex7 - criptografia.
void Criptografia (char NomeArq[100]){
	setlocale(LC_ALL,"portuguese");
	FILE *PtrArq = fopen (NomeArq,"r");
	char chr;
	
	if (PtrArq == NULL)
		printf("\nArquivo não existe.\n");
	else{
		chr=fgetc(PtrArq);
		FILE *PtrArq2 = fopen ("Arq7.txt","w");
		while(!feof(PtrArq)){
			fputc(chr+5,PtrArq2);
			chr=fgetc(PtrArq);
		}
		fclose(PtrArq2);
	}
	fclose(PtrArq);
	printf("\nFim do programa, arquivo criptografado.");
	getch();
}

//ex8 - descriptografar.
void Descriptografar (char NomeArq[100]){
	setlocale(LC_ALL,"portuguese");
	FILE *PtrArq = fopen (NomeArq,"r");
	char chr;
	if (PtrArq == NULL)
		printf("\nErro ao tentar abrir o arquivo\n");
	else{
		FILE *PtrArq2 = fopen("Descrip7.txt","w");
		chr = fgetc(PtrArq);
		while(!feof(PtrArq)){
			fputc(chr-5,PtrArq2);
			chr=fgetc(PtrArq);
		}
		fclose(PtrArq2);
	}
	fclose(PtrArq);
	printf("\nArquivo descriptografado!\n");
	getch();
}

void Vogais(void){
	setlocale(LC_ALL,"portuguese");
	FILE *PtrArq = fopen ("test.txt","r");
	int qtde=0;
	char chr;
	
	if (PtrArq == NULL)
		printf("\nFalha no arquivo.\n");
		
	else{
		
		chr=fgetc(PtrArq);
			if(chr=='A'||chr=='E'||chr=='I'||chr=='O'||chr=='U')
				qtde++;
				
		while(!feof(PtrArq)){
			if(chr==32){
				chr=fgetc(PtrArq);
					if(chr=='A'||chr=='E'||chr=='I'||chr=='O'||chr=='U')
						qtde++;
			}
			else
				chr=fgetc(PtrArq);
			
		}
		fclose(PtrArq);
	}
	
	printf("Tem exatas %d vogais.\n",qtde);
	getch();
}

void GerarArqContagem(void){
	FILE *Ptr=fopen("arqNum.txt","w");
	int i;
	char chr[10];
	for(i=1;i<=1000;i++)
	{
		itoa(i,chr,10);
		fputs(chr,Ptr);
		fputc('\n',Ptr);
		if(i==1000)
			fputs("wdasdwda",Ptr);
	}
	fclose(Ptr);
	printf("\nGerado\n");
	getch();
}
//ex10

void MostrarArqContagem(char NomeArq[100]){
	FILE *Ptr=fopen (NomeArq,"r");
	char chr[100];
	
	fgets(chr,100,Ptr);
	printf("%s",chr);
	while(!feof(Ptr))
	{		
		fgets(chr,100,Ptr);
		printf("%s",chr);
	}
	fclose(Ptr);
	
	getch();
}

void LerLinha (char NomeArq[100]){
	FILE *PtrArq = fopen (NomeArq,"r");
	char chr[100];
	int linha=1;
	if (PtrArq == NULL)
		printf("\nArquivo n existe.\n");
	else{
		printf("%d ",linha);
		fgets(chr,100,PtrArq);
		printf("%s",chr);
		while(!feof(PtrArq)){
			linha++;
			printf("%d ",linha);
			fgets(chr,100,PtrArq);
			printf("%s",chr);
		}
		fclose(PtrArq);
		
	}
	getch();
}

////ex28 e 14 arruamr..
void RetornarVogais(char NomeArq[100]){
	FILE *Ptr=fopen (NomeArq,"r");
	char chr;
	if(Ptr==NULL)
		printf("\nERRO");
	else
	{
		FILE *PtrN=fopen("novo.txt","w");
		chr=fgetc(Ptr);	
		while(!feof(Ptr))
		{
		
			if(chr=='A'||chr=='E'||chr=='I'||chr=='O'||chr=='U')
				fputc('@',PtrN);
			else
				fputc(chr,PtrN);
			chr=fgetc(Ptr);		
		}
		fclose(PtrN);
	}	
	fclose(Ptr);

}
	

void Executa(void)
{
	char opcao;
	do
	{
		opcao = Menu();
		system("cls");
		
		switch(opcao)
		{
			case 'A': MaiorChr("Exercicio1.txt");
					  break;
			case 'B': MaiorStr("Exercicio1String.txt");
					  break;
			case 'C': ContCaracteres("Exercicio2.txt");
					  break;
			case 'D': Iguais("Exercicio3.txt","Ex3.txt");
					  break;
			case 'E': PrimeirasLetrasMaisc("Exercicio4.txt");
					  break;	
			case 'F': ArquivoFormatado();
					  break;
			case 'G': Criptografia("Exercicio7.txt");
					  break;
			case 'H': Descriptografar("Arq7.txt");
					  break;
			case 'I': Vogais();
					  break;
			case 'J': GerarArqContagem();
					  break;
			case 'K': MostrarArqContagem("arqNum.txt");
					  break;
			case 'L': LerLinha("Ex10.txt");
					  break;
			case 'M': RetornarVogais("Ex28.txt");
					  break;					  					  					  						  					  							  					  				  										  
		}
		
	}while(opcao!=27);
}



int main (void){
	Executa();
	return 0;
}
