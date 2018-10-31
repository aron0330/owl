#include "case.h"

/*
typedef struct {
    unsigned int type;			//�Զ�or�ֶ�
    unsigned int index;       	//����
	unsigned int position;		//λ��
	int enable;					//�Ƿ����
    char name[20];         		//��������
	char dev_name[60];			//��������			
	char nod_path[60];			//����
    char init_string[50];       
	char pass_string[100];
	char fail_string[50];
	IDirectFBSurface *surface;
}case_t;
*/

void test_flashlight(case_t *flashlight_case)
{
	int interval_time = 1000000;
	int light_time = 1000000;
	char i;
	char command[100];
	if(flashlight_case->enable)
	{
		while(true)
		{
			strcpy(command, "/sys/bus/platform/devices/flashlight.0/status");
			if(!is_nod_exists(command))
			{
				printf("can't operate flashlight nod\n");
				return;
			}
			strcpy(command, "echo 0 > /sys/bus/platform/devices/flashlight.0/status");
			printf("command = %s\n", command);
			pcba_system(command);
			
			direct_thread_sleep(light_time);
			
			strcpy(command, "echo 1 > /sys/bus/platform/devices/flashlight.0/status");
			printf("command = %s\n", command);
			pcba_system(command);
			
			direct_thread_sleep(interval_time);
		}
	}
}
	
