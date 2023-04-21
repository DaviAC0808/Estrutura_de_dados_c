#include "poligonos.h"

float CalPerimetroTri(float a, float b, float c)
{
    return a + b + c;
}

float CalPerimetroRet(float a, float b)
{
    return 2 * a + 2 * b;
}

float CalPerimetroCir(float r)
{
    return 2 * PI + r;
}

float CalAreaTri(float b, float a)
{
    return (b * a) / 2;
}

float CalAreaRet(float b, float a)
{
    return b * a;
}

float CalAreaCir(float r)
{
    return 2 * PI * r * r;
}
