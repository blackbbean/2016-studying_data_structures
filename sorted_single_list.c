#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}NODE;

int main()
{
    NODE *head=NULL,*tmp,*prev,*p;
    int i,n,x;
    
    printf("갯수 입력 : ");
    scanf("%d",&n);
    
    printf("%d개의 정수를 입력하세요\n",n);
    
    for(i=0;i<n;i++)
    {
        printf("input data %d : ",i+1);
        scanf("%d",&x);
        
        tmp=(NODE*)malloc(sizeof(NODE));
        tmp->data=x;
        tmp->link=NULL;
        
        if(head == NULL) // 첫노드라면,
        {
            head=tmp;
        }
        else
        {
            if(x < head->data) // 데이터가 head가 가진 값보다 작다면
            {
                tmp->link=head;
                head=tmp; // 새로들어온 노드가 head가 된다.
            }
            else
            {
                p=head;
                while(p != NULL && x > p->data)// 현재 값보다 큰값을 가진 노드를 찾는다.
                    
                {
                    prev=p; // 현재 노드를 저장
                    p=p->link;
                }
                // 검색이 완료된 이후 prev는 n보다 작은 값을
                // 가지고 prev->link 값은 n보다 큰값을 가진다.
                
                tmp->link=prev->link;
                prev->link=tmp; // 연결
            }
        }
    }
    
    p=head;
    
    printf("출력 : ");
    
    while(p != NULL) // 전체 출력
    {
        printf("%d-> ",p->data);
        p=p->link;
    }
    
    printf("\n");
    
    while(head != NULL) // 메모리 해제
    {
        p=head->link;
        free(head); 
        head=p; 
    } 
    
    return 0; 
} 
