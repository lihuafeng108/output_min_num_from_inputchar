#include <stdio.h>
#include <string.h>

struct record
{
    char num;    //<lihf> ����
    int  count;  //<lihf> ���ֵĴ���
};

//<lihf> �ҳ�����ֵ��С���±꣬����¼�����������
static int fine_min_num_and_count(char const *array, int len, struct record *result)
{
    int min = 999999;
    
    for(int i=0; i<len; i++)
    {
        if(min > array[i])
        {
            min = array[i];
            
            result->num = i;
            result->count = min;
        }
    }
}

static int output_min_num(char const *src, int len)
{
    char signers[10] = {0};  //<lihf> ���src��¼���ַ����ڣ�����signers[]���¼��Ӧ�±�����ֳ��ֵĴ�����0��ʾ��
    char tmp;
    int ret_num = -1;
    
    if( (NULL == src) || (len <=0) )
    {
        printf("�����������");
        return -1;
    }
    
    for(int i=0; i<len; i++)
    {
        if( ('0' <= src[i]) && (src[i] <= '9') )
        {
            tmp = src[i] - '0';
            signers[tmp]++;
        }
    }
    
    struct record result;
    fine_min_num_and_count(signers, 10, &result);
    
    //(1) ��0���ֵĸ���Ϊ0��ʱ��
    if( (0 == result.num) &&  (0 == result.count) )
    {
        struct record result_tmp;
        fine_min_num_and_count(signers+1, 9, &result_tmp);
        if(0 == result_tmp.count)
        {//����ĳ������Ҳ����0��
            
            ret_num = result_tmp.num+1;
        }
        else
        {
            ret_num = 1*10*(result.count+1);
        }
    }
    else
    {//�����ֵ���ֵĸ���Ϊ0
        ret_num = result.num*(result.count+1);
    }
    
    return ret_num;
}

int main(void)
{
    int ret;
    char input[1024] = {0};
    int slen;
    
    scanf("%c", input);
    slen =  strlen(input);
    
    ret = output_min_num(input, slen);
    if( ret > 0)
    {
        printf("%d\n", ret);
    }
     
    return 0;
}