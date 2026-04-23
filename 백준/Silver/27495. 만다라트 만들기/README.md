# [27495. 만다라트 만들기](https://www.acmicpc.net/problem/27495)

## 문제
우주는 만다라트를 활용하여 새해 계획표를 만들기로 했다.


만다라트는 3x3 행렬을 가로로 3개, 세로로 3개씩 배치해 9x9 행렬로 만든 표이다. 만다라트를 만들기 위해서는 먼저 아래와 같이 목표를 만들어야 한다.




최종 목표를 1개 만든다.


최종 목표를 이루기 위해서 도움이 되는 중간 목표를 8개 만든다.


각각의 중간 목표를 이루는데 도움이 되는 세부 목표를 8개씩 만든다.




이 목표들을 가지고 만다라트를 만드는 방법은 다음과 같다.




9x9 행렬을 3x3 행렬 9개로 구분한다.


9x9 행렬에서 중앙에 위치하는 3x3 행렬을 채운다. 최종 목표는 행렬의 가장 가운데에 작성하고, 중간 목표 8개는 나머지 8칸에 하나씩 작성한다.


중앙 3x3 행렬을 제외하고 나머지 3x3 행렬의 가운데에 중간 목표를 다시 적는다. 단, 중앙에 위치하는 3x3 행렬내에서 중간 목표가 위치하는 방향과 9x9 행렬 내에서 같은 중간 목표가 작성된 3x3 행렬이 위치하는 방향은 동일해야 한다. 예를 들어, 중앙 3x3 행렬 내에서 "건강"이라는 중간 목표를 최종 목표의 우상단에 작성했다면, "건강"을 중심으로 하는 3x3 행렬은 9x9 행렬 내에서 우상단에 위치해야 한다.


3x3 행렬의 빈칸들을 세부 목표로 채운다. 중심에 쓰인 중간 목표를 이루는 데 도움이 되는 세부 목표 8개를 8칸에 하나씩 작성한다.




아래는 완성된 만다라트의 예시이다.




하지만 아무도 우주의 계획표를 알아보지 못했고, 우주는 만다라트를 쉽게 풀어서 써주기로 했다. 쉽게 쓰인 계획표는 이렇게 만들어진다. 먼저 중간 목표를 하나 출력하고, 그 아래로 8개의 세부 목표를 출력한다. 이를 8번 반복하여 8개의 중간 목표와 그 아래의 세부 목표들을 모두 출력한다. 이 때, 중간 목표끼리는 사전순으로 정렬되어 있어야 하며, 중간 목표 아래의 세부 목표 8개도 사전순으로 정렬되어 있어야 한다. 목표 a가 목표 b보다 사전순으로 앞에 오는 경우는 다음과 같다.




숫자가 알파벳보다 사전순으로 빠르다.


알파벳 대문자가 알파벳 소문자보다 사전순으로 빠르다.


길이가 i인 목표와 길이가 i+1인 목표가 존재하며 두 목표의 0~i번째 인덱스까지의 문자가 동일한 경우, 길이 i인 목표가 사전순으로 빠르다. 예를 들어서, 목표 "ab"가 목표 "abc"보다 사전순으로 빠르다.

## 예제 입력 1
```
s11 s12 s13 s21 s22 s23 s31 s32 s33
s18 m1 s14 s28 m2 s24 s38 m3 s34
s17 s16 s15 s27 s26 s25 s37 s36 s35
s81 s82 s83 m1 m2 m3 s41 s42 s43
s88 m8 s84 m8 f m4 s48 m4 s44
s87 s86 s85 m7 m6 m5 s47 s46 s45
s71 s72 s73 s61 s62 s63 s51 s52 s53
s78 m7 s74 s68 m6 s64 s58 m5 s54
s77 s76 s75 s67 s66 s65 s57 s56 s55
```

## 예제 출력 1
```
#1. m1
#1-1. s11
#1-2. s12
#1-3. s13
#1-4. s14
#1-5. s15
#1-6. s16
#1-7. s17
#1-8. s18
#2. m2
#2-1. s21
#2-2. s22
#2-3. s23
#2-4. s24
#2-5. s25
#2-6. s26
#2-7. s27
#2-8. s28
#3. m3
#3-1. s31
#3-2. s32
#3-3. s33
#3-4. s34
#3-5. s35
#3-6. s36
#3-7. s37
#3-8. s38
#4. m4
#4-1. s41
#4-2. s42
#4-3. s43
#4-4. s44
#4-5. s45
#4-6. s46
#4-7. s47
#4-8. s48
#5. m5
#5-1. s51
#5-2. s52
#5-3. s53
#5-4. s54
#5-5. s55
#5-6. s56
#5-7. s57
#5-8. s58
#6. m6
#6-1. s61
#6-2. s62
#6-3. s63
#6-4. s64
#6-5. s65
#6-6. s66
#6-7. s67
#6-8. s68
#7. m7
#7-1. s71
#7-2. s72
#7-3. s73
#7-4. s74
#7-5. s75
#7-6. s76
#7-7. s77
#7-8. s78
#8. m8
#8-1. s81
#8-2. s82
#8-3. s83
#8-4. s84
#8-5. s85
#8-6. s86
#8-7. s87
#8-8. s88
```

