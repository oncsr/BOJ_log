# [30037. K-Words Problem](https://www.acmicpc.net/problem/30037)

## 문제
아티초크는 교양과목 '한국 문화로 보는 프로그래밍 언어론'을 수강 중이다.


아티초크는 지난주에 과제로 '아희가 한국 문화에 미친 영향'을 주제로 $5\,000$단어 분량의 보고서를 작성했는데, 이번 주에는 이 보고서를 짧게 요약하는 과제가 나왔다.


이번 학기에 전공과목만 $7$과목을 수강하고 있었던 아티초크는 보고서 요약을 직접 할 여유가 없었다.


따라서 아래의 규칙에 따라 보고서를 요약해주는 프로그램을 만들기로 했다. 규칙은 다음과 같다.




보고서에 단어 'Korea'가 등장할 경우, 다음에 나오는 단어와 합쳐 'K-단어'로 축약한다. (ex. Korea language → K-Language)
	


단어 'Korea'는 대문자와 소문자를 구분한다.


단어 'Korea' 다음에 나오는 단어의 첫 글자가 소문자일 경우 대문자로 변환한다.


이 규칙을 여러 번 연달아 적용할 수 있는 경우 뒤에서부터 적용한다.


단어 'Korea' 뒤에 문장 부호가 붙어 있는 경우 이 규칙을 적용할 수 없다.






보고서에 단어 'of' 직후에 단어 'Korea'가 등장할 경우, 단어 'of' 직전에 나오는 단어와 합쳐 K-단어로 축약한다. (ex. Language of Korea → K-Language)
	


단어 'of'와 'Korea'는 대문자와 소문자를 구분한다.


단어 'of' 직전에 나오는 단어의 첫 글자가 소문자일 경우 대문자로 변환한다.


이 규칙을 여러 번 연달아 적용할 수 있는 경우 앞에서부터 적용한다.


단어 'of' 뒤에 문장 부호가 붙어 있는 경우 이 규칙을 적용할 수 없다.


단어 'of' 앞에 단어가 없거나, 단어 'of' 직전에 나오는 단어에 문장 부호가 붙어 있는 경우 이 규칙을 적용할 수 없다.


단어 'Korea' 뒤에 문장 부호가 붙어있는 경우, 단어 'Korea' 뒤의 문장 부호를 단어 'of' 직전에 나오는 단어 뒤에 붙인다. 






1번 규칙과 2번 규칙을 한 문장에 동시에 적용할 수 있는 경우, 2번 규칙을 먼저 적용한다.




아티초크는 전공 과제가 너무 밀려, 보고서 요약 프로그램을 작성할 여유조차 없었다. 그런 아티초크를 대신하여 구현해 보자.

## 예제 입력 1
```
7
Artichoke in Korea Army uses Aheui.
Aheui, the best language of Korea.
Korea is our country.
of Korea? Korea Korea Aheui of Korea.
Language of, Korea Korea.
Aheui has shown the greatness of Korea of Korea.
korea Korea! koRea Of Korea of Korea oF kORea.
```

## 예제 출력 1
```
Artichoke in K-Army uses Aheui.
Aheui, the best K-Language.
K-Is our country.
of Korea? K-K-K-Aheui.
Language of, K-Korea.
Aheui has shown the K-K-Greatness.
korea Korea! koRea Of K-Korea oF kORea.
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 4904 KB | 8 ms | 1905 B | 2년 전 |
