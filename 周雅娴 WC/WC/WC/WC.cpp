
#include <stdio.h>
#include <string.h>


int *getCharNum(char *filename, int *totalNum);
int main(){
    char filename[30];
    // totalNum[0]: ������  totalNum[1]: ���ַ���  totalNum[2]: �ܵ�����
    int totalNum[3] = {0, 0, 0};
    printf("Input file name: ");
    scanf("%s", filename);
    if(getCharNum(filename, totalNum)){
        printf("Total: %d lines, %d words, %d chars\n", totalNum[0], totalNum[2], totalNum[1]);
    }else{
        printf("Error!\n");
    }
    return 0;
}

int *getCharNum(char *filename, int *totalNum){
    FILE *fp;  // ָ���ļ���ָ��
    char cache[1005];  //���������洢��ȡ����ÿ�е�����
    int cacheLen;  // ��������ʵ�ʴ洢�����ݵĳ���
    int i;  // ��ǰ�����������ĵ�i���ַ�
    char c;  // ��ȡ�����ַ�
    int isLastBlank = 0;  // �ϸ��ַ��Ƿ��ǿո�
    int charNum = 0;  // ��ǰ�е��ַ���
    int wordNum = 0; // ��ǰ�еĵ�����
    if( (fp=fopen(filename, "rb")) == NULL ){
        perror(filename);
        return NULL;
    }
    printf("line   words  chars\n");
    // ÿ�ζ�ȡһ�����ݣ����浽cache��ÿ�����ֻ����1000���ַ�
    while(fgets(cache, 1003, fp) != NULL){
        cacheLen = strlen(cache);
        // ����������������
        for(i=0; i<cacheLen; i++){
            c = cache[i];
            if( c==' ' || c=='\t'){  // �����ո�
                !isLastBlank && wordNum++;  // ����ϸ��ַ����ǿո���ô��������1
                isLastBlank = 1;
            }else if(c!='\n'&&c!='\r'){  // ���Ի��з�
                charNum++;  // ����Ȳ��ǻ��з�Ҳ���ǿո��ַ�����1
                isLastBlank = 0;
            }
        }
        !isLastBlank && wordNum++;  // ������һ���ַ����ǿո���ô��������1
        isLastBlank = 1;  // ÿ�λ�������Ϊ1
        // һ�н������������ַ������ܵ�������������
        totalNum[0]++;  // ������
        totalNum[1] += charNum;  // ���ַ���
        totalNum[2] += wordNum;  // �ܵ�����
        printf("%-7d%-7d%d\n", totalNum[0], wordNum, charNum);
        // ���㣬����ͳ����һ��
        charNum = 0;
        wordNum = 0;
    }
    return totalNum;
}
