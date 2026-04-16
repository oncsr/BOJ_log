# [15913. 가위 바위 보 999](https://www.acmicpc.net/problem/15913)

## 문제
채점 프로그램과 가위 바위 보를 999번 해서, 최대한 많이 이겨 보자.


채점 프로그램은 랜덤을 이용해 가위 바위 보 중 하나를 결정하며, 그 코드를 간단히 나타내면 다음과 같다. 아래 코드의 변수 
judge
가 채점 프로그램이 결정한 값이다.



#include <random>
using namespace std;
int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, 2);
    int judge = distribution(gen);
    return 0;
}

## 예제 입력 1
```

```

## 예제 출력 1
```
0
```

## 예제 입력 2
```

```

## 예제 출력 2
```
1
```

## 예제 입력 3
```

```

## 예제 출력 3
```
2
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Unrated | Text / 수정 | 4528 KB | 0 ms | 1 B | 11달 전 |
