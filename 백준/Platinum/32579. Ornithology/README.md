# [32579. Ornithology](https://www.acmicpc.net/problem/32579)

## 문제
On the outskirts of the town, close to the farm, there stand two parallel power lines, separated by a narrow dirt road. The power lines were a favorite resting spot for a variety of birds.


Today, on this cool autumn morning, the lines are filled with a group of birds. On the first line there are $n$ consecutive positions for birds numbered $0, 1, \dots , n - 1$. On the second power line there are also $n$ positions numbered in the same manner.


Initially, every position of the first line is occupied by some birds (possibly zero) and there are no birds on the second power line. Each bird has its desired position to fly to on the second line. No two birds on the same position on the first line share the same desired position.


At one moment, all the birds at once will decide to fly to their desired positions. Every bird flies along the straight line segment connecting its initial and desired position.


It can happen that some pairs of birds crash into each other during their flight. This can happen when their corresponding line segments cross. We shall call such unordered pair of birds 
dangerous
 pair.


For example, if a bird on position $2$ wants to go to position $1$ and the bird on position 1 wants to go to position $2$, their paths cross.


The birds will not collide if their paths have the same desired position (on the second line) or if they start from the same position (on the first line). In other words a pair of birds with the same initial or desired positions is not considered a dangerous pair.


The task is very simple. Compute the number of dangerous pairs of birds.

## 예제 입력 1
```
3
2 1 2
1 0
1 1
```

## 예제 출력 1
```
3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | C++17 / 수정 | 5736 KB | 100 ms | 727 B | 1년 전 |
