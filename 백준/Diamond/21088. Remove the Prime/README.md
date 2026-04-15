# [Diamond III] Remove the Prime - 21088 

[문제 링크](https://www.acmicpc.net/problem/21088) 

### 성능 요약

메모리: 2296 KB, 시간: 5812 ms

### 분류

수학, 정수론, 게임 이론, 소수 판정, 소인수분해, 스프라그–그런디 정리, 폴라드 로, 밀러–라빈 소수 판별법

### 제출 일자

2024년 8월 8일 04:47:39

### 문제 설명

<p>Two players play a game using an array of positive integers. They make alternating moves, the player who cannot make a move loses. In one move you have to choose a <strong>prime</strong> number $p$ and a non-empty segment $[l;r]$ of the array such that all numbers in this segment are divisible by $p$, and then remove <strong>all</strong> factors $p$ from each of them. Removing all factors means that we take a number and divide it by $p$ while it is divisible.</p>

<p>Determine who wins if both players play optimally.</p>

### 입력 

 <p>The first line contains one integer $n$ ($1 \le n \le 1000$) --- the size of array.</p>

<p>The second line contains the array $a_{1}, a_{2}, \ldots, a_{n}$ itself ($1 \le a_{i} \le 10^{18}$).</p>

### 출력 

 <p>Print "<code>First</code>" (without quotes) if first player wins and "<code>Second</code>" (without quotes) otherwise.</p>

