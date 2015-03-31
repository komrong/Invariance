//Invariance -- Termination check algorithm

/*
To each vertex P(sub)i (i = 1, . . . , 5) of a pentagon an integer x(sub)i is assigned, the sum s = Σx(sub)i being positive. The following operation is allowed, provided at least one of the x(sub)i’s is negative: Choose a negative x(sub)i, replace it by −x(sub)i, and add the former value of x(sub)i to the integers assigned to the two neighboring vertices of P(sub)i (the remaining two integers are left unchanged). This operation is to be performed repeatedly until all negative integers disappear. Decide whether this procedure must eventually terminate.
*/

/*
An algorithm runs as long as the specified condition is met
*/

#include <stdio.h>
#include <time.h>

int main(void){
	int vertex[5];
	int sum = 0;
	int t1 = 0;
	int t = 0;
	int l = 0;
	do{
		sum = 0;
		t = 0;
		l = 0;
		int k = 0;
		while(k < 5){
			printf("Assign the vertex %d: \n", (k+1));
			scanf("%d", &(vertex[k]));
			sum += vertex[k];
			k++;
		}
		
		k = 0;
		while(k < 5){
			if(vertex[k] < 0){
				t++;
			}
			k++;
		}
		
		if(t == 0){
			printf("You must at least assign one negative number. Go again!!!\n");
			sleep(5);
		}
		else if(sum < 0){
			printf("The sum of numbers has to be positive. Go again!!!\n");
			sleep(5);
		}
		else{
			printf("Your numbers: %d\t %d\t %d\t %d\t %d\t\n", vertex[0], vertex[1], vertex[2], vertex[3], vertex[4]);
			t1 = t;
			while(t1 != 0){
				int i = 0;
				while(i < 5){
					if(vertex[i] < 0){
						if(i == 0){
							vertex[i+4] += vertex[i];
							vertex[i+1] += vertex[i];
							vertex[i] = -vertex[i];
							break;
						}
						else if(i == 4){
							vertex[i-1] += vertex[i];
							vertex[i-4] += vertex[i];
							vertex[i] = -vertex[i];
							break;
						}
						else{
							vertex[i-1] += vertex[i];
							vertex[i+1] += vertex[i];
							vertex[i] = -vertex[i];
							break;
						}
					}
					i++;
				}
				int j = 0;
				t1 = 0;
				while(j < 5){
					if(vertex[j] < 0){
					t1++;
					}
					j++;
				}
				
				printf("Line %d:  %d  %d  %d  %d  %d\n", l, vertex[0], vertex[1], vertex[2], vertex[3], vertex[4]);
				l++;
			}
		}
	}while(t == 0 || sum < 0);
	
	return 0;
}
