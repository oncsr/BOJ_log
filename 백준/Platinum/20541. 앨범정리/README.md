# [20541. 앨범정리](https://www.acmicpc.net/problem/20541)

## 문제
지혜는 컴퓨터에 있는 사진들을 정리하기 위해 앨범정리 프로그램을 만들었다. 지혜가 만든  앨범정리 프로그램은 기본적으로 "album" 앨범이 존재하며 "album" 앨범은 절대로 삭제할 수 없다. 프로그램을 실행시키면 "album" 앨범부터 시작하여 명령어들을 통해 앨범 삭제/추가, 사진 삭제/추가, 현재앨범 이동 등을 할 수 있다. 앨범정리 프로그램은 다음과 같은 명령어 들로 구성 되어 있다. 수행할 명령어의 개수 $N$이 주어질 때 각 명령어 수행 후 문자열 출력이 필요한 명령어에 대해서 문자열을 출력한다.




mkalb
	


명령어 수행후
: 현재 앨범에 속해있는 앨범 중 동일한 이름을 가진 앨범이 존재하여 앨범이 생성되지 않았으면 "duplicated album name"을 출력합니다. 그렇지 않다면 아무것도 출력하지 않습니다.


mkalb $S$
		


현재 앨범에 $S$ 의 이름을 가진 앨범을 생성합니다.


현재 앨범에 속해있는 앨범 중 동일한 이름을 가진 앨범이 존재하면 앨범을 생성하지 않습니다.










rmalb
	


명령어 수행후
: 삭제된 앨범의 개수와 사진의 개수를 공백으로 구분하여 출력합니다.


rmalb $S$
		


현재 앨범에 속해있는 앨범 중 $S$ 의 이름을 가진 앨범이 존재한다면, 해당 앨범을 삭제합니다.


삭제된 앨범에 속한 모든 앨범과 사진들 또한 삭제됩니다.






rmalb -1
		


현재 앨범에 속해있는 앨범이 존재한다면, 이름이 사전순으로 가장 빠른 앨범을 삭제 합니다.


삭제된 앨범에 속한 모든 앨범과 사진들 또한 삭제됩니다.






rmalb 0
		


현재 앨범에 속해있는 모든 앨범을 삭제 합니다.


삭제된 앨범에 속한 모든 앨범과 사진들 또한 삭제됩니다.






rmalb 1
		


현재 앨범에 속해있는 앨범이 존재한다면, 이름이 사전순으로 가장 늦은 앨범을 삭제 합니다. 


삭제된 앨범에 속한 모든 앨범과 사진들 또한 삭제됩니다.










insert
	


명령어 수행후
: 현재 앨범에 속해있는 사진 중에 동일한 이름을 가진 사진이 존재하여 사진이 삽입되지 않았으면 "duplicated photo name"을 출력합니다. 그렇지 않다면 아무것도 출력하지 않습니다.


insert $S$
		


현재 앨범에 $S$ 의 이름을 가진 사진을 삽입합니다.


현재 앨범에 속해있는 사진 중 동일한 이름을 가진 사진이 존재하면 사진을 삽입하지 않습니다.










delete
	


명령어 수행후
: 삭제된 사진의 개수를 출력합니다.


delete $S$
		


현재 앨범에 속해있는 사진 중 $S$ 의 이름을 가진 사진이 존재한다면, 해당 사진을 삭제합니다.






delete -1
		


현재 앨범에 속해있는 사진이 존재한다면, 이름이 사전순으로 가장 빠른 사진을 삭제 합니다.






delete 0
		


현재 앨범에 속해있는 모든 사진을 삭제합니다.






delete 1
		


현재 앨범에 속해있는 사진이 존재한다면, 이름이 사전순으로 가장 늦은 사진을 삭제 합니다. 










ca
	


명령어 수행후
: 현재 앨범 이름을 출력합니다.


ca $S$
		


현재 앨범에 속해있는 앨범 중 $S$ 의 이름을 가진 앨범으로 이동합니다.


현재 앨범에 속해있는 앨범 중 $S$ 의 이름을 가진 앨범이 없다면 현재 앨범에 머무릅니다.






ca ..
		


현재 앨범의 상위 앨범으로 이동합니다.


현재 앨범이 최상위 앨범인 "album" 앨범이라면 현재 앨범에 머무릅니다.






ca /
		


최상위 앨범인 "album" 앨범으로 이동합니다.












"A가 B에 속해있다"라는 것은 A의 
바로 하위
에 B가 있다는 것을 의미합니다. 만약 A가 B에 속해있고, B가 C에 속해있는 경우, A는 C에 속해 있는 것이 아닙니다.

## 예제 입력 1
```
24
mkalb animal
mkalb insect
ca animal
mkalb sky
mkalb land
mkalb ocean
ca land
insert elephant
insert tiger
insert banana
delete banana
ca elephant
ca ..
ca ocean
insert whale
ca /
ca insect
mkalb land
mkalb sky
ca ocean
ca ..
ca ..
rmalb -1
rmalb -1
```

## 예제 출력 1
```
animal
land
1
land
animal
ocean
album
insect
insect
album
album
4 3
3 0
```

## 예제 입력 2
```
29
mkalb domestic
mkalb ovarseas
ca domestic
ca incheon
mkalb incheon
ca incheon
mkalb chinatown
mkalb wolmido
ca chinatown
insert jajangmyeon
insert champon
insert friedrice
insert jajangmyeon
ca /
ca domestic
rmalb incheon
ca /
rmalb ovarseas
mkalb overseas
ca overseas
mkalb japanese
mkalb europe
rmalb japanese
ca europe
rmalb 0
ca ..
delete europe
ca ..
rmalb 1
```

## 예제 출력 2
```
domestic
domestic
incheon
chinatown
duplicated photo name
album
domestic
3 3
album
1 0
overseas
1 0
europe
0 0
overseas
0
album
2 0
```

## 예제 입력 3
```
30
mkalb univ
mkalb middle
mkalb elementary
insert middle
ca middle
insert middleschool
ca ..
rmalb middle
ca univ
mkalb inha
insert kaist
insert harvard
delete harvard
ca inha
mkalb inkyungho
mkalb hightech
mkalb jungseok
delete 0
rmalb 1
ca jungseok
ca hightech
mkalb computer
mkalb elect
mkalb machine
rmalb 1
rmalb 1
insert computer
insert elect
ca /
rmalb 0
```

## 예제 출력 3
```
middle
album
1 1
univ
1
inha
0
1 0
inha
hightech
1 0
1 0
album
6 3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | C++17 / 수정 | 6004 KB | 112 ms | 2212 B | 1년 전 |
