#include<stdio.h>

// this is the recursive function from tower of hanoi
void towerOfHanoi(int num_of_disk, char rod_before, char rod_after, char rod_auxiliary){
	// if the number of disk is more than 0, then it will call itself
	// but if the number of disk is equals or less than 0, then it will stop
	if(num_of_disk > 0){
		towerOfHanoi(num_of_disk - 1, rod_before, rod_auxiliary, rod_after);
		printf("Moving disk from %c to %c\n", rod_before, rod_after);
		towerOfHanoi(num_of_disk - 1, rod_auxiliary, rod_after, rod_before);
	}
}

int main(){
	// you can change the value from the variables below
	int num_of_disk = 5;
	char rod_before = 'A';
	char rod_after = 'B';
	char rod_auxiliary = 'C';
	
	towerOfHanoi(num_of_disk, rod_before, rod_after, rod_auxiliary);
	
	return 0;
}
