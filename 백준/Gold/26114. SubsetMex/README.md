# [Gold IV] SubsetMex - 26114 

[문제 링크](https://www.acmicpc.net/problem/26114) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

그리디 알고리즘

### 제출 일자

2024년 8월 26일 18:32:18

### 문제 설명

<p>A multiset is a collection of elements similar to a set, where elements can repeat multiple times. For example, the following is a multiset:</p>

<p>{0, 0, 1, 2, 2, 5, 5, 5, 8}</p>

<p>Given a multiset S defined on non-negative integers, and a target non-negative integer value n such that n does not belong to S, your goal is to insert n into S by using the following 3-step operation, repeatedly:</p>

<ol>
	<li>Choose a (possibly empty) subset T of S. Here, T is a set of distinct numbers that appear in S.</li>
	<li>Erase elements of T from S. (Remove only one copy of each element.)</li>
	<li>Insert mex(T) into S, where mex(T) is the smallest non-negative integer that does not belong to T. The name mex stands for “minimum excluded” value.</li>
</ol>

<p>Your goal is to find the minimum number of operations to perform so that n becomes part of S.</p>

<p>Since the size of S may be large, it will be given in the form of a list (f<sub>0</sub>, …, f<sub>n−1</sub>) of size n, where fi represents the number of times that the number i appears in S. (Recall that n is the integer we are trying to insert into S.)</p>

### 입력 

 <p>The first line contains a single integer t (1 ≤ t ≤ 200) — the number of test cases. Each two of the following lines describe a test case:</p>

<ul>
	<li>The first line of each test case contains a single integer n (1 ≤ n ≤ 50), representing the integer to be inserted into S.</li>
	<li>The second line of each test case contains n integers f<sub>0</sub>, f<sub>1</sub>, …, f<sub>n−1</sub> (0 ≤ f<sub>i</sub> ≤ 10<sup>16</sup>), representing the multiset S as mentioned above.</li>
</ul>

### 출력 

 <p>For each test case, print a single line containing the minimum number of operations needed to satisfy the condition.</p>

