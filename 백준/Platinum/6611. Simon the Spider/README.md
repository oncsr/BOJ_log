# [6611. Simon the Spider](https://www.acmicpc.net/problem/6611)

## 문제
In the problem 6609, you have seen that the potential reproductive capabilities of insects are very high. Fortunately for us humans, the insects also have natural enemies that help to reduce their population. Spiders belong among the best known insect predators, so there is no wonder we included them in this problem set.


Simon the Spider ate many insects this summer and got fat. The threads of his web will soon be too thin to carry him and so he needs to reinforce them. Since fat spiders are also lazy, Simon wants to use as little material as possible — well, you know that spiders have to produce the material for building webs by themselves. Finally, he decided to reinforce only some of the threads, but it is important that every node of his web must be reachable over the reinforced links.


Additionally, Simon plans to spend his free time on one of the reinforced links and he wants this one link to be long. Therefore, when calculating the total length of all reinforced links, the length of the longest reinforced link will be subtracted instead of added. Help Simon to decide which links should be reinforced to have the lowest possible total length under these circumstances.

## 예제 입력 1
```
3 1
1 2 5
4 5
1 2 5
2 3 6
3 4 8
3 4 4
1 4 2
```

## 예제 출력 1
```
disconnected
-1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 4 | C++17 / 수정 | 28164 KB | 872 ms | 3876 B | 2년 전 |
