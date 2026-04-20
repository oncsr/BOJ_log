# [23364. Almost Always](https://www.acmicpc.net/problem/23364)

## 문제
Today, your probability theory class covered probabilistic events that occur 
with high probability
. As you are now explaining to your friend, this means that as some parameter $n$ goes to infinity, the probability of this event goes to $1$.


An example of an event that occurs with high probability is the following: given a list of $n$ independent uniform random integers between $1$ and $2\cdot 10^9$, there are two elements such that one divides the other.


Your friend does not believe this, as he can easily come up with many examples where no number divides any other number: Just take any subset of $\{10^9+1, 10^{9}+2, \dots, 2\cdot 10^9\}$ and none of these will divide any other!


To convince your friend, you will show him that you can find two elements that divide each other for exactly $100$ instances of the problem. You are confident this will succeed, since the probability of failure is in fact less than $10^{-25}$ per instance when $n=5\cdot 10^5$.

## 예제 입력 1
```
10
4 9 8 10 5 28 3 62 9 17
```

## 예제 출력 1
```
5 4
```

## 예제 입력 2
```
10
7 48 17 43 97 26 85 10 26 9
```

## 예제 출력 2
```
3 7
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 15632 KB | 168 ms | 267 B | 2년 전 |
