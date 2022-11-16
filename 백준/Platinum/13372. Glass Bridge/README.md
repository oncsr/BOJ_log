# [Platinum V] Glass Bridge - 13372 

[문제 링크](https://www.acmicpc.net/problem/13372) 

### 성능 요약

메모리: 9832 KB, 시간: 200 ms

### 분류

자료 구조(data_structures), 세그먼트 트리(segtree)

### 문제 설명

<p>Water pollution is a problem common to many metropolis around the world, and the ACM metropolis of ICPC country is not an exception. Many cities try to solve this problem by having sewage treated before dumping into water sources, but for the ACM metropolis this is not a viable solution because space is a scarce treasure.</p>

<p>Alternatively, the government of ACM metropolis decided to use a chemical method. Specifically, the government would dump a treatment chemical into rivers around the metropolis to purify the water. However, the chemical reaction requires sunlight, thus all bridges across the rivers are being converted to Glass Bridge.</p>

<p>Funnily enough, the glass bridges still blocks 50% of the sunlight. If two glass bridges stacked, it only let 25% of total sunlight passing through. This could be a problem, as the chemical agent requires at least 40% of total sunlight to works. Although unavoidable, the government want to minimize the area that has less than 40% of sunlight.</p>

<p>The government has plans to construct N more bridge over a river. These bridges may overlaps, and thus limiting the sunlight. Given that three-story bridge is not feasible to construct (limiting the crossing bridges to two at a time), government wants to know how many areas of the river are covered with two bridge.</p>

<p>The metropolis around the river is structured such that the District 1 is directly across from District -1, District 2 from District -2, and so on. Each district has bridge to one another district across the river. </p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13372/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202016-10-11%20%EC%98%A4%ED%9B%84%204.05.59.png" style="height:171px; width:350px"></p>

### 입력 

 <p>First line has the number of test cases, T (1 ≤ T ≤ 20)</p>

<p>For each test case, the first line contains N specifying the number of bridge to construct. (2 ≤ N ≤ 100 000)</p>

<p>Then on the next line are integers a<sub>1</sub> a<sub>2</sub> a<sub>3 </sub>… a<sub>i</sub> … a<sub>n</sub> (1 ≤ a<sub>i</sub> ≤ N) saying that there are plan to construct bridge from District i to District –a<sub>i</sub> .</p>

### 출력 

 <p>For each test case, output a number of area that has bridge crossing each other.</p>

