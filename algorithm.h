// Scribble Vibes
// Authors : Valentin Gourjon & Antoine Souben-Fink
// Ce fichier contient les algorithmes de tracé de formes basiques : Ligne, Cercle, Courbe de Bézier


#ifndef PROJETTI202_ALGORITHM_H
#define PROJETTI202_ALGORITHM_H

#include "geometry.h"
#include "double_chained_list.h"

void traceLine(Line* line, List* pixel);
void traceCircle(Circle* circle, List* pixel);

void traceCurve(Curve* curve, List* pixel);

#endif //PROJETTI202_ALGORITHM_H
