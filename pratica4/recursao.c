#include "recursao.h"
#include <stdio.h>

int max(int x, int y){
    if (x > y)
        return x;
    return y;
}
int mod(int x, int y) {
    // Seu codigo aqui
    if(x == y)
        return 0;
    if(x < y)
        return x;
    return mod(x - y, y);
}

int mdc(int x, int y) {
    // Seu codigo aqui
    if(y == 0)
        return x;
    return mdc(y, mod(x, y));   

}

int mmcRec(int x, int y, int z) {
    // Seu codigo aqui
    if(mod(z, x)== 0 && mod(z, y)==0)
        return z;
    return mmcRec(x, y,z + max(x,y));
}

int mmc(int x, int y) {
    // Seu codigo aqui
    // Esta funcao chama mmcRec passando z como maximo entre x e y
    return mmcRec(x, y, max(x,y));
}

