# [Gold IV] Wordle 찍기 - 26147 

[문제 링크](https://www.acmicpc.net/problem/26147) 

### 성능 요약

메모리: 2488 KB, 시간: 44 ms

### 분류

애드 혹(ad_hoc), 구성적(constructive), 구현(implementation)

### 문제 설명

<p>영민이는 최근 Wordle이라는 게임에 빠졌다.</p>

<p>Wordle은 숫자 야구와 비슷한 방식으로 진행되며, 컴퓨터가 미리 지정해둔 5글자의 영어 단어를 맞히는 게 목표이다. 컴퓨터가 지정한 이 단어를 편의상 정답 단어라고 하자.</p>

<p>플레이어는 5글자의 단어를 입력하는 방식으로 정답을 추측할 수 있으며, 컴퓨터는 그 추측이 얼마나 맞는지 아래와 같은 방식으로 알려준다.</p>

<ul>
	<li>만약 플레이어가 글자와 그 글자의 위치를 모두 맞췄다면, 그 글자를 초록색으로 칠한다.</li>
	<li>만약 플레이어가 글자는 맞췄지만 그 글자의 위치는 틀렸다면, 그 글자를 노란색으로 칠한다.</li>
	<li>만약 플레이어가 글자를 틀렸다면, 그 글자는 회색으로 칠한다.</li>
</ul>

<p>예를 들면, 아래는 정답 단어가 READY일 때, 플레이어의 추측과 이에 대한 결과를 보여준다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/96ce2978-451c-459f-88b5-87efa4541ac1/-/preview/" style="width: 250px; height: 213px;"></p>

<p>하지만 영어 단어에는 중복된 글자가 있을 수 있기 때문에, 실제 Wordle에서는 아래와 같은 방식으로 글자를 칠한다.</p>

<ul>
	<li>만약 플레이어가 추측한 단어의 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>i</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$ i $</span></mjx-container>번째 글자가 정답 단어의 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>i</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$ i $</span></mjx-container>번째 글자와 동일하다면, 그 글자를 초록색으로 칠한다.</li>
	<li>위에서 매치되지 않은 글자들 중, 플레이어가 추측한 단어와 정답 단어에 동시에 등장하는 글자들끼리 <strong>앞에서부터 일대일로</strong> 매칭시킨다. 이때 매칭된 글자들은 노란색으로 칠한다</li>
	<li>위 과정에서 칠해지지 않은 글자들은 회색으로 칠한다.</li>
</ul>

<p>예를 들면, 아래는 정답 단어가 SPEED일 때, 플레이어의 추측과 이에 대한 결과를 보여준다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/8abfb405-a5d5-41ef-970b-e03cfdf989f7/-/preview/" style="height: 254px; width: 500px;"></p>

<p>영민이는 Wordle을 플레이하다보니, 각 단어가 색칠된 정보만을 알고 있을 때 정답 단어를 알아차릴 수 있을지 궁금해졌다.</p>

<p>실제로는 사전에 존재하는 5글자 영어 단어만을 입력할 수 있지만, 이 문제에서는 편의상 영어 대문자로 이루어진 5글자 문자열을 모두 입력할 수 있다고 생각하자.</p>

### 입력 

 <p>첫째 줄에는 판정 결과의 수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$ N $</span></mjx-container>이 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>100</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$( 1 \le N \le 100\,000 )$</span> </mjx-container></p>

<p>이어 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$ N $</span></mjx-container>개의 줄에 걸쳐 각 단어의 판정 결과가 주어진다. 초록색은 'G', 노란색은 'Y', 회색은 'B'로 주어진다.</p>

### 출력 

 <p>만약 입력으로 주어진 상태가 실제로는 불가능한 상태라면 IMPOSSIBLE을 출력한다.</p>

<p>그렇지 않다면, 첫째 줄에는 정답 단어를 출력한 뒤, 다음 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$ N $</span></mjx-container>개의 줄에 걸쳐 실제 가능한 경우 중 하나를 출력한다.</p>

<p>가능한 답이 여러가지라면, 그 중 아무거나 하나 출력한다.</p>

