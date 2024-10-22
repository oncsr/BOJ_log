# [Gold III] Walk the Talk - 7037 

[문제 링크](https://www.acmicpc.net/problem/7037) 

### 성능 요약

메모리: 2192 KB, 시간: 12 ms

### 분류

다이나믹 프로그래밍, 누적 합, 문자열

### 제출 일자

2024년 10월 22일 12:43:07

### 문제 설명

<p>Farmer John has set up a puzzle for his cows to solve. At the entrance to the barn, he has laid out an H x W (1 <= H <= 30, 1 <= W <= 30) grid of letters. Before a cow can enter the barn, she must spell out a valid English word by jumping from square to square, creating a sequence of letters. She can start at any square but may only jump to a subsequent square that is located to the right and/or above the current square (i.e., neither to the left nor lower). The next square can be any distance from the current one since the cows are world-class jumpers!</p>

<p>No two cows may traverse the exact same path, although two cows are allowed to spell the same word via different paths.</p>

<p>As an example, consider this grid (presuming 'TO' and 'OX' are words):</p>

<pre><code>T X X O
T X Q T
X T X Q</code></pre>

<p>Four paths are valid, all spelling 'TO' (one spelling requires a 'T' from the bottom row and an 'O' from the top row). 'OX' is a valid word, but would require jumping to an 'X' square left of the 'O', which is not allowed.</p>

<p>Given the grid and a list of valid words, compute the number of cows that can enter the barn without any cow repeating a path. See a copy of the list <a href="https://upload.acmicpc.net/cc33b2da-a711-49a1-b809-aa4495021fe4/">here</a>.</p>

### 입력 

 <ul>
	<li>Line 1: Two integers: H and W</li>
	<li>Lines 2..H+1: Each line contains W characters, without spaces, representing a row in the grid. The first row is the top row.The first character in each row is the left-most character.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: The number of cows that can enter the barn without repeating a path.</li>
</ul>

