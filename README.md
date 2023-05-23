# Projet Capteur de Solène Bourguet et Victor Cuzacq
_Ce projet s’inscrit dans le contexte de l’UF « Du capteur au band de test en open source hardware » du département de Génie Physique de l’INSA Toulouse._  

## Objectif :  
Ce projet se base sur les travaux des chercheurs : Cheng-Wen Lin, Zhibo Zhao, Jaemyung Kim et Jiaxing Huang, afin d’évaluer les potentialités de leur technologie low-tech, le « Pencil Draw Strain Gauges ». L’objectif de ce projet est de réaliser un capteur low-tech à base de graphite et d’en faire une analyse critique argumentée pour en cerner les potentialités et le cas échéant proposer des solutions d’amélioration.  

Pour ce capteur nous utilisons une feuille sur laquelle nous avons dessiner au crayon de papier. La contrainte mécanique appliquée sur la feuille va ainsi modifier la distance entre les particules de graphique et par conséquent la résistance au passage du courant.  


![Capteur1](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/imagesRapport/image%201.jpg?raw=true)

Les étapes et le matériel nécessaire à ce projet sont détaillés ci-dessous.  

## Sommaire  
1. [Livrables](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#1-livrables)    
2. [Matériel requis](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#2-mat%C3%A9riel-requis)  
3. [Simulation sur LTSpice](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#3-simulation-sur-ltspice)  
4. [Kicad](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#4-kicad)    
  1 [Symboles et empreintes de composants](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#41-symboles-et-empreintes-de-composants)  
  2 [Schématique](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#42-sch%C3%A9matique)  
  3 [Placement des composants](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#43-placement-des-composants)    
  4 [Visualisation 3D](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#44-visualisation-3d)  
5. [Fabrication du shield](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#5-fabrication-du-shield)    
  1 [Réalisation du PCB](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#51-r%C3%A9alisation-du-pcb)    
  2 [Perçage et soudure de nos composants](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#52-per%C3%A7age-et-soudure-de-nos-composants)    
6. [Arduino](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#6-arduino)    
  1 [Bibliothèques utilisées](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#61-biblioth%C3%A8ques-utilis%C3%A9es)    
  2 [Code Arduino](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#62-code-arduino)    
7. [Application Android](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#7-application-android)  
8. [Banc de test](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#8-banc-de-test)    
  1 [Banc de test](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#81-banc-de-test-1)    
  2 [Résultats obtenus](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#82-r%C3%A9sultats-obtenus)    
  3 [Analyse des résultats](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#83-analyse-des-r%C3%A9sultats)    
9. [Pistes d’améliorations](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#9-pistes-dam%C3%A9liorations)     
10. [Datasheet](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq#10-datasheet)   

## 1. Livrables  
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


## 2. Matériel requis

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

## 3. Simulation sur LTspice 

Le capteur graphique que nous souhaitons réalisé est alimenté en 5V et sa résistance fluctue entre 20 et 100MΩ, ainsi le courant en sortie sera de l’ordre de 100nA (I =U/R). Ce courant de sortie sera trop faible pour être capté par la carte Arduino UNO, c’est pourquoi nous devons utiliser un amplificateur transimpédance, pour amplifier le signal de sortie de notre capteur. 

Ce montage gère à la fois l’amplification et le filtrage du signal pour limiter l’amplification du bruit.

![Circuit](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/imagesRapport/image%203.jpg?raw=true)  

Voici la fonction des différents composants :
  - R5 en entrée protège l'ampli opérationnel contre les décharges électrostatiques, en forme avec C1 un filtre pour les bruits en tension  
  - C1 avec R1 forme un filtre pour le bruit en courant  
  - R2 sera interchangeable, pour permettre une adaptation du calibre  
  - C4 avec R3 forme un filtre actif  
  - C2 avec R6 forme le filtre de sortie 
  
On peut calculer la résistance du capteur grâce à la formule :

$R_{Capteur} = (1 + \dfrac{R3}{R2}) \times R1 \times (\dfrac{VCC}{VADC}) - R1 - R5$  

Dans notre code Arduino ainsi que dans notre Kicad, notre R4 est égale au R5 du schéma ci-contre et R5 vaut R6 du schéma.   

## 4. Kicad

Nous avons modélisé notre shield PCB sur le logiciel KICAD. Nous avons commencé par dessiner tous les composants puis nous avons créé leur empreinte.  

### 4.1 Symboles et empreintes de composants   

- Amplificateur LTC1050  
  
![Ampli](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/imagesRapport/image%204.jpg?raw=true)  

- Ecran OLED  

![OLED](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/assets/123974749/09e4a31a-6486-44ba-bfba-36fdb46bc8d2)
  

- Flex sensor  

![Flex](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/imagesRapport/image%206.jpg?raw=true)   

- Module Bluetooth HC05  

![Bluetooth](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/imagesRapport/image%2078.jpg?raw=true)  


### 4.2 Schématique  

Une fois les empreintes créées, nous avons réalisé le schéma de notre shield.  

![shield](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/imagesRapport/image%208.jpg?raw=true)  

### 4.3 Placement des composants  

![placementcompo](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/imagesRapport/image%209.jpg?raw=true)  

### 4.4 Visualisation 3D  

Nous avons téléchargé les modèles 3D de nos composants afin de visualiser notre PCB en 3D et de vérifier que les composants de la carte ne se chevauchent pas.   
 
![3D](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/imagesRapport/image%2010.jpg?raw=true)  

## 5. Fabrication du shield  

![shield](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/imagesRapport/image%2011.jpg?raw=true)  

![shield2](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/imagesRapport/image%2012.jpg?raw=true)  

### 5.1 Réalisation du PCB  

Nous avons réalisé notre PCB avec l’aide de Catherine Crouzet au sein du département du Génie Physique et du Génie Electrique et Informatique de l’INSA Toulouse. Pour fabriquer notre PCB nous avons utilisé une plaquette d’époxy recouverte d’une fine couche de cuivre. Nous avons d’abord imprimé notre modélisation du PCB réalisé sur Kicad. Nous avons ensuite plongé notre plaquette avec notre modélisation imprimée dans une machine insolant des UVs.  
Notre modélisation imprimée va servir de masque lors de cette insolation sous UVs. A l’aide d’un révélateur, nous avons retiré la partie de la résine non insolée. Nous plongeons ensuite la plaquette dans un bain de perchlorure de fer pour la gravure. Le cuivre non protégé par la résine est éliminé. Pour finir, nous lavons notre plaquette à l’acétone pour éliminer les dernières traces de résine.   


### 5.2 Perçage et soudure de nos composants   

Nous perçons ensuite notre PCB à l’aide d’une perceuse électrique pour insérer nos composants. Le diamètre de nos percage varie selon le type de composant :   
-	0,8 mm : pour l’AOP LTC1050, le module OLED, Bluetooth, le Flex sensor, les résistances et les capacités
-	1,0 mm : pour les broches de connexion de la carte Arduino UNO.  
Nous avons soudé nos composants sur la face arrière du PCB. Nous avons cependant constaté des courts-circuits sur la carte PCB qui nous ont obligé à souder des fils reliés à la masse sur la face avant de notre PCB.  

## 6. Arduino  

### 6.1 Bibliothèques utilisées    

Nous avons utilisé 3 bibliothèques dans notre code Arduino :  
-	Wire.h : qui s’occupe de la communication avec l’écran OLED ;  
-	SoftwareSerial.h : pour définir les ports utilisés par le module Bluetooth ;  
-	Adafruit_SSD1306.h : afin de contrôler notre écran OLED.   

### 6.2 Code Arduino   

Notre code permet de récupérer la tension à la sortie du capteur et de calculer la valeur de sa résistance. Nous avons rajouté des éléments sur le shield pour faciliter la communication de l’information :    
-	Un écran OLED : l’écran reçoit la valeur de la résistance (en MΩ) du capteur en continu 
-	Un module Bluetooth : qui envoie les données à l’application  
-	Un Flex sensor : dont la valeur de la résistance et la valeur de son angle sont affichés dans le Serial Monitor. Sa présence nous permet de vérifier les démarches réalisées sur le capteur.  

## 7. Application Android   

Nous avons créé une application android sur Mit App Inventor que nous avons pu télécharger via le .apk du dossier. 
Le but de notre application est d’afficher la valeur de la tension de sortie du capteur en continu sur un téléphone Android et de tracer un graphique de la valeur de sa résistance en fonction du temps. C’est l’application qui va calculer la valeur de la résistance du capteur. 
Notre interface comprend :  
-	Un bouton connexion au Bluetooth de notre shield. Il devient vert quand la connexion est établie et grise quand elle ne l’est pas.   
-	Un bouton déconnexion au Bluetooth. Il devient rouge quand on appuie dessus.  
-	La valeur de la tension de sortie du capteur en continu.   
-	Un graphique affichant la valeur de la résistance de notre capteur en fonction du temps.   

## 8. Banc de test   

### 8.1 Banc de test   

Nous avons testé notre capteur sur un banc de test disponible au Génie Physique de l’INSA Toulouse. Notre banc de test composé de 7 demi cylindres de rayon allant de 2,5cm à 1cm par pas de 0,5cm.   

![banc1](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/imagesRapport/image%2013.jpg?raw=true)  
![banc2](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/imagesRapport/image%2014.jpg?raw=true)  

En enrobant les cylindres avec notre capteur, nous créons une déformation que nous pouvons calculer avec la formule :   

$\epsilon = \dfrac{e}{2 \times R_{Capteur}}$   

avec l’épaisseur du papier : e = 0,3 mm et l’angle de la deformation : θ  

et $R_{Capteur} = \dfrac{d}{2 \times θ}$  

![explication](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/imagesRapport/image%2016%C2%B5.jpg?raw=true)  

![explication2](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/imagesRapport/image%202.jpg?raw=true)  

La contrainte mécanique (compression ou expansion) appliquée au papier va modifier la distance entre les particules de graphite et donc la résistance au passage du courant :  
-	Lorsque l’on enrobe le cylindre avec la face recouverte de graphite vers le haut, nous appliquons une tension ou expansion à notre papier, ainsi les particules de graphite se retrouve plus éloignées. Par conséquent le courant circule moins facilement et la valeur de la résistance augmente.   
-	A l’inverse, lorsque l’on enrobe le cylindre avec la face recouverte de graphite contre le cylindre, nous appliquons une compression à notre papier, ainsi les particules de graphite se rapprochent. Par conséquent le courant circule plus facilement et la valeur de la résistance diminue.   

_Attention : Plus nous utilisons la jauge de contrainte, plus nous l’abîmons. En effet, la quantité de graphite diminue avec le temps à cause du frottement des pinces en métal ou des doigts avec le papier._   


### 8.2 Résultats obtenus  

La caractérisation de notre capteur est basé sur la mesure des variations de la résistance dû à la déformation.  

![graph1](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/imagesRapport/image%2018.jpg?raw=true)

![graph2](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/imagesRapport/image%2017.jpg?raw=true)  

### 8.3 Analyse des résultats   

Les résultats obtenus semblent cohérents. En effet, on observe bien une résistance qui diminue lorsqu’on applique une compression au capteur. Par conséquent ΔR (=R-R0) diminue plus la déformation est grande. Et à l’inverse on observe une résistance grandissante lorsqu’on applique une expansion à notre capteur. Par conséquent ΔR (=R-R0) augmente plus la déformation est importante.  

De plus, en fonction du type de crayon utilisé, les variations de résistances changent. En effet, si un crayon est considéré comme gras c’est qu’il dépose plus de graphite sur le papier. Par conséquent le courant aura plus de facilité à passer et donc la résistance sera plus faible. Ainsi nous pouvons constater que les crayons de type B sont plus gras que les crayons de type HB.   

### 8.4 Comparaison avec le flex sensor  

![graph3](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/imagesRapport/image%2019.jpg?raw=true)  

Nous avons analysé la variation de la résistance du flex sensor pour le comparer avec notre capteur. Nous pouvons constater que le flex sensor possède une valeur de résistance plus importante que notre capteur de graphite.   

## 9. Pistes d'améliorations 

Certains points de notre banc de test peuvent être remis en question :  
-	Le dépôts de graphite est difficile à maîtriser. Par conséquent il est impossible de créer plusieurs jauge de contraintes identiques. De plus, la quantité de graphite diminue avec le temps à cause du frottement des pinces en métal ou des doigts avec le papier.  
-	Nous aurions pu rajouter sur notre shield un potentiomètre digital qui nous aurait permis de pouvoir analyser une gamme de résistance plus grande.   


## 10. Datasheet  

La datasheet de notre capteur est disponible [ICI](https://github.com/MOSH-Insa-Toulouse/2022-2023-4gp-bourguet-cuzacq/blob/main/Datasheet/Datasheet_low_tech_graphitr_based_on_strain_sensor.pdf).  


### Remerciement et contact 

Nous souhaiterions remercier Catherine Crouzet qui nous a beaucoup aidé à comprendre et à solutionner nos problèmes tout au long du projet.  

Pour toutes questions ou informations supplémentaires, vous pouvez nous contacter par mail :  
-	Solène BOURGUET : bourguet@insa-toulouse.fr   
-	Victor CUZACQ : cuzacq@insa-toulouse.fr   










