# [Gold V] Hesthoppning - 26885 

[문제 링크](https://www.acmicpc.net/problem/26885) 

### 성능 요약

메모리: 3260 KB, 시간: 12 ms

### 분류

너비 우선 탐색(bfs), 깊이 우선 탐색(dfs), 그래프 이론(graphs), 그래프 탐색(graph_traversal)

### 문제 설명

<p>De snela hestarna Hsara och Pascal bor tillsammans i en tvådimensionell hage av storlek <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> rader och <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container> kolumner. Hagen är omgiven av ett stort stängsel, men innanför det så finns det rutor där hestarna kan hoppa fritt. De vill dock båda undvika att hoppa på rutor där det ligger stora stenar.</p>

<p>För de som spelat schack så är det välkänt att ett hopp går till genom att ta två steg i en riktning och ett steg i en riktning vinkelrät mot den första. Det är möjligt att hoppa över stenar, men rutan som man landar i måste vara fri. Givet hur hagen ser ut, och var hestarna befinner sig från början, så vill de veta om det är möjligt för dem att träffas. De kan träffas om det finns något sätt de kan hoppa på så att de hamnar på samma ruta. Hjälp dem att ta reda på det.</p>

### 입력 

 <p>Den första raden innehåller heltalen <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> och <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>, separerade med ett blanksteg.</p>

<p>De nästa <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> raderna består av <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container> tecken som var och en beskriver hur en ruta i hagen ser ut. Ett '.' innebär att rutan är tom, '\#' beskriver en ruta med en sten i, och 'H' betyder att en av hestarna står i den här rutan.</p>

<p>Hagen är omgiven av stängsel. Det är garanterat att indata alltid innehåller exakt två 'H'-celler.</p>

### 출력 

 <p>Ditt program ska skriva ut ett ord på en rad - "JA" om hestarna kan mötas på någon cell och "NEJ" annars.</p>

