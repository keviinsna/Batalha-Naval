#include <stdio.h>

#include "../interfaces/defs.h"
#include "../interfaces/funcoes.h"

JOGADOR jogador, cpu;

void titulo(){
    printf("\n\n\n");
    printf("\t\t\t\t\t╔══╗ ╔═══╗╔════╗╔═══╗╔╗   ╔╗ ╔╗╔═══╗     ╔═╗ ╔╗╔═══╗╔╗  ╔╗╔═══╗╔╗   \t       ▓▓╬▓\n");
    printf("\t\t\t\t\t║╔╗║ ║╔═╗║║╔╗╔╗║║╔═╗║║║   ║║ ║║║╔═╗║     ║║╚╗║║║╔═╗║║╚╗╔╝║║╔═╗║║║   \t      ▓▓▓║▓▓\n");
    printf("\t\t\t\t\t║╚╝╚╗║║ ║║╚╝║║╚╝║║ ║║║║   ║╚═╝║║║ ║║     ║╔╗╚╝║║║ ║║╚╗║║╔╝║║ ║║║║   \t     ▓▓▓▓╬▓▓▓▓\n");
    printf("\t\t\t\t\t║╔═╗║║╚═╝║  ║║  ║╚═╝║║║ ╔╗║╔═╗║║╚═╝║     ║║╚╗║║║╚═╝║ ║╚╝║ ║╚═╝║║║ ╔╗\t  ▄ ▓▓▓▓▓║▓▓▓▓▓     \n");
    printf("\t\t\t\t\t║╚═╝║║╔═╗║  ║║  ║╔═╗║║╚═╝║║║ ║║║╔═╗║     ║║ ║║║║╔═╗║ ╚╗╔╝ ║╔═╗║║╚═╝║\t ▀████████████████▀  \n");
    printf("\t\t\t\t\t╚═══╝╚╝ ╚╝  ╚╝  ╚╝ ╚╝╚═══╝╚╝ ╚╝╚╝ ╚╝     ╚╝ ╚═╝╚╝ ╚╝  ╚╝  ╚╝ ╚╝╚═══╝\n");

    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\tFEITO POR: ELLEN, IGOR e KEVIN\n\n\n");
}

int tela_inicial(){
    int opcao;
    
    limpa_tela();    
    titulo();
    menu_inicial();   
    
    do{
        printf("\n\n\t\t\t\t\t\t\t     > DIGITE O NÚMERO DA OPÇÃO: ");    
        limpa_buffer();
        if(!scanf("%d", &opcao))
            opcao = 4;
        if(!(0 <= opcao && opcao <= 2)){
            limpa_tela();
            titulo();
            menu_inicial();  
            printf("\t\t\t\t\t\t\t> OPÇÃO INEXISTENTE. POR FAVOR, TENTE NOVAMENTE.\n");        
        }
    }while(!(0 <= opcao && opcao <= 2));

    limpa_tela();
    titulo();
    menu_inicial();
    limpa_buffer();

    return opcao;
}
void menu_inicial(){    

    printf("\t\t\t\t\t\t\t    ----------------------------------------\n");
    printf("\t\t\t\t\t\t\t   |               MENU INICIAL             |\n");
    printf("\t\t\t\t\t\t\t   |----------------------------------------|\n");
    printf("\t\t\t\t\t\t\t   |                                        |\n");
    printf("\t\t\t\t\t\t\t   |     > [1] INICIAR                      |\n");
    printf("\t\t\t\t\t\t\t   |     > [2] INSTRUÇÕES                   |\n");
    printf("\t\t\t\t\t\t\t   |     > [0] SAIR                         |\n");
    printf("\t\t\t\t\t\t\t   |                                        |\n");
    printf("\t\t\t\t\t\t\t    ---------------------------------------\n\n");    
}

void menu_multijogadores(){

    printf("\t\t\t\t\t\t\t    ----------------------------------------\n");
    printf("\t\t\t\t\t\t\t   |               MENU INICIAL             |\n");
    printf("\t\t\t\t\t\t\t   |----------------------------------------|\n");
    printf("\t\t\t\t\t\t\t   |                                        |\n");
    printf("\t\t\t\t\t\t\t   |     > [1] Jogador vs Jogador           |\n");
    printf("\t\t\t\t\t\t\t   |     > [2] Jogador vs CPU               |\n");    
    printf("\t\t\t\t\t\t\t   |                                        |\n");
    printf("\t\t\t\t\t\t\t    ---------------------------------------\n\n");
}
int tela_multijogadores(){
    int opcao;

    limpa_tela();    
    titulo();
    menu_multijogadores();
   
    do{
        printf("\n\n\t\t\t\t\t\t\t     > DIGITE O NÚMERO DA OPÇÃO: ");    
        limpa_buffer();
        if(!scanf("%d", &opcao))
            opcao = 4;
        if(!(1 <= opcao && opcao <= 2)){
            limpa_tela();
            titulo();
            menu_multijogadores();  
            printf("\t\t\t\t\t\t\t> OPÇÃO INEXISTENTE. POR FAVOR, TENTE NOVAMENTE.\n");        
        }
    }while(!(1 <= opcao && opcao <= 2));
    
    return opcao;
}

