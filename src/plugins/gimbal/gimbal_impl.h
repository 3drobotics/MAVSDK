#pragma once

#include "plugins/gimbal/gimbal.h"
#include "plugin_impl_base.h"
#include "system.h"

namespace mavsdk {

class GimbalImpl : public PluginImplBase {
public:
    GimbalImpl(System& system);
    ~GimbalImpl();

    void init() override;
    void deinit() override;

    void enable() override;
    void disable() override;

    Gimbal::Result set_pitch_and_yaw(float pitch_deg, float yaw_deg);

    void
    set_pitch_and_yaw_async(float pitch_deg, float yaw_deg, Gimbal::result_callback_t callback);

    Gimbal::Result set_gimbal_mode(const Gimbal::GimbalMode gimbal_mode);

    Gimbal::Result send_mavlink_command(uint8_t target_system_id, uint8_t target_component_id, uint16_t command, bool current, bool autocontinue, float param1, float param2, float param3, float param4, int32_t x, int32_t y, float z);

    void
    set_gimbal_mode_async(const Gimbal::GimbalMode gimbal_mode, Gimbal::result_callback_t callback);

    float to_float_gimbal_mode(const Gimbal::GimbalMode gimbal_mode) const;

    Gimbal::Result set_roi_location(double latitude_deg, double longitude_deg, float altitude_m);

    void set_roi_location_async(
        double latitude_deg,
        double longitude_deg,
        float altitude_m,
        Gimbal::result_callback_t callback);

    // Non-copyable
    GimbalImpl(const GimbalImpl&) = delete;
    const GimbalImpl& operator=(const GimbalImpl&) = delete;

private:
    static Gimbal::Result gimbal_result_from_command_result(MAVLinkCommands::Result command_result);

    static void receive_command_result(
        MAVLinkCommands::Result command_result, const Gimbal::result_callback_t& callback);
};

} // namespace mavsdk
