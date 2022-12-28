# [Gold IV] Dollar Dayz - 26988 

[문제 링크](https://www.acmicpc.net/problem/26988) 

### 성능 요약

메모리: 30616 KB, 시간: 48 ms

### 분류

다이나믹 프로그래밍(dp)

### 문제 설명

<p>Farmer John goes to Dollar Days at The Cow Store and discovers an unlimited number of tools on sale. During his first visit, the tools are selling variously for <span>$</span>1, <span>$</span>2, and <span>$</span>3. Farmer John has exactly <span>$</span>5 to spend. He can buy 5 tools at <span>$</span>1 each or 1 tool at <span>$</span>3 and an additional 1 tool at <span>$</span>2. Of course, there are other combinations for a total of 5 different ways FJ can spend all his money on tools. Here they are:</p>

<pre>        1 @ US$3 + 1 @ US$2
        1 @ US$3 + 2 @ US$1
        1 @ US$2 + 3 @ US$1
        2 @ US$2 + 1 @ US$1
        5 @ US$1
</pre>

<p>Write a program than will compute the number of ways FJ can spend N dollars (1 ≤ N ≤ 1000) at The Cow Store for tools on sale with a cost of <span>$</span>1..<span>$</span>K (1 ≤ K ≤ 100).</p>

### 입력 

 <p>A single line with two space-separated integers: N and K.</p>

### 출력 

 <p>A single line with a single integer that is the number of unique ways FJ can spend his money.</p>

