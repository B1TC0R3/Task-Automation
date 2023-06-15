#ifndef CONFIG_READER_H
#define CONFIG_READER_H

#include "common_headers.h"
#include "yaml-cpp/yaml.h"

template <typename T>
class ConfigReader {
    public:
        ConfigReader();
        void load(std::string path);
        T valueOf(std::string setting_name);
};

#endif
