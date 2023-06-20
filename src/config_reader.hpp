//Copyright (C) 2023 Thomas Gingele

#ifndef CONFIG_READER_H
#define CONFIG_READER_H

#include <sys/stat.h>

#include "common_headers.hpp"
#include "yaml-cpp/yaml.h"

struct Config {
    bool printBanner = true;
};

class ConfigReader {
    YAML::Node yaml;

    public:
        Config load(std::string file);

    private:
        Config convertYamlToStruct();

        template<typename Type>
        Type getValue(YAML::Node node, Type defaultValue);
};

#endif
