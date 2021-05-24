# Custom version of CameraWebServer code from Arduino IDE example.
To get original code, in your Arduino IDE go to: File > Examples > ESP32 > Camera > CameraWebServer
The source of this modified project is https://github.com/electrical-pro/ESP32CAM

This code has LED control.
WARNING: LED on the board doesn't have a current limiting resistor, so it gets very hot quickly, use it at your own risk. (I've used a separate LED module).

| API        | Feature           |
| ------------- |:-------------:|
| http://192.168.X.X/setup     | Display page with main control setup to test and control the camera settings |
| http://192.168.X.X/signal     | Get signal of WIFI connection      |
| http://192.168.X.X/restart      | Restart the Arduino      |
| http://192.168.X.X/status      | Display a Json with current camera settings      |
| http://192.168.X.X/capture      | Get a Jpeg form camera      |
| http://192.168.X.X:81/stream      | Get a video stream from camera      |
| http://192.168.X.X:81/control?var=XXXX&val=XX      | Url to configure the setup by code. <br> e.g. :  /control?var=flash&val=1     |

  
<br>

# Components

USB to UART converter https://s.click.aliexpress.com/e/_dW0jGff

ESP32 Camera: https://s.click.aliexpress.com/e/_d8XnZxj

DC-DC Converter: https://s.click.aliexpress.com/e/_dWvPhXW

5V LED Modules here: https://s.click.aliexpress.com/e/_d7fCXNX


Almost all needed on Amazon:
ESP32 Camera + UART converter + wires: https://amzn.to/3s4ZjXQ
