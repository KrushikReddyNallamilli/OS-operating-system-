#include <stdio.h>
int curr[20][20], maxclaim[20][20], avl[20];
int alloc[5] = {0, 0, 0, 0, 0};
int maxres[20], running[20], safe=0;
int count = 0, i, j, exec, r, p, k = 1,pronum[20],c=0;
int main()
{
	printf("\nEnter the number of processes: ");
	scanf("%d", &p);
	for (i = 0; i < p; i++) {
		running[i] = 1;
		count++;
	}
	printf("\nEnter the number of resources: ");
	scanf("%d", &r);
	for (i = 0; i < r; i++) {
		printf("\nEnter the resource for instance %d: ", k++);
		scanf("%d", &maxres[i]);
	}
	printf("\nEnter maximum resource table:\n");
	for (i = 0; i < p; i++) {
		for(j = 0; j < r; j++) {
			scanf("%d", &maxclaim[i][j]);
		}
	}
	printf("\nEnter allocated resource table:\n");
	for (i = 0; i < p; i++) {
		for(j = 0; j < r; j++) {
			scanf("%d", &curr[i][j]);
		}
	}
	printf("\nThe resource of instances: ");
	for (i = 0; i < r; i++) {
		printf("\t %d", maxres[i]);
	}
	printf("\n The allocated resource table:\n");
	for (i = 0; i < p; i++) {
		for (j = 0; j < r; j++) {
			printf("\t %d", curr[i][j]);
		}
		printf("\n");
	}
	printf("\nThe maximum resource table:\n");
	for (i = 0; i < p; i++) {
		for (j = 0; j < r; j++) {
			printf("\t%d", maxclaim[i][j]);
		}
	printf("\n");
	}
	for (i = 0; i < p; i++) {
		for (j = 0; j < r; j++) {
			alloc[j] += curr[i][j];
		}
	}
	printf("\nAllocated resources:");
	for (i = 0; i < r; i++) {
		printf("\t %d", alloc[i]);
	}
	for (i = 0; i < r; i++) {
	avl[i] = maxres[i] - alloc[i];
	}
	printf("\nAvailable resources:");
	for (i = 0; i < r; i++) {
		printf("\t %d", avl[i]);
	}
	printf("\n");
	while (count != 0) {
		safe = 0;
		for (i = 0; i < p; i++) {
			if (running[i]) {
				exec = 1;
				for (j = 0; j < r; j++) {
					if (maxclaim[i][j] - curr[i][j] > avl[j]) {
					exec = 0;
					break;
					}
				}
				if (exec) {
					printf("\nProcess %d is executing \n", i + 1);
					running[i] = 0;
					count--;
					safe = 1;
					pronum[c++]=i+1;
					for (j = 0; j < r; j++) {
						avl[j] += curr[i][j];
					}
					break;
				}
			}
		}
		if (!safe) {
			printf("\nThe processes are in unsafe state.\n");
			break;
		} else {
			printf("\n The process is in safe state");
			printf("\n The available resource is:");
			for (i = 0; i < r; i++) {
				printf("\t %d", avl[i]);
			}
			printf("\n");
		}
	}
	printf("\n The safe sequence of Process is: ");
	for (i = 0; i < p; i++) {
		printf("\t P%d", pronum[i]);
	}
}

// Outut:

// Enter the number of processes: 5

// Enter the number of resources: 3

// Enter the resource for instance 1: 10

// Enter the resource for instance 2: 5

// Enter the resource for instance 3: 7

// Enter maximum resource table:
// 7 5 3
// 3 2 2
// 9 0 2
// 2 2 2
// 4 3 3

// Enter allocated resource table:
// 0 1 0
// 2 0 0
// 3 0 2
// 2 1 1
// 0 0 2

// The resource of instances:       10      5       7
//  The allocated resource table:
//          0       1       0
//          2       0       0
//          3       0       2
//          2       1       1
//          0       0       2

// The maximum resource table:
//         7       5       3
//         3       2       2
//         9       0       2
//         2       2       2
//         4       3       3

// Allocated resources:     7       2       5
// Available resources:     3       3       2

// Process 2 is executing

//  The process is in safe state
//  The available resource is:      5       3       2

// Process 4 is executing

//  The process is in safe state
//  The available resource is:      7       4       3

// Process 1 is executing

//  The process is in safe state
//  The available resource is:      7       5       3

// Process 3 is executing

//  The process is in safe state
//  The available resource is:      10      5       5

// Process 5 is executing

//  The process is in safe state
//  The available resource is:      10      5       7

//  The safe sequence of Process is:        P2      P4      P1      P3      P5
