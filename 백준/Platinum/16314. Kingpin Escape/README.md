# [16314. Kingpin Escape](https://www.acmicpc.net/problem/16314)

## 문제
You are the kingpin of a large network of criminal hackers. Legend has it there has never been a richer criminal than you. Not just because you are the smartest, but also because you are the stingiest.


The police have been after you for years, but they have never been able to catch you thanks to your great set of escape routes. Whenever they want to catch you in one of your many hideouts, you quickly get away through your network of tunnels, back-alleys and speakeasies. Your routes are set up so that from every hideout you have in the city you can get to any other hideout by following only your secret passageways. Furthermore, because you are such a penny-pincher, your network is the smallest possible: from every hideout to every other hideout there is precisely one route through the network, no more and no fewer.


Yesterday, your mole in the police force has informed you of an unfortunate fact: the police are on to you! They have gotten wind of your secret network, and will attempt to catch you. They are planning to block some of your escape routes, and catch you in the act. They will start blocking your secret passageways one by one, until you have nowhere left to go.


Fortunately, your headquarters are absolutely safe. If you can just get there, you are always fine. Furthermore, your mole in the police force can inform you immediately as soon as the police start blocking passageways, so that they only have time to block one of them before you get notified. If you get back to your headquarters before they block any more routes, you’re safe.


You want to add some passageways to the network so that whenever at most one of them is blocked, you can still get to your headquarters from any other hideout. Since the news has not changed your frugality, you want to extend your network as cheaply as possible. Can you figure out the least number of passageways you need to add, and which ones you need?

## 예제 입력 1
```
4 0
0 1
0 2
0 3
```

## 예제 출력 1
```
2
3 2
3 1
```

## 예제 입력 2
```
6 0
0 1
0 2
0 3
1 4
1 5
```

## 예제 출력 2
```
2
3 5
2 4
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 1 | C++17 / 수정 | 9156 KB | 48 ms | 613 B | 2년 전 |
