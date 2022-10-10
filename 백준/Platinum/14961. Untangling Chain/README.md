# [Platinum V] Untangling Chain - 14961 

[문제 링크](https://www.acmicpc.net/problem/14961) 

### 성능 요약

메모리: 2020 KB, 시간: 4 ms

### 분류

구성적(constructive)

### 문제 설명

<p>A rectilinear chain is an ordered sequence that alternates horizontal and vertical segments as in Figure K.1. You are given a rectilinear chain whose first segment starts from the origin (0,0) and goes to the right. Such a rectilinear chain of <em>n</em> edges can be described as a sequence of <em>n</em> pairs (<em>l<sub>k</sub></em>,<em>t<sub>k</sub></em>) where <em>l<sub>k</sub></em> is the length of the <em>k</em>-th edge <em>e<sub>k</sub></em> and <em>t<sub>k</sub></em> denotes the turning direction from the <em>k</em>-th edge <em>e<sub>k</sub></em> to the (<em>k</em>+1)-st edge <em>e<sub>k</sub></em><sub>+1</sub>. For 1 ≤ <em>k</em> < <em>n</em>, if the chain turns left from <em>e<sub>k</sub></em> to <em>e<sub>k</sub></em><sub>+1</sub>, then <em>t<sub>k</sub></em> = 1, and if it turns right, then <em>t<sub>k</sub></em> = -1. For <em>k</em> = <em>n</em>, <em>t<sub>k</sub></em> is set to be zero to indicate that <em>e<sub>k</sub></em> is the last edge of the chain. For example, a rectilinear chain of six pairs shown in Figure 1(a) is described as a sequence of six pairs (4, 1), (5, -1), (2, -1), (2, -1), (4, 1), (5, 0).</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14961/1.png" style="height:275px; width:540px"></p>

<p style="text-align:center">Figure K.1. (a) A non-simple chain. (b) An untangled simple chain</p>

<p>You would already notice that the rectilinear chain drawn by the given description is not simple. A chain is <em>simple</em> if any two edges in the chain have no intersection except at the end points shared by adjacent edges. To represent the chain in a more succinct way, you want to make it simple if it is not simple. In other words, you need to untangle a given rectilinear chain to a simple chain by modifying the length of its edges. But the length of each edge in the resulting chain must be at least 1 and at most <em>n</em>, and the turning directions must be kept unchanged. The chain shown in Figure K.1(b) shows one of possible modifications for the non-simple chain given in Figure K.1(a), and its description is (4, 1), (5, -1), (2, -1), (2, -1), (1, 1), (2, 0).</p>

<p>Given a description of a rectilinear chain, you should write a program to untangle the rectilinear chain.</p>

### 입력 

 <p>Your program is to read from standard input. The first line contains an integer, <em>n</em> (1 ≤ <em>n</em> ≤ 10,000), representing the number of edges of an input rectilinear chain. In the following <em>n</em> lines, the <em>k</em>-th line contains two integers <em>l<sub>k</sub></em> and <em>t<sub>k</sub></em> for the edge <em>e<sub>k</sub></em>, separated by a single space, where <em>l<sub>k</sub></em> (1 ≤ <em>l<sub>k</sub></em> ≤ 10,000) is the length of <em>e<sub>k</sub></em>, and <em>t<sub>k</sub></em> is the turning direction from <em>e<sub>k</sub></em> to <em>e<sub>k</sub></em><sub>+1</sub>; <em>t<sub>k</sub></em> =  1 if it is the left turn and <em>t<sub>k</sub></em> = -1 if it is the right turn for 1 ≤ <em>k</em> < <em>n</em>, and <em>t<sub>k</sub></em> = 0 for <em>k</em> = <em>n</em>.</p>

### 출력 

 <p>Your program is to write to standard output. The first line should contain <em>n</em> positive integers, representing the length of the edges of your untangled simple chain according to the edge order of the input chain. Each length should be at least 1 and at most <em>n</em>. Note that you do not need to output the turning directions because the turning directions of the simple chain is identical to the ones of the input chain. You can assume that any rectilinear chain described in the input can be untangled with the edge length condition.</p>

