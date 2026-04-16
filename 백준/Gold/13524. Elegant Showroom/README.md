# [13524. Elegant Showroom](https://www.acmicpc.net/problem/13524)

## 문제
A car showroom is one of the few places where cars can be found indoors. Showrooms often have many cars, even above ground level! As cars are sold and new cars are bought in to sell, the cars must be moved carefully out of the showroom.


Clearly employees only wish to move cars if they have to. So, given a map of a showroom including its walls, doors and where the cars are, and the co-ordinates of the car to move, how many cars must be moved?


Cars can be rotated on the spot, but can only be moved through a completely empty space and not diagonally. Doors are always wide enough to move a car through.

## 예제 입력 1
```
4 5
#####
#cDc#
#c#cD
#####
3 2
```

## 예제 출력 1
```
4
```

## 예제 입력 2
```
10 10
##########
#cc#ccccc#
#cc#cccccD
#cccccccc#
########c#
#cccccccc#
###cccccc#
#c#cccccc#
#cccccccc#
##########
2 2
```

## 예제 출력 2
```
11
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | C++17 / 수정 | 2864 KB | 16 ms | 940 B | 1년 전 |
