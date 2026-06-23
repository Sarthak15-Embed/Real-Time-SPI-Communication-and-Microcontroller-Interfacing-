# Real-Time SPI Communication and Microcontroller Interfacing

![C Language](https://img.shields.io/badge/Language-C-blue)
![Embedded Systems](https://img.shields.io/badge/Domain-Embedded%20Systems-green)
![SPI Protocol](https://img.shields.io/badge/Protocol-SPI-orange)
![ARM7](https://img.shields.io/badge/Master-ARM7%20LPC2148-red)
![PIC16F877A](https://img.shields.io/badge/Slave-PIC16F877A-purple)

## Project Overview

This project demonstrates **real-time SPI communication between ARM7 LPC2148 and PIC16F877A**.

In this system, the **ARM7 LPC2148 works as SPI Master** and reads ADC data. The ADC value is transmitted through SPI to the **PIC16F877A configured as SPI Slave**. Whenever the ADC value changes on the master side, the received value also changes on the PIC side in real time.

This project focuses on microcontroller-to-microcontroller communication, SPI peripheral configuration, real-time data transfer, and embedded firmware debugging.

---

## Key Features

* ARM7 LPC2148 configured as SPI Master
* PIC16F877A configured as SPI Slave
* Real-time ADC data transfer using SPI
* Master-to-slave microcontroller interfacing
* Register-level Embedded C implementation
* Hardware-level firmware testing
* Suitable for learning SPI protocol and MCU communication

---

## Hardware Used

| Component                    | Purpose                               |
| ---------------------------- | ------------------------------------- |
| ARM7 LPC2148                 | SPI Master and ADC value source       |
| PIC16F877A                   | SPI Slave and received data processor |
| Potentiometer / Analog Input | ADC input to LPC2148                  |
| LEDs / LCD                   | Output indication on PIC side         |
| Jumper Wires                 | SPI connections                       |
| 5V / 3.3V Supply             | Power supply                          |
| Common Ground                | Required for SPI communication        |

---

## Software Used

* Keil uVision for ARM7 LPC2148
* MPLAB X IDE for PIC16F877A
* XC8 Compiler
* Embedded C

---

## System Architecture

```text
Analog Input / Potentiometer
            |
            v
+----------------------+
| ARM7 LPC2148         |
| SPI Master           |
| ADC Read + SPI Send  |
+----------------------+
     |   |   |   |
     |   |   |   |
     v   v   v   v
   SCK MOSI MISO SSEL
     |   |   |   |
     v   v   v   v
+----------------------+
| PIC16F877A           |
| SPI Slave            |
| SPI Receive + Output |
+----------------------+
            |
            v
      LED / LCD Output
```

---

## Microcontroller Connection Diagram

### SPI Pin-to-Pin Connections

| ARM7 LPC2148 Master Pin | Signal     | PIC16F877A Slave Pin | Description                    |
| ----------------------- | ---------- | -------------------- | ------------------------------ |
| P0.4                    | SCK0       | RC3 / SCK            | SPI Clock from Master to Slave |
| P0.5                    | MOSI0      | RC5 / SDO            | Master Out Slave In            |
| P0.6                    | MISO0      | RC4 / SDI            | Master In Slave Out            |
| P0.7                    | SSEL0 / CS | RA5 / SS             | Slave Select                   |
| GND                     | GND        | GND                  | Common Ground                  |

> Common ground between LPC2148 and PIC16F877A is mandatory for reliable SPI communication.

---

## Important Voltage Note

ARM7 LPC2148 works at **3.3V logic**, while PIC16F877A commonly works at **5V logic**.

For real hardware testing, use proper voltage-level compatibility or level shifting, especially on signals going from PIC to LPC2148.

Recommended:

* LPC2148 MOSI/SCK/CS to PIC input may work depending on logic threshold.
* PIC MISO output to LPC2148 input should be protected using a level shifter or voltage divider.

---

## Working Principle

1. LPC2148 reads analog input using ADC.
2. ADC value is converted into digital form.
3. LPC2148 sends the ADC value to PIC16F877A using SPI.
4. PIC16F877A receives the data as SPI Slave.
5. Output on PIC side changes according to received value.
6. When the ADC input changes on LPC2148 side, the PIC output updates in real time.

---

## SPI Communication Flow

```text
Start
  |
Initialize LPC2148 ADC
  |
Initialize LPC2148 SPI as Master
  |
Initialize PIC16F877A SPI as Slave
  |
Read ADC Value on LPC2148
  |
Send ADC Data through SPI
  |
Receive Data on PIC16F877A
  |
Update Output
  |
Repeat Continuously
```

---

## Project Structure

```text
Real-Time-SPI-Communication-and-Microcontroller-Interfacing-
│
├── README.md
│
├── Master
│   └── LPC2148 Master SPI + ADC Code
│
├── ADC_SPI_RX.X
│   └── PIC16F877A Slave SPI Receiver Code
│
└── Arm7_SPI Result.JPG
    └── Hardware / Output Result Image
```

---

## LPC2148 Master Role

The LPC2148 performs the following tasks:

* Initializes ADC peripheral
* Reads analog input value
* Initializes SPI0 as Master
* Generates SPI clock
* Sends ADC data to PIC16F877A
* Controls chip select/slave select signal

---

## PIC16F877A Slave Role

The PIC16F877A performs the following tasks:

* Initializes SPI module in Slave mode
* Waits for data from LPC2148
* Receives SPI data
* Processes received ADC value
* Updates output based on received data

---

## SPI Signals Explanation

| Signal  | Full Form                  | Direction             |
| ------- | -------------------------- | --------------------- |
| SCK     | Serial Clock               | Master to Slave       |
| MOSI    | Master Out Slave In        | LPC2148 to PIC16F877A |
| MISO    | Master In Slave Out        | PIC16F877A to LPC2148 |
| SS / CS | Slave Select / Chip Select | Master to Slave       |

---

## Result Image

```markdown
![SPI Communication Result](Arm7_SPI%20Result.JPG)
```

Output image:

![SPI Communication Result](Arm7_SPI%20Result.JPG)

---

## Expected Output

* ADC value changes on LPC2148 side.
* SPI data is transmitted from LPC2148 to PIC16F877A.
* PIC16F877A receives updated values in real time.
* Output indication changes according to received SPI data.
* Communication remains stable during continuous data transfer.

---

## Troubleshooting

| Problem                   | Possible Reason                  | Solution                                   |
| ------------------------- | -------------------------------- | ------------------------------------------ |
| PIC not receiving data    | Wrong SPI pin connection         | Verify SCK, MOSI, MISO, SS wiring          |
| Random values received    | No common ground                 | Connect LPC2148 GND and PIC GND            |
| SPI not working           | Wrong master/slave configuration | Check SPI control registers                |
| Data mismatch             | Clock polarity/phase mismatch    | Match SPI mode on both controllers         |
| LPC2148 input damage risk | PIC output is 5V                 | Use level shifting for PIC to LPC2148 line |

---

## Learning Outcomes

Through this project, I learned:

* SPI communication between two different microcontrollers
* ARM7 LPC2148 SPI Master configuration
* PIC16F877A SPI Slave configuration
* ADC data transfer through SPI
* Real-time embedded communication
* Hardware debugging and signal validation
* Microcontroller interfacing using Embedded C

---

## Future Improvements

* Display received ADC value on LCD
* Add checksum/error detection
* Use interrupt-based SPI reception on PIC
* Add multiple slave devices
* Transfer 10-bit ADC data in two bytes
* Add UART debugging output
* Use logic analyzer for SPI signal verification

---

## Author

**Sarthak Pampattiwar**

Embedded Systems Enthusiast
Skills: Embedded C, ARM7 LPC2148, PIC16F877A, UART, SPI, I2C, ADC, PWM, GPIO

---

## Repository Description

Real-time SPI communication between ARM7 LPC2148 Master and PIC16F877A Slave for ADC data transfer and microcontroller interfacing.
