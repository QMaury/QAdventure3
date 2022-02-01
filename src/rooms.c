/* 2021-12-20   23:36
 * written by QMS 
 * */

/* I do not feel like coding right now but, I have been too lazy for too long. look at me go.
 * 2021-12-20   23:38
 * - QMS 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vars.h"
#include "func.h"
#include "comb.h"

#define txtdiv printf("\n|=========================================|\n\n");
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

int qDirCheck() {
        // this is fucking embarrassing
        
        if(enemy == NULL) {
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
                                if(cnrt == 0)
                                        invalid();
                                else
                                        ++y;
                                break;
                        case 2:
                                if(csth == 0)
                                        invalid();
                                else
                                        --y;
                                break;
                        case 3:
                                if(cwst == 0)
                                        invalid();
                                else
                                        --x;
                                break;
                        case 4:
                                if(cest == 0)
                                        invalid();
                                else
                                       ++x;
                                break;
                        default:
                                invalid();
                                break;
                }
        }
        else {
                printf("under construction\n");
        }
        cest = cwst = csth = cnrt = 0;
}

int qItemCheck() {
        if(item != NULL) 
                puts("quux");
}

int qFoeCheck() {
        if(enemy != NULL){
                printf("A %s blocks your path.\n", enemy);
                /* "oof. maybe this'll work??"          2021-12-25      09:23   QMS */
        }
        else { 
                printf("This room has no enemies.\n");
                // printf("");
        }
}

void doRoom0() {
        txtdiv
        enemy = NULL;

        cannorth = 1; 
        cansouth = 1; 
        caneast = 0; 
        canwest = 0;

        printRoom();
        qDirCheck();
        
}

void doRoom1() {
        txtdiv
        enemy = NULL;
        
        cnrt = 1;
        csth = 1;
        
        printf("There is a sword on the floor.\nYou take the sword.\n");
        sword = 1;
        cont();

        printRoom();
        qDirCheck();
}

void doRoom2() {
        txtdiv
        enemy = "Slime";
        if(sword > slimeReq) {
                printf("You have killed the slime!\n");
                enemy = NULL;
        }
        else {
                printf("The slime attacks!\n");
                ded = 1;
        }

        cnrt = 1;
        csth = 1;
        cwst = 1;

        printRoom();
        qDirCheck();
}
// something fucks up here

void doRoom3() {
        txtdiv ;
        cnrt = 1;
        csth = 1;
        cest = 1;

        // wtf i fixed it?
        // i deleted "printRoom()", it started working, I put it back, and now it just works??
        printRoom();
        qDirCheck();
}

void doRoom4() {
        txtdiv ;
        enemy = NULL;
        cnrt = 1;
        csth = 1;

        printRoom();
        qDirCheck();
}

// this looks like shit

void doRoom11() {
        txtdiv ;
        enemy = NULL;
        cest = 1;
        printRoom();
        
        qDirCheck();
}
