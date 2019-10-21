#include "plugins/passthrough/passthrough.h"
#include "passthrough_impl.h"

namespace mavsdk {

Passthrough::Passthrough(System& system) : PluginBase(), _impl{new PassthroughImpl(system)} {}

Passthrough::~Passthrough() {}

Passthrough::Result Passthrough::send_message(const Passthrough::MavlinkMessage mavlink_message)
{
    return _impl->send_message(mavlink_message);
}

std::string Passthrough::result_str(Result result)
{
    switch (result) {
        case Passthrough::Result::SUCCESS:
            return "Success";
        case Passthrough::Result::CONNECTION_ERROR:
            return "Connection error";
        default:
            // FALLTHROUGH
        case Passthrough::Result::UNKNOWN:
            return "Unknown";
    }
}

uint8_t Passthrough::get_our_sysid() const
{
    return _impl->get_our_sysid();
}
uint8_t Passthrough::get_our_compid() const
{
    return _impl->get_our_compid();
}

uint8_t Passthrough::get_target_sysid() const
{
    return _impl->get_target_sysid();
}

uint8_t Passthrough::get_target_compid() const
{
    return _impl->get_target_compid();
}

Passthrough::Result Passthrough::send_command_int(const Passthrough::CommandInt command_int)
{
    return _impl->send_command_int(command_int);
}

Passthrough::Result Passthrough::send_command_long(Passthrough::CommandLong command_long)
{
    return _impl->send_command_long(command_long);
}

} // namespace mavsdk
