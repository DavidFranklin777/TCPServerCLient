#ifndef CONNECTION_H
#define CONNECTION_H
#include <boost/asio.hpp>
#include <string>
#include <iostream>
#include <memory>

using boost::asio::ip::tcp;

namespace networking {
class connection : public std::enable_shared_from_this<connection>
{
public:
    using pointer = std::shared_ptr<connection>;
    static pointer Create(boost::asio::io_context& ioContext)
    {
        return pointer(new connection(ioContext));
    }
    void start();
    tcp::socket& socket();


private:
    explicit connection( boost::asio::io_context& ioContext);
    tcp::socket m_Socket;
    std::string m_Message {"\n From Connection: Hello Cliantsche!"};
};
}

#endif // CONNECTION_H
