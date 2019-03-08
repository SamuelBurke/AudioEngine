#include "Source.h"

#include <AL/al.h>
#include <vorbis/vorbisfile.h>

#include <iostream>
#include <vector>

namespace AudioEngine
{


struct SoundImpl
{
	ALuint id;

	~SoundImpl()
	{
		alDeleteBuffers(1, &id);
	}

	void Load_OGG(std::string _filePath, std::vector<char> &_buffer, ALenum &_format, ALsizei &_freq)
	{
		int endian = 0;
		int bitStream = 0;
		long bytes = 0;
		char array[2048] = { 0 };
		vorbis_info *pInfo = NULL;
		OggVorbis_File oggFile = { 0 };

		//create a file descriptor using the inbuilt 'fopen'
		if (ov_fopen(_filePath.c_str(), &oggFile) != 0)
		{
			std::cout << "failed to open file '" << _filePath << "' for decoding" << std::endl;
			throw std::exception();
		}

		//extract information from the file header
		pInfo = ov_info(&oggFile, -1);

		//record the format required by OpenAL
		if (pInfo->channels == 1)
		{
			_format = AL_FORMAT_MONO16;
		}
		else
		{
			_format = AL_FORMAT_STEREO16;
		}

		//record the sample rate required by OpenAL
		_freq = pInfo->rate;

		//keep reading bytes from the file to populate the output buffer
		while (true)
		{
			//read bytes into temporary array
			bytes = ov_read(&oggFile, array, 2048, endian, 2, 1, &bitStream);

			if (bytes < 0)
			{
				ov_clear(&oggFile);
				std::cout << "failed to decode file '" << _filePath << "'." << std::endl;
				throw std::exception();
			}

			else if (bytes == 0)
			{
				break;
			}

			//copy from temporary array into output buffer
			_buffer.insert(_buffer.end(), array, array + bytes);
		}

		//clean up and close the file
		ov_clear(&oggFile);
	}

};

Source::Source()
{
}

Source::Source(std::string _filePath)
{
	Load(_filePath);
}

void Source::Load(std::string _filePath)
{
	m_impl = std::make_shared<SoundImpl>();

	ALenum format = 0;
	ALsizei freq = 0;
	std::vector<char> bufferData;

	alGenBuffers(1, &m_impl->id);

	m_impl->Load_OGG(_filePath.c_str(), bufferData, format, freq);

	alBufferData(m_impl->id, format, &bufferData[0], static_cast<ALsizei>(bufferData.size()), freq);	
}

void Source::Play()
{
	ALuint sourceId = 0;
	alGenSources(1, &sourceId);
	alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSource3f(sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSourcei(sourceId, AL_BUFFER, m_impl->id);
	alSourcePlay(sourceId);

	//audioSources.push_back(sourceId);
}	

}
