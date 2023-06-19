//Copyright (C) 2023 Thomas Gingele

#ifndef CONFIG_READER_H
#define CONFIG_READER_H

#include <sys/stat.h>

#include "common_headers.h"
#include "yaml-cpp/yaml.h"

class ConfigReader {
    private:
        YAML::Node yaml;

    public:
        void load(std::string file);
        std::string valueOf(std::string setting_name);
};

#endif
