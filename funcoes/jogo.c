#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "../interfaces/defs.h"
#include "../interfaces/funcoes.h"

JOGADOR jogador, cpu;

void inicializa_tabuleiro(char tabuleiro[MAX][MAX]){
    int i, j;
    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++)
            tabuleiro[i][j] = '.';
    }    
}

void pega_nome_jogador(JOGADOR *jogador){
    char c;
    int i = 0;

    printf("\n\n\t\t\t\t\t\t\t     > INSIRA SEU NOME: ");
    while(c != '\n'){
        scanf("%c", &c);
        c = toupper(c);
        jogador->nome[i++] = c;     
    }
    jogador->nome[i-1] = '\0';
}

void posicionar_embarcacao(int multijogador){
    char c, gera_tab_auto;

    limpa_buffer();
    limpa_tela();
    titulo();

    pega_nome_jogador(&jogador);    
    inicializa_tabuleiro(jogador.tabuleiro);

    limpa_tela();        
    imprime_tabuleiro(jogador.tabuleiro);

    do{
        printf("\n\t\t> DESEJA GERAR TABULEIRO AUTOMATICAMENTE? [s,n]: ");
        scanf("%c", &gera_tab_auto);
        limpa_buffer();

        if(tolower(gera_tab_auto) != 's' && tolower(gera_tab_auto) != 'n'){            
            limpa_tela();        
            imprime_tabuleiro(jogador.tabuleiro);
            printf("\t\t> OPÇÃO INEXISTENTE. POR FAVOR, TENTE NOVAMENTE.\n");
        }else
            break;       

    }while(1);
    
    if(tolower(gera_tab_auto) == 's'){
        preenche_tabuleiro_auto(jogador.tabuleiro); 
        limpa_tela();
        imprime_tabuleiro(jogador.tabuleiro);
    }else{
        limpa_tela();
        imprime_tabuleiro(jogador.tabuleiro);
        preenche_tabuleiro(jogador.tabuleiro);
    }
    
    printf("\n\t\tTABULEIRO PRONTO!");  

    printf("\n\n\t\t> DIGITE QUALQUER COISA PARA AVANÇAR: ");    
    scanf("%c", &c);
    limpa_buffer();

    if(multijogador == 1){ /* jogador vs jogador */
        limpa_tela();
        titulo();

        pega_nome_jogador(&cpu);    
        inicializa_tabuleiro(cpu.tabuleiro);

        limpa_tela();        
        imprime_tabuleiro(cpu.tabuleiro);
        
        do{
            printf("\n\t\t> DESEJA GERAR TABULEIRO AUTOMATICAMENTE? [s,n]: ");
            scanf("%c", &gera_tab_auto);
            limpa_buffer();

            if(tolower(gera_tab_auto) != 's' && tolower(gera_tab_auto) != 'n'){            
                limpa_tela();        
                imprime_tabuleiro(cpu.tabuleiro);
                printf("\t\t> OPÇÃO INEXISTENTE. POR FAVOR, TENTE NOVAMENTE.\n");
            }else
                break;       

        }while(1);
        
        if(tolower(gera_tab_auto) == 's'){
            preenche_tabuleiro_auto(cpu.tabuleiro); 
            limpa_tela();
            imprime_tabuleiro(cpu.tabuleiro);
        }else{
            limpa_tela();
            imprime_tabuleiro(cpu.tabuleiro);
            preenche_tabuleiro(cpu.tabuleiro);
        }

        printf("\n\t\tTABULEIRO PRONTO!");  

        printf("\n\n\t\t> DIGITE QUALQUER COISA PARA AVANÇAR: ");    
        scanf("%c", &c);
        limpa_buffer();

    }else{
        inicializa_tabuleiro(cpu.tabuleiro);
        strcpy(cpu.nome, "CPU");
        preenche_tabuleiro_auto(cpu.tabuleiro); 
    }
    
}

