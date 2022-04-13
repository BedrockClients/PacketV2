#include "TestCommand.h"
#include "../../../Utils/Logger.h"
#include "../../../Utils/Utils.h"
#include <sstream>
#include "../../../SDK/Tag.h"

TestCommand::TestCommand() : IMCCommand("test", "Test for Debugging purposes", "") {
}

TestCommand::~TestCommand() {
}

void listEnts(C_Entity* ent, bool isValid) {
	int id = ent->getEntityTypeId();
	char* name = ent->getNameTag()->getText();
	logF("---------------");
	logF("Entity Name: %s", name);
	logF("Entity ID: %d", id);
	logF("---------------");
}

void showAimedBlockInfo() {
	PointingStruct* pointingStruct = g_Data.getLocalPlayer()->pointingStruct;
	C_Block* block = g_Data.getLocalPlayer()->region->getBlock(pointingStruct->block);
	int id = (int)block->toLegacy()->blockId;
	char* name = block->toLegacy()->name.getText();
	logF("---------------");
	logF("Block Name: %s", name);
	logF("Block ID: %d", id);
	logF("---------------");
}

bool TestCommand::execute(std::vector<std::string>* args) {
	C_LocalPlayer* player = g_Data.getLocalPlayer();

	//auto inv = player->getSupplies()->inventory;
	//logF("%i %i", inv->getFirstEmptySlot(), inv->getEmptySlotsCount());
	
	//inv->swapSlots(1, 2);


	return true;
}
