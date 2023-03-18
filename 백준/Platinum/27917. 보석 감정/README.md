# [Platinum IV] 보석 감정 - 27917 

[문제 링크](https://www.acmicpc.net/problem/27917) 

### 성능 요약

메모리: 13812 KB, 시간: 328 ms

### 분류

문자열, 무작위화

### 문제 설명

<p>설곽국에는 예지와 의행이라는 두 명품 브랜드가 있습니다. 두 브랜드에서는 보석을 꿰어 만든 명품 목걸이를 생산합니다. 각각의 보석은 영어 소문자 중 하나에 해당하는 약칭을 가지고 있습니다.</p>

<p>두 브랜드는 모두 보석을 자체 생산한다고 주장합니다. 브루는 두 브랜드의 보석이 비슷하다는 제보를 받고 목걸이의 보석을 비교해 보기로 했습니다. 보석은 육안으로는 비교가 불가능해서, 기계를 이용해 비교해야 합니다. 기계를 한 번 사용할 때마다 두 보석이 같은지 또는 다른지를 알 수 있습니다.</p>

<p>브루에게는 예지 브랜드에서 생산한 목걸이 A와, 의행 브랜드에서 생산한 목걸이 B가 있습니다. 두 목걸이에는 각각 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 보석이 있습니다. 기계를 적은 횟수로 사용해 목걸이 A와 목걸이 B 양쪽에 모두 포함된 보석 종류가 하나라도 있는지 판별하는 프로그램을 작성하세요.</p>

### 입력 

 <p>입력의 첫 줄에는 목걸이 당 보석의 수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>과 서브태스크의 번호 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D460 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>s</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$s$</span></mjx-container>가 띄어쓰기를 사이에 두고 주어집니다. 이 두 수를 먼저 입력받아야 합니다.</p>

<p>이후 문자열 "? [X1] [Y1] [X2] [Y2]"를 출력해 기계를 이용할 수 있습니다. 각 칸에는 다음 규칙을 따라 출력합니다.</p>

<ul>
	<li>[X1]: 첫 번째 보석이 속한 목걸이의 이름. 'A' 또는 'B'여야 합니다. (따옴표 제외)</li>
	<li>[Y1]: 첫 번째 보석이 해당 목걸이에서 몇 번째 보석인지를 출력합니다.</li>
	<li>[X2]: 두 번째 보석이 속한 목걸이의 이름. 'A' 또는 'B'여야 합니다. (따옴표 제외)</li>
	<li>[Y2]: 두 번째 보석이 해당 목걸이에서 몇 번째 보석인지를 출력합니다.</li>
</ul>

<p>예를 들어, 목걸이 A의 세 번째 보석과 목걸이 B의 5번째 보석을 비교하는 경우, “? A 3 B 5”를 출력합니다.</p>

<p>출력한 뒤에는 줄을 바꾸고 표준 출력 버퍼를 플러시(<code>flush</code>)해야 합니다. 언어별로 표준 출력 버퍼를 플러시하는 방법은 다음과 같습니다.</p>

<ul>
	<li>C++
	<ul>
		<li><code>fflush(stdout);</code> (<code>printf</code>를 사용 중인 경우)</li>
		<li><code>std::cout << std::flush;</code> (<code>std::cout</code>을 사용 중인 경우)</li>
	</ul>
	</li>
	<li>Python: <code>sys.stdout.flush()</code> (코드 최상단에 <code>import sys</code>가 필요)</li>
</ul>

<p>기계를 한 번 사용한 뒤에는 정수 하나를 입력받아야 합니다. 해당 정수가 1인 경우 두 보석의 종류가 같고, 0인 경우 두 보석의 종류가 다름을 의미합니다.</p>

<p>만약 답을 알아낸 경우, 다음 지시에 따라 행동하세요.</p>

<ul>
	<li>두 목걸이에 같은 종류의 보석이 하나라도 있는 경우, "! 1"을 출력합니다.</li>
	<li>두 목걸이에 같은 종류의 보석이 하나도 없는 경우, "! 0"을 출력합니다.</li>
</ul>

<p>답을 출력한 이후 프로그램은 즉시 종료되어야 합니다.</p>

### 출력 

 Empty

