#pragma once

#include "plugin_impl_base.h"
#include "mavlink_include.h"
#include "device_impl.h"
#include "action.h"
#include <cstdint>

namespace dronelink {

class ActionImpl : public PluginImplBase
{
public:
    ActionImpl();
    ~ActionImpl();

    void init() override;
    void deinit() override;

    Action::Result arm() const;
    Action::Result disarm() const;
    Action::Result kill() const;
    Action::Result takeoff() const;
    Action::Result land() const;
    Action::Result return_to_land() const;

    void arm_async(Action::result_callback_t callback);
    void disarm_async(Action::result_callback_t callback);
    void kill_async(Action::result_callback_t callback);
    void takeoff_async(Action::result_callback_t callback);
    void land_async(Action::result_callback_t callback);
    void return_to_land_async(Action::result_callback_t callback);

private:
    bool is_arm_allowed() const;
    bool is_disarm_allowed() const;

    void process_extended_sys_state(const mavlink_message_t &message);

    static void report_result(Action::result_callback_t callback, Action::Result result);

    static Action::Result action_result_from_command_result(DeviceImpl::CommandResult result);

    static void command_result_callback(DeviceImpl::CommandResult command_result,
                                        void *user);

    bool _in_air_state_known;
    bool _in_air;

    static constexpr uint8_t VEHICLE_MODE_FLAG_CUSTOM_MODE_ENABLED = 1;

    // FIXME: these chould potentially change anytime
    static constexpr uint8_t PX4_CUSTOM_MAIN_MODE_AUTO = 4;
    static constexpr uint8_t PX4_CUSTOM_SUB_MODE_AUTO_RTL = 5;
};

} // namespace dronelink
