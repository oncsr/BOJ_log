# [Diamond V] Urban geography - 31393 

[문제 링크](https://www.acmicpc.net/problem/31393) 

### 성능 요약

메모리: 355468 KB, 시간: 3724 ms

### 분류

자료 구조, 그래프 이론, 이분 탐색, 분리 집합, 매개 변수 탐색, 분할 정복, 오프라인 쿼리, 오프라인 동적 연결성 판정

### 제출 일자

2025년 9월 1일 01:19:58

### 문제 설명

<p>Android Vasya prepares a project in Urban geography. The aim of the project is to improve the infrasructure of the city he lives in.</p>

<p>Now the city consists of $n$ districts, some of which are connected by roads. Using these roads one can get from any district to any other district of the city by car. Vasya thinks that such big amount of roads makes citizens use their own cars instead of walking or cycling. He wants to close as many roads for cars as possible and turn them into boulevards. Of course, Vasya wants to keep the possibility to get from any district to any other district of the city by car using roads.</p>

<p>Now citizens pay for using roads, and prices for different roads may vary very much. Vasya thinks that leaving open some expensive and some cheap roads at the same time is not a good idea beacuse it can increase social tension in the city. That's why he wants to minimize the price spread between the most expensive and the cheapest roads. Help Vasya choose the roads to keep open.</p>

### 입력 

 <p>The first line contains integers $n$ и $m$ --- the number of city districts and roads accordingly ($2 \leq n \leq 30\,000; n - 1 \leq m \leq 30\,000$). The next $m$ lines contain triples of integers $a_i$, $b_i$ и $c_i$, meaning that between the city districts $a_i$ и $b_i$ there is a road with the price $c_i$ ($1 \leq a_i, b_i \leq n$; $a_i \neq b_i$; $1 \leq c_i \leq 10^9$). There can be several roads between two districts.</p>

### 출력 

 <p>In the only line output the sequence of integers --- numbers of the roads which should be kept open in the city. The roads are numbered as they appear in the input data. If there are several solutions, output any of them.</p>

