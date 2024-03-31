Application de retouche de photos pour le projet d'IHM groupe 4

## Constitution du groupe :

ARTAUD Cyril

BORG Lucas

CASSAGNE Florian

CHAIB Rafik

CONG Viet


Fonctionnalités réalisées :
- 
- Chargement et sauvegarde d'une ou plusieurs images.
- Retouches de bases : redimensionnement, rognage
- Filtres : Luminosité, contraste, saturation, flou avec différentes 
  intensités, puis quelques effets comme "chaud", "froid" et "nuances de gris"
- Fonctions pour annuler une modification, ou rétablir une modification 
  annulée à l'image.


## Choix de conception :

#### Maintenabilité du code

-Respect des principes SOLID, par exemple en faisant en sorte qu'une classe 
corresponde à une seule fonctionnalité, par exemple, la classe 
FilterBrightness qui ne permet que d'ajuster la luminosité de l'image en 
cours d'utilisation. Certaines classes n'ont pas pu respecter totalement les 
principes SOLID ou être bien optimisées, principalement dû à un manque de 
temps ou de coordination.

#### Ergonomie 
- Fenêtre indiquant le chargement du filtre appliqué
- Possibilité d'afficher ou de masquer des groupes de paramètres, comme par 
exemple le widget qui ajuste la luminosité et le contraste


## Aide

- Vous y retrouverez un répertoire "resources/img" dans le code source, qui 
  contient plusieurs images utiles lors de vos tests.