#include <serverCallbacks.h>

namespace myhappyplants
{
    ServerCallbacks::ServerCallbacks(BluetoothServer *server)
    {
        this->Server = server;
    }

    void ServerCallbacks::onConnect(BLEServer *pServer)
    {
        deviceConnected = true;
    };

    void ServerCallbacks::onDisconnect(BLEServer *pServer)
    {
        deviceConnected = false;
    }

    bool ServerCallbacks::isConnected()
    {
        return deviceConnected;
    }
} // namespace myhappyplants