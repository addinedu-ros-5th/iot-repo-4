# iot-repo-2
IoT Project Team 4 repository. Smart city. 

***
## Smart City
<img src="https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=Python&logoColor=white"><img src="https://img.shields.io/badge/arduino-00878F?style=for-the-badge&logo=arduino&logoColor=white"><img src="https://img.shields.io/badge/amazonrds-527FFF?style=for-the-badge&logo=amazonrds&logoColor=white"><img src="https://img.shields.io/badge/mysql-4479A1?style=for-the-badge&logo=mysql&logoColor=white">

<img src="https://img.shields.io/badge/git-F05032?style=for-the-badge&logo=git&logoColor=white"><img src="https://img.shields.io/badge/github-181717?style=for-the-badge&logo=github&logoColor=white"><img src="https://img.shields.io/badge/confluence-172B4D?style=for-the-badge&logo=confluence&logoColor=white"><img src="https://img.shields.io/badge/jirasoftware-0052CC?style=for-the-badge&logo=jirasoftware&logoColor=white"><img src="https://img.shields.io/badge/slack-4A154B?style=for-the-badge&logo=slack&logoColor=white">

Implementation of a smart city centered on bus and garbage truck services by controlling the MCU with a PyQt-based GUI

### Team Member
<table>
  <tbody>
    <tr>
      <td align="center"><a href=""><img src="https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/ae17daa4-ec21-4cf5-95bb-fe201756e65c"width="100px;" alt="https://github.com/JangHyeongJun-0523"/><br /><sub><b>Jang Hyungjun <br/> Team Reader <br/> Confluence, Jira, <br/> Git, AWS RDS <br/> City A & B <br/> Presentation
      </b></sub></a><br /></td>
      <td align="center"><a href=""><img src="https://avatars.githubusercontent.com/u/163802905?v=4" width="100px;" alt=""/><br /><sub><b>Kang Jiyeon<br/> Member <br/> Bus <br/> PC ↔ MCU Network <br/><br/></b></sub></a><br /></td>
      <td align="center"><a href=""><img src="https://avatars.githubusercontent.com/u/163628109?v=4" width="100px;" alt=""/><br /><sub><b>Kim Yohan <br/> Member <br/>Bus Station<br/>GUI design<br/><br/></b></sub></a><br /></td>
      <td align="center"><a href=""><img src="https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/02e1768e-1df9-42db-9d9c-2c3880a6a324" width="100px;" alt=""/><br /><sub><b>Cho Sunghyun<br/> Member  <br/> Garbage Service <br/> PC ↔ MCU  Network <br/> GUI button <br/> </b></sub></a><br /></td><tr/>
  </tbody>
</table>

## Requirment & Design
### User Requirement

