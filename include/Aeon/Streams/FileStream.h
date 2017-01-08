#ifndef AEON_STREAMS_FILESTREAM_H__
#define AEON_STREAMS_FILESTREAM_H__
#include <iostream>
#include <fstream>
#include <memory>
#include "Stream.h"
namespace Aeon
{
namespace Streams
{

class FileStream : public Stream
{
public:
	FileStream(const std::string &path, int access_mode = AccessMode::READ);
	virtual ~FileStream();

	virtual size_t		read(void *buffer, size_t count);
	virtual size_t		write(const void *buffer, size_t count);

	virtual size_t		read_line(std::string &str);

	virtual bool		seek(size_t pos, SeekDirection direction);
	virtual size_t		tell() const;

	virtual bool		eof() const;

	virtual void		close();

	virtual void		flush();

	virtual bool		good();

protected:
	void				__open_file();
	void				__calculate_file_size();

	FILE *				m_file;
};

typedef std::shared_ptr<FileStream> FileStreamPtr;

} /* namespace Streams */
} /* namespace Aeon */

#endif /* AEON_STREAMS_FILESTREAM_H__ */