void instrucoes(){
    char opcao;

    limpa_tela();
    limpa_buffer();
    titulo();
    printf("\n");
    printf("\t\t\t\t   --------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t  |                                      INSTRUÇÕES SOBRE O JOGO                                     |\n");
    printf("\t\t\t\t  |--------------------------------------------------------------------------------------------------|\n");
    printf("\t\t\t\t  |                                                                                                  |\n");
    printf("\t\t\t\t  |     Batalha Naval consiste em um jogo estratégico de tabuleiro 10x10 formado por 2 jogadores,    |\n");
    printf("\t\t\t\t  | cujo principal objetivo é acabar com todas a embarcações do adversário.                          |\n");
    printf("\t\t\t\t  |                                                                                                  |\n");
    printf("\t\t\t\t  |     Antes de iniciar a partida, os jogadores devem posicionar, vertical ou horizontalmente, suas |\n");
    printf("\t\t\t\t  | embarcações da maneira que achar melhor, respeitando a regra não de haver embarcações adjacentes,|\n");
    printf("\t\t\t\t  | exceto para as bombas. Há também a possibilidade de gerar o tabuleiro aleatoriamente.            |\n");
    printf("\t\t\t\t  |                                                                                                  |\n");
    printf("\t\t\t\t  |     Depois disso, o primeiro jogador realiza o primeiro tiro, ou seja, diz qual casa do tabuleiro|\n");
    printf("\t\t\t\t  | adversário deseja atacar, inserindo as coordenadas da posição.                                   |\n");
    printf("\t\t\t\t  |                                                                                                  |\n");
    printf("\t\t\t\t  |     Caso acerte uma embarcação, ele joga novamente. Caso contrário, a vez é passada para o outro |\n");
    printf("\t\t\t\t  | jogador.                                                                                         |\n");
    printf("\t\t\t\t  |                                                                                                  |\n");
    printf("\t\t\t\t  |     O jogo termina quando um jogador perde todas as embarcações ou quando você acerte todas as   |\n");
    printf("\t\t\t\t  | bombas do adversário, e nesse último caso, você é o perdedor.                                    |\n");
    printf("\t\t\t\t  |                                                                                                  |\n");
    printf("\t\t\t\t   --------------------------------------------------------------------------------------------------\n\n");  
     
    printf("\n\n\t\t\t\t\t\t\t\t> DIGITE QUALQUER COISA PARA VOLTAR: ");    
    scanf("%c",&opcao);
    limpa_buffer();  
}

