# [11313. Best Buddies](https://www.acmicpc.net/problem/11313)

## 문제
You have signed up for the annual Calgary Collegiate Programming Contest. Unlike previous years, participants are not choosing their own team members, but are assigned to teams as follows. Consider we list all participants in alphabetic order. Then Team 1 consists of the first three participants in this order. Team 2 consists of the next three participants in this order. Assume that the number N of participants is divisible by 3 so that every team has exactly 3 team members.


Assume that every participant has exactly one first name and exactly one last name, the name is spelled over the alphabet {a, . . . , z}, and that no two participants carry the exact same name. The alphabetic order we choose, is to first sort in lexicographically ascending order with respect to last names, and then, when necessary, with respect to first names. So john smith is alphabetized after carla smith, but before bob taylor.


Given the name of a participant, output the names of the participant’s two team mates.

## 예제 입력 1
```
12
john smith
carla smith
bob taylor
alice watson
sarah taylor
ryan singh
jessica li
kevin wright
charles lee
megan davies
ryan davies
julia leung
3
ryan davies
sarah taylor
kevin wright
```

## 예제 출력 1
```
megan davies
charles lee
alice watson
kevin wright
sarah taylor
alice watson
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 2 | C++17 / 수정 | 20312 KB | 264 ms | 585 B | 1년 전 |
