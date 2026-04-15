# [Diamond IV] Vjeverice - 28713 

[문제 링크](https://www.acmicpc.net/problem/28713) 

### 성능 요약

메모리: 184452 KB, 시간: 1712 ms

### 분류

자료 구조, 그래프 이론, 그래프 탐색, 트리, 세그먼트 트리, 분리 집합, 느리게 갱신되는 세그먼트 트리, 최소 스패닝 트리, 최소 공통 조상, 희소 배열, Heavy-light 분할

### 제출 일자

2025년 12월 18일 00:11:39

### 문제 설명

<p>Živopisan Lund, gradić na jugu Švedske, krasi predivan park Botaniska Trädgården, a u njemu stanuju - vjeverice!</p>

<p>U parku je $n$ stabala, a vjeverice između $m$ parova stabala imaju označen puteljak. Svake godine ih dočeka isti problem: dođe jesen, lišće počne padati, i zatrpa im puteljke. Tada vjeverica moraju ponovno kamenčićima označavati sve puteljke. Već su to toliko puta ponovile da za svaki puteljak znaju koliko im je kamenčića potrebno da ga ponovo označe, za $i$-ti puteljak, koji spaja $a_i$-to stablo i $b_i$-stablo, potrebno im je $c_i$ kamenčića.</p>

<p>Za ovu godinu osmislile su novi plan: odlučile su ne označiti sve puteljke, nego samo njih $n - 1$. Učiniti će to na način da su sva stabla povezana, tj. između svakog para stabala postoji uzastopan niz označenih puteljaka koji od jednog stabla vodi do drugog. Dodatno, puteljke će odabrati na način da ukupan broj kamenčića na puteljcima bude najmanji moguć.</p>

<p>Koliko kamenčića će im biti potrebno?</p>

<p>Taman kad su se bacile na izračun potrebnih kamenčića, javilo se $q$ vjeverica, $i$-ta od njih izrazila je svoju sumnju u broj kamenčića potrebnih za označavanje puteljaka:</p>

<p style="text-align: center;">Za označiti $x_i$-ti puteljak potrebno nam je $d_i$ kamenčića, a ne $c_i$!.</p>

<p>Koliko im je ukupno kamenčića potrebno za označavanje puteljaka po novom planu ako je izjava $i$-te vjeverica istinita, a izjave ostalih vjeverica lažno?</p>

### 입력 

 <p>U prvom retku su prirodni brojevi $n$ i $m$ ($2 ≤ n ≤ 100\,000$, $1 ≤ m ≤ \min(200\,000, \frac{n \cdot (n-1)}{2})$), broj stabala u parku i broj puteljaka između njih.</p>

<p>Slijedi $m$ redaka po tri prirodna broja $a_i$, $b_i$ i $c_i$ ($1 ≤ a_i , b_i ≤ n$, $a_i \ne b_i$, $1 ≤ c_i ≤ 1\,000$), a koji označavaju da $i$-ti puteljak spaja stabla $a_i$ i $b_i$, a za njegovo označavanje potrebno je $c_i$ kamenčića.</p>

<p>U sljedećem retku je cijeli broj $q$ ($1 ≤ q ≤ 100\,000$), broj nesigurnih vjeverica.</p>

<p>Slijedi $q$ redaka po dva prirodna broja $x_i$ i $d_i$ ($1 ≤ x_i ≤ m$, $1 ≤ d_i ≤ 1\,000$), brojevi u izjavi $i$-te vjeverice ($x_i$ je redni broj puteljka u ulaznim podacima).</p>

<p>Ulazni podaci će biti takvi da će sva stabla biti povezana, a između svakog para stabala biti će najviše jedan puteljak.</p>

### 출력 

 <p>Ispišite $n$ redaka. U prvom retku ispišite traženi broj kamenčića prije izjava. U $i + 1$-tom retku ispišite traženi broj kada je jedino izjava $i$-te vjeverice istinita.</p>

