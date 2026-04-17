# [13288. A New Alphabet](https://www.acmicpc.net/problem/13288)

## 문제
A New Alphabet has been developed for Internet communications. While the glyphs of the new alphabet don’t necessarily improve communications in any meaningful way, they certainly make us feel cooler.


You are tasked with creating a translation program to speed up the switch to our more elite New Alphabet by automatically translating ASCII plaintext symbols to our new symbol set.


The new alphabet is a one-to-many translation (one character of the English alphabet translates to anywhere between 1 and 6 other characters), with each character translation as follows:




For instance, translating the string “Hello World!” would result in:


[-]3110 \/\/0|Z1|)!


Note that uppercase and lowercase letters are both converted, and any other characters remain the same (the exclamation point and space in this example).

## 예제 입력 1
```
All your base are belong to us.
```

## 예제 출력 1
```
@11 `/0|_||Z 8@$3 @|Z3 8310[]\[]6 ']['0 |_|$.
```

## 예제 입력 2
```
What's the Frequency, Kenneth?
```

## 예제 출력 2
```
\/\/[-]@'][''$ ']['[-]3 #|Z3(,)|_|3[]\[](`/, |<3[]\[][]\[]3']['[-]?
```

## 예제 입력 3
```
A new alphabet!
```

## 예제 출력 3
```
@ []\[]3\/\/ @1|D[-]@83']['!
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 2 | C++17 / 수정 | 2168 KB | 0 ms | 472 B | 2년 전 |
