#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,n;
	int burstTime[20],temp,j,arrivalTime[20],waitTime[20],turnAroundTime[20],ta=0,sum=1,ct[20];
	float avgWaitTime=0,avgArrivalTime=0,TurnAroundSum=0,WaitSum=0;
	printf(" -----------------Welcome to the Program of Shortest Job First Scheduling-----------------\n");
	printf("\nEnter the total number of processes  :");
	scanf("%d",&n);
	int process[n]; 
	for(i=0;i<n;i++)
	{	printf("\n------------------------------------------------------------------------------------");
		printf("\n\nEnter Details of Process : %d",i+1);
		printf("\n\n------------------------------------------------------------------------------------");
		printf("\nEnter the burst time of %d process :",i+1);
		scanf(" %d",&burstTime[i]);
		printf("\nEnter arrival time of %d process : ",i+1);
	   A:	scanf("%d",&arrivalTime[i]);
    		if(arrivalTime[i]==0)
 		{
 			printf("ERROR !! Arrival Time Should Not Be Zero");
 			printf("\nEnter arrival time of process %d : ",i+1);
  			goto A;
		 }
		process[i]=i;
	}
	 for(i=0;i<n;i++)						//Process are getting arranged according to the arrival	time
	{
		for(j=0;j<n;j++)
		{
			if(arrivalTime[i]<arrivalTime[j])
			{
				temp=process[j];
				process[j]=process[i];
				process[i]=temp;
				temp=arrivalTime[j];
				arrivalTime[j]=arrivalTime[i];
				arrivalTime[i]=temp;
				temp=burstTime[j];
				burstTime[j]=burstTime[i];
				burstTime[i]=temp;
			}
			else
			continue;
		}
	}
}
