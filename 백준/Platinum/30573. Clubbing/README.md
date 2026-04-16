# [30573. Clubbing](https://www.acmicpc.net/problem/30573)

## 문제
Students of Tomorrow Programming School engage in different school programming clubs. Each student is a member of some number of clubs. The clubs are supervised by the Principal Club Coach (PCC). His main occupation is to talk to club members to help them organize their activities. PCC has a fixed schedule in the form of a list of students he is going to talk to in the nearest future. He always talks to only one student at a time, he may talk to a student repeatedly at various times. Each talk takes short time interval, which is always the same. There is negligible time between subsequent talks.


Currently, the school director also needs to talk to some students in the presence of PCC, because he needs to start another state supported programming project. He is going to visit PCC’s cabinet and spend some uninterrupted time there. In that time, he wants to talk to all members of at least one club. Thus, PCC defined a so-called director interval in his schedule. It is an uninterrupted sequence of his talks to students, in which all members of at least one club appear at least once.


Before he suggests an acceptable director interval, PCC at least wants to know the number of such intervals in his schedule.

## 예제 입력 1
```
2
pid
lid
lidp
```

## 예제 출력 1
```
3
```

## 예제 입력 2
```
2
baf
lek
affleck
```

## 예제 출력 2
```
4
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | C++17 / 수정 | 2536 KB | 16 ms | 875 B | 3달 전 |
