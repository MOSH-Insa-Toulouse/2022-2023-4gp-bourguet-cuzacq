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

	$  R_{Capteur}  $   
	
	= (1 +  $$\frac{R3}{R2}$$) * R1 * ( $\frac{VCC}{VADC}$ ) - R1 - R5  

$(5 + 3\times 8 - (1 + 35 \div 5))(18 - 5 \times 2)$   

