#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
     const char *ssid     = "Redmi note 7";
     const char *password = "9063781082";
     unsigned long lastTime = 0;
     unsigned long timerDelay = 5000;
     #define RELAY1 D4
     #define RELAY2 D5


void setup()
{
    pinMode(RELAY1, OUTPUT);
    pinMode(RELAY2, OUTPUT);
    digitalWrite(RELAY1, HIGH);
    digitalWrite(RELAY2, HIGH);

    delay(1000);
    lcd.begin();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Home Automation");
    lcd.setCursor(0, 1);
    lcd.print(" mazon Web EC2 ");
    delay(3000);
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    Serial.println("Connecting");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Connecting to");
    lcd.setCursor(0, 1);
    lcd.print(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
        lcd.print("...");
    }
    Serial.println("");
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WiFI Connected");
    lcd.setCursor(0, 1);
    lcd.print(WiFi.localIP());
Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}


void loop()
{
    // Send an HTTP POST request depending on timerDelay
    if ((millis() - lastTime) > timerDelay)
    {
        // Check WiFi connection status

        if (WiFi.status() == WL_CONNECTED)
        {
            WiFiClient client;
            HTTPClient http;
            String server Path ="http://13.233.25.184/projects/Home_Automation/buttonStatus.txt";
            // Your Domain name with URL path or IP address with path
            http.begin(client, serverPath.c_str());
            // Send HTTP GET request
            int httpResponseCode = http.GET();
            if (httpResponseCode > 0)
            {
                Serial.print("HTTP Response code: ");
                Serial.println(httpResponseCode);
                String payload = http.getString();
                Serial.println(payload);
                lcd.clear();
                lcd.print("Device Status");
                lcd.setCursor(0, 1);
                if (payload == "LON")
                    {
                        lcd.print("LIGHT-1 ON");
                        digitalWrite(RELAY1, LOW);
                        delay(50);
                        Serial.println("LIGHT-1 ON");
                    }
                else if (payload == "LOFF")
                {
                    lcd.print("LIGHT-1 OFF");
                    digitalWrite(RELAY1, HIGH);
                    delay(50);
                    Serial.println("LIGHT-1 OFF");
                }
                else if (payload == "BON")
                {
                    lcd.print("LIGHT-2 ON");
                    digitalWrite(RELAY2, LOW);
                    delay(50);
                    Serial.println("LIGHT-2 ON");
                }
                else if (payload == "BOFF")
                    {
                        lcd.print("LIGHT-2 OFF");
                        digitalWrite(RELAY2, HIGH);
                        delay(50);
                        Serial.println("LIGHT-2 OFF");
                    }
                else if (payload == "ALLON")
                {
                    lcd.print("ALL DEVICES ON");
                    digitalWrite(RELAY1, LOW);
                    digitalWrite(RELAY2, LOW);
                    delay(50);
                    Serial.println("ALL Devices ON");
                }
                else if (payload == "ALLOFF")
                {
                    lcd.print("ALL DEVICES OFF");
                    digitalWrite(RELAY1, HIGH);
                    digitalWrite(RELAY2, HIGH);
                    delay(50);
                    Serial.println("ALL Devices OFF");
                }
                delay(1000);
            }
            else
            {
                Serial.print("Error code: ");
                Serial.println(httpResponseCode);
            }
            // Free resources
            http.end();
        }
        else
        {
            Serial.println("WiFi Disconnected");
        }
        lastTime = millis();
    }
}