## 예제 입력 2
```
CareTheBody TakeSupplements FSQ90kg ImproveInStep StrengthenTheBodyCore1 StabilizeThePivot CreateAnAngle HitTheBallFromAbove StrengthenTheWrist
Flexibility Physical RSQ130kg StabilizeTheReleasePoint Control GetRidOfUneasyFeelings DoNotTenseUp Precision TheLowerBodyLeads
Stamina RangeOfMotion1 Meals StrengthenTheLowerExtremities1 DontOpenTheBody ControlMental ReleaseTheBallInTheFront IncreaseTheNumberOfRotations RangeOfMotion2
HaveDearGoalsAndPurposes DoNotSwingJoyAndSorrow CoolHeadAndHotPassion Physical Control Precision TurnAtThePivot StrengthenTheLowerExtremities2 GainWeight
BeStrongAtPinches Mental DontSwayByAtmosphere Mental DraftNo1 Speed160kmhr StrengthenTheBodyCore2 Speed160kmhr StrengthenAroundTheShoulders
DontCreateUpsAndDowns TenacityForVictory TheHeartToCareTeamMates Personality Luck CurveBalls RangeOfMotion3 CatchLinerBalls IncreasePitching
Sensitivity WorthyToBeLoved PlanAhead Greetings PickingTrashes CleanTheRoom IncreaseCoundBalls PrecisionForkBalls PrecisionOfSliders
Caring Personality Gratitude UseTheToolsWithCare Luck AttitudeForJudges CurveBallsWithSpeed CurveBalls DecisiveBallsForLeftBatter
WellMannered WorthyToBeTrusted SustainedEfforts PositiveThinking WorthyToBeSupported ReadBooks PitchWithTheSameAsStraight ControlFromStrikeIntoBall ImagineTheDepth
```

## 예제 출력 2
```
#1. Control
#1-1. ControlMental
#1-2. DontOpenTheBody
#1-3. GetRidOfUneasyFeelings
#1-4. ImproveInStep
#1-5. StabilizeThePivot
#1-6. StabilizeTheReleasePoint
#1-7. StrengthenTheBodyCore1
#1-8. StrengthenTheLowerExtremities1
#2. CurveBalls
#2-1. ControlFromStrikeIntoBall
#2-2. CurveBallsWithSpeed
#2-3. DecisiveBallsForLeftBatter
#2-4. ImagineTheDepth
#2-5. IncreaseCoundBalls
#2-6. PitchWithTheSameAsStraight
#2-7. PrecisionForkBalls
#2-8. PrecisionOfSliders
#3. Luck
#3-1. AttitudeForJudges
#3-2. CleanTheRoom
#3-3. Greetings
#3-4. PickingTrashes
#3-5. PositiveThinking
#3-6. ReadBooks
#3-7. UseTheToolsWithCare
#3-8. WorthyToBeSupported
#4. Mental
#4-1. BeStrongAtPinches
#4-2. CoolHeadAndHotPassion
#4-3. DoNotSwingJoyAndSorrow
#4-4. DontCreateUpsAndDowns
#4-5. DontSwayByAtmosphere
#4-6. HaveDearGoalsAndPurposes
#4-7. TenacityForVictory
#4-8. TheHeartToCareTeamMates
#5. Personality
#5-1. Caring
#5-2. Gratitude
#5-3. PlanAhead
#5-4. Sensitivity
#5-5. SustainedEfforts
#5-6. WellMannered
#5-7. WorthyToBeLoved
#5-8. WorthyToBeTrusted
#6. Physical
#6-1. CareTheBody
#6-2. FSQ90kg
#6-3. Flexibility
#6-4. Meals
#6-5. RSQ130kg
#6-6. RangeOfMotion1
#6-7. Stamina
#6-8. TakeSupplements
#7. Precision
#7-1. CreateAnAngle
#7-2. DoNotTenseUp
#7-3. HitTheBallFromAbove
#7-4. IncreaseTheNumberOfRotations
#7-5. RangeOfMotion2
#7-6. ReleaseTheBallInTheFront
#7-7. StrengthenTheWrist
#7-8. TheLowerBodyLeads
#8. Speed160kmhr
#8-1. CatchLinerBalls
#8-2. GainWeight
#8-3. IncreasePitching
#8-4. RangeOfMotion3
#8-5. StrengthenAroundTheShoulders
#8-6. StrengthenTheBodyCore2
#8-7. StrengthenTheLowerExtremities2
#8-8. TurnAtThePivot
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 3 | C++17 / 수정 | 2164 KB | 0 ms | 909 B | 3년 전 |
