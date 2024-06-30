// 괄호검사
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 5

typedef int element;

typedef struct{
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType *s){
    s->top = -1;
}

int is_empty(StackType *s){
    return (s->top == -1);
}

int is_full(StackType *s){
    return (s->top == MAX_STACK_SIZE -1);
}

void push(StackType *s, element item){
    if(is_full(s)){ // 예외처리. 배열이 꽉 찼니 물어봐야함
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s-> data[++(s->top)] = item; // ++보다 s->top 이 우선이라 괄호 필요없지만 명확하게 하기 위해 했음
}

// element pop(StackType *s){ // 피크 함수
//     if(is_empty(s)){
//         fprintf(stderr, "스택 공백 에러\n");
//         return;
//     }
//     else return s->data[++(s->top)--];
// }

element pop(StackType *s){ // 삭제 함수
    if(is_empty(s)){
        printf(stderr, "스택 공백 에러\n");
        exit(1); // 프로그램 끝내버리기. exit함수는 standard 라이브러리에 포함되어 있음. 오류없이 사용하기 위해 <stdlib.h> include
    }
    else return s->data[s->top];
}

void print_stack(StackType *s){
    for(int i = s->top; i >=0; i--){
        printf("%3d ", s->data[i]);
    }
}

int check_matching(const char* in){
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in);
    init_stack(&s);

    for(int i=0;i<n;i++){
        ch = in[i];

        switch(ch){ // 이거 코드 완성해오기 괄호검사 . 게시판에 올리기 . 실행결과, 코드. 옳바른 검사, 틀린 검사 등등 롤리기
            case '(': case '{': case '[':
            push (&s, ch); break;

            case ')': case '}': case ']':
            ; break;
        }
    }

}

int main(void){
    char *p = "{A[i+1)] = 0;}";
    //char *p = "[f(i+2})=0;]";


    if(check_matching(p) == 1)
        printf("%s: 괄호검사 성공\n", p);
    else
        printf("%s : 괄호검사 실패\n", p);
        
    return 0;
}