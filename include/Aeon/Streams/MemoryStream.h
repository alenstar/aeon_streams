#ifndef AEON_STREAMS_MEMORY_STREAM_H__
#define AEON_STREAMS_MEMORY_STREAM_H__
#include <iostream>
#include <fstream>
#include <memory>
#include "Stream.h"
namespace Aeon
{
namespace Streams
{

class MemoryStream : public Stream
{
public:
	enum class DeleteMode
	{
		None,
		DeleteOnDestruct
	};

	MemoryStream(DeleteMode delete_mode = DeleteMode::DeleteOnDestruct, int access_mode = AccessMode::READ_WRITE);
	MemoryStream(BufferPtr buffer, int access_mode = AccessMode::READ_WRITE);
	MemoryStream(void *buffer, size_t size, DeleteMode delete_mode = DeleteMode::DeleteOnDestruct, int access_mode = AccessMode::READ_WRITE);
	~MemoryStream();

	virtual size_t					read(void *buffer, size_t count);
	virtual size_t					write(const void *buffer, size_t count);

	virtual size_t					read_line(std::string &str);

	virtual bool					seek(size_t pos, SeekDirection direction);
	virtual size_t					tell() const;

	virtual bool					eof() const;

	virtual void					close();

	virtual void					flush();

	virtual bool					good();

	virtual BufferPtr				get_as_buffer();

protected:
	BufferPtr						m_buffer;
	DeleteMode						m_delete_mode;

	size_t							m_buffer_offset;
};

typedef std::shared_ptr<MemoryStream> MemoryStreamPtr;
#define AeonEmptyMemoryStream MemoryStreamPtr;

} /* namespace Streams */
} /* namespace Aeon */

#endif /* AEON_STREAMS_MEMORY_STREAM_H__ */