void imprime_tabuleiro(char tabuleiro[MAX][MAX]){
    int i, j;
    printf("\n\n\n\t\t   POSICIONE SUAS EMBARACAÇÕES:\n\t\t ------------------------------------------\n");
    for(i = 0; i < MAX; i++){
        printf("\t\t");

        /* Tabuleiro 1 */        
        for(j = 0; j < MAX; j++){            
            if(!i || !j){
                if(!i && !j)
                    printf("  | ");
                else if(!i){
                    printf("%c   ", 'A'+j-1); /*Letras (colunas)*/ 
                    if(j == MAX - 1)
                        printf("\n\t\t ------------------------------------------");                    
                }else 
                    printf("%2d| ", i);     /*Números (linhas)*/
            }else{
                if(tabuleiro[i][j] == '.')
                    printf(COLOR_BLUE "%c   " COLOR_RESET, tabuleiro[i][j]);
                else if(tabuleiro[i][j] == '*')
                    printf(COLOR_GREY "%c   " COLOR_RESET, tabuleiro[i][j]);
                else if(tabuleiro[i][j] == '1')
                    printf(COLOR_GREEN"%c   "COLOR_RESET, tabuleiro[i][j]);
                else
                    printf(COLOR_YELLOW "%c   "COLOR_RESET, tabuleiro[i][j]);
            }   
 
            if(j == MAX -1){
                printf("\t\t");
                switch (i){
                case 0: 
                    printf("SÍMBOLOS:\t\t\t\t   EMBARCAÇÕES: ");
                    break;
                case 2:
                    printf(COLOR_GREEN"1"COLOR_RESET" - BARCOS");
                    printf("\t\t\t   1 PORTA-AVIÕES (4 CASAS): 1");
                    break;
                case 4:
                    printf(COLOR_YELLOW"@"COLOR_RESET" - BOMBAS");
                    printf("\t\t\t   2 CRUZADORES (3 CASAS CADA): 1");
                    break;
                case 6:
                    printf(COLOR_BLUE"."COLOR_RESET" - ÁGUA");
                    printf("\t\t\t   3 CONTRATORPEDOS (2 CASAS CADA): 1");
                    break;
                case 8:
                    printf("* - POSIÇÃO INVÁLIDA");
                    printf("\t\t   4 SUBMARINOS (1 CASA CADA): 1");
                    break;
                case 10: 
                    printf("\t\t\t\t   3 BOMBAS (1 CASA CADA): @");
                    break;
                default:
                    break;
                }
            }                
        }
        printf("\n");        
    }
    printf("\t\t ------------------------------------------\n");
}
void imprime_ambos_tabuleiros(char tabuleiro[MAX][MAX], char tabuleiro2[MAX][MAX]){
    int i, j;
    printf("\n\n\n\t\t\t\t  TABULEIRO DE %s\t\t\t\t\t\t  TABULEIRO DE %s\n", cpu.nome, jogador.nome);
    printf("\t\t\t ------------------------------------------\t\t\t");
    printf(" ------------------------------------------\n");
    
    for(i = 0; i < MAX; i++){
        printf("\t\t\t");

        /* Tabuleiro 1 */ 
        for(j = 0; j < MAX; j++){
            if(!i || !j){
                if(!i && !j)
                    printf("  | ");
                else if(!i)
                    printf("%c   ", 'A'+j-1); /*Letras (colunas)*/ 
                else 
                    printf("%2d| ", i);
            }else{
            	if(tabuleiro[i][j] == '!')
                	printf(COLOR_YELLOW"@   "COLOR_RESET);
                else if (tabuleiro[i][j] == '#')
                	printf(COLOR_GREEN"1   "COLOR_RESET);
                else if(tabuleiro[i][j] == 'X')
                    printf(COLOR_RED "X   " COLOR_RESET);
                else if ((tabuleiro[i][j] == '1') || (tabuleiro[i][j] == '@') || (tabuleiro[i][j] == '*') || (tabuleiro[i][j] == '.')){
                	printf(COLOR_BLUE ".   " COLOR_RESET);
                }                
            }    
        }
        
        printf("\t\t\t");

        /* Tabuleiro 2 */
        for(j = 0; j < MAX; j++){
            if(!i || !j){
                if(!i && !j)
                    printf("  | ");
                else if(!i)
                    printf("%c   ", 'A'+j-1); /*Letras (colunas)*/ 
                else 
                    printf("%2d| ", i);
            }else{
            	if(tabuleiro2[i][j] == '!')
                	printf(COLOR_YELLOW"@   "COLOR_RESET);
                else if (tabuleiro2[i][j] == '#')                	
                	printf(COLOR_GREEN"1   "COLOR_RESET);
                else if(tabuleiro2[i][j] == 'X')
                    printf(COLOR_RED "X   " COLOR_RESET);
                else if ((tabuleiro2[i][j] == '1') || (tabuleiro2[i][j] == '@') ||(tabuleiro2[i][j] == '*') || tabuleiro2[i][j] == '.'){
                	printf(COLOR_BLUE ".   " COLOR_RESET);
                }
            }
        }
        if(!i){
            printf("\n\t\t\t ------------------------------------------\t\t\t");
            printf(" ------------------------------------------");
        }            
        printf("\n");
    }
    printf("\t\t\t ------------------------------------------\t\t\t");
    printf(" ------------------------------------------\n");
}

