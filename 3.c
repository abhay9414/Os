#include<stdio.h>
int main()
{
  int remain,flag=0,ts;
  int i,j,n,time;
  int sum_wait=0,sum_taround=0,at[10],bt[10],rt[10],p[10];
  printf("Enter input of processes for program for round robin scheduling in c: ");
  scanf("%d",&n);
  remain=n;
  for(i=0;i<n;i++)
  {
    printf("Enter priority, arrival time and burst time for Process P%d :",i+1);
    scanf("%d",&p[i]);
    scanf("%d",&at[i]);
    scanf("%d",&bt[i]);
    rt[i]=p[i];
  }
  printf("Enter time slice for os algorithm in c");
  scanf("%d",&ts);
  printf("\n \t Process turnaround time and waiting time \n");
  for(time=0,i=0;remain!=0;)
  {
    if(rt[i]<=ts && rt[i]>0)
    {
      time+=rt[i];
      rt[i]=0;
      flag=1;
    }
    else if(rt[i]>0)
    {
      rt[i]-=ts;
      time+=ts;
    }
    if(rt[i]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
      sum_wait+=time-at[i]-bt[i];
      sum_taround+=time-at[i];
      flag=0;
    }
    if(i==n-1)
      i=0;
    else if(at[i+1]<=time)
      i++;
    else
      i=0;
  }
  printf("\nAvg waiting time program for round robin = %f\n",sum_wait*1.0/n);
  printf("Avg sum_taround = %f",sum_taround*1.0/n);
  return 0;
}
