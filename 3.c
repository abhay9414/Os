#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

float CPU_UTIL();
int n;
int bt[10],i,at[10],pr[10];
void bust_time()
{
	printf("\n   Enter the Bust Time:\n\n");
	printf("\t PROCESS \t\tBURST_TIME\n\n");
	
	for(i=0;i<n;i++)
	{
		printf("\t   P%d  \t\t\t  ",i);
		scanf("%d",&bt[i]);
	}
	
}

void arrival_time()
{ 
    system("cls");
	printf("\n\tEnter the Arrival Time:\n\n");
	printf("\t PROCESS \t  BURST_TIME \t  ARRIVAL TIME \n\n");
	
	for(i=0;i<n;i++)
	{
		printf("\t   P%d\t\t    %d   \t   \t  ",i,bt[i]);
		scanf("%d",&at[i]);
	}
	
}

void priority()
{ 
    system("cls");
	printf("\n\tEnter the Priority:\n\n");
	printf("\t PROCESS \t  BURST_TIME \t    ARRIVAL TIME \t  PRIORITY\n\n");
	
	for(i=0;i<n;i++)
	{
		printf("\t   P%d \t \t     %d   \t \t    %d       \t   ",i,bt[i],at[i]);
		scanf("%d",&pr[i]);
	}
	
}

void *pro(int * loc)
{ printf("\n\t''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\t");
printf("\n       \t \tPROCESS %d IS BEING EXECUTED \t\n\n",*loc);
printf("\t''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\t\n");
//printf("\t WITH BUST TIME := %d  WITH ARRIVAL TIME := %d\n\n ",bt[*loc],at[*loc]);
}


int prio(float cpu)
{
    return (cpu/2)+60;
}

float CPU_UTIL()
{
    long double a[4], b[4], loadavg;
    FILE *fp;
    char dump[50];

    fp = fopen("/proc/stat","r");
        fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&a[0],&a[1],&a[2],&a[3]);
        fclose(fp);
        sleep(1);

        fp = fopen("/proc/stat","r");
        fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&b[0],&b[1],&b[2],&b[3]);
        fclose(fp);

        loadavg = ((b[0]+b[1]+b[2]) - (a[0]+a[1]+a[2])) / ((b[0]+b[1]+b[2]+b[3]) - (a[0]+a[1]+a[2]+a[3]))*100;
        //printf("The current CPU utilization is : %Lf\n",loadavg);

        return loadavg;
}


int main()
{ 

printf("\n\tEnter the number of process\t\n");
scanf("%d",&n);
	bust_time();
	arrival_time();
	priority();
	int i,j;
	 
	 
	
	system("cls");
    pthread_t v[n];
    int priority[n];
    for(j=0;j<n;j++)
    {

      int  temp=10000,loc;
    for(i=0 ;i<n;i++)
    {
    priority[i]=prio(CPU_UTIL());
    
    if(temp>priority[i])
    {
        temp=priority[i];
        loc=i+1;
    }

    printf("\n\t%d ||  \t PROCESS %d    || \t PRIORITY %d\n",i+1,i+1,priority[i]);
    }

    pthread_create(&v[loc],NULL,pro,(void*)&loc);

    pthread_join(v[loc],NULL);
    
    }


    return 0;
}

