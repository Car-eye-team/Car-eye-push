/*
 * Car eye ��������ƽ̨: www.car-eye.cn
 * Car eye ��Դ��ַ: https://github.com/Car-eye-team
 * CarEyeRtmpAPI.h
 *
 * Author: Wgj
 * Date: 2018-03-19 19:11
 * Copyright 2018
 *
 * CarEye RTMP������ӿ�ͷ�ļ�
 * ʵʱ��������ʱ��֧�����8��ͨ������
 */

#ifndef __CAREYE_PUSHER_H__
#define __CAREYE_PUSHER_H__

#include "CarEyeTypes.h"

// RTMP���������
#define CarEyeRTMPHandle void*

#ifdef __cplusplus
extern "C"
{
#endif

	/*
	* Comments: ʹ����Ч��Key����CarEye RTMP��������ע���Ա�ʹ��, ʹ�ñ�ϵͳǰ�������ע���������ʹ��
	* Param key: ��Ч����Կ
	* Param packName: ���Androidϵͳ��Ӧ�ó������
	* @Return int CAREYE_NOERROR: �ɹ�, ���ؽ���ο�CarEyeError
	*/
#ifdef ANDROID
	CE_API int CE_APICALL CarEyeRTMP_Register(char* key, char* packName);
#else
	CE_API int CE_APICALL CarEyeRTMP_Register(char* key);
#endif

	/*
	* Comments: ע������״̬�¼�
	* Param event: ��ȡ����״̬�Ļص�����
	* @Return None
	*/
	CE_API void CE_APICALL CarEyeRTMP_RegisterStateChangedEvent(CarEyePusher_StateChanged event);

	/*
	* Comments: ��ȡ��ǰͨ�����������Ƿ��Ѿ����ӵ�����������������׼��
	* Param channel: ͨ����
	* @Return int 0δ����׼��, ��0����׼��
	*/
	CE_API int CE_APICALL CarEyeRTMP_PusherIsReady(int channel);

	/*
	* Comments: ����RTMP���������ļ�ͨ��
	* Param svrip: ��ý�������IP��ַ������
	* Param port: ��ý��������˿ں�
	* Param Name: ������ͨ����
	* Param fileName: Ҫ�����ı����ļ�·�� Ŀǰ��ʱ֧��MP4�ļ�
	* Param startMs: ������ʼ�ĺ�����
	* Param endMs: ���������ĺ����� endMs�������startMs, ��������ʧ��, ������������Ϊ0ʱ����ȫ�ļ�
	* @Return int ���ڵ���0: ����������ͨ���� С��0�����Ųο�CarEyeError
	*/
	CE_API int CE_APICALL CarEyeRTMP_StartNativeFile(char* svrip, unsigned short port, char* name, char* fileName, int startMs, int endMs);

	/*
	* Comments: ������ý�����ݵ�ָ��ͨ����
	* Param channel: Ҫ���͵�ͨ����
	* Param frame: Ҫ���͵�֡����
	* @Return int �Ƿ����ͳɹ�, ״̬��ο�CarEyeError
	*/
	CE_API int CE_APICALL CarEyeRTMP_PushNativeData(int channel, CarEye_AV_Frame* frame);

	/*
	* Comments: �ر�ָ���ı����ļ�RTMP����ͨ��
	* Param channel: ��������RTMP����ͨ����
	* @Return int �Ƿ�ɹ��ر�, ״̬��ο�CarEyeError
	*/
	CE_API int CE_APICALL CarEyeRTMP_StopNativeFile(int channel);

	/*
	* Comments: ����һ��ֱ��������������
	* Param : None
	* @Return �ɹ����������������ʧ�ܷ���NULL
	*/
	CE_API CarEyeRTMPHandle CE_APICALL CarEyeRTMP_Create(void);

	/*
	* Comments: ����ֱ����������״̬�ص�����
	* Param :
	* @Return void
	*/
	CE_API int CE_APICALL CarEyeRTMP_SetCallback(CarEyeRTMPHandle handle, CarEyeRTMP_CallBack callback, void *userptr);

	/*
	* Comments: ����RTMP����ͨ��
	* Param handle: �����ɹ������������
	* Param url: ��������
	* Param mediaInfo: Ҫ������ý����Ϣ
	* @Return int CAREYE_NOERROR: ���ӳɹ� С��0�����Ųο�CarEyeError
	*/
	CE_API int CE_APICALL CarEyeRTMP_Connect(CarEyeRTMPHandle handle, const char* url, CarEye_MediaInfo*  mediaInfo);

	/*
	* Comments: RTMPֱ���������Ƿ�������
	* Param :
	* @Return void
	*/
	CE_API int CE_APICALL CarEyeRTMP_IsConnected(CarEyeRTMPHandle handle);
	
	/*
	* Comments: �ر�ָ����RTMP����ͨ��
	* Param channel: ��������RTMP����ͨ����
	* @Return int �Ƿ�ɹ��ر�, ״̬��ο�CarEyeError
	*/
	CE_API int CE_APICALL CarEyeRTMP_Release(CarEyeRTMPHandle handle);

	/*
	* Comments: ������ý�����ݵ�ָ��ͨ����
	* Param channel: Ҫ���͵�ͨ����
	* Param frame: Ҫ���͵�֡����
	* @Return int �Ƿ����ͳɹ�, ״̬��ο�CarEyeError
	*/
	CE_API int CE_APICALL CarEyeRTMP_PushData(CarEyeRTMPHandle handle, CarEye_AV_Frame* frame);

#ifdef __cplusplus
}
#endif

#endif
