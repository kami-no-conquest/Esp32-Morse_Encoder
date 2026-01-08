# ESP32 Morse Encoder

# Overview

The ESP32 Morse Encoder is an embedded systems project that converts text received over the Serial interface into International Morse Code, transmitting it visually using an LED.

The project emphasizes correct Morse timing, clean character-to-pattern mapping, and simple, readable firmware suitable for learning and extension.


# Morse Timing Conventions

The encoder follows standard International Morse Code timing rules:

* **Dot (`.`)** → 1 time unit
* **Dash (`-`)** → 3 time units
* **Gap between symbols** (dot/dash) → 1 time unit
* **Gap between letters** → 3 time units
* **Gap between words** → 7 time units

One time unit is defined by the `dotDelay` constant (default: **200 ms**).


# Features

* Supports letters (A–Z) and numbers (0–9)
* Implements standard Morse timing conventions
* Serial-based text input
* LED-based visual Morse output


# Hardware Used

* ESP32 development board
* 1 × LED
* 1 × 220Ω resistor
* Breadboard and jumper wires


# How It Works

1. The ESP32 waits for characters sent via the Serial Monitor.
2. Each character is normalized to uppercase (Morse code is case-insensitive).
3. Letters (`A–Z`) and digits (`0–9`) are mapped to Morse patterns using lookup tables.
4. Each Morse pattern is iterated symbol by symbol:
   * `.` triggers a short LED pulse (dot)
   * `-` triggers a long LED pulse (dash)
5. Delays between symbols, letters, and words are applied according to Morse timing rules.

The Morse patterns are stored as null-terminated C strings, and iteration continues until the terminator (`'\0'`) is reached.

# License

This project is released under the MIT License. You are free to use, modify, and distribute the code with proper attribution.
