#ifndef FUNCS_H_
#define FUNCS_H_

float **lineGet(int, float, float, float, float, float);
float **lineFromPts(int, float, float, float, float, float, float);
float **pointsGet();
float **normPlot(int, int, float, float, float);
void free_multi_memory(float**, int);

#endif
