# [Platinum V] Bolhas e Baldes - 13681 

[문제 링크](https://www.acmicpc.net/problem/13681) 

### 성능 요약

메모리: 9832 KB, 시간: 148 ms

### 분류

자료 구조(data_structures), 분할 정복(divide_and_conquer), 게임 이론(game_theory), 세그먼트 트리(segtree), 정렬(sorting)

### 문제 설명

<p>Andrea, Carlos e Marcelo são muito amigos e passam todos os finais de semana à beira da piscina. Enquanto Andrea se bronzeia ao sol, os dois ficam jogando Bolhas. Andrea, uma cientista da computação muito esperta, já disse a eles que não entende por que passam tanto tempo jogando um jogo tão primário.</p>

<p>Usando o computador portátil dela, os dois geram um inteiro aleatório N e uma seqüência de inteiros, também aleatória, que é uma permutação de 1, 2, . . . ,N.</p>

<p>O jogo então começa, cada jogador faz um movimento, e a jogada passa para o outro jogador. Marcelo é sempre o primeiro a começar a jogar.</p>

<p>Um movimento de um jogador consiste na escolha de um par de elementos consecutivos da seqüência que estejam fora de ordem e em inverter a ordem dos dois elementos. Por exemplo, dada a seqüência 1, 5, 3, 4, 2, o jogador pode inverter as posições de 5 e 3 ou de 4 e 2, mas não pode inverter as posições de 3 e 4, nem de 5 e 2. Continuando com o exemplo, se o jogador decide inverter as posições de 5 e 3 então a nova seqüência será 1, 3, 5, 4, 2.</p>

<p>Mais cedo ou mais tarde, a seqüência ficará ordenada. Perde o jogador impossibilitado de fazer um movimento.</p>

<p>Andrea, com algum desdém, sempre diz que seria mais simples jogar cara ou coroa, com o mesmo efeito. Sua missão, caso decida aceitá-la, é determinar quem ganha o jogo, dada a seqüência inicial.</p>

### 입력 

 <p>A entrada contém vários casos de teste. Os dados de cada caso de teste estão numa única linha, e são inteiros separados por um espaço em branco. Cada linha contém um inteiroN (2 ≤ N ≤ 10<sup>5</sup>), seguido da seqüência inicial P = (X<sub>1</sub>, X<sub>2</sub>, ...,X<sub>N</sub>) de N inteiros distintos dois a dois, onde1 ≤ X<sub>i</sub> ≤ N para 1 ≤ i ≤ N.</p>

<p>O final da entrada é indicado por uma linha que contém apenas o número zero.</p>

### 출력 

 <p><span style="font-size:14px"><span style="color:#454545"><span style="font-family:Ubuntu,sans-serif"><span style="background-color:#ffffff">Para cada caso de teste da entrada seu programa deve imprimir uma única linha, com o nome do vencedor, igual a </span></span></span></span><span style="font-family:courier">Carlos</span><span style="font-size:14px"><span style="color:#454545"><span style="font-family:Ubuntu,sans-serif"><span style="background-color:#ffffff">ou </span></span></span></span><span style="font-family:courier">Marcelo</span><span style="font-size:14px"><span style="color:#454545"><span style="font-family:Ubuntu,sans-serif"><span style="background-color:#ffffff">., sem espaços em branco.</span></span></span></span></p>

