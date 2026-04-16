# [34427. paintbucket](https://www.acmicpc.net/problem/34427)

## 문제
After pulling a wrong lever in the lab, you find yourself traveling through time and space. At some point while traveling, you passed out and have now awoken in an office. Around you are plenty of old computers. The person in charge comes over and helps you out. They tell you it's the year 1985 and that you're in the office for some computing company. They're creating a painting program for a new operating system and are struggling to create the latest feature. The person in charge gives you some more information:


"We need your help to create a computer program that implements what we will call the paint bucket. Given an image filled with colors and the location of a click, you need to output a list of coordinates that will be colored by the paint bucket."


"Here is an example. If the user were to click on the upper left red pixel with the paint bucket in Figure 1 (e.g., the user is requesting the red pixels be changed to green), then all of the green pixels in Figure 2 are the ones that would get colored."




Figure 1
: The image before the user clicked on the upper left red pixel.




Figure 2
: The image after the user clicked, to change several red pixels to green pixels.


"Here is a more formal description. If the user clicks on a pixel with color $c$, the paint bucket should color every pixel in the same 'group' as the pixel they clicked on. Any two pixels are in the same group if you can draw a path that walks across adjacent pixels while only stepping on pixels of color $c$. You can NOT take diagonal steps. Thus, in our example in the figures, note how all of the red pixels that became green are in the same group. Likewise, all of the blue pixels are in another group and each red pixel that did not change is in a group of its own."


Since you haven't made any plans for today, you decide to stick around and help out this company.

## 예제 입력 1
```
5 5 0 0
0 0 0 0 1
0 0 0 1 0
0 0 1 0 0
0 1 0 0 0
1 0 0 0 0
```

## 예제 출력 1
```
0 0
1 0
2 0
3 0
0 1
1 1
2 1
0 2
1 2
0 3
```

## 예제 입력 2
```
5 5 3 2
7 7 7 7 7
7 7 7 1 7
7 7 1 1 1
7 7 7 1 7
7 7 7 7 7
```

## 예제 출력 2
```
3 1
2 2
3 2
4 2
3 3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 5 | C++17 / 수정 | 22256 KB | 288 ms | 673 B | 6달 전 |
