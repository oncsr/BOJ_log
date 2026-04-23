# [26205. Eliminating Ballons](https://www.acmicpc.net/problem/26205)

## 문제
An enourmous number of balloons are floating about in the Convention Hall after the Awarding Ceremony of the ICPC Subregional Contest. The manager of the Convention Hall is angry, because he will host another event tomorrow and the ballons must be removed. Fortunately this year Carlinhos came prepared with his bow and arrows to pop the balloons.


Also, luckily, due to the air conditioning flow, the balloons are all in the same vertical plane (that is, a plane parallel to a wall), although in distinct heights and positions.


Carlinhos will shoot from the left side of the convention hall, at a chosen height, in the direction of the right side of the Convention Hall. Each arrow moves from left to right, at the height it was shot, in the same vertical plane of the baloons. When an arrow touches a balloon, the baloon pops and the arrow continues its movement to the right, at a height decreased by $1$. In other words, if the arrow was at height $H$, after popping a balloon it continues at height $H - 1$.


Carlinhos wants to pop all balloons shooting as few arrows as possible. Can you help him?

## 예제 입력 1
```
5
3 2 1 5 4
```

## 예제 출력 1
```
2
```

## 예제 입력 2
```
4
1 2 3 4
```

## 예제 출력 2
```
4
```

## 예제 입력 3
```
6
5 3 2 4 6 1
```

## 예제 출력 3
```
3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 5 | C++17 / 수정 | 5804 KB | 68 ms | 296 B | 3년 전 |
