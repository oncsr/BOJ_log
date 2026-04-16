# [33783. Friends](https://www.acmicpc.net/problem/33783)

## 문제
A new social network has been released and as you're very into new technology, you immediately decide to join it. After creating your account, you would look who has joined the network already so you can send some friend requests. It appears this is not a regular social network like Facebook and there's one difference: when you are friends with someone, you're automatically friends with all the people he or she is also friends with. For example, if you're friends with "Jan", and "Jan" is friends with "Piet", then you are also friends with "Piet" and all other people he has as friend.


You are given the details of the network. You know which members have joined the network and which users are friends with each other. Each user has an unique identifier in the network.


More and more people are joining the new established network and you would like to know whether you're friends with everyone. After all, one can never have too much friends on a social network!

## 예제 입력 1
```
5 4 3
0 1
1 2
2 3
3 4
```

## 예제 출력 1
```
yes
```

## 예제 입력 2
```
6 3 2
1 2
1 4
0 5
```

## 예제 출력 2
```
no
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 2 | Java 11 / 수정 | 22308 KB | 196 ms | 1397 B | 1년 전 |
