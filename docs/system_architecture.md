# System Architecture

## Overview

This project follows a client-server architecture using the ESP32 as a local web server.

## Components

- **Client:** Web browser (user interface)
- **Server:** ESP32 microcontroller
- **Devices:** LEDs (lights), fan, and sockets connected via GPIO

## How It Works

1. The ESP32 connects to a Wi-Fi network
2. It hosts a web server using HTTP
3. The user accesses the ESP32 using its IP address in a browser
4. The web interface sends HTTP requests when buttons are clicked
5. The ESP32 processes the request and toggles GPIO pins
6. Devices turn ON or OFF accordingly

## System Flow

User → Browser → ESP32 Web Server → GPIO Pins → Devices

## Advantages

- No cloud dependency
- Low latency (fast response)
- Cost-effective solution
- Easy to expand with more devices

## Future Improvements

- Add authentication (login system)
- Use MQTT or cloud services for remote access
- Real-time updates using WebSockets