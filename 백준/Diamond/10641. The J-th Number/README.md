# 10641 - The J-th Number

[문제 링크](https://www.acmicpc.net/problem/10641)

| 난이도 | 시간 제한 | 메모리 제한 |
|--------|----------|------------|
| Diamond 3 | 10 초 | 512 MB |

## 알고리즘 분류
- 자료 구조
- 세그먼트 트리
- 이분 탐색
- 느리게 갱신되는 세그먼트 트리
- 값 / 좌표 압축
- 병렬 이분 탐색

## 제출 결과
| 메모리 | 시간 | 언어 | 코드 길이 | 제출 일자 |
|--------|------|------|----------|----------|
| 408744 KB | 6588 ms | Java 15 | 5427 B | 2026년 4월 5일 08:07:04 |

## 문제 설명
You are given N empty arrays, t<sub>1</sub>,…,t<sub>n</sub>. At first, you execute M queries as follows.

- add a value v to array t<sub>i</sub> (a ≤ i ≤ b)

Next, you process Q following output queries.

- output the j-th number of the sequence sorted all values in t<sub>i</sub> (x ≤ i ≤ y)

## 입력
The dataset is formatted as follows.

```

N M Q
a1 b1 v1
...
aM bM vM
x1 y1 j1
...
xQ yQ jQ

```

The first line contains three integers N (1 ≤ N ≤ 10<sup>9</sup>), M (1 ≤ M ≤ 10<sup>5</sup>) and Q (1 ≤ Q ≤ 10<sup>5</sup>). Each of the following M lines consists of three integers a<sub>i</sub>, b<sub>i</sub> and v<sub>i</sub> (1 ≤ a<sub>i</sub> ≤ b<sub>i</sub> ≤ N, 1 ≤ v<sub>i</sub> ≤ 10<sup>9</sup>). Finally the following Q lines give the list of output queries, each of these lines consists of three integers x<sub>i</sub>, y<sub>i</sub> and j<sub>i</sub> (1 ≤ x<sub>i</sub> ≤ y<sub>i</sub> ≤ N,1≤ j<sub>i</sub> ≤ Σ<sub>xi≤k≤yi</sub>|tk|).

## 출력
For each output query, print in a line the j-th number.
