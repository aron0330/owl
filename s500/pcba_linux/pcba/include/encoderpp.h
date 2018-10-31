
#ifndef ENCODERPP_H
#define ENCODERPP_H

// #include "audiopp_dev.h"
#include "vad_detect.h"
#include "denoise.h"

#ifdef _WIN32
#include <stdlib.h>
#include <string.h>
#define actal_malloc   malloc
#define actal_free     free
#define actal_memset   memset

typedef __int64 int_64;

#define  max_energy    (0x80000000000000)  

#else

typedef long long int_64;
extern void *actal_malloc(int);
extern void actal_free(void *);
extern void *actal_memset(void *, int, int);

#define  max_energy    (0x80000000000000LL)  

#endif

#ifndef NULL
#define NULL 0
#endif

typedef struct
{
	int   energy_enable;        //�Ƿ�֧�����������
	int   adc_enable;           //�Ƿ�֧��adc����

	int   avr_enable;           //�Ƿ�֧�����أ� 
	int   fenqu_enable;         //�Ƿ�֧���Զ�������
	
	int   agc_enable;           //�Ƿ�֧���Զ��������棬 
	int   denoise_enable;       //�Ƿ�֧�ֽ��룬 

	int   gain_enable;          //�Ƿ�֧��¼������

	int   sample_rate;          //��ǰ������
	int   adc_channels;         //ʵ����������������
	int   encoder_channels;     //��������Ҫ��������
    int   encoder_frame_len;    //��ǰ������Ҫ����������֡��
    int   adc_frame_len;        //��������֡��          
	
    int   energy;               //ȡ�������ݵ�ǰ512�����������õ�������

    int   vad_mode;             //¼��ģʽ, 0:����¼��, 1:����ģʽ, 2:�Զ�����
    int   vad_level;            //������⼶������ȷ������ֵ��Ϊ0��ʾ���ó�ʼ¼��������ƽ��ֵ����Ϊ0��-0.5dBһ��   
	int   vad_delay;            //��⵽�������ӳ�һ��ʱ��Ŵ�����λms

    int   agc_level;            //�Զ��������漶��, Ϊ0��ʾ�ر� 
    int   denoise_level;        //���뼶��Ϊ0��ʾ�ر�

   	int   input_gain;           //¼���������ã���λ֮��ĵ���
	int   input_shift;          //¼���������ã���Ҫ��λ�ĸ���

	int   need_adc_flag;         //�Ƿ���Ҫ�µ�ADC����  
    
	VAD_State * vad_st;
	int   last_vad_flag;

	int  *adcin_left;            //encpp���ڻ���adc�������������ݵ�buffer
	int  *adcin_right;           //encpp���ڻ���adc�������������ݵ�buffer

	int  *denoiseout_left;       //encpp���ڻ���denoise��������������ݵ�buffer
	int  *denoiseout_right;      //encpp���ڻ���denoise��������������ݵ�buffer

	DenoiseInterface *denoise_IF;
	int  adc_new_flag;
} Encoderpp_state;

int  sat16(int pcm_in);
void  sat16_4(int * in_ptr, short * out_ptr, int length);
int  cal_energy(short *pcm_in, int pcm_num, int channel);
int  set_energy_out(int energy_in);


#endif



