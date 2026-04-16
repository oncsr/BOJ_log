# [35376. But I Want to Win](https://www.acmicpc.net/problem/35376)

## 문제
Borphee, the largest city in all of Frobozz, recently lost its mayor to the insatiable appetite of a Grue. The deputy mayor became the interim mayor and immediately took over the mayoral duties, which consist primarily of presiding over the annual 
Double Fanucci Championships\/
 (an extraordinarily complex card game) and the 
From Bad to Worst Songfest\/
, which is where the most dreadful singers in the land gather every winter. The mayor's salary is several hundred thousand zorkmids (zm) a year, which is very lucrative for such an easy job. With the special election quickly approaching, it goes without saying that the deputy mayor wants to do anything in his power to change his "interim mayor" status to "mayor" and retain his very generous salary. 


The entire empire uses a variation of 
single-winner ranked choice voting\/
 for all its elections. It works like this:




Voters mark their ballots in order of preference: first choice (their favorite candidate), second choice (their next favorite candidate) and so on. Each voter 
must
 rank all candidates on their ballot.  For example, if there are 12 candidates in the election, then each voter will rank their choices from 1 (their favorite) to 12 (their least favorite).  The election then proceeds in a set of 
rounds
.


At the start of each round, all first-choice votes are counted. If a candidate receives more than 50\% of the first-choice votes, that candidate wins, and the election is over.


If there is no winner, then the candidate with the least number of first-place votes is removed from all ballots, and the remaining candidates with worse rankings move up. For example, if a voter ranked four candidates in the order A (first-choice) B C D and candidate A is removed, then this voter's ballot is changed to B (new first-choice) C D; if candidate B is removed, then the ballot is changed to A C D. If one or more candidates tie for the least number of first-place votes then all of them are removed from the ballots.


After the ballots are readjusted, return to step 2 to start the next round.




This procedure may continue until there are only 2 candidates left, at which point the candidate with the majority of first-place votes wins.


The interim mayor assumes that the election will eventually come down to him and one other very popular candidate as the two front runners. With this in mind, he wants to concentrate his campaigning efforts on the voters who ranked one of the other candidates first on their ballot, in case the initial vote count puts him in 2nd place. To help him better plan, he wants you to develop a program that will allow him to determine the minimum number of rounds (after the first round) that it will take for him to obtain a majority of the votes, assuming he is in 2nd place after round 1.

## 예제 입력 1
```
3
1 70 67
```

## 예제 출력 1
```
IMPOSSIBLE TO WIN
```

## 예제 입력 2
```
6
1 2 13 12 70 69
```

## 예제 출력 2
```
3
```

## 예제 입력 3
```
3
11 2 10
```

## 예제 출력 3
```
1
```

## 예제 입력 4
```
3
1 2 3
```

## 예제 출력 4
```
IMPOSSIBLE TO WIN
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 1 | Java 15 / 수정 | 14544 KB | 116 ms | 2111 B | 1달 전 |
