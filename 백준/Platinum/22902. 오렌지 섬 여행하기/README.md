# [Platinum I] 오렌지 섬 여행하기 - 22902 

[문제 링크](https://www.acmicpc.net/problem/22902) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

해 구성하기, 그리디 알고리즘, 수학, 정수론

### 문제 설명

<p>브루는 오렌지 섬으로 여행을 떠났다. 오렌지 섬에는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 오렌지 나무가 서 있고, 이들은 각각 1번부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>번까지의 번호가 붙어 있다.</p>

<p>브루는 섬의 1번 오렌지 나무에게 오렌지 섬의 역사에 관해 물었다. 1번 오렌지 나무는 아래와 같이 오렌지 섬의 역사를 읊어 주었다.</p>

<blockquote>
<p><em>"태초에, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> 그루의 오렌지 나무는 오렌지를 하나도 가지고 있지 않았단다.</em></p>

<p><em>어느 날, 모든 나무들은 서로 한 번씩 악수를 했지. 악수를 한 두 나무의 번호가 <strong>서로소</strong>였을 때, 두 나무는 <strong>좋은 관계</strong>를 형성하고 더 큰 번호의 나무에 오렌지가 하나 자랐어.</em></p>

<p><em>악수가 모두 끝난 뒤, 오렌지를 가지지 못한 1번 오렌지 나무에도 오렌지가 하나 자랐단다."</em></p>

<p style="text-align: right;"><em>- 1번 오렌지 나무</em></p>
</blockquote>

<p>예를 들어, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c34"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>=</mo><mn>4</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N=4$</span></mjx-container>일 경우에는, 1번, 2번 나무는 오렌지를 각각 하나씩 가지고 있고, 3번, 4번 나무는 오렌지를 각각 두 개씩 가지고 있게 된다.</p>

<p>브루는 오렌지 섬의 모든 오렌지를 따 먹으려고 한다. 구체적으로, 브루는 아래와 같은 과정을 통해 오렌지를 먹게 된다.</p>

<ol>
	<li>아무 나무로 이동해 오렌지를 정확히 하나 따 먹는다.</li>
	<li>그 후, 현재 위치한 나무와 <strong>좋은 관계</strong>인 나무로 이동해 오렌지를 정확히 하나 따 먹는다.</li>
	<li>오렌지를 모두 먹을 때까지 2번 과정을 반복한다.</li>
</ol>

<p>브루가 오렌지를 모두 먹을 수 있는지 판별하고, 먹을 수 있는 경우 오렌지를 먹는 순서를 아무거나 하나 출력하는 프로그램을 작성하자.</p>

### 입력 

 <p>첫째 줄에는 오렌지 섬에 있는 나무의 수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다.</p>

### 출력 

 <p>만약 브루가 모든 오렌지를 따 먹는 것이 가능하다면, 브루가 오렌지를 먹는 순서대로 오렌지 나무의 번호를 출력 예시와 같은 형식으로 출력한다.</p>

<p>만약 브루가 모든 오렌지를 따 먹는 것이 불가능하다면, <code>-1</code>을 출력한다.</p>

