# Projet de C
## Semestre 2 Efrei

[![Ubuntu build](https://github.com/DocSystem/ProjetTI202/actions/workflows/cmake-ubuntu.yml/badge.svg)](https://github.com/DocSystem/ProjetTI202/actions/workflows/cmake-ubuntu.yml)
[![macOS build](https://github.com/DocSystem/ProjetTI202/actions/workflows/cmake-macos.yml/badge.svg)](https://github.com/DocSystem/ProjetTI202/actions/workflows/cmake-macos.yml)
[![Windows build](https://github.com/DocSystem/ProjetTI202/actions/workflows/cmake-windows.yml/badge.svg)](https://github.com/DocSystem/ProjetTI202/actions/workflows/cmake-windows.yml)

Un éditeur d'images vectorielles dans le terminal.

## Membres du groupe
 - Gourjon Valentin
 - Souben-Fink Antoine

## Commandes disponibles 


|               Commande               |                                                         Description                                                          |
|:------------------------------------:|:----------------------------------------------------------------------------------------------------------------------------:|
|                `help`                |                                                       Afficher l'aide                                                        |
|               `clear`                |                                                       Effacer l'écran                                                        |
|                `plot`                |                                                       Afficher l'image                                                       |
|                `exit`                |                                                     Quitter le programme                                                     |
|               *Formes*               |                                                                                                                              |
|            `list shapes`             |                                                 Afficher la liste des formes                                                 |
|         `delete shape [id]`          |                                            Supprimer la forme d'identifiant `id`                                             |
|               `erase`                |                                          Supprimer toute les formes du calque actif                                          |
|           `point [x] [y]`            |                                          Ajouter un point au coordonnées (`x`,`y`)                                           |
|      `line [x1] [y1] [x2] [y2]`      |                              Ajouter une ligne entre les coordonnées (`x1`,`y1`) et (`x2`,`y2`)                              |
|      `circle [x] [y] [radius]`       |                                  Ajouter un cercle de centre (`x`,`y`) et de rayon `radius`                                  |
|      `square [x] [y] [length]`       |              Ajouter un carré dont le sommet supérieur gauche à pour coordonnées (`x`,`y`) et de coté  `length`              |
| `rectangle [x] [y] [width] [height]` | Ajouter un rectangle dont le sommet supérieur gauche à pour coordonnées (`x`,`y`), de largeur `width` et de hauteur `height` |
| `polygon [x1] [y1] [...] [xn] [yn]`  |                    Ajouter un polygone dont les sommets sont les coordonnées (`x1`,`y1`) ... (`xn`,`yn`)                     |
|              *Calques*               |                                                                                                                              |
|             `list layer`             |                                                Afficher la liste des calques                                                 |
|          `new layer [name]`          |                                            Créer un nouveau calque de nom `name`                                             |
|             `layer [id]`             |                                            Aller sur le calque d'identifiant `ìd`                                            |
|         `delete layer [id]`          |                                            Supprimer le calque d'identifiant `id`                                            |
|       `set layer visible [id]`       |                                         Rendre le calque d'identifiant `id` visible                                          |
|        `set layer hide [id]`         |                                        Rendre le calque d'identifiant `id` invisible                                         |

