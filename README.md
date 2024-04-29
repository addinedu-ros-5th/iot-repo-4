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
|UR_B_01|버스 이동 기능|버스는 정해진 노선대로 이동한다.|
|테스트1|테스트2|테스트3|
|테스트1|테스트2|테스트3|
|테스트1|테스트2|테스트3|
|테스트1|테스트2|테스트3|
|테스트1|테스트2|테스트3|
|테스트1|테스트2|테스트3|


### Software Requirement
|No.|Function|Description|R/O|Priority|
|---|---|---|---|---|
|SR_B_01|버스 이동 기능|버스는 학교 정류장에서 시작한다. <br/> 버스는 정류장에 도착하면 잠시 멈춘다.<br/>(정류장의 문이 닫힐 때까지 멈춰있는다.)|R|1|
|SR_BS_01|버스 정류장 기능|정류장에 버스가 감지되면 스크린 도어가 열린다.|R|1|
|SR_BS_01|버스 정류장 기능|정류장에 버스가 감지되면 스크린 도어가 열린다.|R|1|
|SR_BS_01|버스 정류장 기능|정류장에 버스가 감지되면 스크린 도어가 열린다.|R|1|
|SR_BS_01|버스 정류장 기능|정류장에 버스가 감지되면 스크린 도어가 열린다.|R|1|
|SR_BS_01|버스 정류장 기능|정류장에 버스가 감지되면 스크린 도어가 열린다.|R|1|
|SR_BS_01|버스 정류장 기능|정류장에 버스가 감지되면 스크린 도어가 열린다.|R|1|
|SR_BS_01|버스 정류장 기능|정류장에 버스가 감지되면 스크린 도어가 열린다.|R|1|


### City blueprint
![image](https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/7a46d366-527e-4b29-9f12-824b2a99ce78)

### Hardware
![image](https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/626fa5ce-fa8f-4f57-9c9c-efc305b3f646)

### Software


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
2. 라인 센서 문제
    - 오른쪽 라인 센서 둔감 문제로 인해 라인 인식이 잘 안됐음.
3. 전원 분배
    - 예상했던 것에 비해 많은 전원 필요

### Bus station flow chart 
![image](https://github.com/addinedu-ros-5th/iot-repo-4/assets/70615068/14533040-0024-4fa6-9044-cbe236094668)

### Bus station error case
1. 통신 문제
    - 블루투스 : 연결은 성공했지만, 수신 문제를 해결하지 못함.
    - esp32보드 : 시간 부족
2. 라인 센서 문제
    - 오른쪽 라인 센서 둔감 문제로 인해 라인 인식이 잘 안됐음.
3. 전원 분배
    - 예상했던 것에 비해 많은 전원 필요

### Trash can flow chart 
![image]()

### Trash can error case
1. 통신 문제
    - 블루투스 : 연결은 성공했지만, 수신 문제를 해결하지 못함.
    - esp32보드 : 시간 부족
2. 라인 센서 문제
    - 오른쪽 라인 센서 둔감 문제로 인해 라인 인식이 잘 안됐음.
3. 전원 분배
    - 예상했던 것에 비해 많은 전원 필요

### Speed enforcement flow chart 
![image]()

### Speed enforcement error case
1. 통신 문제
    - 블루투스 : 연결은 성공했지만, 수신 문제를 해결하지 못함.
    - esp32보드 : 시간 부족
2. 라인 센서 문제
    - 오른쪽 라인 센서 둔감 문제로 인해 라인 인식이 잘 안됐음.
3. 전원 분배
    - 예상했던 것에 비해 많은 전원 필요

### Clock Tower flow chart 
![image]()

### Speed enforcement error case
1. 통신 문제
    - 블루투스 : 연결은 성공했지만, 수신 문제를 해결하지 못함.
    - esp32보드 : 시간 부족
2. 라인 센서 문제
    - 오른쪽 라인 센서 둔감 문제로 인해 라인 인식이 잘 안됐음.
3. 전원 분배
    - 예상했던 것에 비해 많은 전원 필요

### School bell flow chart 
![image]()

### School bell error case
1. 통신 문제
    - 블루투스 : 연결은 성공했지만, 수신 문제를 해결하지 못함.
    - esp32보드 : 시간 부족
2. 라인 센서 문제
    - 오른쪽 라인 센서 둔감 문제로 인해 라인 인식이 잘 안됐음.
3. 전원 분배
    - 예상했던 것에 비해 많은 전원 필요

### Street lamp & Apartment light flow chart 
![image]()

### Street lamp & Apartment light error case
1. 통신 문제
    - 블루투스 : 연결은 성공했지만, 수신 문제를 해결하지 못함.
    - esp32보드 : 시간 부족
2. 라인 센서 문제
    - 오른쪽 라인 센서 둔감 문제로 인해 라인 인식이 잘 안됐음.
3. 전원 분배
    - 예상했던 것에 비해 많은 전원 필요


### Discomfort index flow chart 
![image]()

### Discomfort index error case
1. 전원 인가 문제
    - 블루투스 : 연결은 성공했지만, 수신 문제를 해결하지 못함.

### Data base

### GUI

## Verification
### Embedded check
|UR number|SR number|Function|Description|P/NP|
|---------|---------|--------|-----------|----|
|SR_B_01|B_TC_01|버스 이동 기능|버스는 학교 정류장에서 시작한다.<br/>버스는 정류장에 도착하면 잠시 멈춘다.<br/>(정류장의 문이 닫힐 때까지 멈춰있는다.)|P|
|SR_BS_01|BS_TC_01|버스 정류장 기능|정류장에 버스가 감지되면 스크린 도어가 열린다.|P|
|SR_GT_01|GT_TC_01|쓰레기 수거 기능|쓰레기가 가득 찼을 때에만 수거를 진행한다.|NP|
|SR_GT_01|GT_TC_01|쓰레기 수거 기능|쓰레기가 가득 찼을 때에만 수거를 진행한다.|NP|
|SR_GT_01|GT_TC_01|쓰레기 수거 기능|쓰레기가 가득 찼을 때에만 수거를 진행한다.|NP|
|SR_GT_01|GT_TC_01|쓰레기 수거 기능|쓰레기가 가득 찼을 때에만 수거를 진행한다.|NP|
|SR_GT_01|GT_TC_01|쓰레기 수거 기능|쓰레기가 가득 찼을 때에만 수거를 진행한다.|NP|
|SR_GT_01|GT_TC_01|쓰레기 수거 기능|쓰레기가 가득 찼을 때에만 수거를 진행한다.|NP|
|SR_GT_01|GT_TC_01|쓰레기 수거 기능|쓰레기가 가득 찼을 때에만 수거를 진행한다.|NP|

### GUI check
|UR number|SR number|Description|P/NP|
|---------|---------|-----------|----|
|CT-1|T-1|버스의 실시간 위치를 표시한다.|NP|
|CT-1|T-1|버스의 실시간 위치를 표시한다.|NP|
|CT-1|T-1|버스의 실시간 위치를 표시한다.|NP|
|CT-1|T-1|버스의 실시간 위치를 표시한다.|NP|
|CT-1|T-1|버스의 실시간 위치를 표시한다.|NP|

## Demonstation
### Bus

### Garbage truck

### GUI - Street lamp control

