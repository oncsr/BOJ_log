# [Gold III] FEB - 28034 

[문제 링크](https://www.acmicpc.net/problem/28034) 

### 성능 요약

메모리: 2648 KB, 시간: 8 ms

### 분류

애드 혹, 해 구성하기, 그리디 알고리즘

### 제출 일자

2023년 5월 12일 01:16:06

### 문제 설명

<p>Bessie and Elsie are plotting to overthrow Farmer John at last! They plan it out over $N$ ($1\le N\le 2\cdot 10^5$) text messages. Their conversation can be represented by a string $S$ of length $N$ where $S_i$ is either $B$ or $E$, meaning the $i$th message was sent by Bessie or Elsie, respectively.</p>

<p>However, Farmer John hears of the plan and attempts to intercept their conversation. Thus, some letters of $S$ are $F$, meaning Farmer John obfuscated the message and the sender is unknown.</p>

<p>The <em>excitement level</em> of a non-obfuscated conversation is the number of times a cow double-sends - that is, the number of occurrences of substring $BB$ or $EE$ in $S$. You want to find the excitement level of the original message, but you don’t know which of Farmer John’s messages were actually Bessie’s / Elsie’s. Over all possibilities, output all possible excitement levels of $S$.</p>

### 입력 

 <p>The first line will consist of one integer $N$.</p>

<p>The next line contains $S$.</p>

### 출력 

 <p>First output $K$, the number of distinct excitement levels possible. On the next $K$ lines, output the excitement levels, in increasing order.</p>

