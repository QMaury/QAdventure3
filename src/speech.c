#include <stdio.h>
#include <string.h>
#include "func.h"
#include "rooms.h"
#include "vars.h"
#include "speech.h"

int npc;
int have = 0;
char playername[51] = "";

int qGetPlayerName() {
        printf("\n\033[1;31m\"What is your name?\"\033[0m\n> ");
        fgets(playername, 50, stdin);
	playername[strlen(playername)-1] = '\0';
}

int qtalk1() {
        if(have == 0) {
                have = 1;
                qGetPlayerName();
                char dude[5] = "dude";
                int dudeB = strcasecmp(playername, dude);

                if(dudeB == 0)
                        printf("\n\033[1;31m\"Dude. Now that's a name no one would self apply where I come from.\"\n", playername);
                else
                        printf("\n\033[1;31m\"%s, huh? Nice name.\n", playername);
                printf(" My name is Walter.\"\033[0m\n");
                cont();
        }

        else {
                printf("\n\033[1;31m\"Hello, %s.\n What do you want to talk about?\"\033[0m\n",playername);
                printf("1) Ask about the area\n2) Ask why he's here\n3) Nevermind\n> ");
                int resp = getAction();
                printf("\n");
                switch(resp) {
                        case 1:
                                printf("\033[1;31m\"lol this is a cave.\"\033[0m\n");
                                break;
                        case 2: 
                                printf("\033[1;31mnothing here yet.\033[0m\n");
                                break;
                        case 3:
                                break;
                }
                cont();
        }
}

int qtalk(int npc) {
        switch(npc) {
                case 1:
                        qtalk1();
                        break;
        }
}
