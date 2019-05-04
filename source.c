#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char str[10001];//string 선언
	int i,j;
	int count = 0, max_count=0,max_count_count=0;//count는 개별 알파벳, max_count는 그 중에서 가장 큰 것, max_count가 총 몇 개 있는가?
	char max_letter[1];

	scanf("%s", str);//이제 문자열 받는거는 기억할 수 있지?

	for (i = 0; i < str[i]; i++) {
		if (str[i] > 97)//소문자이면 모두 대문자로 바꿔주기
			str[i] -= 32;
	}

	for (i = 0; i < str[i]; i++) {//반복 중첩문을 두어 하나하나씩 비교
		for (j = 0; j < str[j]; j++) {//i부터 하나하나 1부터 끝까지 같은 애가 있나 비교해줌. 
			if (j < i) {//뒤에 이미 count된 똑같은 알파벳을 가진 애가 나온다면 비교해주지마.
				if (str[i] == str[j])
					break;
			}
			if (str[i] == str[j])
				count++;
		}
			//개별로 count가 끝나고 난 후.
			if (count > max_count) {//만약 현재 max_count보다 큰 것이 있다면
				max_count = count;//max count에 바꿔줌
				max_letter[0] = str[i];//문자도 넣어준다.
				max_count_count = 0;//1,1 끼리 비교되고 있었을 때 더 큰 놈이 나타난다면 reset 시켜준다.(중복된 놈이 없다.)
			}
			else if (max_count == count) {//max_count랑 똑같다면? 빈도수가 똑같은 애들이 더 있다는 뜻.
				max_count_count++;
			}
			count = 0;	
	}

	if (max_count_count > 0) {
		printf("?\n");
	}
	else {
		printf("%c\n", max_letter[0]);
	}
}