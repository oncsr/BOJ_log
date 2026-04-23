# [26265. 멘토와 멘티](https://www.acmicpc.net/problem/26265)

## 문제
서울사이버대학교에는 멘토링 프로그램이 있다. 멘토링 프로그램은 한 명의 멘토(선배학습자)가 여러 명의 멘티(후배학습자)에게 대학 생활에 대한 노하우와 정보 등을 전수하는 것이다.


빅데이터·AI 센터에서 딥러닝 서버를 돌리며 바쁜 나날을 보내던 노교수는, 어느 날 멘토링 회의 참석 요청이 들어와 이를 준비하던 도중 멘토-멘티 순서쌍 목록이 적힌 노트를 찾았다. 하지만 노트가 제대로 정리되어 있지 않아 분석이 어려웠으므로, 마침 센터에서 인턴을 하는 대학원생 뚜루에게 목록의 정렬을 맡기기로 했다.


하지만 논문을 쓰느라 수면 부족에 시달리고 있는 뚜루는 이러한 프로그램을 짤 틈이 나지 않았기 때문에, 당신에게 다시 목록을 맡겼다. 목록이 주어질 때 멘토를 기준으로 사전 순으로 정렬하되, 멘토가 같은 순서쌍들에 대해선 멘티의 사전 역순으로 정렬하자.

## 예제 입력 1
```
5
alice bob
alice dave
eve mallory
peggy victor
alice carol
```

## 예제 출력 1
```
alice dave
alice carol
alice bob
eve mallory
peggy victor
```

## 예제 입력 2
```
8
cgiosy jhnah
son kim
son lee
cgiosy leejseo
cgiosy junseo
son hwang
cgiosy sean
cgiosy cologne
```

## 예제 출력 2
```
cgiosy sean
cgiosy leejseo
cgiosy junseo
cgiosy jhnah
cgiosy cologne
son lee
son kim
son hwang
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 5 | C++17 / 수정 | 17540 KB | 412 ms | 478 B | 3년 전 |