void preenche_tabuleiro(char tabuleiro[MAX][MAX]){
    int linha, i, j, qtd_barco, tamanho, coluna;
    char orientacao, barco[20], c;

    for(i = 1; i <= 5; i++){
        switch (i){
            case 1:
                qtd_barco = QTD_PORTA_AVIAO;
                strcpy(barco, "PORTA-AVIÃO");
                tamanho = TAM_PORTA_AVIAO;
                break; 
            
            case 2:
                qtd_barco = QTD_CRUZADOR;
                strcpy(barco,"CRUZADOR");
                tamanho = TAM_CRUZADOR;
                break;
            
            case 3:
                qtd_barco = QTD_CONTRATORPEDO;
                strcpy(barco,"CONTRATORPEDO");
                tamanho = TAM_CONTRATORPEDO;
                break;
            
            case 4:
                qtd_barco = QTD_SUBMARINO;
                strcpy(barco,"SUBMARINO");
                tamanho = TAM_SUBMARINO;
                break;
            
            case 5:
                qtd_barco = QTD_BOMBA;
                strcpy(barco,"BOMBA");
                tamanho = TAM_BOMBA;
                break;            
        }
        
        for(j = 1; j <= qtd_barco; j++){

            printf("\n\t\t> DIGITE AS COORDENADAS DO(A) %d° %s: \n\n", j, barco);
            
            printf("\t\t> LINHA: ");
            scanf("%d", &linha);
            limpa_buffer();
            
            printf("\t\t> COLUNA: ");
            scanf("%c", &c);

            coluna = toupper(c) - 64;

            if(i < 4){
                limpa_buffer(); 
                printf("\t\t> ORIENTAÇÃO [h/v]: ");
                orientacao = tolower(getchar());
            }

            if(i < 5){
                while(!verifica_coordenadas(linha, coluna, tamanho, tabuleiro, orientacao)){
                    limpa_tela();
                    limpa_buffer();
                    imprime_tabuleiro(tabuleiro);
                    printf("\n\n\t\t> COORDENADA INVÁLIDA!\n");

                    printf("\n\t\t> DIGITE AS COORDENADAS DO(A) %d° %s: \n\n", j, barco);
                
                    printf("\t\t> LINHA: ");
                    scanf("%d", &linha);
                    limpa_buffer();
                    printf("\t\t> COLUNA: ");
                    scanf("%c", &c);
                    coluna = toupper(c) - 64;

                    if(i < 4){
                        limpa_buffer();
                        printf("\t\t> ORIENTAÇÃO [h/v]: ");
                        orientacao = tolower(getchar());
                    }
                }
            }else{
                while(!verifica_coordenadas_bomba(linha, coluna,tabuleiro)){
                    limpa_tela();
                    limpa_buffer();
                    imprime_tabuleiro(tabuleiro);
                    printf("\n\n\t\t> COORDENADA INVÁLIDA!\n");

                    printf("\n\t\t> DIGITE AS COORDENADAS DO(A) %d° %s: \n\n", j, barco);
                
                    printf("\t\t> LINHA: ");
                    scanf("%d", &linha);
                    limpa_buffer();
                    printf("\t\t> COLUNA: ");
                    scanf("%c", &c);
                    coluna = toupper(c) - 64;
                }
            }

            if(i != 5){
                insere_barco(linha, coluna, tamanho, tabuleiro, orientacao);
                cria_borda_barco(linha, coluna, tamanho, tabuleiro, orientacao); /*não pode barcos adjacentes*/               
            }
            else{
                insere_bomba(linha, coluna, tabuleiro);
            }

            limpa_tela();
            limpa_buffer();
            imprime_tabuleiro(tabuleiro);
        }
    }
}
void preenche_tabuleiro_auto(char tabuleiro[MAX][MAX]){    
    int i, j,qtd_barco, tamanho, coluna, linha, ori;
    static int k;
    char orientacao;
    
    for(i = 1; i <= 5; i++){
        switch (i){
            case 1:
                qtd_barco = QTD_PORTA_AVIAO;
                tamanho   = TAM_PORTA_AVIAO;
                break; 
            
            case 2:
                qtd_barco = QTD_CRUZADOR;
                tamanho   = TAM_CRUZADOR;
                break;
            
            case 3:
                qtd_barco = QTD_CONTRATORPEDO;
                tamanho   = TAM_CONTRATORPEDO;
                break;
            
            case 4:
                qtd_barco = QTD_SUBMARINO;
                tamanho   = TAM_SUBMARINO;
                break;
            
            case 5:
                qtd_barco = QTD_BOMBA;
                tamanho   = TAM_BOMBA;
                break;            
        }
        srand(k + time(NULL));
        k++;
        for(j = 1; j <= qtd_barco; j++){
            
            linha =  1 + rand()%10; /*[1,10]*/ 
            coluna = 1 + rand()%10; /*[1,10] => [A,J]*/
                        
            if(i < 4){
                ori = rand()%2; /*[0,1]*/ 
                orientacao = (!ori)? 'h' : 'v'; /* 0 = h; 1 = v */ 
            }

            /* Verifica */    
            if(i < 5){        
                while(!verifica_coordenadas(linha, coluna, tamanho, tabuleiro, orientacao)){

                    linha =  1 + rand()%10; /*[1,10]*/ 
                    coluna = 1 + rand()%10; /*[1,10] => [A,J]*/
                
                    if(i < 4){
                        ori = rand()%2; /*[0,1]*/ 
                        orientacao = (!ori)? 'h' : 'v'; /* 0 = h; 1 = v */ 
                    }
                }
            }else{
                while(!verifica_coordenadas_bomba(linha, coluna, tabuleiro)){
    
                    linha =  1 + rand()%10; /*[1,10]*/ 
                    coluna = 1 + rand()%10; /*[1,10] => [A,J]*/
                
                    if(i < 4){
                        ori = rand()%2; /*[0,1]*/ 
                        orientacao = (!ori)? 'h' : 'v'; /* 0 = h; 1 = v */ 
                    }
                }
            } 

            if(i != 5){
                insere_barco(linha, coluna, tamanho, tabuleiro, orientacao);
                cria_borda_barco(linha, coluna, tamanho, tabuleiro, orientacao); /*não pode barcos adjacentes*/         
            }
            else{
                insere_bomba(linha, coluna, tabuleiro);
            }            
        }
    }
}

