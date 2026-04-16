# [8201. Pilots](https://www.acmicpc.net/problem/8201)

## 문제
In the Byteotian Training Centre, the pilots prepare for missions requiring extraordinary precision and control. One measure of a pilot's capability is the duration he is able to fly along a desired route without deviating too much - simply put, whether he can fly steadily. This is not an easy task, as the simulator is so sensitive that it registers even a slightest move of the yoke
1
. At each moment the simulator stores a single parameter describing the yoke's position. Before each training session a certain tolerance level t is set. The pilots' task then is to fly as long as they can in such a way that all the yoke's position measured during the flight differ by at most t. In other words, a fragment of the flight starting at time i and ending at time j is within tolerance level t if the position measurements, starting with i-th and ending with j-th, form such a sequence a
i
,…,a
j
  that for all elements a
k
,a
l
 of this sequence, the inequality |a
k
-a
l
| ≤ t holds.


Your task is to write a program that, given a number and the sequence of yoke's position measurements, determines the length of the longest fragment of the flight that is within the tolerance level t.


1
a device used for piloting in an aircraft

## 예제 입력 1
```
3 9
5 1 3 5 8 6 6 9 10
```

## 예제 출력 1
```
4
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 4 | C++17 / 수정 | 51676 KB | 452 ms | 664 B | 6달 전 |
