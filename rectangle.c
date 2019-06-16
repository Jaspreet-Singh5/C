#include <stdio.h>
#include <math.h>

void line();

main(){
	int cordinates[4][2];
	int i,j,area, side[4];
	line();
	for(i=0;i<4;i++){
		printf("Enter the value of x for no.%d cordinate: ",i+1);
		scanf("%d",&cordinates[i][0]);
		printf("Enter the value of y for no.%d cordinate: ",i+1);
		scanf("%d",&cordinates[i][1]);
		line();
	}
	
	for(i=0;i<4;i++){
		printf("%d,%d\n",cordinates[i][0],cordinates[i][1]);
	}
	line();
	
	for(i=0;i<4;i++){
		if(i+1==4)
			side[i] = sqrt(pow(cordinates[i][0] - cordinates[0][0],2) + pow(cordinates[i][1] - cordinates[0][1],2));	
		else
		side[i] = sqrt(pow(cordinates[i][0] - cordinates[i+1][0],2) + pow(cordinates[i][1] - cordinates[i+1][1],2));	
	}
	printf("%d %d %d %d \n",side[0],side[1],side[2],side[3]);
	
	if(side[0] == side[2] && side[1] == side[3]){
		area= side[0]*side[1];
		line();
		printf("Area: %d\n",area);
		line();	
	}
	
	else{
		line();
		printf("Wrong cordinates!!\n");
		line();
	}
	
}

// line
void line(){
	int i;
	for(i=0;i<100;i++){
		printf("=");
	}
	printf("\n");
}