void insere_barco(int linha, int coluna, int tam_barco, char tabuleiro[MAX][MAX], char orientacao){
    int i; 
    
    for(i = 0; i < tam_barco; i++){
        if(orientacao == 'h')
            tabuleiro[linha][coluna+i] = '1';
        else
            tabuleiro[linha+i][coluna] = '1';
    }        
}
void insere_bomba(int linha, int coluna,char tabuleiro[MAX][MAX]){    
    tabuleiro[linha][coluna] = '@';    
}

int verifica_coordenadas(int linha, int coluna, int tam_barco, char tabuleiro[MAX][MAX], char orientacao){
    int i, ori, resp = 1;

    if(orientacao != 'h' && orientacao != 'v')
        resp = 0;
    else{
        ori = (orientacao == 'h')? coluna : linha;
        
        if(linha < 1 || coluna < 1 || linha > MAX - 1 || coluna > MAX - 1)
            resp = 0;
        else if(ori + tam_barco - 1 > MAX - 1)
            resp = 0;
        else{
            if(orientacao == 'h'){
                for(i = 0; i < tam_barco; i++){
                    if(tabuleiro[linha][coluna + i] == '1' || tabuleiro[linha][coluna + i] == '*'){
                        resp = 0;
                        break;
                    }
                }
            }else{
                for(i = 0; i < tam_barco; i++){
                    if(tabuleiro[linha + i][coluna] == '1' || tabuleiro[linha + i][coluna] == '*'){
                        resp = 0;
                        break;
                    }
                }
            }
        }
    }        
    return resp;
}
int verifica_coordenadas_bomba(int linha, int coluna, char tabuleiro[MAX][MAX]){
    int resp = 1;
        
        if(linha < 1 || coluna < 1 || linha > MAX - 1 || coluna > MAX - 1)
            resp = 0;
        else{
            if(tabuleiro[linha][coluna] == '1')
                resp = 0;
        }
    return resp;
}

