#include "passthrough/passthrough.grpc.pb.h"
#include "plugins/passthrough/passthrough.h"

namespace mavsdk {
namespace backend {

template<typename Passthrough = Passthrough>
class PassthroughServiceImpl final : public rpc::passthrough::PassthroughService::Service {
public:
    PassthroughServiceImpl(Passthrough& passthrough) : _passthrough(passthrough) {}

    grpc::Status SendMessage(
        grpc::ServerContext* /* context */,
        const rpc::passthrough::SendMessageRequest* request,
        rpc::passthrough::SendMessageResponse* response) override
    {
        if (request != nullptr) {
            const auto requested_mavlink_message = request->mavlink_message();

            const auto passthrough_result = _passthrough.send_message(translateRPCMavlinkMessage(requested_mavlink_message));

            if (response != nullptr) {
                auto* rpc_passthrough_result = new rpc::passthrough::PassthroughResult();
                rpc_passthrough_result->set_result(
                    static_cast<rpc::passthrough::PassthroughResult::Result>(passthrough_result));
                rpc_passthrough_result->set_result_str(mavsdk::Passthrough::result_str(passthrough_result));

                response->set_allocated_passthrough_result(rpc_passthrough_result);
            }
        }

        return grpc::Status::OK;
    }

    grpc::Status GetOurSysId(
        grpc::ServerContext* /* context */,
        const rpc::passthrough::GetOurSysIdRequest* /* request */,
        rpc::passthrough::GetOurSysIdResponse* response) override
    {
        if (response != nullptr) {
            response->set_sysid(_passthrough.get_our_sysid());
        }

        return grpc::Status::OK;
    }

    grpc::Status GetOurCompId(
        grpc::ServerContext* /* context */,
        const rpc::passthrough::GetOurCompIdRequest* /* request */,
        rpc::passthrough::GetOurCompIdResponse* response) override
    {
        if (response != nullptr) {
            response->set_compid(_passthrough.get_our_compid());
        }

        return grpc::Status::OK;
    }

    grpc::Status GetTargetSysId(
        grpc::ServerContext* /* context */,
        const rpc::passthrough::GetTargetSysIdRequest* /* request */,
        rpc::passthrough::GetTargetSysIdResponse* response) override
    {
        if (response != nullptr) {
            response->set_target_sysid(_passthrough.get_target_sysid());
        }

        return grpc::Status::OK;
    }

    grpc::Status GetTargetCompId(
        grpc::ServerContext* /* context */,
        const rpc::passthrough::GetTargetCompIdRequest* /* request */,
        rpc::passthrough::GetTargetCompIdResponse* response) override
    {
        if (response != nullptr) {
            response->set_target_compid(_passthrough.get_target_compid());
        }

        return grpc::Status::OK;
    }

    grpc::Status SendCommandInt(
        grpc::ServerContext* /* context */,
        const rpc::passthrough::SendCommandIntRequest* request,
        rpc::passthrough::SendCommandIntResponse* response) override
    {
        if (request != nullptr) {
            const auto requested_command_int = request->command_int();

            const auto passthrough_result = _passthrough.send_command_int(translateRPCCommandInt(requested_command_int));

            if (response != nullptr) {
                auto* rpc_passthrough_result = new rpc::passthrough::PassthroughResult();
                rpc_passthrough_result->set_result(
                    static_cast<rpc::passthrough::PassthroughResult::Result>(passthrough_result));
                rpc_passthrough_result->set_result_str(mavsdk::Passthrough::result_str(passthrough_result));

                response->set_allocated_passthrough_result(rpc_passthrough_result);
            }
        }

        return grpc::Status::OK;
    }

