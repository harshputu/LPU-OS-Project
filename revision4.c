#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,n;
	int burstTime[20],temp,j,arrivalTime[20],waitTime[20],turnAroundTime[20],ta=0,csum=1,completionTime[20],real=1,turnAroundtime1[20],completionTime1[20],large;
	float avgWaitTime=0,avgTurnTime=0,turnAroundSum=0,waitSum=0;
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
	waitTime[0]=0;
	for(i=0;i<n;i++)
	{	
		real=real+burstTime[i];
		turnAroundTime1[i]=real-arrivalTime[i];
		completitionT1[i]=turnAroundTime1[i]+arrivalTime[i];
		csum=csum+burstTime[i];
		turnAroundTime[i]=csum-arrivalTime[i];
		waitTime[i]=turnAroundTime[i]-burstTime[i];
		completionTime[i]=turnAroundTime[i]+arrivalTime[i];
		turnAroundSum=turnAroundSum+turnAroundTime[i];
		waitSum=waitSum+waitTime[i];
		csum=csum+2;
	}
	avgTurnTime=(turnAroundSum/n);
	avgWaitTime=(waitSum/n);
	int large=completionTime[0];
	for(i=1;i<n;i++)
	{
		if(large<completionTime[i])
		large=completionTime[i];
	}
	printf("---------------------------------------------------------------------------------------");
	printf("\n RESULT:-");
	printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around\t Completion " );
	for(i=0;i<n;i++)
	{
		printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d\t\t%d",process[i],burstTime[i],arrivalTime[i],waitTime[i],turnAroundTime[i],completionTime[i]);
	}
 	printf("\n\nAVERAGE WAITING TIME : %f",avgWaitTime);
	printf("\nAVERAGE TURN AROUND TIME : %f",avgTurnTime);
	printf("\nCOMPLETE EXECUTION TIME FOR ALL THE PROCESSES IS %d",large);
	return 0;
	

}
