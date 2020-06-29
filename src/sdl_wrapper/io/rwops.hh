/**
 * @file rwops.hh
 * @brief Contains the RWops class and vaguely corresponds to SDL_rwops.h
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @date 2020-06-25
 */

#ifndef SDL_WRAPPER_RWOPS_RWOPS_HH
#define SDL_WRAPPER_RWOPS_RWOPS_HH

#include <SDL2/SDL_rwops.h>
#include <cstddef>
#include <string_view>
#include <vector>

/**
 * @namespace sdl::io
 * @brief Contains the RWops class, an interface for streaming I/O.
 *
 */
namespace sdl::io
{
/**
 * @brief An interface for streaming I/O. Typically used for file operations.
 *
 */
class RWops
{
  public:
    /**
     * @brief Construct an empty RWops object for custom RWops implementations.
     *
     */
    RWops();

    /**
     * @brief Construct a new RWops object from read-only memory.
     *
     * @param constMem the read-only memory
     * @param size the amount of read-only memory
     */
    RWops(const void *constMem, int size) __attribute__((nonnull(2)));

    /**
     * @brief Construct a new RWops object for reading and/or writing to a file by name.
     *
     * @param fileName the file to open
     * @param mode the mode to open the file in. Its syntax is roughly similar to fopen():
     *
     * <table>
     * <tr><th>Value<th>Meaning
     * <tr><td>r<td>Read from the file
     * <tr><td>w<td>Create/write to the file
     * <tr><td>a<td>Append to the file
     * <tr><td>r+<td>Read/write to the file, but the file must exist
     * <tr><td>w+<td>Read/write to the file, the file will be created if it doesn't exist
     * <tr><td>a+<td>Read/append to the file, the file will be created if it doesn't exist. Can read any part of the
     * file, but may only write to the end.
     * </table>
     *
     * Additionally, b may be appended to the `mode` text to perform the operation in binary mode.
     */
    RWops(std::string_view fileName, std::string_view mode);

    /**
     * @brief Construct a new RWops object from an already-opened file pointer.
     *
     * @param fp the file pointer
     * @param autoClose whether to close the file with the RWops when it is destroyed
     */
    RWops(FILE *fp, bool autoClose) __attribute__((nonnull(2)));

    /**
     * @brief Construct a new RWops object for a read-write memory buffer.
     *
     * @param mem the memory buffer
     * @param size the size of the memory buffer
     */
    RWops(void *mem, int size) __attribute__((nonnull(2)));

    ~RWops();

    RWops(const RWops &) = delete;
    RWops &operator=(const RWops &) = delete;

    /**
     * @brief move constructor
     *
     * @param other the object to move from
     */
    RWops(RWops &&other);
    /**
     * @brief move assignment operator
     *
     * @param other the object to move from
     * @return RWops& the object that was moved to
     */
    RWops &operator=(RWops &&other);

    /**
     * @brief Read `amt` bytes from the stream.
     *
     * @param amt the number of bytes to read
     * @return std::vector<std::byte> the bytes read
     */
    std::vector<std::byte> read(Uint32 amt);

  private:
    /**
     * @brief The internal SDL handle.
     *
     */
    SDL_RWops *handle;
    /**
     * @brief Whether this object was default-constructed.
     *
     */
    bool allocd;
};
} // namespace sdl::io

#endif // SDL_WRAPPER_RWOPS_RWOPS_HH