    grpc::Status SendCommandLong(
        grpc::ServerContext* /* context */,
        const rpc::passthrough::SendCommandLongRequest* request,
        rpc::passthrough::SendCommandLongResponse* response) override
    {

        if (request != nullptr) {
            const auto requested_command_long = request->command_long();

            const auto passthrough_result = _passthrough.send_command_long(translateRPCCommandLong(requested_command_long));

            if (response != nullptr) {
                auto* rpc_passthrough_result = new rpc::passthrough::PassthroughResult();
                rpc_passthrough_result->set_result(
                    static_cast<rpc::passthrough::PassthroughResult::Result>(passthrough_result));
                rpc_passthrough_result->set_result_str(mavsdk::Passthrough::result_str(passthrough_result));

                response->set_allocated_passthrough_result(rpc_passthrough_result);
            }
        }

        return grpc::Status::OK;
    }


    static mavsdk::Passthrough::CommandInt translateRPCCommandInt(const rpc::passthrough::CommandInt rpc_command_int) 
    {
        mavsdk::Passthrough::CommandInt command_int;

        command_int.target_system_id = rpc_command_int.target_system_id();
        command_int.target_component_id = rpc_command_int.target_component_id();
        command_int.command = rpc_command_int.command();
        command_int.current = rpc_command_int.current(); 
        command_int.autocontinue = rpc_command_int.autocontinue(); 
        command_int.params = translateRPCParamsInt(rpc_command_int.params());

        return command_int;  
    }

    static mavsdk::Passthrough::CommandInt::ParamsInt 
    translateRPCParamsInt(const rpc::passthrough::ParamsInt& rpc_params_int)
    {
        mavsdk::Passthrough::CommandInt::ParamsInt params_int;

        params_int.param1 = rpc_params_int.param1();
        params_int.param2 = rpc_params_int.param2();
        params_int.param3 = rpc_params_int.param3();
        params_int.param4 = rpc_params_int.param4();
        params_int.x = rpc_params_int.x();
        params_int.y = rpc_params_int.y();
        params_int.z = rpc_params_int.z();

        return params_int;
    }

    static mavsdk::Passthrough::CommandLong translateRPCCommandLong(const rpc::passthrough::CommandLong rpc_command_long) 
    {
        mavsdk::Passthrough::CommandLong command_long;

        command_long.target_system_id = rpc_command_long.target_system_id();
        command_long.target_component_id = rpc_command_long.target_component_id();
        command_long.command = rpc_command_long.command();
        command_long.confirmation = rpc_command_long.confirmation();
        command_long.params = translateRPCParamsLong(rpc_command_long.params());   

        return command_long;  
    }

    static mavsdk::Passthrough::CommandLong::ParamsLong 
    translateRPCParamsLong(const rpc::passthrough::ParamsLong& rpc_params_long)
    {
        mavsdk::Passthrough::CommandLong::ParamsLong params_long;

        params_long.param1 = rpc_params_long.param1();
        params_long.param2 = rpc_params_long.param2();
        params_long.param3 = rpc_params_long.param3();
        params_long.param4 = rpc_params_long.param4();
        params_long.param5 = rpc_params_long.param5();
        params_long.param6 = rpc_params_long.param6();
        params_long.param7 = rpc_params_long.param7();

        return params_long;
    }

    static mavsdk::Passthrough::MavlinkMessage 
    translateRPCMavlinkMessage(const rpc::passthrough::MavlinkMessage rpc_mavlink_message)
    {
        mavsdk::Passthrough::MavlinkMessage mavlink_message;

        mavlink_message.checksum = uint16_t(rpc_mavlink_message.checksum());
        mavlink_message.magic = uint8_t(rpc_mavlink_message.magic());
        mavlink_message.len = uint8_t(rpc_mavlink_message.len());
        mavlink_message.incompat_flags = uint8_t(rpc_mavlink_message.incompat_flags());
        mavlink_message.compat_flags = uint8_t(rpc_mavlink_message.compat_flags());
        mavlink_message.seq = uint8_t(rpc_mavlink_message.seq());
        mavlink_message.compid = uint8_t(rpc_mavlink_message.compid());
        mavlink_message.msgid = uint8_t(rpc_mavlink_message.msgid());

        std::vector<uint64_t> payload64;
        for (auto payload : rpc_mavlink_message.payload64()) {
            payload64.push_back(uint64_t(payload));
        }

        mavlink_message.payload64 = payload64;

        std::vector<uint8_t> ck;
        for (auto c : rpc_mavlink_message.ck()) {
            ck.push_back(uint8_t(c));
        }

        mavlink_message.ck = ck;

        return mavlink_message;   
    }

