# [17532. Denouncing Mafia](https://www.acmicpc.net/problem/17532)

## 문제
Nlogonia police department is investigating the local mafia. They already know all the members and the structure of the organization: The Nlogonian mafia has N members, and each is identified by an integer between 1 and N, where 1 is the number that identifies the mafia boss. In addition, every member except the boss is a direct subordinate of another member.


Even after months of investigation, police still do not have enough information to arrest any mafia members for any crime. So they decided to ask for the help of a seer: given a mafia member, the seer can magically guess the crimes he has committed, and the police can then confirm them by interrogation.


In addition, when a Nlogonian mafia member is interrogated, he not only admits his crimes, but also, in exchange for a lighter sentence, he reports the crimes of his direct superior. If the superior has not already been arrested, the police can interrogate him as well, and he will then report his superior, and so on, until they reach the boss.


Unfortunately, the seer has only enough energy to guess a maximum of K mafia members, and the police wants to use the seer powers carefully so they can arrest as many bad guys as possible. Given K and the full structure of the mafia, what is the maximum amount of mafia members the police can arrest?

## 예제 입력 1
```
8 2
1 1 2 3 4 4 6
```

## 예제 출력 1
```
7
```

## 예제 입력 2
```
10 3
1 1 2 2 3 3 4 4 5
```

## 예제 출력 2
```
8
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 4 | Java 11 / 수정 | 46588 KB | 400 ms | 1323 B | 1년 전 |
