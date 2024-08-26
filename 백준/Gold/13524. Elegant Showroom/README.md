# [Gold IV] Elegant Showroom - 13524 

[문제 링크](https://www.acmicpc.net/problem/13524) 

### 성능 요약

메모리: 2864 KB, 시간: 16 ms

### 분류

데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2024년 8월 26일 18:48:57

### 문제 설명

<p>A car showroom is one of the few places where cars can be found indoors. Showrooms often have many cars, even above ground level! As cars are sold and new cars are bought in to sell, the cars must be moved carefully out of the showroom.</p>

<p>Clearly employees only wish to move cars if they have to. So, given a map of a showroom including its walls, doors and where the cars are, and the co-ordinates of the car to move, how many cars must be moved?</p>

<p>Cars can be rotated on the spot, but can only be moved through a completely empty space and not diagonally. Doors are always wide enough to move a car through.</p>

### 입력 

 <ul>
	<li>One line containing two integers R, C (3 ≤ R, C ≤ 400), the size of the showroom in rows and columns.</li>
	<li>Another R lines, each containing a string of C characters with the following meaning:
	<ul>
		<li>’#’: a wall;</li>
		<li>’c’: a car;</li>
		<li>’D’: a door in a wall.</li>
	</ul>
	</li>
	<li>The first and last lines must be walls or doors. The first and last characters in a row must be walls or doors.</li>
	<li>The next line will contain two integers r (1 < r < R), and c (1 < c < C), the co-ordinates of the car to move. 1, 1 is the top-left corner.</li>
</ul>

### 출력 

 <ul>
	<li> One line containing one integer: the smallest number of cars that need to be moved (including the car we are moving) to allow our desired car to leave the building.</li>
</ul>

