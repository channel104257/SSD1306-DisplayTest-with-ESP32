#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

#define I2C_SDA1 26
#define I2C_SCL1 25

#include "word.h"

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE, /* clock=*/I2C_SCL1, /* data=*/I2C_SDA1); // ESP32 Thing, HW I2C with pin remapping

void setup(void)
{
    pinMode(9, OUTPUT);
    digitalWrite(9, 0); // default output in I2C mode for the SSD1306 test shield: set the i2c adr to 0
    Wire.begin(I2C_SDA1, I2C_SCL1);

    u8g2.begin();
    u8g2.setFont(myFont);
    u8g2.enableUTF8Print();
}

void loop(void)
{
    u8g2.firstPage();
    do
    {
        //void U8G2::setCursor(u8g2_uint_t x, u8g2_uint_t y)
        u8g2.setCursor(0, 16);
        u8g2.print("學習不只是義務");
        u8g2.setCursor(0, 34);
        u8g2.print("更是種投資");
        //u8g2.drawStr 只能顯示英文字符
        u8g2.setCursor(0, 62);
        u8g2.print("星詠工作室"); //須注意字元是否有像素出現在基準線以下
    } while (u8g2.nextPage());
}