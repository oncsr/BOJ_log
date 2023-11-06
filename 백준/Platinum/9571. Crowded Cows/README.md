# [Platinum V] Crowded Cows - 9571 

[문제 링크](https://www.acmicpc.net/problem/9571) 

### 성능 요약

메모리: 3004 KB, 시간: 20 ms

### 분류

자료 구조, 트리를 사용한 집합과 맵, 두 포인터

### 제출 일자

2023년 11월 6일 17:13:40

### 문제 설명

<p>Farmer John's N cows (1 <= N <= 50,000) are grazing along a one-dimensional fence.  Cow i is standing at location x(i) and has height h(i) (1 <= x(i),h(i) <= 1,000,000,000).</p><p>A cow feels "crowded" if there is another cow at least twice her height within distance D on her left, and also another cow at least twice her height within distance D on her right (1 <= D <= 1,000,000,000).  Since crowded cows produce less milk, Farmer John would like to count the number of such cows.  Please help him.</p>

### 입력 

 <ul><li>Line 1: Two integers, N and D.</li><li>Lines 2..1+N: Line i+1 contains the integers x(i) and h(i).  The locations of all N cows are distinct.</li></ul>

### 출력 

 <ul><li>Line 1: The number of crowded cows.</li></ul>

