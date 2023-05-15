//////////////////////// BIBLIOTHEQUES ///////////////////////////////
#include <Wire.h> // s'occupe de la communication avec l'OLED
#include <SoftwareSerial.h> // pour la définition des ports utilisés par le module bluetooth
#include <Adafruit_SSD1306.h> //pour OLED 

////////////////////////DEFINITION DU BLUETOOTH//////////////////////
#define rxPin 10 //Broche 11 en tant que RX, à raccorder sur TX du HC-05
#define txPin 11 //Broche 10 en tant que RX, à raccorder sur TX du HC-05
#define baudrate 9600

SoftwareSerial mySerial(rxPin , txPin); //Définition du software serial + bluetooth

////////////////////////DEFINITION OLED//////////////////////////////

#define nombreDePixelsEnLargeur 128         // Taille de l'écran OLED, en pixel, au niveau de sa largeur
#define nombreDePixelsEnHauteur 64          // Taille de l'écran OLED, en pixel, au niveau de sa hauteur
#define brocheResetOLED         -1          // Reset de l'OLED partagé avec l'Arduino (d'où la valeur à -1, et non un numéro de pin)
#define adresseI2CecranOLED     0x3C        // Adresse de "mon" écran OLED sur le bus i2c (généralement égal à 0x3C ou 0x3D)

Adafruit_SSD1306 OLED(nombreDePixelsEnLargeur, nombreDePixelsEnHauteur, &Wire, brocheResetOLED);

////////////////////////DEFINITION DU FLEX SENSOR////////////////////
const int flexPin = A0;

const float VCC = 5; // mon VCC=5V
const float R_DIV = 33000.0; // la résistance utilisée avant mon flex sensor
const float flatResistance = 15000.0; // résistance quand le flex sensor est plat
const float bendResistance = 50000.0; // résistance à 90°

////////////////////////DEFINITION DES VARIABLES DU CIRCUIT//////////
int ResistancePin = A2; // résistance du capteur 
int tailleDeCaractere =2;
int Val_Resist=0.0;

////////////////////////RESISTANCES//////////////////////////////////
#define R1 100000.0 // en Ohm
#define R2  1000.0 // 
#define R3  100000.0 //  
#define R4  10000.0 // qui est R5 sur le circuit du cours
#define R5  1000.0 // qui est R6 sur le circuit du cours
#define Vcc  5.0 
float Vs = 0.0; // voltage à la sortie
float calibre = 0.000001; //calibre en Mohm

////////////////////////SETUP DU PROGRAMME///////////////////////////

void setup(){
  pinMode(rxPin,INPUT); //On définit le pin Rx en INPUT
  pinMode(txPin,OUTPUT); //On définit le pin Tx en OUTPUT
  pinMode(flexPin, INPUT); //On définit le pin du flex en INPUT

  mySerial.begin(baudrate);
  Serial.begin(baudrate); //ouverture port série
  
  // Initialisation de l'écran OLED
  if (!OLED.begin(SSD1306_SWITCHCAPVCC, adresseI2CecranOLED)) // Arrêt du programme (boucle infinie) si échec d'initialisation
    while (1);

}

////////////////////////CORPS DU PROGRAMME///////////////////////////

void loop() {
  uint8_t ValBitApp; // definition de la variable envoyé au bluetooth
  while (mySerial.available()>0){
    Serial.print(mySerial.read());
  }

  Vs= analogRead(ResistancePin)*5.0/1023.0; // on recupère la valeur de sortie du capteur et on la convertie en Volt ___ 9bits de conversion
  ValBitApp=(analogRead(ResistancePin)/4); // envoie de la donnée sur 1 byte au bluetooth
  mySerial.write(ValBitApp);
  
  Val_Resist = ((R1*((R2+R3)/R2)*(Vcc/Vs))-R4-R1)*calibre; // calcul de la valeur de la resistance
  //mySerial.write(analogRead(ResistancePin));
  //Serial.println(analogRead(ResistancePin));

  OLED.clearDisplay(); // j'efface l'integralité du buffer
  OLED.setTextColor(SSD1306_WHITE); // affichage du texte en blanc

////////////////////////AFFICHAGE DU CAPTEUR GRAPHITE SUR LE OLED/////

  OLED.setTextSize(1); 
  OLED.setCursor(1, 3);

  OLED.print("Mesure en continue");  

  OLED.setTextSize(tailleDeCaractere);// Taille des caractères (1:1, puis 2:1, puis 3:1)
  OLED.setCursor(3, 28);// Déplacement du curseur en position (0,0), c'est à dire dans l'angle supérieur gauche
  OLED.print(Val_Resist);
  OLED.print("Mohm");
 
  OLED.display(); // Transfert le buffer à l'écran

////////////////////////AFFICHAGE DU FLEX SUR LE SERIAL MONITOR//////
  
  int ADCflex = analogRead(flexPin); 
  float Vflex = ADCflex * VCC/ 1023.0;
  float Rflex = R_DIV * (VCC / Vflex - 1.0);
  //Serial.println("Resistance: " + String(Rflex) + " ohms");

  float angle = map(Rflex, flatResistance, bendResistance, 0, 90.0); // Utiliser la résistance calculée pour estimer l'angle de courbure du capteur
  //Serial.println("Bend: " + String(angle) + " degrees");
  //Serial.println();

  Serial.println("##### RESISTANCE ######");
  Serial.println(analogRead(Rflex));
  delay(1000);
  Serial.println("##### ANGLE ######");
  Serial.println(angle);

}
