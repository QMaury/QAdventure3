#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include "rooms.h"
#include "vars.h"
#include "speech.h"

#define qtalk1() walter()

int npc;
int quux; // for strcasecmp();
int have[10];
char playername[51] = "";

int qGetPlayerName() {
        printf("\n\033[1;31m\"What is your name?\"\033[0m\n> ");
        fgets(playername, 50, stdin);
	playername[strlen(playername)-1] = '\0';
}

int qtalkNPC(int *c) { // *c == &npc
        switch(*c) {
                case 1:
                        if(have[1] == 0) {
                                have[1] = 1;
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
                        break;
                
                        // TODO FIX THIS
                case 2:
                        printf("\nAAAAAAaaaA\n");
                        cont();
                        break;
        }
}

/*
int qctstr(int foo) { // cantalk
        quux = strcasecmp(foo, "walter");
        if(quux != 0)
                quux = strcasecmp(canTalk1, "lol");
}
*/

int qtalk(int npc) {
        switch(npc) {
                case 1: //TODO fix this
                        qtalkNPC(&npc); 
                        break;
                case 2:
                        qtalkNPC(&npc); 
                        break;
                default:
                        invalid;
                        break;
        }
}

int qtprompt() {
        printf("\nTalk to whom?\n");
        if(canTalk1 != NULL)
                printf("1) Talk to %s\n", canTalk1);
        if(canTalk2 != NULL)
                printf("2) Talk to %s\n", canTalk2);
        if(canTalk3 != NULL)
                printf("3) Talk to %s", canTalk3);
        if(canTalk4 != NULL)
                printf("4) Talk to %s", canTalk4);
        printf("> ");
        sResp = getAction(); 
        switch(sResp) {
                case 1:
                        qtalk(1);
                        break;
                case 2:
                        qtalk(2);
                        break;
                default:
                        invalid;
                        break;
        }

                
}
