# [32477. Alien Attack 2](https://www.acmicpc.net/problem/32477)

## 문제
Aliens are visiting Earth and, as usual, they plan to abduct humans for their experiments. In the past, alien abductions have caused a lot of press coverage and wild speculation on Earth. Luckily for them, most people do not believe these stories and think that aliens are not real.


In order to keep a low profile in the future, the Galactic Committee for Person Captures (GCPC) has established rules for abductions. Besides a lot of boring paperwork, the aliens have to prepare the abduction carefully. While they can make multiple trips (in fact, alien travel is so fast in practice that this is not a limitation at all), they must be smart about it so that their secret is not revealed to humans. If aliens want to abduct a person, they are required to abduct all of their friends at the same time, so that no one notices that their friend is missing when they want to hang out. Of course, friendships on planet Earth are bidirectional, that is if Alice is a friend of Bob, then Bob is also a friend of Alice.


In preparation for the trip, the aliens have observed their targets and started taking note of all their friendships. In total, they must abduct $n$ people, including their friends. Now, they want to book a starship at their local dealership and wonder how much space they need to abduct all $n$ people. A starship's storage space is measured in terms of the number of people that can be transported simultaneously. What is the minimum storage space required to abduct all $n$ people?

## 예제 입력 1
```
5 3
1 2
2 3
4 5
```

## 예제 출력 1
```
3
```

## 예제 입력 2
```
3 0
```

## 예제 출력 2
```
1
```

## 예제 입력 3
```
8 8
1 2
2 3
3 4
1 4
1 5
2 6
3 7
4 8
```

## 예제 출력 3
```
8
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 2 | C++17 / 수정 | 14116 KB | 92 ms | 575 B | 1년 전 |
