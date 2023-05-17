#include <stdio.h>

int find_lru(int used[], int n) {
    int min = used[0], min_index = 0;
    for (int i = 1; i < n; i++) {
        if (used[i] < min) {
            min = used[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int n; // number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n]; // array to hold pages
    printf("Enter the page references:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    int m; // maximum number of frames in physical memory
    printf("Enter the maximum number of frames in physical memory: ");
    scanf("%d", &m);

    int frames[m]; // array to hold frames in physical memory
    for (int i = 0; i < m; i++) {
        frames[i] = 0;
    }

    int used[m]; // array to hold the time each frame was last used
    for (int i = 0; i < m; i++) {
        used[i] = -1;
    }

    int page_faults = 0; // count of page faults

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int frame_index = -1;

        for (int j = 0; j < m; j++) {
            if (frames[j] == page) {
                frame_index = j;
                break;
            }
        }

        if (frame_index == -1) {
            page_faults++;

            for (int j = 0; j < m; j++) {
                if (frames[j] == 0) {
                    frame_index = j;
                    break;
                }
            }

            if (frame_index == -1) {
                frame_index = find_lru(used, m);
            }

            frames[frame_index] = page;
        }

        for (int j = 0; j < m; j++) {
            if (frames[j] != 0) {
                used[j]++;
            }
        }
        used[frame_index] = 0;
    }

    printf("Number of page faults: %d\n", page_faults);

    return 0;
}
