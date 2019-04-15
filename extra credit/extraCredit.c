#include <stdio.h>
#include <stdlib.h>
//Sturcutre t that holds 4 intergers and a string
struct address_t {
	int x;
	int y;
	int z;
	int m;
	char nickName[255];
};

//Scan adresses reads in adresses

//Print adresses prints adresses
void print_address(struct address_t address){
	printf("%d.%d.%d.%d	%s", address.x, address.y, address.z, address.m, address.nickName);
}
//Local adress checks if two addresses are local
int local_address(struct address_t a, struct address_t b){
	if (a.x == b.x && a.y == b.y){
		return 1;
	} else {
		return 0;
	}
}
//Main function opens file
int main () {
	FILE *fp;
	char buff[255];
	struct address_t addresses[255];
	int count = 0;
	
	fp = fopen("/public/csci112sp19/extracredit/ipaddresses.txt", "r");
	
	//Checks if file exists
	if (fp == NULL) {
		printf("Error opening file\n");
		exit(1);
	}
	
	//Loops through file achiving adreses until reaches end of document
	while (fscanf(fp, "%s", buff) > 0){
		sscanf(buff, "%d.%d.%d.%d", &addresses[count].x, &addresses[count].y, &addresses[count].z, &addresses[count].m);
		fgets(addresses[count].nickName, 255, (FILE*) fp);
		print_address(addresses[count]);
		count++;
	}
	
	//Checks all ip address to see which are local and prints machines that are on the same netowrk (I could not figure out how to stip the new line character from the end of the machine name so the formating is weird)
	for (int i = 0; i < count - 1; i++){
			for (int j = i + 1; j < count- 1; j++) {
					if (local_address(addresses[i],addresses[j])){
						printf("Machines %s and %s are on the same network\n", addresses[i].nickName, addresses[j].nickName);
					}
			}
	}
}
