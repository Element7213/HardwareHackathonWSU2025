#include <WiFi.h>
#include <esp32cam.h>
#include <WebServer.h>

const char* WIFI_SSID = "Bay";
const char* WIFI_PASS = "05640000";

WebServer server(80);
static auto loRes = esp32cam::Resolution::find(320, 240); // Set low resolution

void streamMJPEG() {
  WiFiClient client = server.client();
  String header = "HTTP/1.1 200 OK\r\n"
                  "Content-Type: multipart/x-mixed-replace; boundary=frame\r\n"
                  "Connection: close\r\n\r\n";
  client.print(header);

  while (client.connected()) {
    auto frame = esp32cam::capture();
    if (frame == nullptr) {
      Serial.println("Capture Fail");
      break;
    }

    client.print("--frame\r\n");
    client.print("Content-Type: image/jpeg\r\n");
    client.print("Content-Length: " + String(frame->size()) + "\r\n\r\n");
    frame->writeTo(client);
    client.print("\r\n");

    delay(100);  // Adjust for FPS
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println();

  using namespace esp32cam;
  Config cfg;
  cfg.setPins(pins::AiThinker);
  cfg.setResolution(loRes);
  cfg.setBufferCount(2);
  cfg.setJpeg(50);

  bool ok = Camera.begin(cfg);
  Serial.println(ok ? "CAMERA OK" : "CAMERA FAIL");

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi");
  Serial.print("Stream available at: http://");
  Serial.print(WiFi.localIP());
  Serial.println("/stream");

  server.on("/stream", streamMJPEG);
  server.begin();
}

void loop() {
  server.handleClient();
}