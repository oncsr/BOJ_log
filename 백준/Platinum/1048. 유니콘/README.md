# [1048. 유니콘](https://www.acmicpc.net/problem/1048)

## 문제
유니콘은 체스에서 나이트와 비슷한 말이다. 단, 나이트는 두 칸을 한 방향으로 움직이고, 또 다른 한 칸을 다른 방향으로  움직이지만, 유니콘은 두 칸보다 많은 칸을 한 방향으로 움직이고, 한 칸보다 많은 칸을 또다른 방향으로 움직인다.


좀 더 정확하게 유니콘이 움직이는 방법을 살펴보면 다음과 같다.




유니콘을 든다.


유니콘을 $4$개의 기본 방향 중 하나로 두 칸보다 많이 움직인다.


유니콘을 방금 움직인 방향과 수직인 방향 $2$개 중 하나로 한 칸보다 많이 움직인다.


유니콘을 놓는다.




체스판의 크기는 $N \times M$이다. 체스판의 각 칸에는 알파벳 대문자의 처음 $L$개의 문자 중 하나가 쓰여 있다.


$N$, $M$, $L$, 그리고 단어가 주어진다. 유니콘이 움직인 경로 (유니콘을 놓은 곳)가 입력으로 주어진 단어와 일치하는 경우의 수를 출력하는 프로그램을 작성하시오.

## 예제 입력 1
```
3 4 2
AB
ABBA
AAAA
BBBB
```

## 예제 출력 1
```
2
```

## 예제 입력 2
```
5 5 2
CD
ABBAA
AAABB
BBBBB
ABABA
ABBBB
```

## 예제 출력 2
```
0
```

## 예제 입력 3
```
4 4 1
AA
AAAA
AAAA
AAAA
AAAA
```

## 예제 출력 3
```
20
```

## 예제 입력 4
```
4 4 1
AAAAA
AAAA
AAAA
AAAA
AAAA
```

## 예제 출력 4
```
172
```

## 예제 입력 5
```
1 1 5
ABCDE
C
```

## 예제 출력 5
```
0
```

## 예제 입력 6
```
8 8 26
TOPCODER
AILFPSPF
DZIOMYCE
QOODZARU
YVOTLTRX
LSRIGANL
LCIUUSNF
IWVXKTDE
OVPPNXRD
```

## 예제 출력 6
```
1
```

## 예제 입력 7
```
20 20 2
AAAAA
ABBAAAAABBBBBBBABABA
ABBBBBABAAAABBAAABAA
BAAABAABAABBABABBABB
BBABBAAAABABAAAAABBA
BBABAABABBAABABABBBA
BABABAABABBBABBAABBA
BAABBAAABBBABBABAAAA
BAABBBBABAABAAAAABAA
AABABAAAAABBBABABBBA
BBAABAAABBAABAAAAABA
BAAAAABABBAAABABABBA
ABBAABBBABABBABAAABB
AAAABAAAAAAAABBBAABB
AAABABAAAAAABAAABABB
AAABABABBABABAAABBBA
AAABBBBAABBAABAAABBA
BBBBAAABBABABAAAABAB
BBAABBAABAAAABAABABA
BBBAABBABABBBBBBBBBA
AAABABBBBAABABBBBBBB
```

## 예제 출력 7
```
373977054
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 4 | Java 11 / 수정 | 39696 KB | 668 ms | 2914 B | 1년 전 |
