/* 2021-12-20   23:49
 * written by QMS
 * */

#include <stdio.h>
#include <stdlib.h>

#include "vars.h"
#include "func.h"

#define txtdiv printf("|=========================================|\n\n");

int contRes;

void qcheckItem() {
        // rewrite this at some point when less autistic
        // maybe make use of enums somehow

        if(item == "bar") {
                printf("bar is brown and slimy\n");  // lol
                cont();
        }
        else {
                printf("what the fuck is that thing bro? I never saw anything like that b4\n");
        }
}

void qExit() {
        clear;
        head;
        txtdiv;
        printf("Exit the dungeon?\n\n1) Yes\n2) No\n> ");
        action = getAction();
        switch(action) {
                case 1:
                    clear;
                    head;
                    txtdiv;
                    printf("Goodbye!\n");
                    cont();
                    exit(0);
                    break;
                case 2:
                    break;
                default:
                    invalid;
                    break;
        }
}

void printRoom() {
        printf("You are in room %i, %i\n\n", x, y);
}

void printRoomH() {
        printf("You are in room %i, %i\n", x, y);
}

int getAction() {
	char actionString[80];

	fgets(actionString, sizeof(actionString), stdin);
	return atoi(actionString);;
}

void cont() {
	printf("\n1) Continue\n> ");
	contRes = getAction();
	switch(contRes) {
		case 1:
			break;
	}
        printf("\n");
}
