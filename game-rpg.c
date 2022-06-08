#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <time.h>



// VARIABLES
int godmode = 0; // GAMEMODE
char gamestarter[10], nome[20], startroll[10], invname[20] = "INVENTARIO", itemchoice[15], chinventory; // names - ROLLS & CHOICES
int numroll, choices, invuse; // numbers - ROLLS & CHOICES
int a, b, c = 1, i, loop = 0, luckloop = 0, jeweloop = 0; length, columns, rows; // DESIGN
int provisions = 10, gold, hability = 99, first_hability, energy = 99, first_energy, luck = 99, first_luck, dards; // STATUS POINTS

int hability_potion = 0, luck_potion = 0, energy_potion = 0, jewel = 0, emerald = 0, sapphire = 0, iron_hook = 0, iron_key = 0, wood_tube = 0, rope = 0, metal_bell = 0, brass_bell = 0, chalice = 0, morph_potion = 0, leather_wristband = 0, monkey_amulet = 0, dagger = 0, ruby = 0, topaz = 0, wooden_legs = 0, old_bone = 0, shield = 0, wish_ring = 0, moringa_acid = 0, diamond = 0, grenade = 0, energy_ring;// ITENS

int read_skeleton_scroll = 0, high_temperature_potion = 0, knowledge_morph_potion = 0, knowledge_bloody_beast = 0, skill_trap_potion = 0, knowledge_deadgirl_poem = 0, disarmed = 0;// SKILLS AND KNOWLEDGE

int status_OP006 = 0, status_OP226 = 0, status_OP162 = 0, status_OP257 = 0, status_OP150 = 0, status_OP011 = 0, status_OP020 = 0, status_OP028 = 0, status_OP033 = 0, status_OP052 = 0, status_OP171 = 0, status_OP244 = 0, status_OP256 = 0, status_OP094 = 0, status_OP095 = 0, status_OP105 = 0, status_OP106 = 0, status_OP114 = 0, status_OP123 = 0, status_OP147 = 0, status_OP157 = 0, status_OP169 = 0, status_OP175 = 0, status_OP229 = 0, status_OP240 = 0, status_OP251 = 0, status_OP270 = 0, status_OP285 = 0, status_OP308 = 0, status_OP337 = 0, status_OP363 = 0, status_OP375 = 0, status_OP391 = 0, status_OP397 = 0, status_OP026 = 0, status_OP038 = 0, status_OP042 = 0, status_OP045 = 0, status_OP072 = 0, status_OP057 = 0, status_OP103 = 0, status_OP158 = 0, status_OP165 = 0, status_OP167 = 0, status_OP341 = 0, status_OP269 = 0, status_OP330 = 0, status_OP336 = 0, status_OP127 = 0, status_OP115 = 0; //status no repating variables

// COMBAT VARIABLES
int combatloop = 0, combatloop2 = 0, defenseloop = 0, monsenergy, monsenergy2, monshability, monshability2, damagemonster, damagemonster2, numrollmonster, playerhabil, monschoice, fight1, fight2, atkseries;
char combatroll[8], luckhit[5];

// SAVE VARIABLES
int stageops;

// COLORS
void colors(){
    system("COLOR 0A");
    printf("\033[1;30m a"); // BLACK
    printf("\033[1;31m a"); // RED
    printf("\033[1;32m a"); // GREEN
    printf("\033[1;33m a"); // YELLOW
    printf("\033[1;34m a"); // BLUE
    printf("\033[1;35m a"); // PURPLE
    printf("\033[1;36m a"); // CYAN
    printf("\033[0;37m a"); // WHITE
    system("cls");
}

// SAVING PROCESS
void save(){
    FILE * fSave;

    fSave = fopen("save.txt", "w");
    fprintf(fSave, "ITENS: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", hability_potion, luck_potion, energy_potion, jewel, emerald, sapphire, iron_hook, iron_key, wood_tube, rope, metal_bell, brass_bell, chalice, morph_potion, leather_wristband, monkey_amulet, dagger, ruby, topaz, wooden_legs, old_bone, shield, wish_ring, moringa_acid, diamond, grenade, energy_ring); // ITENS

    fprintf(fSave, "STATUS: %d %d %d %d %d\n", energy, hability, provisions, luck, gold); // STATUS

    fprintf(fSave, "stageops: %d\n", stageops);

    fprintf(fSave, "godmode: %d\n", godmode);

    fprintf(fSave, "NAME: %s\n", nome); // NAME

    fprintf(fSave, "NO-REPEATING: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", status_OP006, status_OP226, status_OP162, status_OP257, status_OP150, status_OP011, status_OP020, status_OP028, status_OP033, status_OP052, status_OP171, status_OP244 , status_OP256, status_OP094, status_OP095, status_OP105, status_OP106, status_OP114, status_OP123, status_OP147, status_OP157, status_OP169, status_OP175, status_OP229, status_OP240, status_OP251, status_OP270, status_OP285, status_OP308, status_OP337, status_OP363, status_OP375, status_OP391, status_OP397, status_OP026, status_OP038, status_OP042, status_OP045, status_OP072, status_OP057, status_OP103, status_OP158, status_OP165, status_OP167, status_OP341, status_OP269, status_OP330, status_OP336, status_OP127, status_OP115); // no repeating

    fprintf(fSave, "SKILLS:%d %d %d %d %d %d %d\n", read_skeleton_scroll, high_temperature_potion, knowledge_morph_potion, knowledge_bloody_beast, skill_trap_potion, knowledge_deadgirl_poem, disarmed);


    fclose(fSave);
}

void load(){

    FILE * fSave;


    fSave = fopen("save.txt", "r");

    fscanf(fSave, "ITENS: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &hability_potion, &luck_potion, &energy_potion, &jewel, &emerald, &sapphire, &iron_hook, &iron_key, &wood_tube, &rope, &metal_bell, &brass_bell, &chalice, &morph_potion, &leather_wristband, &monkey_amulet, &dagger, &ruby, &topaz, &wooden_legs, &old_bone, &shield, &wish_ring, &moringa_acid, &diamond, &grenade, &energy_ring); // ITENS

    fscanf(fSave, "STATUS: %d %d %d %d %d\n", &energy, &hability, &provisions, &luck, &gold); // STATUS

    fscanf(fSave, "stageops: %d\n", &stageops);

    fscanf(fSave, "godmode: %d\n", &godmode);

    fscanf(fSave, "NAME: %s\n", &nome); // NAME

    fscanf(fSave, "NO-REPEATING: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &status_OP006, &status_OP226, &status_OP162, &status_OP257, &status_OP150, &status_OP011, &status_OP020, &status_OP028, &status_OP033, &status_OP052, &status_OP171, &status_OP244 , &status_OP256, &status_OP094, &status_OP095, &status_OP105, &status_OP106, &status_OP114, &status_OP123, &status_OP147, &status_OP157, &status_OP169, &status_OP175, &status_OP229, &status_OP240, &status_OP251, &status_OP270, &status_OP285, &status_OP308, &status_OP337, &status_OP363, &status_OP375, &status_OP391, &status_OP397, &status_OP026, &status_OP038, &status_OP042, &status_OP045, &status_OP072, &status_OP057, &status_OP103, &status_OP158, &status_OP165, &status_OP167, &status_OP341, &status_OP269, &status_OP330, &status_OP336, &status_OP127, &status_OP115); // no repeating


    fscanf(fSave, "SKILLS:%d %d %d %d %d %d %d\n", &read_skeleton_scroll, &high_temperature_potion, &knowledge_morph_potion, &knowledge_bloody_beast, &skill_trap_potion, &knowledge_deadgirl_poem, &disarmed);

    fclose(fSave);

    printf("\nBem vindo novamente %s\n", nome);
    printf("\033[1;32m\nSKILLS INSTAURADAS");
    printf("\nITENS INSTAURADOS");
    printf("\nSTATUS INSTAURADOS");
    printf("\nESTÁGIO: %d\n\033[0;37m", stageops);
    if(stageops == 0){
        printf("\n\nVocê não possui save");
        enter();
        startchar();
    }else if(stageops == 1){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP001();
    }else if(stageops == 9){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP009();
    }else if(stageops == 10){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP010();
    }else if(stageops == 11){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP011();
    }else if(stageops == 12){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP012();
    }else if(stageops == 13){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP013();
    }else if(stageops == 14){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP014();
    }else if(stageops == 16){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP016();
    }else if(stageops == 22){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP022();
    }else if(stageops == 24){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP024();
    }else if(stageops == 31){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP031();
    }else if(stageops == 35){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP035();
    }else if(stageops == 37){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP037();
    }else if(stageops == 39){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP039();
    }else if(stageops == 41){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP041();
    }else if(stageops == 43){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP043();
    }else if(stageops == 47){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP047();
    }else if(stageops == 49){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP049();
    }else if(stageops == 52){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP052();
    }else if(stageops == 53){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP053();
    }else if(stageops == 55){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP055();
    }else if(stageops == 56){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP056();
    }else if(stageops == 59){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP059();
    }else if(stageops == 60){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP060();
    }else if(stageops == 62){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP062();
    }else if(stageops == 65){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP065();
    }else if(stageops == 66){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP066();
    }else if(stageops == 68){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP068();
    }else if(stageops == 73){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP073();
    }else if(stageops == 74){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP074();
    }else if(stageops == 75){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP075();
    }else if(stageops == 76){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP076();
    }else if(stageops == 78){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP078();
    }else if(stageops == 81){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP081();
    }else if(stageops == 88){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP088();
    }else if(stageops == 90){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP090();
    }else if(stageops == 93){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP093();
    }else if(stageops == 99){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP099();
    }else if(stageops == 100){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP100();
    }else if(stageops == 102){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP102();
    }else if(stageops == 105){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP105();
    }else if(stageops == 107){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP107();
    }else if(stageops == 108){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP108();
    }else if(stageops == 109){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP109();
    }else if(stageops == 110){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP110();
    }else if(stageops == 113){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP113();
    }else if(stageops == 114){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP114();
    }else if(stageops == 117){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP117();
    }else if(stageops == 119){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP119();
    }else if(stageops == 120){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP120();
    }else if(stageops == 121){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP121();
    }else if(stageops == 122){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP122();
    }else if(stageops == 126){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP126();
    }else if(stageops == 128){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP128();
    }else if(stageops == 129){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP129();
    }else if(stageops == 132){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP132();
    }else if(stageops == 134){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP134();
    }else if(stageops == 136){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP136();
    }else if(stageops == 137){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP137();
    }else if(stageops == 138){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP138();
    }else if(stageops == 146){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP146();
    }else if(stageops == 153){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP153();
    }else if(stageops == 155){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP155();
    }else if(stageops == 156){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP156();
    }else if(stageops == 159){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP159();
    }else if(stageops == 163){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP163();
    }else if(stageops == 164){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP164();
    }else if(stageops == 168){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP168();
    }else if(stageops == 170){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP170();
    }else if(stageops == 173){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP173();
    }else if(stageops == 179){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP179();
    }else if(stageops == 182){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP182();
    }else if(stageops == 183){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP183();
    }else if(stageops == 184){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP184();
    }else if(stageops == 185){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP185();
    }else if(stageops == 187){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP187();
    }else if(stageops == 188){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP188();
    }else if(stageops == 192){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP192();
    }else if(stageops == 194){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP194();
    }else if(stageops == 197){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP197();
    }else if(stageops == 200){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP200();
    }else if(stageops == 205){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP205();
    }else if(stageops == 207){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP207();
    }else if(stageops == 210){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP210();
    }else if(stageops == 213){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP213();
    }else if(stageops == 214){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP214();
    }else if(stageops == 216){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP216();
    }else if(stageops == 218){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP218();
    }else if(stageops == 220){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP220();
    }else if(stageops == 221){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP221();
    }else if(stageops == 222){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP222();
    }else if(stageops == 226){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP226();
    }else if(stageops == 230){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP230();
    }else if(stageops == 232){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP232();
    }else if(stageops == 234){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP234();
    }else if(stageops == 237){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP237();
    }else if(stageops == 239){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP239();
    }else if(stageops == 240){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP240();
    }else if(stageops == 241){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP241();
    }else if(stageops == 249){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP249();
    }else if(stageops == 250){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP250();
    }else if(stageops == 258){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP258();
    }else if(stageops == 259){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP259();
    }else if(stageops == 260){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP260();
    }else if(stageops == 262){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP262();
    }else if(stageops == 263){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP263();
    }else if(stageops == 264){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP264();
    }else if(stageops == 267){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP267();
    }else if(stageops == 273){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP273();
    }else if(stageops == 281){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP281();
    }else if(stageops == 282){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP282();
    }else if(stageops == 284){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP284();
    }else if(stageops == 285){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP285();
    }else if(stageops == 287){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP287();
    }else if(stageops == 288){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP288();
    }else if(stageops == 292){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP292();
    }else if(stageops == 293){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP293();
    }else if(stageops == 299){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP299();
    }else if(stageops == 300){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP300();
    }else if(stageops == 301){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP301();
    }else if(stageops == 305){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP305();
    }else if(stageops == 307){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP307();
    }else if(stageops == 308){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP308();
    }else if(stageops == 310){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP310();
    }else if(stageops == 315){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP315();
    }else if(stageops == 316){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP316();
    }else if(stageops == 318){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP318();
    }else if(stageops == 320){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP320();
    }else if(stageops == 321){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP321();
    }else if(stageops == 324){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP324();
    }else if(stageops == 328){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP328();
    }else if(stageops == 330){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP330();
    }else if(stageops == 337){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP337();
    }else if(stageops == 338){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP338();
    }else if(stageops == 339){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP339();
    }else if(stageops == 341){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP341();
    }else if(stageops == 342){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP342();
    }else if(stageops == 343){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP343();
    }else if(stageops == 344){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP344();
    }else if(stageops == 351){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP351();
    }else if(stageops == 352){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP352();
    }else if(stageops == 356){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP356();
    }else if(stageops == 357){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP357();
    }else if(stageops == 360){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP360();
    }else if(stageops == 364){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP364();
    }else if(stageops == 365){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP365();
    }else if(stageops == 367){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP367();
    }else if(stageops == 368){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP368();
    }else if(stageops == 376){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP376();
    }else if(stageops == 379){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP379();
    }else if(stageops == 381){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP381();
    }else if(stageops == 382){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP382();
    }else if(stageops == 385){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP385();
    }else if(stageops == 388){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP388();
    }else if(stageops == 390){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP390();
    }else if(stageops == 392){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP392();
    }else if(stageops == 393){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP393();
    }else if(stageops == 394){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP394();
    }else if(stageops == 396){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP396();
    }else if(stageops == 397){
        printf("\n\nVocê irá para o estágio de onde parou");
        enter();
        OP397();
    }
}
// MENU START GAME
void startmenu(){
    loop = 0;

    colors();
    printf("\033[1;37m----------------------------------------------------------------------------------------------------------- A MASMORRA DA MORTE ------------------------------------------------------------------------------------------------------------\033[0;37m");
    printf("                                                                                                        Digite \033[1;35m\"START\"\033[0;37m para começar                                                                                                         \n");
    printf("                                                                                                         Digite \033[1;35m\"LOAD\"\033[0;37m para carregar                                                                                                         \n");

    printf("                                                                                                                      ");
    while(loop<1){
        gets(gamestarter);
        if(strcasecmp(gamestarter, "start") == 0){
            printf("\n\tNo interior do labirinto escuro e sinuoso de Fang há horrores desconhecidos à  sua espera. Concebido pela mente diabólica do barão Sukumvit, o labirinto está infestado de armadilhas mortais e monstros sedentos sangue, os quais submeterão SUAS habilidades a testes quase além do limite possível de resistência. Inúmeros aventureiros aceitaram o desafio da \"Prova dos Campeões\" e atravessaram a porta talhada em forma de boca do labirinto para nunca mais voltar. VOCê se atreve a entrar?\n\tTentado pela promessa de um prêmio fabuloso, e pelo fascínio do desafio nunca superado, VOCÊ está entre os seis guerreiros experientes que se preparam para enfrentar o labirinto. Somente um pode chegar à  saída e vencer, os demais perecerão... \033[1;33mPor fim, diga-me aventureiro, quem é você?\033[0;37m");
            loop++;
        }
        if(strcasecmp(gamestarter, "load") == 0){
            loop++;
            printf("LOAD CARREGADO COM SUCESSO\n");
            load();
        }
    }
    enter();
    startchar();
}

void godmodeactivation(){
    system("cls");
    first_energy = 100;
    first_hability = 100;
    first_luck = 100;
    energy = 100;
    hability = 100;
    luck = 100;
    gold = 100;
    provisions = 100;

    printf("\t\033[1;33m- GODMODE FOI ATIVADO -\n\n");
    printf("SEUS STATUS FORAM TODOS DEFINIDOS PARA 100\033[0;37m");
    printf("\n\n\033[1;33mSua ENERGIA:\033[0;37m %i", energy);
    printf("\n\033[1;33mSua HABILIDADE:\033[0;37m %i", hability);
    printf("\n\033[1;33mSua SORTE:\033[0;37m %i", luck);
    printf("\n\033[1;33mSeu GOLD:\033[0;37m %d", gold);
    printf("\n\033[1;33mSuas PROVISÕES:\033[0;37m %d\n\n", provisions);
    printf("\033[1;36mTODOS OS ITENS COLETÁVEIS AGORA ESTÃO NO SEU INVENTÁRIO\n");
    hability_potion = 1; luck_potion = 1, energy_potion = 1, emerald = 1, sapphire = 1, iron_hook = 0, iron_key = 1, wood_tube = 1, rope = 1, metal_bell = 1, brass_bell = 1, chalice = 1, morph_potion = 1, leather_wristband = 1, monkey_amulet = 1, dagger = 1, ruby = 1, topaz = 1, wooden_legs = 1, old_bone = 1, shield = 1, wish_ring = 1, moringa_acid = 1, diamond = 1;
    printf("TODOS AS SKILLS COLETÁVEIS AGORA ESTÃO NO SEU INVENTÁRIO\033[0;37m\n");
    read_skeleton_scroll = 1, high_temperature_potion = 1, knowledge_morph_potion = 1, knowledge_bloody_beast = 1, skill_trap_potion = 1, knowledge_deadgirl_poem = 1;
    enter();
    OP001();
}
// CREATION OF CHARACTER

void startchar(){
    loop = 0;
    printf("\033[0;31m");
    printf("INSIRA SEU NOME: ");
    printf("\033[0;37m");
    gets(nome);
    if(godmode != 0)
        printf("GODMODE - Para ativar digite \"GODMODE\"\n\n");
    printf("Muito bem %s, agora vamos definir seus valores de habilidade e energia.\n\033[1;33mDigite \"ROLL\" para rolar os dados.\033[0;37m\n\n", nome);
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            system("cls");

            dice1();
            printf("\nSua HABILIDADE foi setada para:");
            printf("\033[1;32m %d", numroll + 6);
            printf("\033[0;37m");
            first_hability = numroll + 6;
            hability = first_hability;

            printf("\nSua ENERGIA foi setada para:");
            printf("\033[1;31m %d", numroll + 12);
            printf("\033[0;37m\n");
            first_energy = numroll + 12;
            energy = first_energy;

            dice2();
            printf("\nSua SORTE foi setada para:");
            printf("\033[1;33m %d", numroll + 6);
            printf("\033[0;37m");
            first_luck = numroll + 6;
            luck = first_luck;
            loop++;
        }if(strcasecmp(startroll, "godmode")== 0){
            loop++;
            godmodeactivation();
        }
    }

    enter();
    loop = 0;

        printf("Escolha uma das três poções para carregar na sua jornada\n\n");
        printf("POÇÃO DE \033[0;32mHABILIDADE\033[0;37m - Repõe os pontos de HABILIDADE.");
        printf("\nPOÇÃO DA \033[0;31mFORCA\033[0;37m - repõe os pontos de ENERGIA.");
        printf("\nPOÇÃO DA \033[0;33mFORTUNA\033[0;37m - repõe os pontos de SORTE e acrescenta 1 ponto à  SORTE Inicial");

    while(loop < 1){
        printf("\033[1;35m");
        printf("\n\n Digite o nome colorido da poção escolhida para selecionar: ");
        gets(itemchoice);
        if(strcasecmp(itemchoice, "habilidade") == 0){
            hability_potion += 1;
            printf("A poção de HABILIDADE foi adicionada a seu inventário");
            loop++;
        } else if (strcasecmp(itemchoice, "forca") == 0){
            energy_potion += 1;
            printf("A poção de FORÇA foi adicionada a seu inventário");
            loop++;
        } else if (strcasecmp(itemchoice, "fortuna") == 0){
            luck_potion += 1;
            printf("A poção de FORTUNA foi adicionada a seu inventário");
            loop++;
        }
    }
    provisions = 10;
    printf("\033[1;37m");
    save();
    enter();
    resume();
}

// COMBATS

void combat1(){
    printf("COMEÇOU O COMBATE!");
    combatloop = 0;
    while(combatloop < 1){
        loop = 0;
        printf("\nRode os dados:\n");
        printf("\033[0;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        gets(combatroll);
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
            printf("HP MONSTRO: %d", monsenergy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
            printf("\nVOCE LEVOU DANO\n");
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
            if(strcasecmp(combatroll, "roll") == 0){
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
                        printf("HP MONSTRO: %d", monsenergy);
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
                                        }else{
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy -= 1;
                                            loop++;
                                        }
                                        printf("\n\n");
                                    }else if(strcasecmp(luckhit, "nao") == 0)
                                        loop++;
                                }
                                energy -= 2;
                                printf("SEU HP: %d", energy);
                                fight1 += 1;
                                defenseloop += 1;
                                combatloop2 += 1;
                                enter();
                            }
                        }
                    }
                    else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
                        printf("\nVOCE LEVOU DANO\n");
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
                                        }else{
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy -= 1;
                                            loop++;
                                        }
                                        printf("\n\n");
                                    } else if(strcasecmp(luckhit, "nao") == 0)
                                        loop++;
                                }
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
                                        }else{
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy -= 1;
                                            loop++;
                                        }
                                        printf("\n\n");
                                    } else if(strcasecmp(luckhit, "nao") == 0)
                                        loop++;
                                }

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
                                        }else{
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy -= 1;
                                            loop++;
                                        }
                                        printf("\n\n");
                                    } else if(strcasecmp(luckhit, "nao") == 0)
                                        loop++;
                                }

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

// DICES

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

// MORTE
void death(){
    provisions = 0, gold = 0, hability = 0, first_hability, energy = 0, first_energy, luck = 0, first_luck, dards; // STATUS POINTS

    hability_potion = 0, luck_potion = 0, energy_potion = 0, jewel = 0, emerald = 0, sapphire = 0, iron_hook = 0, iron_key = 0, wood_tube = 0, rope = 0, metal_bell = 0, brass_bell = 0, chalice = 0, morph_potion = 0, leather_wristband = 0, monkey_amulet = 0, dagger = 0, ruby = 0, topaz = 0, wooden_legs = 0, old_bone = 0, shield = 0, wish_ring = 0, moringa_acid = 0, diamond = 0, grenade = 0; // ITENS RESET

    read_skeleton_scroll = 0, high_temperature_potion = 0, knowledge_morph_potion = 0, knowledge_bloody_beast = 0, skill_trap_potion = 0, knowledge_deadgirl_poem = 0, disarmed = 0;// SKILLS AND KNOWLEDGE

    status_OP006 = 0, status_OP226 = 0, status_OP162 = 0, status_OP257 = 0, status_OP150 = 0, status_OP011 = 0, status_OP020 = 0, status_OP028 = 0, status_OP033 = 0, status_OP052 = 0, status_OP171 = 0, status_OP244 = 0, status_OP256 = 0, status_OP094 = 0, status_OP095 = 0, status_OP105 = 0, status_OP106 = 0, status_OP114 = 0, status_OP123 = 0, status_OP147 = 0, status_OP157 = 0, status_OP169 = 0, status_OP175 = 0, status_OP229 = 0, status_OP240 = 0, status_OP251 = 0, status_OP270 = 0, status_OP285 = 0, status_OP308 = 0, status_OP337 = 0, status_OP363 = 0, status_OP375 = 0, status_OP391 = 0, status_OP397 = 0, status_OP026 = 0, status_OP038 = 0, status_OP042 = 0, status_OP045 = 0, status_OP072 = 0, status_OP057 = 0, status_OP103 = 0, status_OP158 = 0, status_OP165 = 0, status_OP167 = 0, status_OP341 = 0, status_OP269 = 0, status_OP330 = 0, status_OP336 = 0;
    
    stageops = 0; // Stage


    save();
    printf("\n\n                                                                               Sua aventura chegou ao fim héroi. Aperte \033[1;31m\"ENTER\"\033[0;37m para retornar a tela inicial.                                                                               ");
    enter();
    startmenu();
}

// PRESS ENTER DESIGN EFFECT
void enter(){
    printf("\n\n                                                                                                        Aperte \033[1;35m\"ENTER\"\033[0;37m para continuar                                                                                                        ");
    getch();
    system("cls");
}

void inventory(){
    system("cls");
    while(loop < 1){
    length = strlen(invname);

    columns = length + 4;
    rows = (length / 2)>=3 ? length/2 : 1;

    /* Iterate over each row */
    for(a=1; a<=rows; a++)
    {
        /* Iterate over each column */
        for(b=1; b<=columns; b++)
        {
            if(a==1 || a==rows || b==1 || b==columns)
            {
                /* Print star for 1st and last row, column */
                printf("*");
            }
            else
            {
                if(a==rows/2+1 && b>=3 && b<=columns-2)
                    printf("%c", invname[b-3]);
                else
                    printf(" ");
            }
        }

        /* Move to the next line/row */
        printf("\n");
    }

    printf("\n\nHABILIDADE: ");
    printf("\033[1;32m");
    printf("%d", hability);
    printf("\033[0;37m");
    printf("\nENERGIA: ");
    printf("\033[1;31m");
    printf("%d", energy);
    printf("\033[0;37m");
    printf("\nSORTE: ");
    printf("\033[1;33m");
    printf("%d", luck);
    printf("\033[0;37m");

    printf("\033[1;33m");
    printf("\n\nOURO: %d", gold);
    printf("\033[0;37m");
    printf("\033[1;34m");
    printf("\nPROVISÕES: %d, se deseja usar suas provisões digite \033[1;33m\"9\"\033[0;37m ", provisions);
    printf("\033[0;37m");

    printf("\n\nPOÇÕES:\n");
    if(energy_potion == 0 && luck_potion == 0 && hability_potion == 0)
        printf("\n\033[1;31mVocê não possui POÇÕES\033[0;37m");
    if(luck_potion != 0)
        printf("\nPoção de fortuna: x%d, se deseja usar este item aperte \033[1;33m\"1\"\033[0;37m", luck_potion);
    if(energy_potion != 0)
        printf("\nPoção de força: x%d, se deseja usar este item aperte \033[1;33m\"2\"\033[0;37m", energy_potion);
    if(hability_potion != 0)
        printf("\nPoção de habilidade: x%d, se deseja usar este item aperte \033[1;33m\"3\"\033[0;37m", hability_potion);
    
    printf("\n\nITENS COLETADOS:\n");
    if(iron_hook == 0 && iron_key == 0 && wood_tube == 0 && rope == 0 && metal_bell == 0 && chalice == 0 && morph_potion == 0 && leather_wristband == 0 && high_temperature_potion == 0 && energy_ring && wish_ring == 0)
        printf("\n\033[1;31mVoce não possui ITENS\033[0;37m");
    if(iron_hook != 0)
        printf("\nGancho de Ferro: x%d", iron_hook);
    if(iron_key != 0)
        printf("\nChave de Ferro: x%d", iron_key);
    if(wood_tube != 0)
        printf("\nTubo oco de Madeira: x%d", wood_tube);
    if(rope != 0)
        printf("\nRolo de Corda: x%d", rope);
    if(metal_bell != 0)
        printf("\nSino de Metal: x%d", metal_bell);
    if(chalice != 0)
        printf("\nCálice: x%d", chalice);
    if(morph_potion != 0)
        printf("\nPoção de Réplica: x%d", morph_potion);
    if(leather_wristband != 0)
        printf("\nMunhequeira de Couro: x%d", leather_wristband);
    if(energy_ring != 0)
        printf("\nAnel de Energia: x%d", energy_ring);
    if(wish_ring != 0)
        printf("\nAnel dos Desejos: x%d", wish_ring);

    printf("\n\nJOIAS COLETADAS:\n");
    if(emerald == 0 && jewel == 0 && sapphire == 0 && diamond == 0 && ruby == 0 && topaz == 0)
        printf("\n\033[1;31mVocê não possui JOIAS\033[0;37m");
    if(emerald != 0)
        printf("\nEsmeralda: %d", emerald);
    if(diamond != 0)
        printf("\nDiamante: %d", diamond);
    if(ruby != 0)
        printf("\nRubi: %d", ruby);
    if(topaz != 0)
        printf("\nTopazio: %d", topaz);
    if(sapphire != 0)
        printf("\nSafira: %d", sapphire);
    if(jewel != 0)
        printf("\nJoia: %d", jewel);

    printf("\n\nSKILLS\n");
    if(read_skeleton_scroll == 0 && high_temperature_potion == 0 && knowledge_morph_potion == 0 && knowledge_bloody_beast == 0 && skill_trap_potion == 0 && knowledge_deadgirl_poem == 0 && disarmed == 0)
        printf("\n\033[1;31mVocê não possui SKILLS\033[0;37m");
    if(knowledge_deadgirl_poem != 0)
        printf("\nCONHECIMENTO DO POEMA DA GAROTA MORTA");
    if(read_skeleton_scroll != 0)
        printf("\nCONHECIMENTO PERGAMINHO DO ESQUELETO");
    if(knowledge_bloody_beast != 0)
        printf("CONHECIMENTO DA BESTA SANGRENTA");
    if(high_temperature_potion != 0)
        printf("\nCORPO VULCANICO - RESISTE A ALTAS TEMPERATURAS");
    if(skill_trap_potion != 0)
        printf("6 SENTIDO - VOCê ENXERGA ARMADILHAS");
    if(disarmed != 0)
        printf("\nVocê está DESARMADO");

    printf("\n\nSe deseja sair aperte \"4\"\n");
    printf("Se deseja ler as regras aperte \"0\"\n\n");
        scanf("%d", &invuse);
        if(invuse == 1){ // LUCK
            luck_potion -= 1;
            luck = first_luck + 1;
            printf("\nSUA POÇÃO FOI USADA");
            printf("\n\033[1;33mSua sorte atual: %d\033[0;37m", luck);
            enter();
        }else if(invuse == 2){
            energy_potion -= 1;
            energy = first_energy;
            printf("\nSUA POÇÃO FOI USADA");
            printf("\033[1;32mSua energia atual: %d\033[0;37m", energy);
            enter();
        }else if(invuse == 3){
            hability_potion -= 1;
            hability = first_hability;
            printf("\nSUA POÇÃO FOI USADA");
            printf("\n\033[1;31mSua habilidade atual: %d\033[0;37m", hability);
            enter();
        }else if(invuse == 9){
            provisions -= 1;
            energy += 2;
            printf("\nUMA DE SUAS PROVISÕES FOI UTILIZADA");
            printf("\n\033[1;32mSua ENERGIA atual: %d\033[0;37m", energy);
            enter();
        }else if(invuse == 4){
            loop++;
        }else if(invuse == 0){
            rules();
        }
    }
}

//RULES

void rules(){
    system("cls");
    printf("\t\t------------REGRAS DO JOGO-------------\n\n");
    printf("\tAntes de você poder continuar aventureiro, temos que explicar algumas coisas sobre o jogo. O jogo é bem simples, haverá um texto como esse que você lê e logo abaixo terá sua opções de escolha iguais aos exemplos abaixo:\n\nSe você quiser seguir para a esquerda, \033[1;35mdigite 1.\033[0;37m\nSe quiser ir para a direita, \033[1;35mdigite 2.\033[0;37m\n\n\tAssim você irá digitar o número da opção que você quiser e será levado para tal número e irá executar o que tem escrito no texto seguinte e assim você irá progredir no jogo. \033[1;31mCUIDADO, SE VOCê ESCOLHER A OPÇÃO ERRADA, NÃO HÁ VOLTA!\033[0;37m Em dados momentos do jogo você receberá itens, ganhará \033[1;31mHABILIDADE,  \033[1;32mENERGIA\033[0;37m e \033[1;33mSORTE\033[0;37m assim como as perderá, além disso, você pode receber o que nós chamamos de \033[1;35mSKILL\033[0;37m ou talvez \033[1;31mlutar contra um monstro amedrontador\033[0;37m. HABILIDADE é o atributo que te ajudará em batalhas e em certas situações que exigem certa destrez. Sua SORTE é utilizada em situações específicas ou durante o combate para tentar causar mais dano ou receber menos danos. Sua \033[1;32mENERGIA\033[0;37m é a quantidade de dano que você aguentar receber, se sua ENERGIA chegar a \033[1;31m0\033[0;37m o jogo acaba e você terá que retornar ao início com um novo personagem. As \033[1;35mSKILL\033[0;37m são algum tipo de conhecimento que se adquire ao longo de sua jornada, por exemplo ler um livro, você adquire o conhecimento dentro do livro, porém não leva o livro consigo, assim é considerado uma SKILL um item não físico.\n\n\tO combate contra monstros e outras criaturas não é complicado e tudo será bem automático, além disso todas as informações sobre serão ditas em tela, basta você digitar \033[1;33m\"ROLL\"\033[0;37m quando for pedido. Após rolar os dados, o resultado é somado a sua \033[1;31mHABILIDADE\033[0;37m e assim resultando na sua \033[1;31mFORÇA DE ATAQUE\033[0;37m. O seu adversário faz o mesmo e também junta sua FORÇA DE ATAQUE. Quem tiver maior FORÇA DE ATAQUE causa 2 de dano ao seu oponente e, usando sua sorte, você poderá dobrar o dano ou receber metade do dano.\n\n\tCertas situações também exigiram algum tipo de teste, podendo ser um teste de \033[1;31mHABILIDADE\033[0;37m ou um teste de \033[1;33mSORTE\033[0;37m. O texto irá pedir para você rolar dados e se o resultado for IGUAL OU MENOR que o valor atual do seu atributo, você passou no teste, se o resultado for MAIOR que o valor atual do seu atributo, você falhou no teste...Porém, você não saberá o resultado dos dados e nem mesmo se passou ou não, você apenas será levado até o respectivo texto e você terá que ler as consequências nele, dessa forma criamos uma tensão maior dentro do jogo.\n\n\tPor fim, você ainda poderá conseguir itens ao longo do jogo com efeitos diversos. Maioria dos itens são para situações específicas e são usados apenas quando se é pedido no texto, você notará isso quando se deparar com uma opção como esta:\n\nSe você tiver uma chave e quiser abrir a porta, \033[1;35mdigite 1.\033[0;37m\nSe não tiver o item ou não quiser, \033[1;35mdigite 2.\033[0;37m\n\n\tMesmo que você, jogador malandro, tente ser mais esperto que o jogo e minta tentando digitar o número para ir adiante mesmo não tendo o item, nós, programadores do jogo, fizemos com que isso não aconteça, logo jogue justo e não trapaceie.\n\n\tBom, você está pronto para a aventura, sempre que precisar, \"digite 0\" fora de combate e fora de testes de atributo para acessar seu inventário sempre que for necessário!\n\n\t\033[1;33mSEU JOGO SEMPRE É SALVO EM OPÇÕES DE MULTIPLAS ESCOLHAS!\n\n\tBOM JOGO E OBRIGADO POR JOGAR!\033[0;37m");
    enter();
    inventory();
}


// OPENING

void resume(){
    printf("\t...Sua visão é escura e relaxante. De muito longe você ouve gritos de alegria e aclamação, o forte e frenético bater de palmas de uma multidão e um certo ritmo feito por tambores e berrantes. Todo esse barulho começa aumentar e sua visão é ofuscada pela luz da janela de sua cabine, forçando-o a acordar assustado. Você olha ao redor, retomando o fôlego, logo se recorda de onde está... Você havia se inscrevido para participar do desafio da Prova dos Campeões, cujo vencedor receberá 1 milhão de peças de ouro. O desafio fica em Fang, uma cidade conhecida apenas por essa prova que ocorre anualmente. Você fora escolhido para participar da prova e acaba de acordar no barco que veleja pelo rio Kok até Fang.\n\tVocê e outros 5 desafiantes desembarcam no porto da cidade. Um grande aglomerado de centenas de pessoas os recebem com grande felicidade e hospitalidade. Todos vocês são levados por uma guia de pele escura e longos cabelos negros ondulados vestindo um simples vestido de pano branco, tal guia os leva até uma grande estalagem, talvez a melhor da cidade, chamada Lagarto Trovejante. Você chega na estalagem com o sol alto no céu e até seu anoitecer você é tratado quase como um rei, tudo que é pedido logo é atendido por algum serviçal da cidade. Comida exótica e típica da região lhe é dada assim como a bebida. Finalmente o sol se põe atrás do rio Kok e você é levado para seus aposentos, uma suíte privada enorme para seu descanso e conforto.\n\tVocê se deita em sua cama confortável, porém mal consegue dormir, a ansiedade o mantém acordado por boa parte da noite. Você não sabe o que esperar, os perigos que irá encontrar... Isso o deixa um pouco nervoso... Você finalmente acorda na manhã do dia seguinte. A mesma guia leva você e os outros desafiantes até um estádio pequeno onde se encontra um grande estande com várias espadas penduradas. Você seleciona a espada que melhor te agrada, então uma armadura de couro batido te é entregue, por fim, você recebe uma mochila grande com provisões suficientes para 10 refeições e um enorme cantil para 10 dias de água.\n\tVocê e os outros desafiantes se aquecem por mais ou menos uma hora até que o som de um alto berrante ecoa por toda a cidade, o chamado para o início da aventura... Você é o quarto da fila dos desafiantes seguindo o caminho formado por pessoas de ambos os lados até finalmente chegar numa grande caverna no formato de uma boca de serpente com duas grandes presas bem aparentes. O primeiro competidor adentra a bocanha e uma hora após o primeiro, o segundo entra e assim vai até que sua vez chega. Seu coração bate forte e o nervosismo bate... Você é chamado, você respira fundo e começa a caminhar para dentro do calabouço da morte...\n\nLembre-se, você pode acessar seu inventário digitando \"00\" sempre que necessário (você não poderá abrir o inventário em batalhas).");

    enter();
    OP001();
}

// OPCAO 001

void OP001(){
    stageops = 1;
    save();
    loop = 0;

    printf("\t1 - O clamor dos espectadores excitados some gradualmente atrás de você, que se aventura cada vez mais fundo na penumbra do túnel da caverna... Grandes cristais pendem do teto do túnel a intervalos de 20 metros, irradiando uma luz suave, apenas suficiente para que veja por onde anda. À medida que seus olhos vão pouco a pouco se acostumando à  quase escuridão, você começa a ver movimentos à  sua volta. Aranhas e besouros sobem e descem pelas paredes entalhadas, desaparecendo em frestas e gretas ao sentir sua aproximação, além disso ratazanas e ratos correm pelo chão à  sua frente. Pingos de água caem em pequenas poças com um sinistro som gotejante que ecoa pelo túnel. O ar é frio, úmido e pesado. Depois de caminhar lentamente pelo túnel por uns cinco minutos, você chega a uma mesa de pedra encostada contra a parede à  sua esquerda. Nela há seis caixas, uma das quais tem seu nome pintado na tampa.\n\nSe você quiser abrir a caixa, \033[1;35mdigite 270.\033[0;37m\nSe preferir continuar caminhando para o norte, \033[1;35mdigite 66.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop<1){
        scanf("%d", &choices);
        switch (choices)
        {
        case 270:
            loop++;
            system("cls");
            OP270();
            break;

        case 66:
            loop++;
            system("cls");
            OP066();
            break;

        case 0:
            inventory();
            enter();
            OP001();
            break;

        }
    }
}

//OPÇÃO 002
void OP002(){
    loop = 0;

    printf("\t2 - O Escorpião consegue prendê-lo nas garras por tempo suficiente para mover a cauda segmentada para frente, por sobre a cabeça, e cravar em você o ferrão venenoso. \033[1;31mO efeito é fatal, e você desaba no chão da Arena da Morte, imaginando se Throm conseguirá vencer.\033[0;37m");
    death();
}

//OPÇÃO 003
void OP003(){
    loop = 0;

    printf("\t3 - O Gnomo sacode a cabeça e diz: \"Temo que você não tenha passado pela Prova dos Campeões. Os segredos do Calabouço da Morte do Barão Sukumvit ficarão guardados por mais um ano, pois você não terá permissão para sair daqui. Você foi indicado para ser meu servo pelo resto dos seus dias; \033[1;31mpreparará e modificará o subterrâneo para competidores futuros. Talvez em outra vida você tenha sucesso...\033[0;37m\"");
    death();
}

//OPÇÃO 004
void OP004(){
    loop = 0;

    printf("\t4 - Na escuridão total, você não vê a curva do cano para baixo. Escorrega e, incapaz de se segurar no cano cheio de limo, desliza pela borda. Seus gritos ecoam pelo tubo, enquanto você cai 50 metros até o fundo. \033[1;31mVocê fracassou na Prova dos Campeões.\033[0;37m");
    death();
}

//OPÇÃO 005
void OP005(){
    loop = 0;

    printf("\t5 - Você se arrasta pelo chão e se vê no covil de uma tribo de TROGLODITAS. Ao engatinhar passando por eles, sua bainha bate em uma pedra. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP185();
            }else{
                luck--;
                system("cls");
                OP395();
            }
        }
    }
}

//OPÇÃO 006
void OP006(){
    loop = 0;
    monsenergy = 11;
    monshability = 11;

    printf("\t6 - Sabendo que o Mantécora disparará os espinhos da cauda, Você corre para se proteger atrás de um dos pilares. Antes que consiga chegar lá, uma saraivada de espinhos voa pelo ar, e um deles penetra-lhe o braço. Você perde 2 pontos de ENERGIA. Não perca tempo e ataque o Mantécora com espada, antes que ele possa disparar mais espinhos.\n\n\033[1;31mMANTÉCORA   HABILIDADE 11   ENERGIA 11\033[0;37m\n\n");

    if(status_OP006 == 0){
        energy -= 2;
        status_OP006 += 1;
        printf("\n\nSua ENERGIA: %i", energy);
        enter();
        combat1();
        printf("\n\nSua ENERGIA: %i", energy);
        printf("\n\nVocê conseguiu sobreviver ao monstro!");
        enter();
        OP364();
    }else{
        enter();
        OP364();
    }
}

//OPÇÃO 007
void OP007(){
    loop = 0;
    printf("\t7 - Antes que você tenha tempo de chegar a uma porta, o rochedo já está sobre você, \033[1;31mque grita de dor e medo quando ele o esmaga no chão.\033[0;37m");
    death();
}

//OPÇÃO 008
void OP008(){
    loop = 0;

    printf("\t8 - O Demônio do Espelho agarra-o pelo pulso. Imediatamente, ele começa a puxá-lo na direção do espelho. A força dele é incrível, e, apesar de todos os seus esforços, você não consegue evitar que o arraste progressivamente na direção do espelho. Quando ele toca o espelho, parece desaparecer diretamente através dele. Horrorizado, você vê seu próprio braço desaparecer, seguido pelo resto do corpo. \033[1;31mVocê está agora em um mundo de espelhos de outra dimensão, do qual jamais retornará.\033[0;37m");
    death();
}

//OPÇÃO 009
void OP009(){
    stageops = 9;
    save();
    loop = 0;

    printf("\t9 - Os Hobgoblins não têm nada que lhe seja útil, por isso você resolve abrir o saco no chão. Dentro, acha uma moringa de barro arrolhada. Você a desarrolha e cheira o líquido que contém. O odor é penetrante e acre.\n\nSe quiser beber um pouco do líquido, \033[1;35mdigite 158.\033[0;37m\nSe quiser mergulhar um pedaço de pano nele, \033[1;35mdigite 375.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 158:
                loop++;
                system("cls");
                OP158();
                break;
            case 375:
                loop++;
                system("cls");
                OP375();
                break;
            case 0:
                inventory();
                enter();
                OP009();
                break;
        }
    }
}

//OPÇÃO 010
void OP010(){
    stageops = 10;
    save();
    loop = 0;

    printf("\t10 - Ainda correndo o mais rápido possível, você enfia a mão na mochila e tira o tubo de madeira. Seu plano é ficar sob a água, respirando pelo tubo. Com sorte, os Trogloditas pensarão que você será arrastado até a morte rio abaixo, pois a torrente desaparece nas profundezas da montanha. Você segura o tubo entre os dentes e mergulha na água. Segurando-se em um dos pilares da ponte embaixo d'água, você fica absolutamente imóvel por 10 minutos. Quando finalmente acha que os Trogloditas foram embora, você sobe a superfície e olha em volta. Não há ninguém à  vista, e você sai do rio e atravessa a ponte para a margem norte. Quaisquer Provisões restantes que você possa ter estão agora encharcadas e imprestáveis. Elas foram removidas do seu inventário. Você segue pela vasta caverna até que, finalmente, vê um túnel na parede do outro lado. Você caminha até uma pesada porta de madeira, que está trancada.\n\nSe você tiver uma chave de ferro e quiser abrir, \033[1;35mdigite 86.\033[0;37m\nSe não quiser, \033[1;35mdigite 276.\033[0;37m");

    printf("\033[1;34mLEMBRE-SE, VOCÊ PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 86:
                loop++;
                system("cls");
                OP086();
                break;
            case 276:
                loop++;
                if(iron_key != 0){
                    system("cls");
                    OP276();
                } else{
                    printf("Você não possui este item.");
                    enter();
                    OP010();
                }
                break;
            case 0:
                inventory();
                enter();
                OP010();
                break;
        }
    }
}

//OPÇÃO 011
void OP011(){
    stageops = 11;
    save();
    loop = 0;

    printf("\t11 - Você olha para baixo e vê os corpos esparramados dos Guardiões Voadores imóveis no chão. Então, começa a forçar o olho de esmeralda do ídolo para retirá-lo com a ponta da espada. Finalmente, ele se solta, e você fica surpreso com o peso da jóia. Esperando que possa ser útil mais tarde, você o coloca na mochila.\n\nSe quiser agora retirar o olho direito, \033[1;35mdigite 140.\033[0;37m\nSe preferir descer do ídolo, \033[1;35mdigite 46.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");


    while(loop < 1){
        if(status_OP011 == 0){
            jewel += 1;
            status_OP011 += 1;
            printf("Esmelda foi adicionada ao seu inventário.");
            scanf("%i", &choices);
            switch(choices){
                case 140:
                    loop++;
                    system("cls");
                    OP140();
                    break;
                case 46:
                    loop++;
                    system("cls");
                    OP046();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP011();
                    break;
            }
        }else{
            printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
            scanf("%i", &choices);
            switch(choices){
                case 140:
                    loop++;
                    system("cls");
                    OP140();
                    break;
                case 46:
                    loop++;
                    system("cls");
                    OP046();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP011();
                    break;
            }
        }
    }
}

//OPÇÃO 012
void OP012(){
    stageops = 12;
    save();
    loop = 0;

    printf("\t12 - A porta abre para um grande aposento iluminado por velas, repleto das mais extraordinárias estátuas, de aparência real, representando guerreiros e cavaleiros. Um velho de cabelos brancos, trajando trapos esfarrapados, salta de trás de uma das estátuas e começa a dar risinhos. Uma centelha nos olhos dele faz com que você pense que algo se esconde por trás daquela aparência de idiota. Numa voz estridente, ele diz: \"Bom, mais uma pedra para meu jardim. Fico feliz que você tenha vindo se juntar a seus amigos. Sou um homem justo, e por isso vou lhe fazer uma pergunta. Se responder corretamente, ficará livre - mas, se sua resposta estiver errada, eu o transformarei em pedra!\" Ele volta a dar risadinhas, obviamente feliz com sua chegada. Você:\n\nEsperará pela pergunta? \033[1;35mDigite 382.\033[0;37m\nVai atacá-lo com sua espada? \033[1;35mDigite 195.\033[0;37m\nCorrerá para a porta? \033[1;35mDigite 250.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 382:
                loop++;
                system("cls");
                OP382();
                break;
            case 195:
                loop++;
                system("cls");
                OP195();
                break;
            case 250:
                loop++;
                system("cls");
                OP250();
                break;
            case 0:
                inventory();
                enter();
                OP012();
                break;
        }
    }
}

//OPCAO 013
void OP013(){
    stageops = 13;
    save();
    loop = 0;

    printf("\t13 - O túnel faz uma curva abrupta para a esquerda e se dirige para o norte, tanto quanto a sua vista alcança. As pegadas que você está seguindo começam a sumir à  medida que o túnel vai ficando mais seco. Logo não vê mais o teto gotejante e as poças no chão. Você repara que o ar está se tornando mais quente, e se vê ofegante, embora esteja andando bem devagar. Em uma pequena reentrância da parede da esquerda, você vê um pedaço de bambu na vertical. Levantando-o, repara que ele está cheio de um líquido claro. Sua garganta está dolorosamente seca, e você se sente um pouco tonto por causa do calor no túnel.\n\nSe quiser beber o líquido, \033[1;35mdigite 147.\033[0;37m\nSe não quiser se arriscar a beber e preferir continuar para o norte, \033[1;35mdigite 182.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch (choices){
            case 147:
                loop++;
                system("cls");
                OP147();
                break;
            case 182:
                loop++;
                system("cls");
                OP182();
                break;
            case 0:
                inventory();
                enter();
                OP013();
                break;
        }
    }
}

//OPCAO 014
void OP014(){
    stageops = 14;
    save();
    loop = 0;

    printf("\t14 - O túnel conduz a uma câmara escura, coberta de espessas teias de aranha. Abrindo caminho entre elas, você tropeça em um pequeno cofre de madeira.\n\nSe quiser tentar abrir o cofre, \033[1;35mdigite 157.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 310.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 157:
                loop++;
                system("cls");
                OP157();
                break;
            case 310:
                loop++;
                system("cls");
                OP310();
                break;
            case 0:
                inventory();
                enter();
                OP014();
                break;
        }
    }
}

//OPCAO 015
void OP015(){
    loop = 0;

    printf("\t15 - Uma sensação de cócegas desce pela sua espinha enquanto você se arrasta cuidadosamente para fora do aposento. De volta ao túnel, você solta um suspiro de alívio e fecha a porta com força. Feliz com sua boa sorte, parte para o oeste mais uma vez.");

    enter();
    OP074();
}

//OPCAO 016
void OP016(){
    stageops = 16;
    save();
    loop = 0;

    printf("\t16 - Você só teve tempo de ouvir o Gnomo dizer: \"Três crânios\", antes que um raio branco de energia disparasse da fechadura e o atingisse no peito, derrubando-o inconsciente. Jogue um dado, o resultado mais 1 é reduzido do total da sua ENERGIA. Se você ainda estiver vivo, recupera a consciência e o Gnomo manda que tente de novo. Você escolheu as gemas erradas da outra vez; portanto, não tentará aquela combinação novamente.\n\n    A         B         C     \nEsmeralda|Diamante |Safira    -> \033[1;35mDigite 16.\033[0;37m\nDiamante |Safira   |Esmeralda -> \033[1;35mDigite 392.\033[0;37m\nSafira   |Esmeralda|Diamante  -> \033[1;35mDigite 177.\033[0;37m\nEsmeralda|Safira   |Diamante  -> \033[1;35mDigite 287.\033[0;37m\nDiamante |Esmeralda|Safira    -> \033[1;35mDigite 132.\033[0;37m\nSafira   |Diamante |Esmeralda -> \033[1;35mDigite 249.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 16:
                loop++;
                system("cls");
                OP016();
                break;
            case 392:
                loop++;
                system("cls");
                OP392();
                break;
            case 177:
                loop++;
                system("cls");
                OP177();
                break;
            case 287:
                loop++;
                system("cls");
                OP287();
                break;
            case 132:
                loop++;
                system("cls");
                OP132();
                break;
            case 249:
                loop++;
                system("cls");
                OP249();
                break;
            case 0:
                inventory();
                enter();
                OP016();
                break;
        }
    }
}

//OPCAO 017
void OP017(){
    loop = 0;

    printf("\t17 - Você não é forte o bastante para forçar e abrir a pesada porta. A água já está na cintura agora, e você está exausto por causa dos esforços. O nível da água sobe rapidamente, e você se vê boiando cada vez mais alto. Até que seu rosto fica imprensado contra o teto. \033[1;31mLogo fica completamente imerso e não tem como prender a respiração por mais tempo.\033[0;37m");
    death();
}

//OPCAO 018
void OP018(){
    loop = 0;

    printf("\t18 - Para sorte sua, os dentes da naja se cravam na munhequeira de couro que você está usando. A serpente se enrosca de novo bem depressa, pronta para lançar outro ataque, quando o Anão ordena que você faça mais uma tentativa. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");


    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP055();
            }else{
                system("cls");
                OP202();
            }
        }
    }
}

//OPCAO 19
void OP019(){
    loop = 0;

    printf("\t19 - Você não consegue resistir ao olhar hipnótico da Medusa quando seus olhares se encontram. \033[1;31mSente os membros enrijecerem e entra em pânico, indefeso, enquanto se transforma em pedra.\033[0;37m");
    death();
}

//OPCAO 20
void OP020(){
    loop = 0;

    printf("\t20 - Somente sua incrível força poderia resistir à  mordida da aranha venenosa. Contudo, você está enfraquecido e repara que sua mão está tremendo ao colocar a Peça de Ouro no bolso. \033[1;31mReduza sua HABILIDADE em 1 ponto\033[0;37m. Você amaldiçoa a pessoa que largou a mochila e parte para o norte de novo.\n\n");

    if(status_OP020 == 0){
        hability -= 1;
        gold += 1;
        status_OP020 += 1;
        printf("Você perdeu 1 de HABILIDADE");
        printf("\nSua HABILIDADE: %i", hability);
        printf("\033[1;33m");
        printf("\n\nVocê ganhou 1 de GOLD");
        printf("\033[0;37m");
        printf("\nSeu GOLD: %d", gold);
        enter();
        OP279();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP279();
    }
}

//OPCAO 21
void OP021(){
    loop = 0;

    printf("\t21 - O ferimento não teve qualquer efeito sobre a Besta Sangrenta, que continua a atacá-lo tão furiosamente quanto antes. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP097();
            }else{
                luck--;
                system("cls");
                OP116();
            }
        }
    }
}

//OPCAO 22
void OP022(){
    stageops = 22;
    save();
    loop = 0;

    printf("\t22 - Embora vocês fiquem um pouco perturbados na companhia um do outro, sabendo que só pode haver um vencedor na Prova dos Campeões, ambos estão contentes por compartilhar os benefícios de uma aliança temporária. Contam um ao outro as explorações que fizeram até agora, falam dos monstros e armadilhas que encontraram e dos perigos que venceram. Caminhando em frente, vocês logo chegam à  borda de um poço largo. É profundo e escuro demais para verem-lhe o fundo. O Bárbaro se oferece para ajudá-lo descer ao fundo com a corda dele, dizendo que tem uma tocha com a qual você poderá iluminar o caminho. Você:\n\nAceitará a oferta do Bárbaro? \033[1;35mDigite 63.\033[0;37m\nOferece-se para ajudar a descida dele, já que ele está tão ansioso para investigar o poço? \033[1;35mDigite 184.\033[0;37m\nSugerirá que, em vez disso, ambos pulem por cima do poço?\033[1;35m Digite 311.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch (choices){
            case 63:
                loop++;
                system("cls");
                OP063();
                break;

            case 184:
                loop++;
                system("cls");
                OP184();
                break;
            case 311:
                loop++;
                system("cls");
                OP311();
                break;
            case 0:
                inventory();
                enter();
                OP022();
                break;
        }
    }
}

//OPCAO 23
void OP023(){
    loop = 0;

    printf("\t23 - O papel traz uma advertência simples, escrita em sangue seco:\033[1;31m \"Cuidado com os Juízes da Prova.\"\033[0;37m.Você recoloca o papel no prego e corre de volta pelo túnel para se reunir ao Bárbaro.");

    enter();
    OP154();
}

//OPCAO 24
void OP024(){
    stageops = 24;
    save();
    loop = 0;

    printf("\t24 - Colocada em uma alcova em arco na parede do túnel, você vê uma cadeira de madeira ornamentada, esculpida na forma de uma ave de rapina de aparência demoníaca.\n\nSe você quiser se sentar na cadeira, \033[1;35mdigite 324.\033[0;37m\nSe preferir continuar seguindo para o norte, \033[1;35mdigite 188.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 324:
                loop++;
                system("cls");
                OP324();
                break;
            case 188:
                loop++;
                system("cls");
                OP188();
                break;
            case 0:
                inventory();
                enter();
                OP024();
                break;
        }
    }
}

//OPCAO 25
void OP025(){
    loop = 0;

    printf("\t25 - Embora a temperatura no túnel esteja mais alta do que você conseguiria normalmente tolerar, o líquido do bambu mantém-no vivo.");

    enter();
    OP197();
}

//OPCAO 26
void OP026(){
    loop = 0;

    printf("\t26 - A pílula faz com que você se sinta mole e letárgico. Você perde 2 pontos de HABILIDADE. O Anão diz que agora você pode prosseguir para o segundo estágio do teste. Ele pega uma cesta de vime e lhe diz que ela contém uma serpente. Vira a cesta e a serpente cai no chão. É uma naja, e se ergue no ar, pronta para dar o bote. O Anão diz que pretende testar suas reações. Você deverá agarrar a naja, com as mãos nuas, pelo pescoço, evitando as presas mortais. Você se agacha, tensionando os músculos para o momento decisivo. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");

    if(status_OP026 == 0){
        hability -= 2;
        status_OP026 += 1;
        while(loop < 1){
            gets(startroll);
            if(strcasecmp(startroll, "roll") == 0){
                dice2();
                if(numroll <= hability){
                    system("cls");
                    OP055();
                }else{
                    system("cls");
                    OP202();
                }
            }
        }
    }else{
        while(loop < 1){
            gets(startroll);
            if(strcasecmp(startroll, "roll") == 0){
                dice2();
                if(numroll <= hability){
                    system("cls");
                    OP055();
                }else{
                    system("cls");
                    OP202();
                }
            }
        }
    }
}

//OPCAO 27
void OP027(){
    loop = 0;

    printf("\t27 - Você caminha até o apavorado homem e corta a corrente com sua espada. Ele cai de joelhos e se inclina, agradecendo, repetidamente. Diz que, há quatro anos, entrou na Prova dos Campeões, mas fracassou. Ele caiu em um poço e teve que ser resgatado por um Juiz da Prova, um dos administradores do calabouço do Barão Sukumvit. Foi-lhe, então, oferecida a opção de morrer ou servir como lacaio no Calabouço da Morte. Para sobreviver, ele trabalhou como escravo, até que não pôde mais suportar e tentou escapar. Lástima, não teve êxito e foi capturado pelos Orcas, os guardas volantes do Juiz da Prova. Como corretivo, cortaram-lhe uma das mãos e condenaram-no a um ano de prisão nessa cela. Você pergunta se ele tem alguma informação que lhe possa ser útil. Ele coça a cabeça: \"Bem, não cheguei a me sair exatamente bem aqui, mas, de fato, sei que você precisa juntar gemas e pedras preciosas, se espera escapar. Não sei por que, mas é isso.\" Sem mais dizer, o esfarrapado prisioneiro dispara para fora do aposento, virando à  esquerda no túnel. Você resolve prosseguir para o norte e vira à  direita no túnel.");

    enter();
    OP078();
}

//OPCAO 28
void OP028(){
    loop = 0;

    printf("\t28 - A cota de malha do Anão é de ferro da melhor qualidade, obviamente feita por um mestre armeiro. Você a tira do corpo dele e a coloca sobre sua cabeça. \033[1;32mAcrescente 1 ponto de HABILIDADE\033[0;37m. Não há mais nada de útil na câmara, portanto você decide investigar o novo túnel.\n\n");

    if(status_OP028 == 0){
        hability += 1;
        printf("Você recebeu 1 de HABILIDADE");
        printf("\nSua HABILIDADE: %i", hability);
        enter();
        OP213();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP213();
    }
}

//OPCAO 29
void OP029(){
    loop = 0;

    printf("\t29 - O túnel conduz ao norte por alguma distância, antes de chegar a um beco sem saída. A entrada de um escorrega se projeta da parede leste do túnel. Parece ser a única maneira de sair. Você resolve se arriscar e sobe no escorrega. Deslizando suavemente, você desce em um aposento, onde aterrissa de costas.");

    enter();
    OP090();
}

//OPCAO 30
void OP030(){
    loop = 0;

    printf("\t30 - Dando um passo à  frente, você salta para a borda do outro lado do poço. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP160();
            }else{
                luck--;
                system("cls");
                OP319();
            }
        }
    }
}

//OPCAO 31
void OP031(){
    stageops = 31;
    save();
    loop = 0;

    printf("\t31 - O Gnomo sorri e diz: \"Bom. Agora, você possui uma safira?\".\n\nSe você de fato tiver uma safira, \033[1;35mdigite 376.\033[0;37m\nSe não, \033[1;35mdigite 3.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 3:
                loop++;
                system("cls");
                OP003();
                break;
            case 376:
                loop++;
                if(sapphire != 0){
                    system("cls");
                    OP376();
                } else{
                    printf("Você não possui este item.");
                    enter();
                    OP031();
                }
                break;
            case 0:
                inventory();
                enter();
                OP031();
                break;
        }
}
}

//OPCAO 32
void OP032(){
    loop = 0;

    printf("\t32 - Você logo chega a uma outra encruzilhada no túnel. Um braço leva para o leste, mas as pegadas úmidas que você vem seguindo continuam para o norte, e você resolve continuar na trilha delas.");

    enter();
    OP037();
}

//OPCAO 33
void OP033(){
    loop = 0;

    printf("\t33 - Foi um erro ter tateado no interior do buraco com o braço da espada. Está coberto de marcas de sucção e dá a sensação de ter sido esmagado. \033[1;31mVocê perde 3 pontos de HABILIDADE\033[0;37m. Você dá uma espiada para dentro do buraco e vê o toco do tentáculo ensanguentado que pende inerte. Cuidadosamente, retira o gancho e a bolsa de couro, na qual encontra um minúsculo sino de latão. Você guarda suas novas posses na mochila e segue para o norte.\n\n");

    if(status_OP033 == 0){
        hability -= 3;
        iron_hook += 1;
        brass_bell += 1;
        status_OP033 += 1;

        printf("Você perdeu 3 de HABILIDADE");
        printf("\nSua HABILIDADE: %i", hability);
        printf("\033[1;34m");
        printf("\n\nSino de Latão foi adicionado a seu inventário");
        printf("\nGancho foi adicionado a seu inventário");
        enter();
        OP292();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP292();
    }
}

//OPCAO 34
void OP034(){
    loop = 0;

    printf("\t34 - Você tenta forçar por baixo da esmeralda com a ponta da espada. Para sua grande surpresa, a esmeralda se despedaça com o contato, soltando um jato de gás venenoso diretamente no seu rosto. \033[1;31mO gás o faz desmaiar, e você solta a corda, despenca do ídolo e cai no chão de pedra.\033[0;37m");
    death();
}

//OPCAO 35
void OP035(){
    stageops = 35;
    save();
    loop = 0;

    printf("\t35 - O túnel continua para o oeste por várias centenas de metros, terminando finalmente em alguns degraus que conduzem a um alçapão fechado. Você sobe os degraus lentamente, ouvindo vozes abafadas acima. Na penumbra, você pode ver que o alçapão não está trancado.\n\nSe quiser bater na porta do alçapão, \033[1;35mdigite 333.\033[0;37m\nSe preferir irromper pela porta com a espada desembainhada, \033[1;35mdigite 124\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while (loop < 1){
        scanf("%i", &choices);
        switch (choices){
            case 333:
                loop++;
                system("cls");
                OP333();
                break;
            case 124:
                loop++;
                system("cls");
                OP124();
                break;
            case 0:
                inventory();
                enter();
                OP035();
                break;
        }
    }
}

//OPCAO 36
void OP036(){
    loop = 0;

    printf("\t36- Embora você jamais tenha corrido tanto em toda a sua vida, o rochedo chega cada vez mais perto. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE e ENERGIA.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability && numroll <= energy){
                system("cls");
                OP340();
            }else{
                system("cls");
                OP007();
            }
        }
    }
}

//OPCAO 37
void OP037(){
    stageops = 37;
    save();
    loop = 0;

    printf("\t37 - A passagem se alarga em uma ampla caverna, mais escura, mas muito mais seca. As pegadas desaparecem gradualmente à  sua frente. Há um grande ídolo no centro da caverna, com cerca de seis metros de altura. Os olhos da estátua são jóias, cada uma do tamanho do seu punho. Duas criaturas empalhadas, com aparência de pássaros, encontram-se de pé em cada lado do ídolo.\n\nSe você quiser subir no ídolo para pegar as jóias, \033[1;35mdigite 351.\033[0;37m\nSe preferir atravessar a caverna para o túnel na parede do outro lado, \033[1;35mdigite 239.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch (choices){
            case 351:
                loop++;
                system("cls");
                OP351();
                break;
            case 239:
                loop++;
                system("cls");
                OP239();
                break;
            case 0:
                inventory();
                enter();
                OP037();
                break;
        }
    }
}

//OPCAO 38
void OP038(){
    loop = 0;

    printf("\t38 - Em silêncio, o homem fica de lado enquanto você engole a água e devora o pão. Uma dor aguda lhe invade o estômago, e você cai de joelhos. O velho olha para você com desprezo e diz: \"Bem, o que pode esperar quem come comida envenenada?\". \033[1;31mVocê perde 3 pontos de ENERGIA\033[0;37m. Ele se afasta, arrastando os pés, e o deixa se contorcendo em dores no chão. Você acaba recuperando força bastante para continuar para o oeste.\n\n");

    if(status_OP038 == 0){
        energy -= 3;
        status_OP038 += 1;
        printf("Você perdeu 3 de ENERGIA");
        printf("\nSua ENERGIA: %i\n\n", energy);
        if(energy <= 0){
            death();
        }else{
            printf("Você acaba recuperando força o bastante para continuar para o oeste.");
            enter();
            OP109();
        }
    }else{
        printf("Você perdeu 3 de ENERGIA");
        printf("\nSua ENERGIA: %i\n\n", energy);
        if(energy <= 0){
            death();
        }else{
            printf("Você acaba recuperando força o bastante para continuar para o oeste.");
            enter();
            OP109();
        }
    }
}

//OPCAO 39
void OP039(){
    stageops = 39;
    save();
    loop = 0;
    monsenergy = 8;
    monshability = 7;

    printf("\t39 - Você consegue se desviar das pernas estendidas da Mosca Gigante que mergulha sobre você. Recuando, você desembainha a espada e se prepara para lutar contra o horroroso inseto, quando ele se volta para atacá-lo outra vez.\n\n\033[1;31mMOSCA GIGANTE HABILIDADE 7 ENERGIA 8\033[0;37m\n\nVocê pode fugir, correndo de volta para o túnel, para prosseguir ao norte, \033[1;35mdigite 267.\033[0;37m\nSe preferir ficar e lutar, \033[1;35mdigite 111.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 267:
                loop++;
                system("cls");
                OP267();
                break;
            case 111:
                loop++;
                system("cls");
                combat1();
                printf("\n\nVocê derrotou a MOSCA GIGANTE!\n");
                printf("Sua ENERGIA: %i", energy);
                enter();
                OP111();
                break;
            case 0:
                inventory();
                enter();
                OP039();
                break;
        }
    }
}

//OPCAO 40
void OP040(){
    loop = 0;
    monsenergy = 9;
    monshability = 9;

    printf("\t40 - Você chama o Anão, dizendo que está pronto para lutar contra o MINOTAURO. A porta de madeira se ergue lentamente, e você vê a assustadora fera, meio homem, meio touro, entrar na arena. Ele bufa e expele vapor pelas narinas, enquanto vai ficando mais e mais furioso, pronto para atacar. Súbito, arranca adiante, girando uma acha de dois gumes.\n\n\033[1;31mMINOTAURO HABILIDADE 9 ENERGIA 9\033[0;37m\n\n");

    enter();
    combat1();
    printf("Você sobreviveu ao MINOTAURO\n");
    printf("\n\nSua ENERGIA: %i", energy);
    enter();
    OP163();

}

//OPCAO 41
void OP041(){
    stageops = 41;
    save();
    loop = 0;

    printf("\t41 - Você caminha lentamente para a alcova, verificando cuidadosamente o chão para não cair em outras armadilhas ocultas. Você vê que a taça contém um líquido vermelho efervescente. Você:\n\nBeberá o líquido vermelho? \033[1;35mDigite 98.\033[0;37m\nDeixará a taça e caminhará de volta para procurar o Bárbaro? \033[1;35mDigite 126.\033[0;37m\nDeixará a câmara para continuar para o oeste? \033[1;35mDigite 83.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 98:
                loop++;
                system("cls");
                OP098();
                break;
            case 126:
                loop++;
                system("cls");
                OP126();
                break;
            case 83:
                loop++;
                system("cls");
                OP083();
                break;
            case 0:
                inventory();
                enter();
                OP041();
                break;
        }
    }
}

//OPCAO 42
void OP042(){
    loop = 0;

    printf("\t42 - Os dentes da naja se cravam fundo no seu pulso e você sente o veneno se alastrando pelo corpo. \033[1;31mVocê perde 5 pontos de ENERGIA.\033[0;37m\n\n");

    if(status_OP042 == 0){
        energy -= 5;
        status_OP042 += 1;
        printf("Você perdeu 5 de ENERGIA");
        printf("\nSua ENERGIA: %i\n\n", energy);
        if(energy <= 0){
            death();
        }else{
            printf("O Anão não tem pena e lhe diz para tentar outra vez. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");
            while(loop < 1){
                gets(startroll);
                if(strcasecmp(startroll, "roll") == 0){
                    dice2();
                    if(numroll <= hability){
                        system("cls");
                        OP055();
                    }else{
                        system("cls");
                        OP202();
                    }
                }
            }
        }
    }else{
        printf("Você perdeu 5 de ENERGIA");
        printf("\nSua ENERGIA: %i\n\n", energy);
        if(energy <= 0){
            death();
        }else{
            printf("O Anão não tem pena e lhe diz para tentar outra vez. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");
            while(loop < 1){
                gets(startroll);
                if(strcasecmp(startroll, "roll") == 0){
                    dice2();
                    if(numroll <= hability){
                        system("cls");
                        OP055();
                    }else{
                        system("cls");
                        OP202();
                    }
                }
            }
        }
    }
}

//OPCAO 43
void OP043(){
    stageops = 43;
    save();
    loop = 0;
    save();
    printf("\t43 - O túnel vira abruptamente para a direita e continua para o norte, até onde a vista alcança. Há uma porta entreaberta na parede do lado esquerdo. Você ouve alguém gritando por socorro, a voz vindo do outro lado da porta.\n\nSe você quiser abrir a porta, \033[1;35mdigite 200.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 316.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 200:
                loop++;
                system("cls");
                OP200();
                break;
            case 316:
                loop++;
                system("cls");
                OP316();
                break;
            case 0:
                inventory();
                enter();
                OP043();
                break;
        }
    }
}

//OPCAO 44
void OP044(){
    loop = 0;
    printf("\t44 - Você está a apenas alguns metros da porta quando ouve o velho atrás de si enunciar umas palavras estranhas. Instantaneamente, sente os músculos endurecerem e a pele esticar. Você entra em pânico, \033[1;31mmas não há nada que possa fazer para impedir a petrificação do seu corpo.\033[0;37m");
    death();
}

//OPCAO 45
void OP045(){
    loop = 0;

    printf("\t45 - O disco, afiado como uma navalha, atinge-lhe as costas com terrível efeito. \033[1;31mVocê perde 1 ponto de HABILIDADE e 4 pontos de ENERGIA\033[0;37m\n\n");

    if(status_OP045 == 0){
        hability -= 1;
        energy -= 4;
        status_OP045 += 1;
        printf("Você perdeu 4 de ENERGIA");
        printf("\nSua ENERGIA: %i", energy);
        printf("\n\nVocê perdeu 1 de HABILIDADE");
        printf("\nSua HABILIDADE: %i\n\n", hability);

        if(energy <= 0){
            death();
        }else{
            printf("\n\nVocê sobreviveu, mas luta para tirar o disco das costas, enquanto o ninja joga mais um.");
            enter();
            OP312();
        }
    }else{
        printf("Você perdeu 4 de ENERGIA");
        printf("\nSua ENERGIA: %i", energy);
        printf("\n\nVocê perdeu 1 de HABILIDADE");
        printf("\nSua HABILIDADE: %i\n\n", hability);

        if(energy <= 0){
            death();
        }else{
            printf("\n\nVocê sobreviveu, mas luta para tirar o disco das costas, enquanto o ninja joga mais um.");
            enter();
            OP312();
        }
    }
}

//OPCAO 46
void OP046(){
    loop = 0;

    printf("\t46 - Você desce cuidadosamente do ídolo e, sem perder mais tempo na caverna, corre para o túnel adiante na parede norte.");

    enter();
    OP239();
}

//OPCAO 47
void OP047(){
    stageops = 47;
    save();
    loop = 0;
    save();

    printf("\t47 - Você tem um tubo oco de madeira?\n\nSe tiver, \033[1;35mdigite 10.\033[0;37m\nSe não tiver, \033[1;35mdigite 335.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 335:
                loop++;
                system("cls");
                OP335();
                break;
            case 10:
                loop++;
                if(wood_tube != 0){
                    system("cls");
                    OP010();
                } else{
                    printf("Você não possui este item.");
                    enter();
                    OP047();
                }
                break;
            case 0:
                inventory();
                enter();
                OP047();
                break;
        }
    }
}

//OPCAO 48
void OP048(){
    printf("\t48 - Somente sua força imensa e determinação inquebrantável evitam que você caia inconsciente ao solo. Você aperta os dentes e, resoluto, segue adiante.");

    enter();
    OP197();
}

//OPCAO 49
void OP049(){
    stageops = 49;
    save();
    loop = 0;
    save();

    printf("\t49 - Você dá uma espiada, virando a esquina, e vê duas pequenas criaturas correndo de você. Vestem roupas largas e usam chapéus pontudos e desengonçados. São os travessos LEPRECHAUNS.\n\nSe você quiser segui-los, \033[1;35migite 205.\033[0;37m\nSe preferir caminhar de volta para a última encruzilhada e seguir para o norte, \033[1;35mdigite 241.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 205:
                loop++;
                system("cls");
                OP205();
                break;
            case 241:
                loop++;
                system("cls");
                OP241();
                break;
            case 0:
                inventory();
                enter();
                OP049();
                break;
        }
    }
}

//OPCAO 50
void OP050(){
    loop = 0;

    printf("\t50 - Você acorda e vê Throm puxando o anel do seu dedo. Ele joga o anel no chão e o esmaga com a acha de guerra. Em seguida, grunhindo para expressar que desaprova sua atitude, sai caminhando para o leste. Com esforço, você se levanta e o segue cambaleante.");

    enter();
    OP221();
}

//OPCAO 51

void OP051(){
    loop = 0;
    monsenergy = 5;
    monshability = 6;
    printf("\t51 - Os Hobgoblins não estão preparados para o seu ataque, e você consegue matar o primeiro antes que ele possa puxar da espada. Você se volta para enfrentar o outro Hobgoblin, que rosna de ódio.\n\n\033[1;31mHOBGOBLIN HABILDADE 6 ENERGIA 5\033[0;37m\n\n");

    enter();
    combat1();
    printf("\n\nVocê derrotou o HOBGOBLIN");
    printf("\n\nSua ENERGIA: %i", energy);
    enter();
    OP009();
}

//OPCAO 52

void OP052(){
    stageops = 52;
    save();
    loop = 0;
    save();

    printf("\t52 - Ao abrir o livro, você vê que ele começa a se desintegrar. As páginas se transformando em poeira nas suas mãos. Mas você consegue salvar alguns fragmentos e ler o manuscrito. O livro parece ser sobre monstros, e, do que você pode concluir, contém uma descrição completa de um ser chamado Besta Sangrenta. É uma horrível criatura inchada, com pele grossa e coberta de espinhos e úlceras faciais que se abrem para se tornar falsos olhos, cujo objetivo é esconder o único ponto fraco da Besta Sangrenta - seus olhos verdadeiros. Essas monstruosidades geralmente habitam poços de lodo fétido que exalam gás venenoso, tão forte que pode facilmente deixar uma pessoa inconsciente. A Besta Sangrenta, embora pesada demais para sair da poça de lodo, tem uma língua longa e poderosa que se enrosca em torno de suas vítimas para arrastá-las para o interior da poça. Quando a carne das vítimas começa a apodrecer no lodo abjeto, a Besta Sangrenta a devora. Você conta a Throm sobre a grotesca Besta Sangrenta, mas ele simplesmente sacode os ombros e lhe diz para seguir adiante.\n\nSe você quiser abrir o livro preto, \033[1;35mdigite 138.\033[0;37m\nDo contrário, você deve prosseguir para o norte com Throm, \033[1;35mdigite 369.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    if(status_OP052 == 0){
        knowledge_bloody_beast += 1;
        status_OP052 += 1;
        printf("\033[1;34m");
        printf("Você recebeu o conhecimento da Besta Sangrenta, isso foi adicionado à s suas SKILLS.\n");
        printf("\033[0;37m");

        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 138:
                    loop++;
                    system("cls");
                    OP138();
                    break;
                case 369:
                    loop++;
                    system("cls");
                    OP369();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP052();
                    break;
            }
        }
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n");
        while(loop < 1){
            printf("");
            scanf("%i", &choices);
            switch(choices){
                case 138:
                    loop++;
                    system("cls");
                    OP138();
                    break;
                case 369:
                    loop++;
                    system("cls");
                    OP369();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP052();
                    break;
            }
        }
    }
}

//OPCAO 53

void OP053(){
    stageops = 53;
    save();
    loop = 0;
    save();

    printf("\t53 - A Besta Sangrenta é inchada demais para sair da poça, mas, com a longa e poderosa língua, varre as cercanias e tenta alcançar a sua perna. Felizmente, você caiu fora do seu alcance. O ar, ao nível do chão, não contém nenhum dos vapores venenosos, mas você acorda com dor na garganta. Você cobre a boca com a manga da camisa para poder respirar através dela, e decide o que fazer.\n\nSe você quiser correr, contornando a poça, na direção do túnel, \033[1;35mdigite 370.\033[0;37m\nSe preferir atacar a Besta Sangrenta com sua espada, \033[1;35mdigite 348.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 370:
                loop++;
                system("cls");
                OP370();
                break;
            case 348:
                loop++;
                system("cls");
                OP348();
                break;
            case 0:
                inventory();
                enter();
                OP053();
                break;
        }
    }
}

//OPCAO 54

void OP054(){
    loop = 0;

    printf("\t54 - O laço se solta e você consegue tirá-lo do pescoço do ídolo com uma sacudidela. Ele cai ao chão com um ruído alto. Você enrola a corda rapidamente e a coloca na mochila. Sem perder mais tempo na caverna, corre para o túnel na parede norte.");

    enter();
    OP239();
}

//OPCAO 55

void OP055(){
    stageops = 55;
    save();
    loop = 0;
    save();

    printf("\t55 - Com a velocidade de um raio, você estica a mão e segura a naja logo abaixo da boca aberta. Você a ergue e, com o braço estendido, sacode-a na frente do Anão. Ele fica impassível, mas, com seu jeito calmo e sem expressão, diz: \"Por favor, coloque a naja de volta na cesta e prepare-se para a parte final do teste. Siga-me.\". Você faz o que ele disse e o segue de volta para a câmara, onde Throm está andando de um lado para o outro, evidentemente nervoso. Você acena para ele, enquanto o Anão abre uma segunda porta secreta e manda que você entre por ela e espere por ele. Outra vez você obedece, e se vê em outro aposento circular, embora este se assemelhe a uma pequena arena. O chão é coberto de areia, e uma pequena sacada circunda a parede da arena. No lado oposto ao da porta secreta pela qual você entrou, há uma porta de madeira de aparência agourenta. De repente, você ouve um grito, e olha para cima, vendo o Anão sorridente na sacada. Ele joga dois pedaços de papel para você. Num deles, estão escritas as palavras SEI PORCÃO, e no outro, RUIM NO ATO. Com a voz sempre calma, ele diz: \"Se você rearrumar as letras das palavras, descobrirá os nomes de duas criaturas. Você pode escolher com qual delas quer lutar na minha Arena da Morte.\"\n\nSe você puder identificar a criatura rearrumando as letras de SEI PORCÃO, \033[1;35mdigite 143.\033[0;37m\nSe puder identificar a criatura rearrumando as letras de RUIM NO ATO, \033[1;35mdigite 40.\033[0;37m\nSe você não puder identificar nenhuma das duas criaturas, \033[1;35mdigite 347.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");



    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 143:
                loop++;
                system("cls");
                OP143();
                break;
            case 40:
                loop++;
                system("cls");
                OP040();
                break;
            case 347:
                loop++;
                system("cls");
                OP347();
                break;
            case 0:
                inventory();
                enter();
                OP055();
                break;
        }
    }
}

//OPCAO 56

void OP056(){
    stageops = 56;
    save();
    loop = 0;
    save();

    printf("\t56 - Você vê que a obstrução é causada por um objeto grande e marrom, parecendo um rochedo. Você o toca com a mão e fica surpreso ao descobrir que é macio e esponjoso. \n\nSe você quiser tentar subir por cima dele, \033[1;35mdigite 373.\033[0;37m\nSe preferir cortá-lo ao meio com sua espada, \033[1;35mdigite 215.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 373:
                loop++;
                system("cls");
                OP373();
                break;
            case 215:
                loop++;
                system("cls");
                OP215();
                break;
            case 0:
                inventory();
                enter();
                OP056();
                break;
        }
    }
}

//OPCAO 57

void OP057(){
    loop = 0;

    printf("\t57 - Embora você já tenha examinado a arca cuidadosamente, em busca de quaisquer mecanismos ocultos, não consegue ver a armadilha dentro dela. Ao levantar a tampa, uma bola de ferro pendente de uma corda é lançada para trás, partindo a cápsula de vidro fixada no lado de dentro da tampa. Uma nuvem de gás venenoso é instantaneamente liberado no ar, e você cambaleia, recuando, enquanto tosse e se engasga. \033[1;31mVocê perde 4 pontos de ENERGIA.\033[0;37m\n\n");

    if(status_OP057 == 0){
        energy -= 4;
        status_OP057 += 1;
        printf("Você perdeu 4 de ENERGIA");
        printf("\nSua ENERGIA: %i", energy);

        if(energy <= 0){
            death();
        }else{
            printf("\n\nVocê sobreviveu ao gás venenoso");
            enter();
            OP198();
        }
    }else{
        printf("Você perdeu 4 de ENERGIA");
        printf("\nSua ENERGIA: %i", energy);

        if(energy <= 0){
            death();
        }else{
            printf("\n\nVocê sobreviveu ao gás venenoso");
            enter();
            OP198();
        }
    }
}

//OPCAO 58

void OP058(){
    loop = 0;

    printf("\t58 - Você caminha lentamente entre os postes, tomando cuidado para não tocar em nenhum deles. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP080();
            }else{
                system("cls");
                OP246();
            }
        }
    }
}

//OPCAO 59

void OP059(){
    stageops = 59;
    save();
    loop = 0;
    save();

    printf("\t59 - Adiante, a distância, você ouve o som de passos lentos vindo na sua direção. Sem saber o que ou quem poderia estar se aproximando, você olha em volta, em busca de um lugar para se esconder. Encontra uma fenda grande na parede do túnel onde não bate luz.\n\nSe você quiser defrontar-se com o recém-chegado de espada na mão, \033[1;35mdigite 341.\033[0;37m\nSe preferir esconder-se nas sombras, \033[1;35mdigite 283.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 341:
                loop++;
                system("cls");
                OP341();
                break;
            case 283:
                loop++;
                system("cls");
                OP283();
                break;
            case 0:
                inventory();
                enter();
                OP059();
                break;
        }
    }
}

//OPCAO 60

void OP060(){
    stageops = 60;
    save();
    loop = 0;

    printf("\t60 - O túnel termina em uma grande porta de carvalho. Throm não perde tempo e vai logo testando a maçaneta, ficando algo admirado ao descobrir que a porta não está trancada. Ele a empurra e vocês se deparam com uma câmara iluminada por tochas. Sentado sozinho em uma cadeira ornamentada, há um ANÃO, que os convida a entrar na câmara. Ao fazê-lo, a porta de carvalho se fecha atrás de vocês. \"Aventureiros, vocês se saíram muito bem até agora\", diz o Anão com voz profunda. \"Contudo, como vocês dois sabem, só pode haver um vencedor na Prova dos Campeões. Como Juiz da Prova, é minha obrigação para com o Barão Sukumvit só permitir que o mais capaz continue. Portanto, tenho que preparar um teste de inteligência e força para eliminar um de vocês. Por favor, não tentem livrar-se de mim. Seria completamente estúpido, pois, como vocês podem ver, não há nenhuma maneira óbvia de sair desta câmara, e somente eu sei onde está a saída oculta. Agora, se vocês não se importassem de decidir entre vocês quem irá primeiro, eu tratarei de fazer as preparações necessárias.\" Você olha para Throm, subitamente com raiva de que a eficaz associação de vocês pudesse ter que terminar. Ele se inclina e sussurra no seu ouvido que vocês deveriam tentar matar o Anão e preocuparse com a saída depois.\n\nSe você quiser unir-se a Throm no ataque ao Anão, \033[1;35mdigite 179.\033[0;37m\nSe você preferir convencer Throm seguir em frente com o teste do Anão, \033[1;35mdigite 365.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 179:
                loop++;
                system("cls");
                OP179();
                break;
            case 365:
                loop++;
                system("cls");
                OP365();
                break;
            case 0:
                inventory();
                enter();
                OP060();
                break;
        }
    }
}

//OPCAO 61

void OP061(){
    loop = 0;

    printf("\t61 - Apesar do terrível ruído de campainha nos seus ouvidos, você ouve passos descendo pelo túnel. Seus gritos altos atraíram um guardião do túnel. Há um HOBGOBLIN de pé junto a você. Ele sorri doentiamente enquanto pressiona a ponta da espada contra seu pescoço. \033[1;31mVocê não tem como se defender e impedir que ele o trespasse.\033[0;37m");
    death();
}

//OPCAO 62

void OP062(){
    stageops = 62;
    loop = 0;
    save();

    printf("\t62 - O Gnomo pula no ar, gritando: \"Belo trabalho, ninguém jamais conseguiu encontrar todas as três gemas antes! Agora, prepare-separa o teste final, o qual eu explicarei uma vez e somente uma vez. Como você pode ver, a fechadura desta porta tem três ranhuras, com as etiquetas A, B e C, cada uma delas construída para aceitar uma gema específica. Você tem porque pôr uma das suas três gemas em cada uma das ranhuras na ordem certa. Se conseguir isso na primeira tentativa, ótimo. Porém, se puser as gemas nas ranhuras erradas, você será atingido por um raio de energia da fechadura, o que lhe causará ferimentos. De qualquer maneira, como eu disse, tenho permissão para ajudá-lo um pouco. Se você colocar uma gema em sua ranhura correta, mas puser as outras duas erradas, eu gritarei: Uma coroa e dois crânios. Se você colocar todas as três gemas incorretamente, eu gritarei: Três crânios. Você terá permissão para tentar repetidamente até que tenha êxito ou morra. Está pronto?\" Você faz um aceno de cabeça e caminha adiante para colocar as três gemas nas ranhuras. Resolva que gemas colocará nas ranhuras com etiquetas:\n\n    A         B         C     \nEsmeralda|Diamante |Safira    -> \033[1;35mDigite 16\033[0;37m\nDiamante |Safira   |Esmeralda -> \033[1;35mDigite 392\033[0;37m\nSafira   |Esmeralda|Diamante  -> \033[1;35mDigite 177\033[0;37m\nEsmeralda|Safira   |Diamante  -> \033[1;35mDigite 287\033[0;37m\nDiamante |Esmeralda|Safira    -> \033[1;35mDigite 132\033[0;37m\nSafira   |Diamante |Esmeralda -> \033[1;35mDigite 249\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 16:
                loop++;
                system("cls");
                OP016();
                break;
            case 392:
                loop++;
                system("cls");
                OP392();
                break;
            case 177:
                loop++;
                system("cls");
                OP177();
                break;
            case 287:
                loop++;
                system("cls");
                OP287();
                break;
            case 132:
                loop++;
                system("cls");
                OP132();
                break;
            case 249:
                loop++;
                system("cls");
                OP249();
                break;
            case 0:
                inventory();
                enter();
                OP062();
                break;
        }
    }
}

//OPCAO 63

void OP063(){
    loop = 0;

    printf("\t63 - Você amarra a corda na cintura e segura a tocha que Throm, seu aliado Bárbaro, lhe dá, já acesa. Segurando a corda frouxa, Throm o vai descendo-o lentamente por sobre a borda do poço até as profundezas escuras. Você pode ver, com a luz da tocha, que os lados do poço são extremamente lisos. Você desce por uns 20 metros antes de chegar ao fundo do poço. Ali, vê um outro túnel que segue para o norte, e chama Throm para contar-lhe a descoberta. Ele responde, dizendo que vai amarrar a corda em uma rocha proeminente na borda do poço e descerá. Você ouve o Bárbaro descendo, e logo estão juntos de novo. Throm recupera a corda, sacudindo-a para soltá-la da rocha, e vocês partem para o norte pelo novo túnel.");

    enter();
    OP194();
}

//OPCAO 64

void OP064(){
    loop = 0;

    printf("\t64 - Logo que você põe o anel no dedo, todo seu corpo começa a tremer. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP115();
            }else{
                system("cls");
                OP190();
            }
        }
    }
}

//OPCAO 65

void OP065(){
    stageops = 65;
    save();
    loop = 0;

    printf("\t65 - Você bebeu uma Poção encontrada dentro de um livro de couro preto?\n\nSe bebeu, \033[1;35mdigite 345.\033[0;37m\nSe não, \033[1;35mdigite 372.\033[0;37m");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 372:
                loop++;
                system("cls");
                OP372();
                break;
            case 345:
                loop++;
                if(skill_trap_potion != 0){
                    system("cls");
                    OP345();
                } else{
                    printf("Você não fez isso.");
                    enter();
                    OP065();
                }
                break;
            case 0:
                inventory();
                enter();
                OP065();
                break;
        }
    }
}

//OPCAO 66

void OP066(){
    stageops = 66;
    loop = 0;
    save();

    printf("\t66 - Depois de caminhar pelo túnel por alguns minutos, você chega a uma encruzilhada. Uma seta branca pintada na parede aponta para o oeste. No chão, você vê pegadas molhadas, feitas por aqueles que entraram antes de você. É difícil ter certeza, mas parece que três deles seguiram a direção da seta, enquanto um resolveu ir para o leste.\n\nSe você quiser ir para o oeste, \033[1;35mdigite 293.\033[0;37m\nSe preferir ir para o leste, \033[1;35mdigite 119.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%d", &choices);
        switch(choices){
            case 293:
                loop++;
                system("cls");
                OP293();
                break;
            case 119:
                loop++;
                system("cls");
                OP119();
                break;
            case 0:
                inventory();
                enter();
                OP066();
                break;
        }
    }
}

//OPCAO 67

void OP067(){
    loop = 0;

    printf("\t67 - Você se agarra a um dos pilares submersos da ponte e gruda nele, prendendo a respiração. Enquanto isso, os Trogloditas chegam à  margem e concluem que você deve ter sido arrastado rio abaixo para morte certa, já que o rio desaparece nas profundezas da montanha. A essa altura, seus pulmões estão estourando de falta de ar. \033[1;33mDigite \"ROLL\" e teste sua SORTE\033[0;37m outra vez.\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP146();
            }else{
                luck--;
                system("cls");
                OP219();
            }
        }
    }
}

//OPCAO 68

void OP068(){
    stageops = 68;
    save();
    loop = 0;

    printf("\t68 - Você desce a passagem e logo se encontra de pé na borda de um poço profundo e escuro. A passagem continua para o leste, do outro lado do poço. Você pensa que provavelmente conseguirá pular por cima do poço, mas não tem certeza. Há uma corda que pende do teto e desce sobre o centro do poço. Você:\n\nJogará seu escudo por cima do poço e depois pulará? \033[1;35mDigite 271.\033[0;37m\nPulará por cima do poço carregando todas as suas posses? \033[1;35mDigite 30.\033[0;37m\nUsará a espada para trazer a corda até você, de modo a poder usá-la para atravessar até a outra margem? \033[1;35mDigite 212.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 271:
                loop++;
                system("cls");
                OP271();
                break;
            case 30:
                loop++;
                system("cls");
                OP030();
                break;
            case 212:
                loop++;
                system("cls");
                OP212();
                break;
            case 0:
                inventory();
                enter();
                OP068();
                break;
        }
    }
}

//OPCAO 69

void OP069(){
    loop = 0;

    printf("\t69 - Erva não nota que você abriu a porta. Você se esgueira para fora do aposento, fecha a porta silenciosamente e se vê no fim de um outro túnel.");

    enter();
    OP305();
}

//OPCAO 70

void OP070(){
    loop = 0;

    printf("\t70 - Você consegue mergulhar para o lado, por pouco, antes que o rochedo despenque sobre o chão do túnel, rachando a pedra. Enquanto se limpa, nota que há luz do sol no fim do túnel. Você corre para lá, alegre com a bela visão do céu azule das árvores verdes. Ao correr para fora do túnel, você espera ser cumprimentado por multidões vibrantes, mas fica horrorizado com o que vê. Não há recepção de herói que possa vir das pessoas à  sua volta. Estão todos mortos. Você está, na realidade, de pé em uma câmara fria, o chão coberto de cadáveres e esqueletos com armaduras - a saída para a vitória era apenas uma ilusão! Só os restos dos aventureiros do passado são reais. Você corre de volta para o túnel, mas colide com uma barreira invisível.\033[1;31m Você caiu na armadilha e está condenado a terminar seus dias na câmara dos mortos.\033[0;37m");
    death();
}

//OPCAO 71

void OP071(){
    loop = 0;

    printf("\t71 - Mais uma vez, você estica a mão para o pergaminho, só que dessa vez ele está em meio a uma pilha de ossos quebrados. Ao desenrolá-lo, você vê o mapa de um aposento com o desenho de uma criatura pavorosa dentro. Embaixo da figura do monstro, há uma rima que diz: \"Se você encontrar a Mantécora, é bom de sua cauda cuidar. Proteja-se dos espinhos que irão voar pelo ar.\"Você enrola o pedaço de pergaminho e o coloca na mochila. Repetindo a rima muitas vezes para si mesmo, você caminha para o outro lado, em direção à  alcova.");

    enter();
    OP128();
}

//OPCAO 72

void OP072(){
    loop = 0;

    printf("\t72 - O Espelho se quebra, lançando fragmentos de vidro por toda parte. As quatro faces do Demônio do Espelho gritam de agonia, e aparecem rachaduras em todas elas. Em seguida, elas também se partem e caem ao chão numa pilha de cacos de vidro. Infelizmente ao quebrar o espelho, você cortou seriamente o braço com que segura a espada. Embora sua força não tenha sido afetada, sua habilidade com as armas foi prejudicada. \033[1;31mVocê perde 2 pontos de HABILIDADE antes de continuar na sua jornada para o norte.\033[0;37m\n\n");

    if(status_OP072 == 0){
        hability -= 2;
        status_OP072 += 1;
        printf("Você perdeu 2 de HABILIDADE");
        printf("\nSua HABILIDADE: %i", hability);
        enter();
        OP122();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        printf("Você perdeu 2 de HABILIDADE");
        printf("\nSua HABILIDADE: %i", hability);
        enter();
        OP122();
    }
}

//OPCAO 73

void OP073(){
    stageops = 73;
    save();
    loop = 0;

    printf("\t73 - Se quiser, poderá caminhar de volta à  procura do Bárbaro, \033[1;35mdigite 126.\033[0;37m\nDo contrário, saia da câmara para continuar para o oeste, \033[1;35mdigite 83.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 126:
                loop++;
                system("cls");
                OP126();
                break;
            case 83:
                loop++;
                system("cls");
                OP083();
                break;
            case 0:
                inventory();
                enter();
                OP073();
                break;
        }
    }
}

//OPCAO 74

void OP074(){
    stageops = 74;
    save();
    loop = 0;

    printf("\t74 - O túnel faz uma curva fechada para a direita, e você se vê em uma espécie de galeria, coberta de espelhos por uns 20 metros. Um esqueleto humano parece estar sendo arrastado a meio caminho através de um espelho da parede da direita. Súbito, um ser grotesco, com quatro braços e quatro faces que gritam, emerge do espelho, barrando-lhe a passagem. Caminha lentamente na sua direção, todos os braços estendidos para agarrá-lo. É o DEMàNIO DO ESPELHO, de outro plano dimensional, que veio para levar seu espírito. Você:\n\nFará um desejo (se estiver usando um Anel dos Desejos)? \033[1;35mDigite 265.\033[0;37m\nTentará quebrar os espelhos? \033[1;35mDigite 300.\033[0;37m\nAtacará o Demônio do Espelho com sua espada? \033[1;35mDigite 327.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 265:
                if(wish_ring != 0){
                    loop++;
                    wish_ring -= 1;
                    system("cls");
                    OP265();
                    break;
                } else{
                    printf("\033[1;31m\nVocê não possui este item\033[0;37m");
                    enter();
                    OP074();
                }
            case 300:
                loop++;
                system("cls");
                OP300();
                break;
            case 327:
                loop++;
                system("cls");
                OP327();
                break;
            case 0:
                inventory();
                enter();
                OP074();
                break;
        }
    }
}

//OPCAO 75

void OP075(){
    stageops = 75;
    save();
    loop = 0;

    printf("\t75 - Você esfrega o líquido nos seus ferimentos, mas eles não saram. Olhando fixamente para a garrafa vazia, você fica se perguntando o que o líquido seria exatamente.\n\nSe quiser, poderá abrir o livro vermelho, \033[1;35mdigite 52.\033[0;37m\nDo contrário, você deve continuar para o norte com Throm, \033[1;35mdigite 369.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 52:
                loop++;
                system("cls");
                OP052();
                break;
            case 369:
                loop++;
                system("cls");
                OP369();
                break;
            case 0:
                inventory();
                enter();
                OP075();
                break;
        }
    }
}

//OPCAO 76

void OP076(){
    stageops = 76;
    save();
    loop = 0;

    printf("\t76 - Você dá a volta pela enorme massa morta do Verme da Rocha e dá uma espiada dentro da escuridão de seu buraco perfurado. Você só consegue ver alguns metros, mas pode notar que ele se inclina levemente e é tímido por causa da gosma secretada pelo Verme da Rocha.\n\nSe você quiser explorar o buraco de broca, \033[1;35mdigite 317.\033[0;37m\nSe preferir caminhar para o oeste pelo túnel, \033[1;35mdigite 117.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 317:
                loop++;
                system("cls");
                OP317();
                break;
            case 117:
                loop++;
                system("cls");
                OP117();
                break;
            case 0:
                inventory();
                enter();
                OP076();
                break;
        }
    }
}

//OPCAO 77

void OP077(){
    loop = 0;

    printf("\t77 - Você cambaleia pela porta aberta para outro túnel, no fim do qual está a visão bem-vinda da luz do dia. Com grande surpresa, você vê o Gnomo caído, morto, na metade do caminho do túnel, com uma seta de besta cravada na cabeça. O Gnomo, no esforço por libertar-se, caiu na armadilha final do Barão Sukumvit.\033[1;33m Você passa por ele rumo à  luz do sol brilhante.\033[0;37m");

    enter();
    OP400();
}
//OPCAO 78

void OP078(){
    stageops = 78;
    save();
    loop = 0;
    printf("\t78 - Há um cano com cerca de um metro de diâmetro aberto na parede da direita. Está escuro demais para se ver muito abaixo nele. Você grita dentro do cano de ferro e ouve sua voz ecoar por alguns instantes até desaparecer.\n\nSe você quiser engatinhar pelo cano, \033[1;35mdigite 301.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 142.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while (loop < 1){
        scanf("%d", &choices);
        switch(choices){
            case 301:
                loop++;
                system("cls");
                OP301();
                break;
            case 142:
                loop++;
                system("cls");
                OP124();
                break;
            case 0:
                inventory();
                enter();
                OP078();
                break;
        }
    }
}

//OPCAO 79

void OP079(){
    printf("\t79 - Você segura os braços da cadeira firmemente, esperando que uma onda de energia se espalhasse pelo seu corpo. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP106();
            }else{
                luck--;
                system("cls");
                OP383();
            }
        }
    }
}


//OPCAO 80

void OP080(){
    printf("\t80 - Você vai com calma e consegue passar pelo último poste sem ter tocado em nenhum deles. Corre para o leste, ainda seguindo os dois pares de pegadas.");

    enter();
    OP313();
}

//OPCAO 81

void OP081(){
    stageops = 81;
    save();
    loop = 0;

    printf("\t81 - A única mobília no quarto do Goblin consiste em uma mesa, duas cadeiras e um armário de parede. Há duas portas fechadas, uma na parede oeste, outra na parede norte. Você:\n\nAbrirá o armário? \033[1;35mDigite 307.\033[0;37m\nAbrirá a porta do oeste? \033[1;35mDigite 263.\033[0;37m\nAbrirá a porta do norte? \033[1;35mDigite 136.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while (loop < 1){
        scanf("%d", &choices);
        switch(choices){
            case 307:
                loop++;
                system("cls");
                OP307();
                break;
            case 263:
                loop++;
                system("cls");
                OP263();
                break;
            case 136:
                loop++;
                system("cls");
                OP136();
                break;
            case 0:
                inventory();
                enter();
                OP081();
                break;
        }
    }
}

//OPCAO 82

void OP082(){
    printf("\t82 - Quando o Diabo do Poço bate como corpo contra a parede, você solta a corda e cai em segurança no chão. Você corre na direção das portas duplas e fica aliviado ao senti-las se abrirem quando as empurra; deixa que elas se fechem atrás de si e segue para o norte pelo túnel.");

    enter();
    OP214();
}

//OPCAO 83

void OP083(){
    printf("\t83 - A passagem logo conduz a uma encruzilhada. Você repara em mais pegadas no chão, possivelmente uns três pares, dirigindo-se ao norte pela passagem do sul. Resolve segui-las.");

    enter();
    OP037();
}

//OPCAO 84

void OP084(){
    loop = 0;

    printf("\t84 - \033[1;33mDigite \"ROLL\" e role os dados.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= 8){
                system("cls");
                OP121();
            }else{
                system("cls");
                OP152();
            }
        }
    }
}

//OPCAO 85

void OP085(){
    printf("\t85 - Antes que você possa fazer qualquer outra coisa, o velho murmura umas palavras estranhas. Você sente os músculos se enrijecerem e a pele se esticar. Começa a entrar em pânico, \033[1;31mmas não há nada que possa fazer para impedir a petrificação do seu corpo.\033[0;37m");
    death();
}

//OPCAO 86

void OP086(){
    printf("\t86 - A chave gira na fechadura, e a porta se abre para um cruzamento de quatro caminhos do túnel. Não há nada a ser visto a leste ou a oeste, a não ser os já conhecidos cristais do teto que continuam a produzir luz fraca. Subitamente, você ouve um chamado: \"Por aqui, por aqui, você está no caminho certo.\" A voz parece estar vindo de algum lugar bem à  sua frente. Não resistindo à  curiosidade, você resolve atender ao chamado.");
    //Va para 187

    enter();
    OP187();
}

//OPCAO 87

void OP087(){
    printf("\t87 - A porta se abre para um aposento grande.");
    //va para 381

    enter();
    OP381();
}

//OPCAO 88

void OP088(){
    stageops = 88;
    save();
    loop = 0;

    printf("\t88 - Logo que os TROGLODITAS o vêem pegam os arcos e correm para cercá-lo. Para seu horror, o líder dá um passo adiante e declara que você é prisioneiro deles e terá que se submetera uma prova, segundo o rito milenar, a Corrida da Flecha.\n\nSe você estiver disposto a participar da Corrida da Flecha, \033[1;35mdigite 343.\033[0;37m\nSe preferir tentar lutar para fugir, \033[1;35mdigite 268.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 343:
                loop++;
                system("cls");
                OP343();
                break;
            case 268:
                loop++;
                system("cls");
                OP268();
                break;
            case 0:
                inventory();
                enter();
                OP088();
                break;
        }
    }
}

//OPCAO 89

void OP089(){
    printf("\t89 - De volta à  solidez do chão da caverna, você tenta sacudir a corda para que saia do pescoço do ídolo. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP054();
            }else{
                luck--;
                system("cls");
                OP261();
            }
        }
    }
}

//OPCAO 90

void OP090(){
    stageops = 90;
    save();
    loop = 0;

    printf("\t90 - Logo que se levanta, você se defronta com o quadro mais repulsivo que seus olhos jamais viram. Ali, na sua frente, chafurda numa poça circular de lodo fétido uma criatura inchada, inacreditavelmente horrível. O corpo é verde e coberto de ameaçadores espinhos. A cara é um amontoado de feridas vermelhas, uma das quais subitamente se abre para revelar mais um dos muitos olhos sinistros que tudo vêem. Um caminho estreito contorna a borda da poça e leva a um outro túnel na parede do outro lado.\n\nSe você já tiver lido detalhes sobre a abjeta BESTA SANGRENTA em um livro encadernado em couro, \033[1;35mdigite 172.\033[0;37m\nSe você não tiver lido o livro, \033[1;35mdigite 357.\033[0;37m\n\n");

    //ITEM
    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 172:
                loop++;
                if(knowledge_bloody_beast != 0){
                    system("cls");
                    OP172();
                }else{
                    printf("Você não leu esse item.");
                    enter();
                    OP090();
                }
                break;
            case 357:
                loop++;
                system("cls");
                OP357();
                break;
            case 0:
                inventory();
                enter();
                OP090();
                break;
        }
    }
}

//OPCAO 91

void OP091(){
    printf("\t91 - A maça de ferro do Orca atinge-lhe o braço, jogando sua espada no chão. Você terá que lutar com as mãos nuas, o que lhe reduz a HABILIDADE em 4 pontos enquanto durar o combate. Felizmente, o túnel é estreito demais para os dois Orcas atacarem-no ao mesmo tempo. Lute com um de cada vez.\n\n\033[1;31mPrimeiro ORCA HABILIDADE 5 ENERGIA 5\nSegundo ORCA HABILIDADE 6 ENERGIA 4\033[0;37m\n\n");

    monsenergy = 5;
    monshability = 5;
    hability -= 4;
    printf("Sua HABILIDADE: %d", hability);
    enter();
    combat1();
    printf("\n\nSua ENERGIA: %d", energy);
    printf("\n\nVOCê ENFRENTARÁ A SEGUNDA ORCA! SE PREPARE PARA O COMBATE");
    monsenergy = 4;
    monshability = 6;
    enter();
    combat1();
    printf("Você recupera a sua espada e sua habilidade retorna ao normal");
    printf("\n\nSua HABILIDADE: %d", hability);
    hability += 4;
    enter();
    OP257();
}

//OPCAO 92

void OP092(){
    printf("\t92 - Reunindo todas as suas forças, você desfere um golpe final no Demônio do Espelho com sua espada. Com um som de estourar os tímpanos, abrem-se rachaduras no rosto e membros do monstro. As várias bocas gritam de agonia nos estertores da morte, antes do Demônio se despedaçar completamente numa pilha de minúsculos cacos. Você solta um enorme suspiro de alívio e depois se apressa a seguir em frente.");
    //Va para 122

    enter();
    OP122();
}

//OPCAO 93

void OP093(){
    stageops = 93;
    save();
    loop = 0;

    printf("\t93 - A porta se abre para um pequeno e escuro aposento, contendo apenas, na parede do lado oposto, uma robusta arca de madeira em cima de uma prateleira. No chão, coberto de poeira espessa, você pode ver claramente pegadas frescas que vão até a arca e retornam à  porta. Você se pergunta se um dos seus rivais está à  sua frente na \"Caminhada\" ou se a arca só foi posta na prateleira recentemente por um dos Juízes da Prova.\n\nSe você quiser entrar no aposento e abrir a arca, \033[1;35mdigite 284.\033[0;37m\nSe preferir continuar percorrendo o túnel, \033[1;35mdigite 230.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 284:
                loop++;
                system("cls");
                OP284();
                break;
            case 230:
                loop++;
                system("cls");
                OP230();
                break;
            case 0:
                inventory();
                enter();
                OP093();
                break;
        }
    }
}

//OPCAO 94

void OP094(){
    printf("\t94 - Respirando fundo, você se debruça sobre o poço e mergulha o braço na massa de vermes que se contorcem. Eles são frios e viscosos, e o contato é extremamente desagradável, mas, pelo menos, são inofensivos, e você consegue pegar o punhal pelo cabo. Ao sacudi-lo firmemente, ele sai da rachadura em que a ponta estava cravada. Admirando-lhe a beleza, e imaginando se ele teria um dia pertencido a um competidor de pouca sorte, você põe o punhal ornamentado de opala firmemente no cinto e sai da caverna.\n\n");

    if(status_OP094 == 0){
        dagger += 1;
        status_OP094 += 1;
        printf("\033[1;34mUma Adaga foi adicionada a seu inventário\033[0;37m");
        enter();
        OP174();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP174();
    }
}

//OPCAO 95

void OP095(){
    printf("\t95 - O anel de ferro está preso a um pequeno alçapão. É fácil  puxa -lo, e, dentro de um pequeno compartimento, você encontra um escudo, finamente trabalhado, feito do mais puro ferro. Maravilhado com o esplendor da peça, você a amarra ao seu braço. \033[1;32mAcrescente 1 ponto de HABILIDADE\033[0;37m. Você caminha na direção das portas duplas e as empurra.\n\n");

    if(status_OP095 == 0){
        hability += 1;
        status_OP095 += 1;
        printf("Você ganhou 1 de HABILIDADE");
        printf("\nSua ENERGIA: %i", energy);
        enter();
        OP248();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP248();
    }
}

//OPCAO 96

void OP096(){
    printf("\t96 - Seu segundo golpe também não consegue partir o espelho. O Demônio do Espelho estica um braço, agarra-lhe o pulso e começa a puxá-lo na direção do espelho. A força é incrível, e, apesar de todos os seus esforços, você não consegue resistir. A cada segundo, você chega mais perto do espelho. Quando o Demônio do Espelho toca o espelho, desaparece através dele. Com horror, você vê seu próprio braço desaparecer também através do espelho, e o resto do corpo logo tem o mesmo destino. \033[1;31mVocê está agora em um mundo de espelhos de outra dimensão, do qual jamais retornará.\033[0;37m");
    death();
}

//OPCAO 97

void OP097(){
    loop = 0;
    printf("\t97 - Você não sabe, mas a Besta Sangrenta só tem um ponto fraco: seus olhos reais. Mais por sorte do que por propósito, você crava sua lâmina profundamente em um deles, e a Besta Sangrenta desaba de volta na poça. Depois de medonhas convulsões, ela afunda sob a superfície oleosa da poça. Sem esperar para ver se ela vai se recuperar, você corre e entra no túnel, ansioso por se afastar da câmara tóxica da Besta Sangrenta o mais rápido possível.");
    //Va para 134

    enter();
    OP134();
}


//OPCAO 98

void OP098(){
    loop = 0;

    printf("\t98 - Erguendo a taça, você aciona um mecanismo de mola, e um dardo é disparado da perna da mesa de madeira. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP105();
            }else{
                luck--;
                system("cls");
                OP235();
            }
        }
    }
}

//OPCAO 99

void OP099(){
    stageops = 99;
    save();
    loop = 0;

    printf("\t99 - Sorrindo, você diz a Erva que a acha muito parecida com Barriga Azeda. Então, enquanto ela olha com admiração para a pintura, você pega um banco quebrado, aproxima-se silenciosamente por trás dela e golpeia-lhe a cabeça com toda a força. Para seu imenso alívio, Erva cai sem sentidos.\n\nSe você quiser revistar-lhe o quarto, \033[1;35mdigite 266.\033[0;37m\nSe não, saia pela porta da parede leste. Você se encontrará no final de um túnel, \033[1;35mdigite 305.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 266:
                loop++;
                system("cls");
                OP266();
                break;
            case 305:
                loop++;
                system("cls");
                OP305();
                break;
            case 0:
                inventory();
                enter();
                OP099();
                break;
        }
    }
}

//OPCAO 100

void OP100(){
    stageops = 100;
    save();
    loop = 0;

    printf("\t100 - Alguns metros adiante, descendo a passagem, você vê uma outra porta fechada na parede da esquerda. Há uma letra X na placa central da porta. Colocando o ouvido na porta, você escuta atentamente, mas não consegue ouvir nada.\n\nSe você quiser abrir a porta, \033[1;35mdigite 87.\033[0;37m\nSe preferir continuar caminhando para o norte, \033[1;35mdigite 217.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 87:
                loop++;
                system("cls");
                OP087();
                break;
            case 217:
                loop++;
                system("cls");
                OP217();
                break;
            case 0:
                inventory();
                enter();
                OP100();
                break;
            default:
                break;
        }
    }
}

//OPCAO 101

void OP101(){
    printf("\t101 - A correnteza do rio é bastante forte, e, atrapalhado pela armadura e a mochila, você não está em condição de nadar contra ela. Em poucos segundos, é arrastado por baixo da ponte. De pé na margem do rio, os Trogloditas olham, riem e gracejam, \033[1;31menquanto você desce o rio para encontrar a morte nas profundezas da montanha.\033[0;37m");
    death();
}

//OPCAO 102

void OP102(){
    stageops = 102;
    save();
    loop = 0;

    printf("\t102 - Você entra em um aposento pequeno e completamente vazio. Logo a porta se fecha atrás de você. Repentinamente, uma voz ressoa, vinda de lugar nenhum: \"Bem vindo ao Calabouço da Morte, o engenhoso labirinto assassino do meu senhor. Aventureiro, creio que você apresentará seus respeitos ao meu senhor gritando seu nome?\".Você gritará:\n\nSalve, Sukumvit? \033[1;35mDigite 133.\033[0;37m\nSukumvit é um verme? \033[1;35mDigite 251.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 133:
                loop++;
                system("cls");
                OP133();
                break;
            case 251:
                loop++;
                system("cls");
                OP251();
                break;
            case 0:
                inventory();
                enter();
                OP102();
                break;
        }
    }
}

//OPCAO 103

void OP103(){
    loop = 0;

    printf("\t103 - Você respira o gás venenoso e começa a se engasgar. \033[1;31mVocê perde 3 pontos de ENERGIA.\033[0;37m");

    if(status_OP103 == 0){
        energy -= 3;
        status_OP103 += 1;
        if(energy < 1){
            death();
        }
        else{
            printf("\n\nSua ENERGIA: %i", energy);
            enter();
            OP077();
        }
    }else{
        energy -= 3;
        if(energy < 1){
            death();
        }
        else{
            printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
            printf("\n\nSua ENERGIA: %i", energy);
            enter();
            OP077();
        }
    }
}
//OPCAO 104

void OP104(){
    loop = 0;
    printf("\t104 - Reagindo rapidamente, você consegue saltar por cima da língua estendida e correr para o túnel, deixando a Besta Sangrenta a chafurdar na poça à  espera de outra vítima.");
    //Va para 134

    enter();
    OP134();
}

//OPCAO 105

void OP105(){
    stageops = 105;
    save();
    loop = 0;

    printf("\t105 - Seus reflexos são precisos, e você rapidamente pula de lado. O dardo passa assobiando, por pouco não o atingindo, e se choca contra a parede do outro lado. Você vê a cálice jogada no chão, e o líquido vermelho escorrendo pela pedra cinzenta como pequenos riachos. Pelo menos a taça pode ser de alguma utilidade, portanto você a põe na mochila.\n\nSe quiser, poderá caminhar de volta para revistar o Bárbaro, \033[1;35mdigite 126.\033[0;37m\nDo contrário, saia da câmara para continuar para o oeste, \033[1;35mdigite 83.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    if(status_OP105 == 0){
        chalice += 1;
        status_OP105 += 1;
        printf("A taça foi adicionada ao seu inventário.");
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 126:
                    loop++;
                    system("cls");
                    OP126();
                    break;
                case 83:
                    loop++;
                    system("cls");
                    OP083();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP105();
                    break;
            }
        }
    }else{
        while(loop < 1){
            printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
            scanf("%i", &choices);
            switch(choices){
                case 126:
                    loop++;
                    system("cls");
                    OP126();
                    break;
                case 83:
                    loop++;
                    system("cls");
                    OP083();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP105();
                    break;
            }
        }
    }
}

//OPCAO 106

void OP106(){
    printf("\t106 - Ao apertar o braço da cadeira, você aciona a mola de um painel secreto, que salta no ar. Você encontra um frasco de vidro e lê o rótulo: \"Poção da Réplica - uma dose apenas. Este líquido fará com que seu corpo tome a forma de qualquer ser que esteja próximo.\" Você coloca a estranha poção na mochila e continua para o norte.\n\n");

    if(status_OP106 == 0){
        morph_potion += 1;
        status_OP106 += 1;
        printf("\033[1;34mPoção de Réplica foi adicionada a seu inventário\033[0;37m");
        enter();
        OP188();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP188();
    }
}

//OPCAO 107

void OP107(){
    stageops = 107;
    save();
    loop = 0;

    printf("\t107 - Você chega a uma porta em arco localizada na parede à  direita do túnel. A pesada porta de pedra está fechada, mas há um trinco de ferro e uma maçaneta redonda.\n\nSe você quiser tentar a porta, \033[1;35mdigite 168.\033[0;37m\nSe, em vez disso, quiser continuar pelo túnel, \033[1;35mdigite 267.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 168:
                loop++;
                system("cls");
                OP168();
                break;
            case 267:
                loop++;
                system("cls");
                OP267();
                break;
            case 0:
                inventory();
                enter();
                OP107();
                break;
        }
    }
}

//OPCAO 108

void OP108(){
    stageops = 108;
    save();
    loop = 0;

    printf("\t108 - Há um grande painel de vidro na parede à  esquerda do túnel. Através dele, você pode ver um aposento intensamente iluminado por tochas com INSETOS GIGANTES de todas as formas possíveis. Abelhas, vespas, besouros, carrapatos, até os bichos do queijo têm mais de seis centímetros de comprimento. O ruído é ameaçador. No meio do aposento, uma coroa cravejada de jóias está colocada sobre uma pequena mesa. No meio da coroa, há uma jóia, parece um grande diamante. Você:\n\nQuebrará o vidro e tentará apanhar a coroa? \033[1;35mDigite 394.\033[0;37m\nContinuará para o oeste? \033[1;35mDigite 59.\033[0;37m\nRetornará à  encruzilhada para seguir para o norte? \033[1;35mDigite 14.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 200:
                loop++;
                system("cls");
                OP200();
                break;
            case 316:
                loop++;
                system("cls");
                OP316();
                break;
            case 0:
                inventory();
                enter();
                OP108();
                break;
        }
    }
}

//OPCAO 109

void OP109(){
    stageops = 109;
    save();
    loop = 0;

    printf("\t109 - Você chega a uma outra encruzilhada no túnel.\n\nSe quiser continuar seguindo para o oeste, \033[1;35mdigite 43.\033[0;37m\nSe quiser seguir para o norte, \033[1;35mdigite 24.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 43:
                loop++;
                system("cls");
                OP043();
                break;
            case 24:
                loop++;
                system("cls");
                OP024();
                break;
            case 0:
                inventory();
                enter();
                OP109();
                break;
        }
    }
}

//OPCAO 110

void OP110(){
    stageops = 110;
    save();
    loop = 0;

    printf("\t110 - O túnel logo faz uma outra curva fechada para a direita. Seguindo para o leste, você chega a uma estranha obstrução: uma linha de 12 postes de madeira atravessados no túnel. Eles estão fixos à s paredes a cerca de meio metro do chão, com um espaço de um metro entre eles.\n\nSe você quiser caminhar entre os postes, \033[1;35mdigite 58.\033[0;37m\nSe preferir subir pelos postes e passar por sobre a obstrução, \033[1;35mdigite 223.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 58:
                loop++;
                system("cls");
                OP058();
                break;
            case 223:
                loop++;
                system("cls");
                OP223();
                break;
            case 0:
                inventory();
                enter();
                OP110();
                break;
        }
    }
}

//OPCAO 111

void OP111(){
    loop = 0;

    printf("\t111 - Você limpa o viscoso lodo amarelo da lâmina de sua espada e caminha rapidamente para a porta, de volta para o túnel, e segue para o norte.");
    //va para 267

    enter();
    OP267();
}

//OPCAO 112

void OP112(){
    loop = 0;
    printf("\t112 - A não ser pelas Provisões, que ficaram encharcadas e \033[1;31mnão servem mais para serem comidas\033[0;37m, todas as suas outras posses permanecem intactas. Você as recoloca cuidadosamente na mochila e parte para o norte de novo.\n\n");
    //Va para 356

    provisions = 0;
    printf("Você perdeu todas as sua PROVISÕES\n");
    printf("Suas PROVISÕES: %d", provisions);
    enter();
    OP356();
}

//OPCAO 113

void OP113(){
    stageops = 113;
    save();
    loop = 0;

    printf("\t113 - A bola de madeira passa assobiando pelo crânio, atingindo a parede do outro lado com um estrondo.\n\nSe você quiser tentar outra vez com a outra bola, \033[1;35mdigite 371.\033[0;37m\nSe já tiver jogado duas vezes, ou não quiser tentar de novo, você pode fechar a porta e continuar pelo túnel, \033[1;35mdigite 74.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 371:
                loop++;
                system("cls");
                OP371();
                break;
            case 74:
                loop++;
                system("cls");
                OP074();
                break;
            case 0:
                inventory();
                enter();
                OP113();
                break;
        }
    }
}

//OPCAO 114

void OP114(){
    stageops = 114;
    save();
    loop = 0;

    printf("\t114 - O Homem da Caverna está usando uma munhequeira de couro com quatro pequenos crânios de rato pendurados.\n\nSe você quiser colocá-la no seu próprio pulso, \033[1;35mdigite 336.\033[0;37m\nSe preferir prosseguir para o norte, \033[1;35mdigite 298.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 336:
                loop++;
                system("cls");
                OP336();
                break;
            case 298:
                loop++;
                system("cls");
                OP298();
                break;
            case 0:
                inventory();
                enter();
                OP114();
                break;
        }
    }
}

//OPCAO 115

void OP115(){
    loop = 0;

    printf("\t 115 - Seu corpo continua a vibrar intensamente, e você se sente como se estivesse prestes a desmaiar. Mas sua força é grande, e você consegue resistir ao tremendo choque sofrido. Finalmente, você se acalma e começa a sentir a ação dos poderes benéficos do anel. Some 3 pontos de ENERGIA. Throm o olha ansioso, e você o tranquiliza, dizendo que está plenamente recuperado. Ele caminha para o leste, você o segue prontamente.");
    //Va para 221

    if(status_OP115 == 0){
        energy_ring += 1;
        status_OP115 += 1;
        printf("O anel foi adicionado ao seu inventário e você ganha 3 de ENERGIA.");
        enter();
        OP221();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP221();
    }
}

//OPCAO 116

void OP116(){
    loop = 0;

    printf("\t116 - Você não consegue acreditar que a Besta Sangrenta não tenha sido afetada pela nova ferida. Você hesita uma fração de segundo demais, e a fera dá um bote, partindo-lhe o crânio com as mandíbulas. \033[1;31mEm seguida, arrasta-o para a poça, onde seu corpo, depois de decomposto, será devorado pela pavorosa criatura.\033[0;37m");
    death();
}

//OPCAO 117

void OP117(){
    stageops = 117;
    save();
    loop = 0;

    printf("\t117 - Depois de longa caminhada túnel abaixo, você chega a um beco sem saída. Um grande espelho, que vai do chão até o teto, está colocado na parede do fundo e, na penumbra, você só consegue visualizar vagamente o seu próprio reflexo.\n\nSe quiser olhar o espelho mais de perto, \033[1;35mdigite 329.\033[0;37m\nSe preferir fazer a longa caminhada de volta para a última encruzilhada no túnel, a fim de prosseguir para o leste, \033[1;35mdigite 135.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 329:
                loop++;
                system("cls");
                OP329();
                break;
            case 135:
                loop++;
                system("cls");
                OP135();
                break;
            case 0:
                inventory();
                enter();
                OP117();
                break;
        }
    }
}

//OPCAO 118

void OP118(){
    loop = 0;
    printf("\t118 - apesar das estalactites que caem por toda parte, você consegue passar ileso pelo arco. Você olha ao redor e vê Throm disparando na sua direção, um braço por cima da cabeça paia protegê-la. Ele corre para o túnel e se encosta na parede fria, a respiração ofegante. Desculpase por ter iniciado o desabamento das rochas e lhe oferece a mão. Você diz a Throm que talvez fosse melhor ele usar a linguagem dos sinais no futuro, mesmo para rir! Os dois sorriem e partem para o leste mais uma vez.");


    enter();
    OP060();
}

//OPCAO 119

void OP119(){
    stageops = 119;
    save();
    loop = 0;

    printf("\t119 - Adiante, você pode ver um grande obstáculo no chão do túnel, embora esteja escuro demais para saber exatamente o que é. As pegadas molhadas que você vem seguindo continuam até a obstrução.\n\nSe você quiser continuar para o leste, \033[1;35mdigite 56.\033[0;37m\nSe preferir voltar para a encruzilhada e seguir para o oeste, \033[1;35mdigite 293.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 56:
                loop++;
                system("cls");
                OP056();
                break;
            case 293:
                loop++;
                system("cls");
                OP293();
                break;
            case 0:
                inventory();
                enter();
                OP119();
                break;
        }
    }
}

//OPCAO 120

void OP120(){
    stageops = 120;
    save();
    loop = 0;

    printf("\t120 - Jogados num buraco de mais ou menos um metro de profundidade, você vê um gancho de ferro e uma bolsa de couro.\n\nSe quiser esticar a mão para apanhá-los, \033[1;35mdigite 228.\033[0;37m\nSe preferir ignorar os objetos e continuar para o norte, \033[1;35mdigite 29\033[0;37m\n\n.");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 0){
        scanf("%i", &choices);
        switch(choices){
            case 228:
                loop++;
                system("cls");
                OP228();
                break;
            case 292:
                loop++;
                system("cls");
                OP292();
                break;
            case 0:
                inventory();
                enter();
                OP120();
                break;
        }
    }
}

//OPCAO 121

void OP121(){
    stageops = 121;
    save();
    loop = 0;

    printf("\t121 - O Anão olha para os dados. \"Você não é muito bom nesse jogo, é?\", graceja. \"Lamento, mas você terá que sofrer uma penalidade antes de continuar.\" Ele retira duas pílulas do bolso. Uma está marcada com a letra S e a outra com a letra L. Pede que você escolha uma e engula.\n\nSe você escolher a pílula marcada com a letra S, \033[1;35mdigite 26.\033[0;37m\nSe quiser engolir a outra, \033[1;35mdigite 354.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 0){
        scanf("%i", &choices);
        switch(choices){
            case 26:
                loop++;
                system("cls");
                OP026();
                break;
            case 354:
                loop++;
                system("cls");
                OP354();
                break;
            case 0:
                inventory();
                enter();
                OP121();
                break;
        }
    }
}

//OPCAO 122

void OP122(){
    stageops = 122;
    save();
    loop = 0;
    printf("\t122 - À sua frente, há dois lances de escadas de pedra, separados por um corrimão de crânios de ratazana.\n\nVocê pode subir pelo lance de escadas da esquerda, \033[1;35mdigite 176.\033[0;37m\nOu pelo da direita, \033[1;35mdigite 384.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 176:
                loop++;
                system("cls");
                OP176();
                break;
            case 384:
                loop++;
                system("cls");
                OP384();
                break;
            case 0:
                inventory();
                enter();
                OP122();
                break;
        }
    }
}

//OPCAO 123

void OP123(){
    loop = 0;

    printf("\t123 - O colar é um amuleto de força. \033[1;32mSome 1 ponto de HABILIDADE e 1 ponto de ENERGIA e continue na sua missão.\033[0;37m");

    if(status_OP123 == 0){
        hability += 1;
        energy += 1;
        status_OP123 += 1;
        printf("\n\nSua ENERGIA: %i", energy);
        printf("\nSua HABILIDADE: %i", hability);
        enter();
        OP282();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP282();
    }
}

//OPCAO 124

void OP124(){
    loop = 0;
    monshability = 5;
    monshability2 = 5;
    monsenergy = 4;
    monsenergy2 = 5;

    printf("\t124 - Você abre o alçapão e sobe os degraus correndo, chegando a um aposento profundamente iluminado por lanternas. Dois GOBLINS afiam espadas curtas em uma pedra colocada no meio do chão. Você os pega desprevenidos, mas eles logo se recuperam e se projetam para frente a fim de atacá-lo.\n\nPrimeiro GOBLIN HABILIDADE 5 ENERGIA 4\nSegundo GOBLIN HABILIDADE 5 ENERGIA 5\n\nOs Goblins o atacarão separadamente em cada Série de Ataque, mas você deve escolher com qual dos dois vai lutar. Ataque o Goblin escolhido como numa batalha normal. Contra o outro, você tem que jogar os dados para determinar sua Força de Ataque da maneira usual, mas, mesmo que sua Força de Ataque seja maior, você não ferirá o Goblin. Compute isso simplesmente como se tivesse se defendido de um golpe dele. Porém, se a Força de Ataque dele for maior, ele o ferirá, da forma costumeira");

    enter();
    combat2();
    printf("\nVocê foi vitorioso no duelo duplo!\n");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP081();



}

//OPCAP 125

void OP125(){
    loop = 0;
    printf("\t125 - Você caminha para a porta na ponta dos pés, enquanto Erva segue tagarelando. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP069();
            }else{
                luck--;
                system("cls");
                OP139();
            }
        }
    }
}

//OPCAO 126

void OP126(){
    stageops = 126;
    save();
    loop = 0;

    printf("\t126 - A bolsa no cinto do Bárbaro contém apenas uma porção de carne seca de aparência estranha, embrulhada num pano. Você:\n\nComerá a carne seca? \033[1;35mDigite 226.\033[0;37m\nDeixará a carne e caminhará para a alcova? \033[1;35mDigite 41.\033[0;37m\nDeixará a câmara e seguirá para o oeste? \033[1;35mDigite 83.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 226:
                loop++;
                system("cls");
                OP226();
                break;
            case 41:
                loop++;
                system("cls");
                OP041();
                break;
            case 83:
                loop++;
                system("cls");
                OP083();
            case 0:
                inventory();
                enter();
                OP126();
                break;
        }
    }
}

//OPCAO 127

void OP127(){
    loop = 0;

    printf("\t127 - A única maneira possível de sair do salão, tanto quanto você pode ver, é usando um escorrega na parede norte. Você resolve arriscar e sobe no escorrega. Desce deslizando suavemente e aterrissa de costas em outro aposento.\n\n");

    if(status_OP127 == 0){
    status_OP127 += 1;
    diamond += 1;
    printf("\033[1;34mO Diamante foi adicionado ao seu inventário.\033[0;37m");
    enter();
    OP090();
    } else{
    printf("\033[1;31mVocê já pegou o diamante\033[0;37m");
    enter();
    OP090();
    }
}

//OPCAO 128

void OP128(){
    stageops = 128;
    save();
    loop = 0;

    printf("\t128 - Na parte de trás da alcova, há uns degraus que conduzem a uma adega abaixo. Teias de aranha tocam-lhe o rosto enquanto você desce. O teto da adega é bastante baixo, e o chão está coberto de lixo e detritos. No meio da parede do outro lado, uma passagem em arco leva a outro túnel iluminado por cristais. Grandes cogumelos crescem no lixo à  sua direita.\n\nSe você quiser atravessar a passagem em arco, \033[1;35mdigite 35.\033[0;37m\nSe preferir parar para comer alguns cogumelos, \033[1;35mdigite 233.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 35:
                loop++;
                system("cls");
                OP035();
                break;
            case 233:
                loop++;
                system("cls");
                OP233();
                break;
            case 0:
                inventory();
                enter();
                OP128();
                break;
        }
    }
}

//OPCAO 129

void OP129(){
    stageops = 129;
    save();
    loop = 0;

    printf("\t129 - Você amarra a corda ao gancho e o atira por cima da muralha. O gancho se prende na pedra, e você começa a se içar. De cima da muralha, vê um monstro gigantesco, semelhante a um dinossauro, circulando em um poço coberto de areia. O grosso couro da criatura é verde malhado, e de pé nas fortes pernas traseiras, deve atingir uns 10 metros de altura. As enormes mandíbulas deixam ver filas de dentes afiados como navalhas ao se abrirem e fecharem com força suficiente para triturar-lhe os ossos. Uma grande porta dupla na parede do outro lado do poço parece ser a única maneira de sair desta parte do calabouço. Você:\n\nDescerá pela corda para dentro do poço, a fim de enfrentar o DIABO DO POÇO? \033[1;35mDigite 349.\033[0;37m\nJogará seu amuleto de osso de macaco no poço? \033[1;35mDigite 361.\033[0;37m\nTentará, de cima da muralha, fisgar O DIABO DO POÇO com o gancho de ferro? \033[1;35mDigite 167.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 349:
                loop++;
                system("cls");
                OP349();
                break;
            case 361:
                loop++;
                if(monkey_amulet != 0){
                    monkey_amulet -= 1;
                    system("cls");
                    OP361();
                } else{
                    printf("Você não possui este item.");
                    enter();
                    OP129();
                }
                break;
            case 167:
                loop++;
                if(iron_hook != 0){
                    system("cls");
                    OP167();
                }
                else{
                    printf("Você não possui este item.");
                    enter();
                    OP129();
                }
                break;
            case 0:
                inventory();
                enter();
                OP129();
                break;
        }
    }
}

//OPCAO 130

void OP130(){
    loop = 0;
    monsenergy = 5;
    monshability = 7;

    printf("\t130 - Os Hobgoblins param de lutar imediatamente. Eles não entendem o que você está dizendo e rosnam agressivamente. Em seguida, desembainham as espadas curtas e avançam para atacá-lo. Lute com um de cada vez.\n\n\033[1;31mPrimeiro HOBGOBLIN HABILIDADE 7 ENERGIA 5\nSegundo HOBGOBLIN HABILIDADE 6 ENERGIA 5\033[0;37m\n\n");
    enter();
    combat1();
    printf("\nVOCê GANHOU DO PRIMEIRO GOBLIN! SE PREPARE PARA O PRàXIMO DUELO");
    enter();
    monsenergy = 5;
    monshability = 6;
    combat1();
    printf("\n\nVOCê GANHOU O DUELO DUPLO!\n");
    printf("Sua ENERGIA: %i", energy);
    enter();
    OP009();
}

//OPCAO 131

void OP131(){
    loop = 0;

    printf("\t131 - Os dardos da besta voam por cima de sua cabeça e se cravam na parede; felizmente, você ainda está agachado. Agora que a armadilha já disparou, você pode sair do aposento pela mesma porta pela qual entrou. De volta no túnel, você segue para o oeste.");

    enter();
    OP074();
}

//OPCAO 132

void OP132(){
    stageops = 132;
    save();
    loop = 0;

    printf("\t132 - Você só tem tempo de ouvir o Gnomo dizer: \"Uma coroa e dois crânios\", antes de ser atingido no peito por um raio branco de energia disparado da fechadura. Você cai sem sentidos. \033[1;33mDigite \"ROLL\" e role um dado\033[0;37m, \033[1;31mo resultado mais 1 é reduzido de sua ENERGIA.\033[0;37m\n\n");
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice1();
            if(numroll > 0){
                energy = (energy - (numroll + 1));
                printf("Sua ENERGIA: %i", energy);
            }
            if(energy > 0){
                printf("\n\nVocê recupera a consciência e o Gnomo manda que tente de novo. Você sabe que colocou uma gema na ranhura certa, mas qual? Você suspira e tenta uma nova combinação.\n\n    A         B         C     \nEsmeralda|Diamante |Safira    -> \033[1;35mDigite 16.\033[0;37m\nDiamante |Safira   |Esmeralda -> \033[1;35mDigite 392.\033[0;37m\nSafira   |Esmeralda|Diamante  -> \033[1;35mDigite 177.\033[0;37m\nEsmeralda|Safira   |Diamante  -> \033[1;35mDigite 287.\033[0;37m\nDiamante |Esmeralda|Safira    -> \033[1;35mDigite 132.\033[0;37m\nSafira   |Diamante |Esmeralda -> \033[1;35mDigite 249.\033[0;37m\n\n");

                printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

                scanf("%i", &choices);
                switch(choices){
                    case 16:
                        loop++;
                        system("cls");
                        OP016();
                        break;
                    case 392:
                        loop++;
                        system("cls");
                        OP392();
                        break;
                    case 177:
                        loop++;
                        system("cls");
                        OP177();
                        break;
                    case 287:
                        loop++;
                        system("cls");
                        OP287();
                        break;
                    case 132:
                        loop++;
                        system("cls");
                        OP132();
                        break;
                    case 249:
                        loop++;
                        system("cls");
                        OP249();
                        break;
                    case 0:
                        inventory();
                        enter();
                        OP132();
                        break;
                }
            }else{
                death();
            }
        }
    }
}

//OPCAO 133

void OP133(){
    loop = 0;

    printf("\t133 - Mais uma vez, a voz misteriosa ecoa, só que agora num tom cheio de desprezo e escárnio. \"Então, temos uma erva daninha em nosso meio, não\", zomba a voz. \"Meu senhor tem um presente especial para você, verme abjeto.\". Subitamente, começa a entrar água no aposento por um buraco no teto. Logo sobe até a altura dos seus tornozelos, e não parece haver qualquer meio de escapar. Você caminha na água até a porta. Está firmemente trancada, mas, no desespero, você tenta arrombá-la, batendo com o ombro. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP178();
            }else{
                system("cls");
                OP017();
            }
        }
    }
}
//OPCAO 134

void OP134(){
    stageops = 134;
    save();
    loop = 0;

    printf("\t134 - O túnel leva a um amplo aposento cujo teto é sustentado por diversos pilares de mármore. Ao entrar no aposento, você depara com uma estranha fera à  sua direita. Tem corpo de leão, asas de dragão, rabo de escorpião e cabeça de velho barbudo.\n\nSe você tiver lido o poema escrito no Pergaminho do Guerreiro Esqueleto, \033[1;35mdigitar 222.\033[0;37m\nSe não tiver lido esse poema, \033[1;35mdigite 247.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 247:
                loop++;
                system("cls");
                OP247();
                break;
            case 222:
                loop++;
                if(read_skeleton_scroll != 0){
                    system("cls");
                    OP222();
                } else{
                    printf("Você não leu este item.");
                    enter();
                    OP134();
                }
                break;
            case 0:
                inventory();
                enter();
                OP134();
                break;
        }
    }
}

//OPCAO 135

void OP135(){
    loop = 0;

    printf("\t135 - Passando pelo buraco perfurado do Verme da Rocha, à  sua esquerda, você logo chega à  encruzilhada. Dá uma olhada rápida no túnel que conduz ao sul, mas não vê ninguém se aproximando. Apressando o passo, você segue velozmente para o leste.");
    enter();
    OP068();
}

//OPCAO 136

void OP136(){
    stageops = 136;
    save();
    loop = 0;

    printf("\t136 - A porta abre para um outro túnel, que se inclina numa subida ao longe. Depois de percorrer essa subida por algum tempo, você chega a uma parte plana, onde numa porta na parede da direita encontra-se pregada uma mão já decomposta.\n\nSe você quiser abrir a porta, \033[1;35mdigite 210.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 78.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 210:
                loop++;
                system("cls");
                OP210();
                break;
            case 78:
                loop++;
                system("cls");
                OP078();
                break;
            case 0:
                inventory();
                enter();
                OP136();
                break;
        }
    }
}

//OPCAO 137

void OP137(){
    stageops = 137;
    save();
    loop = 0;

    printf("\t137 - Caminhando pelo túnel, você se surpreende com um grande sino de ferro pendurado no teto.\n\nSe quiser tocar o sino, \033[1;35mdigite 220.\033[0;37m\nSe preferir contorná-lo e prosseguir para o oeste, \033[1;35mdigite 362.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 220:
                loop++;
                system("cls");
                OP220();
                break;
            case 362:
                loop++;
                system("cls");
                OP362();
                break;
            case 0:
                inventory();
                enter();
                OP137();
                break;
        }
    }
}

//OPCAO 138

void OP138(){
    stageops = 138;
    save();
    loop = 0;

    printf("\t138 - As páginas do livro estão unidas com lacre, mas um pequeno orifício foi cortado no meio delas, de tamanho suficiente para conter uma pequena garrafa arrolhada, na qual há um líquido de cor clara. Você mostra isso a Throm, que levanta a mão, indicando não querer que você sequer chegue perto dele com aquilo; a desconfiança que ele sente em relação à s coisas desconhecidas fica evidente. Você:\n\nBeberá o líquido? \033[1;35mDigite 397.\033[0;37m\nEsfregará o líquido nos seus ferimentos? \033[1;35mDigite 75.\033[0;37m\nAbrirá o livro vermelho? \033[1;35mDigite 52.\033[0;37m\nDeixará a garrafa e o livro de lado para continuar para o norte com Throm? \033[1;35mDigite 369.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 397:
                loop++;
                system("cls");
                OP397();
                break;
            case 75:
                loop++;
                system("cls");
                OP075();
                break;
            case 52:
                loop++;
                system("cls");
                OP052();
                break;
            case 369:
                loop++;
                system("cls");
                OP369();
                break;
            case 0:
                inventory();
                enter();
                OP138();
                break;
        }
    }
}

//OPCAO 139

void OP139(){
    loop = 0;
    monsenergy = 9;
    monshability = 9;

    printf("\t139 - Ao tentar escapar, você é atacado ferozmente por Erva, que, com raiva, vira-se rapidamente, pega um banco quebrado e o atinge com ele. \033[1;31mVocê perde 2 pontos de ENERGIA.\033[0;37m");

    energy -= 2;
    printf("\n\nVocê perdeu 2 de ENERGIA");
    printf("\nSua ENERGIA: %i\n\n", energy);
    if(energy <= 0)
        death();
    else{
        printf("Você consegue desembainhar a espada e lutar.\n\nERVA HABILIDADE 9 ENERGIA 9\n\n");
        combat1();
        printf("\n\nSua ENERGIA: %i", energy);
        printf("\033[1;31m");
        printf("\n\nVocê conseguiu sobreviver ao monstro!");
        printf("\033[0;37m");
        enter();
        OP201();
    }
}

//OPCAO 140

void OP140(){
    loop = 0;

    printf("\t140 - Você tenta forçar o olho de esmeralda com a ponta da espada, procurando enfiá-la por baixo dele. Para sua grande surpresa, ele se despedaça com o contato, soltando um jato de gás venenoso direto no seu rosto. Você desmaia e cai para trás, chocando-se contra o ídolo várias vezes até parar no chão de pedra. \033[1;31mSua aventura termina aqui.\033[0;37m");
    death();
}

//OPCAO 141

void OP141(){
    loop = 0;

    printf("\t141 - O Demônio do Espelho está quase em cima de você quando, reunindo todas as suas forças, você desfere um golpe decisivo contra o espelho com a espada. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP072();
            }else{
                system("cls");
                OP096();
            }
        }
    }
}

//OPCAO 142

void OP142(){
    loop = 0;

    printf("\t142 - Há uma nova ramificação no túnel à  sua esquerda, e, à  frente, você vê dois corpos estendidos no chão. Você pára e dá uma espiada no novo túnel, mas, não vendo nem portas nem criaturas, resolve seguir por ele. Com a espada na mão, você caminha na direção dos corpos estendidos.");

    enter();
    OP338();
}

//OPCAO 143

void OP143(){
    loop = 0;

    printf("\t143 - Você chama o Anão, dizendo-lhe para mandar vir o ESCORPIÃO, pois você está pronto para lutar. Lentamente, a porta de madeira é erguida, e um enorme e grotesco escorpião negro se esgueira por baixo dela e entra no aposento. Você desembainha a espada em guarda e se prepara para enfrentar a sinistra criatura com pinças gigantescas e ferrão mortal.\n\nO Escorpião o ataca com ambas as pinças, e você terá que considerar cada uma das pinças como uma entidade separada, como se lutasse contra duas criaturas. Ambas as pinças possuem HABILIDADE 10, porém cada pinça tem ENERGIA 5 e o atacarão separadamente em cada Série de Ataque, mas você terá que escolher qual delas enfrentará. Ataque uma pinça como numa batalha normal. Contra a outra pinça, você joga os dados para determinar sua Força de Ataque da forma costumeira, mas você não causará ferimentos ao Escorpião, mesmo que sua Força de Ataque seja maior; conte isso como se você tivesse apenas conseguido se defender de um golpe. É claro que, se a Força de Ataque da pinça for maior que a sua, você será ferido da maneira usual. Se, durante qualquer das Séries de Ataque, a Força de Ataque do Escorpião totalizar 22, o combate terminará e terá um evento diferente do evento caso você ganhe.\n\n\033[1;31mESCORPIÃO GIGANTE HABILIDADE 10 ENERGIA 10\033[0;37m");
    monshability = 10;
    monshability2 = 10;
    monsenergy = 5;
    monsenergy2 = 5;
    enter();

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
            if(strcasecmp(combatroll, "roll") == 0){
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
                        printf("HP MONSTRO: %d", monsenergy);
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
                                        }else{
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy -= 1;
                                            loop++;
                                        }
                                        printf("\n\n");
                                    }else if(strcasecmp(luckhit, "nao") == 0)
                                        loop++;
                                }
                                energy -= 2;
                                printf("SEU HP: %d", energy);
                                fight1 += 1;
                                defenseloop += 1;
                                combatloop2 += 1;
                                enter();
                            }
                        }
                    }
                    else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
                        printf("\nVOCE LEVOU DANO\n");
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
                                        }else{
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy -= 1;
                                            loop++;
                                        }
                                        printf("\n\n");
                                    } else if(strcasecmp(luckhit, "nao") == 0)
                                        loop++;
                                }
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
                                        }else{
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy -= 1;
                                            loop++;
                                        }
                                        printf("\n\n");
                                    } else if(strcasecmp(luckhit, "nao") == 0)
                                        loop++;
                                }

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
                                        }else{
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy -= 1;
                                            loop++;
                                        }
                                        printf("\n\n");
                                    } else if(strcasecmp(luckhit, "nao") == 0)
                                        loop++;
                                }

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
//OPCAO 144

void OP144(){
    loop = 0;

    printf("\t144 - Ainda sorrindo, o velho olha para você e diz em voz baixa: \033[1;31m\"Errado.\".\033[0;37m");

    enter();
    OP085();
}

//OPCAO 145

void OP145(){
    loop = 0;
    monsenergy = 6;
    monshability = 8;

    printf("\t145 - O Anão estava esperando seu movimento. Além disso, você não é tão rápido quanto deveria, devido ao sofrimento recente, por isso ele evita seu golpe facilmente, dizendo: \"Eu poderia matá-lo agora, se quisesse, mas estou com saudades de uma luta corpo a corpo.\" Em seguida, ele larga a besta no chão e puxa uma acha do cinto. Apesar da fadiga, você só pensa em vingança.\n\n\033[1;31mANÃO HABILIDADE 8 ENERGIA 6\n\nVocê lutará com -2 de HABILIDADE, por causa da sua condição física.\033[0;37m\n\n");

    hability -= 2;
    combat1();
    hability += 2;
    printf("\n\nSua HABILIDADE FOI RECUPERADA!\nSua ENERGIA: %i", energy);
    printf("\033[1;31m");
    printf("\n\nVocê conseguiu sobreviver ao monstro!");
    printf("\033[0;37m");
    enter();
    OP028();
}

//OPCAO 146

void OP146(){
    stageops = 146;
    save();
    loop = 0;

    printf("\t146 - A dor nos pulmões força-o a subir à  superfície para respirar. Felizmente, nenhum dos Trogloditas o vê e todos se dispersam. Você sai do rio e atravessa a ponte para a margem norte. Quaisquer Provisões restantes que você possa ter estão agora imprestáveis. Você segue pela vasta caverna até que, finalmente, vê um túnel na parede do outro lado. Você anda até ele e chega a uma pesada porta de madeira, que está trancada.\n\nSe você tiver uma chave de ferro, \033[1;35mdigite 86.\033[0;37m\nSe não tiver a chave, \033[1;35mdigite 276.\033[0;37m\n\n");
    provisions = 0;

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    printf("Suas PROVISÕES foram removidas do inventário.\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 276:
                loop++;
                system("cls");
                OP276();
                break;
            case 86:
                loop++;
                if(iron_key != 0){
                    system("cls");
                    OP086();
                } else{
                    printf("Você não tem esta chave.");
                    enter();
                    OP146();
                }
                break;
            case 0:
                inventory();
                enter();
                OP146();
                break;
        }
    }
}

//OPCAO 147

void OP147(){
    printf("\t147 - A água no tubo de bambu é agradavelmente refrescante. \033[1;32mVocê ganha 1 ponto de ENERGIA\033[0;37m. A água contém também uma solução mágica que lhe permite expor-se a temperaturas altíssimas sem sofrer danos. Jogando fora o bambu, você segue para o norte de novo com excelente disposição.\n\n");

    if(status_OP147 == 0){
        high_temperature_potion += 1;
        energy += 1;
        status_OP147 += 1;
        printf("\033[1;32mVocê ganhou 1 de ENERGIA");
        printf("\nSua ENERGIA: %i\033[0;37m", energy);
        enter();
        OP182();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP182();
    }
}

//OPCAO 148

void OP148()
{
    loop = 0;
    luckloop = 0;

    printf("\t148 - Nada há a fazer senão descer as escadas, na direção dos cachorros que latem. Você chega ao pé da escada com a espada na mão e enfrenta os dois gigantescos CÃES DE GUARDA, que saltam sobre você, um de cada vez.\n\n\033[1;31mPRIMEIRO CAO DE GUARDA HABILIDADE 7 ENERGIA 7\nSEGUNDO CAO DE GUARDA HABILIDADE 7 ENERGIA 8\033[0;37m\n\n");

    monsenergy = 7;
    monshability = 7;
    combat1();
    loop = 0;
    while(loop < 1)
    {
        printf("Você deseja FUGIR?\n");
        gets(startroll);
        if(strcasecmp(startroll, "sim") == 0)
        {
            energy -= 2;
            printf("Você recebe 2 de dano.");
            if(energy <= 0)
                death();
            else if(energy > 0)
            {
                printf("\nVocê deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
                while(luckloop < 1)
                {
                    gets(luckhit);
                    if(strcasecmp(luckhit, "sim") == 0){
                        dice2();
                        if(numroll <= luck){
                            luck--;
                            printf("\n\nSua SORTE: %d", luck);
                            energy += 1;
                            luckloop++;
                        }
                        else{
                            luck--;
                            printf("\n\nSua SORTE: %d", luck);
                            energy -= 1;
                            luckloop++;
                        }
                        enter();
                        OP315();
                    }
                    else if(strcasecmp(luckhit, "nao") == 0)
                        loop++;
                }
            }
        }
        else if(strcasecmp(startroll, "nao") == 0)
        {
            printf("\n\nVOCê ENFRENTARÁ O SEGUNDO CÃO! SE PREPARE PARA O COMBATE!\n");
            monsenergy = 8;
            monshability = 7;
            combat1();
            printf("\033[1;35m");
            printf("VOCê VENCEU OS DOIS INIMIGOS!\n");
            printf("\033[0;37m");
            printf("Sua ENERGIA: %d", energy);
            enter();
            OP175();
        }
    }
}

//OPCAO 149

void OP149(){
    loop = 0;
    printf("\t149 - Você solta a corda e ouve ela cair no fundo do poço. O Bárbaro o amaldiçoa, prometendo matá-lo se seus caminhos se cruzarem outra vez. Você recua, toma distância e salta. Cai em segurança do outro lado do poço e continua para o oeste. Mais adiante no túnel, você pisa em uma parte do chão de pedra que se inclina para frente, disparando uma armadilha que solta um rochedo preso frouxamente no teto. Você olha para cima bem no momento em que o rochedo está prestes a cair sobre você. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP070();
            }else{
                luck--;
                system("cls");
                OP353();
            }
        }
    }
}

//OPCAO 150

void OP150(){
    loop = 0;

    printf("\t150 - Tendo tido a boa idéia de não pôr o seu braço da espada dentro do buraco, os efeitos do tentáculo não são muito graves. \033[1;31mVocê perde 1 ponto de HABILIDADE\033[0;37m. Enfiando novamente o braço no buraco, de lá retira o gancho e a bolsa de couro. Dentro da bolsa, você encontra um minúsculo sino de metal. Guarda suas novas posses na mochila e continua para o norte.");


    if(status_OP150 == 0){
        hability -= 1;
        iron_hook += 1;
        metal_bell += 1;
        status_OP150 += 1;
        printf("\n\nSua HABILIDADE: %i", hability);

        printf("\033[1;34m");
        printf("\n- Gancho foi adicionada a seu inventário.");
        printf("\n- Sino de metal foi adicionada a seu inventário.");
        printf("\033[0;37m");
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP292();
    }
}

//OPCAO 151

void OP151(){
    loop = 0;

    printf("\t151 - Quando toca o olho de esmeralda do ídolo, você ouve um rangido abaixo. Ao olhar, fica abismado ao ver os dois pássaros empalhados voando. As asas das criaturas batem aos arrancos, mas logo estão acima de você e parecem prontos para atacar. Lute com um dos GUARDIÃES VOADORES de cada vez, mas reduza sua HABILIDADE em 2 pontos durante este combate, pois a posição restringe-lhe os movimentos.\n\n\033[1;31mPRIMEIRO GUARDIAO VOADOR - HABILIDADE: 7 - ENERGIA: 8\nSEGUNDO GUARDIÃO VOADOR - HABILIDADE: 8 - ENERGIA: 8\033[0;37m\n\n");
    hability -= 2;
    monsenergy = 7;
    monshability = 8;
    enter();
    combat1();
    printf("PREPARE-SE PARA O SEGUNDO COMBATE!");
    enter();
    monsenergy = 8;
    monshability = 8;
    combat1();

    hability += 2;
    OP240();
}

//OPCAO 152

void OP152(){
    loop = 0;

    printf("\t152 - O Anão o cumprimenta por ter adivinhado corretamente. Ele diz que agora você deverá seguir para a segunda fase do teste. Apanhando uma cesta de vime, ele lhe diz que há uma cobra dentro dela. Vira a cesta e a cobra cai ao chão; é uma naja, que se ergue no ar, pronta para o bote. O Anão diz que quer testar suas reações. De mãos vazias, você deverá segurar a naja pelo pescoço, evitando-lhe os dentes mortais.\n\nVocê se agacha, tensionando os músculos para o momento decisivo. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n ");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP055();
            }else{
                system("cls");
                OP202();
            }
        }
    }
}

//OPCAO 153

void OP153(){
    stageops = 153;
    save();
    loop = 0;

    printf("\t153 - A porta abre para um pequeno aposento, no qual há um crânio humano cujos olhos são jóias, pousado sobre um pedestal de mármore. Uma bateria de bestas com dardos está fixada à  parede da esquerda, e duas pequenas bolas de madeira estão no chão, bem perto da porta. Você:\n\nEntrará no aposento e apanhará o crânio? Digite 390.\nJogará, da porta, uma das bolas de madeira no crânio? \033[1;35mDigite 371.\033[0;37m\nFechará a porta e continuará para o oeste, levando as bolas de madeira? \033[1;35mDigite 74.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 390:
                loop++;
                system("cls");
                OP200();
                break;
            case 371:
                loop++;
                system("cls");
                OP316();
                break;
            case 74:
                loop++;
                system("cls");
                OP074();
                break;
            case 0:
                inventory();
                enter();
                OP153();
                break;
        }
    }
}

//OPCAO 154

void OP154(){
    printf("\t154 - Correndo pelo túnel, você logo alcança o Bárbaro e diz a ele que a passagem do leste conduz a um beco sem saída. Ele faz um aceno com a cabeça, num entendimento silencioso, e ambos partem para o oeste.\n\n");
    enter();
    OP022();
}

//OPCAO 155

void OP155(){
    stageops = 155;
    save();
    loop = 0;

    printf("\t155 - As palavras do poema dela cruzam velozmente a sua mente: \"Quando o corredor a água encontrar, não se apresse em recuar...\" Está claro, é aqui que ela quer que você mergulhe na água. Agora, você deve decidir.\n\nSe quiser mergulhar na água, \033[1;35mdigite 378.\033[0;37m\nSe preferir caminhar de volta para o túnel, \033[1;35mdigite 322.\033[0;37m");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 378:
                loop++;
                system("cls");
                OP378();
                break;
            case 322:
                loop++;
                system("cls");
                OP322();
                break;
            case 0:
                inventory();
                enter();
                OP155();
                break;
        }
    }
}

//OPCAO 156

void OP156(){
    stageops = 156;
    save();
    loop = 0;

    printf("\t156 - A pequena placa desliza e se abre facilmente, e você divisa um aposento com um poço profundo no chão atrás da porta. Na parede do outro lado, há dois ganchos de ferro, num dos quais está pendurado um rolo de corda.\n\nSe você quiser abrir a porta, pular por cima do poço e pegar a corda, \033[1;35mdigite 208.\033[0;37m\nSe preferir continuar para o norte pelo túnel, \033[1;35mdigite 326.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 208:
                loop++;
                system("cls");
                OP208();
                break;
            case 326:
                loop++;
                system("cls");
                OP326();
                break;
            case 0:
                inventory();
                enter();
                OP156();
                break;
        }
    }
}

//OPCAO 157

void OP157(){
    printf("\t157 - O pequeno cofre se abre facilmente; dentro, uma bolsa de veludo negro contém uma pérola grande. \033[1;32mSome 1 ponto de SORTE\033[0;37m. Depois de pôr a pérola no bolso, você avança em meio à s teias de aranha.");

    if(status_OP157 == 0){
        luck += 1;
        printf("Você ganhou 1 de SORTE.");
        printf("\n\nSua SORTE: %i", luck);
        enter();
        OP310();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP310();
    }
}

//OPCAO 158

void OP158(){
    loop = 0;

    printf("\t158 - Você leva a moringa aos lábios e toma um gole. O líquido queima tanto que você larga a moringa e segura a garganta em agonia.\033[1;31m Você engoliu ácido! Perde 1 ponto de HABILIDADE e 4 de ENERGIA.\033[0;37m");

    if(status_OP158 == 0){
        hability -= 1;
        energy -= 4;
        status_OP158 += 1;
        printf("\n\nSua HABILIDADE CAIU EM 1");
        printf("\nSua HABILIDADE: %i", hability);
        printf("\n\nSua ENERGIA CAIU EM 4");
        printf("\nSua ENERGIA: %d", energy);
        enter();
        if(energy <= 0){
            death();
        }else if(energy > 0){
            printf("\n\nVocê sobreviveu ao ácido!");
            enter();
            OP275();
        }
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        printf("\n\nSua HABILIDADE CAIU EM 1");
        printf("\nSua HABILIDADE: %i", hability);
        printf("\n\nSua ENERGIA CAIU EM 4");
        printf("\nSua ENERGIA: %d", energy);
        enter();
        if(energy <= 0){
            death();
        }else if(energy > 0){
            printf("\n\nVocê sobreviveu ao ácido!");
            enter();
            OP275();
        }
    }
}

//OPCAO 159

void OP159(){
    stageops = 159;
    save();
    loop = 0;

    printf("\t159 - Suas reações ainda estão lentas por causa do veneno em seu organismo, e, embora você tente pular por cima da língua estendida, suas pernas o traem. A língua pegajosa se enrosca em torno da sua perna, derrubando-o, e começa a puxa-lo na direção da poça. A espada escorregou da sua mão, e você começa a entrar em pânico.\n\nSe você tiver um punhal, \033[1;35mdigite 294.\033[0;37m\nSe não tiver um punhal, \033[1;35mdigite 334.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 334:
                loop++;
                system("cls");
                OP334();
                break;
            case 294:
                loop++;
                if(dagger != 0){
                    system("cls");
                    OP294();
                } else{
                    printf("Você não tem este item.");
                    enter();
                    OP159();
                }
                break;
            case 0:
                inventory();
                enter();
                OP159();
                break;
        }
    }
}

//OPCAO 160

void OP160(){
    printf("\t160 - Sua armadura e sua espada são pesadas e dificultam o salto, mas você aterrissa em segurança, por um triz, na borda do outro lado do poço. Você não perde tempo e se encaminha para o leste.");
    enter();
    OP237();
}

//OPCAO 161

void OP161(){
    printf("\t161 - Você passa sem parar pelos dois Leprechauns e segue para o norte, os risos e a gozação ainda ecoando nos seus ouvidos. Mais adiante no túnel, você pára para descansar e verificar seus pertences. \033[1;31mSe você tinha gemas, elas agora sumiram.\033[0;37m O Leprechaum que caiu sobre as suas costas roubou-as da mochila. Você amaldiçoa os Leprechauns ladrões e prossegue para o norte.\n\n");

    emerald = 0;
    sapphire = 0;
    ruby = 0;
    topaz = 0;
    printf("\033[1;34m");
    printf("VOCê PERDEU TODAS AS SUAS JOIAS");
    printf("\033[0;37m");
    enter();
    OP029();
}

//OPCAO 162

void OP162(){
    loop = 0;
    printf("\t162 - Retirando a tampa da caixa na luz do túnel, você encontra uma chave de ferro e uma gema grande. É uma safira. \033[1;32mSome 1 ponto de SORTE.\033[0;37m Colocando as coisas cuidadosamente na mochila, você parte para o norte mais uma vez.");

    if(status_OP162 == 0){
        iron_key += 1;
        sapphire += 1;
        status_OP162 += 1;
        luck += 1;
        printf("\033[1;34m");
        printf("\n\nUma chave de ferro foi adicionada ao seu inventário");
        printf("\nUma safira foi adicionada ao seu inventário");
        printf("\n\n1 de SORTE foi adicionado");
        printf("\nSua SORTE: %i", luck);
        printf("\033[0;37m");
        enter();
        OP142();
    }else{
        printf("\033[1;34m");
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        printf("\nSua SORTE: %i", luck);
        printf("\033[0;37m");
        enter();
        OP142();
    }
}

//OPCAO 163

void OP163(){
    stageops = 163;
    save();
    loop = 0;

    printf("\t163 - O Anão congratula pela vitória. Ele joga um saco na arena e lhe diz para relaxar e recuperar as forças para a parte final do teste. Depois, ele sai, dizendo que estará de volta em 10 minutos. Você abre o saco e encontra uma moringa com vinho e galinha cozida.\n\nSe você quiser comer o que o Anão ofereceu, \033[1;35mdigite 363.\033[0;37m\nSe preferir simplesmente ficar sentado, esperando que ele volte, \033[1;35mdigite 302.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 363:
                loop++;
                system("cls");
                OP363();
                break;
            case 302:
                loop++;
                system("cls");
                OP302();
                break;
            case 0:
                inventory();
                enter();
                OP163();
                break;
        }
    }
}

//OPCAO 164

void OP164(){
    stageops = 164;
    save();
    loop = 0;

    printf("\t164 - Enquanto você caminha, pingos de água voltam a cair do teto do túnel. Você vê pegadas úmidas, feitas pelas mesmas botas que você havia seguido anteriormente, se dirigindo para o oeste. As pegadas conduzem a uma porta de ferro fechada na parede do lado direito do túnel, mas não parecem continuar a partir dali.\n\nSe quiser abrir a porta, \033[1;35mdigite 299.\033[0;37m\nSe preferir continuar em frente para o oeste, \033[1;35mdigite 83.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 299:
                loop++;
                system("cls");
                OP299();
                break;
            case 83:
                loop++;
                system("cls");
                OP083();
                break;
            case 0:
                inventory();
                enter();
                OP164();
                break;
        }
    }
}

//OPCAO 165

void OP165(){
    printf("\t165 - Há uma ranhura no cadeado, na qual você coloca a moeda. Imediatamente, o cadeado se abre, e você consegue desacorrentar as pernas-de-pau. Você as coloca nos ombros e, mais uma vez, parte para o norte.");

    if(status_OP165 == 0){
        gold -= 1;
        wooden_legs += 1;
        status_OP165 += 1;
        printf("\n\n\033[1;31mUma moeda de ouro foi removida do inventário.");
        printf("\n\033[1;34mPernas-de-Pau foram adicionadas a seu inventário.\033[0;37m");
        enter();
        OP234();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        printf("\n\n\033[1;31mUma moeda de ouro foi removida do inventário.");
        printf("\n\033[1;34mPernas-de-Pau foram adicionadas a seu inventário.\033[0;37m");
        enter();
        OP234();
    }
}

//OPCAO 166

void OP166(){
    printf("\t166 - Ao tocar o olho de esmeralda do ídolo, você ouve um rangido abaixo de si. Olhando na direção do ruído. Você fica abismado ao ver os dois pássaros empalhados voando. As asas dele batem aos arrancos, mas logo estão sobre você e parecem prontos para atacar. Lute com os GUARDIÕES VOADORES um de cada vez, mas reduza a sua HABILIDADE em 3 pontos durante este combate, pois a posição restringe-lhe os movimentos.\n\n\033[1;31mPRIMEIRO GUARDIAO VOADOR HABILIDADE 7 ENERGIA 8\nSEGUNDO GUARDIAO VOADOR HABILIDADE 8 ENERGIA 8\033[0;37m\n\n");
    monsenergy = 8;
    monshability = 7;
    hability -= 3;
    printf("Sua HABILIDADE foi reduzida em 3\n");
    printf("Sua HABILIDADE: %d\n\n", hability);
    enter();
    combat1();
    printf("\n\nSua ENERGIA: %d", energy);
    printf("\n\nVOCê ENFRENTARÁ O SEGUNDO GUARDIAO VOADOR! SE PREPARE PARA O COMBATE");
    monsenergy = 8;
    monshability = 8;
    enter();
    combat1();
    printf("\n\nSua ENERGIA: %d", energy);
    printf("\nVocê recupera os movimentos e sua habilidade retorna ao normal");
    hability += 3;
    printf("\nSua HABILIDADE: %d", hability);
    enter();
    OP011();
}

//OPCAO 167

void OP167(){
    loop = 0;

    printf("\t167 - Você gira o gancho de ferro em torno da cabeça e o atira na fera lá embaixo. As enormes mandíbulas do Diabo do Poços e fecham firmemente sobre o gancho, e, em seguida, ele joga a cabeça para trás. Ainda segurando a corda, você é puxado do alto da muralha e despenca no fundo do poço. \033[1;31mVocê perde 4 pontos de ENERGIA.\033[0;37m");

    if(status_OP167 == 0){
        energy -= 4;
        status_OP167 += 1;
        printf("\n\nSua ENERGIA CAIU EM 4");
        printf("\nSua ENERGIA: %d", energy);
        enter();
        if(energy <= 0){
            death();
        }else if(energy > 0){
            printf("\n\nVOCE SOBREVIVEU!");
            enter();
            OP203();
        }
    }else{
        printf("\n\nSua ENERGIA CAIU EM 4");
        printf("\nSua ENERGIA: %d", energy);
        enter();
        if(energy <= 0){
            death();
        }else if(energy > 0){
            printf("\n\nVOCE SOBREVIVEU!");
            enter();
            OP203();
        }
    }
}
//OPCAO 168

void OP168(){
    stageops = 168;
    save();
    loop = 0;

    printf("\t168 - Levantando o trinco e empurrando a pesada porta de pedra, você se vê em uma grande caverna. A luz é fraca e sombria, mas seus olhos logo se adaptam e você vê que as paredes são úmidas e revestidas de algas verdes. O chão está coberto de palha. A atmosfera é quente, úmida e fétida, e um zumbido suave enche o ar. Com cautela, você avança pela palha na direção de um dos cantos da caverna, onde parece haver um poço raso. Espiando com cuidado para dentro do poço, você fica enojado ao ver uma massa de vermes esbranquiçados que se contorcem, alguns deles chegando a meio metro de comprimento. Nauseado, você está prestes a ir embora quando repara que os corpos ondulantes dos vermes estão amontoados em torno de um punhal, cuja ponta está firmemente presa a uma fenda no fundo do poço. O cabo é envolto em couro negro com incrustações de opalas, e a lâmina é feita de um estranho metal lustrado preto-avermelhado. Você fica doido para pegar a arma, mas isso significaria enfiar a mão no meio daqueles vermes.\n\nVocê tenta apanhar o punhal? \033[1;35mDigite 94.\033[0;37m\nOu recua enojado e sai da caverna? \033[1;35mDigite 267.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 94:
                loop++;
                system("cls");
                OP094();
                break;
            case 267:
                loop++;
                system("cls");
                OP267();
                break;
            case 0:
                inventory();
                enter();
                OP168();
                break;
        }
    }
}

//OPCAO 169

void OP169(){
    loop = 0;

    printf("\t169 - Ele olha desconfiado quando você lhe oferece uma parte das suas Provisões. Mas a fome é mais forte que o medo, e ele acaba pondo a comida na boca. Você pergunta o que ele está fazendo nos túneis, e ele explica que é servo de um dos Juízes da Prova, os controladores de seções do calabouço designados pelo Barão Sukumvit. Diz que gostaria de escapar, mas ninguém pode sair do calabouço, a fim de impedir que o segredo da construção seja revelado. Você diz-se um dos concorrentes na Prova dos Campeões e que apreciaria qualquer tipo de ajuda. Esfregando o queixo, ele vira-se para você e diz: \"Tudo o que lhe posso dizer é que, em um dos túneis setentrionais, há uma cadeira esculpida na forma de um pássaro demoníaco; um painel secreto no braço da cadeira contém uma poção em um frasco de vidro. é uma Poção de Réplica. Agora, preciso realizar minhas tarefas. Boa sorte. Espero que nos encontremos de novo fora destes túneis infernais.\" O homem sai se arrastando e você continua sua jornada para o oeste.");

    if(status_OP169 == 0){
        knowledge_morph_potion += 1;
        provisions -= 1;
        status_OP169 += 1;
        printf("\033[1;34m");
        printf("\n\n\033[1;34mVOCê ADQUIRIU O CONHECIMENTO QUE EXISTE UMA POÇÃO DE RÉPLICA, ACHE-A NO CALABOUÇO\033[0;37m");
        printf("\033[0;37m");
        enter();
        OP109();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP109();
    }
}

//OPCAO 170

void OP170(){
    stageops = 170;
    save();
    loop = 0;

    printf("\t170 - Ao se aproximar da figura prostrada, você vê que é um dos seus rivais na Prova dos Campeões. É, na realidade, a Mulher-elfo. Ela luta tenazmente pela vida, envolta no abraço de uma enorme JIBàIA que lhe esmaga os ossos.\n\nSe você quiser ajudá-la, \033[1;35mdigite 281.\033[0;37m\nSe preferir deixá-la à  própria sorte e retornar pelo túnel para seguir para o norte, \033[1;35mdigite 192.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 281:
                loop++;
                system("cls");
                OP281();
                break;
            case 192:
                loop++;
                system("cls");
                OP192();
                break;
            case 0:
                inventory();
                enter();
                OP170();
                break;
        }
    }
}

//OPCAO 171

void OP171(){
    loop = 0;

    printf("\t171 - A porta abre para um pequeno aposento, mas, antes que saiba o que está acontecendo, você despenca no vazio havia um poço atrás da porta e você não o viu. Você cai pesadamente no fundo e se contorce em dores. \033[1;31mPerde 4 pontos de ENERGIA\033[0;37m. As paredes do poço são rugosas e têm muitos pontos onde apoiar os pés e as mãos; por isso, você consegue fazer a escalada e sair com bastante facilidade. Você amaldiçoa sua própria ansiedade e diz a si mesmo que doravante será mais cuidadoso. No interior do aposento, você vê dois ganchos de ferro numa das paredes. Há um rolo de corda pendurado em um deles; você o coloca na mochila, salta de volta por cima do poço e sai do aposento, dirigindo-se ao norte.\n\n");

    if(status_OP171 == 0){
        rope += 1;
        energy -= 4;
        status_OP171 += 1;
        printf("\033[1;31mVocê perdeu 4 de ENERGIA");
        printf("\nSua ENERGIA: %i\033[0;37m\n\n", energy);
        printf("\033[1;34mO ROLO DE CORDA FOI ADICIONADO A SEU INVENTÁRIO\033[0;37m");
        enter();
        OP326();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP326();
    }
}

//OPCAO 172

void OP172(){
    loop = 0;

    printf("\t172 - Lembrando da descrição da abjeta Besta Sangrenta, e da advertência quanto aos gases tóxicos que exalam da poça da fera, você cobre a boca com a manga da camisa e, atento, avança, espada na mão, para a língua do monstro. Enquanto você contorna a poça, a fera se projeta para frente e estica a língua, mas você está prevenido e a perfura com um golpe da espada. A fera urra de dor e se estica, frenética, para fora da poça, tentando abocanhá-lo com as mandíbulas inundadas de sangue. Você golpeia-lhe a carantonha com a espada, na tentativa de atingir-lhe os olhos verdadeiros.\n\n\033[1;31mBESTA SANGRENTA - HABILIDADE: 12 - ENERGIA: 10\033[0;37m\n\n");

    monsenergy = 10;
    monshability = 12;

    printf("COMEÇOU O COMBATE!");
    combatloop = 0;
    atkseries = 0;
    while(combatloop < 1){
        loop = 0;
        printf("\nRode os dados:\n");
        printf("\033[0;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        gets(combatroll);
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
            atkseries += 1;
            monsenergy -= 2;
            if(atkseries >= 2){
                printf("\nVOCê GANHOU 2 SÉRIES DE ATAQUE!");
                enter();
                OP278();
            }
            printf("\nVocê deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
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
            printf("HP MONSTRO: %d", monsenergy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
            printf("\nVOCE LEVOU DANO\n");
            printf("\nVocê deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
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

//OPCAO 173

void OP173(){
    stageops = 173;
    save();
    loop = 0;

    printf("\t173 - A água fresca é revigorante e vem de uma fonte que foi salpicada com poeira de Duende.\n\nVocê pode beber da outra fonte, digite 337.\nOu continuar para o norte, digite 368.\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 337:
                loop++;
                system("cls");
                OP337();
                break;
            case 368:
                loop++;
                system("cls");
                OP368();
                break;
            case 0:
                inventory();
                enter();
                OP173();
                break;
        }
    }

}

//OPCAO 174

void OP174(){
    loop = 0;

    printf("\t174 - Quando você está retornando para a porta, o zumbido aumenta de intensidade, e você procura desesperadamente descobrir de onde ele vem. Ao olhar para o alto, você vê num relance a imensa e grotesca forma negra de uma MOSCA GIGANTE surgindo de uma reentrância no alto da parede da caverna. Ao se aproximar, você se dá conta de que ela tem pelo menos um metro e meio de comprimento. As asas opacas vibram, produzindo o abominável zumbido que você vem ouvindo; as seis pernas peludas estão posicionadas para agarrá-lo; abaixo dos olhos multifacetados, há uma longa probóscida, negra e lustrosa, que se movimenta malignamente para dentro e para fora. Você retirou o tesouro da Mosca Gigante do ninho de larvas, e agora deve enfrentar as consequências.\033[1;33m Digite \"ROLL\" e teste sua SORTE.\033[0;37m");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP039();
            }else{
                luck--;
                system("cls");
                OP350();
            }
        }
    }
}

//OPCAO 175

void OP175(){
    loop = 0;

    printf("\t175 - Presa à  coleira de um dos Cães de Guarda, há uma cápsula de metal. Você retira a parte de cima da cápsula e encontra um pequeno dente lá dentro. É um dente de Leprechaum, que lhe trará boa sorte. \033[1;32mSome 2 pontos de SORTE\033[0;37m. Você põe o dente no bolso e parte para o leste pelo túnel.");

    if(status_OP175 == 0){
        luck += 2;
        status_OP175 += 1;
        printf("\n\nFOI ADICIONADO DOIS PONTOS DE SORTE");
        printf("\nSua SORTE: %d", luck);
        enter();
        OP315();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP315();
    }
}

//OPCAO 176

void OP176(){
    loop = 0;

    printf("\t176 - Caminhando cuidadosamente, você vai subindo os degraus devagar. Logo chega ao topo sem problemas. Continue pelo túnel adiante.");
    enter();
    OP277();
}

//OPCAO 177

void OP177(){
    loop = 0;

    printf("\t177 - Você só tem tempo para ouvir o Gnomo gritar: \"Três coroas!\", antes que a fechadura estale e abra. Quando a pesada porta gira lentamente para fora, o Gnomo corre na direção dela, jogando a bola de vidro a seus pés. Um gás verde escapa do vidro quebrado, e você tenta não o inspirar. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP243();
            }else{
                system("cls");
                OP103();
            }
        }
    }

}

//OPCAO 178

void OP178(){
    loop = 0;

    printf("\t178 - A porta não resiste às violentas pancadas que você desfere. A placa central racha e se despedaça; você abre a pontapés um buraco grande o bastante para por ele se esgueirar. Molhado, mas feliz por ter sobrevivido a essa ameaça, você parte para o norte de novo.");
    enter();
    OP344();
}

//OPCAO 179

void OP179(){
    stageops = 179;
    save();
    loop = 0;

    printf("\t179 - Quando você parte na direção do Anão, ele tira do cinto dois dardos de mão e os atira contra você e Throm, atingindo-os nas pernas. Ambos ficam instantaneamente paralisados pelo veneno existente na ponta dos dardos. Você perde 2 pontos de ENERGIA. Como que pregado ao chão, você vê o Anão se aproximar e retirar-lhe o dardo coxa. Ele pergunta se agora você está disposto a entrar da em seu campeonato. Você se esforça para balançar a cabeça afirmativamente. Aos poucos, os efeitos do veneno se dissipam, e a mobilidade retorna. O Anão ordena que você o siga e que Throm espere o retorno dele. Ele abre uma porta secreta na parede da câmara, e vocês entram em um pequeno aposento circular. Ele fecha a porta atrás de você e lhe dá dois dados de osso, mandando que os jogue no chão. Você tira um seis e um dois, total oito. O Anão ordena um novo lançamento, mas desta vez você tem que adivinhar o total: será igual, maior ou menor que oito?\n\nSe você preferir igual a oito, \033[1;35mdigite 290.\033[0;37m\nSe optar por maior que oito, \033[1;35mdigite 84.\033[0;37m\nSe escolher menor que oito, \033[1;35mdigite 191.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 290:
                loop++;
                system("cls");
                OP290();
                break;
            case 84:
                loop++;
                system("cls");
                OP084();
                break;
            case 191:
                loop++;
                system("cls");
                OP191();
                break;
            case 0:
                inventory();
                enter();
                OP179();
                break;
        }
    }
}

//OPCAO 180

void OP180(){
    loop = 0;

    printf("\t180 - Você avança na direção da Besta Sangrenta; de repente, sente-se fraco. O gás que emana da poça é altamente tóxico, e você vai ao chão, inconsciente. \033[1;33mDigite \"ROLL e teste sua SORTE.\033[0;37m");
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP053();
            }else{
                luck--;
                system("cls");
                OP272();
            }
        }
    }
}

//OPCAO 181

void OP181(){
    loop = 0;

    printf("\t181 - O túnel conduz a um salão com piso de mármore e pilares que se erguem até o teto. Ao atravessar o piso, suas passadas ecoam pelo salão. Os cabelos da sua nuca começam a ficar em pé, pois você pressente que está sendo observado. Sem que você saiba, um dos seus rivais se esconde atrás de um pilar. é o NINJA, o terrível assassino vestido com o manto negro. Sem qualquer ruído, ele sai do esconderijo e joga um disco estrelado nas suas costas. Uma voz interior manda que você se abaixe. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m");
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP312();
            }else{
                luck--;
                system("cls");
                OP045();
            }
        }
    }
}

//OPCAO 182

void OP182(){
    stageops = 182;
    save();
    loop = 0;

    printf("\t182 - A temperatura continua a subir, e você começa a pingar suor. Adiante, o calor se intensifica. Parece que você está numa fornalha. A situação é tão insuportável que você começa a desfalecer.\n\nSe você tiver bebido o líquido do tubo de bambu, \033[1;35mdigite 25.\033[0;37m\nSe não tiver parado para beber o líquido, \033[1;35mdigite 242.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 242:
                loop++;
                system("cls");
                OP242();
                break;
            case 25:
                loop++;
                if(high_temperature_potion != 0){
                    system("cls");
                    OP025();
                } else{
                    printf("Você não leu este item.");
                    enter();
                    OP182();
                }
                break;
            case 0:
                inventory();
                enter();
                OP182();
                break;
        }
}
}

//OPCAO 183

void OP183(){
    stageops = 183;
    save();
    loop = 0;

    printf("\t183 - Você sobe nas pernas-de-pau e dá alguns passos experimentais. Sua confiança aumenta, e logo você se sente capaz de enfrentar a caminhada pelo lodo. A fumaça sobe da base das pernas-de-pau: o lodo começa a corroê-las. Você segue em frente com firmeza e acaba atingindo terreno sólido de novo. Infelizmente, as pernas-de-pau ficam cobertas de lodo, e você é forçado a abandoná-las.\n\nSe quiser ir para o oeste, \033[1;35mdigite 386.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 218.\033[0;37m\n\n");

    wooden_legs -= 1;
    printf("Pernas-de-Pau removidas do seu inventário.\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 386:
                loop++;
                system("cls");
                OP386();
                break;
            case 218:
                loop++;
                system("cls");
                OP218();
                break;
            case 0:
                inventory();
                enter();
                OP183();
                break;
        }
    }
}

//OPCAO 184

void OP184(){
    stageops = 184;
    save();
    loop = 0;

    printf("\t184 - O Bárbaro, que se diz chamar Throm, amarra a corda em volta da cintura, dando-lhe a outra ponta. Ao acender a tocha, você nota um ar de desconfiança nos olhos do Bárbaro. Lentamente, ele sobe na borda do poço, enquanto você se firma no chão e segura a corda tensa. Ao abaixá-lo aos poucos, você vê os lados lisos do poço iluminados pela tocha de Throm. Ele finalmente chega ao fundo e grita que há um outro túnel rumo ao norte. Manda que você prenda a corda em uma rocha saliente na borda do poço e desça.\n\nSe você quiser ficar com o Bárbaro e seguir para o norte pelo túnel inferior, \033[1;35mdigite 323.\033[0;37m\nSe desejar abandoná-lo, pulando por cima do poço para se dirigir ao oeste, \033[1;35mdigite 149.\033[0;37m");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 323:
                loop++;
                system("cls");
                OP323();
                break;
            case 149:
                loop++;
                system("cls");
                OP149();
                break;
            case 0:
                inventory();
                enter();
                OP184();
                break;
        }
    }
}

//OPCAO 185

void OP185(){
    stageops = 185;
    save();
    loop = 0;

    printf("\t185 - Os Trogloditas estão tão concentrados na dança tribal que não ouvem o ruído da sua espada, e você engatinha e passa. Quando acha que está suficientemente longe, você se levanta e corre pelo piso da caverna. À sua frente, corre um rio subterrâneo de leste para oeste através da caverna; sobre ele, uma ponte de madeira. Ao ouvir um barulho, você olha para trás e toma consciência de que foi descoberto. Os Trogloditas estão vindo atrás de você.\n\nSe quiser correr pela ponte, \033[1;35mdigite 318.\033[0;37m\nSe preferir mergulhar no rio, \033[1;35mdigite 47.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 47:
                loop++;
                system("cls");
                OP047();
                break;
            case 318:
                loop++;
                system("cls");
                OP318();
                break;
            case 0:
                inventory();
                enter();
                OP185();
                break;
        }
    }
}

//OPCAO 186

void OP186(){
    loop = 0;

    printf("\t186 - Lenta e cuidadosamente, você começa a escalar o ídolo. Quando está prestes a segurar na grande orelha, seu pé escorrega. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP260();
            }else{
                luck--;
                system("cls");
                OP358();
            }
        }
    }

}

//OPCAO 187

void OP187(){
    stageops = 187;
    save();
    loop = 0;

    printf("\t187 - O túnel faz uma curva fechada para a direita, depois da qual você vê um velhinho de barba longa encolhido atrás de uma grande cesta de vime. A cesta está amarrada a uma corda cuja ponta desaparece no teto. Com aparência preocupada,o velho diz: \"Não me ataque, estranho. Não sou nenhuma ameaça para você. Estou aqui simplesmente para ajudá-lo. Se você fizesse a gentileza de me oferecer algum tipo de remuneração, eu ficarei feliz em içá-lo na cesta para o nível superior. E, acredite-me, você deveria estar lá.\".\n\nSe você quiser dar ao homem alguma coisa da sua mochila pelo serviço, \033[1;35mdigite 360.\033[0;37m\nSe preferir passar por ele e seguir pelo túnel, \033[0;35mdigite 280.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 360:
                loop++;
                system("cls");
                OP360();
                break;
            case 280:
                loop++;
                system("cls");
                OP280();
                break;
            case 0:
                inventory();
                enter();
                OP187();
                break;
        }
    }
}

//OPCAO 188

void OP188(){
    stageops = 188;
    save();
    loop = 0;

    printf("\t188 - O túnel começa a declinar e termina numa poça profunda.\n\nSe você conseguir se lembrar do poema da garota-espírito, \033[1;35mdigite 155.\033[0;37m\nSe não tiver encontrado a garota-espírito, \033[1;35mdigite 224.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 224:
                loop++;
                system("cls");
                OP224();
                break;
            case 155:
                loop++;
                if(knowledge_deadgirl_poem != 0){
                    system("cls");
                    OP155();
                } else{
                    printf("Você não possui esta SKILL.");
                    enter();
                    OP188();
                }
                break;
            case 0:
                inventory();
                enter();
                OP188();
                break;
        }
}
    // KNOWLEDGE POEM OF THE SPIRIT GIRL
}

//OPCAO 189

void OP189(){
    printf("\t189 - As pontas da maça do Orca penetram dolorosamente na sua coxa esquerda. Você perde 3 pontos de ENERGIA. Você cambaleia para trás, mas consegue recuperar o equilíbrio a tempo de se defender. Felizmente, o túnel é estreito demais para que ambos os Orcas ataquem-no a um só tempo. Lute com um de cada vez.\n\n\033[1;31mPRIMEIRA ORCA  HABILIDADE 5 ENERGIA 5\nSEGUNDA ORCA  HABILIDADE 6 ENERGIA 4\n\n\033[0;37m");

    monsenergy = 5;
    monshability = 5;
    enter();
    combat1();
    printf("PREPARE-SE PARA O SEGUNDO COMBATE!");
    enter();
    monsenergy = 4;
    monshability = 6;
    combat1();
    printf("Você derrotou AS DUAS ORCAS!");
    enter();
    OP257();
}

//OPCAO 190

void OP190(){
    loop = 0;

    printf("\t190 - Seu corpo vibra desenfreadamente, e você não consegue evitar o desmaio. \033[1;31mVocê perde 3 pontos de ENERGIA\033[0;37m.\n\n");

    energy -= 3;
    printf("Você perdeu 3 de ENERGIA");
    printf("sua ENERGIA: %d", energy);
    if(energy <= 0)
    death();
    else{
        printf("Você sobreviveu");
        enter();
        OP050();
    }
}

//OPCAO 191

void OP191(){
    printf("\t191 - \033[1;33mDigite \"ROLL\" e role os dados.\033[0;37m\n\n");
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= 8){
                system("cls");
                OP152();
            }
            else{
                system("cls");
                OP121();
            }
        }
    }
}

//OPCAO 192

void OP192(){
    stageops = 192;
    save();
    loop = 0;

    printf("\t192 - Caminhando pelo túnel, você repara em uma grade de ferro no chão.\n\nSe quiser parar e levantá-la, \033[1;35mdigite 120.\033[0;37m\nSe preferir prosseguir, \033[1;35mdigite 292.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 120:
                loop++;
                system("cls");
                OP120();
                break;
            case 292:
                loop++;
                system("cls");
                OP292();
                break;
            case 0:
                inventory();
                enter();
                OP192();
                break;
        }
    }
}

//OPCAO 193

void OP193(){
    printf("\t193 - O ácido queima a parede do seu estômago, penetrando nos seus órgãos vitais.\033[1;31m Você tomba inconsciente para nunca mais se recuperar. Sua aventura termina aqui.\033[0;37m");
    death();
}

//OPCAO 194

void OP194(){
    stageops = 194;
    save();
    loop = 0;

    printf("\t194 - Em uma plataforma de pedra na parede do túnel, você vê dois livros empoeirados encadernado sem couro. Throm expressa seu desprezo pela palavra escrita com um grunhido, insistindo para que você deixe os livros de lado e siga adiante com ele. Você:\n\nAbrirá o livro de couro vermelho? \033[1;35mDigite 52.\033[0;37m\nAbrirá o livro de couro preto? \033[1;35mDigite 138.\033[0;37m\nContinuará para o norte do túnel? \033[1;35mDigite 369.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 52:
                loop++;
                system("cls");
                OP052();
                break;
            case 138:
                loop++;
                system("cls");
                OP138();
                break;
            case 369:
                loop++;
                system("cls");
                OP369();
                break;
            case 0:
                inventory();
                enter();
                OP194();
                break;
        }
    }
}

//OPCAO 195

void OP195(){
    printf("\t195 - Você desembainha a espada e corre na direção do velho. Ele ergue o braço esquerdo e, subitamente, você esbarra em uma barreira invisível. \"Não seja tolo, meus poderes são grandes!\", diz o velho calmamente. \"Se você não acredita em mim, veja isto.\" Saindo do nada, um punho voador lhe desfere um soco no rosto antes que você possa se esquivar. \033[1;31mVocê perde 1 ponto de ENERGIA\033[0;37m. Você sacode a cabeça e esfrega o queixo. Parece que não tem alternativa senão tentar responder à  pergunta do velho.");

    energy -= 1;
    printf("\n\nVocê perdeu 1 de ENERGIA\n");
    printf("Sua ENERGIA: %d\n", energy);
    if(energy <= 0)
        death();
    else{
        enter();
        OP382();
    }
}

//OPCAO 196

void OP196(){
    loop = 0;
    monsenergy = 11;
    monshability = 11;

    printf("\t196 - Você levanta o escudo bem a tempo de se proteger de uma saraivada de espinhos lançados contra seu coração pela cauda do Mantécora. Ileso, com os espinhos cravados no escudo, você desembainha a espada e avança para o Mantécora.\n\n\033[1;31mMANTÉCORA - HABILIDADE: 11 - ENERGIA: 11\033[0;37m");

    enter();
    combat1();
    enter();
    OP364();
}

//OPCAO 197

void OP197(){
    stageops = 197;
    save();
    loop = 0;

    printf("\t197 - Graças aos céus, a temperatura agora começa a cair rapidamente, e logo parece quase fresca de novo. No lado esquerdo do túnel, há uma porta fechada e nela, uma pequena placa de ferro que talvez possa ser aberta. Você:\n\nTentará abrir a porta? \033[1;35mDigite 171.\033[0;37m\nTentará fazer deslizar a placa de ferro? \033[1;35mDigite 156.\033[0;37m\nContinuará para o norte, subindo o túnel? \033[1;35mDigite 326.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 171:
                loop++;
                system("cls");
                OP171();
                break;
            case 156:
                loop++;
                system("cls");
                OP156();
                break;
            case 326:
                loop++;
                system("cls");
                OP326();
                break;
            case 0:
                inventory();
                enter();
                OP197();
                break;
        }
    }
}

//OPCAO 198

void OP198(){
    printf("\t198 - Quando o gás se dissipa, você caminha de volta para a arca e olha dentro dela. Há uma corrente com pingente jogada no fundo, mas alguém já retirou a pedra que estava incrustada nele. Isso o aborrece tanto que você o atira ao chão e sai furioso do aposento, subindo o túnel.");
    enter();
    OP230();
}

//OPCAO 199

void OP199(){
    loop = 0;

    printf("\t199 - Os dardos da besta são em número tão grande que é impossível evitá-los. Jogue um dado para determinar o número de dardos que lhe atingem o corpo, \033[1;31mperdendo 2 pontos de ENERGIA\033[0;37m para cada um deles. \033[1;33mDigite \"roll\" e role os dados.\033[0;37m");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll")== 0){
            dice1();
            dards = (numroll * 2);
            energy -= dards;
            if(energy <= 0){
                loop++;
                death();
            }else{
                luck--;
                loop++;
                printf("\n\nVocê terá que descansar aqui por um longo tempo para se recuperar dos ferimentos. \033[1;31mPerde 1 ponto de SORTE.\033[0;37m Quando você, finalmente, se sente forte o bastante para seguir adiante, sai do aposento e continua para o oeste pelo túnel.\n\n");

                printf("\033[1;31mVocê perdeu 1 de SORTE\n\033[0;37m");
                printf("Sua SORTE: %d", luck);

                printf("\n\n\033[1;31mVocê perdeu %d de ENERGIA com os dardos\n\033[0;37m", dards);
                printf("Sua ENERGIA: %d", energy);
                enter();
                OP074();
            }
        }
    }
}

//OPCAO 200

void OP200(){
    stageops = 200;
    save();
    loop = 0;

    printf("\t200 - A porta abre para um pequeno aposento como chão coberto de palha. No centro do aposento, há uma grande gaiola coberta de cerca de dois metros de altura; uma corda presa ao topo da cobertura de pano passa por um anel de ferro no teto e desce até o chão.\n\nSe você quiser levantar o pano, \033[1;35mdigite 321.\033[0;37m\nSe preferir sair do aposento e se dirigir para o norte pelo túnel, \033[1;35mdigite 316.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 321:
                loop++;
                system("cls");
                OP321();
                break;
            case 316:
                loop++;
                system("cls");
                OP316();
                break;
            case 0:
                inventory();
                enter();
                OP200();
                break;
        }
    }

}

//OPCAO 201

void OP201(){
    loop = 0;

    printf("\t201 - Você revista os armários e caixas no quarto de Erva mas não encontra nada, a não ser um osso velho. Há uma porta na parede leste da câmara, e você resolve sair. Pode levar o osso velho, se quiser. Você agora está de pé no final de um outro túnel.\n\n");
    printf("Deseja levar o osso velho? - Digite \033[1;32m\"SIM\"\033[0;37m ou \033[1;31m\"NAO\"\033[0;37m\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "sim")== 0){
            loop++;
            old_bone += 1;
            printf("\033[1;34m");
            printf("\nO osso velho foi adicionado ao seu inventário");
            printf("\033[0;37m");
            enter();
            OP305();
        }else if(strcasecmp(startroll, "nao")== 0){
            loop++;
            enter();
            OP305();
        }
    }
}

//OPCAO 202

void OP202(){
    loop = 0;

    printf("\t202 - As reações da naja são mais rápidas do que as suas, e a cabeça estufada do animal se projeta para mordê-lo. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP018();
            }else{
                luck--;
                system("cls");
                OP042();
            }
        }
    }
}

//OPCAO 203

void OP203(){
    loop = 0;
    monsenergy = 15;
    monshability = 12;

    printf("\t203 - Você se levanta com dificuldade e desembainha a espada. Faz isso bem a tempo, pois a assustadora fera se aproxima velozmente. Esta vai ser uma das lutas mais difíceis de sua vida.\n\n\033[1;31mDIABO DO POÇO HABILIDADE: 12 ENERGIA: 15\033[0;37m\n\n");
    combat1();
    printf("\nVOCê SOBREVIVEU A FERA ASSUSTADORA!\n");
    printf("\n\nSua ENERGIA: %i", energy);
    enter();
    OP258();
}

//OPCAO 204

void OP204(){
    loop = 0;

    printf("\t204 - Há uma placa sensível à  pressão no topo do pedestal, e, logo que o crânio é colocado de volta sobre ele, o mecanismo invisível é disparado. Imediatamente, uma chuva de dardos lançados pela besta atravessa o aposento. \033[1;33mDigite \"ROLL\"\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP131();
            }else{
                luck--;
                system("cls");
                OP199();
            }
        }
    }
}

//OPCAO 205

void OP205(){
    stageops = 205;
    save();
    loop = 0;

    printf("\t205 - Correndo atrás dos Leprechauns, você ouve mais risos, só que agora eles vêm de trás de você. Você se vira e vê mais seis Leprechauns saindo de uma porta oculta na parede do túnel. De repente, mais um Leprechaun salta de uma plataforma fixada no teto e cai sobre suas costas. Livrando-se dele com um safanão, você desembainha a espada, o que faz com que os Leprechauns riam ainda mais alto.\n\nSe você quiser atacá-los, \033[1;35mdigite 306.\033[0;37m\nSe preferir tentar passar por eles, \033[1;35mdigite 161.\033[0;37m");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 306:
                loop++;
                system("cls");
                OP306();
                break;
            case 161:
                loop++;
                system("cls");
                OP161();
                break;
            case 0:
                inventory();
                enter();
                OP205();
                break;
        }
    }

}

//OPCAO 206

void OP206(){
    printf("\t206 - As estalactites continuam a cair ao redor, mas você não tem força suficiente para fazer mais do que se arrastar na direção do arco. De repente, sente um braço em volta da cintura e se dá conta, em estado de semi-inconsciência, de que Throm o está carregando. Ele o põe na segurança do túnel e cuida dos seus ferimentos. Você resolve comer parte das Provisões para ajudar a recuperar as forças, e dá também uma parte para Throm, como agradecimento por ele tê-lo salvado. Ele se desculpa por ter iniciado o desabamento das rochas e lhe oferece a mão. Apesar da dor, você consegue sorrir e apertar a mão dele. Quando você finalmente se recupera, levanta-se e segue para o leste, com Throm caminhando à  sua frente.\n\n");

    provisions -= 2;
    printf("\033[1;31mVocê perdeu parte de suas PROVISÕES\n\033[0;37m");
    printf("\033[1;35m");
    printf("Suas PROVISÕES: %d", provisions);
    printf("\033[0;37m");
    enter();
    OP060();
}

//OPCAO 207

void OP207(){
    stageops = 207;
    save();
    loop = 0;

    printf("\t207 - Você tira a camisa e a rasga ao meio, depois amarra cada um dos pedaços em volta de cada pé, a fim de se proteger em certa medida do lodo corrosivo, e dispara para cruzá-lo a passos largos. No terreno fume do outro lado do lodaçal, você tenta freneticamente, com a espada, arrancar a camisa que queima em seus pés. Porém, parte do lodo penetrou até seu tornozelo. \033[1;31mVocê perde 3 pontos de ENERGIA\033[0;37m. Partindo para o norte de novo, você chega a uma encruzilhada. Se quiser ir para o oeste, \033[1;35mdigite 386.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 218.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    energy -= 3;
    printf("Você perdeu 3 de ENERGIA\n");
    printf("\n\nSua ENERGIA: %i\n\n", energy);
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 386:
                loop++;
                system("cls");
                OP386();
                break;
            case 218:
                loop++;
                system("cls");
                OP218();
                break;
            case 0:
                inventory();
                enter();
                OP207();
                break;
        }
    }


}

//OPCAO 208

void OP208(){
    loop = 0;

    printf("\t208 - A porta abre para o aposento; você toma distância e salta sobre o poço. Coloca a corda na mochila e salta de volta por sobre o poço para sair do aposento e prosseguir para o norte.");
    printf("A Corda foi adicionada ao seu inventário.");
    rope += 1;
    enter();
    OP326();
}

//OPCAO 209

void OP209(){
    loop = 0;

    printf("\t209 - Você fica desolado ao descobrir que não apenas todas as suas Provisões restantes estão encharcadas e imprestáveis para comer, mas também que um dos seus tesouros desapareceu. Jogue fora um item da sua Lista de Equipamentos ou uma de suas jóias ou poções. Você guarda cuidadosamente na mochila as posses que lhe restam e parte para o norte outra vez.\n\n");
    //vá para 356
    provisions = 0;
    printf("Escolha o item que você quer despejar:");
    printf("\n\nINVENTÁRIO:\n");
    
    printf("\n\nPOÇÕES:\n");
    if(energy_potion == 0 && luck_potion == 0 && hability_potion == 0 && morph_potion == 0)
        printf("\n\033[1;31mVocê não possui POÇÕES\033[0;37m");
    if(luck_potion != 0)
        printf("\nPoção de fortuna: x%d, se deseja jogar fora este poção digite \033[1;33m\"1\"\033[0;37m", luck_potion);
    if(energy_potion != 0)
        printf("\nPoção de força: x%d, se deseja jogar fora este poção digite \033[1;33m\"2\"\033[0;37m", energy_potion);
    if(hability_potion != 0)
        printf("\nPoção de habilidade: x%d, se deseja jogar fora esta poção digite \033[1;33m\"3\"\033[0;37m", hability_potion);
    if(morph_potion != 0)
        printf("\nPoção de Réplica: x%d, se deseja jogar fora este item digite \033[1;33m\"4\"\033[0;37m", morph_potion);

    printf("\n\nITENS COLETADOS:\n");
    if(iron_hook == 0 && iron_key == 0 && wood_tube == 0 && rope == 0 && metal_bell == 0 && chalice == 0 && leather_wristband == 0 && high_temperature_potion == 0)
        printf("\n\033[1;31mVoce não possui ITENS\033[0;37m");
    if(iron_hook != 0)
        printf("\nGancho de Ferro: x%d, se deseja jogar fora este item digite \033[1;33m\"5\"\033[0;37m", iron_hook);
    if(iron_key != 0)
        printf("\nChave de Ferro: x%d, se deseja jogar fora este item digite \033[1;33m\"6\"\033[0;37m", iron_key);
    if(wood_tube != 0)
        printf("\nTubo oco de Madeira: x%d, se deseja jogar fora este item digite \033[1;33m\"7\"\033[0;37m", wood_tube);
    if(rope != 0)
        printf("\nRolo de Corda: x%d, se deseja jogar fora este item digite \033[1;33m\"8\"\033[0;37m", rope);
    if(metal_bell != 0)
        printf("\nSino de Metal: x%d, se deseja jogar fora este item digite \033[1;33m\"9\"\033[0;37m", metal_bell);
    if(chalice != 0)
        printf("\nCálice: x%d, se deseja jogar fora este item digite \033[1;33m\"10\"\033[0;37m", chalice);

    printf("\n\nJOIAS COLETADAS:\n");
    if(emerald == 0 && jewel == 0 && sapphire == 0 && diamond == 0 && ruby == 0 && topaz == 0)
        printf("\n\033[1;31mVocê não possui JOIAS\033[0;37m");
    if(emerald != 0)
        printf("\nEsmeralda: x%d, se deseja jogar fora esta joia digite \033[1;33m\"11\"\033[0;37m", emerald);
    if(diamond != 0)
        printf("\nDiamante: x%d, se deseja jogar fora esta joia digite \033[1;33m\"12\"\033[0;37m", diamond);
    if(ruby != 0)
        printf("\nRubi: x%d, se deseja jogar fora esta joia digite \033[1;33m\"13\"\033[0;37m", ruby);
    if(topaz != 0)
        printf("\nTopazio: x%d, se deseja jogar fora esta joia digite \033[1;33m\"14\"\033[0;37m", topaz);
    if(sapphire != 0)
        printf("\nSafira: %d, se deseja jogar fora esta joia digite \033[1;33m\"15\"\033[0;37m", sapphire);
    if(jewel != 0)
        printf("\nJoia: x%d, se deseja jogar fora esta joia digite \033[1;33m\"16\"\033[0;37m", jewel);
    
    printf("\n\n");
    while(loop < 1){
        scanf("%d", &invuse);
        switch (invuse)
        {
        case 1:
            luck_potion -= 1;
            loop++;
            break;
        case 2:
            energy_potion -= 1;
            loop++;
            break;
        case 3:
            hability_potion -= 1;
            loop++;
            break;
        case 4:
            morph_potion -= 1;
            loop++;
            break;
        case 5:
            iron_hook -= 1;
            loop++;
            break;
        case 6:
            iron_key -= 1;
            loop++;
            break;
        case 7:
            wood_tube -= 1;
            loop++;
            break;
        case 8:
            rope -= 1;
            loop++;
            break;
        case 9:
            metal_bell -= 1;
            loop++;
            break;
        case 10:
            chalice -= 1;
            loop++;
            break;
        case 11:
            emerald -= 1;
            loop++;
            break;
        case 12:
            diamond -= 1;
            loop++;
            break;
        case 13:
            ruby -= 1;
            loop++;
            break;
        case 14:
            topaz -= 1;
            loop++;
            break;
        case 15:
            sapphire -= 1;
            loop++;
            break;
        case 16:
            jewel -= 1 ;
            loop++;
            break;
        }
    }
    printf("\n\033[1;31mVocê jogou fora o item/joia selecionado\033[0;37m");
    enter();
    OP356();
}

//OPCAO 210

void OP210(){
    stageops = 210;
    save();
    loop = 0;

    printf("\t210 - Você entra em um aposento no qual há um homem maltrapilho, de pé, acorrentado, à  parede pelo braço esquerdo. Vendo que ele não tema mão direita, você se dá conta de que a mão pregada na porta deve ser dele. Implorando piedade, ele se encolhe para longe de você, tanto quanto as correntes permitem.\n\nSe você quiser libertá-lo das cadeias, \033[1;35mdigite 27.\033[0;37m\nSe preferir sair do aposento e se dirigir para o norte, \033[1;35mdigite 78.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 27:
                loop++;
                system("cls");
                OP027();
                break;
            case 78:
                loop++;
                system("cls");
                OP078();
                break;
            case 0:
                inventory();
                enter();
                OP210();
                break;
        }
    }

}

//OPCAO 211

void OP211(){
    loop = 0;
    monsenergy = 9;
    monshability = 9;

    printf("\t211 - Você consegue se livrar do aperto de Erva e desembainha a espada. Apanhando um banco quebrado para lhe servir de arma, ela avança na sua direção.\n\n\033[0;31mERVA HABILIDADE 9 ENERGIA 9\033[0;37m\n\n");
    enter();
    combat1();
    printf("\nVOCê DERROTOU A \"ERVA\"");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP201;
}

//OPCAO 212

void OP212(){
    printf("\t212 - Segurando a corda firmemente, você toma distância para o salto. Contudo, sob a luz fraca, você não nota que alguém enfraqueceu a corda, a ponto de parti-la em duas, logo acima do local em que você está segurando. Quando se lança por sobre o poço, a corda rompe e você grita de medo ao despencar de cabeça nas profundezas.");
    enter();
    OP285();
}

//OPCAO 213

void OP213(){
    stageops = 213;
    save();
    loop = 0;

    printf("\t213 - O túnel logo se divide em dois. Você ouve um zumbido que vem do ramo da direita. Se quiser caminhar para o oeste para investigar quem ou o que está fazendo o ruído, \033[1;35mdigite 108.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 14.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 108:
                loop++;
                system("cls");
                OP108();
                break;
            case 14:
                loop++;
                system("cls");
                OP014();
                break;
            case 0:
                inventory();
                enter();
                OP213();
                break;
        }
    }
}

//OPCAO 214

void OP214(){
    stageops = 214;
    save();
    loop = 0;

    printf("\t214 - Caminhando em frente, você vê uma linha vermelha pintada no chão do túnel e nota um aviso na parede que diz: \"Armas não são permitidas a partir deste ponto.\" \nSe você quiser abandonar suas armas antes de continuar para o norte, \033[1;35mdigite 389.\033[0;37m\nSe preferir ignorar o aviso e prosseguir para o norte, \033[1;35mdigite 181.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 389:
                loop++;
                system("cls");
                OP389();
                break;
            case 181:
                loop++;
                system("cls");
                OP181();
                break;
            case 0:
                inventory();
                enter();
                OP214();
                break;
        }
    }
}

//OPCAO 215

void OP215(){
    printf("\t215 - Sua espada arrebenta facilmente a fina casca externa da gigantesca bola de esporos. Uma espessa nuvem de esporos saída da bola se espalha e o envolve. Alguns dos esporos grudamse à  sua pele, que começa a coçar terrivelmente. Aparecem grandes caroços no seu rosto e braços, e sua pele parece estar em fogo. \033[1;31mVocê perde 2 pontos de ENERGIA.\033[0;37m Coçando freneticamente os caroços, você passa por cima da bola de esporos, agora murcha, e segue para o oeste.\n\n");

    energy -= 2;
    printf("\033[1;31mVocê perdeu dois de ENERGIA");
    printf("\nSua ENERGIA: %i\033[0;37m", energy);
    enter();
    OP013();
}

//OPCAO 216

void OP216(){
    stageops = 216;
    save();
    loop = 0;

    printf("\t216 - Reconhecendo a cabeça de serpentes da Medusa, você fecha os olhos para evitar o olhar mortal da criatura que o transformaria em pedra.\nSe você quiser entrar na gaiola com os olhos fechados para enfrentá-la com sua espada, \033[1;35mdigite 308.\033[0;37m\nSe preferir recuar para sair do aposento com os olhos fechados e continuar para o norte, \033[1;35mdigite 316.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 308:
                loop++;
                system("cls");
                OP308();
                break;
            case 316:
                loop++;
                system("cls");
                OP316();
                break;
            case 0:
                inventory();
                enter();
                OP216();
                break;
        }
    }
}

//OPCAO 217

void OP217(){
    printf("\t217 - A passagem começa a subir lentamente, conduzindo-o sempre para o norte. Você não passa por uma única encruzilhada. Não há portas ou mesmo uma alcova para ser investigada, e você vai ficando mais relaxado enquanto segue adiante. Depois de certo tempo, você se torna tão temerário que não repara em um fino arame estendido bem baixo de lado a lado da passagem. Somente quando o seu pé o toca, e você ouve um ronco distante, é que se dá conta do erro que cometeu. O ronco cresce até um nível ensurdecedor, e subitamente surge da penumbra do túnel à  sua frente um gigantesco rochedo que vem rolando na sua direção, ganhando velocidade a cada segundo. \033[1;31mLargando o escudo, se tiver um (você perde 1 ponto de HABILIDADE)\033[0;37m, você se volta para fugir do rochedo que se aproxima.\n\n");

    hability -= 1;
    printf("Você perdeu 1 de HABILIDADE");
    printf("\nSua HABILIDADE: %i", hability);
    if(shield != 0){
        shield = 0;
        printf("\033[1;34m");
        printf("Você perdeu seu Escudo");
        printf("\033[0;37m");
    }
    enter();
    OP036();
}

//OPCAO 218

void OP218(){
    stageops = 218;
    save();
    loop = 0;

    printf("\t218 - Você logo chega a uma porta dupla na parede da esquerda. Apura os ouvidos, mas não percebe nada. Tenta a maçaneta, ela gira, você abre uma fresta na porta da esquerda e dá uma espiada. Um guerreiro armado jaz de bruços no chão de um aposento vazio, de paredes lisas e teto baixo. Ele deve estar morto, pois permanece inerte mesmo quando você grita por ele. Uma jóia grande, talvez um diamante, está caída logo adiante do braço esticado.\nSe você quiser entrar no aposento e pegar a jóia, \033[1;35mdigite 65.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 252.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 65:
                loop++;
                system("cls");
                OP065();
                break;
            case 252:
                loop++;
                system("cls");
                OP252();
                break;
            case 0:
                inventory();
                enter();
                OP218();
                break;
        }
    }
}

//OPCAO 219

void OP219(){
    printf("\t219 - A dor nos pulmões força-o a subir à  tona para respirar. Infelizmente, um dos Trogloditas o vê e grita pelos companheiros. Indefeso, você vê os arqueiros fazerem pontaria, e uma saraivada de flechas cai sobre você com impacto fatal. \033[1;31mSeu corpo sem vida desce o rio boiando, penetrando nas profundezas ocultas da montanha.\033[0;37m");\
    death();
}

//OPCAO 220

void OP220(){
    stageops = 220;
    save();
    loop = 0;

    printf("\t220 - Um \"bong\" sombrio soa como um toque de sino fúnebre. Tudo vibra à  sua volta, e você aperta os dentes quando sua cabeça também estremece. Todo seu corpo está tremendo, e você cai. Você tirita e tem calafrios, contorcendo-se convulsivamente no chão, à  medida que as vibrações se intensificam. Procura desesperadamente uma maneira de parar o sino. Você:\n\nGritará o mais alto possível? \033[1;35mDigite 61.\033[0;37m\nTentará abafar o sino com sua bota? \033[1;35mDigite 346.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 61:
                loop++;
                system("cls");
                OP061();
                break;
            case 346:
                loop++;
                system("cls");
                OP346();
                break;
            case 0:
                inventory();
                enter();
                OP220();
                break;
        }
    }
}

//OPCAO 221

void OP221(){
    stageops = 221;
    save();
    loop = 0;

    printf("\t221 - O túnel conduz a uma caverna úmida de teto alto, como chão coberto de rochas. Estalactites em forma de dentes pendem ameaçadoramente, os pingos constantes criando poças leitosas no chão. O túnel prossegue atravessando a passagem em arco, a qual é talhada na forma de uma boca demoníaca.\nSe você quiser examinara caverna, \033[1;35mdigite 374.\033[0;37m\nSe preferir prosseguir direto pela passagem em arco, \033[1;35mdigite 60.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 374:
                loop++;
                system("cls");
                OP374();
                break;
            case 60:
                loop++;
                system("cls");
                OP060();
                break;
            case 0:
                inventory();
                enter();
                OP221();
                break;
        }
    }
}

//OPCAO 222

void OP222(){
    stageops = 222;
    save();
    loop = 0;

    printf("\t222 - Você reconhece a fera - é um MANTÉCORA. Levando a sério a advertência do poema, você fica atento para a cauda dele, de cuja ponta sai uma profusão de espinhos afiados, grossos e duros como dardos de ferro. Se você tiver um escudo, \033[1;35mdigite 196.\033[0;37m\nSe não estiver carregando um escudo, \033[1;35mdigite 6.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 196:
                loop++;
                system("cls");
                OP196();
                break;
            case 6:
                loop++;
                system("cls");
                OP006();
                break;
            case 0:
                inventory();
                enter();
                OP222();
                break;
        }
    }
}

//OPCAO 223

void OP223(){
    loop = 0;

    printf("\t223 - Você pisa com confiança no primeiro poste e avança para o próximo. Ao tocar o terceiro poste, ele imediatamente solta uma chuva de farpas afiadas, cada uma com vários centímetros de comprimento. \033[1;31mVocê perde 2 pontos de SORTE\033[0;37m. As farpas voam em todas as direções a grande velocidade, e você não consegue evitá-las. \033[1;33mDigite \"ROLL\" para saber o número de farpas que lhe penetram a pele.\033[1;31m Cada uma delas reduz sua ENERGIA em 1 ponto.\033[0;37m\n\n");

    luck -= 2;

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            energy -= numroll;
            if(energy > 0){
                printf("\n\nSe você ainda estiver vivo, consegue arrastar-se por sobre os postes restantes e se senta para a dolorosa tarefa de retirar as farpas do corpo. Depois de descansar um pouco, você segue para o leste.");
                enter();
                OP313();
            }else if(energy <= 0){
                death();
            }
        }
    }
}

//OPCAO 224

void OP224(){
    loop = 0;

    printf("\t224 - Parece não haver como continuar para o norte. Você dá meia-volta e retorna pelo túnel, passando pela cadeira de madeira. Logo chega à  encruzilhada e vira à  direita para seguir para o oeste.");

    enter();
    OP043();

}

//OPCAO 225

void OP225(){
    loop = 0;

    printf("\t225 - Você reage prontamente e, com um golpe de espada, consegue cortar a língua estendida da Besta Sangrenta. A fera urra de dor e se atira para frente, tentando prendê-lo nas mandíbulas ensangà¼entadas. Esta será uma luta até a morte.\n\n\033[1;31mBESTA SANGRENTA HABILIDADE 12 ENERGIA 10.\033[0;37m\n\nQuando vencer a sua primeira Série de Ataque, \033[1;33mteste sua SORTE.\033[0;37m");

    monshability = 12;
    monsenergy = 10;
    enter();

    printf("COMEÇOU O COMBATE!");
    combatloop = 0;
    while(combatloop < 1){
        loop = 0;
        printf("\nRode os dados:\n");
        printf("\033[0;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        gets(combatroll);
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
            printf("\nVocê deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
            while(loop < 1){
                gets(luckhit);
                if(strcasecmp(luckhit, "sim") == 0){
                    dice2();
                    if(numroll <= luck){
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        monsenergy -= 2;
                        combatloop += 1;
                        loop++;
                        enter();
                        OP097();
                    }
                    else{
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        monsenergy += 1;
                        combatloop += 1;
                        loop++;
                        enter();
                        OP021();
                    }
                    printf("\n\n");
                }
                else if(strcasecmp(luckhit, "nao") == 0){
                    printf("\033[1;31mVOCE PRECISA TESTAR SUA SORTE\033[0;37m");
                }
            }
            printf("HP MONSTRO: %d", monsenergy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
            printf("\nVOCE LEVOU DANO\n");
            printf("\nVocê deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
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

//OPCAO 226

void OP226(){
    stageops = 226;
    save();
    loop = 0;

    printf("\t226 - A carne contém ervas que lhe aumentarão a força. \033[1;31mSome 3 pontos seu índice de ENERGIA.\033[0;37m\n\nVocê pode caminhar até a alcova, se ainda não o fez, \033[1;35mdigite 41.\033[0;37m\n\nOu sair da câmara e continuar para o oeste, \033[1;35mdigite 83.\033[0;37m\n\n");

    if(status_OP226 == 0){
        status_OP226 += 1;
        energy += 3;
        printf("Você ganhou 3 de ENERGIA");
        printf("\nSua ENERGIA: %i\n\n", energy);
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 83:
                    loop++;
                    system("cls");
                    OP083();
                    break;
                case 316:
                    loop++;
                    system("cls");
                    OP316();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP226();
                    break;
            }
        }
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        printf("\nSua ENERGIA: %i\n\n", energy);
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 83:
                    loop++;
                    system("cls");
                    OP083();
                    break;
                case 316:
                    loop++;
                    system("cls");
                    OP316();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP226();
                    break;
            }
        }
    }
}

//OPCAO 227

void OP227(){
    printf("\t227 - Ainda sorrindo, o velho olha para você. \033[1;31m\"Errado\"\033[0;37m, ele diz em voz baixa.");

    enter();
    OP085();
}

//OPCAO 228

void OP228(){
    loop = 0;

    printf("\t228 - Você enfia o braço no buraco e sente seu sangue gelar quando uma coisa quente e pegajosa se enrosca nele. Você consegue tirar o braço de dentro do buraco, mas um horrendo tentáculo, com ventosas incrivelmente fortes, está pendurado nele. Quando você consegue se libertar, cortando o tentáculo, seu braço dói e lateja. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP150();
            }else{
		    luck--;
                system("cls");
                OP033();
            }
        }
    }

}

//OPCAO 229

void OP229(){
    printf("\t229 - Logo que sua cabeça entra embaixo da luz azul, você ouve o som de vozes abafadas. Os rostos já não riem, e as expressões são agora máscaras de desespero e angústia. O rosto triste de uma menina paira à  sua frente, ela começa a sussurrar um poema. Em transe, você ouve atentamente, acreditando que ela tem uma mensagem especial para você, enquanto ela recita:\033[1;35m\"Quando o corredor a água encontrar, Não se apresse em recuar. Mergulhe depois dos pulmões encher, Se sua Prova espera vencer.\"\033[0;37m Guardando de cor o poema da garota-espírito, você atravessa o raio de luz e se dirige rapidamente para o norte.\n\n");

    if(status_OP229 == 0){
        knowledge_deadgirl_poem += 1;
        status_OP229 +=1;
        printf("\033[1;34mVocê adquiriu o conhecimento do poema da garota morta\033[0;37m");
        enter();
        OP107();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP107();
    }
}

//OPCAO 230

void OP230(){
    stageops = 230;
    save();
    loop = 0;

    printf("\t230 - O túnel começa a se alargar e abre para uma imensa caverna, de onde você pode ouvir o som de muitas vozes agudas. Você se aproxima silenciosamente da entrada e espia. Cerca de 20 minúsculos seres, com narizes e orelhas compridos, correm em círculo em volta de uma grande efígie de ouro. Você:\n\nAndará até eles para conversar? Digite 85.\nTentará se esgueirar e passar por eles? \033[1;35mDigite 5.\033[0;37m\nBeberá a Poção da Réplica (se você a tiver)? \033[1;35mDigite 385.\033[0;37m");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 85:
                loop++;
                system("cls");
                OP085();
                break;
            case 5:
                loop++;
                system("cls");
                OP005();
                break;
            case 222:
                loop++;
                if(morph_potion != 0){
                    system("cls");
                    OP385();
                } else{
                    printf("Você não possui este item.");
                    enter();
                    OP134();
                }
                break;
            case 0:
                inventory();
                enter();
                OP230();
                break;
        }
    }
}

//OPCAO 231

void OP231(){
    printf("\t231 - Você encontra uma poça atrás dos Hobglobins mortos e toma grandes goles de água fresca o mais rápido possível. Isso neutraliza o ácido e, lentamente, você começa a se recuperar. Ainda com dor, você se levanta e parte para o norte.");

    enter();
    OP110();
}

//OPCAO 232

void OP232(){
    stageops = 232;
    save();
    loop = 0;

    printf("\t232 - Se você estiver desarmado, \033[1;35mdigite 286.\033[0;37m\nSe ainda estiver com suas armas, \033[1;35mdigite 320.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 320:
                loop++;
                system("cls");
                OP320();
                break;
            case 286:
                loop++;
                if(disarmed != 0){
                    system("cls");
                    OP286();
                } else{
                    printf("\nVocê está armado.");
                    enter();
                    OP232();
                }
                break;
            case 0:
                inventory();
                enter();
                OP232();
                break;
        }
    }
}

// OPÇÃO 233
void OP233(){
    printf("\t233 - Você parte um pedaço grande do cogumelo e o mastiga ansiosamente. De imediato, seu estômago incha, e você pode mesmo vê-lo estufando por baixo do cinto. Todo o seu corpo começa a se expandir, rasgando-lhe ruidosamente as roupas. Você fica cada vez maior, e logo seu rosto está imprensado de encontro ao teto. Os cogumelos que você comeu são muito procurados por mágicos para as poções de crescimento, mas para você eles significam a morte. Você está grande demais para poder algum dia sair da adega. \033[1;31mSua aventura termina aqui.\033[0;37m");
    death();
}

// OPÇÃO 234
void OP234(){
    stageops = 234;
    save();
    loop = 0;

    printf("\t234 - Um pouco mais adiante, você chega a uma parte do túnel coberta de lodo verde e espesso. Parece ameaçador, por isso você resolve testá-lo primeiro com um pedaço de pano. A pasta corrosiva do lodo queima o pano instantaneamente, não deixando nem sinal dele.\n\nSe você estiver carregando um par de pernas-de-pau, \033[1;35mdigite 183.\033[0;37m\nSe não as tiver, \033[1;35mdigite 207.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 207:
                loop++;
                system("cls");
                OP207();
                break;
            case 183:
                loop++;
                if(wooden_legs != 0){
                    system("cls");
                    OP183();
                } else{
                    printf("Você não tem este item.");
                    enter();
                    OP234();
                }
                break;
            case 0:
                inventory();
                enter();
                OP234();
                break;
        }
    }

}

//OPCAO 235
void OP235(){
    printf("\t235 - Você não tem tempo para reagir antes que o dardo se crave na sua coxa. \033[1;31mVocê perde 2 pontos de ENERGIA.\033[0;37m");

    energy -= 2;
    printf("\n\nSua ENERGIA: %i", energy);
    if(energy <= 0){
        death();
    } else
    printf("Você sobreviveu ao Dardo");
    enter();
    OP073();
}

//OPCAO 236
void OP236(){
    loop = 0;
    monsenergy = 8;
    monshability = 9;
    
    printf("\t236 - O punho recua e prepara um novo ataque. Com a mão livre, você puxa a espada e tenta cortar a maçaneta da porta. Embora não o reconheça, você está sendo atacado pela forma fluida de um IMITADOR.\n\n\033[1;31mIMITADOR HABILIDADE 9 ENERGIA 8\033[0;37m\n\n");

    enter();
    printf("COMEÇOU O COMBATE!");
    combatloop = 0;
    while(combatloop < 1){
        loop = 0;
        printf("\nRode os dados:\n");
        printf("\033[0;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        gets(combatroll);
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
            printf("AGORA É SUA HORA DE BATER EM RETIRADA!");
            enter();
            OP314();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
            printf("\nVOCE LEVOU DANO\n");
            printf("\nVocê deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
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

//OPCAO 237
void OP237(){
    stageops = 237;
    save();
    loop = 0;

    printf("\t237 - O túnel faz uma curva súbita para a esquerda e continua para o norte até onde a vista alcança. Você logo chega a uma porta de madeira, fechada, na parede do lado esquerdo.\n\nSe você quiser abrir a porta, \033[1;35mdigite 12.\033[0;37m\nSe preferir continuar seguindo para o norte, \033[1;35mdigite 100.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 12:
                loop++;
                system("cls");
                OP012();
                break;
            case 100:
                loop++;
                system("cls");
                OP100();
                break;
            case 0:
                inventory();
                enter();
                OP237();
                break;
        }
    }
}

//OPCAO 238
void OP238(){
    loop = 0;

    printf("\t238 - Ao cair, você consegue agarrar a corda com as mãos. Lentamente, você se iça até o outro lado e sobe para o piso. Você retira o elmo do poste e o põe na cabeça. O elmo foi feito por um ferreiro altamente habilidoso.\033[1;32m Some 1 ponto de HABILIDADE\033[0;37m. Não querendo se arriscar a caminhar de volta pela corda bamba, você resolve engatinhar por ela. De volta ao terreno firme, em segurança, você atravessa a passagem em arco para seguir pelo túnel na direção norte.\n\n");

    hability =+ 1;
    printf("Você ganhou 1 de HABILIDADE");
    printf("\nSua HABILIDADE: %i", hability);
    enter();
    OP291();
}

//OPCAO 239
void OP239(){
    stageops = 239;
    save();
    loop = 0;

    printf("\t239 - Não muito adiante, o túnel chega a uma porta fechada à  sua esquerda. Colocando o ouvido na porta, você escuta, mas não ouve nada. Se você quiser abrir a porta, \033[1;35mdigite 102.\033[0;37m\nSe desejar prosseguir para o norte, \033[1;35mdigite 344.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 102:
                loop++;
                system("cls");
                OP102();
                break;
            case 344:
                loop++;
                system("cls");
                OP344();
                break;
            case 0:
                inventory();
                enter();
                OP239();
                break;
        }
    }


}

//OPCAO 240
void OP240(){
    stageops = 240;
    save();
    loop = 0;

    printf("\t240 - Você olha para baixo e vê esparramados no chão os corpos inertes dos Guardiães Voadores. Você começa a forçar o olho esquerdo de esmeralda do ídolo com a ponta da espada. Finalmente, ele se solta e cai na sua mão; o peso da pedra o deixa surpreso. Esperando que seja de utilidade mais tarde, você a guarda na mochila. Se quiser agora forçar o olho direito, \033[1;35mdigite 34.\033[0;37m\nSe preferir descer do ídolo, \033[1;35mdigite 89.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    if(status_OP240 >= 0 && status_OP240 <= 3){
        emerald += 1;
        status_OP240 += 1;
        printf("\033[1;34m");
        printf("Uma Esmeralda foi adicionada a seu inventário\n");
        printf("\033[0;37m");
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 34:
                    loop++;
                    system("cls");
                    OP034();
                    break;
                case 89:
                    loop++;
                    system("cls");
                    OP089();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP240();
                    break;
            }
        }
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 34:
                    loop++;
                    system("cls");
                    OP034();
                    break;
                case 89:
                    loop++;
                    system("cls");
                    OP089();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP240();
                    break;
            }
        }
    }
}

//OPCAO 241
void OP241(){
    stageops = 241;
    save();
    loop = 0;

    printf("\t241 - Uma cortina de veludo marrom fecha uma passagem em arco na parede oriental do túnel. Se você quiser descerrar a cortina e atravessar a passagem em arco, \033[0;35mdigite 393.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 291.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 393:
                loop++;
                system("cls");
                OP393();
                break;
            case 291:
                loop++;
                system("cls");
                OP291();
                break;
            case 0:
                inventory();
                enter();
                OP241();
                break;
        }
    }
}

//OPCAO 242
void OP242(){
    loop = 0;

    printf("\t242 - Você sacode a cabeça, tentando desesperadamente manter a consciência, mas o calor é intenso demais, e você perde os sentidos. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP048();
            }else{
                system("cls");
                OP366();
            }
        }
    }

}

//OPCAO 243
void OP243(){
    printf("\t243 - Cobrindo o nariz e a boca com a mão, a fim de evitar inalar o gás, você segue o Gnomo pela porta aberta. Você entra em outro túnel, ao fim do qual aparece a visão bem vinda da luz do dia. Para sua grande surpresa, o Gnomo está morto no meio do caminho com um dardo de besta cravado na cabeça. Na ânsia por liberdade, o Gnomo caíra vítima da última armadilha do Barão Sukumvit. \033[1;33mVocê passa pelo infeliz e sai na luz brilhante do sol.\033[0;37m");
    enter();
    OP400();
}

//OPCAO 244
void OP244(){
    printf("\t244 - Ele pega sua Peça de Ouro e lhe diz que, em um túnel setentrional, há uma cadeira de madeira esculpida na forma de um pássaro demoníaco. No braço da cadeira, um painel secreto contém uma poção em um frasco de vidro. \033[1;35m\"é uma Poção de Réplica, se eu bem me lembro. Boa sorte. Espero que nos encontremos de novo fora destes túneis infernais.\"\033[0;37m O homem sai arrastando os pés, e você continua sua jornada.\n\n");

    if(status_OP244 == 0){
        gold -= 1;
        morph_potion += 1;
        status_OP244 += 1;
        printf("Você perdeu 1 de GOLD");
        printf("\nSeu GOLD: %d", gold);
        printf("Poção de Réplica foi adicionada ao seu inventário");
        enter();
        OP109();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP109();
    }
}

//OPCAO 245
void OP245(){
    loop = 0;
    monsenergy = 15;
    monshability = 12;

    printf("\t245 - Você não tem outra alternativa senão abrir a porta, já que o muro é liso demais para ser escalado. Respirando fundo, você gira a maçaneta e entra em um poço coberto de areia. Ali, um monstro enorme com aparência de dinossauro, chegando a uns 10 metros de altura, está de pé nas imensas patas traseiras, diante de grandes portas duplas na parede do outro lado. Possui um couro grosso verde malhado e uma boca com filas de dentes afiados como navalhas. As mandíbulas da criatura se abrem e fecham com força capaz de pulverizar ossos. E mesmo você não consegue evitar o tremor ao se aproximar do Diabo do Poço com a espada na mão.\n\n\033[1;31mDIABO DO POÇO HABILIDADE 12 ENERGIA 15.\033[0;37m");

    enter();
    combat1();
    printf("\n\033[1;33mVOCê DERROTOU O DIABO DO POÇO\033[0;37m");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP258();
}

//OPCAO 246
void OP246(){
    loop = 0;
    printf("\t246 - Apesar de toda a cautela, sua perna raspa em um dos postes, que imediatamente solta uma chuva de farpas afiadas, cada uma com vários centímetros de comprimento. Você perde 2 pontos de SORTE. Elas voam em todas as direções com grande velocidade, e você não consegue evitá-las. \033[1;33mDigite \"ROLL\" e role 2 dados para determinar o número de farpas que se cravam na sua carne.\033[0;37m \033[1;31mCada farpa reduz sua ENERGIA em 1 ponto.\033[0;37m\n\n");

    luck -= 2;
    printf("Você perdeu 2 de SORTE\n");
    printf("Sua SORTE: %i\n\n", luck);

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            energy -= numroll;
            printf("\nVOCê RECEBEU %i DE DANO", numroll);
            if(energy > 0){
                loop++;
                printf("\n\nvocê senta para a dolorosa tarefa de retirar as farpas do corpo antes de partir para o leste.");
                enter();
                OP313();
            }else if(energy <= 0)
                death();
        }
    }
}

//OPCAO 247
void OP247(){
    loop = 0;

    printf("\t247 - A fera diante de você é o temível MANTÉCORA. A ponta da cauda da criatura guarda uma profusão de espinhos pontudos, grossos e duros como dardos de ferro. Subitamente, ele sacode a cauda, lançando uma saraivada de espinhos na sua direção.  Se você ainda estiver vivo, avança com dificuldade para atacar o Mantécora com sua espada, antes que ele tenha tempo de disparar mais espinhos.\n\n\033[1;31mMANTÉCORA HABILIDADE 11 ENERGIA 11\033[0;37m\n\n");

    dice1();
    dards = numroll * 2;
    energy -= dards;
    printf("Você perdeu %d de ENERGIA\n\n", dards);
    if(energy <= 0){
        death();
    }else
    printf("\nVocê sobreviveu a rajada de espinhos!");
    enter();
    combat1();
    printf("\nVOCê DERRROTOU A MANTÉCORA!");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP364();
}

//OPCAO 248
void OP248(){
    printf("\t248 - As portas abrem para um túnel que segue para o norte. Você fecha as portas atrás de si e parte mais uma vez.");

    enter();
    OP214();
}

//OPCAO 249
void OP249(){
    stageops = 249;
    save();
    loop = 0;

    printf("\t249 - Você só tem tempo de ouvir o Gnomo dizer: \"Uma coroa e dois crânios\", antes que um raio branco de energia parta da fechadura e atinja-lhe o peito, derrubando-o sem sentidos. \033[1;33mDigite \"ROLL\", \033[1;31mo resultado somado 1 é reduzido de sua ENERGIA.\033[0;37m");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice1();
            if(numroll > 0){
                energy = energy - (numroll + 1);
                printf("Sua ENERGIA: %i", energy);
            }
            if(energy > 0){
                printf("\n\nVocê recupera a consciência e o Gnomo manda que tente de novo. Você sabe que colocou uma gema na ranhura certa, mas qual? Você suspira e tenta uma nova combinação.\n\n    A         B         C     \nEsmeralda|Diamante |Safira    -> \033[1;35mDigite 16.\033[0;37m\nDiamante |Safira   |Esmeralda -> \033[1;35mDigite 392.\033[0;37m\nSafira   |Esmeralda|Diamante  -> \033[1;35mDigite 177.\033[0;37m\nEsmeralda|Safira   |Diamante  -> \033[1;35mDigite 287.\033[0;37m\nDiamante |Esmeralda|Safira    -> \033[1;35mDigite 132.\033[0;37m\nSafira   |Diamante |Esmeralda -> \033[1;35mDigite 249.\033[0;37m\n\n");

                printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

                scanf("%i", &choices);
                switch(choices){
                    case 16:
                        loop++;
                        system("cls");
                        OP016();
                        break;
                    case 392:
                        loop++;
                        system("cls");
                        OP392();
                        break;
                    case 177:
                        loop++;
                        system("cls");
                        OP177();
                        break;
                    case 287:
                        loop++;
                        system("cls");
                        OP287();
                        break;
                    case 132:
                        loop++;
                        system("cls");
                        OP132();
                        break;
                    case 249:
                        loop++;
                        system("cls");
                        OP249();
                        break;
                    case 0:
                        inventory();
                        enter();
                        OP132();
                        break;
                }
            }else{
                death();
            }
        }
    }
}

//OPCAO 250
void OP250(){
    stageops = 250;
    save();
    loop = 0;

    printf("\t250 - Quando você corre para a porta, o velho grita atrás de você: \"Não corra, ninguém escapa de mim. Pare, ou eu o transformarei em pedra neste instante!\" Você: \n\nContinua correndo? \033[1;35mDigite 44.\033[0;37m\nVira-se para atacá-lo com a espada? \033[1;35mDigite 195.\033[0;37m\nDiz a ele que responderá à  pergunta? \033[1;35mDigite 382.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 44:
                loop++;
                system("cls");
                OP044();
                break;
            case 195:
                loop++;
                system("cls");
                OP195();
                break;
            case 382:
                loop++;
                system("cls");
                OP382();
                break;
            case 0:
                inventory();
                enter();
                OP250();
                break;
        }
    }
}

//OPCAO 251
void OP251(){
    printf("\t251 - Mais uma vez, ouve-se a voz misteriosa, só que agora, para sua grande surpresa, num tom bem menos ameaçador: \"Bom, meu senhor gosta daqueles que demonstram ter espírito. Tome este presente para ajudá-lo. Isto lhe concederá um desejo, mas somente um desejo. Adeus.\" Um anel de ouro, magicamente saído do nada, cai a seus pés com um tinido suave. Você o põe num dedo. A porta se abre e você entra de novo no túnel, rumo ao norte.\n\n");

    if(status_OP251 <= 0){
        status_OP251 += 1;
        printf("\033[1;34mAnel dos Desejos foi adicionado a seu inventário\033[0;37m");
        wish_ring += 1;
        enter();
        OP344();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP344();
    }
}

//OPCAO 252
void OP252(){
    printf("\t252 - O túnel continua para o norte por uma boa distância antes de chegar a um beco sem saída. A entrada de um escorrega é visível na parede do oeste, e essa parece ser a única alternativa, além da opção de retornar. Você resolve arriscar e sobe no escorrega. Desliza suavemente e aterrissa sobre as costas em um aposento.");

    enter();
    OP090();
}

//OPCAO 253
void OP253(){
    printf("\t253 - Você tira o osso da mochila e o atira escada abaixo. Os latidos ficam mais altos, transformando-se em rosnados e ranger de dentes quando o osso cai no chão. Lentamente, você desce os degraus com a espada na mão, e vê os dois enormes CÃES DE GUARDA disputando o osso. Você passa correndo por eles e segue em frente pelo túnel.");

    enter();
    OP315();
}

//OPCAO 254
void OP254(){
    printf("\t254 - Você desembainha a espada e avança lentamente na direção do imenso e viscoso Verme da Rocha.\n\nVERME DA ROCHA HABILIDADE 7 ENERGIA 11\n\nVocê poderá fugir depois de duas Séries de Ataque, correndo para o oeste pelo túnel.\n\n");

    monshability = 7;
    monsenergy = 11;

    printf("COMEÇOU O COMBATE!");
    combatloop = 0;
    atkseries = 0;
    while(combatloop < 1){
        loop = 0;
        printf("\nRode os dados:\n");
        printf("\033[0;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        gets(combatroll);
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
            atkseries = atkseries + 1;
            printf("\nVocê deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
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
            printf("HP MONSTRO: %d", monsenergy);
            }
            if(atkseries >= 2){
                loop++;
                printf("\n\n\033[1;34mA PARTIR DE AGORA VOCê PODE TENTAR FUGIR!\n\033[0;31mDIGITE FLEE\033[1;34m INVÉS DE ROLL PARA FUGIR!\033[0;37m");
            }
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
            printf("\nVOCE LEVOU DANO\n");
            printf("\nVocê deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
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
            energy -= 2;
            printf("SEU HP: %d", energy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil == damagemonster){
            printf("\nAMBOS CONSEGUIRAM SE DEFENDER E NINGUÉM SE MACHUCOU");
            enter();
        }
        else if(strcasecmp(combatroll, "flee") == 0 && atkseries == 2){
            combatloop += 1;
            printf("\nAssim que você acerta seu segundo golpe na criatura, durante um momento de distração do Verme, você corre para o oeste como qualquer covarde faria.");
            enter();
            OP117();
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

//OPCAO 255
void OP255(){
    printf("\t255 - Quando corre contornando o caminho estreito, você se sente tonto. O gás da poça está fazendo efeito: sua visão começa a ficar embaçada, e você perde o equilíbrio. Você só tem uma vaga consciência da língua da Besta Sangrenta, enquanto ela se enrosca na sua perna e o arrasta para a poça de lodo. \033[1;31mDepois de decomposto no lodo abjeto, seu corpo será saboreado pela ignóbil Besta Sangrenta.\033[0;37m");
    death();
}

//OPCAO 256
void OP256(){
    loop = 0;

    printf("\t256 - Lembrando do conselho do velho, você examina o braço da cadeira em busca de um painel secreto. Descobrindo uma fenda quase imperceptível, você a força e, súbito, um pequeno painel salta do braço. Ao perceber um pequeno frasco de vidro numa cavidade, você o apanha e lê o rótulo: \033[1;34m\"Poção de Réplica - uma dose apenas. Este líquido fará com que você assuma a forma de qualquer ser vivo que lhe esteja próximo.\"\033[0;37m Você põe a estranha poção na mochila e continua para o norte.");

    if(status_OP256 == 0){
        morph_potion += 1;
        status_OP256 += 1;
        printf("\033[1;34mA Poção de Réplica foi adicionada a seu inventário\033[0;37m");
        enter();
        OP188();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP188();
    }
}

//OPCAO 257
void OP257(){
    printf("\t257 - Dentro dos bolsos de um dos Orcas, você acha uma Peça de Ouro e um tubo oco de madeira. Você guarda na mochila o que encontrou e parte para o oeste.\n\n");

    if(status_OP257 >= 0 && status_OP257 <= 3){
        wood_tube += 1;
        gold += 1;
        status_OP257 += 1;
        printf("\033[1;34mUm tubo oco de madeira foi adicionado a seu inventário\033[0;37m\n");
        printf("\033[1;33m1 de GOLD foi adicionado seu inventário\n");
        printf("Seu GOLD: %d\033[0;37m", gold);
        enter();
        OP164();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP164();
    }
}

//OPCAO 258
void OP258(){
    stageops = 258;
    save();
    loop = 0;

    printf("\t258 - Você está exausto e se senta para um descanso na cauda da fera morta. Olhando para baixo, a seus pés, você de repente nota um anel de ferro que se destaca na areia. Se você quiser puxar o anel, \033[1;35mdigite 95.\033[0;37m\nSe preferir sair do poço pelas portas duplas, \033[1;35mdigite 248.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 95:
                loop++;
                system("cls");
                OP095();
                break;
            case 248:
                loop++;
                system("cls");
                OP248();
                break;
            case 0:
                inventory();
                enter();
                OP258();
                break;
        }
    }

}

//OPCAO 259
void OP259(){
    stageops = 259;
    save();
    loop = 0;

    printf("\t259 - Ignorando a dor, você, continua a correr. À sua frente, vê um rio subterrâneo que corre de leste para oeste atravessando a caverna, com uma ponte de madeira que liga uma margem a outra. Você olha para trás e vê os Trogloditas no seu encalço. Se você quiser correr pela ponte, \033[1;35mdigite 318.\033[0;37m\nSe desejar mergulhar no rio, \033[1;35mdigite 47.\033[0;37m");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 47:
                loop++;
                system("cls");
                OP047();
                break;
            case 318:
                loop++;
                system("cls");
                OP318();
                break;
            case 0:
                inventory();
                enter();
                OP259();
                break;
        }
    }

}

//OPCAO 260
void OP260(){
    stageops = 260;
    save();
    loop = 0;

    printf("\t260 - Você mal consegue se agarrar à  orelha do ídolo e recuperar um ponto de apoio para os pés. Você se desloca pelo rosto da estátua. Sentado no nariz do ídolo, você desembainha a espada e considera qual dos olhos dele arrancará primeiro para levar a jóia.\n\nSe quiser arrancar primeiro o olho esquerdo, \033[1;35mdigite 166.\033[0;37m\nSe preferir arrancar o olho direito, \033[1;35mdigite 140.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 166:
                loop++;
                system("cls");
                OP166();
                break;
            case 140:
                loop++;
                system("cls");
                OP140();
                break;
            case 0:
                inventory();
                enter();
                OP260();
                break;
        }
    }

}

//OPCAO 261
void OP261(){
    printf("\t261 - Apesar de todos os esforços, você não consegue tirar o Laço do pescoço do ídolo. Finalmente, você desiste e o abandona para quem quer que venha depois de você. Não há nada mais de interesse na caverna, portanto você caminha até a parede norte e entra no túnel.");
    enter();
    OP239();
}

//OPCAO 262
void OP262(){
    stageops = 262;
    save();
    loop = 0;

    printf("\t262 - A porta abre para um outro túnel que segue para o norte. Você topa com duas fontes de pedra, uma de cada lado do túnel, esculpidas na forma de querubins, de cujas bocas a água jorra e desce em cascata para pequenas conchas nos pés. Você: Beberá água na fonte da esquerda? \033[1;35mDigite 337.\033[0;37m\nBeberá água na fonte da direita? \033[1;35mDigite 173.\033[0;37m\nContinuará caminhando para o norte? \033[1;35mDigite 368.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 337:
                loop++;
                system("cls");
                OP337();
                break;
            case 173:
                loop++;
                system("cls");
                OP173();
                break;
            case 368:
                loop++;
                system("cls");
                OP368();
                break;
            case 0:
                inventory();
                enter();
                OP262();
                break;
        }
    }
}

//OPCAO 263
void OP263(){
    stageops = 263;
    save();
    loop = 0;

    printf("\t263 - A porta abre para um outro túnel. Caminhando para o oeste, você logo chega a uma porta na parede norte. Se quiser abrir a porta, \033[1;35mdigite 153.\033[0;37m\nSe preferir continuar para o oeste, \033[1;35mdigite 74.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 153:
                loop++;
                system("cls");
                OP153();
                break;
            case 74:
                loop++;
                system("cls");
                OP074();
                break;
            case 0:
                inventory();
                enter();
                OP263();
                break;
        }
    }

}

//OPCAO 264
void OP264(){
    stageops = 264;
    save();
    loop = 0;

    printf("\t264 - Adiante, na penumbra, você vê dois HOBGOBLINS se engalfinhando. Há uma bolsa de couro jogada no chão, e parece ser ela a razão da luta. Você:\n\nTentará conversar com eles? \033[1;35mDigite 130.\033[0;37m\nVai atacá-los com sua espada? \033[1;35mDigite 51.\033[0;37m\nTentará passar sem ser percebido? \033[1;35mDigite 355.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 130:
                loop++;
                system("cls");
                OP130();
                break;
            case 51:
                loop++;
                system("cls");
                OP051();
                break;
            case 355:
                loop++;
                system("cls");
                OP355();
                break;
            case 0:
                inventory();
                enter();
                OP264();
                break;
        }
    }
}

//OPCAO 265
void OP265(){
    printf("\t265 - Você esfrega seu anel mágico e deseja que o Demônio do Espelho seja transportado de volta ao próprio mundo e nunca mais retome. Ainda avançando na sua direção, o ser começa a se esvair e desaparece aos poucos. Por fim, ele some completamente, e você pode continuar sua jornada para o norte.");
    // Volte para 188.
    enter();
    OP188();
}

//OPCAO 266
void OP266(){
    loop = 0;

    printf("\t266 - Você revista os armários e caixas no quarto de Erva, mas não encontra nada, exceto um osso velho, que pode levar com você, se quiser. Saindo da câmara pela porta do leste, você agora se encontra de pé no final de um outro túnel.");

    enter();
    OP305();
}

//OPCAO 267
void OP267(){
    stageops = 267;
    save();
    loop = 0;

    printf("\t267 - O túnel logo termina em uma encruzilhada. Olhando para a esquerda e para a direita, você vê uma passagem estreita que desaparece na penumbra da distância.\n\nSe você quiser se dirigir para o oeste, \033[1;35mdigite 352.\033[0;37m\nSe preferir seguir para o leste, \033[1;35mdigite 68.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 352:
                loop++;
                system("cls");
                OP352();
                break;
            case 68:
                loop++;
                system("cls");
                OP068();
                break;
            case 0:
                inventory();
                enter();
                OP267();
                break;
        }
    }
}

//OPCAO 268
void OP268(){
    loop = 0;

    printf("\t268 - Você salta para adiante e tenta agarrar o líder para usá-lo como refém. Contudo, os Trogloditas estavam prevenidos para sua tentativa, e seis dos arqueiros deles imediatamente disparam flechas em você. A pontaria deles é mortalmente precisa, e as seis flechas atingem o alvo. Você tomba sem vida. \033[1;31mOs Trogloditas encerraram abruptamente sua jornada.\033[0;37m");
    death();
}

//OPCAO 269
void OP269(){
    stageops = 269;
    save();
    loop = 0;

    printf("\t269 - Você esvazia o conteúdo do vidro na mão e o aplica à s suas feridas. Os efeitos curativos são imediatos, e você se sente mais forte a cada momento. Acrescente 3 pontos de ENERGIA. Você poderá comer o arroz e beber a água, \033[1;35mdigite 330.\033[0;37m Ou sair do salão, levando apenas o diamante com você, \033[1;35mdigite 127\033[0;37m.");

    if(status_OP269 == 0){
        energy += 3;
        status_OP269 += 1;
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 330:
                    loop++;
                    system("cls");
                    OP330();
                    break;
                case 127:
                    loop++;
                    system("cls");
                    OP127();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP269();
                    break;
            }
        }
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 330:
                    loop++;
                    system("cls");
                    OP330();
                    break;
                case 127:
                    loop++;
                    system("cls");
                    OP127();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP269();
                    break;
            }
        }
    }
}

//OPCAO 270
void OP270(){
    loop = 0;

    printf("\t270 - A tampa da caixa sai facilmente. Dentro, você acha duas Peças de Ouro e um bilhete, escrito num pequeno pedaço de pergaminho, endereçado a você. Depois de colocar o ouro no bolso, você lê a mensagem: Muito bem. Pelo menos você tem o bom senso de parar e tirar proveito da ajuda simbólica que lhe é dada. Agora, posso avisá-lo da necessidade de encontrar e usar diversos itens, se espera sair-se bem no meu Calabouço da Morte. Assinado \"Sukumvit.\" Guardando de cor o aviso do bilhete, você o rasga em pequenos pedaços e continua para o norte pelo túnel.\n\n");

    if(status_OP270 == 0){
        gold += 2;
        status_OP270 += 1;
        printf("\033[1;33mFoi adicionado dois de GOLD ao seu inventário");
        printf("\nSeu GOLD: %d\033[0;37m", gold);
        enter();
        OP066();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP066();
    }
}

//OPCAO 271
void OP271(){
    loop = 0;

    printf("\t271 - Quando você está prestes a soltar o escudo e atirá-lo por cima do poço, ele escorrega de seus dedos e rola pelo chão. Você não consegue apanhá-lo antes que ele ultrapasse a borda, caindo ruidosamente, de lado, no fundo. A perda do escudo reduz-lhe a capacidade, \033[1;31mvocê perde 1 ponto de HABILIDADE\033[0;37m. Amaldiçoando sua própria falta de jeito, você dá um passo à  frente, salta por sobre o poço e cai em segurança do outro lado. Você não perde tempo e se dirige para o leste.");
    // Digite 237.
    hability -= 1;
    printf("Você perdeu um ponto de HABILIDADE");
    printf("\nSua HABILIDADE: %i", hability);
    enter();
    OP237();
}

//OPCAO 272
void OP272(){
    loop = 0;

    printf("\t272 - Embora a Besta Sangrenta seja pesada e estufada demais para sair da poça, a língua da fera se estica e se enrosca na sua perna. Ainda inconsciente, você é arrastado para a poça de lodo. \033[1;31mDepois de decomposto pela ação do lodo abjeto, seu corpo será saboreado pela repugnante Besta Sangrenta.\033[0;37m");
    death();
}

//OPCAO 273
void OP273(){
    stageops = 273;
    save();
    loop = 0;

    printf("\t273 - A bola de madeira se choca contra o crânio, derrubando-o do pedestal. Para sua surpresa, as bestas não disparam os dardos mortais. Você entra no aposento com cautela e apanha o crânio do chão. Reconhece as jóias amarelas dos olhos como sendo topázios, e rapidamente os arranca das órbitas. Você os coloca na mochila, imaginando se ainda há uma cilada à  sua espera no aposento. Você: Ficará de quatro e sairá engatinhando do aposento, segurando o crânio? \033[1;35mDigite 15.\033[0;37m\nRecolocará o crânio no pedestal antes de sair do aposento? \033[1;35mDigite 204.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 15:
                loop++;
                system("cls");
                OP015();
                break;
            case 204:
                loop++;
                system("cls");
                OP204();
                break;
            case 0:
                inventory();
                enter();
                OP273();
                break;
        }
    }
}

//OPCAO 274
void OP274(){
    loop = 0;

    printf("\t274 - Você pisa nervosamente na corda, sem se atrever a olhar para baixo. Na metade da travessia, você começa a entrar em pânico e perde o equilíbrio. \033[1;33mDIGITE \"ROLL\" e teste sua HABILIDADE\033[0;37m.\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP238();
            }else{
                system("cls");
                OP359();
            }
        }
    }
}

//OPCAO 275
void OP275(){
    loop = 0;

    printf("\t275 - Uma fumaça espessa sobe do chão no lugar onde o ácido caiu da moringa quebrada. Você se arrasta desesperadamente, tentando encontrar água potável nas poças rasas do túnel gotejante. \033[1;33mDIGITE \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP231();
            }else{
                luck--;
                system("cls");
                OP309();
            }
        }
    }

}

//OPCAO 276
void OP276(){
    loop = 0;

    printf("\t276 - Ao tentar arrombar a porta com uma pancada de ombro, você ouve as vozes esganiçadas dos Trogloditas que vêm descendo o túnel. Você está encurralado e desembainha a espada. Os Trogloditas se aproximam, os arcos prontos, e uma saraivada de flechas o atinge com impacto fatal. \033[1;31mSeu corpo desaba sem vida nas profundezas do Calabouço da Morte.\033[0;37m");
    death();
}

//OPCAO 277
void OP277(){
    printf("\t277 - O túnel faz uma curva fechada para a direita e depois, uns 100 metros adiante, chega a um cruzamento. Olhando para a esquerda, você vê dois corpos caídos no chão. Resolve chegar perto e investigar.");

    enter();
    OP338();
}

//OPCAO 278
void OP278(){
    printf("\t278 - Sua lâmina atinge um dos olhos verdadeiros da Besta Sangrenta. O efeito é devastador. Ela desaba na poça, debatendo-se freneticamente. Você aproveita a oportunidade e corre, contornando a poça, rumo à  saída para o túnel.");

    enter();
    OP134();
}

//OPCAO 279
void OP279(){
    printf("\t279 - Você chega a um cruzamento no túnel. Uma nova ramificação leva para o oeste, mas as pegadas molhadas que você vem seguindo continuam para o norte. Você decide continuar seguindo as pegadas.");

    enter();
    OP032();
}

//OPCAO 280
void OP280(){
    printf("\t280 - O túnel continua para o leste por uma boa distância antes de chegar a um cruzamento. As paredes, o teto e o chão do túnel que leva para o sul estão cobertos por um limo verde e espesso. Você considera que é mais seguro dirigir-se para o norte.");

    enter();
    OP280();
}

//OPCAO 281
void OP281(){
    stageops = 281;
    save();
    loop = 0;

    printf("\t281 - Com um golpe da sua espada de fé, você corta a cabeça da Jibóia. Você desenrola o corpo gigantesco, libertando a Mulher-elfo, e tenta ressuscitá-la. Os olhos dela se abrem um pouco, mas não há esperança. Ela olha para você e sorri, depois murmura:\"Obrigada. Sei que é tarde demais para mim, mas lhe direi o que já pude aprender. A saída está adiante, mas você precisa de gemas para destrancar a última porta. Uma delas é um diamante, mas não sei quais são as outras. Pena, não encontrei um diamante, mas aconselho-o a procurar um. Boa sorte.\" Os olhos dela se fecham, e ela tomba no chão frio. Você a olha entristecido enquanto ela solta o último suspiro. Sabendo que ela não se importaria, retira-lhe os dois punhais e examina a mochila de couro que trazia. Dentro, você acha um pedaço de pão ázimo, um espelho e um amuleto de osso com a forma de um macaco. Se você quiser comer o pão, \033[1;35mdigite 399.\033[0;37m\nSe preferir pegar apenas o espelho e o amuleto e retornar ao túnel para dirigir-se ao norte, \033[1;35mdigite 192.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 399:
                loop++;
                system("cls");
                OP399();
                break;
            case 192:
                loop++;
                system("cls");
                OP192();
                break;
            case 0:
                inventory();
                enter();
                OP281();
                break;
        }
    }

}

//OPCAO 282
void OP282(){
    stageops = 282;
    save();
    loop = 0;

    printf("\t282 - O túnel logo termina em uma encruzilhada. Parado lá sozinho e sem saber para que lado ir está um de seus rivais. É um dos Bárbaros. Você o chama, mas ele não responde; apenas olha fria e fixamente para você, segurando a acha com firmeza. Você anda até ele e pergunta para que lado está indo. Ele grunhe sua resposta, dizendo que está indo para o oeste, e, se quiser, você pode ir com ele. Se você quiser seguir para o oeste com o Bárbaro, \033[1;35mdigite 22.\033[0;37m\nSe preferir recusar a oferta e seguir para o leste sozinho, \033[1;35mdigite 388.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 22:
                loop++;
                system("cls");
                OP022();
                break;
            case 388:
                loop++;
                system("cls");
                OP388();
                break;
            case 0:
                inventory();
                enter();
                OP282();
                break;
        }
    }
}

//OPCAO 283
void OP283(){
    printf("\t283 - Você precisa se espremer e entrar fundo na fenda para se esconder completamente. Dessa posição desajeitada, você não consegue ver o dono dos pés que se arrastam, passando lentamente. Um minuto depois, tudo está quieto de novo, por isso você se esgueira de volta para o túnel e prossegue para o oeste.");

    enter();
    OP109();
}

//OPCAO 284
void OP284(){
    stageops = 284;
    save();
    loop = 0;

    printf("\t284 - Você bebeu uma poção encontrada em um livro de couro preto? Se você tiver bebido, \033[1;35mdigite 398.\033[0;37m Se não, \033[1;35mdigite 57.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 57:
                loop++;
                system("cls");
                OP057();
                break;
            case 398:
                loop++;
                if(skill_trap_potion != 0){
                    system("cls");
                    OP398();
                } else{
                    printf("Você não leu este item.");
                    enter();
                    OP284();
                }
                break;
            case 0:
                inventory();
                enter();
                OP284();
                break;
        }
    }
}

//OPCAO 285
void OP285(){
    stageops = 285;
    save();
    loop = 0;

    printf("\t285 - Você cai pesadamente de costas, mas, felizmente, sua mochila suaviza o impacto.\033[1;31m Você perde 1 ponto de HABILIDADE e 2 pontos de ENERGIA\033[0;37m. A escuridão é quase total no fundo do poço, e você se arrasta, tateando. Repentinamente, sua mão toca alguma coisa fria, dura e lisa. O objeto é pequeno e redondo, mas você não consegue imaginar o que pode ser. Você o põe na mochila, esperando saber o que é quando sair do poço. Você continua a engatinhar e, adiante, topa com a parede do poço. É lisa demais para ser escalada, e você tem que escavar apoios nela com a espada. Isso toma muito tempo, mas, finalmente, você chega à  boca do poço e sai dele pelo lado leste. Imediatamente, verifica a mochila, e descobre que o objeto encontrado é uma esfera de rubi vermelho vivo. Você fica absolutamente deslumbrado e se dirige para o leste com excelente disposição, assobiando suavemente.\n\n");

    if(status_OP285 >= 0 && status_OP285 <= 2){
        energy -= 2;
        hability -= 1;
        ruby += 1;
        status_OP011 += 1;
        printf("Você perdeu 1 de HABILIDADE\n");
        printf("Sua HABILIDADE: %i\n\n", hability);
        printf("Você perdeu 2 de ENERGIA\n");
        printf("Sua ENERGIA: %i\n\n", energy);
        printf("\033[1;34m");
        printf("Rubi Vermelho foi adicionado a seu inventário");
        printf("\033[0;37m");
        enter();
        OP237();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP237();
    }
}

//OPCAO 286
void OP286(){
    printf("\t286 - Foi obviamente um erro ter largado suas armas, mas, pelo menos, agora você pode se apossar das do Ninja morto. Você escolhe uma das facas compridas e a longa espada curva. O fio da lâmina de aço é excepcionalmente duro, e você não consegue deixar de admirar-lhe a beleza terrificante.\n\n");

    printf("\033[1;32mVocê ganhou 4 de HABILIDADE\033[0;37m\n");
    printf("Sua HABILIDADE: %i\n\n", hability);
    enter();
    OP320();
}

//OPCAO 287
void OP287(){
    stageops = 287;
    save();
    loop = 0;

    printf("\t287 - Você só tem tempo de ouvir o Gnomo dizer: \"Uma coroa e dois crânios\", antes que um raio branco de energia parta da fechadura e atinja-lhe o peito, derrubando-o sem sentidos. \033[1;33mDigite \"ROLL\",\033[1;31m  você perde ENERGIA igual ao resultado mais 1.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice1();
            if(numroll > 0){
                energy = energy - (numroll + 1);
                printf("Sua ENERGIA: %i", energy);
            }
            if(energy > 0){
                printf("\n\nVocê recupera a consciência e o Gnomo manda que tente de novo. Você sabe que colocou uma gema na ranhura certa, mas qual? Você suspira e tenta uma nova combinação.\n\n    A         B         C     \nEsmeralda|Diamante |Safira    -> \033[1;35mDigite 16.\033[0;37m\nDiamante |Safira   |Esmeralda -> \033[1;35mDigite 392.\033[0;37m\nSafira   |Esmeralda|Diamante  -> \033[1;35mDigite 177\033[0;37m\nEsmeralda|Safira   |Diamante  -> \033[1;35mDigite 287.\033[0;37m\nDiamante |Esmeralda|Safira    -> \033[1;35mDigite 132.\033[0;37m\nSafira   |Diamante |Esmeralda -> \033[1;35mDigite 249.\033[0;37m\n\n");

                printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

                scanf("%i", &choices);
                switch(choices){
                    case 16:
                        loop++;
                        system("cls");
                        OP016();
                        break;
                    case 392:
                        loop++;
                        system("cls");
                        OP392();
                        break;
                    case 177:
                        loop++;
                        system("cls");
                        OP177();
                        break;
                    case 287:
                        loop++;
                        system("cls");
                        OP287();
                        break;
                    case 132:
                        loop++;
                        system("cls");
                        OP132();
                        break;
                    case 249:
                        loop++;
                        system("cls");
                        OP249();
                        break;
                    case 0:
                        inventory();
                        enter();
                        OP132();
                        break;
                }
            }else{
                death();
            }
        }
    }
}

//OPCAO 288
void OP288(){
    stageops = 288;
    save();
    loop = 0;

    printf("\t288 - Você olha para a esquerda e vê Throm de pé sobre o Troll da Caverna que ele liquidou. O sangue que escorre do corte profundo que tem no ombro não parece preocupá-lo. Vocês revistam os corpos dos Trolls da Caverna, mas não encontram nada além de um anel de osso em um cordão de couro no pescoço de um deles. O anel tem um símbolo entalhado. Throm o reconhece e explica que deve ter pertencido a druidas do norte; trata-se de um antigo e poderoso talismã, capaz de aumentar-lhe os poderes, se seu corpo puder aceitá-lo. Throm recusa-se a tocar nele, e aconselha que você também não o faça. Se você quiser pôr o anel, \033[1;35mdigite 64.\033[0;37m\nSe preferir continuar para o leste com Throm, \033[1;35mdigite 221.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 64:
                loop++;
                system("cls");
                OP064();
                break;
            case 221:
                loop++;
                system("cls");
                OP221();
                break;
            case 0:
                inventory();
                enter();
                OP288();
                break;
        }
    }

}

//OPCAO 289
void OP289(){
    loop = 0;

    printf("\t289 - A cobertura de pano sobe para o topo da gaiola, e nela, para seu horror, você vê o rosto de uma mulher velha, cujo cabelo é uma massa de serpentes que silvam. é a terrível MEDUSA!. \033[1;33mDIGITE \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP216();
            }else{
                luck--;
                system("cls");
                OP019();
            }
        }
    }
}

//OPCAO 290
void OP290(){
    printf("\t290 - \033[1;33mDigite \"ROLL\" e role os dados.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll == 8){
                system("cls");
                OP152();
            }else{
                system("cls");
                OP121();
            }
        }
    }
}

//OPCAO 291
void OP291(){
    printf("\t291 - O túnel continua para o norte por uma longa distância, antes de fazer uma curva fechada para a direita. Ao virá-la, você chega a um beco sem saída. Somente a entrada de um escorrega de madeira na parede oferece alguma esperança de continuidade no caminho. Você resolve se arriscar e sobe no escorrega. Desliza suavemente e aterrissa sobre as costas num aposento.");

    enter();
    OP090();
}

//OPCAO 292
void OP292(){
    stageops = 292;
    save();
    loop = 0;

    printf("\t292 - Uma porta se torna visível na parede do lado esquerdo do túnel. Você escuta cuidadosamente junto à  porta, mas não ouve nada. A porta não está trancada, e a maçaneta gira facilmente. Se você quiser abrir a porta, \033[1;35mdigite 93.\033[0;37m\nSe preferir prosseguir pelo túnel, \033[1;35mdigite 230.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 93:
                loop++;
                system("cls");
                OP093();
                break;
            case 230:
                loop++;
                system("cls");
                OP230();
                break;
            case 0:
                inventory();
                enter();
                OP292();
                break;
        }
    }
}

//OPCAO 293
void OP293(){
    stageops = 293;
    save();
    loop = 0;

    printf("\t293 - Seguindo os três pares de pegadas molhadas pela passagem oeste do túnel, você logo chega a uma encruzilhada.\n\nSe quiser continuar para o oeste, seguindo dois pares de pegadas, \033[1;35mdigite 137.\033[0;37m\nSe quiser se dirigir para o norte, seguindo o terceiro par de pegadas, \033[1;35mdigite 387.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 137:
                loop++;
                system("cls");
                OP137();
                break;
            case 387:
                loop++;
                system("cls");
                OP387();
                break;
            case 0:
                inventory();
                enter();
                OP293();
                break;
        }
    }
}

//OPCAO 294
void OP294(){
    loop = 0;

    printf("\t294 - Você puxa o punhal do cinto com a mão livre e golpeia a língua da Besta Sangrenta. A fera urra de dor e rola para a frente, tanto quanto consegue, para tentar abocanhá-lo com as mandíbulas ensanguentadas. Do chão, você tem que lutar contra a fera como punhal. \033[1;31mReduza sua HABILIDADE em 2 pontos durante este combate\033[0;37m, pois não está lutando com sua espada.\n\n\033[1;31mBESTA SANGRENTA HABILIDADE 12 ENERGIA 10\033[0;37m \n\nTão logo que você vencer sua primeira Série de Ataque, \033[1;33mTESTE SUA SORTE.\033[0;37m");

    monshability = 12;
    monsenergy = 10;
    enter();

    printf("COMEÇOU O COMBATE!");
    combatloop = 0;
    while(combatloop < 1){
        loop = 0;
        printf("\nRode os dados:\n");
        printf("\033[0;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        gets(combatroll);
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
            printf("\nVocê deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
            while(loop < 1){
                gets(luckhit);
                if(strcasecmp(luckhit, "sim") == 0){
                    dice2();
                    if(numroll <= luck){
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        monsenergy -= 2;
                        combatloop += 1;
                        loop++;
                        enter();
                        OP097();
                    }
                    else{
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        monsenergy += 1;
                        combatloop += 1;
                        loop++;
                        enter();
                        OP021();
                    }
                    printf("\n\n");
                }
                else if(strcasecmp(luckhit, "nao") == 0){
                    printf("\033[1;31mVOCE PRECISA TESTAR SUA SORTE\033[0;37m");
                }
            }
            printf("HP MONSTRO: %d", monsenergy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
            printf("\nVOCE LEVOU DANO\n");
            printf("\nVocê deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
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

//OPCAO 295
void OP295(){
    loop = 0;

    printf("\t295 - Correndo na direção da passagem em arco, você tropeça numa pedra e perde o equilíbrio. Você cai estatelado no chão, e, antes que tenha tempo de levantar-se, uma estalactite despenca, rasgando-lhe a perna com a ponta aguçada. \033[1;31mVocê perde 5 pontos de ENERGIA.\033[0;37m\n\n");

    energy -= 5;
    printf("Você perdeu 2 de ENERGIA\n");
    printf("Sua ENERGIA: %i\n\n", energy);
    if(energy <= 0){
        death();
    }else{
        printf("Você conseguiu sobreviver");
        enter();
        OP206();
    }
}

//OPCAO 296
void OP296(){
    stageops = 296;
    save();
    loop = 0;

    printf("\t296 - Você percebe que adiante o túnel faz uma curva e depois continua para o norte. Alertado pelo som de vozes esganiçadas que sussurram e riem baixo, você pára antes da curva. Se quiser desembainhar a espada e olhar depois da curva, \033[1;35mdigite 49.\033[0;37m\nSe preferir caminhar de volta para a encruzilhada e seguir para o norte, \033[1;35mdigite 241.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 49:
                loop++;
                system("cls");
                OP049();
                break;
            case 241:
                loop++;
                system("cls");
                OP241();
                break;
            case 0:
                inventory();
                enter();
                OP296();
                break;
        }
    }
}

//OPCAO 297
void OP297(){
    loop = 0;

    printf("\t297 - A perda de suas posses, obtidas com tanta dificuldade, está se tornando um problema. \033[1;31mVocê perde 1 ponto de SORTE.\033[0;37m Sem mesmo parar para agradecer, Erva o empurra para fora do quarto por uma porta na parede leste. Ei-lo parado no fim de um outro túnel.\n\n");

    luck -= 1;
    printf("Você perdeu 1 de SORTE\n");
    printf("\n\nSua SORTE: %i", luck);
    enter();
    OP305();
}

void OP298(){
    stageops = 298;
    save();
    loop = 0;

    printf("\t298 - Há uma mochila encostada na parede do túnel. Você se pergunta se ela pertenceria a um de seus rivais.\n\nSe você quiser olhar dentro da mochila, \033[1;35mdigite 304.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 279.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 304:
                loop++;
                system("cls");
                OP304();
                break;
            case 279:
                loop++;
                system("cls");
                OP279();
                break;
            case 0:
                inventory();
                enter();
                OP298();
                break;
        }
    }


}

//OPCAO 299
void OP299(){
    stageops = 299;
    save();
    loop = 0;

    printf("\t299 - A porta abre para uma grande câmara, onde você se choca ao ver que um de seus rivais obviamente encontrou morte súbita ao ser perfurado. é um dos Bárbaros, e ele está empalado em vários espigões de ferro bem longos, presos a uma tábua projetada de dentro do chão. O piso está coberto de lixo e detritos, escondendo um arame no qual ele deve ter pisado, disparando assim o mecanismo da tábua com espigões. Numa alcova na parede do outro lado, você pode ver uma taça de prata sobre uma pequena mesa de madeira. Você:\n\nIrá até o Bárbaro para revistá-lo? \033[1;35mDigite 126.\033[0;37m\nCaminhará na direção da alcova? \033[1;35mDigite 41.\033[0;37m\nFechará a porta e continuará para o oeste? \033[1;35mDigite 83.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 126:
                loop++;
                system("cls");
                OP126();
                break;
            case 41:
                loop++;
                system("cls");
                OP041();
                break;
            case 83:
                loop++;
                system("cls");
                OP083();
                break;
            case 0:
                inventory();
                enter();
                OP299();
                break;
        }
    }

}

//OPCAO 300
void OP300(){
    stageops = 300;
    save();
    loop = 0;

    printf("\t300 - Você golpeia o espelho com a espada, com toda sua força, mas isso de nada adianta: o espelho não quebra, e o Demônio do Espelho continua a avançar.\n\nSe você quiser tentar partir o espelho de novo, \033[1;35mdigite 141.\033[0;37m\nSe, em vez disso, preferir atacar o Demônio do Espelho, \033[1;35mdigite 327.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 141:
                loop++;
                system("cls");
                OP141();
                break;
            case 327:
                loop++;
                system("cls");
                OP327();
                break;
            case 0:
                inventory();
                enter();
                OP300();
                break;
        }
    }
}

//OPCAO 301
void OP301(){
    stageops = 301;
    save();
    loop = 0;

    printf("\t301 - O cano está úmido e cheio de limo, mas você segue engatinhando na escuridão abafada, escorregando e deslizando no caminho. Subitamente, sua mão toca em algo duro e quadrado; parece ser de madeira. Ao sacudi-la, a coisa chacoalha, e você conclui que deve estar segurando uma caixa. Se quiser engatinhar de volta e sair do cano para examinar o achado, \033[1;35mdigite 162.\033[0;37m\nSe preferir seguir em frente pelo cano, levando a caixa para examinar mais tarde, \033[1;35mdigite 4.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 162:
                loop++;
                system("cls");
                OP162();
                break;
            case 4:
                loop++;
                system("cls");
                OP004();
                break;
            case 0:
                inventory();
                enter();
                OP301();
                break;
        }
    }
}

//OPCAO 302
void OP302(){
    loop = 0;
    monsenergy = 12;
    monshability = 10;

    printf("\t302 - Depois de cerca de 20 minutos, o Anão reaparece na sacada. Ele lhe grita: \"Bem, eu realmente tenho um problema muito interessante nas mãos. Prepare-se para lutar contra seu próximo adversário.\" A porta de madeira se ergue mais uma vez, e você se admira ao ver um rosto conhecido. é Throm! Ele está muito machucado e tem cortes pelo corpo todo, e não parece reconhecê-lo. Está claramente delirante enquanto cambaleia para frente com a acha erguida para atacá-lo. O Anão ri e lhe diz: \"A naja o mordeu, mas ele tema força de um touro e conseguiu resistir, ao contrário da maioria dos homens. Agora você deve lutar com ele, para decidir finalmente qual dos dois continuará na Prova dos Campeões.\" Você grita com o Anão, revoltado, denunciando a crueldade de um confronto desses. Ele simplesmente ri, e você não tem alternativas e não se defender do ataque do pobre Throm. \n\n\033[1;31mTHROM HABILIDADE 10 ENERGIA 12\033[0;37m\nApesar dos ferimentos, Throm é imensamente forte...");

    enter();
    combat1();
    printf("Você sobreviveu a THROM!\n");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP379();
}

//OPCAO 303
void OP303(){
    printf("\t303 - Com sua mão livre, você busca a moringa na mochila. Desarrolhando-a com os dentes, derrama o ácido sobre a porta, que é na realidade a forma fluida de um IMITADOR. Um jato de fumaça sobe dela, com um alto som sibilante, enquanto o ácido começa a queimar o Imitador. Ela derrete rapidamente, e você consegue afastar-se sem se ferir. Não tendo outra alternativa, você, um tanto apreensivo, gira a maçaneta da outra porta.");

    enter();
    OP262();
}

//OPCAO 304
void OP304(){
    printf("\t304 - Há uma única Peça de Ouro no fundo da mochila. Quando você tenta pegá-la, sente um leve movimento que faz cócegas nas costas, da sua mão. Você retira a mão lentamente, tentando controlar o pânico crescente, e fica horrorizado ao ver uma ARANHA VIàVA NEGRA. Antes que possa afastá-la, ela crava as presas venenosas profundamente no seu pulso.\033[1;31m Você perde 6 pontos de ENERGIA.\033[0;37m\n\n");

    energy -= 6;
    printf("Você perdeu 6 de ENERGIA");
    printf("\nSua ENERGIA: %i\n\n", energy);
    if(energy <= 0){
        death();
    }else{
        printf("Você sobreviveu a picada da Viúva-Negra");
        enter();
        OP020();
    }
}

//OPCAO 305
void OP305(){
    stageops = 305;
    save();
    loop = 0;

    printf("305 - O túnel termina em um lance de degraus de pedra. Do chão, abaixo, vêm latidos de cães. Você tem um osso velho?\n\nSe tiver, \033[1;35mdigite 253.\033[0;37m\nSe não tiver, \033[1;35mdigite 148.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 148:
                loop++;
                system("cls");
                OP148();
                break;
            case 253:
                loop++;
                if(old_bone != 0){
                    system("cls");
                    OP253();
                } else{
                    printf("Você não tem este item.");
                    enter();
                    OP305();
                }
                break;
            case 0:
                inventory();
                enter();
                OP305();
                break;
        }
    }
}

//OPCAO 306
void OP306(){
    printf("306 - Antes que você possa dar um passo na direção dos Leprechauns, um deles joga uma poeira cintilante em você, que é imediatamente congelado no lugar, incapaz de mover um músculo. Você vê, indefeso, os Leprechauns revirarem sua mochila, fugindo com todas as suas posses e deixando a mochila vazia. \033[1;31mVocê perde 2 pontos de SORTE.\033[0;37m Cerca de uma hora depois, o efeito congelante da poeira se desfaz, e as sensações retornam a seu corpo. Furioso com a perda, você ruma para o norte, determinado a se vingar.\n\n");

    luck -= 2;
    printf("Você perdeu 2 de SORTE\n");
    printf("Você perdeu TODOS os itens do seu inventário");

    hability_potion = 0, luck_potion = 0, energy_potion = 0, emerald = 0, sapphire = 0, iron_hook = 0, iron_key = 0, wood_tube = 0, rope = 0, metal_bell = 0, brass_bell = 0, chalice = 0, morph_potion = 0, leather_wristband = 0, monkey_amulet = 0, dagger = 0, ruby = 0, topaz = 0, wooden_legs = 0, old_bone = 0, shield = 0, wish_ring = 0, moringa_acid = 0, diamond = 0;
    enter();
    OP029();
}

//OPCAO 307
void OP307(){
    stageops = 307;
    save();
    loop = 0;

    printf("307 - O armário contém uma marreta de madeira e 10 espigões de ferro, os quais você põe na mochila enquanto decide qual porta abrir.\n\nSe quiser abrir a porta do oeste, volte \033[1;35mdigite 263.\033[0;37m\nSe preferir abrir a porta do norte, \033[1;35mdigite 136.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 263:
                loop++;
                system("cls");
                OP263();
                break;
            case 136:
                loop++;
                system("cls");
                OP136();
                break;
            case 0:
                inventory();
                enter();
                OP307();
                break;
        }
    }
}

//OPCAO 308
void OP308(){
    stageops = 308;
    save();
    loop = 0;

    printf("\t308 - A Medusa berra quando você entra na gaiola, mantendo os olhos firmemente fechados e desferindo golpes furiosos de um lado para o outro com a espada. Você sente a lâmina penetrar profundamente na fera e ouve um baque alto quando ela desaba pesadamente no chão. Você abre os olhos de novo e se arrepia com a visão da Medusa prostrada. O manto dela está preso por um grande broche constituído por uma única gema grande; é uma granada. Você a arranca, põe no bolso e sai do aposento, rumo ao norte.\n\n");

    if(status_OP308 == 0){
        grenade += 1;
        status_OP308 += 1;
        printf("\033[1;34mVocê ganhou uma GRANADA\033[0;37m");
        enter();
        OP316();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP316();
    }
}

//OPCAO 309
void OP309(){
    loop = 0;

    printf("\t309 - Você cambaleia desnorteado em busca de uma poça de água, mas não encontra. O ácido queima com uma dor lancinante bem fundo na sua garganta. \033[1;31mVocê perde 3 pontos de ENERGIA.\033[0;37m \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m");

    energy -= 3;
    printf("Você perdeu 3 de ENERGIA");
    printf("\nSua ENERGIA: %i", energy);
    if(energy <= 0){
        death();
    }else{
        while(loop < 1){
            gets(startroll);
            if(strcasecmp(startroll, "roll") == 0){
                dice2();
                if(numroll <= luck){
                    luck--;
                    system("cls");
                    OP231();
                }else{
                    luck--;
                    system("cls");
                    OP193();
                }
            }
        }
    }
}

//OPCAO 310
void OP310(){
    stageops = 310;
    save();
    loop = 0;

    printf("\t310 - Você chega à  parede do outro lado da câmara e vê duas portas.\n\nSe quiser abrir a portada esquerda, \033[1;35mdigite 339.\033[0;37m\nSe quiser abrir a porta da direita, \033[1;35mdigite 262.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 339:
                loop++;
                system("cls");
                OP339();
                break;
            case 262:
                loop++;
                system("cls");
                OP262();
                break;
            case 0:
                inventory();
                enter();
                OP310();
                break;
        }
    }
}

//OPCAO 311
void OP311(){
    printf("\t311 - Depois de muito relutar, o Bárbaro concorda com sua alternativa. Vocês dois tomam distância e saltam por sobre o poço. Aterrissando em segurança do outro lado, você continua descendo pelo túnel. O Bárbaro, que vai na frente, subitamente tropeça em uma pedra, que se inclina para frente e dispara o mecanismo de um rochedo preso precariamente ao teto. O rochedo despenca sobre ele, derrubando-o e esmagando-lhe o crânio. \033[1;31mVocê terá que continuar sua jornada sozinho.\033[0;37m");

    enter();
    OP325();
}

//OPCAO 312
void OP312(){
    loop = 0;
    monsenergy = 9;
    monshability = 11;

    printf("\t312 - O disco, afiado como uma navalha, passa assobiando pela sua cabeça e crava-se profundamente em um dos pilares. Você se vira e põe-se em guarda para enfrentar o assassino, que avança com a espada longa desembainhada.\n\n\033[1;31mNINJA HABILIDADE 11 ENERGIA 9\033[0;37m\n\n");

    enter();
    combat1();
    printf("Você venceu o NINJA!\n");
    printf("Sua ENERGIA: %i", energy);
    enter();
    OP232();
}

//OPCAO 313
void OP313(){
    printf("\t313 - O túnel termina em uma encruzilhada. As pegadas que você vem seguindo viram para o norte, e você resolve manter-se na trilha delas.");

    enter();
    OP032();
}

//OPCAO 314
void OP314(){
    loop = 0;

    printf("\t314 - Sua espada corta a maçaneta e, separada do corpo de origem, a membrana murcha e cai ao chão. Não tendo outra alternativa, você gira, um tanto apreensivo, a maçaneta da outra porta.");

    enter();
    OP262();
}

//OPCAO 315
void OP315(){
    stageops = 315;
    save();
    loop = 0;

    printf("\t315 - O túnel dá uma guinada brusca para a esquerda e chega ao fim em uma parede alta, na qual há uma porta. Você ouve um rugido feroz vindo do outro lado da porta e tenta imaginar quão gigantesca seria a fera capaz de tamanho ruído.\n\nSe você tiver um rolo de corda e um gancho de ferro, \033[1;35mdigite 129.\033[0;37m\nSe não tiver esses objetos, \033[1;35mdigite 245.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 245:
                loop++;
                system("cls");
                OP245();
                break;
            case 129:
                loop++;
                if(rope != 0 && iron_hook != 0){
                    system("cls");
                    OP129();
                } else{
                    printf("\nVocê não tem estes itens.");
                    enter();
                    OP315();
                }
                break;
            case 0:
                inventory();
                enter();
                OP315();
                break;
        }
    }
}

//OPCAO 316
void OP316(){
    stageops = 316;
    save();
    loop = 0;

    printf("\t316 - O túnel continua por uma boa distância antes de chegar a um cruzamento.\n\nSe você quiser se dirigir para o oeste pelo novo túnel, \033[1;35mdigite 296.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 241.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 241:
                loop++;
                system("cls");
                OP241();
                break;
            case 296:
                loop++;
                system("cls");
                OP296();
                break;
            case 0:
                inventory();
                enter();
                OP316();
                break;
        }
    }
}

//OPCAO 317
void OP317(){
    printf("\t317 - Tateando nos lados do buraco perfurado com sua espada, você abre caminho cegamente pelo lodo viscoso. Você segue as curvas e reviravoltas do orifício por um tempo que parece ser uma eternidade e começa a imaginar onde poderia levar. De repente, você ouve o ruído de alguma coisa se arrastando à  frente. Você fica gelado de medo, seus olhos tentando desesperadamente rasgar a escuridão impenetrável. Antes que você se dê conta do que está acontecendo, seu pescoço é abocanhado pelas fortíssimas mandíbulas de outro Verme da Rocha. E o companheiro daquele que você matou, o qual foi atraído pelo cheiro de sangue na sua espada. Ele aperta mais forte. Seu pescoço estala como um ramo seco. \033[1;31mSua aventura termina aqui.\033[0;37m");
    death();
}

//OPCAO 318
void OP318(){
    stageops = 318;
    save();
    loop = 0;

    printf("\t318 - Depois de cruzar a ponte, você atravessa a caverna correndo. Finalmente, vê um túnel na parede do outro lado, pelo qual você entra a toda. O túnel termina numa pesada porta de madeira, e ela está trancada.\n\nSe você tiver uma chave de ferro, \033[1;35mdigite 86.\033[0;37m\nSe não tiver uma chave, \033[1;35mdigite 276.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 86:
                loop++;
                system("cls");
                OP086();
                break;
            case 276:
                loop++;
                if(iron_key != 0){
                    system("cls");
                    OP276();
                } else{
                    printf("Você não tem este item.");
                    enter();
                    OP318();
                }
                break;
            case 0:
                inventory();
                enter();
                OP318();
                break;
        }
    }
}

//OPCAO 319
void OP319(){
    loop = 0;

    printf("\t319 - A armadura e a espada pesam mais do que você pensa. No ar, você toma consciência, com horror, de que não vai conseguir chegar ao outro lado do poço. Você se choca contra o lado do poço, uns dois metros abaixo da borda, e despenca de cabeça para o fundo.");

    enter();
    OP285();
}

//OPCAO 320
void OP320(){
    stageops = 320;
    save();
    loop = 0;

    printf("\t320 - Você resolve revistar o Ninja e, em meio à s vestes dele, encontra um saco de pano. Dentro, há um frasco de água, um pouco de arroz enrolado em folha de palmeira, um vidro de unguento e um lindo diamante. Você:\n\nComerá o arroz e beberá a água? \033[1;35mDigite 330.\033[0;37m\nEsfregará um pouco do unguento nos seus ferimentos? \033[1;35mDigite 269.\033[0;37m\n Pegará apenas o diamante e sairá do salão? \033[1;35mDigite 127.\033[0;37m\n\n");

    printf("O diamante foi adicionado ao seu inventário.");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 330:
                loop++;
                system("cls");
                OP330();
                break;
            case 269:
                loop++;
                system("cls");
                OP269();
                break;
            case 127:
                loop++;
                system("cls");
                OP127();
                break;
            case 0:
                inventory();
                enter();
                OP320();
                break;
        }
    }
}

//OPCAO 321
void OP321(){
    stageops = 321;
    save();
    loop = 0;

    printf("\t321 - Você puxa o cordão e o pano sobe pelos lados da gaiola. A voz da mulher insiste para que você seja rápido, dizendo que o aposento está preparado para uma cilada, de forma que o piso desabará em um minuto por causa do seu peso extra.\n\nSe você ainda quiser ajudá-la, \033[1;35mdigite 289.\033[0;37m\n Se preferir sair do aposento e se dirigir para o norte pelo túnel, \033[1;35mdigite 316.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 289:
                loop++;
                system("cls");
                OP289();
                break;
            case 316:
                loop++;
                system("cls");
                OP316();
                break;
            case 0:
                inventory();
                enter();
                OP321();
                break;
        }
    }
}

//OPCAO 322
void OP322(){
    loop = 0;

    printf("\t322 - Você passa pela cadeira de madeira e logo retorna ao cruzamento, virando à  direita para o oeste.");

    enter();
    OP043();
}

//OPCAO 323
void OP323(){
    loop = 0;

    printf("\t323 - Depois de amarrar a corda em torno da rocha, você desce devagar para o fundo do poço. Throm recupera a corda dele, soltando-a da rocha com uma sacudidela, e vocês partem juntos pelo novo túnel.");

    enter();
    OP194();
}

//OPCAO 324
void OP324(){
    stageops = 324;
    save();
    loop = 0;

    printf("\t324 - Você falou com o servo aleijado dos Juízes da Prova? Se falou, \033[1;35mdigite 256.\033[0;37m Se não, \033[1;35mdigite 79.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 79:
                loop++;
                system("cls");
                OP079();
                break;
            case 256:
                loop++;
                if(status_OP341 != 0){
                    system("cls");
                    OP256();
                } else{
                    printf("Você não falou com o servo.");
                    enter();
                    OP324();
                }
                break;
            case 0:
                inventory();
                enter();
                OP324();
                break;
        }
    }
}

//OPCAO 325
void OP325(){
    printf("\t325 - Você se levanta e segue túnel abaixo. De repente, vê a luz do dia no fim do túnel. Enquanto corre na direção da visão mais bela que teve diante de si desde muito tempo, um céu claro e azul, árvores verdes, você sonha com o alegre cenário de pessoas vibrando. Mas não há recepção de herói da parte das pessoas à  sua volta. Estão todas mortas. Você está dentro de uma câmara fria repleta de cadáveres e esqueletos com armaduras. A saída para a vitória era apenas uma ilusão. Somente os despojos de aventureiros do passado são reais. Profundamente deprimido, você caminha de volta para o túnel, mas se choca com uma barreira invisível. \033[1;31mVocê está aprisionado neste sinistro local, fadado a terminar seus dias na câmara dos mortos.\033[0;37m");
    death();
}

//OPCAO 326
void OP326(){
    loop = 0;

    printf("\t326 - Adiante, o túnel faz uma curva fechada para a esquerda. Ao  dobrá-la, você quase bate de frente em dois ORCAS de aspecto feroz, armados de maças com pontas de ferro e usando armaduras de couro. Você está totalmente despreparado, e, enquanto desembainha a espada, um deles desfere-lhe um golpe de maça. \033[1;33mDigite \"ROLL\" para rolar um dado.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice1();
            if(numroll == 1 || numroll == 2){
                system("cls");
                OP091();
            }else if(numroll == 3 || numroll == 4){
                system("cls");
                OP189();
            }else{
                system("cls");
                OP380();
            }
        }
    }
}

//OPCAO 327
void OP327(){
    loop = 0;

    printf("\t327 - Exclusivamente voltado para agarrar-lhe o braço, o Demônio do Espelho não tenta defenderse. DEMàNIO DO ESPELHO HABILIDADE 10 ENERGIA 10 Se, durante uma Série de Ataque, a Força de Ataque do Demônio do Espelho for maior que a sua o combate terminará.\n\n");

    printf("COMEÇOU O COMBATE!");
    combatloop = 0;
    while(combatloop < 1){
        loop = 0;
        printf("\nRode os dados:\n");
        printf("\033[0;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        gets(combatroll);
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
            printf("\nVocê deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
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
            printf("HP MONSTRO: %d", monsenergy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
            printf("\nA FORÇA DE ATAQUE DO MONSTRO FOI MAIOR QUE A SUA! O COMBATE TERMINOU\n");
            enter();
            OP008();
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
            system("cls");
            printf("VOCE GANHOU O COMBATE!");
            enter();
            OP092();
        }
    }
}

//OPCAO 328
void OP328(){
    stageops = 328;
    save();
    loop = 0;

    printf("328 - Você olha em torno do quarto de Erva. Ao ver o retrato de um outro Troll pendurado na parede, pergunta a ela se são parentes. Imediatamente, o humor e a expressão dela mudam. Ela afrouxa o aperto sobre você e sorri, dizendo: \"Ah, sim. Este é meu amado e querido irmão Barriga Azeda. Ele tem-se saído muito bem lá no sul, em Port Blacksand. Está agora na Guarda Imperial, na tropa de elite de Lord Azzur. Estou muito orgulhosa dele.\" Erva fica olhando para a pintura e continua a tecer elogios ao irmão.\n\nSe você quiser se esgueirar para fora do quarto, pela porta na parede do leste, \033[1;35mdigite 125.\033[0;37m\nSe preferir continuar a conversa, \033[1;35mdigite 99.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 125:
                loop++;
                system("cls");
                OP125();
                break;
            case 99:
                loop++;
                system("cls");
                OP099();
                break;
            case 0:
                inventory();
                enter();
                OP328();
                break;
        }
    }
}

//OPCAO 329
void OP329(){
    printf("329 - Você caminha até o espelho e se diverte com a imagem distorcida. Sua cabeça parece tão grande quanto uma abóbora, o rosto, muito estranho... Sem qualquer sinal prévio, uma dor terrível martela-lhe a cabeça; você tenta desviar o olhar do espelho, mas não consegue. Alguma força do mal mantém seus olhos pregados ao próprio reflexo. Você segura a cabeça com as mãos e, horrorizado, se dá conta de que ela está se expandindo. \033[1;31mVocê não pode mais suportar a dor, e tomba sem sentidos para nunca mais acordar.\033[0;37m");
    death();
}

//OPCAO 330
void OP330(){
    stageops = 330;
    save();
    loop = 0;

    printf("330 - As rações do Ninja são modestas mas bem-vindas. \033[1;32mAcrescente 1 ponto de ENERGIA.\033[0;37m\n\nVocê poderá esfregar um pouco do unguento nos seus ferimentos, \033[1;35mdigite 269.\033[0;37m\nOu sair do salão, levando só o diamante, \033[1;35mdigite 127.\033[0;37m");

    if(status_OP330 == 0){
        status_OP330 += 1;
        energy += 1;
        printf("Sua ENERGIA: %i", energy);
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 127:
                    loop++;
                    system("cls");
                    OP127();
                    break;
                case 269:
                    loop++;
                    system("cls");
                    OP269();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP330();
                    break;
            }
        }
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 127:
                    loop++;
                    system("cls");
                    OP127();
                    break;
                case 269:
                    loop++;
                    system("cls");
                    OP269();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP330();
                    break;
            }
        }
    }
}

//OPCAO 331
void OP331(){
    loop = 0;
    monsenergy = 6;
    monshability = 8;

    printf("331 - Tocar o pergaminho tem precisamente o efeito que você temia. O esqueleto dá um impulso para frente e, levantando-se da cadeira numa série de movimentos aos arrancos, ergue a espada para golpeá-lo. Esquivando-se para o lado, você desembainha a sua espada para se defender.\n\nGUERREIRO-ESQUELETO HABILIDADE 8 ENERGIA 6");

    enter();
    combat1();
    printf("Você derrotou o GUERREIRO-ESQUELETO!\n");
    printf("Sua ENERGIA: %i", energy);
    enter();
    OP071();
}

//OPCAO 332
void OP332(){
    printf("332 - Sua gema cai na poça com um \"plop\" surdo. Enquanto espera que alguma coisa aconteça, você começa a se sentir fraco. O gás que emana da poça é tóxico, e você tomba inconsciente. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP053();
            }else{
                luck--;
                system("cls");
                OP272();
            }
        }
    }
}

//OPCAO 333
void OP333(){
    printf("333 - Você ouve passos e, de repente, a porta do alçapão é jogada para trás. Por alguns segundos, você é cegado pela intensa luz que vem do aposento de cima, e não vê o Goblin desferir um golpe de lança, nem ouve o riso sádico quando a ponta rasga seu pescoço. \033[1;31mSua aventura termina aqui, nos degraus de pedra do túnel.\033[0;37m");
    death();
}

//OPCAO 334
void OP334(){
    printf("334 - Você tenta se livrar da língua com as mãos nuas, mas não consegue. Lentamente, você é arrastado para a poça, onde, depois de decomposto pelo lodo, \033[1;31mseu corpo será devorado pela pavorosa Besta Sangrenta.\033[0;37m");
    death();
}

//OPCAO 335
void OP335(){
    loop = 0;

    printf("\t335 - Ainda correndo o mais rápido que pode, você mergulha no rio. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP067();
            }else{
                luck--;
                system("cls");
                OP101();
            }
        }
    }

}

//OPCAO 336
void OP336(){
    loop = 0;

    printf("\t336 - A munhequeira foi feita e amaldiçoada por uma Bruxa. Ela torna suas reações mais lentas e embota-lhe os sentidos. \033[1;31mReduza sua HABILIDADE em 4 pontos.\033[0;37m Furioso, você chuta a parede do túnel e segue para o norte.\n\n");

    if(status_OP336 == 0){
        leather_wristband += 1;
        hability -= 4;
        status_OP336 += 1;
        printf("\033[1;34mMunhequeira de Couro Amaldiçoada foi adicionada a seu inventário\033[0;37m");
        printf("\n\nVocê perdeu 4 de HABILIDADE");
        printf("\nSua HABILIDADE: %i", hability);
        enter();
        OP298();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        printf("\nSua HABILIDADE: %i", hability);
        enter();
        OP298();
    }
}

//OPCAO 337
void OP337(){
    stageops = 337;
    save();
    loop = 0;

    printf("\t337 - A água fresca é revigorante, mas provém de uma fonte amaldiçoada por uma Bruxa. Some 1 ponto de ENERGIA, mas desconte 2 pontos de SORTE.\n\nVocê poderá beber da outra fonte, \033[1;35mdigite 173\033[0;37m\nOu continuar para o norte, \033[1;35mdigite 368.\033[0;37m\n\n");

    printf("Você perdeu 2 de SORTE\n");
    printf("Sua SORTE: %i\n\n", luck - 2);
    printf("\n\nVocê ganhou 1 de ENERGIA\n");
    printf("Sua ENERGIA: %i\n\n", energy + 1);

    if(status_OP337 >= 0 && status_OP337 <= 2){
        luck -= 2;
        energy += 1;
        status_OP337 += 1;
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 173:
                    loop++;
                    system("cls");
                    OP173();
                    break;
                case 368:
                    loop++;
                    system("cls");
                    OP368();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP337();
                    break;
            }
        }
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 200:
                    loop++;
                    system("cls");
                    OP200();
                    break;
                case 316:
                    loop++;
                    system("cls");
                    OP316();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP337();
                    break;
            }
        }
    }
}

//OPCAO 338
void OP338(){
    stageops = 338;
    save();
    loop = 0;

    printf("338 - Os corpos são de dois guardas Orcas. Pelo menos um de seus rivais na Prova dos Campeões ainda deve estar à  sua frente. De uma rápida revista aos corpos nada resulta senão um colar de dentes pendurado no pescoço de um dos Orcas.\n\nSe você quiser usar o colar, \033[1;35mdigite 123.\033[0;37m\nSe preferir partir para o norte sem o colar, \033[1;35mdigite 282.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 123:
                loop++;
                system("cls");
                OP123();
                break;
            case 282:
                loop++;
                system("cls");
                OP282();
                break;
            case 0:
                inventory();
                enter();
                OP338();
                break;
        }
    }
}

//OPCAO 339
void OP339(){
    stageops = 339;
    save();
    loop = 0;

    printf("\t339 - Quando você toca a maçaneta da porta, ela fica mole na sua mão, e, quando tenta tirar a mão, descobre que ela está grudada na maçaneta. Então, um punho gigantesco se forma no meio da porta e projeta-se na sua direção, atingindo-o no estômago. Você perde 1 ponto de ENERGIA.\n\nSe tiver uma moringa de ácido, \033[1;35mdigite 303.\033[0;37m\nSe não tiver, \033[1;35mdigite 236.\033[0;37m\n\n");

    printf("Você perdeu 1 de ENERGIA\n");
    printf("Sua ENERGIA: %i\n\n", energy - 1);

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 236:
                energy -= 1;
                loop++;
                system("cls");
                OP236();
                break;
            case 303:
                loop++;
                energy -= 1;
                if(moringa_acid != 0){
                    system("cls");
                    OP303();
                } else{
                    printf("\nVocê não tem este item.");
                    enter();
                    OP339();
                }
                break;
            case 0:
                inventory();
                enter();
                OP339();
                break;
        }
    }
}

//OPCAO 340
void OP340(){
    printf("\t340 - O medo lhe dá uma nova injeção de energia, e, de alguma forma, suas pernas cansadas conseguem mantê-lo à  frente do rochedo. Adiante, à  direita, você vê a forma bem-vinda de uma porta. Você mergulha de encontro à  porta e, por sorte, ela se abre. O rochedo passa estrondoso, e você fica deitado, exausto, no chão de um aposento grande.");

    enter();
    OP381();
}

//OPCAO 341
void OP341(){
    stageops = 341;
    save();
    loop = 0;

    printf("\t341 - Um homem aleijado, com cadeias nos pés, arrasta-se na sua direção carregando uma bandeja de madeira cheia de pão e água. Ele parece cansado e desalentado, e tenta passar por você sem demonstrar reação à  sua presença. Você:\n\nFalará com ele?\033[1;35m Digite 367.\033[0;37m\nPegará pão e água da bandeja dele? \033[1;35mDigite 38.\033[0;37m\nOferecerá a ele alguma provisão (se você ainda tiver alguma)? \033[1;35mDigite 169.\033[0;37m\n\n  ");
    status_OP341 += 1;
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 367:
                loop++;
                system("cls");
                OP367();
                break;
            case 169:
                loop++;
                if(provisions != 0){
                    system("cls");
                    OP169();
                } else{
                    printf("Você não tem este item.");
                    enter();
                    OP341();
                }
                break;
            case 38:
                loop++;
                system("cls");
                OP038();
                break;
            case 0:
                inventory();
                enter();
                OP341();
                break;
        }
    }
}

//OPCAO 342
void OP342(){
    stageops = 342;
    save();
    loop = 0;

    printf("\t342 - Suas reações são lentas por causa do veneno e, embora você tente pular por cima da língua estendida, suas pernas não conseguem erguê-lo o bastante. A língua pegajosa se enrola na sua perna e começa a puxá-lo na direção da poça. Você é arrastado para o chão e não consegue desembainhar a espada.\n\nSe você tiver um punhal, \033[1;35mdigite 294.\033[0;37m\nSe não tiver um punhal, \033[1;35mdigite 334.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 334:
                loop++;
                system("cls");
                OP334();
                break;
            case 294:
                loop++;
                if(dagger != 0){
                    system("cls");
                    OP294();
                } else{
                    printf("Você não tem este item.");
                    enter();
                    OP342();
                }
                break;
            case 0:
                inventory();
                enter();
                OP342();
                break;
        }
    }
}

//OPCAO 343
void OP343(){
    stageops = 343;
    save();
    loop = 0;

    printf("\t343 - Com vozes esganiçadas, os Trogloditas explicam as regras da Corrida da Flecha. Eles dispararão uma flecha e você poderá caminhar, sem ser atacado, até o ponto onde ela cair. Porém, você deverá ir descalço, e o chão da caverna, como pode ver, está coberto de pedras pontiagudas. Logo que você chegar à  flecha, os Trogloditas começarão a persegui-lo; se o pegarem, você será morto. De repente, um dos Trogloditas dispara uma flecha bem alto no ar. Ela cai a grande distância, e, imediatamente, os Trogloditas forçam-no a caminhar na direção dela. Enquanto você anda devagar na direção da flecha, ouve os gritos excitados dos Trogloditas. Ao chegar à  flecha você se volta e vê os Trogloditas agitarem os braços no ar e iniciarem a perseguição. Você corre o mais depressa que pode, os pés sangrando com os cortes sofridos nas pedras pontiagudas. Você perde 1 ponto de ENERGIA. Adiante, um rio subterrâneo, que corre de leste para oeste, cruza a caverna; uma ponte de madeira liga uma margem à  outra.\n\nSe você quiser atravessar a ponte, \033[1;35mdigite 318.\033[0;37m\nSe quiser mergulhar no rio, \033[1;35mdigite 47.\033[0;37m\n\n");

    printf("Você perdeu 1 de ENERGIA");
    printf("\nSua ENERGIA: %i\n\n", energy - 1);

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 318:
                energy -= 1;
                loop++;
                system("cls");
                OP318();
                break;
            case 47:
                energy -= 1;
                loop++;
                system("cls");
                OP047();
                break;
            case 0:
                inventory();
                enter();
                OP343();
                break;
        }
    }
}

//OPCAO 344
void OP344(){
    stageops = 344;
    save();
    loop = 0;

    printf("344 - O túnel faz curvas e reviravoltas, mas continua sempre para o norte. À sua frente, um facho de luz azul desce do teto para o chão. Ele faísca e cintila, e você pode ver imagens de rostos que riem na luz.\n\nSe você quiser passar através da luz, \033[1;35mdigite 229.\033[0;37m\nSe preferir contornar o facho, \033[1;35mdigite 107.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 229:
                loop++;
                system("cls");
                OP229();
                break;
            case 107:
                loop++;
                system("cls");
                OP107();
                break;
            case 0:
                inventory();
                enter();
                OP344();
                break;
        }
    }
}

//OPCAO 345
void OP345(){
    printf("345 - Você está prestes a entrar no aposento quando a Poção de Detecção de Cilada começa a fazer efeito, e você é dominado por uma terrível premonição. Há uma armadilha mortal neste aposento. Você resolve não entrar e continua para o norte pelo túnel.");

    enter();
    OP252();
}

//OPCAO 346
void OP346(){
    loop = 0;

    printf("\t346 - Você tira a bota do pé e se esforça para estendê-la até o sino e travar-lhe a vibração. Aos poucos, o sino vai parando de vibrar, e a dor no seu corpo diminui gradualmente. Você consegue se levantar, mas não afasta a bota do sino até que ele esteja completamente imóvel. Você calça a bota e continua a jornada para o oeste.");

    enter();
    OP362();
}

//OPCAO 347
void OP347(){
    printf("\t347 - O Anão sacode a cabeça, dizendo: \"Só músculos, sem inteligência, não bastam para conquistar a Prova dos Campeões. \033[1;31mSinto dizer que você fracassou\033[0;37m. Você não terá permissão para ir embora, pois poderá revelar os segredos do calabouço para outros. Todavia, você conseguiu muito chegando tão longe, e eu o indicarei para meu servo pelos anos futuros para preparar o calabouço para os novos competidores\".");
    death();
}

//OPCAO 348
void OP348(){
    printf("348 - Você avança sobre a Besta Sangrenta, tentando evitar a língua que se estende para agarrar-lhe a perna. \033[1;33mDigite \"ROLL\" e teste sua SORTE\033[0;37m\n\n");

     while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP225();
            }else{
                system("cls");
                OP159();
            }
        }
    }
}

//OPCAO 349
void OP349(){
    loop = 0;
    monsenergy = 15;
    monshability = 12;

    printf("\t349 - Você desce pela corda para o interior do poço, segurando-se com uma das mãos, enquanto a outra leva a espada desembainhada. O Diabo do Poço é uma das feras mais terríveis que você já viu, e você sabe que esta será uma das lutas mais difíceis da sua vida.\n\n\033[1;31mDIABO DO POÇO HABILIDADE 12 ENERGIA 15\033[0;37m\n\n");

    enter();
    combat1();
    printf("\nVocê derrotou o DIABO DO POÇO!\n");
    printf("Sua HABILIDADE: %i", hability);
    enter();
    OP258();

}

//OPCAO 350
void OP350(){
    loop = 0;

    printf("\t350 - A Mosca Gigante mergulha na sua direção e agarra-o com quatro patas. Rapidamente ela retorna ao teto da caverna, e você se encontra indefeso pendurado no ar. Súbito, para seu horror, ela o solta. Você despenca de 10 metros de altura, estatelando-se no solo.\n\n\033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice1();
            dards = numroll;
            energy -= dards;
            printf("\n\nVocê perdeu %d de ENERGIA", dards);
            printf("\nSua ENERGIA: %i", energy);
            if(energy <= 0){
                death();
            } else{
                printf("\n\nVocê sobreviveu a queda, a tempo de tomando seus sentidos desembainha sua espada contra a investida seguinte da Mosca Gigante");
                enter();
                OP039();
            }
        }
    }
}

//OPCAO 351
void OP351(){
    stageops = 351;
    save();
    loop = 0;

    printf("\t351 - O ídolo é muito liso, e a escalada será difícil. Você tem corda?\n\nSe tiver, \033[1;35mdigite 396.\033[0;37m\nSe não tiver, \033[1;35mdigite 186.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 186:
                loop++;
                system("cls");
                OP186();
                break;
            case 396:
                loop++;
                if(rope != 0){
                    system("cls");
                    OP396();
                } else{
                    printf("\n\033[1;31mVocê não tem este item.\033[0;37m");
                    enter();
                    OP351();
                }
                break;
            case 0:
                inventory();
                enter();
                OP351();
                break;
        }
    }
}

//OPCAO 352
void OP352(){
    stageops = 352;
    save();
    loop = 0;

    printf("\t352 - Você ouve o som de rochas sendo trituradas e esmagadas à  sua frente. O ruído cresce e, subitamente, você se dá conta de que a parede do seu lado direito começa a desabar. Apavorado, você vê uma enorme e horrorosa criatura, com mandíbulas incrivelmente poderosas, deslizar por um buraco na parede. A enorme boca da criatura mastiga rocha enquanto ela vira a cabeça devagar de um lado para outro, sentindo o ar fresco do túnel. O VERME DA ROCHA parece ser cego, mas dá a impressão de estar ciente de sua presença, talvez sentindo o calor de seu corpo. Ele se arrasta na sua direção com as mandíbulas bem abertas, pronto para o ataque.\n\nSe você quiser lutar contra o Verme da Rocha, \033[1;35mdigite 254.\033[0;37m\nSe preferir correr de volta pelo túnel para o cruzamento e depois se dirigir para o leste, \033[1;35mdigite 68.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 254:
                loop++;
                system("cls");
                OP254();
                break;
            case 68:
                loop++;
                system("cls");
                OP068();
                break;
            case 0:
                inventory();
                enter();
                OP352();
                break;
        }
    }

}

//OPCAO 353
void OP353(){
    loop = 0;

    printf("\t353 - Antes que você possa sair do caminho, o rochedo se choca contra seu ombro. \033[1;31mVocê perde 1 ponto de HABILIDADE e 4 pontos de ENERGIA.\033[0;37m\n\n");

    energy -= 4;
    hability -= 1;
    printf("Você perdeu 4 de ENERGIA");
    printf("\nSua ENERGIA: %i", energy);
    printf("\n\nVocê perdeu 1 de HABILIDADE");
    printf("\nSua HABILIDADE: %i", hability);
    if(energy <= 0){
        death();
    }else{
        printf("Você sobrevive a pancada");
        enter();
        OP325();
    }
}

//OPCAO 354
void OP354(){
    loop = 0;

    printf("\t354 - A pílula faz com que você se sinta como se o mundo inteiro estivesse contra você. E perde 2 pontos de SORTE. O Anão lhe diz que agora você pode passar à  segunda fase do teste. Ele apanha uma cesta de vime e lhe diz que ela contém uma serpente. Vira a cesta e a serpente cai no chão. é uma naja, e se ergue no ar, pronta para dar o bote. O Anão lhe diz que pretende testar suas reações. Você deverá agarrar a naja com as mãos nuas, pelo pescoço, evitando as presas mortais. Você se agacha, tensionando os músculos para o momento decisivo.\n\n\033[1;35mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP055();
            }else{
                system("cls");
                OP202();
            }
        }
    }

}

//OPCAO 355
void OP355(){
    printf("\t355 - Você se aproxima silenciosamente por trás dos Hobglobins que lutam e, saltando das sombras, empurra-os contra a parede e foge correndo. Você olha para trás e os vê esparramados no chão. Rindo, você segue depressa para o norte.");

    enter();
    OP110();
}

//OPCAO 356
void OP356(){
    stageops = 356;
    save();
    loop = 0;

    printf("\t356 - Há uma abertura no lado esquerdo da parede do túnel. Você está de pé na entrada de uma caverna grande, quando ouve uma voz de mulher gritando por socorro. Você distingue apenas a forma de uma figura humana que rola pelo chão no fundo da caverna.\n\nSe você quiser entrar na caverna, \033[1;35mdigite 170.\033[0;37m\nSe preferir continuar para o norte pelo túnel, \033[1;35mdigite 192.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 170:
                loop++;
                system("cls");
                OP170();
                break;
            case 192:
                loop++;
                system("cls");
                OP192();
                break;
            case 0:
                inventory();
                enter();
                OP356();
                break;
        }
    }
}

//OPCAO 357
void OP357(){
    stageops = 357;
    save();
    jeweloop = 0;
    loop = 0;

    printf("\t357 - A Besta Sangrenta chafurda na poça, e o cheiro dos gases venenosos, cujas bolhas sobem à  tona e contaminam a atmosfera, provoca ânsias de vômito. Você:\n\nCorrerá contornando a poça da fera, na direção do túnel? \033[1;35mDigite 255.\033[0;37m\nJogará uma gema na poça (se você tiver uma)? \033[1;35mDigite 332.\033[0;37m\nAtacará a fera com sua espada? \033[1;35mDigite 180.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");
    
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 255:
                loop++;
                system("cls");
                OP255();
                break;
            case 332:
                loop++;
                printf("\n\nJOIAS COLETADAS:\n");
                if(emerald == 0 && jewel == 0 && sapphire == 0 && diamond == 0 && ruby == 0 && topaz == 0){
                    printf("\n\033[1;31mVocê não possui JOIAS\033[0;37m");
                    enter();
                    OP357();
                }if(emerald != 0)
                    printf("\nEsmeralda: x%d, se deseja jogar fora esta joia digite \033[1;33m\"1\"\033[0;37m", emerald);
                if(diamond != 0)
                    printf("\nDiamante: x%d, se deseja jogar fora esta joia digite \033[1;33m\"2\"\033[0;37m", diamond);
                if(ruby != 0)
                    printf("\nRubi: x%d, se deseja jogar fora esta joia digite \033[1;33m\"3\"\033[0;37m", ruby);
                if(topaz != 0)
                    printf("\nTopazio: x%d, se deseja jogar fora esta joia digite \033[1;33m\"4\"\033[0;37m", topaz);
                if(sapphire != 0)
                    printf("\nSafira: %d, se deseja jogar fora esta joia digite \033[1;33m\"5\"\033[0;37m", sapphire);
                if(jewel != 0)
                    printf("\nJoia: x%d, se deseja jogar fora esta joia digite \033[1;33m\"6\"\033[0;37m", jewel);
                
                printf("\n");
                while(jeweloop < 1){
                    scanf("%d", &invuse);
                    switch (invuse)
                    {
                    case 1:
                        jeweloop++;
                        emerald -= 1;
                        break;
                    case 2:
                        jeweloop++;
                        diamond -= 1;
                        break;
                    case 3:
                        jeweloop++;
                        ruby -= 1;
                        break;
                    case 4:
                        jeweloop++;
                        topaz -= 1;
                        break;
                    case 5:
                        jeweloop++;
                        sapphire -= 1;
                        break;
                    case 6:
                        jeweloop++;
                        jewel -= 1;
                        break;
                    }
                }
                printf("A joia selecionada foi jogada ao poço");
                enter();
                OP332();
                break;
            case 180:
                loop++;
                system("cls");
                OP180();
            case 0:
                inventory();
                enter();
                OP357();
                break;
        }
    }
}

//OPCAO 358
void OP358(){
    printf("\t358 - Você perde o equilíbrio e despenca de cabeça no chão. \033[1;31mPerde 2 pontos de ENERGIA.\033[0;37m Você desiste de tentar escalar o ídolo e corre para seguir pelo túnel na parede norte.\n\n");

    printf("Você perdeu 2 de ENERGIA\n");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP239();
}

//OPCAO 359
void OP359(){
    printf("\t359 - Você cai da corda e despenca de cabeça na fenda. \033[1;31mBate com a cabeça em uma saliência rochosa e morre antes de chegar ao fundo da fenda.\033[0;37m");
    death();
}

//OPCAO 360
void OP360(){
    stageops = 360;
    save();
    loop = 0;

    printf("\t360 - Depois de pagar, você sobe na cesta de vime. O velho grita, jogando a cabeça para trás: \"Puxa, Erva!\" A corda se retesa, e a cesta se ergue aos solavancos. Enquanto você está sendo1 içado cada vez mais alto, o velho lhe grita: \"Você vai gostar de Erva, ela é uma ótima garota. Nós a chamamos de Erva Venenosa!\" Ele ri descontrolado, e você, um tanto apreensivo, se pergunta quem o está içando. A cesta passa por um buraco no teto, e você se vê em um pequeno quarto, frente a frente com uma mulher TROLL feia e velha. Ela tem o rosto peludo e coberto de verrugas. Com uma enorme mão ela o puxa para fora da cesta, a qual deixa cair lá embaixo. Em seguida, agarra-o pela garganta e lhe diz, numa voz rouca: \"Quero pagamento também!\" Você:\n\nOferecerá a ela alguma coisa da sua mochila? \033[1;35mDigite 297.\033[0;37m\nTentará convencê-la a não cobrar nada de você? \033[1;35mDigite 328.\033[0;37m\nAtacará a mulher com sua espada? \033[1;35mDigite 211.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 297:
                loop++;
                system("cls");
                OP297();
                break;
            case 328:
                loop++;
                system("cls");
                OP328();
                break;
            case 211:
                loop++;
                system("cls");
                OP211();
                break;
            case 0:
                inventory();
                enter();
                OP360();
                break;
        }
    }
}

//OPCAO 361
void OP361(){
    loop = 0;

    printf("\t361 - As mandíbulas do Diabo do Poço dão um bote no amuleto de macaco e o apanham no ar, mas logo se abrem de novo, forçadas pelo amuleto, que se expandiu a ponto de ocupar toda a boca da fera. Enquanto o Diabo do Poço se debate, tentando livrar-se do amuleto, você desce até o fundo para chegar à s portas duplas. Desvairado, o Diabo do Poço usa o imenso corpo na tentativa de esmagar você contra a parede.\033[1;33m\n\nDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP082();
            }else{
                luck--;
                system("cls");
                OP377();
            }
        }
    }

}

//OPCAO 362
void OP362(){
    printf("\t362 - O túnel dá uma guinada acentuada para a direita e continua para o norte até onde a vista alcança. A distância, você ouve uma tremenda comoção: grunhidos, rosnados, uivos. Você desembainha a espada e parte na direção do tumulto.");

    enter();
    OP264();
}

//OPCAO 363
void OP363(){
    loop = 0;

    printf("\t363 - A comida e a bebida são excelentes, e você se sente muito melhor.\033[1;32m Acrescente 2 pontos de ENERGIA.\033[0;37m Plenamente satisfeito, você senta e espera a volta do Anão.\n\n");

    if(status_OP363 == 0){
        energy += 2;
        status_OP363 += 1;
        printf("Você recebeu 2 de ENERGIA");
        printf("\nSua ENERGIA: %i", energy);
        enter();
        OP302();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP302();
    }
}

//OPCAO 364
void OP364(){
    stageops = 364;
    save();
    loop = 0;

    printf("\t364 - Enquanto remove o sangue do Mantécora de sua espada, você leva um susto ao ver um homenzinho com um nariz grande saltar de trás de um dos pilares de mármore. Ele veste uma túnica justa, verde, e parece inofensivo, embora você fique desconfiado do modo como ele segura uma bola de vidro opaco com uma luz verde cintilante. \"Meus cumprimentos!\", ele diz animadamente. \"Meu nome é Igbut, o Gnomo, e sou o Juiz da Prova para seu teste final. Não é preciso dizer que meus poderes mágicos são grandes, por isso você não deve tentar me atacar. Talvez você tenha sabido, durante a sua jornada, que as gemas desempenham um papel essencial na Prova dos Campeões. A porta de ferro à  sua frente é a saída para a vitória, mas só há uma maneira de abri-la. é preciso pôr três gemas no mecanismo da fechadura, numa ordem específica. Cada gema irradia uma energia que acionará o mecanismo, se você as colocar corretamente, é claro. Eu o ajudarei de certa forma, mas primeiro precisamos das gemas certas. Você tem uma esmeralda?\".\n\nSe você tiver uma esmeralda, \033[1;35mdigite 31.\033[0;37m\nSe não tiver, \033[1;35mdigite 3.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 3:
                loop++;
                system("cls");
                OP003();
                break;
            case 31:
                loop++;
                if(emerald != 0){
                    system("cls");
                    OP031();
                } else{
                    printf("Você não tem este item.");
                    enter();
                    OP134();
                }
                break;
            case 0:
                inventory();
                enter();
                OP364();
                break;
        }
    }
}

//OPCAO 365
void OP365(){
    stageops = 365;
    save();
    loop = 0;

    printf("\t365 - Você diz a Throm que matar o Anão não vai adiantar nada, pois vocês jamais acharão a saída da câmara sozinhos. Você argumenta que talvez surja uma chance de enganar o Anão mais tarde, quando tiverem descoberto a saída da câmara, por isso você pretende ir adiante com o teste do Anão. Você diz ao Anão que está pronto, e ele acena para que o siga. Throm deve aguardar a volta dele. Uma porta secreta abre-se na parede da câmara, e você segue o Anão até um pequeno aposento circular. Ele fecha a porta atrás de você e lhe entrega dois dados de osso, mandando que os jogue no chão. Você tira um seis e um dois: total, oito. O Anão pede que você os jogue mais uma vez, mas, agora, deve adivinhar se o total será igual, menor ou maior que oito.\n\nSe seu palpite for que será igual, \033[1;35mdigite 290.\033[0;37m\nSe achar que será menor que oito, \033[1;35mdigite 191.\033[0;37m\nSe optar por maior que oito, \033[1;35mdigite 84.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 290:
                loop++;
                system("cls");
                OP290();
                break;
            case 191:
                loop++;
                system("cls");
                OP191();
                break;
            case 84:
                loop++;
                system("cls");
                OP084();
                break;
            case 0:
                inventory();
                enter();
                OP365();
                break;
        }
    }

}

//OPCAO 366
void OP366(){
    printf("\t366 - A temperatura continua a subir, muito além dos limites de tolerância humanos. Estendido no chão quase derretido do túnel, você não consegue recuperar a consciência. \033[1;31mSua aventura termina aqui.\033[0;37m");
    death();
}

//OPCAO 367
void OP367(){
    stageops = 367;
    save();
    loop = 0;

    printf("\t367 - Ele o encara desconfiado quando você diz que é um competidor na Prova dos Campeões. Você pergunta a ele o que faz nos túneis, e ele lhe responde, um tanto relutante, que é servo de um dos Juízes da Prova, os controladores das diferentes partes do calabouço designados pelo Barão Sukumvit. Depois de alguma conversa, ele admite que gostaria de fugir, mas ninguém pode sair do calabouço, pois poderia revelar os segredos da construção. Ele espera conseguir sair dali mediante suborno, e, por uma Peça de Ouro, poderá dizer-lhe onde há um tesouro escondido.\n\nSe você quiser pagar pela orientação do velho, \033[1;35mdigite 244.\033[0;37m\nSe preferir simplesmente desejar-lhe o melhore continuar para o oeste, \033[1;35mdigite 109.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 244:
                loop++;
                system("cls");
                OP244();
                break;
            case 109:
                loop++;
                system("cls");
                OP109();
                break;
            case 0:
                inventory();
                enter();
                OP367();
                break;
        }
    }
}

//OPCAO 368
void OP368(){
    stageops = 368;
    save();
    loop = 0;

    printf("\t368 - Você vê um par de pernas-de-pau junto à  parede do lado esquerdo do túnel. Elas estão firmemente acorrentadas, e num aviso preso a um cadeado lê-se: \"O preço destas pernas-depau é uma Peça de Ouro. Coloque a moeda na ranhura para abrir o cadeado.\"\n\nSe você quiser comprar as pernas-de-pau, \033[1;35mdigite 165.\033[0;37m\nSe preferir prosseguir para o norte, \033[1;35mdigite 234.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 165:
                loop++;
                system("cls");
                OP165();
                break;
            case 234:
                loop++;
                system("cls");
                OP234();
                break;
            case 0:
                inventory();
                enter();
                OP368();
                break;
        }
    }
}

//OPCAO 369
void OP369(){
    loop = 0;
    monsenergy = 11;
    monshability = 10;

    printf("\t369 - O túnel faz uma curva fechada para a direita, continuando para o leste até onde a vista alcança. Throm pára e lhe diz que faça o mesmo. Ele vira a cabeça devagar de um lado para o outro: \"Ouço passos descendo pelo túnel na nossa direção\", ele sussurra. \"Desembainhe a espada.\" Vocês se agacham para se esconder nas sombras, e bem a tempo: duas figuras armadas se aproximam. Throm salta e brada um grito de guerra. Dois TROLLS DA CAVERNA estão diante de vocês. Throm ataca o primeiro com a acha de guerra, e você corre para ajudá-lo, atacando o segundo Troll da Caverna.\033[1;31m\n\nTROLL DA CAVERNA HABILIDADE 10 ENERGIA 11\n\n\033[0;37m");

    enter();
    combat1();
    printf("\n\nVocê derrotou o TROLL DA CAVERNA");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP288();
}

//OPCAO 370
void OP370(){
    loop = 0;

    printf("370 - Quando você contorna a poça correndo, a Besta Sangrenta estende a língua comprida mais uma vez.\033[1;33m\n\nDigite \"ROLL\" e teste sua HABILIDADE.\n\n\033[0;37m");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP104();
            }else{
                system("cls");
                OP342();
            }
        }
    }
}

//OPCAO 371
void OP371(){
    loop = 0;

    printf("\t371 - Você faz pontaria e joga a bola de madeira no crânio.\033[1;33m\n\nDigite \"ROLL\" e teste sua HABILIDADE.\n\n\033[0;37m");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP237();
            }else{
                system("cls");
                OP113();
            }
        }
    }
}

//OPCAO 372
void OP372(){
    printf("\t372 - Você finalmente chega ao corpo do guerreiro, mas, logo que toca na jóia, tanto ela quanto o guerreiro desaparecem como num passe de mágica. A porta bate atrás de você, e segue-se um estrondo agourento acima da sua cabeça. Você olha para o alto e vê o teto baixando. Corre para a porta na tentativa de escapar, mas ela está trancada e não há maçaneta do lado de dentro. O teto vai descendo, e você é obrigado a se deitar no chão, tentando impedir o movimento do teto comas mãos e os pés. \033[1;31mMas o esforço é inútil, e você é esmagado entre os blocos de pedra.\033[0;37m");
    death();
}

//OPCAO 373
void OP373(){
    printf("\t373 - Você sobe pelo rochedo macio, temendo ser absorvido por ele a qualquer momento. é difícil passar por cima da coisa, pois seus membros afundam na casca mole, mas, por fim, você consegue chegar ao outro lado. Aliviado por estar de novo em terreno firme, você se dirige para o leste.");

    enter();
    OP013();
}

//OPCAO 374
void OP374(){
    loop = 0;

    printf("\t374 - Você caminha pela caverna, mas não acha nada interessante. Throm o chama lá de trás, dizendo que encontrou um saco de couro sob uma pilha de rochas. Abrindo o saco, Throm ri alto quando um minúsculo camundongo corre entre os dedos dele e foge para uma fresta entre dois rochedos. A súbitas, você ouve o som de rocha rachando: estalactites se desprendem do teto, como resultado da vibração causada pelo riso retumbante de Throm, que ainda ecoa pela caverna. Você berra para que Throm fuja pela passagem em arco, enquanto as estalactites desabam.\033[1;33m\n\nDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP118();
            }else{
                luck--;
                system("cls");
                OP295();
            }
        }
    }
}

//OPCAO 375
void OP375(){
    printf("375 - Uma fumaça acre emana da moringa quando você enfia o pano nela. O líquido é indubitavelmente ácido. Você arrolha a moringa de novo e a coloca na mochila, esperando que venha a ter utilidade mais tarde. Você recoloca a espada na bainha e prossegue rumo ao norte.\n\n");

    if(status_OP375 == 0){
        moringa_acid += 1;
        status_OP375 += 1;
        printf("Ácido de Moringa foi adicionado a seu inventário");
        enter();
        OP110();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP110();
    }
}

//OPCAO 376
void OP376(){
    stageops = 376;
    save();
    loop = 0;

    printf("376 - O Gnomo, ainda sorrindo, lhe diz, excitado: \"Excelente! Só falta uma. Você possui um diamante?\"n\\nSe você tiver encontrado um diamante, \033[1;35mdigite 62.\033[0;37m\nSe não tiver encontrado um diamante, \033[1;35mdigite 3.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 3:
                loop++;
                system("cls");
                OP003();
                break;
            case 62:
                loop++;
                if(diamond != 0){
                    system("cls");
                    OP062();
                } else{
                    printf("\n\nVocê não tem este item.");
                    enter();
                    OP376();
                }
                break;
            case 0:
                inventory();
                enter();
                OP376();
                break;
        }
}
}
//OPCAO 377
void OP377(){
    loop = 0;

    printf("377 - A imensa fera atira o corpo contra o seu braço, e você solta a corda. Gritando de dor, você despenca no fundo do poço e \033[1;31mperde 5 pontos de ENERGIA.\033[0;37m\n\n");

    energy -= 5;
    printf("Você perdeu 5 de ENERGIA");
    printf("\nSua ENERGIA: %i", energy);
    if(energy <= 0){
        death();
    } else{
        printf("\n\nVocê sobreviveu ao ataque da fera");
        enter();
        OP203();
    }

}

//OPCAO 378
void OP378(){
    loop = 0;

    printf("378 - Um tanto nervoso, você respira fundo e mergulha na poça escura. A parede norte não se projeta muito longe, sob a superfície da água, e você resolve se arriscar e nadar por baixo dela. Logo começa a sentir falta de ar e é obrigado a voltar à  tona. Você tenta não pensar que pode estar aprisionado em um velho túnel submerso e fica aliviado quando emerge e encontra ar puro. Você está do outro lado da parede e pode ver o túnel saindo da água e continuando para o norte. Saindo da água, você verifica o conteúdo da mochila molhada.\n\n\033[1;33mDigite \"ROLL\" e teste sua SORTE\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP112();
            }else{
                luck--;
                system("cls");
                OP209();
            }
        }
    }
}

//OPCAO 379
void OP379(){
    stageops = 379;
    save();
    loop = 0;

    printf("379 - Exaurido pelo longo duelo, você cai de joelhos. Ao olhar para o corpo imóvel de Throm, um ódio amargo ao Anão enche-lhe o coração. De alguma forma, você vingará Throm. Envolvido pela raiva, não repara que o Anão entra na arena, até que ele chega diante de você, uma besta carregada apontada para o seu peito. \"Sei o que você está pensando\", ele diz calmamente, \"Mas não se esqueça que só eu sei o modo de sair daqui. Levante-se, está na hora de você ir embora.\" O Anão indica que você deve andar à  frente dele. De volta à  câmara, ele vai até a parede norte e empurra uma das pedras que a compõem. Um pedaço da parede, semelhante a uma porta, gira, abrindo-se para um túnel iluminado por cristais. Com a besta ainda apontada para o seu peito, o Anão sorri, dizendo: \"Boa sorte.\"\n\nSe você quiser caminhar direto para o túnel, \033[1;35mdigite 213.\033[0;37m\nSe preferir desferir um soco no Anão, \033[1;35mdigite 145.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 213:
                loop++;
                system("cls");
                OP213();
                break;
            case 145:
                loop++;
                system("cls");
                OP145();
                break;
            case 0:
                inventory();
                enter();
                OP379();
                break;
        }
    }
}

//OPCAO 380
void OP380(){
    loop = 0;
    monsenergy = 5;
    monshability = 5;

    printf("\t380 - A maça de ferro do Orca se choca contra o escudo e resvala sem causar dano. O túnel é estreito demais para que os dois o ataquem ao mesmo tempo, por isso você pode lutar com um de cada vez.\n\n\033[1;31mPrimeiro ORCA HABILIDADE 5 ENERGIA 5\nSegundo ORCA HABILIDADE 6 ENERGIA 4\033[0;37m\n\n");

    enter();
    combat1();
    printf("\nSua ENERGIA: %i\n", energy);
    printf("Você matou a PRIMEIRA ORCA! Se prepare para o seu segundo combate.\n\n");
    loop = 0;
    monsenergy = 4;
    monshability = 6;
    enter();
    combat1();
    printf("\nSua ENERGIA: %i\n", energy);
    printf("Você matou a SEGUNDA ORCA!\n\nVocê venceu a batalha!");
    enter();
    OP257();
}

//OPCAO 381
void OP381(){
    stageops = 381;
    save();
    loop = 0;

    printf("381 - Você olha em volta no aposento e nada vê de interesse, exceto a alcova na parede do oeste e uma cadeira de pedra no meio do aposento, na qual se encontra sentado o esqueleto de um guerreiro armado, possivelmente um concorrente de anos atrás. Os dedos descamados da mão direita estão fechados em torno de um pedaço de pergaminho.\n\nSe você quiser pegar o pergaminho do esqueleto, \033[1;35mdigite 331.\033[0;37m\nSe preferir caminhar até a alcova, \033[1;35mdigite 128.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 331:
                loop++;
                system("cls");
                OP331();
                break;
            case 128:
                loop++;
                system("cls");
                OP128();
                break;
            case 0:
                inventory();
                enter();
                OP381();
                break;
        }
    }

}

//OPCAO 382

void OP382(){
    stageops = 382;
    save();
    loop = 0;

    printf("\t382 - O velho aponta para uma das estátuas, e você logo a reconhece. é o cavaleiro que iniciou a Prova dos Campeões, um olhar de agonia registrado na pedra para toda a eternidade. O velho sorri, dizendo: \"Este homem pesa 50 kg mais a metade do peso dele. Quanto ele pesa?\" O que você responderá?\n\n50 quilos? \033[1;35mDigite 144.\033[0;37m\n75 quilos? \033[1;35mDigite 227.\033[0;37m\n100 quilos? \033[1;35mDigite 391\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 144:
                loop++;
                system("cls");
                OP144();
                break;
            case 227:
                loop++;
                system("cls");
                OP227();
                break;
            case 391:
                loop++;
                system("cls");
                OP391();
                break;
            case 0:
                inventory();
                enter();
                OP382();
                break;
        }
    }
}

//OPCAO 383

void OP383(){
    printf("Para sua grande surpresa, nada de extraordinário lhe acontece enquanto está sentado na cadeira. Nada há a fazer senão continuar para o norte pelo túnel.");

    enter();
    OP188();
}

//OPCAO 384

void OP384(){
    printf("O quarto degrau cede sob seu peso. Sua perna afunda num buraco e, antes que você tenha tempo de retira-la, sente uma terrível dor no pé quando dentes que não pode ver cravam-se nele. Os guinchos agudos que você ouve lá embaixo são produzidos por ratazanas. Elas estão famintas e arrancam-lhe pedaços do pé, ansiosas pela sua carne. Você perde 2 pontos de ENERGIA. Você recupera o equilíbrio e consegue tirar a perna do buraco. Três ratazanas ainda se penduram pelos dentes no seu pé. Chutando freneticamente, você bate com as cabeças delas contra o corrimão até que se soltem. Você então enrola bandagens improvisadas com sua camisa rasgada em torno do pé que sangra e sobe os degraus para partir para o norte de novo.\n\n");

    energy -= 2;
    printf("Você perdeu 2 de ENERGIA");
    printf("\n\nSua ENERGIA: %i", hability);
    enter();
    OP277();
}

//OPCAO 385

void OP385(){
    stageops = 385;
    save();
    loop = 0;

    printf("Você derrama o conteúdo do frasco de vidro na boca e engole o líquido claro. Embora não sinta qualquer mudança imediata, você espera que a poção crie a ilusão de que você é um TROGLODITA igual aos outros diante de você. Respirando fundo, penetra decididamente na caverna. Os Trogloditas continuam com sua dança tribal, acreditando que você é um deles. Você passa por eles andando naturalmente e segue para o norte. Infelizmente, os efeitos da poção são de curta duração, e você ouve um berro atrás de si, quando um dos Trogloditas repara em você, que é forçado a correr, atravessando a caverna. Adiante, você vê um rio subterrâneo que corre de leste para oeste, cruzando a caverna, e uma ponte que liga uma margem à  outra.\n\nSe você quiser correr pela ponte, \033[1;35mdigite 318.\033[0;37m\nSe preferir mergulhar no rio, \033[1;35mdigite 47.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 318:
                loop++;
                system("cls");
                OP318();
                break;
            case 47:
                loop++;
                system("cls");
                OP047();
                break;
            case 0:
                inventory();
                enter();
                OP385();
                break;
        }
    }
}

//OPCAO 386

void OP386(){
    printf("\t386 - Você não chega a percorrer mais de três metros para o oeste antes de se chocar contra uma barreira invisível. Ela estala e solta faíscas, e você é repelido. Você colidiu com uma parede magnética. \033[1;31mVocê perde 1 ponto de ENERGIA\033[0;37m. Não há outra alternativa senão voltar para a encruzilhada e seguir para o norte.\n\n");

    energy -= 1;
    printf("Você perdeu 1 de ENERGIA");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP218();

}

//OPCAO 387

void OP387(){
    loop = 0;
    monsenergy = 7;
    monshability = 7;

    printf("Da sua frente vem o baque de passos pesados que se aproximam. Da penumbra surge um ser grande e primitivo, vestido com uma pele de animal e carregando uma clava de madeira. Ao vê-lo, ele grunhe e cospe no chão, em seguida ergue a clava e avança na sua direção, com um ar nada amigável. Você desembainha a espada e se prepara para enfrentar o HOMEM DA CAVERNA.\n\n\033[1;31mHOMEM DA CAVERNA HABILIDADE 7 ENERGIA 7\033[0;37m\n\n");

    enter();
    combat1();
    printf("Você derrotou o HOMEM DA CAVERNA!\n");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP114();

}

//OPCAO 388

void OP388(){
    stageops = 388;
    save();
    loop = 0;

    printf("O túnel logo chega a um beco sem saída. Um pedaço de papel, escurecido e enrugado de tão velho, está pregado na parede do fundo.\n\nSe você quiser pegá-lo para ver se contém alguma mensagem, \033[1;35mdigite 23\033[0;37m.\nSe preferir apressar-se a voltar pelo túnel para reunir-se ao Bárbaro, \033[1;35mdigite 154.\033[0;37m");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 23:
                loop++;
                system("cls");
                OP023();
                break;
            case 154:
                loop++;
                system("cls");
                OP154();
                break;
            case 0:
                inventory();
                enter();
                OP388();
                break;
        }
    }
}

//OPCAO 389

void OP389(){
    printf("Sem suas armas você está mais vulnerável, e a perda da espada faz com que se sinta praticamente nu.\033[1;31m Você perde 4 pontos de HABILIDADE\033[0;37m. Questionando se tomou a decisão correta, você segue pelo túnel para o norte.\n\n");

    printf("\033[1;34mVocê perdeu 4 de HABILIDADE\033[0;37m");
    printf("\nSua HABILIDADE: %i", hability);
    enter();
    OP181();
}

//OPCAO 390

void OP390(){
    stageops = 390;
    save();
    loop = 0;

    printf("Você se agacha ao lado do pedestal, abaixo da linha de fogo das bestas. Estica a mão e puxa o crânio do pedestal, esperando que sua ação faça as bestas dispararem. Para sua grande surpresa, nada acontece. Some 1 ponto de SORTE. Ainda agachado, você arranca as jóias que formam os olhos do crânio. Você identifica as pedras amarelas - topázios - e as coloca na mochila. Olhando para a série de bestas, pergunta-se se ainda há uma armadilha à  sua espera no aposento. Você:\n\nEngatinha para fora do aposento, levando o crânio? \033[1;35mDigite 15.\033[0;37m\nRecoloca o crânio no pedestal antes de engatinhar para fora do aposento? \033[1;35mDigite 204.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 15:
                loop++;
                system("cls");
                OP015();
                break;
            case 204:
                loop++;
                system("cls");
                OP204();
                break;
            case 0:
                inventory();
                enter();
                OP390();
                break;
        }
    }
}

//OPCAO 391

void OP391(){
    printf("Ainda sorrindo, o velho olha para você e diz: \"Muito bem, Estranho. Você respondeu corretamente. Desejo-lhe boa sorte durante o resto da Prova dos Campeões, e, com este objetivo, aumentarei seus poderes.\" Ele então murmura mais umas poucas palavras ininteligíveis, e você sente um impulso poderoso percorrer-lhe o corpo. \033[1;32mAcrescente 1 ponto a cada um dos seus índices de HABILIDADE, ENERGIA e SORTE.\033[0;37m Você diz adeus ao velho e sai do aposento para continuar para o norte pela passagem.\n\n");

    if(status_OP391 == 0){
        luck += 1;
        energy += 1;
        hability += 1;
        status_OP391 += 1;
        printf("\033[1;33mVocê recebeu 1 de SORTE\n");
        printf("\033[1;32mVocê recebeu 1 de ENERGIA\n");
        printf("\033[1;31mVocê recebeu 1 de HABILIDADE\n\n");
        printf("\033[0;37mSua SORTE: %i", luck);
        printf("\nSua ENERGIA: %i", energy);
        printf("\nSua HABILIDADE: %i", hability);
        enter();
        OP100();
    }else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        enter();
        OP100();
    }
}

//OPCAO 392

void OP392(){
    stageops = 392;
    save();
    loop = 0;

    printf("Você só tem tempo de ouvir o Gnomo dizer: \"Três crânios\", antes que um raio branco de energia seja disparado da fechadura e atinja-lhe o peito, derrubando-o sem sentidos. Digite \"ROLL\" e role um dado, o resultado somado 1 é reduzido de sua ENERGIA.");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice1();
            if(numroll > 0){
                energy = energy - (numroll + 1);
                printf("Sua ENERGIA: %i", energy);
            }
            if(energy > 0){
                printf("\n\nVocê recupera os sentidos e ouve o Gnomo ordenar que tente de novo. Você não acertou nenhuma das gemas, por isso não tentará essa combinação de novo.\n\n    A         B         C     \nEsmeralda|Diamante |Safira    -> \033[1;35mDigite 16.\033[0;37m\nDiamante |Safira   |Esmeralda -> \033[1;35mDigite 392.\033[0;37m\nSafira   |Esmeralda|Diamante  -> \033[1;35mDigite 177.\033[0;37m\nEsmeralda|Safira   |Diamante  -> \033[1;35mDigite 287.\033[0;37m\nDiamante |Esmeralda|Safira    -> \033[1;35mDigite 132.\033[0;37m\nSafira   |Diamante |Esmeralda -> \033[1;35mDigite 249.\033[0;37m\n\n");

                printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

                scanf("%i", &choices);
                switch(choices){
                    case 16:
                        loop++;
                        system("cls");
                        OP016();
                        break;
                    case 392:
                        loop++;
                        system("cls");
                        OP392();
                        break;
                    case 177:
                        loop++;
                        system("cls");
                        OP177();
                        break;
                    case 287:
                        loop++;
                        system("cls");
                        OP287();
                        break;
                    case 132:
                        loop++;
                        system("cls");
                        OP132();
                        break;
                    case 249:
                        loop++;
                        system("cls");
                        OP249();
                        break;
                    case 0:
                        inventory();
                        enter();
                        OP132();
                        break;
                }
            }else{
                death();
            }
        }
    }
}

//OPCAO 393

void OP393(){
    stageops = 393;
    save();
    loop = 0;

    printf("Você entra em um aposento frio, dividido por uma fenda profunda. Uma corda retesada estendida de lado a lado atravessa a fenda para o outro lado, onde um magnífico elmo alado repousa sobre um poste.\n\nSe você quiser caminhar pela corda bamba para chegar ao elmo, \033[1;35mdigite 274.\033[0;37m\nSe preferir retornar pelo túnel para continuar para o norte, \033[1;35mdigite 291.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 274:
                loop++;
                system("cls");
                OP274();
                break;
            case 291:
                loop++;
                system("cls");
                OP291();
                break;
            case 0:
                inventory();
                enter();
                OP393();
                break;
        }
    }
}

//OPCAO 394

void OP394(){
    stageops = 394;
    save();
    loop = 0;

    printf("\t394 - Você arrebenta o vidro com o cabo da espada, fazendo um buraco grande o bastante para que você passe. Imediatamente, os Insetos Gigantes saltam na sua direção. Sem perda de tempo, você entra no aposento, apanhando uma das tochas acesas para se defender. O fogo mantém a maioria dos Insetos a distância, mas, quando você consegue pegar a coroa e retornar ao corredor, certamente foi mordido por alguns deles. Os Insetos Gigantes não vêm atrás de você, preferindo a luz brilhante do aposento em que estão. Você examina a coroa, e vê com desgosto que não é nada além de ferro pintado, e o \"diamante\" é vidro e não vale nada. Você a atira no chão com raiva e fica pensando aonde ir em seguida.\n\nSe quiser se dirigir para o oeste, \033[1;35mdigite 59.\033[0;37m\nSe preferir retornar ao cruzamento para continuar para o norte, \033[1;35mdigite 14.\033[0;37m");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    // Jogue um dado e some 2 ao total. Este é o número de ferroadas que você recebeu, e terá que reduzir sua ENERGIA em 1 ponto para cada uma delas.
    dice1();
    dards = dice1 + 2;
    printf("\033[1;31mVocê perdeu %i de ENERGIA\033[0;37m", dards);
    printf("\nSua ENERGIA: %i\n\n", energy - dards);

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 14:
                energy -= dards;
                loop++;
                system("cls");
                OP014();
                break;
            case 59:
                loop++;
                system("cls");
                OP059();
                break;
            case 0:
                inventory();
                enter();
                OP394();
                break;
        }
    }
}

//OPCAO 395

void OP395(){
    printf("\t395 - Ao ouvir o roído da sua bainha, um dos Trogloditas dá o alarme. Você se levanta e corre o mais rápido que pode pela caverna. Um dos arqueiros dispara uma flecha que lhe rasga o ombro com precisão mortal. \033[1;31mVocê perde 3 pontos de ENERGIA.\033[0;37m\n\n");

    printf("\033[1;31mVocê perdeu 3 de ENERGIA\033[0;37m");
    printf("\nSua HABILIDADE: %i", hability);
    if(energy <= 0){
        death();
    } else{
        printf("Você sobreviveu a flechada no ombro");
        enter();
        OP259();
    }

}

//OPCAO 396

void OP396(){
    stageops = 396;
    save();
    loop = 0;

    printf("\t396 - Você faz um laço com a corda, gira-o acima de si e o lança na cabeça do ídolo, sorrindo com alegria quando ele cai em torno do pescoço da estátua. Você então aperta o nó e começa a içar-se pela corda. Logo chega ao topo, sentando-se em cima do nariz do ídolo enquanto continua a segurar a corda. Você desembainha a espada e fica pensando de que olho arrancar a jóia primeiro.\n\nSe você quiser arrancar primeiro a do olho esquerdo, \033[1;35mdigite 151.\033[0;37m\nSe preferir arrancar a do olho direito, \033[1;35mdigite 34.\n\n\033[0;37m");

    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 151:
                loop++;
                system("cls");
                OP151();
                break;
            case 34:
                loop++;
                system("cls");
                OP034();
                break;
            case 0:
                inventory();
                enter();
                OP396();
                break;
        }
    }
}

//OPCAO 397

void OP397(){
    stageops = 397;
    save();
    loop = 0;

    printf("\t397 - O líquido é uma poção mágica que lhe permitirá detectar armadilhas ocultas. Some 2 pontos de SORTE.\n\nSe ainda não o fez, você pode abrir o livro vermelho, \033[1;35mdigite 52.\033[0;37m\nDo contrário, você terá que continuar para o norte com Throm, \033[1;35mdigite 369.\033[0;37m\n\n");
    printf("\033[1;34mLEMBRE-SE, VOCê PODE ACESSAR SEU INVENTÁRIO DIGITANDO 0\033[0;37m\n\n");
    if(status_OP397 >= 0 && status_OP397 <= 3){
        printf("\033[1;31mA poção foi adicionada à s suas SKILLS.");
        printf("\033[1;31mVocê ganhou 2 de SORTE.");
        printf("\033[0;37mSua SORTE: %i", luck);
        skill_trap_potion += 1;
        luck += 2;
        status_OP397 += 1;
        while(loop < 1){
            scanf("%i", &choices);
            switch (choices){
                case 52:
                    loop++;
                    system("cls");
                    OP052();
                    break;
                case 369:
                    loop++;
                    system("cls");
                    OP369();
                    break;
                case 0:
                    loop++;
                    system("cls");
                    OP397();
                    break;
            }
        }
    }
    else{
        printf("\033[1;31mVocê já esteve aqui, nada foi adicionado ao seu inventário.\033[0;37m\n\n");
        while(loop < 1){
            scanf("%i", &choices);
            switch (choices){
                case 52:
                    loop++;
                    system("cls");
                    OP052();
                    break;
                case 369:
                    loop++;
                    system("cls");
                    OP369();
                    break;
                case 0:
                    loop++;
                    system("cls");
                    OP397();
                    break;
            }
        }
    }
}

//OPCAP 398

void OP398(){
    printf("\t398 - Embora não haja qualquer armadilha evidente, você tem a forte sensação de que a arca contém um perigo oculto. A Poção de Dete`cção de Armadilha está funcionando bem. Você pára de um dos lados da arca e levanta a tampa com a espada, esticando o braço para mantê-la a distância. Quando a tampa se ergue, uma bola de ferro presa a um cordão é atirada para trás e quebra uma cápsula de vidro que está fixada no lado de dentro da tampa, instantaneamente liberando um gás. Felizmente, você tem tempo de pular para trás sem inalar os vapores venenosos. Quando o gás se dissipa, você caminha até a arca e olha dentro dela. Uma corrente com um pingente está jogada no fundo, mas alguém já tirou a jóia que havia nele. Você fica tão aborrecido que joga a corrente no chão e sai do aposento, furioso, para o túnel.");

    enter();
    OP230();
}


//OPCAO 399

void OP399(){
    printf("\t399 - O pão contém ervas curativas secretas dos elfos. \033[1;322mSome 3 pontos de ENERGIA.\033[0;37m Sentindo-se triste, embora forte, você guarda o espelho e o amuleto, saindo da caverna para seguir para o norte.\n\n");

    energy -= 3;
    printf("Você perdeu 3 de ENERGIA\n");
    printf("Sua ENERGIA: %i", energy);
    if(energy <= 0){
        death();
    }else{
        enter();
        OP192();
    }
}

//OPCAO 400

void OP400(){
    printf("\t400 - Logo que você aparece na saída do túnel, uma multidão grita e vibra. As pessoas abrem alas para que você siga na direção de um pequeno palanque, no qual, sentado embaixo de um párasol de bambu colorido, está o Barão Sukumvit. Ele parece apalermado, como se jamais esperasse que alguém conseguisse sair vivo do Calabouço da Morte. O segredo de Fang foi revelado. Quando o Barão se levanta da cadeira, você sobe os degraus do palanque, inclina-se diante dele e observa aqueles olhos frios fixos em você em completo espanto. Você sorri meio sem graça quando ele lhe oferece a mão estendida. Em meio ao barulho ensurdecedor da ovação do povo de Fang, o Barão Sukumvit abre o cofre que contém seu prêmio de 10.000 Peças de Ouro. Em seguida, ele coloca uma coroa de louros sobre a sua cabeça e o proclama Campeão do Calabouço da Morte.");
    enter();
    end();
}

void end(){
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t  \033[1;36mPARABÉNS!\033[0;37m  \t\t\t\t\t\t\t\t\t\t\t\t\t\t\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t Você chegou ao final do \033[1;31mCALABOUÇO DA MORTE!\033[0;37m \t\t\t\t\t\t\t\t\t\t\t\t");
    enter();
    godmode = 1;
    stageops = 0;
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t  CRÉDITOS  \t\t\t\t\t\t\t\t\t\t\t\t\t\t\n\n");
    printf("\tEste jogo é uma adaptação de um livro chamado \"A MASMORRA DA MORTE\" escrito por Ian Livingstone. Toda a programação, idealização e design deste jogo fora feito por três estudantes do primeiro período do curso Sistemas de Informação da instituição CESMAC de Maceió-AL, os alunos são:\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t       \033[1;32mDANIEL CORREIA\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t       MATEUS PACàFICO\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tSILVIO ROMERO\033[0;37m\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     \033[1;33mObrigado por jogar!\033[0;37m");
    enter();
    printf("\t\t\t\t\t\t\t\t\t\t\t\t       \033[1;34mNovo modo \"GODMODE\" disponível para jogo!\033[0;37m");
    save();
    enter();
    startmenu();
}

int main(){
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));
    OP124();
    return 0;
}