//-----------------------------------------------------------------------------
//	Работа со звуковыми каналами
//	Копонент звукового двигателя Шквал
//	команда		: AntiTank
//	разработчик	: Гилязетдинов Марат (Марыч)
//-----------------------------------------------------------------------------
#ifndef _SAGSS_DATA_H_INCLUDED_
#define _SAGSS_DATA_H_INCLUDED_

// внешние включения
#include "ext/Eax.h"
#include "Channels.h"



// внутренная структура для хранения данных
typedef struct context_s {
	//////////////////////////////////////////////////
	// данные для работы с расширениями
	//////////////////////////////////////////////////
	void* _id;  				  // идентификатор контекста
	int _useEax;				// текущая версия используемого EAX интерфейса
	int _eaxSupport[EAX_NUM + 1]; // доступность EAX интерфейсов
	LPDIRECTSOUNDBUFFER _eaxBuffer; 			// буфер для EAX слушателя
	LPKSPROPERTYSET _eaxListener;   		// интерфейс EAX слушателя
	squall_eax_listener_t _eaxLP;   			  // EAX параметры слушателя

	int _zoomfxSupport;

	//////////////////////////////////////////////////
	// данные для работы с DirectX
	//////////////////////////////////////////////////
	HWND _window;					  // окно к которуму присоединять двигатель
	HWND _hiddenWindow;			  // скрытое окно создаваемое двигателем
	LPDIRECTSOUND _directSound;			  // интерфейс Direct Sound
	LPDIRECTSOUND3DLISTENER _listener;				  // интерфейс трехмерного слушателя
	DS3DLISTENER _listenerParameters;	   // параметры слушателя
	LPDIRECTSOUNDBUFFER _primary;   			// первичный звуковой буфер
	DWORD _curDevice;				  // номер текущего устрйства

	//////////////////////////////////////////////////
	// данные для работы с потоками
	//////////////////////////////////////////////////
	unsigned long _threadID;			  // идентификатор звукового потока
	HANDLE _mutex;  			   // мутекс для системы разделения времени обработки
	HANDLE _event;  			   // событие использования звукового потока
	HANDLE _thread; 			   // хендлер звукового потока

	//////////////////////////////////////////////////
	// количество каналов
	//////////////////////////////////////////////////
	int _channels;  			// максимальное количество слышимых звуков
	SSample* _channelsArray;		 // список воспроизводимых звуков

	//////////////////////////////////////////////////
	// настроечные параметры звукового двигателя
	//////////////////////////////////////////////////
	int _bufferSize;		 // длинна звуковой половинки в милисекундах
	int _sampleRate;		 // частота звука
	int _bitPerSample;  	 // количество бит на семпл
	int _used3DAlgorithm;    // используемый алгоритм общета звука
	int _support3DAlgTab[4]; // таблица поддержки 3D алгоритмов
	int _useHW2D;   		 // флаг использования 2D акселерации
	int _useHW3D;   		 // флаг использование 3D акселерации

	// обновление трехмерных настроек
	DWORD _deferred;

	// обработчик слушателя
	squall_callback_listener_t _worker; 			// обработчик слушателя
	void* _workerUserData;     // параметры для вызова обработчика слушателя
	DWORD _workerUpdateTime;   // время через которое нужно вызывать обработчик
	DWORD _prevWorkerTime;     // время вызова обработчика слушателя

	DWORD _searchTemp[256];    // промежуточный массив для выборки данных

	//-----------------------------------------------------------------------------
	// Инициализация DirectSound
	// на входе    :  window   - хендлер окна к которому привязан обьект
	//  			  device   - идентификатор устройства
	//  			  rate     - частота звука
	//  			  bits     - количество бит на выборку
	//  			  channels - количество каналов
	// на выходе	:	успешность инициализации DirectSound
	//-----------------------------------------------------------------------------
	int InitAudio(HWND window, LPGUID device, int rate, int bits, int channels);
	//-----------------------------------------------------------------------------
	// Освобождение DirectSound обьекта
	// на входе    :  *
	// на выходе   :  успешность деинициализации DirectSound
	//-----------------------------------------------------------------------------
	void FreeAudio(void);
	//-----------------------------------------------------------------------------
	// Процедура создания обработчика каналов в игре
	// на входе    :  *
	// на выходе   :  успешность создания обработчика звука
	//-----------------------------------------------------------------------------
	bool CreateSoundThread(void);
	//-----------------------------------------------------------------------------
	// Удаление обработчика звуковых каналов
	// на входе    :  *
	// на выходе   :  успешность удаления обработчика звука
	//-----------------------------------------------------------------------------
	void DeleteSoundThread(void);
	//-----------------------------------------------------------------------------
	//	Поиск канала по идентификатору
	//	на входе	:	ChannelID	- идентификатор канала
	//	на выходе	:	номер канала
	//-----------------------------------------------------------------------------
	int GetChannelIndex(int ChannelID);
	int GetChannelID(int ChannelIndex);
	//-----------------------------------------------------------------------------
	//	Поиск свободного канала
	//	на входе	:	Priority	- приоритет нового канала
	//	на выходе	:	номер канала
	//-----------------------------------------------------------------------------
	int GetFreeChannel(int Priority);
	//-----------------------------------------------------------------------------
	// Инициализация звуковых расширений
	// на входе    :  *
	// на выходе   :  успешность инициализации
	//-----------------------------------------------------------------------------
	int InitAudioExtensions(void);
	//-----------------------------------------------------------------------------
	//	Деинициализация звуковых расширений
	// на входе    :  *
	// на выходе   :  *
	//-----------------------------------------------------------------------------
	void FreeAudioExtensions(void);
	//-----------------------------------------------------------------------------
	//	Установка нового текущего устройства воспроизведения
	// на входе    :  cur_device  - номер текущего устройства воспроизведения 
	//  			  new_device  - номер нового устройства воспроизведения
	// на выходе   :	успешность установки нового устройства воспроизведения
	//-----------------------------------------------------------------------------
	int SetDevice(DWORD cur_device, DWORD new_device);
} context_t;
#endif
