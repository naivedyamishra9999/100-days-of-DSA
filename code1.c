#include <stdio.h>
int main(){
    int n, pos, x;
    int arr[100];
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &pos);
    scanf("%d", &x);
    pos = pos - 1;
    for(int i = n; i > pos; i--){
        arr[i] = arr[i - 1];    
    }
    arr[pos] = x;
    for(int i = 0; i <= n; i++){
        printf("%d", arr[i]);
    }
    return 0;
}