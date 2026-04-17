# [13168. 내일로 여행](https://www.acmicpc.net/problem/13168)

## 문제
친한 친구인 승현이와 지학이는 여름방학 때 여행을 가기로 계획했습니다. 해외여행은 금전적으로 부담이 많기 때문에 둘은 한국의 여러 도시를 여행하기로 했습니다. 한국에는 N개의 도시가 있으며, 승현이는 이 중 여행할 M개의 도시를 결정했습니다. 여행 경로에서 같은 도시를 여러 번 방문할 수 있으며, 여행을 시작하는 도시와 끝내는 도시는 같습니다.


한국에는 두 도시 사이를 오갈 수 있는 K개의 교통수단이 있습니다. 교통수단의 종류는 기차, 지하철, 버스, 택시, 비행기 등으로 다양합니다. 특히 기차 코스는 매우 세부적으로 나뉘어 있어서 무궁화호(Mugunghwa), ITX-새마을(ITX-Saemaeul), ITX-청춘(ITX-Cheongchun), KTX, S-Train, V-Train 등이 있습니다. 모든 교통수단은 한 번 이용하는 데 필요한 비용이 정해져 있습니다. 승현이와 지학이는 계획한 M개의 도시를 최소비용으로 차례대로 움직일 것입니다.


한편, 코레일에서는 ‘내일로’라는 특별한 기차표를 판매하고 있습니다. 방학 동안, 젊은 청년들은 R원을 주고 내일로 티켓을 살 수 있습니다. 한 번 내일로 티켓을 사면, 며칠 동안 무궁화호, ITX-새마을, ITX-청춘은 무료로 이용할 수 있으며, S-Train과 V-Train은 50% 할인된 가격으로 이용할 수 있습니다. KTX나 지하철, 또는 다른 교통수단에 대해서는 할인이 적용되지 않습니다.


지학이는 자신이 아무것도 하지 않는 것에 죄책감을 느끼기 때문에, 자신들의 여행에서 내일로 티켓이 필요한지 생각해보기로 했습니다. 지학이를 도와 내일로 티켓을 사는 것과 사지 않는 것 중 어떤 선택이 더 좋은 지 구하는 프로그램을 작성하세요.

## 예제 입력 1
```
14 40000
Boseong Busan Changwon Cheonan Chuncheon Daegu Daejeon Gwangju Jeonju Jinju Masan Seoul Suncheon Yeosu
9
Seoul Jeonju Suncheon Yeosu Suncheon Boseong Jinju Busan Seoul
23
KTX Seoul Busan 20000
KTX Seoul Gwangju 12000
KTX Gwangju Yeosu 8000
KTX Seoul Jinju 17000
ITX-Saemaeul Seoul Cheonan 7000
ITX-Cheongchun Seoul Chuncheon 3000
V-Train Chuncheon Daegu 10000
Subway Seoul Cheonan 2000
ITX-Saemaeul Cheonan Daejeon 4000
ITX-Saemaeul Daejeon Daegu 10000
ITX-Saemaeul Daegu Busan 7000
Mugunghwa Daejeon Daegu 6000
Mugunghwa Daejeon Gwangju 5000
Mugunghwa Gwangju Jeonju 1500
Mugunghwa Jeonju Suncheon 4000
Mugunghwa Suncheon Yeosu 1500
S-Train Busan Changwon 3000
S-Train Changwon Masan 1000
S-Train Masan Jinju 2000
S-Train Jinju Suncheon 2000
S-Train Suncheon Boseong 1000
Bus Busan Jinju 1500
Bus Suncheon Jinju 4000
```

## 예제 출력 1
```
Yes
```

## 예제 입력 2
```
5 50000
Seoul Cheonan Daejeon Daegu Busan
3
Seoul Busan Seoul
5
ITX-Saemaeul Seoul Cheonan 7000
ITX-Saemaeul Cheonan Daejeon 4000
ITX-Saemaeul Daejeon Daegu 10000
ITX-Saemaeul Daegu Busan 7000
KTX Seoul Busan 24999
```

## 예제 출력 2
```
No
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 4648 KB | 16 ms | 1435 B | 2년 전 |
