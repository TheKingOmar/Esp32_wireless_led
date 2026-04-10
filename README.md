# ESP32 AP LED Controller

A simple ESP32 project that creates its own Wi-Fi network and serves a local web page to control an LED from a browser.

## What it does

- Creates a Wi-Fi access point with the ESP32
- Hosts a small local web server
- Serves an HTML page with LED ON / OFF controls
- Updates the LED state based on browser requests
- Displays the current LED state on the page

## How it works

The ESP32 runs in **Access Point (AP) mode**, so it does not need a home router.

1. The ESP32 creates its own Wi-Fi network
2. A phone or laptop connects to that network
3. The browser opens the ESP32 IP address
4. The web page sends requests like:
   - `/led/on`
   - `/led/off`
5. The ESP32 reads the request and updates the LED

## Hardware

- ESP32 dev board
- LED
- Resistor
- Breadboard
- Jumper wires

## Wiring

- `GPIO 4 -> resistor -> LED -> GND`

## Features

- SoftAP mode
- Local web server on port 80
- Route-based LED control
- Simple HTML/CSS interface
- LED state shown on page

## Example network settings

- SSID: `ESP32 network`
- Password: `12345678`

## How to use

1. Upload the sketch to the ESP32
2. Open Serial Monitor at `115200`
3. Note the printed IP address
4. Connect your phone or laptop to the ESP32 Wi-Fi network
5. Open the printed IP in a browser
6. Use the page buttons to turn the LED on and off

## Notes

- This project uses the ESP32 as its own Wi-Fi network, so internet access is not required
- Some devices may warn that the network has no internet; that is normal
- On my current board, uploading often requires manually holding the **BOOT** button

## Future improvements

- Cleaner UI styling
- Sensor status on the page
- Distance sensor integration
- AJAX / no-refresh controls
- Multiple outputs or modes

## Files

- `main.ino` or equivalent Arduino sketch file
- `README.md`

## Learning goals

This project was built to practice:

- ESP32 Wi-Fi access point mode
- Basic HTTP server handling
- Route parsing from browser requests
- GPIO control from a web interface
- Dynamic HTML generation on a microcontroller
