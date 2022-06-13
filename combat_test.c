#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

#define charsize 100

int fight1, fight2, loop, defenseloop, playerhabil, monsenergy = 10, monsenergy2 = 12, damgemonster, damagemonster2, energy = 99, monschoice = 0, combatloop2, combatloop, damagemonster, numroll, hability = 20, monshability = 8, luck = 99, monshability2 = 10, i;
char combatroll[charsize], luckhit[charsize];

void enter(){
    printf("\n\n                                                                                                        Aperte \033[1;35m\"ENTER\"\033[0;37m para continuar                                                                                                        ");
    getch();
    system("cls");
}

void death(){
    printf("You're dead");
}

void dice1(){ // RODA UM DADO
    for(i = 0; i < 1; i++){
        numroll = (rand() % 6 - 1 + 1) + 1;
        printf("Resultado do dado: %d", numroll);
    }
}

void dice2(){ // RODA DOIS DADOS
    for(i = 0; i < 1; i++){
        numroll = (rand() % 12 - 2 + 1) + 2; // (upper - lower + 1)) + lower
        printf("Resultado dos dados: %d", numroll);
    }
}

void luck_damage(){
    printf("\n\033[1;33mVocê deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
    printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
    while(loop < 1){
        gets(luckhit);
        if(strcasecmp(luckhit, "sim") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                printf("\n\nSua SORTE: %d", luck);
                monsenergy -= 2;
                loop++;
            }
            else{
                luck--;
                printf("\n\nSua SORTE: %d", luck);
                monsenergy += 1;
                loop++;
            }
            printf("\n\n");
        }
        else if(strcasecmp(luckhit, "nao") == 0){
            loop++;
        }
    }
}

void luck_damage2(){ // Deals luck damage to the 2 monster (2v2 combat)
    printf("\n\033[1;33mVocê deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
    printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
    while(loop < 1){
        gets(luckhit);
        if(strcasecmp(luckhit, "sim") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                printf("\n\nSua SORTE: %d", luck);
                monsenergy2 -= 2;
                loop++;
            }
            else{
                luck--;
                printf("\n\nSua SORTE: %d", luck);
                monsenergy2 += 1;
                loop++;
            }
            printf("\n\n");
        }
        else if(strcasecmp(luckhit, "nao") == 0){
            loop++;
        }
    }
}

void luck_defense(){
    printf("\n\033[1;33mVocê deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
    printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
    while(loop < 1){
        gets(luckhit);
        if(strcasecmp(luckhit, "sim") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                printf("\n\nSua SORTE: %d", luck);
                energy += 1;
                loop++;
            }
            else{
                luck--;
                printf("\n\nSua SORTE: %d", luck);
                energy -= 1;
                loop++;
            }
            printf("\n\n");
        }
        else if(strcasecmp(luckhit, "nao") == 0){
            loop++;
        }
    }
}

void defenseTurn2(){
    printf("A VEZ DOS MONSTROS: DEFENDA-SE!");
    while(defenseloop < 1){
        loop = 0;
        printf("\nRode os dados:\n");
        printf("\033[0;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        gets(combatroll);
        if(strcasecmp(combatroll, "roll") == 0){
            dice2();
            damagemonster = numroll + monshability;
            printf("\n\nFORÇA DE ATAQUE DOS MONSTROS: %d\n", damagemonster2);
            dice2();
            playerhabil = numroll + hability;
            printf("\n\nSUA DEFESA: %d\n", playerhabil);
        }
        if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster2){
            printf("\nVOCê CONSEGUIU SE DEFENDER!");
            defenseloop += 1;
            fight1 += 1;
            combatloop2 += 1;
            enter();
        }
        if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster2){
            printf("\nVOCE LEVOU DANO\n");
            luck_defense();
            energy -= 2;
            printf("SEU HP: %d", energy);
            fight1 += 1;
            defenseloop += 1;
            combatloop2 += 1;
            enter();
        }
    }
}

void defenseTurn1(){ // Defense Turn Monster 1 (Who attacks is the monster 2)
    printf("A VEZ DOS MONSTROS: DEFENDA-SE!");
    while(defenseloop < 1){
        loop = 0;
        printf("\nRode os dados:\n");
        printf("\033[0;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        gets(combatroll);
        if(strcasecmp(combatroll, "roll") == 0){
            dice2();
            damagemonster2 = numroll + monshability;
            printf("\n\nFORÇA DE ATAQUE DOS MONSTROS: %d\n", damagemonster2);
            dice2();
            playerhabil = numroll + hability;
            printf("\n\nSUA DEFESA: %d\n", playerhabil);
        }
        if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster2){
            printf("\nVOCê CONSEGUIU SE DEFENDER!");
            defenseloop += 1;
            fight1 += 1;
            combatloop2 += 1;
            enter();
        }
        if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster2){
            printf("\nVOCE LEVOU DANO\n");
            luck_defense();
            energy -= 2;
            printf("SEU HP: %d", energy);
            fight1 += 1;
            defenseloop += 1;
            combatloop2 += 1;
            enter();
        }
    }
}

