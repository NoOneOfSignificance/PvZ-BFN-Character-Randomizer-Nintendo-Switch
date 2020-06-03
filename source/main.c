// Include the most common headers from the C standard library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Include the main libnx system header, for Switch development
#include <switch.h>

// Main program entrypoint
int main(int argc, char* argv[])
{
    consoleInit(NULL);

    printf("PvZ BFN Randomizer but it's ported to the Nintendo Switch.\n\nBy zSupremoz\n\n");
    printf("Press one of the buttons below to randomly select a character.-\n");
    printf("\e[1;32m<A> Plants\e[0m\n");
    printf("\e[1;35m<B> Zombies\e[0m\n\n");

    char plants[10][30] = {"Peashooter", "Chomper", "Kernel Corn", "Night Cap", "Snapdragon", "Cactus", "Citron", "Acorn", "Sunflower", "Rose"};
    char zombies[11][30] = {"Foot Soldier", "Imp", "Super Brainz", "80's Action Hero", "Electric Slide", "All-Star", "Captain Deadbeard", "Space Cadet", "Scientist", "Engineer", "Wizard"};
    time_t t;
    srand((unsigned)time(&t));


    while (appletMainLoop()) {
        hidScanInput();

        u32 kdown = hidKeysDown(CONTROLLER_P1_AUTO);

        if (kdown & KEY_A)
        {
            printf("\e[1;32m%s\e[0m\n", plants[rand()%10]);
        }
        if (kdown & KEY_B)
        {
            printf("\e[1;35m%s\e[0m\n", zombies[rand()%11]);
        }

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}
