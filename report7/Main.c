#include <stdio.h>

int func_array(int array[],int size){
    int ans[size];
    int kaisuu = 1;
    int max = 0;
    int duplication=0;
    for(int i=0; i<size; i++){            
        if(max<array[i]){
            max=array[i];
            ans[0] = max;
        }
    }
    while(kaisuu<size){
        
        int base = 0;
        for(int i=0; i<size; i++){
            if(array[i]>=base && max>array[i]){
                base=array[i];
                ans[kaisuu]=array[i];
            }
            if(array[i]==max){
                duplication+=1;
            }
        }
        

        if(duplication>=2){
            for(int t=0; t<duplication-1; t++){
                ans[kaisuu+t]=max;
            }
            kaisuu += duplication-1;
            duplication = -duplication;

        }else{
            kaisuu+=1;
            max = base;
            duplication = 0;
        }
    }
    
    printf("scores =");
    for(int i=0; i<size; i++){
        printf("%d ",array[i]);
    }

    printf("\nresult =");
    for(int i=0; i<size; i++){
        printf("%d ",ans[i]);
    }
}


int main(){
    const int SIZE = 5; //定数として配列のサイズを宣言                          
    int scores[SIZE] = {1, 22, 1,22,22};
    func_array(scores,SIZE);
    return 0;
}