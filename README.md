# Smart Home Control System

[Project Image](Images/Smart-Home.png)

This project is my graduation project of the Information Technology Institute's Summer Training Program 7/9/2023

---

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
  - [Prerequisites](#prerequisites)
  - [Compiling the Scripts](#compiling-the-scripts)
  - [Importing Hex files into proteus](#importing-hex-files-into-proteus)
- [Software Code Usage](#software-code-usage)
  - [Master APP Header Functions Documentation](#master-APP-header-functions-documentation)
  - [Slave 1 APP Header Functions Documentation](#slave-1-APP-header-functions-documentation)
  - [Slave 2 APP Header Functions Documentation](#slave-2-APP-header-functions-documentation)
- 

---

## Description

The Smart Home Control System is an embedded systems project that allows users to control various home automation functions using a keypad and an LCD screen. This project serves as a secure and convenient way to manage doors and lights in different rooms within a smart home environment.

The system employs AVR microcontrollers, SPI communication, and a custom keypad interface to provide users with functionalities such as door control and room light management. Users must log in with a password to access the system's features, and multiple fail login attempts can lead to account locking.

---

## Features

- Secure user login with password protection
- Door control options (open and close)
- Room light control (on and off)
- Account lockout for security purposes
- Temperature monitoring and fan control
- Light-dependent resistor (LDR) based LED control
- SPI communication between master and slave devices
- User-friendly LCD interface
- Modular and well-documented code

---

## Installation

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/AhmedMohamed264/Smart_Home_Atmega32_SPI.git

---

## Usage

Follow these steps to compile the master, slave1, and slave2 scripts using an IDE such as Eclipse (preferred) or Atmel Studio and then upload the three hex files to the Proteus project.

### Prerequisites

1. **AVR Development Environment:** Ensure you have the necessary AVR development environment set up, including avr-gcc and avr-libc.

2. **IDE (Eclipse or Atmel Studio):** Use an Integrated Development Environment (IDE) for AVR programming, such as Eclipse or Atmel Studio.

### Compiling the Scripts

1. **Open the IDE:** Launch your preferred IDE (Eclipse or Atmel Studio).

2. **Create Projects:** Create separate projects for the master, slave1, and slave2 scripts.

3. **Import Code:** Import the corresponding script code into their respective projects.

4. **Configure Project Settings:** Configure the project settings to match your AVR microcontroller specifications, including clock frequency and microcontroller type.

5. **Compile Code:** Build each project to compile the code. This step generates the hex files for each script.

### Importing Hex files into proteus






