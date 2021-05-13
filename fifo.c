
void fifo(int A[],int T[],int P[],int n){
   for(int i=0;i<n-1;i++){
        if(A[i]>A[i+1]){
            int tmp=A[i];
            int tmp2=T[i];
            int tmp3=P[i];
            A[i]=A[i+1];
            T[i]=T[i+1];
            P[i]=P[i+1];
            A[i+1]=tmp;
            T[i+1]=tmp2;
            P[i+1]=tmp3;
        }
    }
    sauter();
    printf("Proc Arriver Traitement\n");
    for(int i=0;i<n;i++){
        printf("P%d",P[i]);
        for(int y=0;y<T[i];y++){
            printf(".");
        }

    }

}



void RR(int A[], int T[],int P[], int n){
int notFinish=0;
printf("\nEntrer le nombre de quantum\t");
    int q;
    scanf("%d",&q);
    while(notFinish!=1){
       for(int i=0;i<n;i++){
         if(T[i]>0){
            printf("P%d",P[i]);
            if(T[i]>q){
                for(int y=0;y<q;y++){
                    printf(".");
                }
                T[i]=T[i]-3;
            }else{
                for(int y=0;y<T[i];y++){
                    printf(".");
                }
                T[i]=0;
            }

        }
       }



       notFinish=1;
        for(int y=0;y<n;y++){
            if(T[y]>0){
                notFinish=0; break;
            }
        }

    }


}
