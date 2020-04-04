#include<iostream> 
using namespace std; 
int sjf[20][10]; 
  
void swap(int *a,int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
void sort_arrival_time(int n,int sjf[20][10]) 
{ 
    for(int j=0;j<n;j++) 
    { 
        for(int i=0;i<n-j-1;i++) 
        { 
            if(sjf[i][1] > sjf[i+1][1]) 
            { 
                for(int k=0;k<5;k++) 
                { 
                    swap(sjf[i][k], sjf[i+1][k]); 
                } 
            } 
        } 
    } 
} 
  
void completion_time(int n,int sjf[][10]) 
{ 
    int tem,value; 
    sjf[0][3] = sjf[0][1] + sjf[0][2]; 
    sjf[0][5] = sjf[0][3] - sjf[0][1]; 
    sjf[0][4] = sjf[0][5] - sjf[0][2]; 
      
    for(int j=1;j<n;j++) 
    { 
        tem=sjf[j-1][3]; 
        int low = sjf[j][2]; 
        for(int i=j;i<n;i++) 
        { 
            if(tem>=sjf[i][1]&&low >=sjf[i][2]) 
            { 
                low = sjf[i][2]; 
                value = i; 
            } 
        } 
        sjf[value][3] = tem+sjf[value][2]; 
        sjf[value][5] = sjf[value][3] - sjf[value][1]; 
        sjf[value][4] = sjf[value][5] - sjf[value][2]; 
        for(int k=0; k<6; k++) 
        { 
            swap(sjf[value][k], sjf[j][k]); 
        } 
    } 
} 
  
int main() 
{ 
    int n, temp; 
      
    cout<<"Enter number of Process: "; 
    cin>>n; 
    for(int i=0;i<n;i++) 
    { 
       cout<<"...Process "<<i+1<<"...\n"; 
        cout<<"enter process id,arrval time,burst time:";
        cin>>sjf[i][0]>>sjf[i][1]>>sjf[i][2];
    } 
    cout<<"Process ID\tArrival Time\tBurst Time\n"; 
    for(int i=0;i<n;i++) 
    { 
        cout<<sjf[i][0]<<"\t\t"<<sjf[i][1]<<"\t\t"<<sjf[i][2]<<"\n"; 
    } 
      
    sort_arrival_time(n,sjf); 
    completion_time(n,sjf); 
    cout<<"Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n"; 
    int comp_time=0;
    for(int i=0;i<n;i++) 
    { 
    comp_time+=sjf[i][5];
        cout<<sjf[i][0]<<"\t\t"<<sjf[i][1]<<"\t\t"<<sjf[i][2]<<"\t\t"<<sjf[i][4]<<"\t\t"<<sjf[i][5]<<"\t\n"; 
    } 
    float total_wait_time=0,total_turnaround_time=0;
for(int i=0;i<n;i++)
{ 
total_wait_time+=sjf[i][4];
total_turnaround_time+=sjf[i][5];
}
cout<<"avg_wait_time="<<total_wait_time/n<<endl;
cout<<"avg_turnaround_time="<<total_turnaround_time/n;
}
