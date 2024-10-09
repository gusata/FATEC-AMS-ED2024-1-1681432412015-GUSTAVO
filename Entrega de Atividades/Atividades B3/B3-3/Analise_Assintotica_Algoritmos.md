
# Análise Assintótica de Algoritmos

## Introdução
Neste documento, apresentamos a análise assintótica dos algoritmos de busca **Busca Linear**, **Busca Linear em Ordem** e **Busca Binária**. A análise assintótica é um método para descrever o comportamento de um algoritmo à medida que o tamanho da entrada (\( n \)) tende ao infinito, focando no crescimento do tempo de execução ou do consumo de memória conforme o volume de dados aumenta.

## Algoritmos Analisados

### 1. Busca Linear
Na busca linear, o algoritmo percorre a lista de elementos um por um até encontrar o elemento procurado. No pior caso, o algoritmo percorre todos os elementos da lista.

#### Análise de Tempo:
- **Número de operações**: O algoritmo realiza uma comparação para cada elemento da lista até encontrar o alvo ou terminar a lista.
- **Pior caso**: O elemento pode estar na última posição ou não estar presente.
  
A função algébrica no pior caso será:
- **Tempo de execução**: \( f(n) = n \)

#### Notação Big O:
- **Busca Linear**: \( O(n) \)

---

### 2. Busca Linear em Ordem
A busca linear em uma lista ordenada segue o mesmo princípio da busca linear comum, mas com uma otimização. Se a lista estiver em ordem crescente, podemos parar de buscar quando encontrarmos um elemento maior do que o alvo.

#### Análise de Tempo:
- **Número de operações**: Igual à busca linear, no pior caso, o elemento não está presente e a lista é completamente percorrida.
- **Pior caso**: O elemento não está na lista.

A função algébrica no pior caso será:
- **Tempo de execução**: \( f(n) = n \)

#### Notação Big O:
- **Busca Linear em Ordem**: \( O(n) \)

---

### 3. Busca Binária
A busca binária é usada em listas ordenadas. O algoritmo divide a lista em duas partes a cada iteração, eliminando metade dos elementos que não podem conter o elemento procurado.

#### Análise de Tempo:
- **Número de operações**: O tamanho da lista é reduzido pela metade a cada passo, o que leva aproximadamente \( \log_2 n \) comparações no pior caso.
- **Pior caso**: O elemento pode estar em qualquer lugar da lista, e a busca continua até o último elemento.

A função algébrica no pior caso será:
- **Tempo de execução**: \( f(n) = \log_2 n \)

#### Notação Big O:
- **Busca Binária**: \( O(\log n) \)

---

## Gráfico Comparativo

O gráfico a seguir representa o tempo de execução dos algoritmos mencionados usando **notação Big O**:

![alt text](image.png)

- **Busca Linear** e **Busca Linear em Ordem**: Crescem linearmente com \( O(n) \).
- **Busca Binária**: Cresce de forma logarítmica com \( O(\log n) \).

O gráfico demonstra que, para entradas grandes, a busca binária é significativamente mais eficiente do que a busca linear, já que o número de operações aumenta de forma muito mais lenta. Isso destaca a vantagem da busca binária em listas ordenadas.
