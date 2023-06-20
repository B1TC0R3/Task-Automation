//Copyright (C) 2023 Thomas Gingele

#ifndef CONFIG_READER_H
#define CONFIG_READER_H

#include <sys/stat.h>

#include "common_headers.hpp"
#include "yaml-cpp/yaml.h"

struct FileBinding {
    std::string from;
    std::string to;
};

struct DotfileConfig {
    bool use_git;
    std::string url;
    std::string clone_to;
    std::vector<FileBinding> file_bindings;
};

struct Config {
    bool printBanner;
    DotfileConfig dotfiles;
};

class ConfigReader {
    YAML::Node yaml;

    public:
        Config load(std::string file);

    private:
        Config convertYamlToStruct();
        DotfileConfig parseDotfileConfig();

        template<typename Type>
        Type getValue(YAML::Node node, Type defaultValue);
};

#endif
