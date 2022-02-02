/* 2021-12-21   21:32   QMS */

#include <stdio.h>
#include <stdlib.h>

#include "vars.h"
#include "rooms.h"

char *enemy;

int slimeReq = 1;

void fight() {
        if(enemy != NULL) {
                if(enemy == "Slime") {
                        if(sword >= slimeReq) {
                                printf("You slay the Slime\n");
                        }
                        else
                                ded = 1;
                }
        }
}
