# [35224. Instagraph](https://www.acmicpc.net/problem/35224)

## 문제
A celebrity in a social network is somebody with many followers, but who doesn't follow them back. More precisely, a person is a 
celebrity
 for a group of people, if




every member of the group follows the person,


the person follows nobody in the group.




The 
celebrity centrality
 of person $v$, written $\mathrm{CC}(v)$, is the maximum size of such a group.


We model the social network as a directed graph with $N$ vertices  $1$,  $\ldots$, $N$. A directed edge from $u$ to $v$ means that person $u$ follows person $v$. For example, in




we have $\operatorname{CC}(1) = 0$, $\operatorname{CC}(2) = 1$, and $\operatorname{CC}(5) = 2$.


Your task is to find a vertex $v$ with the maximum celebrity centrality $\mathrm{CC}(v)$. In case of a tie, choose the smallest $v$.

## 예제 입력 1
```
6 8
1 2
2 1
2 3
3 2
3 6
4 5
5 2
6 5
```

## 예제 출력 1
```
5 2
```

## 예제 입력 2
```
1 0
```

## 예제 출력 2
```
1 0
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | C++17 / 수정 | 58392 KB | 392 ms | 490 B | 2달 전 |
