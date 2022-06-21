#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int dados[11][8] = {{10,11,12,13,14,15,16},
					   { 0, 1, 0, 1, 1, 0, 0},
             		   { 1, 0, 1 ,1, 1, 0, 0},
             		   { 0, 1, 0, 1, 1, 0, 0},
             		   { 1, 1, 0, 1, 1, 0, 0},
            	 	   { 0, 0, 1, 0, 0, 0, 0},
             		   { 0, 0, 0, 0, 1, 0, 0},
             		   { 0, 0, 0, 1, 0, 0, 0},
             		   { 0, 0, 0, 0, 0, 0, 1},
             		   { 0, 0, 0, 0, 0, 1, 1},
             		   { 0, 0, 0, 0, 0, 1, 0}
           			   };

	
	int i = 0, j = 0,verificador,reserva,suporteMinimo;
	int selecionadosColuna[8],contadorSelecionados=0;
	double selecionadosVezesQAparece[8];
	double suporteEncontrado = 0;
	
	//É definido qual é o suporte desejado para a regra
	double suporteMeta = 50;
	suporteMinimo = (suporteMeta * 10)/100;
	
	printf("Os produtos que aparecem o numero minimo de vezes sao: \n");
	
	//Verifica qual é o produto que aparece o número minimo de vezes na aplicação 
	for(j = 0; j < 8; j++){
		
		for(i = 1; i < 11; i++){
			if(dados[i][j] == 1){
				verificador++;
			}
		}
		
		if(verificador >= suporteMinimo){
			selecionadosColuna[contadorSelecionados] = j;
			selecionadosVezesQAparece[contadorSelecionados] = verificador;
			contadorSelecionados++;
		
			if(dados[0][j] == 10){
				printf("\nLeite");
				
			}else if(dados[0][j] == 11){
				printf("\nCafe");
					
			}else if(dados[0][j] == 12){
				printf("\nCerveja");
				
			}else if(dados[0][j] == 13){
				printf("\nPao");
				
			}else if(dados[0][j] == 14){
				printf("\nManteiga");
				
			}else if(dados[0][j] == 15){
				printf("\nArroz");
				
			}else if(dados[0][j] == 16){
				printf("\nFeijao");
			}
			
		}
		verificador = 0;
	}
	
	printf("\n");
	printf("\nAs regras de associacao sao: \n");
	int produtoSelecionado;
	contadorSelecionados = 0;
	
	//Faz o calculo do suporte e da confiança
	for(j = 0; j < 7; j++){
		
		for(i = 1; i < 11; i++){
			produtoSelecionado = selecionadosColuna[contadorSelecionados];
			if(j == produtoSelecionado){
				break;
			}
			if(dados[i][produtoSelecionado] == 1 && dados[i][j] == 1){
				suporteEncontrado++;
			}
		}
		
		if(suporteEncontrado > 0){
	
			printf("\n******************** Regra ********************");
			printf("\nRegra de associacao entre: ");
			if(dados[0][produtoSelecionado] == 10){
				printf("Leite");
				
			}else if(dados[0][produtoSelecionado] == 11){
				printf("Cafe");
				
			}else if(dados[0][produtoSelecionado] == 12){
				printf("Cerveja");
			}else if(dados[0][produtoSelecionado] == 13){
				printf("Pao");
			}else if(dados[0][produtoSelecionado] == 14){
				printf("Manteiga");
			}else if(dados[0][produtoSelecionado] == 15){
				printf("Arroz");
			}else if(dados[0][produtoSelecionado] == 16){
				printf("Feijao");
			}
			
			printf(" e ");
			
			if(dados[0][j] == 10){
				printf("Leite");
				
			}else if(dados[0][j] == 11){
				printf("Cafe");
				
			}else if(dados[0][j] == 12){
				printf("Cerveja");
			}else if(dados[0][j] == 13){
				printf("Pao");
			}else if(dados[0][j] == 14){
				printf("Manteiga");
			}else if(dados[0][j] == 15){
				printf("Arroz");
			}else if(dados[0][j] == 16){
				printf("Feijao");
			}
			
			float suporteAssoc = suporteEncontrado/10;
			float confiancaAssoc = suporteEncontrado/selecionadosVezesQAparece[contadorSelecionados];
			printf("\nO suporte da associacao e de %.2f", suporteAssoc);
			printf("\nA confianca da associacao e de %.2f", confiancaAssoc);
			printf("\n********************");
			printf("\n");
		}
		
		if(j == 6){
			contadorSelecionados++;
			j = -1;
		}
		suporteEncontrado = 0;
		
	}

	return 0;
}
