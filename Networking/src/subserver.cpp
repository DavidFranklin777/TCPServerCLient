#include "networking/subserver.h"
#include <connection.h>
using boost::asio::ip::tcp;

namespace networking{

SubServer::SubServer(ipv _ipv, int port)
    : m_IpVersion(_ipv),
      m_Port(port),
      m_Acceptor(m_IoContext, tcp::endpoint(m_IpVersion == ipv::v4? tcp::v4() : tcp::v6(), m_Port))
{
}

int SubServer::run()
{
    startAccept();
    try
    {
        m_IoContext.run();
    }
    catch (std::exception &e)
    {
       std::cerr << e.what() << std::endl;
       return -1;
    }

    return 0;
}

void SubServer::startAccept()
{
    // Create a connection
    auto acceptConnection = connection::Create(m_IoContext);
    // Asynchronously accept the connection
    m_Acceptor.async_accept(acceptConnection->socket(), [acceptConnection, this](const boost::system::error_code &error)
    {
        if(!error)
        {
            acceptConnection->start();
        }

       startAccept();

    });
}


}
