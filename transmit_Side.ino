#include <SPI.h>        
#include <Ethernet.h>
#include <EthernetUdp.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:

byte mac[] = { 0xDE, 0xAD, 0xEE, 0xEE, 0xFE, 0xED };

IPAddress ip(192, 168, 2, 178);
unsigned int localPort = 8889;      // local port to listen on
IPAddress RIP(192, 168, 2, 177);
unsigned int RPort = 8888;
int val = 0;
int inPin = 3;

// An EthernetUDP instance to let us send and receive packets over UDP

EthernetUDP Udp;

void setup() {

  // start the Ethernet and UDP:

  Ethernet.begin(mac,ip);
  Udp.begin(localPort);
  Serial.begin(9600);
  pinMode(inPin, INPUT);
}

void loop() {
  digitalWrite(inPin, HIGH); 
  val = digitalRead(inPin); 
   
   
   if (val == 1)
   {
   Udp.beginPacket(RIP, RPort);
   Udp.write("1");
   Udp.endPacket();
   delay(500);
   }
  
  else
   {
  Udp.beginPacket(RIP, RPort);
   Udp.write("0");
   Udp.endPacket();
   delay(500);
   }
}