    //     // static mavsdk::MavlinkPassthrough::CommandInt 
    // static MAVLinkCommands::CommandInt&
    // translateRPCCommandInt(const rpc::passthrough::CommandInt rpc_command_int) 
    // {
    //     MAVLinkCommands::CommandInt *custom_command{};

    //     custom_command->target_system_id = rpc_command_int.target_system_id();
    //     custom_command->target_component_id = rpc_command_int.target_component_id();
    //     custom_command->command = rpc_command_int.command();
    //     custom_command->current = rpc_command_int.current(); 
    //     custom_command->autocontinue = rpc_command_int.autocontinue();
    //     custom_command->params.param1 = rpc_command_int.params().param1();
    //     custom_command->params.param2 = rpc_command_int.params().param2();
    //     custom_command->params.param3 = rpc_command_int.params().param3();
    //     custom_command->params.param4 = rpc_command_int.params().param4();
    //     custom_command->params.x = rpc_command_int.params().x();
    //     custom_command->params.y = rpc_command_int.params().y();
    //     custom_command->params.z = rpc_command_int.params().z();

    //     return *custom_command;  
    // }

    // // static mavsdk::Passthrough::CommandLong 
    // static MAVLinkCommands::CommandLong&
    // translateRPCCommandLong(const rpc::passthrough::CommandLong rpc_command_long) 
    // {
    //     MAVLinkCommands::CommandLong *custom_command{};

    //     custom_command->target_system_id = rpc_command_long.target_system_id();
    //     custom_command->target_component_id = rpc_command_long.target_component_id();
    //     custom_command->command = rpc_command_long.command();
    //     custom_command->confirmation = rpc_command_long.confirmation();
    //     custom_command->params.param1 = rpc_command_long.params().param1();
    //     custom_command->params.param2 = rpc_command_long.params().param2();
    //     custom_command->params.param3 = rpc_command_long.params().param3();
    //     custom_command->params.param4 = rpc_command_long.params().param4();
    //     custom_command->params.param5 = rpc_command_long.params().param5();
    //     custom_command->params.param6 = rpc_command_long.params().param6();
    //     custom_command->params.param7 = rpc_command_long.params().param7();

    //     return *custom_command;  
    // }

    // static mavlink_message_t& 
    // translateRPCMavlinkMessage(const rpc::passthrough::MavlinkMessage rpc_mavlink_message)
    // {
    //     mavlink_message_t *mavlink_message{};

    //     mavlink_message->checksum = uint16_t(rpc_mavlink_message.checksum());
    //     mavlink_message->magic = uint8_t(rpc_mavlink_message.magic());
    //     mavlink_message->len = uint8_t(rpc_mavlink_message.len());
    //     mavlink_message->incompat_flags = uint8_t(rpc_mavlink_message.incompat_flags());
    //     mavlink_message->compat_flags = uint8_t(rpc_mavlink_message.compat_flags());
    //     mavlink_message->seq = uint8_t(rpc_mavlink_message.seq());
    //     mavlink_message->compid = uint8_t(rpc_mavlink_message.compid());
    //     mavlink_message->msgid = uint8_t(rpc_mavlink_message.msgid());

    //     std::vector<uint64_t> payload64;
    //     for (auto payload : rpc_mavlink_message.payload64()) {
    //         payload64.push_back(uint64_t(payload));
    //     }

    //     for(int i = 0; i < 33; i++) {
    //         mavlink_message->payload64[i] = payload64[i];
    //     }

    //     std::vector<uint8_t> ck;
    //     for (auto c : rpc_mavlink_message.ck()) {
    //         ck.push_back(uint8_t(c));
    //     }

    //     for(int i = 0; i < 2; i++) {
    //         mavlink_message->ck[i] = ck[i];
    //     }

    //     return *mavlink_message;   
    // }

private:
    Passthrough& _passthrough;
};

} // namespace backend
} // namespace mavsdk
