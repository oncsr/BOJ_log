# [Diamond IV] 히스토그램 하나 빼기 - 25611 

[문제 링크](https://www.acmicpc.net/problem/25611) 

### 성능 요약

메모리: 46912 KB, 시간: 880 ms

### 분류

자료 구조, 세그먼트 트리, 스위핑, 분리 집합

### 제출 일자

2025년 7월 11일 12:27:01

### 문제 설명

<p>레프는 너비가 1이고, 높이가 <em>h</em><sub>1</sub>, ⋯, <em>h</em><sub><em>N</em></sub>인 <em>N</em>개의 막대기들이 많이 있다. 레프는 이 막대기들을 사용해서 학생들에게 히스토그램에 완전히 포함되는 직사각형 중 넓이가 가장 큰 것을 구하는 문제를 내려고 한다.</p>

<p><em>N</em>명의 학생들에게는 서로 다른 문제를 내야 하는데, 히스토그램을 만들 막대기 종류가 부족했던 레프는 다음과 같이 너비가 (<em>N</em> − 1)인 히스토그램을 <em>N</em>개 만들기로 했다.</p>

<ul>
	<li><em>i</em>번째 막대기를 제거하고, 높이가 <em>h</em><sub>1</sub>, ⋯, <em>h</em><sub><em>i</em> − 1</sub>, <em>h</em><sub><em>i</em> + 1</sub>, ⋯, <em>h</em><sub><em>N</em></sub>인 (<em>N</em> − 1)개의 막대기들을 순서대로 이어붙여 히스토그램 <em>H</em><sub><em>i</em></sub>를 만든다.</li>
</ul>

<p><em>H</em><sub><em>i</em></sub>에서의 직사각형 넓이의 최댓값을 <em>S</em><sub><em>i</em></sub>라고 하자. <em>S</em><sub>1</sub>, ⋯, <em>S</em><sub><em>N</em></sub>을 구하는 프로그램을 작성하여, 레프가 편하게 채점할 수 있도록 도와주자!</p>

### 입력 

 <p>첫째 줄에 양의 정수 <em>N</em>이 주어진다. (2 ≤ <em>N</em> ≤ 500 000)</p>

<p>둘째 줄에 <em>N</em>개의 정수 <em>h</em><sub>1</sub>, ⋯, <em>h</em><sub><em>N</em></sub>이 공백으로 구분되어 주어진다. (1 ≤ <em>h</em><sub><em>i</em></sub> ≤ 10<sup>9</sup>)</p>

### 출력 

 <p>첫째 줄에 <em>N</em>개의 정수 <em>S</em><sub>1</sub>, ⋯, <em>S</em><sub><em>N</em></sub>을 공백으로 구분하여 출력한다.</p>

