# [11449. Icelandic Motorclubs](https://www.acmicpc.net/problem/11449)

## 문제
The country of Iceland has a huge number of beautiful sights, including waterfalls, lava fields, cliffs, geysirs, valleys, volcanoes, glaciers, whales, seals, sheep and much more. Recently, the country has attracted the attention of motor clubs. Expelled from their home countries as a result of revealing reality TV programs, they now seek to bike elsewhere. Members of motor clubs have a lot of money (how else would they be able to pay for all those fancy motor bikes), and thus also own private planes that can drop them with a parachute together with their motor cycle anywhere they want.


The country of Iceland has many rough roads that are not suitable for motor driving, but luckily Iceland has one accessible paved ring road (Road 1) that makes a circle, passing by all the beautiful sights an adventurous motor driver may be interested in. However, Iceland is sparsely populated, and there are not so many gas stations. In fact, in rough winter times, there are barely enough gas stations supplied with gas to make a full round trip with one motor cycle. In the winter, only the inner clockwise lane (Iceland drives right) is free of snow.


Nevertheless, a biker is brave and will try to make a round trip. Luckily, bikers know how much gas is at each gas station and know the distance between each subsequent pair of gas stations on the ring road of Iceland. Also, bikers do not have to worry about the size of the gas tank on the motor bike: it is assumed to be of infinite size. Also, filled gas tanks collapse under air pressure, so the biker jumps out of the plane with an empty tank.


Given the distance between each subsequent pair of gas stations and the amount of gas available at each gas station, at which gas station should the biker start in order to complete a full clockwise circle without running out of gas? Assume that motor bikes are not the most eco-friendly vehicles: they use one liter of gas to drive one mile.

## 예제 입력 1
```
2
5
1 2
3 2
3 4
3 1
0 1
3
3 4
2 3
4 3
```

## 예제 출력 1
```
2
IMPOSSIBLE
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | C++17 / 수정 | 2020 KB | 276 ms | 357 B | 2년 전 |
