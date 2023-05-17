#include<stdio.h>
void findWaitingTime(int n,int bt[], int wt[]){
	wt[0] = 0;
	for (int i = 1; i < n ; i++ )
		wt[i] = bt[i-1] + wt[i-1] ;
}
void findTurnAroundTime( int processes[], int n,int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}
void findavgTime( int processes[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;
	findWaitingTime(n, bt, wt);
	findTurnAroundTime(processes, n, bt, wt, tat);
	printf("Processes Burst time Waiting time Turn around time\n");
	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf(" %d ",(i+1));
		printf("\t\t%d ", bt[i] );
		printf("\t\t%d",wt[i] );
		printf("\t\t%d\n",tat[i] );
	}
	int s=(float)total_wt / (float)n;
	int t=(float)total_tat / (float)n;
	printf("Average waiting time = %d",s);
	printf("\n");
	printf("Average turn around time = %d ",t);
}
int main()
{
	int processes[100];
	int n;
	int burst_time[100];

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the process id %d: ",i);
        scanf("%d",&processes[i]);
        printf("Enter the burst time %d: ",i);
        scanf("%d",&burst_time[i]);
    }
    

	findavgTime(processes, n, burst_time);
	return 0;
}
