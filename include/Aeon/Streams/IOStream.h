#ifndef AEON_STREAMS_IOSTREAM_H__
#define AEON_STREAMS_IOSTREAM_H__

namespace Aeon
{

class IOStream : public Stream
{
public:
	IOStream(int access_mode = AccessMode::READ);
	IOStream(const std::string &name, int access_mode = AccessMode::READ);

	virtual size_t					read(void *buffer, size_t count);
	virtual size_t					write(const void *buffer, size_t count);

	virtual size_t					read_line(std::string &str);

	virtual bool					seek(size_t pos, SeekDirection direction);
	virtual size_t					tell() const;

	virtual bool					eof() const;

	virtual void					flush();

	virtual bool					good() { return true; }

	virtual BufferPtr				get_as_buffer();
};

} //namespace Aeon

#endif /* AEON_STREAMS_IOSTREAM_H__ */
