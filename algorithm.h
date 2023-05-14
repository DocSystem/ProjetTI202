//
// Created by antoine7805 on 15/03/2023.
//

#ifndef PROJETTI202_ALGORITHM_H
#define PROJETTI202_ALGORITHM_H
#include "geometry.h"
#include "double_chained_list.h"

void traceLine(Line* line, List* pixel);
void traceCircle(Circle* circle, List* pixel);

void traceCurve(Curve* curve, List* pixel);

#endif //PROJETTI202_ALGORITHM_H
