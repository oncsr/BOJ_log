# [Diamond V] M - 25458 

[문제 링크](https://www.acmicpc.net/problem/25458) 

### 성능 요약

메모리: 278580 KB, 시간: 2616 ms

### 분류

자료 구조, 그래프 이론, 그래프 탐색, 트리, 이분 탐색, 깊이 우선 탐색, 분리 집합, 최소 스패닝 트리, 최소 공통 조상, 희소 배열, 병렬 이분 탐색

### 제출 일자

2025년 5월 20일 14:22:58

### 문제 설명

<p>M je kodno ime osobe koja obnaša jednu od ključnih funkcija britanske tajne službe (MI6). Jedna od glavnih zadaća na toj funkciji je analiza sigurnosnih svojstava neprijateljskih komunikacijskih mreža. Ovaj zadatak ocrtava jedan od tipičnih problema s kojima se M dnevno susreće.</p>

<p>Neprijateljska komunikacijska mreža sastoji se od $N$ (naizgled običnih) poštanskih ureda i $M$ dvosmjernih prometnica koje direktno povezuju neke parove poštanskih ureda. Radi jednostavnosti, poštanske urede ćemo označiti prirodnim brojevima od $1$ do $N$.</p>

<p>Kada neprijatelj želi poslati tajnu informaciju iz ureda s oznakom $a$ do ureda s oznakom $b$, tajni agent će sjesti u lažno vozilo pošte i provozati se nekim nizom prometnica koje tvore put između ta dva poštanska ureda. Par poštanskih ureda $(a, b)$ smatra se <em>ranjivim</em> ako postoji neka cesta po kojoj će tajni agent sigurno morati proći na svom putovanju od ureda $a$ do ureda $b$, ili ako uopće ne postoji put između ta dva ureda.</p>

<p>M se danas bavi analizom povijesne ranjivosti jedne takve mreže. Naime, M je prikupio informacije o povijesnom razvoju mreže, što znači da zna kojim su se redoslijedom gradile prometnice između poštanskih ureda. Sada ga za neke parove ureda zanima u kojem su trenutku (ako uopće) prestali biti ranjivi.</p>

### 입력 

 <p>U prvom su retku brojevi $N$ i $M$ iz teksta zadatka.</p>

<p>U $i$-tom od idućih $M$ redaka su $x_i$ i $y_i$ koji označavaju da je $i$-ta izgrađena prometnica povezivala poštanske urede s oznakama $x_i$ i $y_i$ ($x_i ≠ y_i$).</p>

<p>Moguće je da više od jedne prometnice povezuje isti par poštanskih ureda.</p>

<p>U sljedećem se retku nalazi prirodan broj $Q$ koji označava broj upita na koje $M$ želi dobiti odgovor.</p>

<p>U $j$-tom od sljedećih $Q$ redaka su različiti brojevi $a_j$ i $b_j$ koji definiraju $j$-ti upit agenta M. Odnosno, M želi saznati u kojem je trenutku par ureda $(a_j , b_j )$ prestao biti ranjiv.</p>

### 출력 

 <p>U $j$-tom retku treba ispisati odgovor na $j$-ti upit agenta M.</p>

<p>Ako je par ureda iz $j$-tog upita i dalje ranjiv, odgovor na $j$-ti upit je $-1$. Inače, odgovor je prirodan broj $k$ koji označava da je par ureda iz upita prestao biti ranjiv nakon izgradnje $k$-te prometnice.</p>

