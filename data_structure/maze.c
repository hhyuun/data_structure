#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 20
#define MAZE_SIZE 6

typedef struct{
	short r;
	short c;
}element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1',}
};

element here = {1,0}, entry = {1,0};
element path[MAX_STACK_SIZE];  // 경로를 저장 배열
int path_index = 0;  // 경로 인덱스

void push_loc(StackType *s, int r, int c){
	if(r<0 || c<0) return;
	if(maze[r][c] != '1' && maze[r][c] != '.'){
		element tmp;
		tmp.r =r;
		tmp.c = c;
		push(s, tmp);
	}
}

// 미로를 화면에 출력
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]){
	printf("\n");
	for(int r=0; r<MAZE_SIZE; r++){
		for(int c=0; c<MAZE_SIZE; c++){
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

// 경로를 출력
void print_path() {
    printf("경로: ");
    for(int i = 0; i < path_index; i++) {
        printf("(%d,%d) ", path[i].r, path[i].c);
    }
    printf("\n");
}

int main(void){
	int r,c;
	StackType s;

	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x'){
		r = here.r;
		c = here.c;
		maze[r][c] = '.';

		path[path_index++] = here;  // 현재 위치를 경로에 저장
        maze_print(maze);
        print_path();  // 경로를 출력

		push_loc(&s, r-1, c);
		push_loc(&s, r+1, c);
		push_loc(&s, r, c-1);
		push_loc(&s, r, c+1);

		if(is_empty(&s)){
			printf("실패 \n");
			return 0;
		}
		else
			here = pop(&s);
	}
	path[path_index++] = here;  // 도착점
    printf("성공\n\n");
    print_path();  // 최종 경로를 출력

	return 0;
	
}