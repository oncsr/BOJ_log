# [Diamond IV] 겨울 숲의 썰매 트랙 - 26220 

[문제 링크](https://www.acmicpc.net/problem/26220) 

### 성능 요약

메모리: 4912 KB, 시간: 4 ms

### 분류

애드 혹(ad_hoc), 구성적(constructive)

### 문제 설명

<p>당신은 겨울 숲에 썰매 트랙을 만들고 있다. 썰매 트랙은 크기 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>×</mo><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N \times N$</span></mjx-container>의 격자 영역 내에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>×</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \times 1$</span></mjx-container> 크기의 다음 두 가지 타일을 놓아 만들 수 있으며, 각각 길이 없는 타일과 길이 있는 타일을 나타낸다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/173d40e9-95cc-40d7-a812-d36d9cc7aeb5/-/preview/" style="width: 227px; height: 118px;"></p>

<p>썰매 트랙의 규칙은 다음과 같다.</p>

<ol>
	<li>하나의 썰매 트랙은 길이 있는 타일들로만 구성된다.</li>
	<li>타일은 회전해서 놓을 수 있다.</li>
	<li>타일의 길은 인접한 다른 타일의 길과 이어져 있어야 한다. 격자판 밖으로 길이 나가거나 길이 끊기면 안 된다.</li>
</ol>

<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>3</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$3$</span></mjx-container> 이상의 홀수일 경우 조건을 만족하는 썰매 트랙은 항상 존재한다.</p>

<p>썰매 트랙의 타일 중 하나를 시작 타일로 정했을 때, 썰매 트랙의 길이를 시작 타일에서 트랙의 길을 따라서 시작 타일로 돌아오기까지 방문한 서로 다른 타일의 수라고 하자.</p>

<p>가장 긴 썰매 트랙을 만들려면 어떻게 해야 할까?</p>

### 입력 

 <p>첫째 줄에 영역의 크기를 나타내는 홀수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c39"></mjx-c><mjx-c class="mjx-c39"></mjx-c><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>3</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>999</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$3 \leq N \leq 999$</span></mjx-container>)이 주어진다.</p>

### 출력 

 <p>가장 긴 썰매 트랙에 대해서 그 트랙의 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container>를 출력한다.</p>

<p>다음 줄에는 시작 타일의 좌표가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45F TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>r</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$r$</span></mjx-container>행 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D450 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>c</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$c$</span></mjx-container>열일때 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45F TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>r</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$r$</span></mjx-container>과 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D450 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>c</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$c$</span></mjx-container>를 출력한다. 가능한 시작 타일이 여러 개일 경우 그 중 아무거나 출력한다. 좌표는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>부터 시작한다.</p>

<p>그 다음 줄에는 선택한 시작 타일에서부터 트랙의 길을 따라서 그 타일으로 돌아오기까지의 이동 방향을 알파벳 대문자로 출력한다. 가로로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container> 이동은 <code>R</code>, 가로로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>−</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$-1$</span></mjx-container> 이동은 <code>L</code>, 세로로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container> 이동은 <code>D</code>, 세로로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>−</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$-1$</span></mjx-container> 이동은 <code>U</code>로 출력한다.</p>

<p>가능한 트랙이 여러 가지일 경우 그 중 아무거나 출력한다.</p>

