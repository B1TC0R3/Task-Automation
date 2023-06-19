//Copyright (C) 2023 Thomas Gingele

#include "config_reader.h"

void ConfigReader::load(std::string file) {
    std::ifstream filestream(file);
    std::stringstream buffer;

    if (access(file.c_str(), F_OK) == -1) {
        std::cout << "Unable to read " << file << ". Does it exist?";
        throw std::runtime_error("Unable to read config file from '" + file + "'!");
    }

    buffer << filestream.rdbuf();
    this->yaml = YAML::Load(buffer.str());
}

std::string ConfigReader::valueOf(std::string setting_name) {
    throw std::runtime_error("Method ConfigReader::valueOf(std::string) not implemented!");
}
