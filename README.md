# Energy-Meter-Monitoring-System
## 1. Introduction:
The Energy Meter Monitoring System is designed to read data from an L&T WL 4405 energy meter connected through Modbus protocol via an RS485 to TTL converter controller. The system displays 28 parameters related to 3-phase energy consumption on a cloud-based webpage and mobile application. Additionally, it sends emergency messages such as overvoltage, undervoltage, and overcurrent alerts via SMS to predefined mobile numbers. Users can also set maximum voltage, minimum voltage, and maximum current values through both the mobile app and webpage interfaces.

![Screenshot 2024-04-23 115407](https://github.com/Daniel4bit/-Energy-Meter-Monitoring-System/assets/65249875/2f28f7b3-145b-4c04-a331-be4287b9ac11)
![Screenshot 2024-04-23 114526](https://github.com/Daniel4bit/-Energy-Meter-Monitoring-System/assets/65249875/550bb7a1-67e8-4d2b-bb00-3e180e7b0e34)
![basic-mfm-wc4405](https://github.com/Daniel4bit/-Energy-Meter-Monitoring-System/assets/65249875/80617846-be63-4167-96b8-97def04ec5f7)
![Screenshot 2024-04-23 115445](https://github.com/Daniel4bit/-Energy-Meter-Monitoring-System/assets/65249875/151441b7-8fd4-426e-a0dc-10b440cb57c8)

## 2. System Architecture:
### The system comprises the following components:
![Screenshot 2024-04-23 113625](https://github.com/Daniel4bit/-Energy-Meter-Monitoring-System/assets/65249875/e05b5a12-4216-43a8-bbfd-886fd5b94e27)

* L&T WL 4405 Energy Meter
* RS485 to TTL Converter
* Microcontroller (e.g., Arduino, Raspberry Pi)
* GPRS Module for Internet Connectivity
* Cloud Server for Data Storage and Hosting
* Webpage Interface
* Mobile Application (iOS/Android)
* SMS Gateway for Emergency Alerts

## 3. Implementation:

* The energy meter is connected to the microcontroller via the RS485 to TTL converter.
* The microcontroller reads data from the energy meter using Modbus protocol.
* Data is processed and sent to the cloud server using GPRS connectivity.
* The cloud server hosts a webpage interface where users can monitor the following parameters:
  
**1. Watts Total
2. Watts per Phase (R, Y, B)
3. Power Factor (Average and per Phase)
4. Volt-Amperes (VA) Total and per Phase
5. Voltage (Line-Line Average and per Phase)
6. Voltage (Phase-Neutral Average and per Phase)
7. Current (Total and per Phase)
8. Frequency
9. Energy Consumption (Wh, VAh, Load Hours)**
  
* A mobile application is developed for both iOS and Android platforms, providing users with remote access to energy meter data and emergency alert settings.
* Users can input their mobile numbers in the app/webpage for receiving emergency SMS alerts.
* The system continuously monitors voltage and current values and triggers emergency alerts when predefined thresholds are exceeded.
  
## 4. Features:

* Real-time monitoring of 28 parameters related to 3-phase energy consumption.
* Cloud-based storage for data accessibility from anywhere.
* Mobile app for remote monitoring and control.
* Emergency alert system for overvoltage, undervoltage, and overcurrent events.
* User-configurable settings for maximum voltage, minimum voltage, and maximum current.
* Secure login/authentication for accessing the system.
  
## 5. Benefits:

* Enhanced monitoring and control of energy consumption.
* Early detection of potential faults or irregularities in the electrical system.
* Remote access to energy meter data, facilitating informed decision-making.
* Timely emergency alerts help prevent damage to electrical equipment and ensure safety.


## 6. Conclusion:
The Energy Meter Monitoring System provides a comprehensive solution for monitoring 3-phase energy consumption and ensuring the safety and efficiency of electrical systems. By leveraging cloud-based technology, mobile accessibility, and real-time alerts, the system empowers users with valuable insights and control over their energy usage. With future enhancements and continuous improvements, the system can further optimize energy management and contribute to sustainable practices.
