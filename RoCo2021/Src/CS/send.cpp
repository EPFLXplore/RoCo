#include "Build.h"

#ifdef BUILD_FOR_TESTING


#include <cstdint>
#include <iomanip>
#include <iostream>
#include <thread>
#include <cstring>
#include <unistd.h>

#include "RoCo.h"

int main() {
	std::cout << "Starting send test..." << std::endl;


	NetworkServerIO* server_io = new NetworkServerIO(PORT_B);

	// server_io->receive(&handle_input);

	int32_t result = server_io->connectServer();

	if(result < 0) {
		std::cout << "Network Server IO connection failed with error code " << result << std::endl;
		std::cout << std::strerror(errno) << std::endl;
	} else {
		std::cout << "Connected to network server IO" << std::endl;
	}


	NetworkBus* server_bus = new NetworkBus(server_io);
	//NetworkBus* client_1_bus = new NetworkBus(client_io_1);
	//NetworkBus* client_2_bus = new NetworkBus(client_io_2);


	//server_bus->forward<PingPacket>(server_bus);
	//client_2_bus->handle(handle_packet);
  int count = 0;
  //client_1_bus->send(&packet);

  while(true){
    PingPacket packet;
		//packet.time = static_cast<uint64_t> (std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::time_point<std::chrono::system_clock>{}.time_since_epoch()).count());
		//std::cout<<(packet.time-std::chrono::high_resolution_clock::now()).count()<<std::endl;
		std::cout<<packet.time<<std::endl;
    server_bus->send<PingPacket>(&packet);
    count+=1;
    std::cout << "PingPacket "<<count<<" sent" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

}
#endif
