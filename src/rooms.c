#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "vars.h"
#include "func.h"
#include "comb.h"

#define cnrt cannorth
#define csth cansouth
#define cwst canwest
#define cest caneast

int cannorth = 0;
int cansouth = 0; 
int canwest = 0; 
int caneast = 0;
int sword = 0;
int verb;
int lResp;
int room;

char *item;

int slimeDed = 0;

void qcheckItem() {
        // rewrite this at some point when less autistic
        // TODO
        if(item == "bar") {
                printf("bar is brown and slimy\n");  // lol
        }
        else if(item == "sword") {
                printf("The sword on the floor sits there, unused.\n");
        }
        else {
                printf("what the fuck is that thing bro? I never saw anything like that b4\n");
        }
        cont();
}

void qcheckRoom() {
        if(room == 0) {
                printf("You are at the entrance to the cave. You can travel north or south from here.\n");
                cont();
        }
}


int qvprmpt() {
        clear;
        head;
        txtdiv;
        printf("What to do?\n1) Move\n2) Look\n3) Use\n4) Attack\n> ");
        verb = getAction();
        switch(verb) {
                case 1:
                        printf("\nWhich direction?\n"); // one direction B-)
                        if(cannorth == 1)
                                printf("1) Go north\n");
                        if(cansouth == 1)
                                printf("2) Go south\n");
                        if(canwest == 1)
                                printf("3) Go west\n");
                        if(caneast == 1)
                                printf("4) Go east\n"); // TODO "how to update variables in header file C"
                        printf("> ");

                         
                        action = getAction();
                        switch(action) {
                                case 1:
                                        if(cnrt == 0) {
                                                invalid;
                                        }
                                        else
                                                ++y;
                                        break;
                                case 2:
                                        if(csth == 0) {
                                                invalid;
                                        }
                                        else
                                                --y;
                                        break;
                                case 3:
                                        if(cwst == 0) {
                                                invalid; 
                                        }
                                        else
                                                --x;
                                        break;
                                case 4:
                                        if(cest == 0) {
                                                invalid
                                        }
                                        else
                                               ++x;
                                        break;
                                default:
                                        invalid;
                                        break;
                        }
                        cest = cwst = csth = cnrt = 0;
                        break;

                case 2:
                        clear;
                        head;
                        txtdiv;
                        printf("Look at what?\n1)");
                        if(item != NULL) {
                                printf(" Look at %s\n", item);
                        }

                        printf("2) ");
                        if(enemy != NULL) {
                                printf("Look at %s\n", enemy);
                        }
                        else 
                                printf("Look at the room\n");
                        if(enemy != NULL && item != NULL) 
                                printf("3) Look at the room\n");
                        printf("> ");

                        if(enemy != NULL) {
                                lResp = getAction();
                                switch(lResp) {
                                        case 1:
                                                qcheckItem();
                                                break;
                                        case 2:
                                                printf("ehh scary %s\n", enemy); // TODO
                                                cont();
                                                break;
                                        case 3:
                                                qcheckRoom();
                                                break;

                                        default:
                                                invalid;
                                                break;
                                }
                        }

                        else {
                                lResp = getAction();
                                switch(lResp) {
                                        case 1:
                                                qcheckItem();
                                                break;
                                        case 2:
                                                qcheckRoom();
                                                break;

                                        default:
                                                invalid;
                                                break;
                                }
                        }
                        // i am a moron. Fix this later
                        enemy = item = NULL;
                        break;
                case 3:
                        printf("UNDER CONSTRUCTION\n");
                        cont();
                        break;
        }
}
/*
int qFoeCheck() {
        if(enemy != NULL){
                printf("A %s blocks your path.\n", enemy);
        }
        else { 
                printf("This room has no enemies.\n");
        }
}
*/

void doRoom0() {
        enemy = NULL;
        room = 0;
        item = "bar";

        cannorth = 1; 
        cansouth = 1; 
        caneast = 0; 
        canwest = 0;

        qvprmpt();
        
}

void doRoom1() {
        clear;
        head;
        txtdiv;

        room = 1;
        item = "sword";
        enemy = NULL;
        
        cnrt = 1;
        csth = 1;

        qvprmpt();
}

void doRoom2() {
        clear;
        head;
        txtdiv ;
        slimeReq = 1;
        room = 2;
        enemy = "Slime";
        if(slimeDed == 0) {
                printf("A %s blocks your path!\nDo you fight it?\n\n1) Yes fight the %s\n2) No, leave the room\n> ", enemy, enemy);
                action = getAction();
                switch(action) {
                        case 1:
                                head;
                                txtdiv;
                                printf("You grab your sword and stab at the %s, successfully killing it!\n\n", enemy);
                                slimeDed = 1;

                                cnrt = 1;
                                csth = 1;
                                cwst = 1;
                                qvprmpt();
                                break;
                        case 2:
                                printf("\n");
                                csth = 1;
                                qvprmpt();
                                break;
                        default:
                                invalid;
                                break;
                }

        }
        else if(slimeDed == 1) { 
                printf("This room has nothing but a sticky green puddle on the ground.\n\n");

                cnrt = 1;
                csth = 1;
                cwst = 1;
                qvprmpt();
        }

}

void doRoom3() {
        clear;
        head;
        txtdiv ;
        room = 3; 
        cnrt = 1;
        csth = 1;
        cest = 1;

        qvprmpt();
}

void doRoom4() {
        head;
        txtdiv ;
        enemy = NULL;
        cnrt = 1;
        csth = 1;

        qvprmpt();
}

void doRoom5() {
        head;
        txtdiv;
        enemy = NULL;
        
        cnrt = 1;
        csth = 1;
        qvprmpt();
}

void doRoom11() {
        head;
        txtdiv ;
        enemy = NULL;
        cest = 1;

        printf("This room is empty except for an ominous looking staircase leading down to some lower level of the dungeon.\n");
        printf("You have a sickening feeling that qms has not yet developed this part of the game, so you decide not to go down there.\n\n");
        
        qvprmpt();
}
