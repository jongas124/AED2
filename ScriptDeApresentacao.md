## Slide 1.<br>
- Apresentação
## Slide 2. Quais as vantagens da utilização de uma árvore de busca balanceada?<br>
1. Eficiência de busca
-> Bom, como sabemos a árvore de busca realiza as operações básicas tais como busca, insersão, remoção e etc, em um tempo
proporcional ao número de níveis da árvore binária de busca, isto é, O(n) no pior caso. Portanto, se a árvore for balanceada,
partimos da premissa que ela terá a menor quantidade de níveis possível, por sua própria definição de balanceamento.
Assim, realizando estas operações em um tempo menor, estimado em O(log(n)).
2. Manutenção da ordenação
-> A manutenção da ordenação em árvores de busca balanceadas ocorre pela organização dos elementos de acordo com a relação
de ordem em cada nó. Durante a inserção, os elementos são colocados em posições adequadas seguindo o critério de comparação.
As operações de inserção e remoção são cuidadosamente projetadas para preservar a ordem dos elementos na árvore.
3. Manutenção automática do equilíbrio
-> Na árvore AVL, cada nó contém um fator de balanceamento, que é a diferença entre as alturas das subárvores esquerda e direita.
Quando um nó é inserido ou removido da árvore, o fator de balanceamento de seus ancestrais é atualizado. Se o fator de 
balanceamento de um nó ficar fora do intervalo [-1, 1], a árvore é reequilibrada por meio de rotações.
Existem quatro tipos de rotações: rotação simples à esquerda, rotação simples à direita, rotação dupla à esquerda e rotação dupla à direita.
Essas rotações reestruturam a árvore de forma a garantir que as alturas das subárvores fiquem equilibradas.
## Slide 3. BSTS, Red-Black Trees, AVL Trees e funções comuns de uma árvore AVL.<br>
- Aqui tem os nomes das duas principais árvores binárias de busca, Rubo-negra e AVL (que escolhemos)
- Comentário possível: Além desses dois tipos, existem outras variações de árvores binárias de busca balanceadas, como a árvore Splay e a árvore RB. Cada tipo de árvore tem suas próprias características e trade-offs em termos de desempenho e complexidade, e a escolha depende das necessidades específicas de cada aplicação.
- A escolha do nosso grupo foi a árvore AVL para implementação de buscas a respeito de uma locadora de jogos.
- (Mostrar a struct base e as funções comuns explicando brevemente cada funcionalidade)
## Slide 4. altura()
- O parâmetro de entrada da função para calcular a altura de um nó é um nó (óbvio rs), primeiro checamos se este nó é nulo, caso seja retornamos zero, pois não teria altura sem árvore né. Se não, retornamos a altura.
## Slide 5. newNode()
- Essa função é utilizada posteriormente na função AddNode e será chamada se raiz for nula, isto é, ela será a raiz da árvore. Começo da árvore.
## Slide 6. RighRotate() e LeftRotate()
- Recebem como parâmetro um nó genérico, depois pegamos os filhos deste nó e atribuímos a x, y e T2, dependendo do tipo de rotação fazemos a rotação e atualizamos a altura dos nós com o macro __max que retorna a maior altura dentre os nós somada a uma unidade proveniente da rotação.
## Slide 7. getBalance()
- Essa função mais simples verifica primeiramente se o nó é nulo e depois retorna a diferença entre altura do nó da esquerda e do nó da direita, nosso fator de balanceamento, que será utilizado posteriormente como critério para as rotações.
## Slide 8. addNode()
- Essa é a clássica função de adicionar um nó, primeiro verificamos se a raiz é nula e chamamos a newNode() em caso afirmativo. Caso contrário, verificamos se o nome do jogo lançado para inserção possui uma ordem lexicografica maior ou menor que o nó raiz para ser inserido a esquerda o ua direita, se a strncmp retornar zero, significa que o jogo é o mesmo, então apenas adicionamos cópias e quantidades disponíveis e retornamos a raiz sem adicionar altura. Caso o jogo não seja o mesmo, então o jogo em questão entrou no filho esquerdo ou direito o que deve ser contabilizado na nova altura deste nó, além de precisarmos verificar seu balanceamento chamando a getBalance (já explicada), chamamos as funções de rightRotate e leftRotate fazendo as rotações simples ou duplas de acordo com a necessidade.
## Slide 9. busca()
- Fazemos a busca pelo nome, primeiramente fazemos a clássica verificação se a raiz é nula ou não, caso seja retornamos nulo.
- Caso não seja, se a strcmp for igual a zero, achamos o nó daquele jogo.
- Se for maior que zero, procuramos no nó a esquerda recursivamente.
- Se for menor que zero, procuramos no nó a direita recursivamente.
## Slide 10. minNode()
- o Nó com um valor mínimo sempre estará a esquerda, então percorremos a árvore pela esquerda até que o nó aponte para nulo, isto é, seja uma folha ou um nó "único". Quando achado o nó que aponta para o nulo, retornamos o nó atual.
## Slide 11. deleteNode()
- Código bem comentado -
## Slide 12. Funções de aplicação
- Explicar brevemente as funções de aplicação (são bem autoexplicativas kkkkk)
## Slide 13. impressaoJogo()
- Verificação se o nó do jogo aponta para nulo e print das características do jogo.
## Slide 14. impressaoGenero(), impressaoPlat() e impressaoAno()
- impressaoGen: Primeiro verificamos se a raiz é nula, depois realizamos a busca na subárvore esquerda e na árvore direita recursivamente, utilizamos a strstr ao invés da strcmp neste caso pq existem jogos que possuem mais de um gênero, então fica melhor comparar as substrings.
- impressaoPlataforma: Mesma coisa só que de plataforma, mas utilizando strcmp.
- impressaoAno: Mesma coisa só que é um inteiro agora, não utilizando strcmp e nem strstr.
## Slide 15. alugarJogo() e devolverJogo()
- A função de alugarJogo primeiro verifica classicamente se o nó é nulo, caso não seja, verificamos se a quantidade disponível é zero.
- Se sim, não é possível alugar o jogo obviamente, caso não reduzimos uma unidade da quantidade disponível pq é possível alugar e já foi alugado inclusive kkkkk.
- A função de devolverJogo funciona de forma semelhante, mas ao invés de avaliarmos se existe cópia disponível, vamos comparar a quantidade disponível com a quantidade de cópias, se elas forem iguais, vc tá tentando devolver um jogo que não é da nossa locadora, retornamos um print que não eh possivel essas coisas. Se não, vc devolveu o jogo e incrementamos uma unidade na qntDisp daquele determinado jogo.
## Slide 16.
- A função de impressaoTodos imprime o NOME de todos os jogos da nossa árvore.