void combat1(){
    printf("COMEÇOU O COMBATE!");
    combatloop = 0;
    while(combatloop < 1){
        loop = 0;
        printf("\nRode os dados:\n");
        printf("\033[0;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        scanf("%s", &combatroll);
        if(strcasecmp(combatroll, "roll") == 0){
            dice2();
            playerhabil = numroll + hability;
            printf("\n\nSUA FORÇA DE ATAQUE: %d\n\n", playerhabil);

            dice2();
            damagemonster = numroll + monshability;
            printf("\n\nFORÇA DE ATAQUE DO MONSTRO: %d\n", damagemonster);
        }
        if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster){
            printf("\nVOCê CAUSOU DANO\n");
            monsenergy -= 2;
            luck_damage();
            printf("HP MONSTRO: %d", monsenergy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
            printf("\nVOCE LEVOU DANO\n");
            luck_defense();
            energy -= 2;
            printf("SEU HP: %d", energy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil == damagemonster){
            printf("\nAMBOS CONSEGUIRAM SE DEFENDER E NINGUÉM SE MACHUCOU");
            enter();
        }
        if(energy <= 0){
            death();
        }
        else if (monsenergy <= 0){
            combatloop += 1;
            printf("VOCE GANHOU O COMBATE");
            enter();
        }
        system("cls");
    }
}

void combat2(){
    printf("COMEÇOU O COMBATE!");
    combatloop = 0;
    fight1 = 0;
    fight2 = 0;
    while(combatloop < 1){
        loop = 0;
        combatloop2 = 0;
        printf("\nRode os dados:\n");
        printf("\033[1;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        while(combatloop2 < 1){
        gets(combatroll);
            if(strcasecmp(combatroll, "roll") == 0)
            {
                printf("DIGITE O INIMIGO QUE VOCE QUER ATACAR\n");
                if(monsenergy > 0)
                    printf("MONSTRO 1: \"digite 1\"\n");
                if(monsenergy2 > 0)
                    printf("MONSTRO 2: \"digite 2\"\n");
                else
                    printf("\n");
            }
            scanf("%d", &monschoice);
            if(monschoice == 1 && monsenergy > 0){
                defenseloop = 0;
                fight1 = 0;
                loop = 0;
                while(fight1 < 1){
                    if(strcasecmp(combatroll, "roll") == 0){
                        dice2();
                        playerhabil = numroll + hability;
                        printf("\n\nSUA FORÇA DE ATAQUE: %d\n", playerhabil);

                        dice2();
                        damagemonster = numroll + monshability;
                        printf("\nFORÇA DE ATAQUE DO MONSTRO 1: %d\n", damagemonster);
                    }
                    if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster){
                        printf("\nVOCê CAUSOU DANO\n");
                        monsenergy -= 2;
                        luck_damage();
                        printf("HP MONSTRO: %d", monsenergy);
                        enter();
                        defenseTurn1();
                    }
                    else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
                        printf("\nVOCE LEVOU DANO\n");
                        luck_defense();
                        energy -= 2;
                        printf("SEU HP: %d", energy);
                        enter();
                        printf("A VEZ DOS MONSTROS: DEFENDA-SE!");
                        while(defenseloop < 1){
                            loop = 0;
                            printf("\nRode os dados:\n");
                            printf("\033[0;31m");
                            printf("DIGITE ROLL\n");
                            printf("\033[0;37m");
                            gets(combatroll);
                            if(strcasecmp(combatroll, "roll") == 0){
                                dice2();
                                damagemonster2 = numroll + monshability;
                                printf("\nFORÇA DE ATAQUE DOS MONSTROS: %d\n", damagemonster2);
                                dice2();
                                playerhabil = numroll + hability;
                                printf("\n\nSUA DEFESA: %d\n", playerhabil);
                            }
                            if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster2){
                                printf("\nVOCê CONSEGUIU SE DEFENDER!");
                                defenseloop += 1;
                                fight1 += 1;
                                combatloop2 += 1;
                                enter();
                            }
                            if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster2){
                                printf("\nVOCE LEVOU DANO\n");
                                luck_defense();
                                energy -= 2;
                                printf("SEU HP: %d", energy);
                                defenseloop += 1;
                                enter();
                            }
                        }
                    }
                    if(energy <= 0){
                        death();
                    }
                    else if (monsenergy <= 0){
                        fight1 += 2;
                        printf("VOCE GANHOU O COMBATE\n\n");
                        printf("COMEÇE O COMBATE COM O PROXIMO MONSTRO");
                        monshability = monshability2;
                        monsenergy = monsenergy2;
                        enter();
                        combat1();
                    }
                    if(fight1 == 2 && fight2 == 2){
                        combatloop2 += 1;
                        combatloop += 1;
                        system("cls");
                    }
                }
            }
            if(monschoice == 2 && monsenergy2 > 0){
                defenseloop = 0;
                fight2 = 0;
                loop = 0;
                while(fight2 < 1){
                    if(strcasecmp(combatroll, "roll") == 0){
                        dice2();
                        playerhabil = numroll + hability;
                        printf("\n\nSUA FORÇA DE ATAQUE: %d\n", playerhabil);

                        dice2();
                        damagemonster2 = numroll + monshability2;
                        printf("\nFORÇA DE ATAQUE DO MONSTRO 1: %d\n", damagemonster2);
                    }
                    if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster2){
                        printf("\nVOCê CAUSOU DANO\n");
                        monsenergy2 -= 2;
                        luck_damage2();
                        printf("HP MONSTRO: %d", monsenergy2);
                        enter();
                        printf("A VEZ DOS MONSTROS: DEFENDA-SE!");
                        while(defenseloop < 1){
                            loop = 0;
                            printf("\nRode os dados:\n");
                            printf("\033[0;31m");
                            printf("DIGITE ROLL\n");
                            printf("\033[0;37m");
                            gets(combatroll);
                            if(strcasecmp(combatroll, "roll") == 0){
                                dice2();
                                damagemonster = numroll + monshability;
                                printf("\nFORÇA DE ATAQUE DOS MONSTROS: %d\n", damagemonster);
                                dice2();
                                playerhabil = numroll + hability;
                                printf("\n\nSUA DEFESA: %d\n", playerhabil);

                            }if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster){
                                printf("VOCê CONSEGUIU SE DEFENDER!");
                                defenseloop += 1;
                                fight2 += 1;
                                combatloop2 += 1;
                                enter();

                            }if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
                                printf("\nVOCE LEVOU DANO\n");
                                luck_defense();
                                energy -= 2;
                                printf("SEU HP: %d", energy);
                                defenseloop += 1;
                                fight2 += 1;
                                combatloop2 += 1;
                                enter();
                            }
                        }
                    }
                    else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster2){
                        printf("\nVOCE LEVOU DANO\n");
                        luck_defense();
                        energy -= 2;
                        printf("SEU HP: %d", energy);
                        enter();
                        printf("A VEZ DOS MONSTROS: DEFENDA-SE!");
                        while(defenseloop < 1){
                            loop = 0;
                            printf("\nRode os dados:\n");
                            printf("\033[0;31m");
                            printf("DIGITE ROLL\n");
                            printf("\033[0;37m");
                            gets(combatroll);
                            if(strcasecmp(combatroll, "roll") == 0){
                                dice2();
                                damagemonster = numroll + monshability;
                                printf("\nFORÇA DE ATAQUE DOS MONSTROS: %d\n", damagemonster);

                                dice2();
                                playerhabil = numroll + hability;
                                printf("\n\nSUA DEFESA: %d\n", playerhabil);

                            }if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster){
                                printf("VOCê CONSEGUIU SE DEFENDER!");
                                defenseloop += 1;
                                fight2 += 1;
                                combatloop2 += 1;
                                enter();

                            }if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
                                printf("\nVOCE LEVOU DANO\n");
                                luck_defense();
                                energy -= 2;
                                printf("SEU HP: %d", energy);
                                defenseloop += 1;
                                fight2 += 1;
                                combatloop2 += 1;
                                enter();

                            }
                        }
                    }
                    if(energy <= 0){
                        death();
                    }
                    else if (monsenergy2 <= 0){
                        combatloop2 += 1;
                        fight2 += 2;
                        printf("VOCE GANHOU O COMBATE\n\n");
                        printf("COMEÇE O COMBATE COM O PROXIMO MONSTRO");
                        enter();
                        combat1();
                    }
                    if(fight1 == 2 && fight2 == 2){
                        combatloop2 += 1;
                        combatloop += 1;
                        system("cls");
                    }
                }
            }
        }
    }
}

void main(){
    setlocale(LC_ALL, "");
    srand(time(NULL));
    combat2();
}