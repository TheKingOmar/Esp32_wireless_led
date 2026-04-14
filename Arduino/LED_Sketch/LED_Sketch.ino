#include <WiFi.h>
const char* ssid = "ESP32 network";
const char* pass = "12345678";
WiFiServer server(80);
const int ledPin = 4;
bool ledState = false;
void setup() {
  Serial.begin(115200);
  bool result = WiFi.softAP(ssid, pass);
  delay(1000);
  Serial.print("Network status: ");
  Serial.println(result);
  Serial.print("IP:");
  Serial.println(WiFi.softAPIP());
  server.begin();
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

}

void loop() {
  WiFiClient client = server.available();
  if (client){
    Serial.println("Client is connected");
    while (client.connected() && !client.available()){
    delay(1);
    }
    String request = client.readStringUntil('\r');
    Serial.println(request);
    if (request.indexOf("/led/on") != -1){
      digitalWrite(ledPin, HIGH);
      ledState = true;

    }
    else if (request.indexOf("/led/off") != -1) {
      digitalWrite(ledPin,LOW);
      ledState = false;
    }
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.println("<html>"
                   "<head>"
                   "<style>"
                   "body{"
                   "font-family:sans;"
                   "}"
                   ".on {"
                   "background-color: green;"
                   "}"
                   ".off {"
                   "background-color: red;"
                   "}"
                   ".state{"
                   "font-size:50px;"
                   "}"
                   "button {"
                    "font-size: 100px;"
                    "width:550px;"
                    "height:350px;"
                    "margin: auto;"
                    "padding: 25px;"
                    "text-align: center;"
                    "border: 15px solid black;"
                    "border-radius:35px;"
                   "}"
                   "h1 { "
                   "font-size:100px;"
                   "margin: auto;"
                   "text-align: center;"
                   "}"
                   "</style>"
                   "</head>"
                   "<body>"
                   "<h1>LED Control</h1>"
                   "<form action ='/led/on'>"
                   "<button type='submit' class='on'>Turn LED ON </button>"
                   "</form>"
                   "<form action='/led/off'>"
                   "<button type='submit' class='off'>Turn LED OFF</button>"
                   "</form>"
                   "<p class='state'>LED state: " ) ; 
    if (ledState){
      client.println("ON</p>");
    } else {
      client.println("OFF</p>");
    }
    client.println("</body>");
    client.println("</html>");
    client.stop();
  } 
}
