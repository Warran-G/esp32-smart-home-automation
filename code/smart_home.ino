#include <WiFi.h>
#include <WebServer.h>

// ========== WIFI CONFIG ==========
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// ========== PIN DEFINITIONS ==========
#define LIGHT1_PIN 12
#define LIGHT2_PIN 13
#define LIGHT3_PIN 14
#define LIGHT4_PIN 27
#define FAN_PIN    26
#define SOCKET1_PIN 25
#define SOCKET2_PIN 33
#define SOCKET3_PIN 32

// ========== SERVER ==========
WebServer server(80);

// ========== DEVICE STATES ==========
bool light1State = false;
bool light2State = false;
bool light3State = false;
bool light4State = false;
bool fanState = false;
bool socket1State = false;
bool socket2State = false;
bool socket3State = false;

// ========== HTML UI ==========
String getHTML() {
  return R"rawliteral(
  <!DOCTYPE html>
  <html>
  <head>
    <title>ESP32 Smart Home</title>
    <style>
      body {
        font-family: Arial;
        text-align: center;
        background: #0f172a;
        color: white;
      }
      h1 { margin-top: 30px; }
      .card {
        background: #1e293b;
        padding: 20px;
        margin: 15px auto;
        width: 250px;
        border-radius: 12px;
      }
      button {
        padding: 10px 20px;
        margin: 5px;
        border: none;
        border-radius: 8px;
        font-size: 16px;
        cursor: pointer;
      }
      .on { background: #22c55e; }
      .off { background: #ef4444; }
    </style>
  </head>
  <body>
    <h1>🏠 Smart Home Control</h1>

    <div class="card">
      <h3>Light 1</h3>
      <a href="/light1/on"><button class="on">ON</button></a>
      <a href="/light1/off"><button class="off">OFF</button></a>
    </div>

    <div class="card">
      <h3>Light 2</h3>
      <a href="/light2/on"><button class="on">ON</button></a>
      <a href="/light2/off"><button class="off">OFF</button></a>
    </div>

    <div class="card">
      <h3>Fan</h3>
      <a href="/fan/on"><button class="on">ON</button></a>
      <a href="/fan/off"><button class="off">OFF</button></a>
    </div>

    <div class="card">
      <h3>Socket 1</h3>
      <a href="/socket1/on"><button class="on">ON</button></a>
      <a href="/socket1/off"><button class="off">OFF</button></a>
    </div>

  </body>
  </html>
  )rawliteral";
}

// ========== ROUTES ==========
void handleRoot() {
  server.send(200, "text/html", getHTML());
}

// Generic toggle function
void toggleDevice(int pin, bool &state, bool turnOn) {
  state = turnOn;
  digitalWrite(pin, turnOn ? HIGH : LOW);
  handleRoot();
}

// ========== SETUP ==========
void setup() {
  Serial.begin(115200);

  // Set all pins
  int pins[] = {LIGHT1_PIN, LIGHT2_PIN, LIGHT3_PIN, LIGHT4_PIN,
                FAN_PIN, SOCKET1_PIN, SOCKET2_PIN, SOCKET3_PIN};

  for (int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }

  // Connect WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.println(WiFi.localIP());

  // Routes
  server.on("/", handleRoot);

  server.on("/light1/on", [](){ toggleDevice(LIGHT1_PIN, light1State, true); });
  server.on("/light1/off", [](){ toggleDevice(LIGHT1_PIN, light1State, false); });

  server.on("/light2/on", [](){ toggleDevice(LIGHT2_PIN, light2State, true); });
  server.on("/light2/off", [](){ toggleDevice(LIGHT2_PIN, light2State, false); });

  server.on("/fan/on", [](){ toggleDevice(FAN_PIN, fanState, true); });
  server.on("/fan/off", [](){ toggleDevice(FAN_PIN, fanState, false); });

  server.on("/socket1/on", [](){ toggleDevice(SOCKET1_PIN, socket1State, true); });
  server.on("/socket1/off", [](){ toggleDevice(SOCKET1_PIN, socket1State, false); });

  server.begin();
}

// ========== LOOP ==========
void loop() {
  server.handleClient();
}