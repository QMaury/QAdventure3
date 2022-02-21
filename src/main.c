/* 2021-13-03 */
#include <stdio.h>
#include <stdlib.h>
#include "rooms.h"
#include "func.h"
#include "vars.h"

/* "now this is some high quality autism."
 * 2021-12-20   00:01
 * -QMS
 */
int room;
int ded;
int action;
int optchr;
int h;

int x, y;

/* that's it for tonight. gonna play some vidyas. at least the program works as intended so far, regardless of how small it's task is.
 * 2021-12-20   00:19
 * -QMS
 */
int evilD = 0;

int main(void) {
        clear;
        x = y = ded = room = 0;
        while (!ded || !evilD) {
                if(x == 0 && y == -1)
                        qExit();

                if(x == 0 && y == 0)
                        doRoom0();

                if(x == 0 && y == 1)
                        doRoom1();

                if(x == 0 && y == 2)
                        doRoom2();

                if(x == 0 && y == 3)
                        doRoom3();

                if(x == 0 && y == 4)
                        doRoom4();

                if(x == -1 && y == 2)
                        doRoom11();
                        
                /*
                switch(room) {
                        case 0:
                                doRoom0();
                                break;
                        case 1:
                                doRoom1();
                                break;
                        case 2:
                                doRoom2();
                                break;
                }
                */

                if(ded==1) {
                        printf("> You have died.\n> Game over.\n\n1) Try again?\n2) No. Exit\n> ");
                        action=getAction();
                        switch(action) {
                                case 1:
                                        printf("\n\n");
                                        main();
                                        ded = 0;
                                        break;
                                case 2:
                                        printf("\nGoodbye!");
                                        cont();
                                        exit(0);
                                        break;
                                default:
                                        invalid;
                                        break;
                        }
                } 
        }
}
