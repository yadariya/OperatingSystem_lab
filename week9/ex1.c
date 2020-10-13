#include <string.h>
#include <stdio.h>
//Ageing: when a page fault occurs, throw out the page that has been unused for the longest time

/**My results:
 * N=10  hits: 7, misses: 993, ratio: 0.007049
 * N=50  hits: 50, misses: 950, ratio: 0.052632
 * N=100 hits: 96, misses: 904, ratio: 0.106195
 * */

typedef struct {
    int R_bit: 1;
    int counter_bits: 8; //as in the book
    int number; // page number from file
} page;

int page_index(int current_page, int size,
               page *Page);// method that returns index of current_page if it is in frame, or 0 otherwise

void updated_counter(page *Page, int size); // method for updating counter bits

void update_R_bit(int n, page *Page, int size); // method for updating R_bits

int main() {
    int N; // maximum number of page frames
    scanf("%d", &N);
    page Page[N];
    int size = 0; //actual  number of pages, initially is 0
    int hit_number = 0; // number of hits
    int miss_number = 0; // number of misses

    FILE *file = fopen("/home/dariya/CLionProjects/example/input.txt", "r");
    if (file == NULL) {
        printf("File cannot be read");
        return 0;
    }

    while (!feof(file)) { // the ageing algorithm is executed until the end of the file
        int current_page; //current page number from the file
        fscanf(file, "%d", &current_page);
        int index = page_index(current_page, size, Page);
        if (index == -1) { //if page fault occurred
            miss_number++;

            // Case with free space in the frame
            if (size < N) {
                page new;
                new.number = current_page;
                new.R_bit = 1;
                new.counter_bits = 0;
                Page[size] = new;
                size++;
            }
                //Case with no free space in the frame
            else {
                int min = Page[0].counter_bits; // throw out the page that has been unused for the longest time =>
                // page whose counter is the lowest
                int min_index = 0;
                for (int i = 0; i < N; i++) {
                    if (Page[i].counter_bits < min) {
                        min_index = i;
                        min = Page[i].counter_bits;
                    }
                }
                Page[min_index].counter_bits = 0;
                Page[min_index].number = current_page;
                Page[min_index].R_bit = 1;
            }
        } else { // if no page fault occurred
            Page[index].R_bit = 1;
            hit_number++;
            update_R_bit(current_page, Page, size);
            updated_counter(Page, size);
        }
    }
    fclose(file);
    printf("hits: %d, misses: %d, ratio: %f", hit_number, miss_number,
           (float) hit_number / miss_number);
    return 0;
}


int page_index(int current_page, int size, page *Page) {
    for (int i = 0; i < size; i++) {
        if (Page[i].number == current_page) {
            return i;
        }
    }
    return -1;
}

void update_R_bit(int n, page *Page, int size) {
    for (int i = 0; i < size; i++) {
        if (Page[i].number != n) {
            Page[i].R_bit = 0;
        }
    }
}

void updated_counter(page *Page, int size) {
    for (int i = 0; i < size; i++) {
        Page[i].counter_bits >>= 1;
        Page[i].counter_bits += 128 * Page[i].R_bit;
    }
}