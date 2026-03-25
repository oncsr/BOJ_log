# [Platinum I] Railway - 22197 

[문제 링크](https://www.acmicpc.net/problem/22197) 

### 성능 요약

메모리: 137856 KB, 시간: 1672 ms

### 분류

그래프 이론, 그래프 탐색, 트리, 누적 합, 깊이 우선 탐색, 최소 공통 조상, 작은 집합에서 큰 집합으로 합치는 테크닉

### 제출 일자

2026년 3월 25일 17:54:45

### 문제 설명

<p>A couple of years ago the Bergen Ministry of Infrastructure prepared a plan for a new light railway network. This network was supposed to connect all n neighbourhoods in the city with n−1 railway tracks in such a way, that there would be a path from every neighbourhood to every other neighbourhood. The planned tracks are identified by numbers from 1 to n − 1.</p>

<p>Years passed, new elections are approaching, and the railway network still exists only on paper. Therefore the Minister of Infrastructure (representing a party holding disagreement in high regard) decided to construct at least some part of the plan. He asked each of his m deputy ministers to choose which neighbourhoods they thought should be connected. That will result in a list of necessary tracks for each deputy minister. If a deputy minister thinks that the neighbourhoods a<sub>1</sub>, . . . , a<sub>s</sub> need to be connected, then according to him or her, the necessary tracks are all those which lie on planned paths from a<sub>i</sub> to a<sub>j</sub> for some 1 ≤ i < j ≤ s.</p>

<p>The minister just received all lists from the deputy ministers. He decided to construct in the first place the tracks which are requested by at least k deputy ministers. Your task is to prepare a list of these tracks.</p>

### 입력 

 <p>In the first line of the input there are three integers n, m and k. The next n − 1 lines contain the plan; in the i-th of these lines there are two integers a<sub>i</sub> and b<sub>i</sub> (1 ≤ a<sub>i</sub>, b<sub>i</sub> ≤ n, a<sub>i</sub> ≠ b<sub>i</sub>), specifying that the i-th track on the plan is between neighbourhoods a<sub>i</sub> and b<sub>i</sub>.</p>

<p>In the next m lines there are neighbourhoods chosen by deputy ministers; the i-th of these lines begins with an integer s<sub>i</sub> which specify the number of neighbourhoods chosen by the i-th deputy minister. After it there are s<sub>i</sub> integers specifying these neighbourhoods. The total length of all lists of deputy ministers is at most S, i.e. ∑s<sub>i</sub> ≤ S.</p>

### 출력 

 <p>In the first line of the output you should write one integer r, specifying the number of tracks which are requested by at least k deputy ministers. In the second line you should write r identifiers of these tracks in ascending order.</p>

