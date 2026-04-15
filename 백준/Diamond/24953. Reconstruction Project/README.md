# [Diamond III] Reconstruction Project - 24953 

[문제 링크](https://www.acmicpc.net/problem/24953) 

### 성능 요약

메모리: 10140 KB, 시간: 1072 ms

### 분류

그래프 이론, 최소 스패닝 트리

### 제출 일자

2024년 4월 23일 03:44:53

### 문제 설명

<p>JOI Town is an industrial area which had flourished some time ago. In order to transport products, many stations and railway tracks were constructed. Though it declined, there remain the stations and the railway tracks which are not used any more</p>

<p>There are $N$ stations in JOI Town, numbered from $1$ to $N$. There remain $M$ railway tracks. The $i$-th railway track ($1 ≤ i ≤ M$) connects the station $A_i$ and the station $B_i$ bidirectionally. The width of the $i$-th railway track is $W_i$. It is possible to travel from any station to any other station using railway tracks.</p>

<p>You are the mayor of JOI Town. You are planning to attract a railroad company using the remaining stations and railway tracks, and revive the JOI Town as the town of railway. Then, $Q$ railroad companies applied for this revival project. However, the width of the railway track for trains varies for different companies. It turns out that they need to reconstruct the railway tracks so that the width of the railway tracks of JOI Town matches the width of the railway tracks for the trains of a company.</p>

<p>The width of the railway tracks for the trains of the railroad company $j$ (1 ≤ j ≤ Q) is Xj . To attract the railroad company $j$, it is required that the following condition is satisfied.</p>

<p><strong>Condition</strong> It is possible to travel from any station to any other station using railway tracks of width $X_j$ only.</p>

<p>In order to satisfy the above condition, you can reconstruct the railway tracks as many times as needed.</p>

<p><strong>Reconstruction</strong> You choose a railway track. Then you reconstruct the chosen track so that its width will be increased or decreased by $1$. The cost is $1$. However, if the width of a railway track is $1$, it is impossible to decrease the width further.</p>

<p>In order to decide on the company to be attracted, you want to estimate the minimum cost to attract each railroad company.</p>

<p>White a program which, given information on the stations, the railway tracks, and the railroad companies, calculates the minimum cost to attract each railroad company.</p>

### 입력 

 <p>Read the following data from the standard input. Given values are all integers.</p>

<p>$\begin{align*}& N \, M \\ & A_1 \, B_1 \, W_1 \\ & A_2 \, B_2 \, W_2 \\ & \vdots \\ & A_M \, B_M \, W_M \\ & Q \\ & X_1 \\ & X_2 \\ & \vdots \\ & X_Q  \end{align*}$</p>

### 출력 

 <p>Write $Q$ lines to the standard output. The $j$-th line ($1 ≤ j ≤ Q$) of output should contain the minimum cost to attract the railroad company $j$.</p>

