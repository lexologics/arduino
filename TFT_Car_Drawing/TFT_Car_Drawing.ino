#include <Adafruit_GFX.h> // Hardware-specific library
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

// work in line numbers.  Font height in ht
int16_t ht = 16, top = 3, line, lines = 15, scroll;

void setup()
{
    tft.reset();
    uint16_t id = tft.readID();
    tft.begin(id);
    tft.setRotation(1);     //Landscape, for portrat it is 0
    tft.fillScreen(WHITE);
    tft.drawRect(0,0,320,149,CYAN);//sky
      tft.fillRect(0,0,320,149,CYAN);
      tft.drawRect(0,240,320,-80,GREEN);//grass
      tft.fillRect(0,240,320,-80,GREEN);
/*    tft.drawLine(100,100,200,100,RED);
    tft.drawLine(100,100,100,120,RED);
    tft.drawLine(100,120,70,120,RED);
    tft.drawLine(70,120,70,140,RED);
    tft.drawLine(70,140,200,140,RED);
    tft.drawLine(200,100,200,140,RED);  */
    tft.drawRect(100,145,100,-45,MAGENTA);  //body
    tft.fillRect(100,145,100,-45,MAGENTA);
    tft.drawCircle(130,140,10,BLACK);//wheel
    tft.fillCircle(130,140,9,YELLOW);
    tft.drawCircle(180,140,10,BLACK);
    tft.fillCircle(180,140,9,YELLOW);
    tft.drawRect(0,150,320,170,BLACK);//road
    tft.fillRect(0,150,320,10,BLACK);
    tft.drawRect(130,125,-25,-15,BLACK);//window
     tft.fillRect(130,125,-25,-15,YELLOW);
       tft.drawRect(170,125,-15,-15,BLACK);
     tft.fillRect(170,125,-15,-15,YELLOW);

     tft.drawRect( 50,150,-10,-60,BLACK);//tree bark
   tft.fillRect( 50,150,-10,-60,BLACK);
  tft.drawCircle(50,60,29,GREEN);// tree top
  tft.fillCircle(50,60,29,GREEN);
  tft.drawRect(250,150,-10,-60,BLACK);//tree bark
  tft.fillRect(250,150,-10,-60,BLACK);
  tft.drawCircle(250,60,29,GREEN);// tree top
  tft.fillCircle(250,60,29,GREEN);
  tft.drawCircle(160,33,30,YELLOW);//sun
  tft.fillCircle(160,33,30,YELLOW);

  tft.setTextColor(WHITE, BLACK);
}
void loop(){
  tft.setCursor(10,10);
  tft.setTextSize(2);
  tft.println("Lexologics");
  delay(100);

}
