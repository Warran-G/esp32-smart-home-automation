# API Routes

## Overview

The ESP32 web server uses HTTP routes to control connected devices.

Each route corresponds to a specific action (turning a device ON or OFF).

---

## Light Controls

- `/light1/on` → Turn Light 1 ON
- `/light1/off` → Turn Light 1 OFF

- `/light2/on` → Turn Light 2 ON
- `/light2/off` → Turn Light 2 OFF

- `/light3/on` → Turn Light 3 ON
- `/light3/off` → Turn Light 3 OFF

- `/light4/on` → Turn Light 4 ON
- `/light4/off` → Turn Light 4 OFF

---

## Fan Controls

- `/fan/on` → Turn Fan ON
- `/fan/off` → Turn Fan OFF

---

## Socket Controls

- `/socket1/on` → Turn Socket 1 ON
- `/socket1/off` → Turn Socket 1 OFF

- `/socket2/on` → Turn Socket 2 ON
- `/socket2/off` → Turn Socket 2 OFF

- `/socket3/on` → Turn Socket 3 ON
- `/socket3/off` → Turn Socket 3 OFF

---

## Notes

- Each route is triggered when a user clicks a button on the web interface
- The ESP32 processes the request and updates the corresponding GPIO pin
- After execution, the server reloads the main page