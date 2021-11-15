# Processo Seletivo 11/21

Repositório criado com o intuito de explicar a resolução do exercício da Fase 3 da OBI 2020 [Cobertura de Celular](https://olimpiada.ic.unicamp.br/pratique/pj/2020/f3/celular/)

## Resolução

A resolução desse exercício em `C++` pode ser encontrada em [_Resolução_](exercicio.cpp)

## Explicação

O objetivo do exercício é garantir que exista uma _cobertura total_ do arquipélago. Para isso, é necessário que todas as torres estejam conectadas, isto é, qualquer torre deve conseguir alcançar todas as outras torres, diretamente ou indiretamente (alcançando uma torre que consegue alcançar a próxima).

Trata-se de um exercício de grafos, sendo as torres os nós, e o alcance entre elas as arestas. Precisamos descobrir se esse grafo é conectado, ou seja, dado quaisquer dois nós distintos, eles possuem um caminho entre eles. Para descobrir isso, é possível fazer uma _DFS_ (Busca por Profundidade), começando de qualquer nó. E se for possível atingir todos os outros nós, então temos um grafo conectado, ou seja, temos uma _cobertura total_.

Na minha resolução, eu sigo esse passo a passo:

1. Leio as coordenadas e guardo num vetor de `pair`.

2. Percorro todas as possíveis conexões de pares e checo se tem um alcance das torres. Para isso, eu chamo a função `is_connected`, que calcula a distância euclidiana entre dois pontos. Se essa distância for menor ou igual ao alcance `m` da torre, então elas estão conectadas, e eu adiciono uma aresta entre elas no grafo.

3. Por fim, eu faço uma `DFS` começando da primeira torre. Se o grafo for conectado, ou seja, todos os nós (torres) tiverem sido visitados após essa `DFS`, então `S` é impresso, caso contrário `N`.



