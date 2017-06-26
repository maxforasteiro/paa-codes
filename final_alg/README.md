# Maximum Clique Problem

Como trabalho final da disciplina de Projeto e Análise de Algoritmos foi solicitado a implementação de um algoritmo ótimo para a solução do problema do clique máximo em um grafo. Um clique é um sub-grafo de um grafo G tal que para cada par de vértices existe uma aresta que conecta esses dois vértices.

# maximum_clique.cpp

No arquivo maximum_clique.cpp temos a implementação ótima para o problema do clique máximo. Para encontrar o clique máximo, gera-se todas os sub-grafos do grafo e a partir daí encontra o clique máximo. Claramente, esse approach nos leva a uma solução não polinomial *(NP)* mas consegue garantir sempre uma solução ótima.
A implementação desse algoritmo foi baseada na implementação de [Wu Xiaotao](https://github.com/AiWuxt/algorithm/blob/master/MaxClique.cpp) com algumas refatorações para adequa-lo ao escopo do nosso projeto.

# maximal_clique.cpp

No arquivo maximal_clique.cpp temos a implementação aproximada para a solução desse problema, onde uma heuristica foi utilizada para fazer algumas escolhas gulosas e conseguir retornar uma solução aproximada em tempo polinomial (P).
A implementação desse algoritmo foi baseada na implementação de [Atul Sehgal](https://stackoverflow.com/questions/22641528/flaw-in-this-maximum-clique-polynomial-time-approach) com algumas refatorações para adequa-lo ao escopo do nosso projeto.

# Testes

Para conseguirmos testar a corretude dos algoritmos utilizamos [este site](http://www.info.univ-angers.fr/pub/porumbel/graphs/) para pegarmos alguns grafos grandes e com número máximo de cliques já conhecidos. Abaixo temos uma lista dos grafos utilizados e seus resultados para os dois approachs:

## Grafo de 125 Vértices, 736 Arestas e Clique máximo de 4

O grafo pode ser encontrado [nesse link](http://www.info.univ-angers.fr/pub/porumbel/graphs/dsjc125.1.col)
Não foi obtida respostas diferentes para a versão aproximada em P e a solução ótima em NP, para ambos os casos a resposta foi: 5.

Solução ótima não otimizada: 0m0.010s, 0m0.011s, 0m0.010s
Solução ótima otimizada: 0m0.006s, 0m0.004s, 0m0.007s
Solução aproximada não otimizada: 0m0.007s, 0m0.007s, 0m0.007s
Solução aproximada otimizada: 0m0.005s, 0m0.005s, 0m0.005s

## Grafo de 450 Vértices, 8168 Arestas e Clique máximo de 15

O grafo pode ser encontrado [nesse link](http://www.info.univ-angers.fr/pub/porumbel/graphs/le450_15a.col)
Não foi obtida respostas diferentes para a versão aproximada em P e a solução ótima em NP, para ambos os casos a resposta foi: 15.

Solução ótima não otimizada: 0m18.917s, 0m18.927s, 0m19.547s
Solução ótima otimizada: 0m5.197s, 0m5.668s, 0m5.224s
Solução aproximada não otimizada: 0m0.502s, 0m0.498s, 0m0.509s
Solução aproximada otimizada: 0m0.238s, 0m0.216s, 0m0.221s

## Grafo de 450 Vértices, 16680 Arestas e Clique máximo de 15

O grafo pode ser encontrado [nesse link](http://www.info.univ-angers.fr/pub/porumbel/graphs/le450_15c.col)
Não foi obtida respostas diferentes para a versão aproximada em P e a solução ótima em NP, para ambos os casos a resposta foi: 15.

Solução ótima não otimizada: 1m0.307s, 0m57.998s, 1m0.544s
Solução ótima otimizada: 0m16.552s, 0m16.236s, 0m16.487s
Solução aproximada não otimizada: 0m2.521s, 0m2.408s, 0m2.425s
Solução aproximada otimizada: 0m1.091s, 0m1.108s, 0m1.101s

## Grafo de 1000 Vértices, 14378 Arestas e Clique máximo de 20

O grafo pode ser encontrado [nesse link](http://www.info.univ-angers.fr/pub/porumbel/graphs/r1000.1.col)
Não foi obtida respostas diferentes para a versão aproximada em P e a solução ótima em NP, para ambos os casos a resposta foi: 20.

Solução ótima não otimizada: 13m7.923s, 13m4.298s, 0m19.547s
Solução ótima otimizada: 0m5.197s, 0m5.668s, 0m5.224s
Solução aproximada não otimizada: 0m0.502s, 0m0.498s, 0m0.509s
Solução aproximada otimizada: 0m0.238s, 0m0.216s, 0m0.221s