void cria_borda_barco(int linha, int coluna, int tam_barco, char tabuleiro[MAX][MAX], char orientacao){
    int i;
    
    if(orientacao =='h'){    
        if(coluna - 1 > 0){
            tabuleiro[linha][coluna - 1] = '*';
            if(linha + 1 < MAX)
                tabuleiro[linha + 1][coluna - 1] = '*';
            if(linha - 1 > 0)
                tabuleiro[linha - 1][coluna - 1] = '*';
        }
        if(coluna + tam_barco < MAX){
            tabuleiro[linha][coluna + tam_barco] = '*';
            if(linha + 1 < MAX)
                tabuleiro[linha + 1][coluna + tam_barco] = '*';
            if(linha - 1 > 0)
                tabuleiro[linha - 1][coluna + tam_barco] = '*';
        }
        for(i = 0; i < tam_barco; i++){
            if((linha - 1 > 0) && (coluna + i < MAX))
                tabuleiro[linha-1][coluna + i] = '*';
            if((linha + 1 < MAX) && (coluna + i < MAX))
                tabuleiro[linha+1][coluna+i] = '*';
        }
    }else{
        if(linha - 1 > 0){
            tabuleiro[linha - 1][coluna] = '*';
            if(coluna - 1 > 0)
                tabuleiro[linha - 1][coluna - 1] = '*';
            if(coluna + 1 < MAX)
                tabuleiro[linha - 1][coluna + 1] = '*';
        }
        if(linha + tam_barco < MAX){
            tabuleiro[linha+tam_barco][coluna] = '*';
            if(coluna - 1 > 0)
                tabuleiro[linha + tam_barco][coluna - 1] = '*';
            if(coluna + 1 < MAX)
                tabuleiro[linha + tam_barco][coluna + 1] = '*';
        }
        for(i = 0; i < tam_barco; i++){
            if((coluna - 1 > 0) && (linha + i < MAX))
                tabuleiro[linha + i][coluna - 1] = '*';
            if((coluna + 1 < MAX) && (linha + i < MAX))
                tabuleiro[linha + i][coluna + 1] = '*';
        }
    }
}

void iniciar_jogo(int multijogador){
	char c;

    jogador.qtd_barcos = cpu.qtd_barcos = QTD_BARCOS;
    jogador.qtd_bombas = cpu.qtd_bombas = QTD_BOMBA;

    limpa_tela();
    imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
   
    if(multijogador == 1)
        jogador_vs_jogador();
    else
        jogador_vs_cpu();	

    printf("\n\n\t\t> DIGITE QUALQUER COISA PARA VOLTAR AO MENU INICIAL: ");    
    scanf("%c", &c);
    limpa_buffer();
}

