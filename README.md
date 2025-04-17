  <h1>ESP8266 Wi-Fi Password Tester (Serial-Based)</h1>

  <p>
    This educational project allows your ESP8266 board to scan nearby Wi-Fi networks and attempt to connect using a list of common passwords—entirely through the Serial Terminal.
  </p>

  <blockquote>
    <strong>DISCLAIMER:</strong> For educational and authorized testing only.<br>
    Do <strong>NOT</strong> use on networks you don’t own or have explicit permission to access.
  </blockquote>

  <h2>Key Features</h2>
  <ul>
    <li>Scans and displays nearby Wi-Fi networks (SSID + RSSI)</li>
    <li>Select network by index from Serial input</li>
    <li>Tries a list of common passwords</li>
    <li>Built-in LED blinks during attempts (faster if successful)</li>
  </ul>

  <h2>Requirements</h2>
  <ul>
    <li>ESP8266 board (e.g., NodeMCU, Wemos D1 Mini)</li>
    <li>Arduino IDE (with ESP8266 board package)</li>
    <li>USB cable for Serial communication</li>
    <li>Serial Monitor (115200 baud)</li>
  </ul>

  <h2>Use With Android Phone</h2>
  <p>
    You can use your ESP8266 with your Android phone using a USB OTG cable and the <strong>Serial USB Terminal</strong> app:
  </p>
  <p>
    <a href="https://play.google.com/store/apps/details?id=de.kai_morich.serial_usb_terminal" target="_blank">
      Serial USB Terminal - Play Store Link
    </a>
  </p>
  <p>Just plug your ESP8266 board into your phone using OTG and launch the app to see Serial output/input in real time.</p>

  <h3>Screenshots:</h3>
  <ul>
    <li><img src="https://github.com/mdabdulgonyrafid/esp8266-wifi-password-bruteforce/blob/main/screenshots/PXL_20250417_172846765.PORTRAIT.ORIGINAL.jpg"  alt="LED blinking" width="300"></li>
    <li><img src="https://github.com/mdabdulgonyrafid/esp8266-wifi-password-bruteforce/blob/main/screenshots/Screenshot_20250417-232811.png" alt="Serial output - Scanning" width="300"></li>
  </ul>

  <h2>How to Use</h2>
  <ol>
    <li>Upload the sketch to your ESP8266</li>
    <li>Open the Serial Monitor (115200 baud)</li>
    <li>View scanned Wi-Fi networks</li>
    <li>Enter the index of the network to test</li>
    <li>Watch LED and Serial output for connection status</li>
  </ol>

  <h2>LED Behavior</h2>
  <ul>
    <li><strong>Slow blink:</strong> Trying password</li>
    <li><strong>Fast blink:</strong> Connected successfully</li>
    <li><strong>Off:</strong> Not connected</li>
  </ul>

  <h2>License</h2>
  <p>
    Licensed under the <strong>GNU General Public License v3.0</strong>.<br>
    Full license: <a href="https://www.gnu.org/licenses/gpl-3.0.en.html" target="_blank">https://www.gnu.org/licenses/gpl-3.0.en.html</a>
  </p>

  <h2>Author</h2>
  <p>
    Developed by <strong>Md. Abdul Gony Rafid</strong><br>
    For educational research on IoT and network security
  </p>
