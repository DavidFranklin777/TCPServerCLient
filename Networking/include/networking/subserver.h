#ifndef SUBSERVER_H
#define SUBSERVER_H
#include <string>
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;
namespace networking {
enum class ipv
{
   v4,
   v6
};

class SubServer
{
public:
    SubServer(ipv _ipv, int port);
    int run();

private:
  ipv                             m_IpVersion;
  int                             m_Port;
  boost::asio::io_context         m_IoContext;
  boost::asio::ip::tcp::acceptor  m_Acceptor;

  void startAccept();

};
}

#endif // SUBSERVER_H