void jogador_vs_jogador(){
    int linha, coluna;
    int resp_verificacao, resp_tiro;

    char c, feedback[60]; 
    int msg_fim = 0;
    
    while(1){
        do{  /*Jogador 1*/
            printf("\n\n\t\t\t> SUA VEZ, %s! \n", jogador.nome);
            printf("\t\t\t> DIGITE AS COORDENADAS DA POSIÇÃO QUE DESEJA ATACAR: \n\n");
            limpa_buffer();        
            printf("\t\t\t> LINHA: ");
            if(!scanf("%d", &linha))
                linha = 20;
            limpa_buffer();
            
            printf("\t\t\t> COLUNA: ");
            scanf("%c", &c);            
            coluna = toupper(c) - 64;
            limpa_buffer();

            resp_verificacao = verifica_tiro(linha, coluna, cpu.tabuleiro);
            if(resp_verificacao == 0){
                limpa_tela();
                imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
                strcpy(feedback,"\t\t\tCOORDENADA INVÁLIDA. TENTE OUTRA.");
                printf("%s", feedback);
                continue;
            }else if(resp_verificacao == 1){
                limpa_tela();
                imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
                strcpy(feedback,"\t\t\tCOORDENADA JÁ ATINGIDA. TENTE OUTRA.");
                printf("%s", feedback);
                continue;
            }else{
                resp_tiro = atira(linha, coluna, cpu.tabuleiro);
                
                if(resp_tiro == 0){
                    cpu.qtd_barcos--;
                    strcpy(feedback, "\t\t\tEMBARCAÇÃO ATINGIDA COM SUCESSO.");
                }else if(resp_tiro == 1){
                    cpu.qtd_bombas--; 
                    strcpy(feedback, "\t\t\t\t\tBOMBA ATINGIDA!");
                }else
                    strcpy(feedback, "\t\t\t\t\tÁGUA ATINGIDA!");
            }

            limpa_tela();
            imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
            if(resp_tiro == 0){
                printf(COLOR_GREEN"%s"COLOR_RESET, feedback);                 
                if(fim_jogo())
                    break;             
            }else{
                printf("%s", feedback);                
                break;
            }
        
        }while(1); 

        msg_fim = fim_jogo();
        if(msg_fim){
            mensagem_fim_jogo(msg_fim);
            break;
        }

        do{  /*Jogador 2*/
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t  > SUA VEZ, %s!", cpu.nome);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t  > DIGITE AS COORDENADAS DA POSIÇÃO QUE DESEJA ATACAR: \n\n");
            limpa_buffer();        
            printf("\t\t\t\t\t\t\t\t\t\t\t  > LINHA: ");
            if(!scanf("%d", &linha))
                linha = 20;
            limpa_buffer();
            
            printf("\t\t\t\t\t\t\t\t\t\t\t  > COLUNA: ");
            scanf("%c", &c);            
            coluna = toupper(c) - 64;
            limpa_buffer();

            resp_verificacao = verifica_tiro(linha, coluna, jogador.tabuleiro);
            if(resp_verificacao == 0){
                limpa_tela();
                imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
                strcpy(feedback,"\t\t\t\t\t\t\t\t\t\t\t COORDENADA INVÁLIDA. TENTE OUTRA.");
                printf("%s", feedback);
                continue;
            }else if(resp_verificacao == 1){
                limpa_tela();
                imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
                strcpy(feedback,"\t\t\t\t\t\t\t\t\t\t\t COORDENADA JÁ ATINGIDA. TENTE OUTRA.");
                printf("%s", feedback);
                continue;
            }else{
                resp_tiro = atira(linha, coluna, jogador.tabuleiro);
                
                if(resp_tiro == 0){
                    cpu.qtd_barcos--;
                    strcpy(feedback, "\t\t\t\t\t\t\t\t\t\t\t EMBARCAÇÃO ATINGIDA COM SUCESSO.");
                }else if(resp_tiro == 1){
                    cpu.qtd_bombas--; 
                    strcpy(feedback, "\t\t\t\t\t\t\t\t\t\t\t\t\tBOMBA ATINGIDA!");
                }else
                    strcpy(feedback, "\t\t\t\t\t\t\t\t\t\t\t\t\tÁGUA ATINGIDA!");
            }

            limpa_tela();
            imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
            if(resp_tiro == 0){
                printf(COLOR_GREEN"%s"COLOR_RESET, feedback);                 
                if(fim_jogo())
                    break;             
            }else{
                printf("%s", feedback);                
                break;
            }
        
        }while(1);   

        msg_fim = fim_jogo();
        if(msg_fim){
            mensagem_fim_jogo(msg_fim);
            break;
        }
    }
}
void jogador_vs_cpu(){
    int linha, coluna;
    int resp_verificacao, resp_tiro; 

    int tiro_anterior = 0, linha_tiro_anterior, coluna_tiro_anterior, primeira_linha, primeira_coluna; 
    int norte_sul, leste_oeste, k, verificou = 0, horizontal;

    char c, feedback[60]; 
    int msg_fim = 0;

    while(1){		
        
		do{ /* Jogador */
			printf("\n\n\t\t\t> SUA VEZ! \n\t\t\t> DIGITE AS COORDENADAS DA POSIÇÃO QUE DESEJA ATACAR: \n\n");
		    limpa_buffer();        
		    printf("\t\t\t> LINHA: ");
		    if(!scanf("%d", &linha))
                linha = 20;
		    limpa_buffer();
		    
            printf("\t\t\t> COLUNA: ");
		    scanf("%c", &c);            
		    coluna = toupper(c) - 64;
            limpa_buffer();

            resp_verificacao = verifica_tiro(linha, coluna, cpu.tabuleiro);
            if(resp_verificacao == 0){
                limpa_tela();
                imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
                strcpy(feedback,"\t\t\tCOORDENADA INVÁLIDA. TENTE OUTRA.");
                printf("%s", feedback);
                continue;
            }else if(resp_verificacao == 1){
                limpa_tela();
                imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
                strcpy(feedback,"\t\t\tCOORDENADA JÁ ATINGIDA. TENTE OUTRA.");
                printf("%s", feedback);
                continue;
            }else{
                resp_tiro = atira(linha, coluna, cpu.tabuleiro);
                
                if(resp_tiro == 0){
                    cpu.qtd_barcos--;
                    strcpy(feedback, "\t\t\tEMBARCAÇÃO ATINGIDA COM SUCESSO.");
                }else if(resp_tiro == 1){
                    cpu.qtd_bombas--; 
                    strcpy(feedback, "\t\t\t\t\tBOMBA ATINGIDA!");
                }else
                    strcpy(feedback, "\t\t\t\t\tÁGUA ATINGIDA!");
            }

            limpa_tela();
            imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
            if(resp_tiro == 0){
                printf(COLOR_GREEN"%s"COLOR_RESET, feedback);                 
                if(fim_jogo())
                    break;             
            }else{
                printf("%s", feedback);                
                break;
            }
           
        }while(1);

        msg_fim = fim_jogo();
        if(msg_fim){
            mensagem_fim_jogo(msg_fim);
            break;
        }            

        srand(time(NULL));
        do{  /* CPU */
            if(tiro_anterior >= 1){       
                verificou = 0;
                if(tiro_anterior == 1){
                    k = rand()%4;
                    do{
                        verificou++;
                        switch (k){                        
                            case 0:
                                linha = linha_tiro_anterior + 1;
                                coluna = coluna_tiro_anterior;
                                k++;                            
                                horizontal = 0;
                                break;
                            case 1:
                                linha = linha_tiro_anterior - 1;
                                coluna = coluna_tiro_anterior;
                                k++;
                                horizontal = 0;
                                break;
                            case 2: 
                                linha = linha_tiro_anterior;
                                coluna = coluna_tiro_anterior + 1;
                                k++;
                                horizontal = 1;
                                break;
                            default:
                                linha = linha_tiro_anterior;
                                coluna = coluna_tiro_anterior - 1;
                                k = 0;
                                horizontal = 1;
                                break;
                        }
                    
                        resp_verificacao = verifica_tiro(linha, coluna, jogador.tabuleiro);
                    }while((resp_verificacao != 2) && (verificou < 4));

                    if((resp_verificacao != 2) && (verificou == 4)){
                        tiro_anterior = 0;
                    }else
                        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t > VEZ DO OPONENTE!\n");
                }else{
                    if(horizontal == 0){
                        norte_sul = rand()%2;
                        do{
                            coluna = coluna_tiro_anterior;
                            verificou++;
                            horizontal = 0;
                            if(norte_sul == 1){
                                linha = linha_tiro_anterior + 1;
                                norte_sul = 0;    
                            }else if(norte_sul == 0){
                                linha = linha_tiro_anterior - 1;                                
                                norte_sul = 1;                                
                            }                        
                            resp_verificacao = verifica_tiro(linha, coluna, jogador.tabuleiro);
                        }while((resp_verificacao != 2) && (verificou < 2));

                        if((resp_verificacao != 2) && (verificou == 2)){
                            norte_sul = (linha_tiro_anterior - primeira_linha > 0)? -1 : 1;
                            
                            resp_verificacao = verifica_tiro( (primeira_linha + norte_sul), coluna, jogador.tabuleiro);
                            if(resp_verificacao != 2)
                                tiro_anterior = 0;
                            else{
                                linha = primeira_linha + norte_sul;
                                coluna = primeira_coluna;
                            }
                            
                        }else
                            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t > VEZ DO OPONENTE!\n");
                    }else{
                        leste_oeste = rand()%2;
                        do{
                            linha = linha_tiro_anterior;
                            verificou++;
                            horizontal = 1;                            
                            if((leste_oeste == 1)){
                                coluna = coluna_tiro_anterior + 1;                                
                                leste_oeste = 0;                                    
                            }else if( (leste_oeste == 0) ){
                                
                                coluna = coluna_tiro_anterior - 1;
                                leste_oeste = 1;
                            }
                            resp_verificacao = verifica_tiro(linha, coluna, jogador.tabuleiro);
                        }while((resp_verificacao != 2) && (verificou < 2));

                        if((resp_verificacao != 2) && (verificou == 2)){
                            leste_oeste = (coluna_tiro_anterior - primeira_coluna > 0)? -1 : 1;
                            
                            resp_verificacao = verifica_tiro( linha, (primeira_coluna + leste_oeste), jogador.tabuleiro);
                            if(resp_verificacao != 2)
                                tiro_anterior = 0;
                            else{
                                linha = primeira_linha;
                                coluna = primeira_coluna + leste_oeste;
                            }
                        }else
                            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t > VEZ DO OPONENTE!\n");
                    }
                }
            }
            if(tiro_anterior == 0){
                printf("\n\n\t\t\t\t\t\t\t\t\t\t\t > VEZ DO OPONENTE!\n");

                do{
                    linha = 1 + rand()%10;
                    coluna = 1 + rand()%10;

                    resp_verificacao = verifica_tiro(linha, coluna, jogador.tabuleiro);
                }while(resp_verificacao != 2);
            }
            delay(2);
            if(resp_verificacao == 2){
                resp_tiro = atira(linha, coluna, jogador.tabuleiro);
                
                limpa_tela();
                imprime_ambos_tabuleiros(cpu.tabuleiro, jogador.tabuleiro);
                
                if(resp_tiro == 0){
                    jogador.qtd_barcos--;
                    printf(COLOR_GREEN "\t\t\t\t\t\t\t\t\t\t\t EMBARCAÇÃO ATINGIDA COM SUCESSO!" COLOR_RESET);
                    tiro_anterior++;
                    if(tiro_anterior == 1){
                        primeira_linha = linha;
                        primeira_coluna = coluna;
                    }
                    linha_tiro_anterior = linha;
                    coluna_tiro_anterior = coluna;
                    verificou = 0;                    

                    if(fim_jogo())
                        break;
                }else if(resp_tiro == 1){
                    jogador.qtd_bombas--;
                    printf( "\t\t\t\t\t\t\t\t\t\t\t\t\tBOMBA ATINGIDA!");
                    if((verificou >= 4) || ((tiro_anterior > 1) && (verificou >= 2)))
                        tiro_anterior = 0;
                    break;
                }else{
                    printf("\t\t\t\t\t\t\t\t\t\t\t\t\tÁGUA ATINGIDA!");
                    if(verificou >= 4)
                        tiro_anterior = 0;
                    break;
                }                
            }                
		}while(1);
        
        /*Mensagem de fim de jogo*/
        msg_fim = fim_jogo();
        if(msg_fim){
            mensagem_fim_jogo(msg_fim);
            break;
        }            
	}
}

