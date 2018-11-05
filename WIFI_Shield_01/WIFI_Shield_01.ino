///* This example set your ESP8266 module as a WiFi Station and create a WiFi AP, 
//  * then other PC could conect into this WiFi and send internet data .
// */
//
//
//
//char OK[2]="";
//
////////////////////////////////////////////////////////////////////////////
//void OK_config()
//{  
// while(1)
//  {
//   OK[0]=Serial.read();
//   if(OK[0]=='O')
//     {
//      OK[1]=Serial.read();
//      if(OK[1]=='K')
//        {
//        break;
//        }
//     }
//   delay(20);
//   }  
//}
////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////
//void esp8266_config()
//{
//  delay(500);
// // Serial.println("AT+RST");   
// // OK_config();  
//  Serial.println("AT+CWMODE_DEF=3");   //Set Wi-Fi mode to 3(SoftAP+Station mode)
//  OK_config();
//  Serial.println("AT+CWSAP=\"VMAWIFI\",\"123456789\",11,2");//Set WIFI ID and password
//  OK_config();
//  Serial.println("AT+CIPMUX=1");          
//  OK_config();
//  Serial.println("AT+CIPSERVER=1");    //Set TCP Server
//  OK_config();
//  digitalWrite(A3,HIGH);
//  OK_config();                          //Wating Client send "OK" to confirm 
//  digitalWrite(A3,LOW);
//}
/////////////////////////////////////////////////////////////////////////
//void setup() 
//{ 
//  Serial.begin(115200);
//  pinMode(A3,OUTPUT);
//  esp8266_config();
//}
//void loop()
//{
// Serial.println("AT+CIPSEND=0,9"); 
// OK_config();
// Serial.println("Arduino"); 
// delay(1500);
//}

void setup() {
  Serial.begin(9600);
  Serial.println("In Setup");
  
}

void loop() {
  
}
