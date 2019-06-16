#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process {
	int pid;
	int bt;
	int art;
};

void findAvg(struct Process [], int);
void findTurnAroundTime(struct Process proc[], int n, 
                        int wt[], int tat[]);
                        
main() {
	struct Process p[] = { { 1, 6, 1 }, { 2, 8, 1 }, 
                    { 3, 7, 2 }, { 4, 3, 3 } };
	int n = sizeof(p)/sizeof(p[0]);
	
	findAvg(p,n);
}

void findAvg(struct Process p[], int n) {
	int tat[n], wt[n];
	int total_tat=0, total_wt=0;
	int i, j,minm=5000;
	int comp=0,t=0, shortest=0, check=0;
	int rt[n], finishT;
	
	for(i=0;i<n;i++)
		rt[i]=p[i].bt;
	
	while(comp!=n) {
		for(i=0;i<n;i++) {
			if(p[i].art<=t && rt[i]<minm && rt[i]>0) {
				minm=rt[i];
				shortest=i;
				check=1;
			}
		}
		
		if(check==0) {
			t++;
			continue;
		}
			
		rt[shortest]--;
		
		minm=rt[shortest];
		if(minm==0)
			minm=5000;
		
		if(rt[shortest] == 0) {
			comp++;
			check=0;
			
			finishT=t+1;
			
			wt[shortest]=finishT-p[shortest].bt-p[shortest].art;
			
			if(wt[shortest]<0)
				wt[shortest]=0;
		}
		
		t++;
	}
	
	findTurnAroundTime(p, n, wt, tat);
	
	printf("Process Id		Burst Time		Arrival Time		Waiting Time		Turnaround Time\n");
	for(i=0;i<n;i++) {
		printf("%d \t\t\t%d \t\t\t%d \t\t\t%d \t\t\t%d\n",p[i].pid,p[i].bt,p[i].art,wt[i],tat[i]);
	}
	
	for(i=0;i<n;i++) {
		total_wt += wt[i];
		total_tat += tat[i];
	}
	
	printf("\nAverage waiting time: %lf",(float)total_wt/(float)n);
	printf("\nAverage turnaround time: %lf",(float)total_tat/(float)n);
}

void findTurnAroundTime(struct Process proc[], int n, 
                        int wt[], int tat[]) 
{ 
	int i;
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (i = 0; i < n; i++) 
        tat[i] = proc[i].bt + wt[i]; 
} 