int verifica_tiro(int linha, int coluna, char tab_atacado[MAX][MAX]){
    int resp = 2;
   
    /*
        0 = coordenada inválida
        1 = coordenada já atingida
        2 = coordenda válida
    */

    if(linha < 1 || coluna < 1 || linha > MAX - 1 || coluna > MAX - 1)  
        resp = 0;
    else if(tab_atacado[linha][coluna] == '#' || tab_atacado[linha][coluna] == '!' || tab_atacado[linha][coluna] == 'X')
        resp = 1;
            
    return resp;
}
int atira(int linha, int coluna, char tab_atacado[MAX][MAX]){
    int resp;

    /*
        0 = Barco atingido
        1 = Bomba atingida
        2 = Água  atingida
    */

    if(tab_atacado[linha][coluna] == '1'){
        tab_atacado[linha][coluna] = '#';
        resp = 0;
    }else if(tab_atacado[linha][coluna] == '@'){
        tab_atacado[linha][coluna] = '!';
        resp = 1;
    }else if(tab_atacado[linha][coluna] == '.' || tab_atacado[linha][coluna] == '*'){
        tab_atacado[linha][coluna] = 'X';
        resp = 2;
    }

    return resp;
}

int fim_jogo(){
    int resp = 0;
    /*
        0 = jogo não terminou
        1 = jogador venceu destruindo os barcos do oponente
        2 = jogador venceu tendo as bombas destruídas
        3 = jogador perdeu tendo os barcos destruídos
        4 = jogador perdeu destruindo as bombas do oponente
    */

    if(jogador.qtd_barcos == 0 || cpu.qtd_bombas == 0)
       resp = (jogador.qtd_barcos == 0)? 3 : 4;
    else if(cpu.qtd_barcos == 0 || jogador.qtd_bombas == 0)
       resp = (cpu.qtd_barcos == 0)? 1 : 2;

    return resp;
}
