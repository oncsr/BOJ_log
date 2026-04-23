# [5221. Pythogorean Triples](https://www.acmicpc.net/problem/5221)

## 문제
In pursuit of one of the Infinity Gems, rumored to be in possession of Loki, Thor and the Avengers have reached what they believe to be one of Loki’s dens. However, their attempt to infiltrate is thwarted by a locked door. The Avengers need to quickly figure out which number (key) to enter on the keypad to gain access; however, they don’t the time to try the trillions of possible combinations. Thor notices a sequence of numbers on a nearby wall. Thor knows Loki well (they are half-brothers after all), and believes that the key is a Pythogorean triple, with the numbers drawn from the sequence.


A triple {x, y, z}, x < y < z is called a Pythogorean triple if: x 2 + y 2 = z 2 . So, for example, {3,4,5} is a Pythogorean triple, while {1,2,3} is not.


Your goal is to write a computer program that helps the Avengers. More specifically, given a sequence of positive integers x1, · · · , xn, all different from each other, your goal is find all the Pythogorean triples in that sequence.


For example, given a sequence, 13, 12, 3, 4, 5, there are two Pythogorean triples in it: {3, 4, 5} and {5, 12, 13}.

## 예제 입력 1
```
4 
6 6 5 4 3 2 1 
3 3000000 5000000 4000000
5 13 12 3 4 5
6 1 2 4 8 16 32
```

## 예제 출력 1
```
Found Pythogorean triples:  {3 4 5}
Found Pythogorean triples:  {3000000 4000000 5000000}
Found Pythogorean triples:  {3 4 5} {5 12 13}
No Pythogorean triples found in the sequence.
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 4 | Java 11 / 수정 | 20548 KB | 260 ms | 2230 B | 3년 전 |
