# [Diamond V] Cat Exercise - 27539 

[문제 링크](https://www.acmicpc.net/problem/27539) 

### 성능 요약

메모리: 167168 KB, 시간: 2044 ms

### 분류

다이나믹 프로그래밍, 자료 구조, 그리디 알고리즘, 트리, 분리 집합, 최소 공통 조상

### 제출 일자

2025년 8월 13일 23:27:47

### 문제 설명

<p>There are $N$ cat towers, numbered from $1$ to $N$. The height of Tower $i$ ($1 ≤ i ≤ N$) is $P_i$. The heights of the towers are distinct integers between $1$ and $N$, inclusive. There are $N - 1$ adjacent pairs of towers. For each $j$ ($1 ≤ j ≤ N - 1$), Tower $A_j$ and Tower $B_j$ are adjacent to each other. In the beginning, it is possible to travel from a tower to any other tower by repeating moves from towers to adjacent towers.</p>

<p>In the beginning, a cat stays in a tower of height $N$.</p>

<p>Then we perform <strong>cat exercises</strong>. In cat exercises, we repeatedly choose a tower and put an obstacle on it. However, we cannot put an obstacle on a tower where we already put an obstacle on it. During the process, the following will happen.</p>

<ul>
	<li>If the cat does not stay in the chosen tower, nothing will happen.</li>
	<li>If the cat stays in the chosen tower and there is an obstacle on every tower which is adjacent to the chosen tower, the cat exercises will finish.</li>
	<li>Otherwise, among the towers where the cat can arrive by repeating moves from towers to adjacent towers without obstacles, the cat will move to the highest tower except for the current tower by repeating moves from towers to adjacent towers. In this process, the cat takes the route where the number of moves from towers to adjacent towers becomes minimum.</li>
</ul>

<p>Given information of the heights of the towers and pairs of adjacent towers, write a program which calculates the maximum possible sum of the number of moves of the cat from towers to adjacent towers if we put obstacles suitably</p>

### 입력 

 <p>Read the following data from the standard input.</p>

<blockquote>
<p>$N$</p>

<p>$P_1$ $P_2$ $\cdots$ $P_N$</p>

<p>$A_1$ $B_1$</p>

<p>$A_2$ $B_2$</p>

<p>$\vdots$</p>

<p>$A_{N-1}$ $B_{N-1}$</p>
</blockquote>

### 출력 

 <p>Write one line to the standard output. The output should contain the maximum possible sum of the number of moves of the cat from towers to adjacent towers.</p>

