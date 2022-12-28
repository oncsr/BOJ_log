# [Gold V] Agar.io - 26732 

[문제 링크](https://www.acmicpc.net/problem/26732) 

### 성능 요약

메모리: 8296 KB, 시간: 76 ms

### 분류

자료 구조(data_structures), 그리디 알고리즘(greedy), 구현(implementation), 우선순위 큐(priority_queue), 시뮬레이션(simulation)

### 문제 설명

<p>Gra agar.io (swego czasu dość popularna w sieci) jest rozgrywana w przeglądarce internetowej. Każdy z obecnych na serwerze graczy steruje pojedynczą komórką o pewnej masie. Kiedy spotyka komórkę o masie mniejszej niż swoja, wchłania ją, powiększając swoją masę o masę drugiej komórki. Kiedy jednak spotka komórkę o masie większej lub równej swojej, natychmiast przegrywa.</p>

<p>Bajtek połączył się właśnie z serwerem gry i jego komórka ma niezbyt imponującą masę 2. Bardzo chciałby jednak wygrać, czyli zostać najwiekszą komórką na tym serwerze. Dzięki niebywałym umiejętnościom hakerskim udało mu się zablokować możliwość poruszania się innych graczy – czyli jest w stanie swobodnie wybierać kolejne ofiary do wchłonięcia, a inni gracze nie mogą uniknąć spotkania.</p>

<p>Ta miła sytuacja nie potrwa jednak długo i administratorzy serwera niebawem cofną blokady Bajtka. Bajtek jest w stanie wchłonąć swoją komórką inną komórkę w czasie jednej sekundy. Ile sekund będzie potrzebował, aby stać się największą komórką na serwerze? Bajtek zadowoli się ewentualnym remisem z innymi największymi komórkami. Napisz program, który na podstawie masy komórek kontrolowanych przez przeciwników Bajtka na serwerze gry, wyznaczy minimalny czas potrzebny Bajtkowi aby stać się największą komórką w grze. Przypominamy, że komórka Bajtka zaczyna z masą równą 2.</p>

### 입력 

 <p>W pierwszym wierszu wejścia znajduje się jedna liczba naturalna N (1 ≤ N ≤ 200 000) określająca liczbę komórek przeciwników Bajtka. W drugim (ostatnim) wierszu wejścia znajduje się ciąg N liczb naturalnych T<sub>i</sub> (1 ≤ T<sub>i</sub> ≤ 10<sup>18</sup>) pooddzielanych pojedynczymi odstępami. Są to masy komórek kolejnych przeciwników Bajtka.</p>

### 출력 

 <p>W pierwszym (jedynym) wierszu wyjścia powinna się znaleźć jedna nieujemna liczba całkowita – minimalny czas w sekundach potrzebny aby komórka Bajtka stała się największa na serwerze (przy założeniu, że pozostałe komórki nie będą zjadać innych).</p>

<p>Jeżeli osiągnięcie tego celu jest niemożliwe, należy zamiast tego wypisać tylko jedno słowo <code>NIE</code>.</p>

