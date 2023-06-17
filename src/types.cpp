#include <nemoapi/types.h>
#include <nemoapi/enum.h>
#include <nemoapi/utils.h>

namespace nemoapi {
namespace rest {

std::ostream &operator<<(std::ostream &os, const err_t &o) {
    os << o.p;
    return os;
}

signature_t signature_t::from_obj(const rapidjson::Document::Object obj){
    signature_t ret{};
    ret.message = obj.HasMember("message") ? obj["message"].GetString() : "";
    ret.hash = obj.HasMember("hash") ? obj["hash"].GetString() : "";
    ret.ttl = obj.HasMember("ttl") ? obj["ttl"].GetInt() : 0;
    return ret;
}

std::ostream &operator<<(std::ostream &os, const signature_t &o){
    os
    << "{"
    << "\"message\":" << o.message
    << ",\"hash\":" << o.hash
    << ",\"ttl\":" << o.ttl
    << "}";
    return os;
}

nemoid_user_info_t nemoid_user_info_t::from_obj(const rapidjson::Document::Object obj){
    nemoid_user_info_t ret{};
    ret.sub = obj.HasMember("sub") ? obj["sub"].GetString() : "";
    ret.email = obj.HasMember("email") ? obj["email"].GetString() : "";
    ret.email_verified = obj.HasMember("email_verified") ? obj["email_verified"].GetBool() : false;
    ret.name = obj.HasMember("name") ? obj["name"].GetString() : "";
    ret.gender = obj.HasMember("gender") ? obj["gender"].GetString() : "";
    ret.birthday = obj.HasMember("birthday") ? obj["birthday"].GetString() : "";
    ret.profile_picture = obj.HasMember("profile_picture") ? obj["profile_picture"].GetString() : "";
    ret.public_key = obj.HasMember("public_key") ? obj["public_key"].GetString() : "";
    ret.redirect_uri = obj.HasMember("redirect_uri") ? obj["redirect_uri"].GetString() : "";
    ret.client_id = obj.HasMember("client_id") ? obj["client_id"].GetString() : "";
    ret.access_token = obj.HasMember("access_token") ? obj["access_token"].GetString() : "";
    ret.expires_in = obj.HasMember("expires_in") ? obj["expires_in"].GetInt() : 0;
    ret.id_token = obj.HasMember("id_token") ? obj["id_token"].GetString() : "";
    ret.refresh_token = obj.HasMember("refresh_token") ? obj["refresh_token"].GetString() : "";
    ret.token_type = obj.HasMember("token_type") ? obj["token_type"].GetString() : "";
    ret.google_two_factor_authentication = obj.HasMember("google_two_factor_authentication") ? obj["google_two_factor_authentication"].GetBool() : false;
    ret.fund_password = obj.HasMember("fund_password") ? obj["fund_password"].GetBool() : false;
    if (obj.HasMember("signature"))
        ret.signature.from_obj(obj["signature"].GetObject());
    ret.nemo_address = obj.HasMember("nemo_address") ? obj["nemo_address"].GetString() : "";
    if (obj.HasMember("wallet_address")) {
        auto arr = obj["wallet_address"].GetArray();
        for (auto& value: arr) {
            ret.wallet_address.push_back(value.GetString());
        }
    }
    return ret;
}

std::ostream &operator<<(std::ostream &os, const nemoid_user_info_t &o){
    os
    << "{"
    << "\"sub\":" << o.sub
    << ",\"email\":" << o.email
    << ",\"email_verified\":" << o.email_verified
    << ",\"name\":" << o.name
    << ",\"gender\":" << o.gender
    << ",\"birthday\":" << o.birthday
    << ",\"profile_picture\":" << o.profile_picture
    << ",\"public_key\":" << o.public_key
    << ",\"redirect_uri\":" << o.redirect_uri
    << ",\"client_id\":" << o.client_id
    << ",\"access_token\":" << o.access_token
    << ",\"expires_in\":" << o.expires_in
    << ",\"id_token\":" << o.id_token
    << ",\"refresh_token\":" << o.refresh_token
    << ",\"token_type\":" << o.token_type
    << ",\"google_two_factor_authentication\":" << o.google_two_factor_authentication
    << ",\"fund_password\":" << o.fund_password
    << ",\"signature\":" << o.signature
        << "[";
        for (auto it = o.wallet_address.begin(); it != o.wallet_address.end(); ++it) {
            os << *it;
            if (std::next(it) != o.wallet_address.end()) {
                os << ",";
            }
        }
        os
        << "]"
    << "}";
    return os;
}

hotwallet_balance_t hotwallet_balance_t::from_obj(const rapidjson::Document::Object obj){
    hotwallet_balance_t ret{};
    ret.balance = obj["balance"].GetString();
    ret.available_balance = obj["available_balance"].GetString();
    ret.pending_balance = obj["pending_balance"].GetString();
    ret.pending_claim = obj["pending_claim"].GetString();
    return ret;
}

std::ostream &operator<<(std::ostream &os, const hotwallet_balance_t &o){
    os
    << "{"
    << "\"balance\":" << o.balance
    << ",\"available_balance\":" << o.available_balance
    << ",\"pending_balance\":" << o.pending_balance
    << ",\"pending_claim\":" << o.pending_claim
    << "}";
    return os;
}

hotwallet_award_t hotwallet_award_t::from_obj(const rapidjson::Document::Object obj){
    hotwallet_award_t ret{};
    ret.balance = obj["balance"].GetString();
    ret.available_balance = obj["available_balance"].GetString();
    ret.pending_balance = obj["pending_balance"].GetString();
    ret.pending_claim = obj["pending_claim"].GetString();
    ret.tx_hash = obj["tx_hash"].GetString();
    ret.amount = obj["amount"].GetString();
    return ret;
}

std::ostream &operator<<(std::ostream &os, const hotwallet_award_t &o){
    os
    << "{"
    << "\"balance\":" << o.balance
    << ",\"available_balance\":" << o.available_balance
    << ",\"pending_balance\":" << o.pending_balance
    << ",\"pending_claim\":" << o.pending_claim
    << ",\"tx_hash\":" << o.tx_hash
    << ",\"amount\":" << o.tx_hash
    << "}";
    return os;
}

hotwallet_allowance_t hotwallet_allowance_t::from_obj(const rapidjson::Document::Object obj){
    hotwallet_allowance_t ret{};
    ret.account = obj["account"].GetString();
    ret.spender = obj["spender"].GetString();
    ret.amount = obj["amount"].GetString();
    return ret;
}

std::ostream &operator<<(std::ostream &os, const hotwallet_allowance_t &o){
    os
    << "{"
    << "\"account\":" << o.account
    << ",\"spender\":" << o.spender
    << ",\"amount\":" << o.amount
    << "}";
    return os;
}

nft_mint_t nft_mint_t::from_obj(const rapidjson::Document::Object obj){
    nft_mint_t ret{};
    ret.uuid = obj["uuid"].GetString();
    return ret;
}

std::ostream &operator<<(std::ostream &os, const nft_mint_t &o){
    os
    << "{"
    << "\"uuid\":" << o.uuid
    << "}";
    return os;
}

} //namespace rest
} //namespace nemoapi