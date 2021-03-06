#ifndef SYSTEM_SYSTEM_MANAGER_H_
#define SYSTEM_SYSTEM_MANAGER_H_

#include <string>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

class SystemManager {

 public:
  static SystemManager* GetInstance();
  void UpdateConfig(std::string key, std::string value);
  void UpdateConfig(std::string key, bool value);
  std::string ReadConfig(std::string key);
  void ReadConfig(std::string key, bool *value);
  std::string hmac() { return hmac_; }
  void ResetToDefault();
  void Init();
 private:
  SystemManager();
  json system_config_;
  std::string key_ = "xiaopi";
  std::string hmac_ = "";
  static SystemManager *instance_;

#ifdef DEVEL
  std::string config_path_ = "./config.json";
#else
  std::string config_path_ = "/etc/config.json";
#endif
};

#endif // SYSTEM_SYSTEM_MANAGER_H_


