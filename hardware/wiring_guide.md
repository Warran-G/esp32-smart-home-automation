# Wiring Guide

## GPIO Pin Mapping

| Device     | GPIO Pin |
|------------|----------|
| Light 1    | 12       |
| Light 2    | 13       |
| Light 3    | 14       |
| Light 4    | 27       |
| Fan        | 26       |
| Socket 1   | 25       |
| Socket 2   | 33       |
| Socket 3   | 32       |

---

## LED Connections

- Each LED is connected to a GPIO pin through a 220Ω resistor
- The other leg of the LED is connected to GND

---

## Fan / Motor

- Connected to GPIO 26
- May require a transistor or relay for higher current loads

---

## Socket Simulation

- LEDs are used to simulate sockets
- In real implementation, relays should be used instead

---

## Important Safety Notes

- NEVER connect high voltage (AC) directly to ESP32
- Always use relay modules for controlling real appliances
- Ensure proper grounding and insulation
- Double-check wiring before powering the circuit