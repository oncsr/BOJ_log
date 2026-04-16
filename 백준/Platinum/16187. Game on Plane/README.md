# [16187. Game on Plane](https://www.acmicpc.net/problem/16187)

## 문제
You are given $N$ points on a plane. These points are precisely the set of vertices of some regular $N$-gon. Koosaga, an extreme villain, is challenging you with a game using these points. You and Koosaga alternatively take turns, and in each turn, the player




chooses two of the given points, then


draws the line segment connecting the two chosen points.




Also, the newly drawn line segment must not intersect with any of the previously drawn line segments in the interior. It is possible for two segments to meet at their endpoints. If at any point of the game, there exists a convex polygon consisting of the drawn line segments, the game ends and the last player who made the move wins.


Given the integer $N$, Koosaga is letting you decide who will move first. Your task is decide whether you need to move first or the second so that you can win regardless of Koosaga's moves.

## 예제 입력 1
```
2
3
5
```

## 예제 출력 1
```
First
Second
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 3 | C++17 / 수정 | 2040 KB | 12 ms | 340 B | 6달 전 |
