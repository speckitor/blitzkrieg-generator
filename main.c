#include <stdio.h>
#include <string.h>

void get_startposes_from_stdin();
int get_startposes_from_file(char *filename);

void blitzkrieg_generate();

int startposes[32] = {0};
int startposes_number = 0;

int main(int argc, char **argv) {
    char *filename = NULL;

    for (int i = 1; i < argc; ++i) {
        if (((strcmp("-f", argv[i]) == 0) || (strcmp("--from-file", argv[i]) == 0)) && i + 1 < argc) {
            filename = argv[i+1];
        } 
    }

    if (filename != NULL) {
        int read_file = get_startposes_from_file(filename);

        if (read_file == 1) {
            fprintf(stderr, "Failed to read file!\n");
        }
    } else {
        get_startposes_from_stdin();
    }    

    blitzkrieg_generate();
    
    return 0;
}

void get_startposes_from_stdin() {
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
}

int get_startposes_from_file(char *filename) {
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        return 1;
    }

    int current_startpos;
    int index = 1;

    char line[4];

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%d", &current_startpos);

        startposes[index] = current_startpos;
        index++;
        startposes_number++;
    }

    fclose(file);

    startposes[index] = 100;
    startposes_number++;

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
