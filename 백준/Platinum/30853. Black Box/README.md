# [30853. Black Box](https://www.acmicpc.net/problem/30853)

## 문제
The following 
Python
-like pseudo code for function 
BlackBox()
 takes a list of positive integers and shuffles the integers in the list in a specific way, and returns the result as a list.


Three list methods are used below; For a list 
L
, 
len(L)
 returns the number of items in 
L
. 
L.append(x)
 adds the item 
x
 to the end of 
L
. 
L.pop(idx)
 removes the item at the specified index 
idx
 from the list 
L
 and returns the removed item.


Given a list 
Z
 of positive integers, write a program to reconstruct a list 
I
 such that 
Z = BlackBox(I)
.




function
 BlackBox( Banana ):
    
if
 len( Banana ) ≤ 4 :
        exit("Too small Banana")
    Apple = [] # [] is an empty list
    Mango = 0
    Papaya = len( Banana )

    
while
( Papaya >= 2 ) :
        Kiwi = Banana[ Mango ]
        Apple.append( Kiwi )
        Banana.pop( Mango )
        Papaya = Papaya - 1
        Mango = ( Kiwi + Mango - 1 ) % Papaya
    # end of while

    Apple.append( Banana[ 0 ] )
    Pear = len( Apple ) - 1
    Orange = Apple[ Pear ]
    Lime = Apple[ 0 ]
    Coconut = Orange % Pear
    Melon = Apple[ Coconut ]
    Apple[ 0 ] = Melon
    Apple[ Coconut ] = Lime

    
return
 ( Apple )
# end of function BlackBox

## 예제 입력 1
```
13
113
49
68
91
10
179
2
71
78
45
57
10
88
```

## 예제 출력 1
```
10
113
179
68
57
45
10
2
88
71
49
78
91
```

## 예제 입력 2
```
9
6
8
7
9
5
1
2
4
3
```

## 예제 출력 2
```
9
8
7
6
5
1
2
3
4
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 3 | C++17 / 수정 | 5508 KB | 712 ms | 1448 B | 2년 전 |
