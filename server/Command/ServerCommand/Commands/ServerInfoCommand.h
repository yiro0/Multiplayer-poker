
#ifndef MY_PROJECTS_CLIENTINFOCOMMAND_H
#define MY_PROJECTS_INFOCOMMAND_H


#include "../ServerCommand.h"

class ServerInfoCommand : public ServerCommand {

private:
    void execute() override;

public:
    explicit ServerInfoCommand(ServerCommandController *pController);
};


#endif //MY_PROJECTS_CLIENTINFOCOMMAND_H
