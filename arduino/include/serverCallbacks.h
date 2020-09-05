#ifndef serverCallbacks_H
#define serverCallbacks_H

#include <bluetoothServer.h>

namespace myhappyplants
{
    class ServerCallbacks : public BLEServerCallbacks
    {
    private:
        BluetoothServer *Server;
        bool deviceConnected = false;

    public:
        ServerCallbacks(BluetoothServer *server);
        void onConnect(BLEServer *pServer);
        void onDisconnect(BLEServer *pServer);
        bool isConnected();
    };
} // namespace myhappyplants
#endif