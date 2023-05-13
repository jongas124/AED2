typedef struct Node
{
    //estrutura AVL
    Node *Left;
    Node *Right;
    int Altura;
    //infos
    char nome[60];
    char genero[20];
    char plataforma[20];
    int qntCopias;
    int qntDisp;
    int anoLanc;
}Node;

//Funções de Árvore

    // Função para calcular o máximo entre dois números
    int max(int a, int b);

    // Função para criar um novo nó com as informações inseridas e com a qntDisp sendo a mesma que a qntCopias
    struct Node *newNode(struct Node *raiz, char *nome, char *genero, char *plataforma, int copias, int ano); 

    // Função para realizar uma rotação simples à direita
    struct Node *rightRotate(struct Node *y);

    // Função para realizar uma rotação simples à esquerda
    struct Node *leftRotate(struct Node *x);

    // Função para obter o fator de balanceamento de um nó
    int getBalance(struct Node *node);

    // Função para inserir um novo nó na árvore AVL
    struct Node *addNode(struct Node *raiz, char *nome, char *genero, char *plataforma, int copias, int ano); 

    // Função para buscar um jogo específico
    struct Node busca(struct Node *raiz, char *nome, char *plataforma);

    // Função para encontrar o nó com o valor mínimo em uma árvore
    struct Node *minNode(struct Node *raiz);

    // Função para remover um nó de uma árvore AVL
    struct Node *deleteNode(struct Node *raiz, char *nome, char *plataforma);



// Funções de Aplicação

    // Função para imprimir dados de um jogo
    void impressaoJogo(struct Node *jogo);

    // Função para imprimir somente nome de jogos por gênero
    void impressaoGenero(struct Node *raiz, char *genero);

    // Função para imprimir somente nome de jogos por plataforma
    void impressaoPlataforma(struct Node *raiz, char *plataforma);

    // Função para imprimir somente nome de jogos por ano
    void impressaoAno(struct Node *raiz, int ano);

    // Função para alugar um jogo
    void alugarJogo(struct Node *jogo);

    // Função para devolver um jogo
    void devolverJogo(struct Node *jogo);
