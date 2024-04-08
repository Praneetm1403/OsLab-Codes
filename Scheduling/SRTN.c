#include<stdio.h>
struct process{
    int pid;
    int burstime;
    int temp;
    int arrivaltime;
    int completiontime;
    int turnaroundtime;
    int waitingtime;
};
int main(){
    printf("Enter the no of processes:");
    int n;
    scanf("%d",&n);
    struct process processes[n];
    for(int j=0;j<n;j++){
        printf("Enter pid burst time and arrival time:");
        scanf("%d %d %d",&processes[j].pid,&processes[j].burstime,&processes[j].arrivaltime);
        processes[j].temp=processes[j].burstime;
    }
    for(int j=0;;j++){
        int min=10000,index=-1;
        for(int k=0;k<n;k++){
            if((processes[k].arrivaltime<=j)&&(processes[k].temp!=0)){
                if(processes[k].temp<min){
                    min=processes[k].temp;
                    index=k;
                }
            }
        }
        if(index==-1){
            break;
        }
        processes[index].temp--;
        if(processes[index].temp==0){
            processes[index].completiontime=j+1;
            processes[index].turnaroundtime=processes[index].completiontime-processes[index].arrivaltime;
            processes[index].waitingtime=processes[index].turnaroundtime-processes[index].burstime;
        }
    }
    printf("pid AT BT TAT WT\n");
    float averagewaitingtime=0,averageturnaroundtime=0;
    for(int j=0;j<n;j++){
        printf("%d %d %d %d %d\n",processes[j].pid,processes[j].arrivaltime,processes[j].burstime,processes[j].turnaroundtime,processes[j].waitingtime);
        averagewaitingtime=averagewaitingtime+processes[j].waitingtime;
        averageturnaroundtime=averageturnaroundtime+processes[j].turnaroundtime;  
    }
    printf("Average waiting time=%f\n",averagewaitingtime/n);
    printf("Average turnaround time=%f\n",averageturnaroundtime/n);
}
