# [3505. Kingdom Roadmap](https://www.acmicpc.net/problem/3505)

## 문제
The Kingdom consists of n cities connected by n − 1 roads in such a way that there is exactly one way to travel from one city to another.


The King is a busy man and he constantly travels from city to city. Unfortunately, during one of his travels one of the roads got damaged and needed serious repairs. As a result, the King was unable to reach his destination in time.


After the incident the King decided to improve reliability of the road system. It was decided that the improved road system shall be able to withstand one damaged road, i.e. there shall always be a path from one city to another even when one road in the Kingdom is damaged. As always, the budget is limited so you need to minimize the number of new roads.


For example, the picture below shows 5 Kingdom’s cities numbered from 1 to 5 and roads between them in solid lines. One of the ways to build new roads is shown in dashed lines.




Your task is to build as few new roads as possible so that there is always a path between any two cities even if one of the roads gets unusable for any reason. There may be multiple optimal solutions. Any one can be used.

## 예제 입력 1
```
5
1 2
2 3
3 4
3 5
```

## 예제 출력 1
```
2
1 4
4 5
```

## 예제 입력 2
```
4
1 2
1 3
1 4
```

## 예제 출력 2
```
2
3 2
1 4
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 2 | C++17 / 수정 | 13656 KB | 44 ms | 585 B | 2년 전 |
