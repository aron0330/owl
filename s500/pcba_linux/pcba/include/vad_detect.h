
#ifndef VAD_DETECT_H
#define VAD_DETECT_H

typedef struct VAD_State
{
	int   vad_flag;             //0��ʾ��ǰ�������Σ�1��ʾ��ǰ��������

    int   vad_threshold;        //���ػ����ģʽ�еľ����������ֵ  
	
	int   vad_delay;            //���ػ����ģʽ�еľ�������ӳ�ʱ��

	int   threshold_mode;       //ȷ������ֵ�ķ�ʽ��Ϊ0��ʾ��AP�趨��Ϊ1��ʾȡ��ʼ16֡����ֵ��ƽ��

	int   frame_count;          //��¼��ǰ֡��
	int   noise_count;
	int   delay_count;

	int   threshold_updata;  //�ж�Ϊ������ʱ���Ƿ���Ҫ����������������

	int   voice_judge;          

}VAD_State;

void vad_init(VAD_State * vad_ptr);
void set_vad_delay(VAD_State * vad_ptr, int time, int rate, int frame_size);
void set_vad_threshold(VAD_State * vad_ptr, int level);
void get_VAD_Flag(VAD_State * vad_ptr, int energy);


#endif

