#include <cmath>

#define DEG2RAD  57.29577951

float distancia(float latitud1, float longitud1, float latitud2, float longitud2) {
        double dist = sin(latitud1 / DEG2RAD) * sin(latitud2 / DEG2RAD)
                + cos(latitud1 / DEG2RAD) * cos(latitud2 / DEG2RAD)
                * cos(longitud2 / DEG2RAD - longitud1 / DEG2RAD);
        return (float) (acos(dist) * 6370.94690683);
}
