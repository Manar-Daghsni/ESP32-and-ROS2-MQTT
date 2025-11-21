#include <WiFi.h>
#include <PubSubClient.h>

// WiFi & MQTT
const char* ssid = "Manar";
const char* password = "123456789";
const char* mqtt_server = "192.168.91.40"; // Raspberry Pi IP

WiFiClient espClient;
PubSubClient client(espClient);
const int buttonPin = 4;

// Table position (from ROS2 AMCL)
const float table_x = 2.710;
const float table_y = 1.278;
const float table_theta = 0.0;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);

  // WiFi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");

  // MQTT
  client.setServer(mqtt_server, 1883);
}

void reconnectMQTT() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("esp32_client")) {
      Serial.println(" connected!");
    } else {
      Serial.print(".");
      delay(500);
    }
  }
}

void loop() {
  // Ensure MQTT connection
  if (!client.connected()) {
    reconnectMQTT();
  }
  client.loop();

  // Button press
  if (digitalRead(buttonPin) == LOW) {
    // Create JSON string with coordinates
    char msg[100];
    snprintf(msg, sizeof(msg), "{\"x\": %.3f, \"y\": %.3f, \"theta\": %.3f}", table_x, table_y, table_theta);

    client.publish("robot/call", msg);
    Serial.print("Button pressed -> published position: ");
    Serial.println(msg);

    delay(2000); // debounce
  }
}
