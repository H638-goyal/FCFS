// first come first serve (with arrival time) program using array 
#include <stdio.h>
int main()
{   
    int n,temp=0,x ;
    printf("enter the number of process");
    scanf("%d",&n);
    int bt[n],at[n],tat[n],wt[n],ct[n],pid[n];
    float atat=0,awt=0;
    for(int i=0;i<n;i++)
    {
        printf("enter the arrival time");
        scanf("%d",&at[i]);
        pid[i]=i+1;
    }
    for(int i=0;i<n;i++)
    {
         printf("Enter the burst time");
        scanf("%d",&bt[i]);
    }
    printf("pid\t AT\t BT\t tat\t ");
    printf("\n");
    for(int i=0;i<n;i++)
    {
    printf("%d\t %d\t %d\t %d\t ",i+1,at[i],bt[i],tat[i]);
    printf("\n");
    }
    printf("after soting\n");
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n-i;j++)
        {
            if(at[j-1]>at[j])
            {
                temp=at[j];
                at[j]=at[j-1];
                at[j-1]=temp;
                temp=bt[j];
                bt[j]=bt[j-1];
                bt[j-1]=temp;
                temp=pid[j];
                pid[j]=pid[j-1];
                pid[j-1]=temp;
                
            }
        }
    }
    ct[0]=bt[0];
    for(int i=1;i<n;i++)
    {   
        if(ct[i-1]<at[i])
        {
            x = at[i]-ct[i-1];
                ct[i]=x+ct[i-1]+bt[i];           
        }
        else
         ct[i]= ct[i-1]+bt[i];
    }
    for(int i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        atat = atat+tat[i];
        awt = awt + wt[i];
    }
    printf("pid\t AT\t BT\t CT\t tat\t WT");
    printf("\n");
    for(int i=0;i<n;i++)
    {
    printf("%d\t %d\t %d\t %d\t %d\t%d",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    printf("\n");
    }
    atat = atat/n;
    awt = awt/n;
    printf("%.2f is the average turn around time\n",atat);
    printf("%.2f is the average waiting time\n",awt);
    printf("\n\n Harsh Goyal");

    return 0;
}


