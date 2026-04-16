# [16587. Hierarchical Structure](https://www.acmicpc.net/problem/16587)

## 문제
Andi works in ACM (Association for Cool Magics). This company specializes in generating fun content for the internet, e.g., memes, jokes, games, etc. Although the working environment in ACM is fun and all employees are treated equal, a hierarchical structure of all the employees is still needed to keep the company run smoothly.


There are N employees in ACM, each with a unique ID ranging from 1 to N. Each employee has exactly one direct supervisor, except one person (usually referred as the “big boss” in ACM) who has no supervisor, thus, this hierarchical structure resembles a tree (in graph theory) rooted at the big boss, the highest level among all employees.


ACM has a rather interesting way to assign projects to its employees. When a project is said to be assigned to two employees a and b, then all the employees in the path between a and b in the tree hierarchical structure are also involved in this project. These employees along with a and b are known as the member of the project. It is common in any other company for the highest level member to lead the discussion in the group, but not within ACM. As ACM focuses on generating fun and creative ideas, the discussion should be led by someone who can understand any joke which pops up during the discussion, thus, they agree that the discussion is to be led by someone whose age is between l and r (inclusive). Andi is wondering, among the employees who might lead the discussion, what is the sum of the ages? It is also possible that no employee might be able to lead the discussion, in which the sum is 0.


Given the hierarchical structure of ACM and Q queries. Each query is in the form of a, b, l, and r representing two employees to whom a project is assigned and the age range. Your task for each query is to find the sum of the ages of the employees involved in the project whose age is between l and r (inclusive).

## 예제 입력 1
```
8 5
80 40 60 50 20 10 70 10
1 2
1 3
1 4
2 5
2 6
4 7
4 8
5 7 30 60
6 8 20 30
8 6 10 100
1 3 70 70
7 3 30 70
```

## 예제 출력 1
```
90
0
190
0
180
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 5 | Java 11 / 수정 | 173660 KB | 2584 ms | 4226 B | 5달 전 |
