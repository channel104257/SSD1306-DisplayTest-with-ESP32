# SSD1306-DisplayTest-with-ESP32

## 所需材料
* ESP32開發板 Goouuu-esp32
* SSD1306 0.96吋 OLED顯示模組
* 麵包版&杜邦線

## 開發環境
* Visual Studio Code + PlatformIO<br>


此範例為測試OLED是否能正常顯示<br>
引用程式庫u8g2請參考 :<br>
PlatformIO : https://platformio.org/lib/show/942/U8g2?utm_source=platformio&utm_medium=piohome<br>
Github : https://github.com/olikraus/U8g2_Arduino?utm_source=platformio&utm_medium=piohome<br>

## 說明
此範例使用的I2C腳位為作者所自定義<br>
在程式中使用下列宣告<br>
```C
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE, /* clock=*/, /* data=*/); // ESP32 Thing, HW I2C with pin remapping
```
`clock`及`data`兩欄請填上對應的`SCL`及`SDA`所在的腳位<br>
參考 : https://github.com/olikraus/U8g2_Arduino/tree/master/examples/full_buffer/U8g2Logo

>在ESP32上自定義I2C腳位
>```C 
>#include <Wire.h> 
>#define I2C_SDA1 26 //宣告自定義SDA腳位
>#define I2C_SCL1 25 //宣告自定義SCL腳位
>.
>.
>void setup(void){
>Wire.begin(I2C_SDA1, I2C_SCL1);
>.
>.
>}
>```
另一點為在主要執行檔中匯入自製字元標頭檔`word.h`<br>
便能成功顯示作者想測試的中文字符<br>
<img src="https://github.com/channel104257/SSD1306-DisplayTest-with-ESP32/blob/main/20210802_093032284_iOS.jpg" style="zoom:5%" />