|No.|Function|Description|
|---|---|---|
|UR_B_01|버스 이동 기능|버스는 정해진 노선대로 이동한다.<br/>버스는 학교에 있는 정류장에서 출발한다.<br/>버스는 다른 방향으로 혹은 다른 경로로 이동할 수 없다.|
|UR_B_02|버스 정차 기능|버스는 정류장이 아닌 곳에서 정차할 수 없다.<br/>운행 중에 정류장에 도착하면 일시적으로 정차한 뒤, 출발한다.|
|UR_BS_01|버스 정류장 기능| 버스가 정류장에 도착하면 정류장의 문이 자동으로 열린다.|
|UR_GT_01|쓰레기 수거 차량 기능|쓰레기 수거 차량은 밤에만 운행한다.|
|UR_GT_02|쓰레기 수거 차량 기능|쓰레기 수거 차량은 쓰레기가 포화 상태일 때만 쓰레기를 수거한다.|
|UR_GT_03|쓰레기 수거 차량 기능|쓰레기를 수거하여 쓰레기 처리 시설에 도착하면, 쓰레기를 배출한다.|
|UR_GT_04|쓰레기 수거 차량 기능|쓰레기 배출 후 운행 종료<br/>운행 종료 시, 쓰레기장에서 대기한다.|
|UR_T_01|쓰레기통 기능|쓰레기 수거 차량이 도착하면 쓰레기를 수거 차량으로 투하한다.|
|UR_S_01|속도 측정 기능|지나가는 차량의 속도를 측정한다.|
|UR_TL_01|신호등 기능|신호등으로 불쾌지수를 표시한다.<br/>• 녹색 : 평온한 상태<br/>• 황색 : 불쾌지수가 일정 수준 상승한 상태<br/>• 적색 : 불쾌지수가 극도로 높아진 상태|
|UR_TL_02|신호등 기능|신호등은 초기 녹색 상태로 시작한다.|
|UR_TL_03|쓰레기통 상태에 따른 신호등 기능|신호등은 쓰레기통의 상태에 따라 다음의 규칙을 따른다.<br/>• 쓰레기통에 쓰레기가 쌓이기 시작하면 황색으로 상태를 표시하여 불쾌지수가 상승했음을 알린다.<br/>• 쓰레기통 포화 시, 적색으로 표시하여 불쾌지수가 극에 달았음을 알린다.<br/>• 포화된 쓰레기통이 비면 다시 녹색으로 신호등 상태를 변경하여 평온한 상태임을 표시한다.|
|UR_SL_01|가로등 기능|밝을 때는 가로등을 꺼진 상태로 유지하고 어두울 때는 가로등을 켠 상태로 유지한다.|
|UR_S_01|학교 종소리 기능|수업 시작을 알리는 종소리가 울린다.|
|UR_C_01|시계탑 기능|현재 시간을 표시한다.|
|UR_A_01|아파트 조명 기능|상시 활성화된 조명을 유지한다.|


### Software Requirement
|No.|Function|Description|R/O|Priority|
|---|---|---|---|---|
|SR_B_01|버스 이동 기능|버스는 학교 정류장에서 시작한다. <br/> 버스는 정류장에 도착하면 잠시 멈춘다.<br/>(정류장의 문이 닫힐 때까지 멈춰있는다.)|R|1|
|SR_BS_01|버스 정류장 기능|정류장에 버스가 감지되면 스크린 도어가 열린다.|R|1|
|SR_GT_01|쓰레기 수거 기능|쓰레기가 가득 찼을 때에만 수거를 진행한다.|R|1|
|SR_GT_02|쓰레기 배출 기능|수거한 쓰레기를 배출한다.|R|1|
|SR_GT_03|대기 기능|쓰레기 배출 후 쓰레기장에서 대기한다.|R|1|
|SR_T_01|투하 기능|쓰레기를 수거 차량으로 투하한다.|R|1|
|SR_S_01|속도 측정 기능|지나가는 차량의 속도를 측정한다.|R|1|
|SR_TL_01|불쾌지수 표시 기능|신호등으로 불쾌지수를 표시한다.<br/>• 녹색 : 평온한 상태<br/>• 황색 : 불쾌지수가 일정 수준 상승한 상태<br/>• 적색 : 불쾌지수가 극도로 높아진 상태|R|1|
|SR_TL_02|불쾌지수 표시 기능|신호등은 초기 상태는 녹색으로 표시한다.|R|1|
|SR_TL_03|불쾌지수 표시 기능|신호등은 쓰레기통의 상태에 따라 다음의 규칙을 따른다.<br/>• 쓰레기통에 쓰레기가 쌓이기 시작하면 황색으로 표시한다.<br/>• 쓰레기통 포화 시, 적색으로 표시한다.<br/>• 쓰레기통이 비면 녹색으로 표시한다.|R|1|
|SR_SL_01|불쾌지수 표시 기능|신호등으로 불쾌지수를 표시한다.<br/>• 녹색 : 평온한 상태<br/>• 황색 : 불쾌지수가 일정 수준 상승한 상태<br/>• 적색 : 불쾌지수가 극도로 높아진 상태|R|1|
|SR_TL_01|가로등 기능|낮에는 소등상태, 밤에는 점등상태를 유지한다.|R|1|
|SR_S_01|종소리 기능|수업 시작을 알리는 소리를 재생한다.|R|2|
|SR_C_01|시간 표시 기능|현재 시간을 표시한다.|R|2|
|SR_A_01|조명 기능|상시 활성화된 조명을 유지한다.|R|1|
|GUI-B-1|버스 위치 표시 기능|버스의 실시간 위치를 표시한다.|R|1|
|GUI-GT-01|쓰레기차 위치 표시 기능|쓰레기 수거 차량의 실시간 위치를 표시한다.|R|1|
|GUI-DI-01|불쾌지수 표시 기능|불쾌지수 신호등의 상태를 표시한다.|R|1|
|GUI-SL-01|가로등 제어 기능|장소별 가로등을 제어한다.|R|1|
|GUI-T-01|쓰레기통 상태 표시 기능|쓰레기통의 채워짐 상태를 표시한다.|R|1|
|GUI-SC-01|차량 속도 표시 기능|지나가는 차량의 측정된 속도를 표시한다.|R|1|


