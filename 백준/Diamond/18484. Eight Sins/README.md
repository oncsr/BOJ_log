# [Diamond V] Eight Sins - 18484 

[문제 링크](https://www.acmicpc.net/problem/18484) 

### 성능 요약

메모리: 13980 KB, 시간: 1748 ms

### 분류

이분 탐색

### 제출 일자

2024년 6월 10일 11:30:37

### 문제 설명

<p>Does every interactive problem have to be binary search?</p>

<p>Somebody has secretly set $n$ integers $a_1, a_2, \ldots, a_n$ such that $1 \le a_1 < a_2 < \ldots < a_n \le k$. You have to guess these integers one by one interacting with the testing system.</p>

<p>Initially $i = 1$. To make a guess, you may send an integer $x$ such that $1 \le x \le k$. The system will reply with a string containing a single character:</p>

<ul>
	<li>"<code>></code>" if $a_i > x$;</li>
	<li>"<code><</code>" if $a_i < x$;</li>
	<li>"<code>=</code>" if $a_i = x$.</li>
</ul>

<p>In case $a_i = x$, the value of $i$ is increased by 1. You win after you guess all $n$ integers correctly, that is, when $i$ reaches $n + 1$.</p>

<p>Note that the values of $a_1, a_2, \ldots, a_n$ are not chosen in advance by the interactor, but all replies to your queries will be consistent with some valid set of $a_1, a_2, \ldots, a_n$ at any time.</p>

### 입력 

 Empty

### 출력 

 Empty

