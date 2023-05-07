# Projet Capteur de Solène Bourguet et Victor Cuzacq
_Ce projet s’inscrit dans le contexte de l’UF « Du capteur au band de test en open source hardware » du département de Génie Physique de l’INSA Toulouse._  

## Objectif :  
Ce projet se base sur les travaux des chercheurs : Cheng-Wen Lin, Zhibo Zhao, Jaemyung Kim et Jiaxing Huang, afin d’évaluer les potentialités de leur technologie low-tech, le « Pencil Draw Strain Gauges ». L’objectif de ce projet est de réaliser un capteur low-tech à base de graphite et d’en faire une analyse critique argumentée pour en cerner les potentialités et le cas échéant proposer des solutions d’amélioration.  

Pour ce capteur nous utilisons une feuille sur laquelle nous avons dessiner au crayon de papier. La contrainte mécanique appliquée sur la feuille va ainsi modifier la distance entre les particules de graphique et par conséquent la résistance au passage du courant.  


![Capteur1](https://i.ibb.co/N14nvj2/image-1.jpg)

Les étapes et le matériel nécessaire à ce projet sont détaillés ci-dessous.  

## Sommaire  
1. [Livrables](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#livrables)    
2. Matériel requis  
3. Simulation sur LTSpice  
4. Kicad  
  1 Symboles et empreintes de composants  
  2 Schématique   
  3 Placement des composants  
  4 Visualisation 3D  
5. Fabrication du shield  
  1 Réalisation du PCB  
  2 Perçage et soudure de nos composants  
6. Arduino  
  1 Bibliothèques utilisées  
  2 Code Arduino  
7. Application Android
8. Banc de test  
  1 Banc de test  
  2 Résultats obtenus  
  3 Analyse des résultats  
9. Pistes d’améliorations   
10. Datasheet

## Livrables  
Voici l’ensemble des livrables du projet :  
- Une carte PCB se connectant à un module Arduino UNO contenant un amplification transimpédance, un module Bluetooth, un écran OLED et un Flex sensor  
-	Un code Arduino permettant de mesurer la déformation du capteur et de piloter un module Bluetooth, un écran OLED et un Flex sensor  
-	Une application Android APK  
-	Un protocole de test (simulation sous LTspice + banc de test ?)  
-	La datasheet du capteur de déformation  


Nous avons commencé par réaliser la modélisation de notre shield sur le logiciel Kicad. Il contient ainsi un amplificateur transimpédance, un écran OLED, un module Bluetooth et un Flex sensor. Nous avons ensuite fabriqué par lithographie notre carte PCB et ajouté les composants par soudage sur la carte après l’avoir percée au préalable. 
Nous avons réalisé un code Arduino permettant de mesurer la variation de résistance du capteur et de piloter un module Bluetooth, un écran OLED et un Flex sensor.  

En parallèle de cela, nous avons créé une application Android grâce au logiciel MIT App Inventor, capable de communiquer avec le module Bluetooth et recevoir la valeur de la tension de sortie et de calculer les valeurs de résistances de notre capteur.  

Par la suite nous avons mis en place un banc de test pour caractériser notre capteur en fonction de sa déformation et de la mine de crayon utilisée (HB, B).   

Pour finir nous avons réalisé une datasheet à l’aide des résultats obtenus par le banc de test.   


## Matériel requis

Voici la liste des composants nécessaires à l’élaboration de notre capteur   

-	2 résistances 100kΩ (R1 et R3)    
-	1 résistance 10kΩ (R5) (R4 sur notre Kicad)  
-	2 résistances 1kΩ (R2 et R6) (R2 et R5 sur notre Kicad)  
-	1 résistance de 33kΩ (Rflex)  
-	1 capacité 1µF (C4)  
-	2 capacités 100nF (C1 et C2)   
-	1 amplificateur opérationnel LTC1050  
-	1 module Bluetooth HC05   
-	1 écran OLE I2C 0.91  
-	1 Flex sensor   
-	1 feuille de papier  
-	3 crayon de papier : HB, B  

## Simulation sur LTspice 

Le capteur graphique que nous souhaitons réalisé est alimenté en 5V et sa résistance fluctue entre 20 et 100MΩ, ainsi le courant en sortie sera de l’ordre de 100nA (I =U/R). Ce courant de sortie sera trop faible pour être capté par la carte Arduino UNO, c’est pourquoi nous devons utiliser un amplificateur transimpédance, pour amplifier le signal de sortie de notre capteur. 

Ce montage gère à la fois l’amplification et le filtrage du signal pour limiter l’amplification du bruit.

![Circuit](https://i.ibb.co/0jgdCKz/image-3.jpg)  

Voici la fonction des différents composants :
  - R5 en entrée protège l'ampli opérationnel contre les décharges électrostatiques, en forme avec C1 un filtre pour les bruits en tension  
  - C1 avec R1 forme un filtre pour le bruit en courant  
  - R2 sera interchangeable, pour permettre une adaptation du calibre  
  - C4 avec R3 forme un filtre actif  
  - C2 avec R6 forme le filtre de sortie  
  - C3 filtre le bruit d'alimentation  
  
On peut calculer la résistance du capteur grâce à la formule :

$R_{Capteur} = (1 + \dfrac{R3}{R2}) \times R1 \times (\dfrac{VCC}{VADC}) - R1 - R5$  

Dans notre code Arduino ainsi que dans notre Kicad, notre R4 est égale au R5 du schéma ci-contre et R5 vaut R6 du schéma.   

## Kicad

Nous avons modélisé notre shield PCB sur le logiciel KICAD. Nous avons commencé par dessiner tous les composants puis nous avons créé leur empreinte.  

### Symboles et empreintes de composants   

- Amplificateur LTC1050  
  
![Ampli](https://i.ibb.co/G98bGdG/image-4.jpg)  

- Ecran OLED  

![OLED](https://i.ibb.co/0DTwwZ9/image-5.jpg)  

- Flex sensor  

![Flex](https://i.ibb.co/BrD0GSZ/image-6.jpg)  

- Module Bluetooth HC05  

![Bluetooth](https://i.ibb.co/X43873G/image-78.jpg)  


### Schématique  

Une fois les empreintes créées, nous avons réalisé le schéma de notre shield.  

![shield](https://i.ibb.co/GHYRhdF/image-8.jpg)  

### Placement des composants  

![placementcompo](https://i.ibb.co/cxhrhTQ/image-9.jpg)  

### Visualisation 3D  

Nous avons téléchargé les modèles 3D de nos composants afin de visualiser notre PCB en 3D et de vérifier que les composants de la carte ne se chevauchent pas.   
 
![3D](https://i.ibb.co/YZMbHvh/image-10.jpg)  

## Fabrication du shield  

![shield](https://i.ibb.co/KzYj2hT/image-11.jpg)  

![shield2](https://i.ibb.co/ccb1nLL/image-12.jpg)  

### Réalisation du PCB  

Nous avons réalisé notre PCB avec l’aide de Catherine Crouzet au sein du département du Génie Physique et du Génie Electrique et Informatique de l’INSA Toulouse. Pour fabriquer notre PCB nous avons utilisé une plaquette d’époxy recouverte d’une fine couche de cuivre. Nous avons d’abord imprimé notre modélisation du PCB réalisé sur Kicad. Nous avons ensuite plongé notre plaquette avec notre modélisation imprimée dans une machine insolant des UVs.  
Notre modélisation imprimée va servir de masque lors de cette insolation sous UVs. A l’aide d’un révélateur, nous avons retiré la partie de la résine non insolée. Nous plongeons ensuite la plaquette dans un bain de perchlorure de fer pour la gravure. Le cuivre non protégé par la résine est éliminé. Pour finir, nous lavons notre plaquette à l’acétone pour éliminer les dernières traces de résine.   


### Perçage et soudure de nos composants   

Nous perçons ensuite notre PCB à l’aide d’une perceuse électrique pour insérer nos composants. Le diamètre de nos percage varie selon le type de composant :   
-	0,8 mm : pour l’AOP LTC1050, le module OLED, Bluetooth, le Flex sensor, les résistances et les capacités
-	1,0 mm : pour les broches de connexion de la carte Arduino UNO.  
Nous avons soudé nos composants sur la face arrière du PCB. Nous avons cependant constaté des courts-circuits sur la carte PCB qui nous ont obligé à souder des fils reliés à la masse sur la face avant de notre PCB.  

## Arduino  

### Bibliothèques utilisées    

Nous avons utilisé 3 bibliothèques dans notre code Arduino :  
-	Wire.h : qui s’occupe de la communication avec l’écran OLED ;  
-	SoftwareSerial.h : pour définir les ports utilisés par le module Bluetooth ;  
-	Adafruit_SSD1306.h : afin de contrôler notre écran OLED.   

### Code Arduino   

Notre code permet de récupérer la tension à la sortie du capteur et de calculer la valeur de sa résistance. Nous avons rajouté des éléments sur le shield pour faciliter la communication de l’information :    
-	Un écran OLED : l’écran reçoit la valeur de la résistance (en MΩ) du capteur en continu 
-	Un module Bluetooth : qui envoie les données à l’application  
-	Un Flex sensor : dont la valeur de la résistance et la valeur de son angle sont affichés dans le Serial Monitor. Sa présence nous permet de vérifier les démarches réalisées sur le capteur.  

## Application Android   

Nous avons créé une application android sur Mit App Inventor que nous avons pu télécharger via le .apk du dossier. 
Le but de notre application est d’afficher la valeur de la tension de sortie du capteur en continu sur un téléphone Android et de tracer un graphique de la valeur de sa résistance en fonction du temps. C’est l’application qui va calculer la valeur de la résistance du capteur. 
Notre interface comprend :  
-	Un bouton connexion au Bluetooth de notre shield. Il devient vert quand la connexion est établie et grise quand elle ne l’est pas.   
-	Un bouton déconnexion au Bluetooth. Il devient rouge quand on appuie dessus.  
-	La valeur de la tension de sortie du capteur en continu.   
-	Un graphique affichant la valeur de la résistance de notre capteur en fonction du temps.   

## Banc de test   

### Banc de test   

Nous avons testé notre capteur sur un banc de test disponible au Génie Physique de l’INSA Toulouse. Notre banc de test composé de 7 demi cylindres de rayon allant de 2,5cm à 1cm par pas de 0,5cm.   

![banc1](https://i.ibb.co/VHXMhRr/image-13.jpg)  
![banc1](https://i.ibb.co/ygxqRcG/image-14.jpg)  
![banc1](https://i.ibb.co/3m3R9xC/image-15.jpg)  

En enrobant les cylindres avec notre capteur, nous créons une déformation que nous pouvons calculer avec la formule :   

$\epsilon = \dfrac{e}{2 \times RR_{Capteur}})$   


















