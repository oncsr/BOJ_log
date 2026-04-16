# [13215. Fish](https://www.acmicpc.net/problem/13215)

## 문제
Kuching the Cat enjoys eating fish. However, he accidently bought a large fish and does not want to eat all of it. To solve his problem, he has subdivided the fish into N linear segments (head to tail) and has given each segment a ‘satisfaction rating’. These segments are labelled 1 to N. The higher the satisfaction rating, the more Kuching will enjoy eating this segment of the fish. However, fish only taste nice if eaten as a chunk. One chunk consists of multiple linear segments of fish that are contiguous/consecutive.


Kuching is very picky and will not enjoy a chunk of fish where the sum of satisfaction ratings is less than K (i.e. he wants the sum to be ≥ K). He wonders how many ways are there to cut a single chunk out of the fish such that he would enjoy eating. Those segments not part of the chunk will be thrown and not eaten


*To clarify: a chunk must contain at least 1 linear segment of fish and can only contain up to N segments in total (i.e. the entire fish)

## 예제 입력 1
```
5 2
1 -2 3 -4 5
```

## 예제 출력 1
```
6
```

## 예제 입력 2
```
5 -2
1 -2 3 -4 5
```

## 예제 출력 2
```
13
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 4 | C++17 / 수정 | 17692 KB | 164 ms | 724 B | 1년 전 |
