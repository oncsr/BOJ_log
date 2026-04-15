# [Diamond V] Hangar Hurdles - 13952 

[문제 링크](https://www.acmicpc.net/problem/13952) 

### 성능 요약

메모리: 317776 KB, 시간: 1596 ms

### 분류

자료 구조, 그래프 이론, 이분 탐색, 누적 합, 분리 집합, 병렬 이분 탐색

### 제출 일자

2025년 11월 23일 21:27:07

### 문제 설명

<p>You are evaluating constructions plans for a giant new hangar that will house an airplane assembly line. The hangar floor can be represented as a rectangular grid consisting of n rows and n columns where every cell is either empty or blocked. The rows are numbered with integers 1 through n top to bottom, while the columns are numbered with integers 1 through n left to right.</p>

<p>It is important that large crates containing airplane parts can be freely moved between various locations inside the hangar. We can model a crate as a square aligned with grid cells and centered in one of the cells. Therefore, for an odd integer k, a crate of size k consists of cells in k consecutive rows and k consecutive columns. The crate can be moved up, down, left or right as long as it fits completely inside the grid and never contains a blocked cell.</p>

<p>You are given q pairs of cells A<sub>k</sub> and B<sub>k</sub> . For each pair, find the size of the largest crate that can be centered in A<sub>k</sub> and then moved across the hangar floor until it’s centered in B<sub>k</sub> .</p>

### 입력 

 <p>The first line contains an integer n (2 ≤ n ≤ 1 000) — the size of the hangar floor. Each of the following n lines contains a string of exactly n characters describing one row of the floor. The character “#” denotes a blocked cell while the character “.” denotes an empty cell.</p>

<p>The following line contains an integer q (1 ≤ q ≤ 300 000) — the number of queries. The k-th of the following q lines contains four integers r<sub>Ak</sub> , c<sub>Ak</sub> ,r<sub>Bk</sub> , c<sub>Bk</sub> (1 ≤ r<sub>Ak</sub> , c<sub>Ak</sub> ,r<sub>Bk</sub> , c<sub>Bk</sub> ≤ n) — the row number and column number of cells A<sub>k</sub> and B<sub>k</sub> respectively. Cell A<sub>k</sub> will be different than the cell B<sub>k</sub> . Also, both cells will always be empty</p>

### 출력 

 <p>Output q lines. The k-th line should contain a single integer s<sub>k</sub> — the size of the largest crate that can be moved from A<sub>k</sub> to B<sub>k</sub> . If no crate can be moved from A<sub>k</sub> to B<sub>k</sub> then s<sub>k</sub> should be 0.</p>

