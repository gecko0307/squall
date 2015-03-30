//-----------------------------------------------------------------------------
//	Класс для работы со звуковыми файлами
//	Копонент звукового двигателя Шквал
//	команда		: AntiTank
//	разработчик	: Гилязетдинов Марат (Марыч)
//-----------------------------------------------------------------------------
#ifndef _SOUND_FILE_H_INCLUDED_
#define _SOUND_FILE_H_INCLUDED_

// включения
#include <windows.h>
#include "Reader.h"

class CAbstractDecompressor;
class CAbstractSoundFile;

//-----------------------------------------------------------------------------
// Класс для работы со звуковыми файлами
//-----------------------------------------------------------------------------
class CSoundFile {
protected:
	unsigned int class_id;
	CReader* reader;				 // класс для низкоуровневой работы с файлами
	CAbstractSoundFile* sound_data; 			// абстрактный звуковой файл
	CAbstractDecompressor* decoder; 			   // используемый декомпрессор

	WAVEFORMATEX pcm_format;			 // формат для использования в Direct X

	bool Init(void);			 // инициализация загруженного файла
	void DeInit(void);  		 // освобождение занятых ресурсов

public:

	// контроль ссылок
	int _ref;   									// количество ссылок на файл
	int AddRef();   			// добавить сслылку
	int DecRef();   			// удалить ссылку

	// конструктор/деструктор
	CSoundFile();   								// конструктор класса
	~CSoundFile();  								// деструктор класса
	//-----------------------------------------------------------------------------
	// Проверка работоспособности класса
	// на входе    :  *
	// на выходе   :  true - классом можно пользоваться
	//  			  false - класс нельзя использовать
	//-----------------------------------------------------------------------------
	bool Check(void);
	//-----------------------------------------------------------------------------
	//	Создание звуковых данных из указанного файла
	//	на входе	:	file	- указатель на имя файла
	//					mem_flag	- флаг загрузки файла в память
	//							  true	- в память
	//							  false	- с докачкой с диска
	//	на выходе	:	успешность инициализации
	//-----------------------------------------------------------------------------
	bool CreateSoundDataFromFile(const char* filename, int stream_flag);

	//-----------------------------------------------------------------------------
	//	Создание звуковых данных из указанной памяти
	//	на входе	:	memory		- указатель на имя файла
	//					memory_size	- флаг загрузки файла в память
	//								true	- в память
	//								false	- с докачкой с диска
	//					new_memory	- флаг создания новой памяти под указанные данные
	//								true	- выделить новую память под звуковые данные
	//								false	- использовать указанную память под звуковые данные
	//	на выходе	:	успешность инициализации
	//-----------------------------------------------------------------------------
	bool CreateSoundDataFromMemory(void* memory, unsigned int memory_size,
		int new_memory);

	//-----------------------------------------------------------------------------
	//	Получение формата звука
	//	на входе	:	*
	//	на выходе	:	указатель на формат звуковых данных
	//-----------------------------------------------------------------------------
	WAVEFORMATEX* GetFormat(void);

	//-----------------------------------------------------------------------------
	//	Заполнение данными буфера
	//	на входе	:	buffer	- указатель на буфер заполнения
	//					start	- позиция в файле в отчетах
	//					length	- длинна получаемых данных в отчетах
	//	на выходе	:	на сколько нужно сдвинуть принимающий буфер
	//-----------------------------------------------------------------------------
	unsigned int GetMonoData(void* buffer, unsigned int start,
		unsigned int length, bool loop);

	//-----------------------------------------------------------------------------
	//	Заполнение данными буфера
	//	на входе	:	buffer	- указатель на буфер заполнения
	//					start	- позиция в файле в отчетах
	//					length	- длинна получаемых данных в отчетах
	//	на выходе	:	на сколько нужно сдвинуть принимающий буфер
	//-----------------------------------------------------------------------------
	unsigned int GetStereoData(void* buffer, unsigned int start,
		unsigned int length, bool loop);

	//-----------------------------------------------------------------------------
	//	Заполнение "монофонической тишиной" буфера
	//	на входе	:	buffer	- указатель на буфер заполнения
	//					length	- длинна тишины в семплах
	//	на выходе	:	на сколько нужно сдвинуть принимающий буфер
	//-----------------------------------------------------------------------------
	unsigned int GetMonoMute(void* buffer, unsigned int length);

	//-----------------------------------------------------------------------------
	//	Заполнение "стерефонической тишиной" буфера
	//	на входе	:	buffer	- указатель на буфер заполнения
	//					length	- длинна тишины в семплах
	//	на выходе	:	на сколько нужно сдвинуть принимающий буфер
	//-----------------------------------------------------------------------------
	unsigned int GetStereoMute(void* buffer, unsigned int length);

	//-----------------------------------------------------------------------------
	//	Получение длинны моно трека в байтах
	//	на входе	:	*
	//	на выходе	:	длинна трека в байтах
	//-----------------------------------------------------------------------------
	unsigned int GetRealMonoDataSize(void);

	//-----------------------------------------------------------------------------
	//	Получение длинны стерео трека в байтах
	//	на входе	:	*
	//	на выходе	:	длинна трека в байтах
	//-----------------------------------------------------------------------------
	unsigned int GetRealStereoDataSize(void);

	//-----------------------------------------------------------------------------
	//	Получение длинны трека с семплах
	//	на входе	:	*
	//	на выходе	:	длинна трека в семплах
	//-----------------------------------------------------------------------------
	unsigned int GetSamplesInFile(void);

	char* GetFileName(void);
};
#endif



