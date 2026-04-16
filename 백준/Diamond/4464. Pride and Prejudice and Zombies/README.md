# [4464. Pride and Prejudice and Zombies](https://www.acmicpc.net/problem/4464)

## 문제
Pride and Prejudice and Zombies, by Jane Austen and Seth Grahame-Smith, spices up the famous 1813 satire about marriage and social convention with intercalary appearances by zombies, skunks, ghouls, chipmunks and ninjas. Most literary critics praised PPZ (as it’s known on Facebook) as “clever”, “insightful”, holding “indomitable appeal”, although Macy Halford of The New Yorker condemned Mr. Grahame-Smith’s retelling as “awful”, and “one hundred per cent terrible”. 


Here’s a little known fact: the book’s release was delayed by some 8 years due to several heated disagreements between Mr. Grahame-Smith and the editors at Quirk Books, the small publishing house in Philadelphia that eventually published the novel. The most impassioned of the arguments centered on the controversial “Vampire Number” chapter, where Mrs. Bennett — desperate to rally the English countryside’s interest in matrimony — contrives a social event where 50 men and 50 women draw slips of paper from a large, feathery hat. “It is an axiom generally acknowledged, that a single man in possession of the complementary multiplicand, must be in want of a wife”, says Mrs. Bennett in announcing the event. On each slip of paper is a single three-digit number. The goal of the event was for each of the women to find the man whose three-digit number, when multiplied by her own, produced a six-digit number that reproduced the digits of the two “multiplicands” (Mrs. Bennett’s word) with the correct “distribution” (also her word) in some order. 


Mr. Grahame-Smith insisted the chapter was vital to the story arc, whereas Quirk Books considered it forced, obscure, boring, and unnecessarily intellectual. Furthermore, Quirk Books was initially contemplating a limited New England release and argued that no one outside of the Pacific Northwest understood math. Mr. Grahame-Smith eventually conceded this to be true, and agreed to cut the chapter. The chapter’s existence only surfaced recently in a follow-up article in The New Yorker where Ms. Halford noted the novel would have “benefitted substantially” had it been included. 


Vampire Numbers


It is generally acknowledged that Vampire numbers are positive integers with an even number — we’ll say 2n — of digits where the 2n digits can be distributed across two n-digit numbers such that their product equals the original 2n-digit number. None of the three numbers can include leading zeroes, and neither of the two n-digit numbers can have consecutive zeroes anywhere. 


For examples:




125460 = 204 x 615 (so 125460 is a Vampire number).


16758243290880 = 1982736 x 8452080 (so 16758243290880 is a Vampire number).


353 has an odd number of digits, so it can’t be a Vampire number by definition.


3421 can’t be subdivided properly, so it’s not a Vampire number either.




Write a program that reads in a series of numbers (each at most 18 digits) and prints whether or not that number is a Vampire number.

## 예제 입력 1
```
1260
6880
8680
102510
108135
110758
115672
116725
125248
12054060
13078260
46847902
46847921
1001795850
315987404670
472812953760
10174695862032
10174695862037
2512099504480801
8186379410403769
170147428389340249
189598345243224241
968781726110944201
968781726110944203
698781726110944201
0
```

## 예제 출력 1
```
1260: yes
6880: yes
8680: no
102510: yes
108135: yes
110758: yes
115672: yes
116725: yes
125248: yes
12054060: yes
13078260: yes
46847902: no
46847921: no
1001795850: yes
315987404670: yes
472812953760: yes
10174695862032: yes
10174695862037: no
2512099504480801: yes
8186379410403769: yes
170147428389340249: yes
189598345243224241: yes
968781726110944201: yes
968781726110944203: no
698781726110944201: no
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 5 | C++17 / 수정 | 2036 KB | 136 ms | 2885 B | 1년 전 |
