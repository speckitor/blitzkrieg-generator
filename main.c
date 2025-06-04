#include <stdio.h>

int startposes[32] = {0};
int startposes_number = 0;

void blitzkrieg_generate();

int main() {
    int current_startpos;
    int index = 1;

    for (;;) {
        scanf("%d", &current_startpos);    

        if (current_startpos == 0) {
            break;
        }
        
        startposes[index] = current_startpos;
        index++;
        startposes_number++;
    }

    startposes[index] = 100;
    startposes_number++;

    blitzkrieg_generate();
    
    return 0;
}
void blitzkrieg_generate() {
    int stage;

    for (stage = 1; stage < startposes_number + 1; ++stage) {
        printf("Stage %d\n", stage);
        for (int run = startposes_number - stage; run >= 0 ; --run) {
            printf("%d - %d\n", startposes[run], startposes[run + stage]);
        }
    }
}
