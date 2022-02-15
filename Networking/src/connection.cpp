#include "connection.h"

namespace networking {

connection::connection(boost::asio::io_context &ioContext)
    : m_Socket(ioContext)
{

}

void connection::start()
{
    auto strongThis = shared_from_this();
    boost::asio::async_write(m_Socket,
                             boost::asio::buffer(m_Message),
                             [strongThis](const boost::system::error_code& error, size_t bytesTransferred)
    {
        if(error)
        {
            std::cout << "Failed to send message!\n";
        }
        else
        {
            std::cout << "Sent " << bytesTransferred << " bytes of data\n";
        }
    });
}

tcp::socket &connection::socket()
{
    return m_Socket;

}



}
