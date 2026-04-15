# [Diamond V] Bicycle Tour - 26851 

[문제 링크](https://www.acmicpc.net/problem/26851) 

### 성능 요약

메모리: 27328 KB, 시간: 328 ms

### 분류

자료 구조, 그래프 이론, 트리, 세그먼트 트리, 분리 집합, 느리게 갱신되는 세그먼트 트리, 최소 스패닝 트리, 최소 공통 조상, Heavy-light 분할

### 제출 일자

2024년 3월 16일 18:07:57

### 문제 설명

<p>There are N junctions in Jakarta (numbered from 1 to N) that are connected by M bidirectional roads such that from any junction you can reach any other junctions by going through one or more roads. The i<sup>th</sup> junction has a height of H<sub>i</sub>.</p>

<p>Ahmad loves to cycle, especially on flat roads. He argues that you need more power to cycle if the road is uphill or downhill. Specifically, to cycle on a road connecting junction i and junction j, you will require a power of |H<sub>i</sub> − H<sub>j</sub>|. The required power to cycle a set of roads is equal to the highest required power to cycle each of those roads. For example, let there be 3 roads where each requires a power of 10, 12, and 7 to cycle, then the required power to cycle through all those roads is max(10, 12, 7) = 12.</p>

<p>A cycling route from junction i is defined as a tour that starts at junction i, going to one or more other junctions while not using the same road more than once, and ends at the same junction i.</p>

<p>Ahmad would like to find a cycling route from each junction that has a minimum required power, and that is your task in this problem. For each junction, you need to output the required power of a cycling route from that junction that has the minimum required power. There might be a case where a cycling route from a junction is not possible; in such a case, the output should be −1 for the respective junction.</p>

<p>For example, let N = 8, H<sub>1..8</sub> = {5, 2, 7, 0, 10, 6, 6, 6}, M = 11, and the roads be shown in the following figure. The label on each node indicates the junction number while the number on each edge indicates the required power to cycle through that road. Notice that the required power to cycle through each road can be obtained from the given H<sub>1..8</sub>.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 450px; height: 141px;"></p>

<p>The following are the cycling routes with the minimum required power from each junction:</p>

<ul>
	<li>Junction 1: 1 → 2 → 7 → 6 → 1, with a required power of 4.</li>
	<li>Junction 2: 2 → 1 → 6 → 7 → 2, with a required power of 4.</li>
	<li>Junction 3: 3 → 2 → 1 → 3, with a required power of 5.</li>
	<li>There is no possible cycling route from junction 4.</li>
	<li>Junction 5: 5 → 3 → 1 → 2 → 5, with a required power of 8.</li>
	<li>Junction 6: 6 → 7 → 8 → 6, with a required power of 0.</li>
	<li>Junction 7: 7 → 8 → 6 → 7, with a required power of 0.</li>
	<li>Junction 8: 8 → 6 → 7 → 8, with a required power of 0.</li>
</ul>

### 입력 

 <p>Input begins with a line containing two integers N M (2 ≤ N ≤ 100 000; N − 1 ≤ M ≤ 200 000) representing the number of junctions and the number of bidirectional roads, respectively. The second line contains N integers H<sub>i</sub> (0 ≤ H<sub>i</sub> ≤ 10<sup>9</sup>) representing the height of the i th junction. The next M lines, each contains two integers u<sub>i</sub> v<sub>i</sub> (1 ≤ u<sub>i</sub> < v<sub>i</sub> ≤ N) representing a bidirectional road connecting junction u<sub>i</sub> and v<sub>i</sub>. It is guaranteed that from any junction you can reach any other junctions by going through one or more roads. It is also guaranteed that for any pairs of junctions (u, v), there is at most one bidirectional road connecting junction u and junction v.</p>

### 출력 

 <p>Output contains N integers in a line each separated by a single space. The i<sup>th</sup> integer represents the required power of a cycling route from junction i with the minimum required power. If there is no possible cycling route from junction i, then the i<sup>th</sup> integer is -1.</p>

