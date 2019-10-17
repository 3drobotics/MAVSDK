#pragma once

#include <mutex>
#include "plugins/passthrough/passthrough.h"
#include "plugin_impl_base.h"

namespace mavsdk {

class PassthroughImpl : public PluginImplBase {
public:
    PassthroughImpl(System& system);
    ~PassthroughImpl();

    void init() override;
    void deinit() override;

    void enable() override;
    void disable() override;

    Passthrough::Result send_message(const Passthrough::MavlinkMessage mavlink_message);
    
    uint8_t get_our_sysid() const;
    uint8_t get_our_compid() const;
    uint8_t get_target_sysid() const;
    uint8_t get_target_compid() const;

    Passthrough::Result send_command_int(const Passthrough::CommandInt command_int);
    Passthrough::Result send_command_long(const Passthrough::CommandLong command_long);

private:
     static Passthrough::Result passthrough_result_from_command_result(MAVLinkCommands::Result command_result);
};

} // namespace mavsdk
