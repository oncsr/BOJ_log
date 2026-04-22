# [27649. 토크나이저](https://www.acmicpc.net/problem/27649)

## 문제
주원이는 시스템과 상호 작용할 수 있는 편리한 텍스트 인터페이스를 제공하는 셸을 만들고 있습니다. 셸은 명령문을 입력받으면, 차례로 tokenizer $\rightarrow$ lexer $\rightarrow$ parser $\rightarrow$ expander $\rightarrow$ executor를 호출하여 명령문을 해석하고, 유효한 프로그램을 실행합니다. 주원이는 셸을 만들기 위해 가장 먼저 아래의 구분자들로 명령문을 자르는 토크나이저를 개발해야 합니다. 하지만 문자열은 항상 공백으로만 구분해 왔던 주원이는 여러 구분자로 명령문을 자르는 것을 어려워하고 있습니다. 주원이의 멋진 셸을 위하여 토크나이저를 만드는 것을 도와주세요.








구분자


명령문


출력 예시






<


cat <infile


cat < infile






>


program >outfile


program > outfile






&&


program&&echo success


program && echo success






||


grep sol < for||echo fail


grep sol < for || echo fail






(


(exit 0)


( exit 0 )






)


(cd $OLDPWD ) && pwd


( cd $OLDPWD ) && pwd






" " (공백)


echo 1  2   3    4




echo 1 2 3 4










토크나이저는 다음과 같은 방식으로 동작한다.




문자열을 앞에서부터 읽어나간다.


구분자를 만나면 구분자의 앞뒤를 자른다. 이후 구분자의 다음 위치부터 다시 읽어나간다. 이때 잘린 문자열을 토큰이라고 한다.


문자열의 끝에 도달할 경우, 앞에서부터 차례대로 토큰들을 공백으로 구분하여 출력한다. 단, 토큰이 공백일 경우 출력하지 않는다.




문자열 S를 
"grep skku   <infile> outfile"
라고 하자. 이때 토큰을 
:
 을 기준으로 구분할 때 문자열 S는 아래와 같이 토큰화된다.


grep
: 
:
skku
: : : :
<
:
infile
:
>
: 
:
outfile


위 토큰 중 단일 공백으로만 이루어진 토큰을 제외하여 순서대로 공백으로 구분하여 출력한다. 예시의 경우 
"grep skku < infile > outfile"
를 출력한다.

## 예제 입력 1
```
grep skku   <infile> outfile
```

## 예제 출력 1
```
grep skku < infile > outfile
```

## 예제 입력 2
```
(exit $?  )||expr $? + $?
```

## 예제 출력 2
```
( exit $? ) || expr $? + $?
```

## 예제 입력 3
```
grep Wall <Makefile|| echo NotSetCflagsWall>outfile
```

## 예제 출력 3
```
grep Wall < Makefile || echo NotSetCflagsWall > outfile
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 3 | C++17 / 수정 | 4916 KB | 92 ms | 788 B | 3년 전 |
