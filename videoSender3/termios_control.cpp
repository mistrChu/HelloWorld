#include "termios_control.h"
using namespace std;
char my_getch() 
{
        int c=0;  int res=0;
        struct termios org_opts, new_opts;
        //�����ն�ԭ������
        res=tcgetattr(STDIN_FILENO, &org_opts);
        assert(res==0);
        //���������ն˲���
        memcpy(&new_opts, &org_opts, sizeof(new_opts));
        new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
        c=getchar();////������ȡ����jian  
        //�ָ��ж�����
        res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
		assert(res==0);
        return c; 
}



