#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "Bay";
const char* password = "05640000";

// Set up the server to listen on port 80
WebServer server(80);

// Function to handle the POST request for receiving coordinates
void handleCoordinates() {
  if (server.hasArg("center_x") && server.hasArg("center_y")) {
    String center_x = server.arg("center_x");
    String center_y = server.arg("center_y");
    Serial.print("Received coordinates: ");
    Serial.print("Center X: ");
    Serial.print(center_x);
    Serial.print(" Center Y: ");
    Serial.println(center_y);
  }
  server.send(200, "text/plain", "Coordinates received");
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  // Wait for the WiFi to connect
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Set up the endpoint to receive coordinates via POST
  server.on("/coordinates", HTTP_POST, handleCoordinates);

  // Start the web server
  server.begin();
  Serial.println("Server started");
}

void loop() {
  server.handleClient();  // Handle incoming client requests
}