### City blueprint
![image](https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/7a46d366-527e-4b29-9f12-824b2a99ce78)

### Hardware
![image](https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/626fa5ce-fa8f-4f57-9c9c-efc305b3f646)


### System architecture
![image](https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/5485b494-4edc-42be-b05f-f26b17415997)


## Implement
### Bus flow chart 
![image](https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/bc4a6f50-c54a-42a4-8cec-2af8efe9e5fd)

### Bus error case
1. 통신 문제
    - 블루투스 : 연결은 성공했지만, 수신 문제를 해결하지 못함.
    - esp32보드 : 시간 부족
2. 라인 센서 문제
    - 오른쪽 라인 센서 둔감 문제로 인해 라인 인식이 잘 안됐음.
3. 전원 분배
    - 예상했던 것에 비해 많은 전원 필요


### Garbage truck flow chart 
![image](https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/32360b7b-843f-4777-bc50-85decde775ae)

### Garbage truck error case
1. 통신 문제
    - 블루투스 : 연결은 성공했지만, 수신 문제를 해결하지 못함.
    - esp32보드 : 시간 부족
2. 전원 분배
    - 예상했던 것에 비해 많은 전원 필요

### Bus station flow chart 
![image](https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/14533040-0024-4fa6-9044-cbe236094668)

### Bus station error case
1. 전원 분배
    - 스텝 모터 동작으로 인해 예상했던 것에 비해 많은 전원 필요

### Trash can flow chart 
![image](https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/b26a4df3-e434-4e82-9010-e9b871cd4e8c)

### Trash can error case
1. 시간 문제
    - 프로젝트 기간내 미완

### Speed enforcement flow chart 
![image](https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/bf02d02e-9635-44cd-9cdd-434935b2da36)

### Speed enforcement error case
1. 속도 측정 정확성 문제
    - 속도 측정 및 계산 과정에서 예외처리가 덜 되어 부정확한 결과 도출

### Clock Tower flow chart 
![image](https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/e7317ea0-aeee-47ec-9ca4-648a0f2a0ca3)


### School bell flow chart 
![image](https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/705a78c2-b55a-4cbf-9a31-2ec23dda681a)

### Street lamp & Apartment light flow chart 
![image](https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/15694d15-3d3a-4e69-af9c-60ca23572444)


### Discomfort index flow chart 
![image](https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/15d3fd7c-4224-4614-9faa-17967eb81598)

### Discomfort index error case
1. 전원 인가 문제
    - +, - 전원 구분 : Cathod, Anode 구분을 하지 않고 전원을 인가하여 작업에 차질

### GUI
![image](https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/b05138cc-f6c6-49f0-85c5-87f4e1c49895)

