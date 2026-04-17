# [1501. 영어 읽기](https://www.acmicpc.net/problem/1501)

## 문제
혹시 인터넷을 하다가, 다음과 같은 식의 문장을 본 적이 있는가?


It is itnersetnig taht pepole can raed smoe grabeld wrods.


원래의 문장은 'It is interesting that people can read some garbled words'이다. 각각의 단어들은 제일 첫 문자와 제일 끝 문자를 제외하고는 순서가 뒤섞여 있다. 한 대학에서 시행한 연구 조사 결과에 따르면, (영어 단어를 아는 사람의 경우) 첫 문자와 제일 끝 문자가 일치하고, 그 사이의 문자들은 순서가 어떻게 뒤바뀌어 있더라도 읽는 데 지장이 없다고 한다.


그렇다보니, 한 단어가 여러 단어로 해석될 수도 있다. 예를 들어 abcde와 같은 단어는, abcde, abdce, acbde, acdbe, adbce, adcbe 같은 단어들로 해석될 수도 있다. 물론 각각의 단어들이 실제로 존재하는 단어(사전에 존재하는 단어)일 경우에만 의미가 있다.


영어 문장이 주어졌을 때, 그 문장을 해석하는 방법의 경우의 수를 구하는 프로그램을 작성하시오. 각각의 단어는, 첫 글자와 끝 글자가 일치하는 다른 단어(사전에 존재하는)로 해석할 수 있다. 영어 문장은 하나 이상의 단어로 이루어져 있으며, 각 단어들은 공백으로 구분되어 있다.

## 예제 입력 1
```
3
ababa
aabba
abcaa
2
ababa
abbaa
```

## 예제 출력 1
```
2
2
```

## 예제 입력 2
```
14
bakers
brakes
breaks
binary
brainy
baggers
beggars
and
in
the
blowed
bowled
barn
bran
1
brainy bakers and beggars bowled in the barn
```

## 예제 출력 2
```
48
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 5 | C++17 / 수정 | 2560 KB | 8 ms | 661 B | 2년 전 |
