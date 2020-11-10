#include <stdio.h>

int executing(int process[], int available[], int size);

void new_Available(int resources[], int A[], int size);

int main(void) {

    FILE *input = fopen("/home/dariya/innopolisuniversityOS/week13/input_dl.txt", "r");
    int resources;
    fscanf(input, "%d", &resources);
    int prossesors;
    fscanf(input, "%d", &prossesors);

    int E[resources];
    int A[resources];

    for (int i = 0; i < resources; i++) {
        fscanf(input, "%d ", &E[i]);
    }

    for (int i = 0; i < resources; i++) {
        fscanf(input, "%d ", &A[i]);
    }
    int allocated[prossesors][resources];
    for (int i = 0; i < prossesors; i++) {
        for (int j = 0; j < resources; j++) {
            fscanf(input, "%d ", &allocated[i][j]);
        }
    }
    int required[prossesors][resources];
    for (int i = 0; i < prossesors; i++) {
        for (int j = 0; j < resources; j++) {
            fscanf(input, "%d ", &required[i][j]);
        }
    }
    int deadlock = 0;
    int hasFinished[prossesors];
    for (int i = 0; i < prossesors; i++) {
        hasFinished[i] = 0;
    }
    int dont_complete = prossesors;
    while (dont_complete != 0) {
        deadlock++;
        for (int i = 0; i < prossesors; i++) {
            if (hasFinished[i] == 0 && executing(required[i], A, resources)) {
                hasFinished[i] = 1;
                new_Available(allocated[i], A, resources);
                deadlock--;
            }
        }
        dont_complete--;
    }
    if (deadlock == 0) {
        FILE *out = fopen("/home/dariya/innopolisuniversityOS/week13/output_ok.txt", "w");
        fprintf(out, "No deadlock");
    } else {
        FILE *out = fopen("/home/dariya/innopolisuniversityOS/week13/output_dl.txt", "w");
        fprintf(out, "Deadlock processes: \n");
        for (int i = 0; i < prossesors; i++) {
            if (!hasFinished[i]) {
                fprintf(out, "%d ", i + 1);
            }
        }
    }

}

int executing(int required[], int available[], int size) {
    for (int i = 0; i < size; i++) {
        if (required[i] > available[i]) {
            return 0;
        }
    }
    return 1;
}

void new_Available(int resources[], int A[], int size) {
    for (int i = 0; i < size; i++) {
        A[i] += resources[i];
    }
}