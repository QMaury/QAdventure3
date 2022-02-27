#include <stdio.h>
#include <string.h>
#include "func.h"
#include "rooms.h"
#include "vars.h"
#include "speech.h"

int npc;
int have = 0;

int qGetPlayerName() {
        char playername[100] = ""; // TODO make this less retarded
                                   
        printf("What is your name?\n");
        fgets(playername, 100, stdin);
	playername[strlen(playername)-1] = '\0';
        printf("\n\nYour name is %s.", playername);
}

int qtalk1() {
        if(have == 0) {
                qGetPlayerName();
                have = 1;
        }

        else if(have == 1) {
                printf("put something here later");
        }
}

int qtalk(int npc) {
        switch(npc) {
                case 1:
                        qtalk1();
                        break;
        }
}
