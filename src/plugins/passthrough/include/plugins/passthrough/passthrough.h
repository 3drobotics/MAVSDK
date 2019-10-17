#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <functional>
#include <vector>

#include "plugin_base.h"

namespace mavsdk {

class System;
class PassthroughImpl;

/**
 * @brief The Passthrough class provides send mavlink messages and commands.
 */
class Passthrough : public PluginBase {
public:
    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto passthrough = std::make_shared<Passthrough>(system);
     *     ```
     *
     * @passthrough system The specific system associated with this plugin.
     */
    explicit Passthrough(System& system);

    /**
     * @brief Destructor (internal use only).
     */
    ~Passthrough();

    /**
     * @brief Possible results returned for passthrough requests.
     * Anotacao: Change to passthrough results
     */
    enum class Result {
        UNKNOWN, /**< @brief Unknown error. */
        SUCCESS, /**< @brief Success. */
        CONNECTION_ERROR /**< @brief Connection error. */
    };

    /**
     * @brief Returns a human-readable English string for `Passthrough::Result`.
     *
     * @passthrough result The enum value for which a human readable string is required.
     * @return Human readable string for the `Passthrough::Result`.
     */
    static std::string result_str(Result result);

   /**
    * @brief Command Int type
    */
    struct CommandInt {
        struct ParamsInt {
            float param1;
            float param2;
            float param3;
            float param4;
            int32_t x; 
            int32_t y; 
            float z;
        } params;

        uint8_t target_system_id;
        uint8_t target_component_id;
        uint16_t command;
        bool current;
        bool autocontinue; 
    };

   /*
    * @brief Command Long type
    */
    struct CommandLong {
        struct ParamsLong {
            float param1;
            float param2;
            float param3;
            float param4;
            float param5; 
            float param6; 
            float param7;
        } params;

        uint8_t target_system_id;
        uint8_t target_component_id;
        uint16_t command = 3;
        uint8_t confirmation = 4;
    };

   /**
    * @brief Mavlink Message type
    */
    struct MavlinkMessage {
        uint16_t checksum;
        uint8_t magic;
        uint8_t len;
        uint8_t incompat_flags;
        uint8_t compat_flags;
        uint8_t seq;
        uint8_t sysid;
        uint8_t compid;
        uint8_t msgid;
        std::vector<uint64_t> payload64{};
        std::vector<uint8_t> ck{};
    };

    /**
     * @brief Send message.
     *
     * @return result of the request.
     */
    Result send_message(const MavlinkMessage mavlink_message);

        /**
     * @brief Get our own system ID.
     *
     * @return our own system ID.
     */
    uint8_t get_our_sysid() const;

    /**
     * @brief Get our own component ID.
     *
     * @return our own component ID.
     */
    uint8_t get_our_compid() const;

    /**
     * @brief Get system ID of target.
     *
     * @return system ID of target.
     */
    uint8_t get_target_sysid() const;

    /**
     * @brief Get target component ID.
     *
     * This defaults to the component ID of the autopilot (1) if available
     * and otherwise to all components (0).
     *
     * @return component ID of target.
     */
    uint8_t get_target_compid() const;

   /**
    * @brief: Send raw command int.
    * 
    * This allows user to construct a raw int mavlink command and send it 
    * to the receiver.
    * 
    * @return Result of the request.
    */
    Result send_command_int(const CommandInt command_int);

   /**
    * @brief: Send raw command long.
    * 
    * This allows user to construct a raw long mavlink command and send it 
    * to the receiver.
    * 
    * @return Result of the request.
    */
    Result send_command_long(const CommandLong command_long);

    /**
     * @brief Copy Constructor (object is not copyable).
     */
    Passthrough(const Passthrough&) = delete;
    /**
     * @brief Equality operator (object is not copyable).
     */
    const Passthrough& operator=(const Passthrough&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<PassthroughImpl> _impl;
};

} // namespace mavsdk
