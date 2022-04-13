#include "PacketLogger.h"

PacketLogger::PacketLogger() : IModule(0, Category::MISC, "Logging Packets!") {
}

PacketLogger::~PacketLogger() {
}

const char* PacketLogger::getModuleName() {
	return ("Logger");
}

void PacketLogger::onSendPacket(C_Packet* packet) {
	if (packet->isInstanceOf<C_PlayerActionPacket>()) {
		auto pk = reinterpret_cast<C_PlayerActionPacket*>(packet);
		g_Data.getClientInstance()->getGuiData()->displayClientMessageF("[PACKETLOG] %s action=%i", packet->getName()->getText(), pk->action);
		return;
	}
	g_Data.getClientInstance()->getGuiData()->displayClientMessageF("[PACKETLOG] %s", packet->getName()->getText());
}