void mensagem_fim_jogo(int mensagem){
    if(mensagem == 1 || mensagem == 2){
        if(mensagem == 1)
            printf("\n\n\n\t\t\tVOCÊ ATINGIU TODAS AS EMBARCAÇÕES DO OPONENTE. ");
        else
            printf("\n\n\n\t\t\tO OPONENTE ATINGIU TODAS AS SUAS BOMBAS. ");
        printf("PARABÉNS! VOCÊ VENCEU, %s.\n\n", jogador.nome);
        printf("\t\t\t\t╔═══╗╔═══╗╔═══╗╔═══╗╔══╗ ╔═══╗╔═╗ ╔╗╔═══╗   ╔╗  ╔╗╔═══╗╔═══╗╔═══╗   ╔╗  ╔╗╔═══╗╔═╗ ╔╗╔═══╗╔═══╗╔╗ ╔╗ ╔╗\n");
        printf("\t\t\t\t║╔═╗║║╔═╗║║╔═╗║║╔═╗║║╔╗║ ║╔══╝║║╚╗║║║╔═╗║   ║╚╗╔╝║║╔═╗║║╔═╗║║╔══╝   ║╚╗╔╝║║╔══╝║║╚╗║║║╔═╗║║╔══╝║║ ║║ ║║\n");
        printf("\t\t\t\t║╚═╝║║║ ║║║╚═╝║║║ ║║║╚╝╚╗║╚══╗║╔╗╚╝║║╚══╗   ╚╗║║╔╝║║ ║║║║ ╚╝║╚══╗   ╚╗║║╔╝║╚══╗║╔╗╚╝║║║ ╚╝║╚══╗║║ ║║ ║║\n");
        printf("\t\t\t\t║╔══╝║╚═╝║║╔╗╔╝║╚═╝║║╔═╗║║╔══╝║║╚╗║║╚══╗║    ║╚╝║ ║║ ║║║║ ╔╗║╔══╝    ║╚╝║ ║╔══╝║║╚╗║║║║ ╔╗║╔══╝║║ ║║ ╚╝\n");
        printf("\t\t\t\t║║   ║╔═╗║║║║╚╗║╔═╗║║╚═╝║║╚══╗║║ ║║║║╚═╝║╔╗  ╚╗╔╝ ║╚═╝║║╚═╝║║╚══╗    ╚╗╔╝ ║╚══╗║║ ║║║║╚═╝║║╚══╗║╚═╝║ ╔╗\n");
        printf("\t\t\t\t╚╝   ╚╝ ╚╝╚╝╚═╝╚╝ ╚╝╚═══╝╚═══╝╚╝ ╚═╝╚═══╝╚╝   ╚╝  ╚═══╝╚═══╝╚═══╝     ╚╝  ╚═══╝╚╝ ╚═╝╚═══╝╚═══╝╚═══╝ ╚╝\n");
    }else{
        if(mensagem == 3)
            printf("\n\n\n\t\t\tO OPONENTE ATINGIU TODAS AS EMBARCAÇÕES. ");
        else
            printf("\n\n\n\t\t\tVOCÊ ATINGIU TODAS AS BOMBAS DO OPONENTE. ");
        printf("PUTS(\"VOCÊ PERDEU, %s!\");\n\n", jogador.nome);
        printf("\t\t\t\t╔╗  ╔╗╔═══╗╔═══╗╔═══╗   ╔═══╗╔═══╗╔═══╗╔═══╗╔═══╗╔╗ ╔╗ ╔╗   ╔═══╗╔══╗╔═╗╔═╗   ╔═══╗╔═══╗     ╔╗╔═══╗╔═══╗╔═══╗  \n");
        printf("\t\t\t\t║╚╗╔╝║║╔═╗║║╔═╗║║╔══╝   ║╔═╗║║╔══╝║╔═╗║╚╗╔╗║║╔══╝║║ ║║ ║║   ║╔══╝╚╣─╝║║╚╝║║   ╚╗╔╗║║╔══╝     ║║║╔═╗║║╔═╗║║╔═╗║  \n");
        printf("\t\t\t\t╚╗║║╔╝║║ ║║║║ ╚╝║╚══╗   ║╚═╝║║╚══╗║╚═╝║ ║║║║║╚══╗║║ ║║ ║║   ║╚══╗ ║║ ║╔╗╔╗║    ║║║║║╚══╗     ║║║║ ║║║║ ╚╝║║ ║║  \n");
        printf("\t\t\t\t ║╚╝║ ║║ ║║║║ ╔╗║╔══╝   ║╔══╝║╔══╝║╔╗╔╝ ║║║║║╔══╝║║ ║║ ╚╝   ║╔══╝ ║║ ║║║║║║    ║║║║║╔══╝   ╔╗║║║║ ║║║║╔═╗║║ ║║  \n");
        printf("\t\t\t\t ╚╗╔╝ ║╚═╝║║╚═╝║║╚══╗   ║║   ║╚══╗║║║╚╗╔╝╚╝║║╚══╗║╚═╝║ ╔╗   ║║   ╔╣─╗║║║║║║   ╔╝╚╝║║╚══╗   ║╚╝║║╚═╝║║╚╩═║║╚═╝║╔╗\n");
        printf("\t\t\t\t  ╚╝  ╚═══╝╚═══╝╚═══╝   ╚╝   ╚═══╝╚╝╚═╝╚═══╝╚═══╝╚═══╝ ╚╝   ╚╝   ╚══╝╚╝╚╝╚╝   ╚═══╝╚═══╝   ╚══╝╚═══╝╚═══╝╚═══╝╚╝\n");
    }
}