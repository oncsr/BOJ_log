# [15403. Escape Room](https://www.acmicpc.net/problem/15403)

## 문제
As you know, escape rooms became very popular since they allow you to play the role of a video game hero. One such room has the following quiz. You know that the locker password is a permutation of N numbers. A permutation of length N is a sequence of distinct positive integers, whose values are at most N. You got the following hint regarding the password - the length of the longest increasing subsequence starting at position i equals A
i
. Therefore you want to find the password using these values. As there can be several possible permutations you want to find the lexicographically smallest one. Permutation P is lexicographically smaller than permutation Q if there is an index i such that P
i
 < Q
i
 and P
j
 = Q
j
 for all j < i. It is guaranteed that there is at least one possible permutation satisfying the above constraints. Can you open the door?

## 예제 입력 1
```
4
1 2 2 1
```

## 예제 출력 1
```
4 2 1 3
```

## 예제 입력 2
```
1
1
```

## 예제 출력 2
```
1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | C++17 / 수정 | 5748 KB | 24 ms | 494 B | 2년 전 |
