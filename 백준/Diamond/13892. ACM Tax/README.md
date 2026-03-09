# [Diamond V] ACM Tax - 13892 

[문제 링크](https://www.acmicpc.net/problem/13892) 

### 성능 요약

메모리: 358048 KB, 시간: 6692 ms

### 분류

자료 구조, 트리, 세그먼트 트리, 최소 공통 조상, 퍼시스턴트 세그먼트 트리

### 제출 일자

2026년 3월 10일 04:01:32

### 문제 설명

<p>Mr. Peter lives in the magical lands of ACM City. The city consists of N districts and N – 1 two-way roads. Each road connects a pair of districts, and for each road we know the length of the road. All districts are connected to each other, meaning Mr. Peter can always travel from any district A to any district B.</p>

<p>The ACM City has a very special rule for travelling. If anyone wants to travel from district A to district B, they must pay the tax equal to the median of the length of all roads from district A to district B. For example, this ACM City of 6 districts.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13892/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202016-11-21%20%EC%98%A4%ED%9B%84%205.02.17.png" style="height:284px; width:530px"></p>

<p>All circles represent districts and lines represent roads connecting two districts. Numbers inside the circles are the number of each district and numbers above the lines are the length of each road. If Mr. Peter travels from district 1 to district 3, the length of all roads would be 1, 5, and 9, therefore he must pay the tax of 5 dollars. However, if Mr. Peter travels from district 6 to district 4, he must pay 4.5 dollars, for the length of the roads are 1, 4, 5, and 7.</p>

<p>Mr. Peter is a very curious person. He wants to know the tax he needs to pay to travel from any two districts. However, Mr. Peter is too lazy to calculate the tax himself, so he asks you, the best programmer in the city, to calculate the tax Mr. Peter needs to pay from district A to district B.</p>

<p>Note: The ‘Median’ is the middle value of a sorted list of numbers. For example, the median of the list 1, 5, 7, 7, 9, 10, 16 is 7. If the amount of numbers in the list is even, the median is the sum of two middle numbers divided by 2. For example, the median of the list 1, 5, 7, 9, 10, 17, 28, 30 is (9+10)/2, which is 9.5.</p>

<p>Given the ACM City of N districts, for each question, find the median of the length of all path from district A to district B.</p>

### 입력 

 <p>The first line contains number of test case T (T ≤ 15). Then for each test case:</p>

<p>The first line contains one integer N (2 ≤ N ≤ 50 000) — the number of districts.</p>

<p>The next N – 1 lines contain three integers U<sub>i</sub>, V<sub>i</sub>, W<sub>i</sub> (1 ≤ U<sub>i</sub>, V<sub>i</sub> ≤ N, U<sub>i</sub> ≠ V<sub>i</sub>, 1 ≤ W<sub>i </sub>≤ 100 000) — the roads connecting district U<sub>i</sub>, and V<sub>i </sub>with the length W<sub>i</sub> .</p>

<p>The next line contains one integer Q (1 ≤ Q ≤ 100 000) — the number of questions Mr. Peter wants to ask.</p>

<p>The next Q lines contain two integers A<sub>i</sub>, B<sub>i</sub> (1 ≤ A<sub>i</sub>, B<sub>i </sub>≤ N, A<sub>i</sub> ≠ B<sub>i</sub>) — the questions Mr. Peter wants to ask how much he needs to pay to travel from district A<sub>i</sub> to district B<sub>i</sub>.</p>

### 출력 

 <p>Print Q lines. In each line contains one real number with one digit after the decimal point — the tax Mr. Peter needs to pay to travel from district A<sub>i</sub> to district B<sub>i</sub>.</p>

