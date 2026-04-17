# [1294. 문자열 장식](https://www.acmicpc.net/problem/1294)

## 문제
오민식은 단어 N개를 이용해서 문자열 W를 만들려고 한다.


일단 오민식은 각각의 문자열을 적절히 쪼갠다. 그 다음에 쪼갠 문자열을 모두 이어붙여서 W를 만든다. 단, 한 문자열을 쪼개서 나온 조각의 순서는 유지해야 한다.


예를 들어, 오민식이 {YOUNGSIK, DONGHO, BAEKJOON} 총 3개를 가지고 있었다면, 오민식은 자기 마음대로 {YOUNG, SIK, DO, NG, HO, BA, E, K, JOO, N}과 같이 쪼갠 다음, 아래와 같이 YOUNGDOBAESIKNGKJOOHON을 만들 수 있다.



YOUNG     SIK
     DO      NG    HO
       BAE     KJOO  N
----------------------
YOUNGDOBAESIKNGKJOOHON



오민식이 만들 수 있는 문자열 중에 사전순으로 가장 앞서는 것을 출력하시오.

## 예제 입력 1
```
4
CCCA
CCCB
CCCD
CCCE
```

## 예제 출력 1
```
CCCACCCBCCCCCCDE
```

## 예제 입력 2
```
5
KOOSAGA
XIAOWUC
DOTORYA
CKI
THENITROMEFAN
```

## 예제 출력 2
```
CDKIKOOOSAGATHENITORTROMEFANXIAOWUCYA
```

## 예제 입력 3
```
5
BKSDSOPTDD
DDODEVNKL
XX
PODEEE
LQQWRT
```

## 예제 출력 3
```
BDDKLODEPODEEEQQSDSOPTDDVNKLWRTXX
```

## 예제 입력 4
```
5
QITHSQARQV
BYLHVGMLRY
LKMAQTJEAM
AQYICVNIKK
HKGZZFFEWC
```

## 예제 출력 4
```
ABHKGLKMAQIQQTHSQARQTJEAMVYICVNIKKYLHVGMLRYZZFFEWC
```

## 예제 입력 5
```
5
XHCYBTUQUW
EKBISADSSN
LOOISPOFAK
MIXBDHPJUQ
BNMNDHMOTC
```

## 예제 출력 5
```
BEKBILMINMNDHMOOIOSADSPOFAKSSNTCXBDHPJUQXHCYBTUQUW
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 3 | C++17 / 수정 | 2168 KB | 744 ms | 724 B | 2년 전 |
