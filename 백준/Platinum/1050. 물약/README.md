# [1050. 물약](https://www.acmicpc.net/problem/1050)

## 문제
과학자 임문빈은 마법의 물약을 만든다. 임문빈은 많은 재료를 가지고 있고, 다음과 같은 식을 이용해서 만든다.


S=N
1
×S
1
+...+N
k
×S
k


여기서 N
1
, ..., N
k
는 1보다 크거나 같고, 9보다 작거나 같은 한 자리 숫자이고, S
1
, ..., S
k
는 재료의 이름이다. 그리고, k는 1보다 크거나 같은 자연수이다. 마지막으로 S는 마법의 물약의 이름이다. 위의 식은 N
1
만큼 S
1
을 넣고, ..., N
k
만큼 S
k
를 넣으면 S가 1만큼 만들어 진다는 얘기와 같다.


같은 물약을 만드는데 여러 가지 재료법이 있을 수도 있다. 이때는, 아무거나 사용하면 된다. 마법의 물약은 또 다른 물약을 만드는데 재료가 될 수도 있고, 이 중 어떤 재료는 시장에서 살 수 있다.


임문빈은 이름이 LOVE인 마법의 물약을 만들려고 한다. (이 물약을 먹으면 임문빈을 사랑하게 된다) 시장에서 파는 재료와 그 가격이 주어지고, 임문빈이 만들 수 있는 모든 물약의 식이 주어진다. 이때, LOVE를 1만큼 만드는데 드는 비용의 최솟값을 출력한다.

## 예제 입력 1
```
3 2
WATER 2
HONEY 6
HOP 9
LOVE=2WATER+4HONEY+2BEER
BEER=1HOP+3WATER+1HOP
```

## 예제 출력 1
```
76
```

## 예제 입력 2
```
3 1
LOVE 100
WATER 1
HONEY 30
LOVE=5WATER+3HONEY
```

## 예제 출력 2
```
95
```

## 예제 입력 3
```
2 1
ORANGEJUICE 6
APPLEJUICE 4
JUICEMIX=1ORANGEJUICE+1APPLEJUICE
```

## 예제 출력 3
```
-1
```

## 예제 입력 4
```
3 2
WATER 1
HONEY 22
HOP 17
LOVE=7WATER+3HONEY
LOVE=2HONEY+2HOP
```

## 예제 출력 4
```
73
```

## 예제 입력 5
```
2 3
OIL 60
WATER 70
FIRSTPOTION=1OIL+1SECONDPOTION
SECONDPOTION=4WATER+1FIRSTPOTION
LOVE=1FIRSTPOTION+1SECONDPOTION
```

## 예제 출력 5
```
-1
```

## 예제 입력 6
```
1 10
HONEYBIT 100
LOVE=6HONEYMEGABYTE
HONEYMEGABYTE=2HONEYFIFTYTWELVEKBYTES
HONEYFIFTYTWELVEKBYTES=8HONEYSIXTYFOURKBYTES
HONEYSIXTYFOURKBYTES=8HONEYEIGHTKBYTES
HONEYEIGHTKBYTES=8HONEYKBYTE
HONEYKBYTE=2EIGHTBYEIGHTWORDS
EIGHTBYEIGHTWORDS=8EIGHTWORDS
EIGHTWORDS=8HONEYWORD
HONEYWORD=8HONEYBYTE
HONEYBYTE=8HONEYBIT
```

## 예제 출력 6
```
1000000001
```

## 예제 입력 7
```
1 1
WATER 1
LOVE=1LOVE
```

## 예제 출력 7
```
-1
```

## 예제 입력 8
```
3 8
MILK 6
WATER 1
HOP 14
NECTAR=4HOP+2MILK
LOVE=5MILK+3BEER
LOVE=2WATER+1LOVE
LOVE=2MIX+1NECTAR
MIX=1MILK+1WATER+1HOP
BEER=5WATER+2HOP
LOVE=1NECTAR+3WATER+3HOP
NECTAR=3BEER+1MILK+2MILK
```

## 예제 출력 8
```
110
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | Java 11 / 수정 | 14772 KB | 128 ms | 2636 B | 1년 전 |
