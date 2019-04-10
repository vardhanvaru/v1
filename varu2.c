#include<stdio.h>

struct data
  { 
int at;
    int bt;
    int et;
    int status;
  };

int lwbt(int time,int np,struct data *processes)
{
 int i,lbt,lbti=-1,onlyonce=0;
  for(i=0;i<np;i++)
    {
if((processes+i)->at<=time)
      {
if((processes+i)->status==0 & onlyonce==0)
         {
lbt=(processes+i)->bt;
          lbti=i;
          onlyonce=1;
         }
       else
         {
if((processes+i)->status==0)
           { 
if (((processes+i)->bt) > lbt)
               {
lbt=(processes+i)->bt;
                lbti=i;
}
           }
         }
       }
     }
   return lbti;
}

void main()
{ 
int np,i,npd=0,lbti;
  printf("enter the no. of process");
  scanf("%d",&np);

  struct data processes[np];
  for(i=0;i<np;i++)
  { 
printf("enter the arrival time");
    scanf("%d",&processes[i].at);
    printf("enter the burst time");
    scanf("%d",&processes[i].bt);
    if(processes[i].at<1)
      {
processes[i].status=1;
       processes[i].et=-1;
       npd++;}
    else
     processes[i].status=0;
  }
  int time=1;
  while(npd<np)
  {
 lbti=lwbt(time,np,&processes[0]);
    if(lbti==-1)
      time=time+1;
    else
     {
processes[lbti].et=time;
     processes[lbti].status=1;
     time=time+processes[lbti].bt+2;
     npd=npd+1;}
  }
  double avg_wt=0,avg_tat=0;
  printf("process the waiting time\t the turnaround time\n");
for(i=0;i<np;i++)
 {
 if (processes[i].et!=-1)
   {
   		printf("%d \t%d\t\t\t%d\n",i,(processes[i].et-processes[i].at),(processes[i].et-processes[i].at+processes[i].bt));
		avg_wt=avg_wt+(processes[i].et-processes[i].at);
		avg_tat=avg_tat+(processes[i].et-processes[i].at+processes[i].bt);
	}
   else
   printf("for process %d it is an error\n",i);
 }
printf("avg turn around time is %lf\n",avg_tat/np);
printf("avg waiting time is %lf\n",avg_wt/np);

}  
 
 
 

