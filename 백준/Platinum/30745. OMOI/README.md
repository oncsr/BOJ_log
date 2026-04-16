# [30745. OMOI](https://www.acmicpc.net/problem/30745)

## 문제
Organization of Meticulous Oil Inspectors (OMOI) is an association of $n$ oil inspectors of the city N. All oil inspectors in the organization are numbered successively from $1$ to $n$ in the order of joining the OMOI. There is a tree-like hierarchy among the OMOI members so that the oil inspector $1$ is the head of OMOI, and every other oil inspector $i$ has an 
immediate supervisor
 $p_i$ who joined OMOI prior to $i$, that is, has a smaller number. An oil inspector $v$ is a 
supervisor
 of an oil inspector $u$ if $v$ is present in the chain of immediate supervisors starting at $u$, that is, in the sequence $p_u$, $p_{p_u}$, and so on. In this case, the oil inspector $u$ is a 
subordinate
 of the oil inspector $v$.


All members of OMOI are very meticulous, and it is not uncommon for them to argue on business questions. We assume that two oil injectors may argue only if none of them is a supervisor of the other. To resolve their dispute, arguing oil inspectors ask their 
closest common supervisor
 for advice, that is, an oil inspector who is their common supervisor with the largest number. Every oil inspector $i$ (expect for the head of OMOI) has a 
perfectionism level
 that is expressed with an integer $c_i$. 
Intensity
 of an argument between two oil inspectors is the sum of their perfectionism levels. Finally, 
tension
 of a working day is the total intensity of all arguments during the day.


At the end of a working day an oil inspector $v$ thinks himself an 
effective manager
 if for each one of his subordinates he resolved at least one argument involving this subordinate during the day. Formally, that means that for each oil inspector $u$ who is a subordinate of $v$ there is an oil inspector $w$ such that $u$ and $w$ had an argument during the day, and $v$ was the closest common supervisor of $u$ and $w$. In particular, every oil inspector who does not have any subordinates thinks himself an effective manager according to this definition.


You are employed at OMOI as a programmer, and know every oil inspector in the organization. At the end of today's workday every oil inspector in the organization told you in confidence that he thought himself an effective manager on this day. You are now interested what could be the smallest tension of today's workday if every oil inspector indeed was an effective manager today.

## 예제 입력 1
```
5
1 2 2 1
1 1 1 1
```

## 예제 출력 1
```
8
```

## 예제 입력 2
```
6
1 1 1 4 4
1 2 3 4 5
```

## 예제 출력 2
```
25
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 4 | Java 11 / 수정 | 89848 KB | 576 ms | 1858 B | 1년 전 |
