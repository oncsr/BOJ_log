# [Platinum V] Kitchen Measurements - 11535 

[문제 링크](https://www.acmicpc.net/problem/11535) 

### 성능 요약

메모리: 7272 KB, 시간: 464 ms

### 분류

너비 우선 탐색, 자료 구조, 데이크스트라, 그래프 이론, 그래프 탐색, 해시를 사용한 집합과 맵, 최단 경로, 트리를 사용한 집합과 맵

### 제출 일자

2024년 11월 7일 19:15:43

### 문제 설명

<p>You are making a recipe and need to measure a precise volume of liquid. There are an assortment of cups of varying volumes in your kitchen, however no cup has any markings on it other than to indicate its total volume, and none of them match the volume that you want. You start with the biggest cup full of liquid and, to make sure you know precisely how much volume you are working with at any point in time, you consider steps in which you pour from any nonempty cup into another cup, always pouring until either the cup you are pouring into becomes full, or the cup you are pouring from becomes empty (whichever occurs first). As a simple example, assume you start with a full cup having capacity 5, and you have another cup with capacity 2, but your goal is to have 3 units of the liquid in the largest cup. In this case, you can start pouring from the larger cup to the smaller, stopping when the smaller one reaches its capacity of 2. This will leave precisely 3 units in the larger cup. See Figure E.1(a).</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11535/1.png" style="height:268px; width:383px"></p>

<p style="text-align:center">Figure E.1: Pouring between cups</p>

<p>As another example, consider a case in which you have 4 cups with capacities 9, 6, 3, and 2, and you start with the largest cup full, the rest empty, and a goal of ending with 8 units in the largest cup. For ease of discussion we will refer to the cup with capacity 9 as the “9-cup” and similarly for the other sizes. You notice that the 6-cup and 2-cup have combined capacity of 8, and so you could pour from the original 9-cup to fill those two cups, then dump the remaining 1 unit from the 9-cup into the 3-cup, and finally pour the full 6-cup and 2-cup back into the 9-cup. See Figure E.1(b). In implementing this strategy, the total volume of liquid poured would be 6 + 2 + 1 + 6 + 2 = 17. You could achieve this goal in another way: pour 3 units from the 9-cup to the 3-cup (leaving 6 units in the 9-cup), then fill the 2-cup from the 3-cup (leaving 1 unit in the 2 cup), and finally pour the full 2-cup back into the 9-cup, resulting in exactly 8 units in that cup. With this strategy, the total volume poured is only 3 + 2 + 2 = 7. See Figure E.1(c).</p>

<p>As a final example, you start with cups of capacities 11, 10, 7, 4, and 2, with the 11-cup full, and a goal of ending up with 10 units in the 11-cup. Obviously, you could fill the 10-cup, dump the remaining 1 unit into another cup, and then pour from the full 10-cup back into the 11-cup, as illustrated in Figure E.2(a). These three pours would mean transferring a total volume of 10 + 1 + 10 = 21. Figure E.2(b) shows a sequence with more steps, but less liquid poured.</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11535/2.png" style="height:329px; width:351px"></p>

<p style="text-align:center">Figure E.2: More pouring</p>

### 입력 

 <p>The input consists of a single line of positive integers: n c<sub>1</sub> c<sub>2</sub> . . . c<sub>n</sub> V , where there are n cups, with 2 ≤ n ≤ 5, having capacities satisfying 64 ≥ c<sub>1</sub> > c<sub>2</sub> > . . . > c<sub>n</sub> ≥ 1. The value V < c<sub>1</sub> designates the desired volume. You must start with largest cup (that with capacity c<sub>1</sub>) full of liquid and the other cups empty, and the goal is to get exactly volume V into the largest cup.</p>

### 출력 

 <p>Output the minimum amount of liquid that must be poured to achieve the goal, or output impossible if the goal cannot be achieved.</p>

