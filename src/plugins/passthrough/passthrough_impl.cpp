#include <functional>
#include "passthrough_impl.h"
#include "system.h"
#include "global_include.h"

namespace mavsdk {

PassthroughImpl::PassthroughImpl(System& system) : PluginImplBase(system)
{
    _parent->register_plugin(this);
}

PassthroughImpl::~PassthroughImpl()
{
    _parent->unregister_plugin(this);
}

void PassthroughImpl::init() {}

void PassthroughImpl::deinit() {}

void PassthroughImpl::enable() {}

void PassthroughImpl::disable() {}

Passthrough::Result PassthroughImpl::send_message(const Passthrough::MavlinkMessage mavlink_message)
{
    mavlink_message_t message;

    message.checksum = mavlink_message.checksum;
    message.magic = mavlink_message.magic;
    message.len = mavlink_message.len;
    message.incompat_flags = mavlink_message.incompat_flags;
    message.compat_flags = mavlink_message.compat_flags;
    message.seq = mavlink_message.seq;
    message.sysid = mavlink_message.sysid; 
    message.compid = mavlink_message.compid;
    message.msgid = mavlink_message.msgid;

    for(int i = 0; i < 33; i++) {
        message.payload64[i] = mavlink_message.payload64[i];
    }

    for(int i = 0; i < 2; i++) {
        message.ck[i] = mavlink_message.ck[i];
    }

    if (!_parent->send_message(message)) {
        return Passthrough::Result::CONNECTION_ERROR;
    }

    return Passthrough::Result::SUCCESS;
}

uint8_t PassthroughImpl::get_our_sysid() const
{
    return _parent->get_own_system_id();
}

uint8_t PassthroughImpl::get_our_compid() const
{
    return _parent->get_own_component_id();
}

uint8_t PassthroughImpl::get_target_sysid() const
{
    return _parent->get_system_id();
}

uint8_t PassthroughImpl::get_target_compid() const
{
    return _parent->get_autopilot_id();
}

Passthrough::Result PassthroughImpl::send_command_int(const Passthrough::CommandInt command_int)
{
    MAVLinkCommands::CommandInt custom_command{};

    custom_command.target_system_id = command_int.target_system_id;
    custom_command.target_component_id = command_int.target_component_id;
    custom_command.command = command_int.command;
    custom_command.current = command_int.current;
    custom_command.autocontinue = command_int.autocontinue;
    custom_command.params.param1 = command_int.params.param1;
    custom_command.params.param2 = command_int.params.param2;
    custom_command.params.param3 = command_int.params.param3;
    custom_command.params.param4 = command_int.params.param4;
    custom_command.params.x = command_int.params.x;
    custom_command.params.y = command_int.params.y;
    custom_command.params.z = command_int.params.z;

    return passthrough_result_from_command_result(_parent->send_command(custom_command));
}

Passthrough::Result PassthroughImpl::send_command_long(const Passthrough::CommandLong command_long)
{
    MAVLinkCommands::CommandLong custom_command{};

    custom_command.target_system_id = command_long.target_system_id;
    custom_command.target_component_id = command_long.target_component_id;
    custom_command.command = command_long.command;
    custom_command.confirmation = command_long.confirmation;
    custom_command.params.param1 = command_long.params.param1;
    custom_command.params.param2 = command_long.params.param2;
    custom_command.params.param3 = command_long.params.param3;
    custom_command.params.param4 = command_long.params.param4;
    custom_command.params.param5 = command_long.params.param5;
    custom_command.params.param6 = command_long.params.param6;
    custom_command.params.param7 = command_long.params.param7;

    return passthrough_result_from_command_result(_parent->send_command(custom_command));
}

Passthrough::Result PassthroughImpl::passthrough_result_from_command_result(MAVLinkCommands::Result command_result)
{
    switch (command_result) {
        case MAVLinkCommands::Result::SUCCESS:
            return Passthrough::Result::SUCCESS;
        case MAVLinkCommands::Result::TIMEOUT:
        case MAVLinkCommands::Result::NO_SYSTEM:
        case MAVLinkCommands::Result::CONNECTION_ERROR:
            return Passthrough::Result::CONNECTION_ERROR;
        case MAVLinkCommands::Result::BUSY:
        case MAVLinkCommands::Result::COMMAND_DENIED:
        default:
            return Passthrough::Result::UNKNOWN;
    }
}

} // namespace mavsdk
