#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char str[10001];//string ����
	int i,j;
	int count = 0, max_count=0,max_count_count=0;//count�� ���� ���ĺ�, max_count�� �� �߿��� ���� ū ��, max_count�� �� �� �� �ִ°�?
	char max_letter[1];

	scanf("%s", str);//���� ���ڿ� �޴°Ŵ� ����� �� ����?

	for (i = 0; i < str[i]; i++) {
		if (str[i] > 97)//�ҹ����̸� ��� �빮�ڷ� �ٲ��ֱ�
			str[i] -= 32;
	}

	for (i = 0; i < str[i]; i++) {//�ݺ� ��ø���� �ξ� �ϳ��ϳ��� ��
		for (j = 0; j < str[j]; j++) {//i���� �ϳ��ϳ� 1���� ������ ���� �ְ� �ֳ� ������. 
			if (j < i) {//�ڿ� �̹� count�� �Ȱ��� ���ĺ��� ���� �ְ� ���´ٸ� ����������.
				if (str[i] == str[j])
					break;
			}
			if (str[i] == str[j])
				count++;
		}
			//������ count�� ������ �� ��.
			if (count > max_count) {//���� ���� max_count���� ū ���� �ִٸ�
				max_count = count;//max count�� �ٲ���
				max_letter[0] = str[i];//���ڵ� �־��ش�.
				max_count_count = 0;//1,1 ���� �񱳵ǰ� �־��� �� �� ū ���� ��Ÿ���ٸ� reset �����ش�.(�ߺ��� ���� ����.)
			}
			else if (max_count == count) {//max_count�� �Ȱ��ٸ�? �󵵼��� �Ȱ��� �ֵ��� �� �ִٴ� ��.
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