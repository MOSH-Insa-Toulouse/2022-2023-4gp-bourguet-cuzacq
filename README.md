# Projet Catpeur de Solène Bourguet et Victor Cuzacq (4A GP INSA)  
_Ce projet s’inscrit dans le contexte de l’UF « Du capteur au band de test en open source hardware » du département de Génie Physique de l’INSA Toulouse._  

## Objectif :  
Ce projet se base sur les travaux des chercheurs : Cheng-Wen Lin, Zhibo Zhao, Jaemyung Kim et Jiaxing Huang, afin d’évaluer les potentialités de leur technologie low-tech, le « Pencil Draw Strain Gauges ». L’objectif de ce projet est de réaliser un capteur low-tech à base de graphite et d’en faire une analyse critique argumentée pour en cerner les potentialités et le cas échéant proposer des solutions d’amélioration.  

Pour ce capteur nous utilisons une feuille sur laquelle nous avons dessiner au crayon de papier. La contrainte mécanique appliquée sur la feuille va ainsi modifier la distance entre les particules de graphique et par conséquent la résistance au passage du courant.  


![Capteur1](https://i.ibb.co/DMG7h8b/imag12.png)  

Les étapes et le matériel nécessaire à ce projet sont détaillés ci-dessous.  

## Sommaire  
1. Livrables  
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




