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

char *item;

int slimeDed = 0;

int qvprmpt() {
        printf("What to do?\n1) Move\n2) Look\n3) Use\n4) Attack\n> ");
        action = getAction();
        switch(action) {
                case 1:
                        printf("\nWhich direction?\n"); // one direction B-)
                        if(cannorth == 1)
                                printf("1) Go north\n");
                        if(cansouth == 1)
                                printf("2) Go south\n");
                        if(canwest == 1)
                                printf("3) Go west\n");
                        if(caneast == 1)
                                printf("4) Go east\n");
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
                // why the fuck does this print before the header?
                printf("\nLook at what?\n1)");
                if(item != NULL) {
                        printf("Look at %s", item);
                }
                if(enemy != NULL) {
                        printf("Look at %s", enemy);
                }
                else if(enemy != NULL && item != NULL) {
                        printf("2) Look at %s", enemy);
                }
                printf("> ");
                // i am a moron. Fix this later
                enemy = item = NULL;
                break;
        case 3:
                printf("foo\n");
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
        head;
        txtdiv;
        enemy = "foo";
        item = "bar";

        cannorth = 1; 
        cansouth = 1; 
        caneast = 0; 
        canwest = 0;

        qvprmpt();
        
}

void doRoom1() {
        head;
        txtdiv;
        enemy = NULL;
        
        cnrt = 1;
        csth = 1;

        if(sword == 0) {
                printf("There is a sword on the floor.\nYou take the sword.\n");
                ++sword;
                cont();
        }

        qvprmpt();
}

void doRoom2() {
        head;
        txtdiv ;
        slimeReq = 1;
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
        head;
        txtdiv ;
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
