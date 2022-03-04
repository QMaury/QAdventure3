#include <stdio.h>
#include "vars.h"
#include "speech.h"
#include "speech.h"
#include "func.h"
#include "comb.h"

int qcheatmode() {
        printf("\n\033[1;31m/* DEBUG MENU */\033[0m\nNice job finding this, ");
        if(have != 0)
                printf("%s.\n", playername);
        else 
                printf("wiseguy.\n");

        printf("> ");
        int cheatcode = getAction();
        switch(cheatcode) {
        case 22201:
                sword = 0;
                printf("sword is now level %d\n", sword);
                cont();
                break;
        case 22202:
                sword = 1;
                printf("sword is now level %d\n", sword);
                cont();
                break;
        case 22203:
                sword = 2;
                printf("sword is now level %d\n", sword);
                cont();
                break;
        case 22204:
                sword = 3;
                printf("sword is now level %d\n", sword);
                cont();
                break;
        case 22205:
                sword = 4;
                printf("sword is now level %d\n", sword);
                cont();
                break;
        case 22206:
                sword = 5;
                printf("sword is now level %d\n", sword);
                cont();
                break;
        case 22207:                     // change playername
                qGetPlayerName();
                cont();
                break;
        }
}

