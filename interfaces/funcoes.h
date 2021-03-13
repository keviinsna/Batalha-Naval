#ifndef FUNCOES_H
#define FUNCOES_H
    
    void limpa_tela();
    void limpa_buffer();
    void delay(int i);
    void muda_config_windows();    

    void titulo();
    void instrucoes();
    int  tela_inicial();
    void menu_inicial();
    int  tela_multijogadores();
    void menu_multijogadores();    

    void posicionar_embarcacao(int multijogador);
    void pega_nome_jogador(JOGADOR *jogador);
    void inicializa_tabuleiro(char tabuleiro[MAX][MAX]);
    void imprime_tabuleiro(char tabuleiro[MAX][MAX]);
    void imprime_ambos_tabuleiros(char tabuleiro1[MAX][MAX], char tabuleiro2[MAX][MAX]);

    void insere_barco(int linha, int coluna, int tam_barco, char tabuleiro[MAX][MAX], char orientacao);
    void insere_bomba(int linha, int coluna,char tabuleiro[MAX][MAX]);
    void preenche_tabuleiro(char tabuleiro[MAX][MAX]);
    void preenche_tabuleiro_auto(char tabuleiro[MAX][MAX]); 
    
    int  verifica_coordenadas(int linha, int coluna, int tam_barco, char tabuleiro[MAX][MAX], char orientacao);
    int  verifica_coordenadas_bomba(int linha, int coluna, char tabuleiro[MAX][MAX]);
    void cria_borda_barco(int linha, int coluna, int tam_barco, char tabuleiro[MAX][MAX], char orientacao);

    void iniciar_jogo(int multijogador);    
    void jogador_vs_jogador();
    void jogador_vs_cpu();
    int  atira(int linha, int coluna, char tab_atacado[MAX][MAX]);
    int  verifica_tiro(int linha, int coluna, char tab_atacado[MAX][MAX]);

    int  fim_jogo();
    void mensagem_fim_jogo(int venceu);

#endif