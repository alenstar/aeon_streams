#ifndef AEON_STREAMS_STREAM_H__
#define AEON_STREAMS_STREAM_H__

namespace Aeon
{
namespace Streams
{

/*!
 * \brief Base class for streams
 *
 * This class serves as the base class for all streams. When implementing a new steam, derive from this class.
 */
class Stream
{
public:
	/*!
 	 * The available access modes for this stream. This allows an implementation to ask the stream for
 	 * it's access permissions.
 	 *
 	 * This is implemented as a anonymous enum within a class, since enum classes do not support bitflags
 	 * at this moment.
 	 */
	class AccessMode 
	{
	public:
		enum
		{
			READ			= 1, /**< enum Read-Only */
			WRITE			= 2, /**< enum Write-Only */
			READ_WRITE		= 3  /**< enum Read-Write (Full access) */
		};
	};

	/*!
 	 * The seek direction used in the Stream::Seek function. This determines the behaviour of the pos
 	 * parameter.
 	 */ 
	enum class SeekDirection
	{
		Begin,				/**< enum Seek forwards from the beginning */
		Current,			/**< enum Seek forwards from wherever the read pointer currently is */
		End					/**< enum Seek backwards from the end */
	};

	/*!
	 * \brief Basic constructor for Stream
	 *
	 * This constructor will give the stream the default name as configured in the 
	 * AEON_STREAMS_DEFAULT_STREAM_NAME macro.
	 *
	 * When no parameter is given, Read-only mode is assumed.
	 *
	 * \param access_mode The access mode for the stream.
	 * \sa AccessMode
 	 */
	Stream(int access_mode = AccessMode::READ);

	/*!
	 * \brief Prefered constructor for Stream
	 *
	 * This constructor will create a named stream.
	 *
	 * When no parameter is given, Read-only mode is assumed.
	 *
	 * \param name The name of the stream. Does not need to be unique.
	 * \param access_mode The access mode for the stream.
	 * \sa AccessMode
	 */
	Stream(const std::string &name, int access_mode = AccessMode::READ);

	virtual ~Stream();

	const std::string &				get_name() { return m_name; }
	virtual int						get_access_mode() { return m_access_mode; }

	virtual bool					is_readable() const { return (m_access_mode & AccessMode::READ) != 0; }
	virtual bool					is_writeable() const { return (m_access_mode & AccessMode::WRITE) != 0; }

	virtual size_t					read(void *buffer, size_t count) = 0;
	virtual size_t					write(const void *buffer, size_t count) = 0;

	virtual size_t					write(BufferPtr buffer);

	virtual size_t					read_line(std::string &str) = 0;
	virtual size_t					write(const std::string &str);

	virtual bool					seek(size_t pos, SeekDirection direction) = 0;
	virtual size_t					tell() const = 0;

	virtual bool					eof() const = 0;

	size_t							size() const { return m_size; }
	virtual void					close() {}

	virtual void					flush() {}

	virtual bool					good() { return false; }

	virtual BufferPtr				get_as_buffer();

protected:
	std::string						m_name;
	size_t							m_size;
	int								m_access_mode;
};

typedef std::shared_ptr<Stream> StreamPtr;
#define AeonEmptyStream StreamPtr()

} /* namespace Streams */
} /* namespace Aeon */

#endif /* AEON_STREAMS_STREAM_H__ */