## Verification
|UR number|SR number|Function|Description|P/NP|
|---------|---------|--------|-----------|----|
|SR_B_01|B_TC_01|버스 이동 기능|버스는 학교 정류장에서 시작한다.<br/>버스는 정류장에 도착하면 잠시 멈춘다.<br/>(정류장의 문이 닫힐 때까지 멈춰있는다.)|P|
|SR_BS_01|BS_TC_01|버스 정류장 기능|정류장에 버스가 감지되면 스크린 도어가 열린다.|P|
|SR_GT_01|GT_TC_01|쓰레기 수거 기능|쓰레기가 가득 찼을 때에만 수거를 진행한다.|NP|
|SR_GT_02|GT_TC_02|쓰레기 배출 기능|수거한 쓰레기를 배출한다.|NP|
|SR_GT_03|GT_TC_03|대기 기능|쓰레기 배출 후 쓰레기장에서 대기한다.|P|
|SR_T_01|T_TC_01|투하 기능|쓰레기를 수거 차량으로 투하한다.|NP|
|SR_S_01|S_TC_01|쓰레기 수거 기능|쓰레기가 가득 찼을 때에만 수거를 진행한다.|NP|
|SR_GT_01|GT_TC_01|속도 측정 기능|지나가는 차량의 속도를 측정한다.|NP|
|SR_TL_01|TL_TC_01|불쾌지수 표시 기능|신호등으로 불쾌지수를 표시한다.<br/>• 녹색 : 평온한 상태<br/>• 황색 : 불쾌지수가 일정 수준 상승한 상태<br/>• 적색 : 불쾌지수가 극도로 높아진 상태|NP|
|SR_TL_02|TL_TC_02|불쾌지수 표시 기능|신호등은 초기 상태는 녹색으로 표시한다.|P|
|SR_TL_03|TL_TC_03|불쾌지수 표시 기능|신호등은 쓰레기통의 상태에 따라 다음의 규칙을 따른다.<br/>• 쓰레기통에 쓰레기가 쌓이기 시작하면 황색으로 표시한다.<br/>• 쓰레기통 포화 시, 적색으로 표시한다.<br/>• 쓰레기통이 비면 녹색으로 표시한다.|NP|
|SR_SL_01|SL_TC_01|가로등 기능|낮에는 소등상태, 밤에는 점등상태를 유지한다.|P|
|SR_S_01|S_TC_01|종소리 기능|수업 시작을 알리는 소리를 재생한다.|P|
|SR_C_01|C_TC_01|시간 표시 기능|현재 시간을 표시한다.|P|
|SR_A_01|A_TC_01|조명 기능|상시 활성화된 조명을 유지한다.|P|
|CT-1|GUI-B-1|버스 위치 표시 기능|버스의 실시간 위치를 표시한다.|NP|
|CT-2|GUI-GT-1|쓰레기차 위치 표시기능|쓰레기 수거 차량의 실시간 위치를 표시한다.|NP|
|CT-3|GUI-DI-1|신호등 상태 표시 기능|불쾌지수 신호등의 상태를 표시한다.|NP|
|CT-4|GUI-SL-1|가로등 제어기능|장소별 가로등을 제어한다.|P|
|CT-5|GUI-T-1|쓰레기통 상태 표시 기능|쓰레기통의 채워짐 상태를 표시한다.|NP|
|CT-5|GUI-SC-1|속도 표시 기능|지나가는 차량의 측정된 속도를 표시한다.|NP|

## Demonstation
### Bus service
https://drive.google.com/file/d/1TuCGNl52vYhs8kNk3kZVGenUzQXJIqdH/view?usp=sharing

### Garbage service
https://drive.google.com/file/d/1eJfoXkU7-yL1qbn8B0kzaFt5K2g6Cxdg/view?usp=sharing

### GUI - Street lamp control
https://drive.google.com/file/d/1LBMFSts0QBAFbuMC3PcCRIBle0IduBIh/view?usp=sharing